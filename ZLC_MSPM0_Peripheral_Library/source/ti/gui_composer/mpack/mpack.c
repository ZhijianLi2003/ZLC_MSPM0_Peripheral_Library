/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-2018 Nicholas Fraser
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

/*
 * This is the MPack 1.0 amalgamation package.
 *
 * http://github.com/ludocode/mpack
 */

#define MPACK_INTERNAL 1
#define MPACK_EMIT_INLINE_DEFS 1

#include "mpack.h"

/* mpack/mpack-platform.c.c */

// We define MPACK_EMIT_INLINE_DEFS and include mpack.h to emit
// standalone definitions of all (non-static) inline functions in MPack.
#define MPACK_INTERNAL 1
#define MPACK_EMIT_INLINE_DEFS 1

/* #include "mpack-platform.h" */
/* #include "mpack.h" */

/* clang-format off */

#if MPACK_DEBUG && MPACK_STDIO
#include <stdarg.h>
#endif



#if MPACK_DEBUG

#if MPACK_STDIO
void mpack_assert_fail_format(const char* format, ...) {
    char buffer[512];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    buffer[sizeof(buffer) - 1] = 0;
    mpack_assert_fail_wrapper(buffer);
}

void mpack_break_hit_format(const char* format, ...) {
    char buffer[512];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    buffer[sizeof(buffer) - 1] = 0;
    mpack_break_hit(buffer);
}
#endif

#if !MPACK_CUSTOM_ASSERT
void mpack_assert_fail(const char* message) {
    MPACK_UNUSED(message);

    #if MPACK_STDIO
    fprintf(stderr, "%s\n", message);
    #endif
}
#endif

// We split the assert failure from the wrapper so that a
// custom assert function can return.
void mpack_assert_fail_wrapper(const char* message) {

    #ifdef MPACK_GCOV
    // gcov marks even __builtin_unreachable() as an uncovered line. this
    // silences it.
    (mpack_assert_fail(message), __builtin_unreachable());

    #else
    mpack_assert_fail(message);

    // mpack_assert_fail() is not supposed to return. in case it does, we
    // abort.

    #if !MPACK_NO_BUILTINS
    #if defined(__GNUC__) || defined(__clang__)
    __builtin_trap();
    #elif defined(WIN32)
    __debugbreak();
    #endif
    #endif

    #if (defined(__GNUC__) || defined(__clang__)) && !MPACK_NO_BUILTINS
    __builtin_abort();
    #elif MPACK_STDLIB
    abort();
    #endif

    MPACK_UNREACHABLE;
    #endif
}

#if !MPACK_CUSTOM_BREAK

// If we have a custom assert handler, break wraps it by default.
// This allows users of MPack to only implement mpack_assert_fail() without
// having to worry about the difference between assert and break.
//
// MPACK_CUSTOM_BREAK is available to define a separate break handler
// (which is needed by the unit test suite), but this is not offered in
// mpack-config.h for simplicity.

#if MPACK_CUSTOM_ASSERT
void mpack_break_hit(const char* message) {
    mpack_assert_fail_wrapper(message);
}
#else
void mpack_break_hit(const char* message) {
    MPACK_UNUSED(message);

    #if MPACK_STDIO
    fprintf(stderr, "%s\n", message);
    #endif

    #if defined(__GNUC__) || defined(__clang__) && !MPACK_NO_BUILTINS
    __builtin_trap();
    #elif defined(WIN32) && !MPACK_NO_BUILTINS
    __debugbreak();
    #elif MPACK_STDLIB
    abort();
    #endif
}
#endif

#endif

#endif


// The below are adapted from the C wikibook:
//     https://en.wikibooks.org/wiki/C_Programming/Strings
#ifndef mpack_memcmp
int mpack_memcmp(const void* s1, const void* s2, size_t n) {
     const unsigned char *us1 = (const unsigned char *) s1;
     const unsigned char *us2 = (const unsigned char *) s2;
     while (n-- != 0) {
         if (*us1 != *us2)
             return (*us1 < *us2) ? -1 : +1;
         us1++;
         us2++;
     }
     return 0;
}
#endif

#ifndef mpack_memcpy
void* mpack_memcpy(void* MPACK_RESTRICT s1, const void* MPACK_RESTRICT s2, size_t n) {
    char* MPACK_RESTRICT dst = (char *)s1;
    const char* MPACK_RESTRICT src = (const char *)s2;
    while (n-- != 0)
        *dst++ = *src++;
    return s1;
}
#endif

#ifndef mpack_memmove
void* mpack_memmove(void* s1, const void* s2, size_t n) {
    char *p1 = (char *)s1;
    const char *p2 = (const char *)s2;
    if (p2 < p1 && p1 < p2 + n) {
        p2 += n;
        p1 += n;
        while (n-- != 0)
            *--p1 = *--p2;
    } else
        while (n-- != 0)
            *p1++ = *p2++;
    return s1;
}
#endif

#ifndef mpack_memset
void* mpack_memset(void* s, int c, size_t n) {
    unsigned char *us = (unsigned char *)s;
    unsigned char uc = (unsigned char)c;
    while (n-- != 0)
        *us++ = uc;
    return s;
}
#endif

#ifndef mpack_strlen
size_t mpack_strlen(const char* s) {
    const char* p = s;
    while (*p != '\0')
        p++;
    return (size_t)(p - s);
}
#endif

#if defined(MPACK_MALLOC) && !defined(MPACK_REALLOC)
void* mpack_realloc(void* old_ptr, size_t used_size, size_t new_size) {
    if (new_size == 0) {
        if (old_ptr)
            MPACK_FREE(old_ptr);
        return NULL;
    }

    void* new_ptr = MPACK_MALLOC(new_size);
    if (new_ptr == NULL)
        return NULL;

    mpack_memcpy(new_ptr, old_ptr, used_size);
    MPACK_FREE(old_ptr);
    return new_ptr;
}
#endif

/* mpack/mpack-common.c.c */

#define MPACK_INTERNAL 1

/* #include "mpack-common.h" */

int mpack_tag_cmp(mpack_tag_t left, mpack_tag_t right)
{

#if MPACK_UINTS || MPACK_INTS
    // positive numbers may be stored as int; convert to uint
    if (left.type == mpack_type_int && left.v.i >= 0)
    {
        left.type = mpack_type_uint;
        left.v.u = (uint64_t) left.v.i;
    }
    if (right.type == mpack_type_int && right.v.i >= 0)
    {
        right.type = mpack_type_uint;
        right.v.u = (uint64_t) right.v.i;
    }
#endif

    if (left.type != right.type)
        return ((int) left.type < (int) right.type) ? -1 : 1;

    switch (left.type)
    {
    case mpack_type_missing: // fallthrough
    case mpack_type_nil:
        return 0;
        case mpack_type_bool:
            return (int)left.v.b - (int)right.v.b;
    case mpack_type_int:
        if (left.v.i == right.v.i)
            return 0;
        return (left.v.i < right.v.i) ? -1 : 1;
    case mpack_type_uint:
        if (left.v.u == right.v.u)
            return 0;
        return (left.v.u < right.v.u) ? -1 : 1;
        case mpack_type_array:
    case mpack_type_map:
        if (left.v.n == right.v.n)
            return 0;
        return (left.v.n < right.v.n) ? -1 : 1;
    case mpack_type_str:

        // floats should not normally be compared for equality. we compare
        // with memcmp() to silence compiler warnings, but this will return
        // equal if both are NaNs with the same representation (though we may
        // want this, for instance if you are for some bizarre reason using
        // floats as map keys.) i'm not sure what the right thing to
        // do is here. check for NaN first? always return false if the type
        // is float? use operator== and pragmas to silence compiler warning?
        // please send me your suggestions.
        // note also that we don't convert floats to doubles, so when this is
        // used for ordering purposes, all floats are ordered before all
        // doubles.
        case mpack_type_float:
            return mpack_memcmp(&left.v.f, &right.v.f, sizeof(left.v.f));
        case mpack_type_double:
            return mpack_memcmp(&left.v.d, &right.v.d, sizeof(left.v.d));
        default:
            break;
    }

    mpack_assert(0, "unrecognized type %i", (int)left.type);
    return false;
}

bool mpack_str_check_no_null(const char *str, size_t bytes)
{
    size_t i;
    for (i = 0; i < bytes; ++i)
        if (str[i] == '\0')
            return false;
    return true;
}

/* mpack/mpack-writer.c.c */

#define MPACK_INTERNAL 1

/* #include "mpack-writer.h" */

#if MPACK_WRITER

static void mpack_writer_clear(mpack_writer_t *writer)
{
    writer->flush = NULL;
    writer->error_fn = NULL;
    writer->teardown = NULL;
    writer->context = NULL;

    writer->buffer = NULL;
    writer->current = NULL;
    writer->end = NULL;
    writer->error = mpack_ok;
}

void mpack_writer_init(mpack_writer_t *writer, char *buffer, size_t size)
{
    mpack_assert(buffer != NULL, "cannot initialize writer with empty buffer");
    mpack_writer_clear(writer);
    writer->buffer = buffer;
    writer->current = buffer;
    writer->end = writer->buffer + size;

#if MPACK_DEBUG
    mpack_log("===========================\n");
    mpack_log("initializing writer with buffer size %i\n", (int)size);
#endif
}

void mpack_writer_init_error(mpack_writer_t *writer, mpack_error_t error)
{
    mpack_writer_clear(writer);
    writer->error = error;
#if MPACK_DEBUG
    mpack_log("===========================\n");
    mpack_log("initializing writer in error state %i\n", (int)error);
#endif
}

void mpack_writer_set_flush(mpack_writer_t *writer, mpack_writer_flush_t flush)
{
#if MPACK_DEBUG
    MPACK_STATIC_ASSERT(MPACK_WRITER_MINIMUM_BUFFER_SIZE >= MPACK_MAXIMUM_TAG_SIZE,
            "minimum buffer size must fit any tag!");
    MPACK_STATIC_ASSERT(31 + MPACK_TAG_SIZE_FIXSTR >= MPACK_WRITER_MINIMUM_BUFFER_SIZE,
            "minimum buffer size must fit the largest possible fixstr!");

    if (mpack_writer_buffer_size(writer) < MPACK_WRITER_MINIMUM_BUFFER_SIZE) {
        mpack_break("buffer size is %i, but minimum buffer size for flush is %i",
                (int)mpack_writer_buffer_size(writer), MPACK_WRITER_MINIMUM_BUFFER_SIZE);
        mpack_writer_flag_error(writer, mpack_error_bug);
        return;
    }
#endif
    writer->flush = flush;
}

#ifdef MPACK_MALLOC
typedef struct mpack_growable_writer_t
{
    char **target_data;
    size_t *target_size;
} mpack_growable_writer_t;

static char* mpack_writer_get_reserved(mpack_writer_t *writer)
{
    // This is in a separate function in order to avoid false strict aliasing
    // warnings. We aren't actually violating strict aliasing (the reserved
    // space is only ever dereferenced as an mpack_growable_writer_t.)
    return (char*) writer->reserved;
}

static void mpack_growable_writer_flush(mpack_writer_t *writer,
                                        const char *data, size_t count)
{

    // This is an intrusive flush function which modifies the writer's buffer
    // in response to a flush instead of emptying it in order to add more
    // capacity for data. This removes the need to copy data from a fixed buffer
    // into a growable one, improving performance.
    //
    // There are three ways flush can be called:
    //   - flushing the buffer during writing (used is zero, count is all data, data is buffer)
    //   - flushing extra data during writing (used is all flushed data, count is extra data, data is not buffer)
    //   - flushing during teardown (used and count are both all flushed data, data is buffer)
    //
    // In the first two cases, we grow the buffer by at least double, enough
    // to ensure that new data will fit. We ignore the teardown flush.

    if (data == writer->buffer)
    {

        // teardown, do nothing
        if (mpack_writer_buffer_used(writer) == count)
            return;

        // otherwise leave the data in the buffer and just grow
        writer->current = writer->buffer + count;
        count = 0;
    }

    size_t used = mpack_writer_buffer_used(writer);
    size_t size = mpack_writer_buffer_size(writer);
#if MPACK_DEBUG
    mpack_log("flush size %i used %i data %p buffer %p\n",
            (int)count, (int)used, data, writer->buffer);
#endif
    mpack_assert(
            data == writer->buffer || used + count > size,
            "extra flush for %i but there is %i space left in the buffer! (%i/%i)",
            (int)count, (int)mpack_writer_buffer_left(writer), (int)used,
            (int)size);

    // grow to fit the data
    // TODO: this really needs to correctly test for overflow
    size_t new_size = size * 2;
    while (new_size < used + count)
        new_size *= 2;
#if MPACK_DEBUG
    mpack_log("flush growing buffer size from %i to %i\n", (int)size, (int)new_size);
#endif
    // grow the buffer
    char *new_buffer = (char*) mpack_realloc(writer->buffer, used, new_size);
    if (new_buffer == NULL)
    {
        mpack_writer_flag_error(writer, mpack_error_memory);
        return;
    }
    writer->current = new_buffer + used;
    writer->buffer = new_buffer;
    writer->end = writer->buffer + new_size;

    // append the extra data
    if (count > 0)
    {
        mpack_memcpy(writer->current, data, count);
        writer->current += count;
    }
#if MPACK_DEBUG
    mpack_log("new buffer %p, used %i\n", new_buffer, (int)mpack_writer_buffer_used(writer));
#endif
}

static void mpack_growable_writer_teardown(mpack_writer_t *writer)
{
    mpack_growable_writer_t *growable_writer =
            (mpack_growable_writer_t*) mpack_writer_get_reserved(writer);

    if (mpack_writer_error(writer) == mpack_ok)
    {

        // shrink the buffer to an appropriate size if the data is
        // much smaller than the buffer
        if (mpack_writer_buffer_used(writer)
                < mpack_writer_buffer_size(writer) / 2)
        {
            size_t used = mpack_writer_buffer_used(writer);

            // We always return a non-null pointer that must be freed, even if
            // nothing was written. malloc() and realloc() do not necessarily
            // do this so we enforce it ourselves.
            size_t size = (used != 0) ? used : 1;

            char *buffer = (char*) mpack_realloc(writer->buffer, used, size);
            if (!buffer)
            {
                MPACK_FREE(writer->buffer);
                mpack_writer_flag_error(writer, mpack_error_memory);
                return;
            }
            writer->buffer = buffer;
            writer->end = (writer->current = writer->buffer + used);
        }

        *growable_writer->target_data = writer->buffer;
        *growable_writer->target_size = mpack_writer_buffer_used(writer);
        writer->buffer = NULL;

    }
    else if (writer->buffer)
    {
        MPACK_FREE(writer->buffer);
        writer->buffer = NULL;
    }

    writer->context = NULL;
}

void mpack_writer_init_growable(mpack_writer_t *writer, char **target_data,
                                size_t *target_size)
{
    mpack_assert(target_data != NULL,
                 "cannot initialize writer without a destination for the data");
    mpack_assert(target_size != NULL,
                 "cannot initialize writer without a destination for the size");

    *target_data = NULL;
    *target_size = 0;

    MPACK_STATIC_ASSERT(sizeof(mpack_growable_writer_t) <= sizeof(writer->reserved),
            "not enough reserved space for growable writer!");
    mpack_growable_writer_t *growable_writer =
            (mpack_growable_writer_t*) mpack_writer_get_reserved(writer);

    growable_writer->target_data = target_data;
    growable_writer->target_size = target_size;

    size_t capacity = MPACK_BUFFER_SIZE;
    char *buffer = (char*) MPACK_MALLOC(capacity);
    if (buffer == NULL)
    {
        mpack_writer_init_error(writer, mpack_error_memory);
        return;
    }

    mpack_writer_init(writer, buffer, capacity);
    mpack_writer_set_flush(writer, mpack_growable_writer_flush);
    mpack_writer_set_teardown(writer, mpack_growable_writer_teardown);
}
#endif

#if MPACK_STDIO
static void mpack_file_writer_flush(mpack_writer_t* writer, const char* buffer, size_t count) {
    FILE* file = (FILE*)writer->context;
    size_t written = fwrite((const void*)buffer, 1, count, file);
    if (written != count)
        mpack_writer_flag_error(writer, mpack_error_io);
}

static void mpack_file_writer_teardown(mpack_writer_t* writer) {
    MPACK_FREE(writer->buffer);
    writer->buffer = NULL;
    writer->context = NULL;
}

static void mpack_file_writer_teardown_close(mpack_writer_t* writer) {
    FILE* file = (FILE*)writer->context;

    if (file) {
        int ret = fclose(file);
        if (ret != 0)
            mpack_writer_flag_error(writer, mpack_error_io);
    }

    mpack_file_writer_teardown(writer);
}

void mpack_writer_init_stdfile(mpack_writer_t* writer, FILE* file, bool close_when_done) {
    mpack_assert(file != NULL, "file is NULL");

    size_t capacity = MPACK_BUFFER_SIZE;
    char* buffer = (char*)MPACK_MALLOC(capacity);
    if (buffer == NULL) {
        mpack_writer_init_error(writer, mpack_error_memory);
        if (close_when_done) {
            fclose(file);
        }
        return;
    }

    mpack_writer_init(writer, buffer, capacity);
    mpack_writer_set_context(writer, file);
    mpack_writer_set_flush(writer, mpack_file_writer_flush);
    mpack_writer_set_teardown(writer, close_when_done ?
            mpack_file_writer_teardown_close :
            mpack_file_writer_teardown);
}

void mpack_writer_init_filename(mpack_writer_t* writer, const char* filename) {
    mpack_assert(filename != NULL, "filename is NULL");

    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        mpack_writer_init_error(writer, mpack_error_io);
        return;
    }

    mpack_writer_init_stdfile(writer, file, true);
}
#endif

void mpack_writer_flag_error(mpack_writer_t *writer, mpack_error_t error)
{
#if MPACK_DEBUG
    mpack_log("writer %p setting error %i: %s\n", writer, (int)error, mpack_error_to_string(error));
#endif
    if (writer->error == mpack_ok)
    {
        writer->error = error;
        if (writer->error_fn)
            writer->error_fn(writer, writer->error);
    }
}

MPACK_STATIC_INLINE void mpack_writer_flush_unchecked(mpack_writer_t *writer)
{
    // This is a bit ugly; we reset used before calling flush so that
    // a flush function can distinguish between flushing the buffer
    // versus flushing external data. see mpack_growable_writer_flush()
    size_t used = mpack_writer_buffer_used(writer);
    writer->current = writer->buffer;
    writer->flush(writer, writer->buffer, used);
}

void mpack_writer_flush_message(mpack_writer_t *writer)
{
#if MPACK_DEBUG
    if (writer->error != mpack_ok)
        return;

    if (writer->flush == NULL) {
        mpack_break("cannot call mpack_writer_flush_message() without a flush function!");
        mpack_writer_flag_error(writer, mpack_error_bug);
        return;
    }


    if (mpack_writer_buffer_used(writer) > 0)
#endif
    mpack_writer_flush_unchecked(writer);
}

#if MPACK_DEBUG
// Ensures there are at least count bytes free in the buffer. This
// will flag an error if the flush function fails to make enough
// room in the buffer.
MPACK_NOINLINE static bool mpack_writer_ensure(mpack_writer_t *writer,
                                               size_t count)
{
    mpack_assert(count != 0, "cannot ensure zero bytes!");
    mpack_assert(
            count <= MPACK_WRITER_MINIMUM_BUFFER_SIZE,
            "cannot ensure %i bytes, this is more than the minimum buffer size %i!",
            (int)count, (int)MPACK_WRITER_MINIMUM_BUFFER_SIZE);
    mpack_assert(
            count > mpack_writer_buffer_left(writer),
            "request to ensure %i bytes but there are already %i left in the buffer!",
            (int)count, (int)mpack_writer_buffer_left(writer));
#if MPACK_DEBUG
    mpack_log("ensuring %i bytes, %i left\n", (int)count, (int)mpack_writer_buffer_left(writer));
#endif
    if (mpack_writer_error(writer) != mpack_ok)
        return false;

    if (writer->flush == NULL)
    {
        mpack_writer_flag_error(writer, mpack_error_too_big);
        return false;
    }

    mpack_writer_flush_unchecked(writer);
    if (mpack_writer_error(writer) != mpack_ok)
        return false;

    if (mpack_writer_buffer_left(writer) >= count)
        return true;

    mpack_writer_flag_error(writer, mpack_error_io);
    return false;
}

// Writes encoded bytes to the buffer when we already know the data
// does not fit in the buffer (i.e. it straddles the edge of the
// buffer.) If there is a flush function, it is guaranteed to be
// called; otherwise mpack_error_too_big is raised.
MPACK_NOINLINE static void mpack_write_native_straddle(mpack_writer_t *writer,
                                                       const char *p,
                                                       size_t count)
{
    mpack_assert(count == 0 || p != NULL, "data pointer for %i bytes is NULL",
                 (int)count);

    if (mpack_writer_error(writer) != mpack_ok)
        return;
#if MPACK_DEBUG
    mpack_log("big write for %i bytes from %p, %i space left in buffer\n",
            (int)count, p, (int)mpack_writer_buffer_left(writer));
#endif
    mpack_assert(
            count > mpack_writer_buffer_left(writer),
            "big write requested for %i bytes, but there is %i available " "space in buffer. should have called mpack_write_native() instead",
            (int)count, (int)(mpack_writer_buffer_left(writer)));

    // we'll need a flush function
    if (!writer->flush)
    {
        mpack_writer_flag_error(writer, mpack_error_too_big);
        return;
    }

    // flush the buffer
    mpack_writer_flush_unchecked(writer);
    if (mpack_writer_error(writer) != mpack_ok)
        return;

    // note that an intrusive flush function (such as mpack_growable_writer_flush())
    // may have changed size and/or reset used to a non-zero value. we treat both as
    // though they may have changed, and there may still be data in the buffer.

    // flush the extra data directly if it doesn't fit in the buffer
    if (count > mpack_writer_buffer_left(writer))
    {
        writer->flush(writer, p, count);
        if (mpack_writer_error(writer) != mpack_ok)
            return;
    }
    else
    {
        mpack_memcpy(writer->current, p, count);
        writer->current += count;
    }
}
#endif

// Writes encoded bytes to the buffer, flushing if necessary.
MPACK_STATIC_INLINE void mpack_write_native(mpack_writer_t *writer,
                                            const char *p, size_t count)
{
    mpack_assert(count == 0 || p != NULL, "data pointer for %i bytes is NULL",
                 (int)count);
#if MPACK_DEBUG
    if (mpack_writer_buffer_left(writer) < count)
    {
        mpack_write_native_straddle(writer, p, count);
    }
#endif
    mpack_memcpy(writer->current, p, count);
    writer->current += count;

}

mpack_error_t mpack_writer_destroy(mpack_writer_t *writer)
{

    // clean up tracking, asserting if we're not already in an error state
    // flush any outstanding data
    if (mpack_writer_error(writer)
            == mpack_ok&& mpack_writer_buffer_used(writer) != 0 && writer->flush != NULL)
    {
        writer->flush(writer, writer->buffer, mpack_writer_buffer_used(writer));
        writer->flush = NULL;
    }

    if (writer->teardown)
    {
        writer->teardown(writer);
        writer->teardown = NULL;
    }

    return writer->error;
}

void mpack_write_tag(mpack_writer_t *writer, mpack_tag_t value)
{
    switch (value.type)
    {
    case mpack_type_missing:
        mpack_break("cannot write a missing value!");
        mpack_writer_flag_error(writer, mpack_error_bug);
        return;
    case mpack_type_nil:
        mpack_write_nil(writer);
        return;
        case mpack_type_bool:   mpack_write_bool  (writer, value.v.b); return;
        case mpack_type_float:  mpack_write_float (writer, value.v.f); return;
        case mpack_type_double: mpack_write_double(writer, value.v.d); return;
    case mpack_type_int:
        mpack_write_int(writer, value.v.i);
        return;
    case mpack_type_uint:
        mpack_write_uint(writer, value.v.u);
        return;
    case mpack_type_str:
        mpack_start_str(writer, value.v.l);
        return;
        case mpack_type_array: mpack_start_array(writer, value.v.n); return;
    case mpack_type_map:
        mpack_start_map(writer, value.v.n);
        return;
    }

    mpack_break("unrecognized type %i", (int)value.type);
    mpack_writer_flag_error(writer, mpack_error_bug);
}

MPACK_STATIC_INLINE void mpack_write_byte_element(mpack_writer_t *writer,
                                                  char value)
{
    mpack_writer_track_element(writer);
#if MPACK_DEBUG
    if (MPACK_LIKELY(mpack_writer_buffer_left(writer) >= 1) || mpack_writer_ensure(writer, 1))
#endif
    *(writer->current++) = value;
}

void mpack_write_nil(mpack_writer_t *writer)
{
    mpack_write_byte_element(writer, (char) 0xc0);
}

void mpack_write_bool(mpack_writer_t *writer, bool value)
{
    mpack_write_byte_element(writer, (char) (0xc2 | (value ? 1 : 0)));
}

void mpack_write_true(mpack_writer_t *writer)
{
    mpack_write_byte_element(writer, (char) 0xc3);
}

void mpack_write_false(mpack_writer_t *writer)
{
    mpack_write_byte_element(writer, (char) 0xc2);
}

void mpack_write_object_bytes(mpack_writer_t *writer, const char *data,
                              size_t bytes)
{
    mpack_writer_track_element(writer);
    mpack_write_native(writer, data, bytes);
}

/*
 * Encode functions
 */

MPACK_STATIC_INLINE void mpack_encode_fixuint(char* p, uint8_t value)
{
    mpack_assert(value <= 127);
    mpack_store_u8(p, value);
}

MPACK_STATIC_INLINE void mpack_encode_u8(char* p, uint8_t value)
{
    mpack_assert(value > 127);
    mpack_store_u8(p, 0xcc);
    mpack_store_u8(p + 1, value);
}

MPACK_STATIC_INLINE void mpack_encode_u16(char* p, uint16_t value)
{
    mpack_assert(value > UINT8_MAX);
    mpack_store_u8(p, 0xcd);
    mpack_store_u16(p + 1, value);
}

MPACK_STATIC_INLINE void mpack_encode_u64(char* p, uint64_t value)
{
    mpack_assert(value > UINT32_MAX);
    mpack_store_u8(p, 0xcf);
    mpack_store_u64(p + 1, value);
}

MPACK_STATIC_INLINE void mpack_encode_fixint(char* p, int8_t value)
{
    // this can encode positive or negative fixints
    mpack_assert(value >= -32);
    mpack_store_i8(p, value);
}

MPACK_STATIC_INLINE void mpack_encode_i8(char* p, int8_t value)
{
    mpack_assert(value < -32);
    mpack_store_u8(p, 0xd0);
    mpack_store_i8(p + 1, value);
}

MPACK_STATIC_INLINE void mpack_encode_i16(char* p, int16_t value)
{
    mpack_assert(value < INT8_MIN);
    mpack_store_u8(p, 0xd1);
    mpack_store_i16(p + 1, value);
}

MPACK_STATIC_INLINE void mpack_encode_i64(char* p, int64_t value)
{
    mpack_assert(value < INT32_MIN);
    mpack_store_u8(p, 0xd3);
    mpack_store_i64(p + 1, value);
}


MPACK_STATIC_INLINE void mpack_encode_u32(char *p, uint32_t value)
{
    mpack_assert(value > UINT16_MAX);
    mpack_store_u8(p, 0xce);
    mpack_store_u32(p + 1, value);
}
MPACK_STATIC_INLINE void mpack_encode_i32(char *p, int32_t value)
{
    mpack_assert(value < INT16_MIN);
    mpack_store_u8(p, 0xd2);
    mpack_store_i32(p + 1, value);
}

MPACK_STATIC_INLINE void mpack_encode_float(char* p, float value)
{
    mpack_store_u8(p, 0xca);
    mpack_store_float(p + 1, value);
}
MPACK_STATIC_INLINE void mpack_encode_double(char* p, double value)
{
    mpack_store_u8(p, 0xcb);
    mpack_store_double(p + 1, value);
}

MPACK_STATIC_INLINE void mpack_encode_fixarray(char* p, uint8_t count)
{
    mpack_assert(count <= 15);
    mpack_store_u8(p, (uint8_t)(0x90 | count));
}

MPACK_STATIC_INLINE void mpack_encode_array16(char* p, uint16_t count)
{
    mpack_assert(count > 15);
    mpack_store_u8(p, 0xdc);
    mpack_store_u16(p + 1, count);
}

MPACK_STATIC_INLINE void mpack_encode_array32(char* p, uint32_t count)
{
    mpack_assert(count > UINT16_MAX);
    mpack_store_u8(p, 0xdd);
    mpack_store_u32(p + 1, count);
}

MPACK_STATIC_INLINE void mpack_encode_fixstr(char *p, uint8_t count)
{
//    mpack_assert(count <= 31);
    mpack_store_u8(p, (uint8_t) (0xa0 | count));
}

MPACK_STATIC_INLINE void mpack_encode_str8(char *p, uint8_t count)
{
    mpack_assert(count > 31);
    mpack_store_u8(p, 0xd9);
    mpack_store_u8(p + 1, count);
}

MPACK_STATIC_INLINE void mpack_encode_str16(char *p, uint16_t count)
{
    // we might be encoding a raw in compatibility mode, so we
    // allow count to be in the range [32, UINT8_MAX].
    mpack_assert(count > 31);
    mpack_store_u8(p, 0xda);
    mpack_store_u16(p + 1, count);
}

MPACK_STATIC_INLINE void mpack_encode_str32(char *p, uint32_t count)
{
    mpack_assert(count > UINT16_MAX);
    mpack_store_u8(p, 0xdb);
    mpack_store_u32(p + 1, count);
}

/*
 * Write functions
 */

// This is a macro wrapper to the encode functions to encode
// directly into the buffer. If mpack_writer_ensure() fails
// it will flag an error so we don't have to do anything.
#if MPACK_DEBUG
#define MPACK_WRITE_ENCODED(encode_fn, size, ...) do {                                                 \
if (MPACK_LIKELY(mpack_writer_buffer_left(writer) >= size) || mpack_writer_ensure(writer, size)) { \
        MPACK_EXPAND(encode_fn(writer->current, __VA_ARGS__));                                         \
        writer->current += size;                                                                       \
    }                                                                                                  \
} while (0)
#else
#define MPACK_WRITE_ENCODED(encode_fn, size, ...) do {                                                 \
        MPACK_EXPAND(encode_fn(writer->current, __VA_ARGS__));                                         \
        writer->current += size;                                                                       \
} while (0)
#endif

void mpack_write_u8(mpack_writer_t* writer, uint8_t value) {
    if (value <= 127) {
        MPACK_WRITE_ENCODED(mpack_encode_fixuint, MPACK_TAG_SIZE_FIXUINT, (uint8_t)value);
    } else if (value <= UINT8_MAX) {
        MPACK_WRITE_ENCODED(mpack_encode_u8, MPACK_TAG_SIZE_U8, (uint8_t)value);
    }
}



void mpack_write_u16(mpack_writer_t* writer, uint16_t value) {
    MPACK_WRITE_ENCODED(mpack_encode_u16, MPACK_TAG_SIZE_U16, (uint16_t)value);
}

void mpack_write_u32(mpack_writer_t *writer, uint32_t value) {
    MPACK_WRITE_ENCODED(mpack_encode_u32, MPACK_TAG_SIZE_U32, (uint32_t )value);
}

void mpack_write_u64(mpack_writer_t* writer, uint64_t value) {
    MPACK_WRITE_ENCODED(mpack_encode_u64, MPACK_TAG_SIZE_U64, value);
    return;
}

void mpack_write_uint(mpack_writer_t* writer, uint32_t value) {
    mpack_writer_track_element(writer);

    if (value <= 127) {
        MPACK_WRITE_ENCODED(mpack_encode_fixuint, MPACK_TAG_SIZE_FIXUINT, (uint8_t)value);
    } else if (value <= UINT8_MAX) {
        MPACK_WRITE_ENCODED(mpack_encode_u8, MPACK_TAG_SIZE_U8, (uint8_t)value);
    } else if (value <= UINT16_MAX) {
        MPACK_WRITE_ENCODED(mpack_encode_u16, MPACK_TAG_SIZE_U16, (uint16_t)value);
    } else if (value <= UINT32_MAX) {
        MPACK_WRITE_ENCODED(mpack_encode_u32, MPACK_TAG_SIZE_U32, (uint32_t)value);
    }
    return;
}

void mpack_write_i8(mpack_writer_t* writer, int8_t value) {
    if (value >= -32) {
           MPACK_WRITE_ENCODED(mpack_encode_fixint, MPACK_TAG_SIZE_FIXINT, (int8_t)value);
       } else if (value >= INT8_MIN) {
           MPACK_WRITE_ENCODED(mpack_encode_i8, MPACK_TAG_SIZE_I8, (int8_t)value);
       }
}

void mpack_write_i16(mpack_writer_t* writer, int16_t value) {
    MPACK_WRITE_ENCODED(mpack_encode_i16, MPACK_TAG_SIZE_I16, (int16_t)value);
}

void mpack_write_i32(mpack_writer_t *writer, int32_t value)
{
    MPACK_WRITE_ENCODED(mpack_encode_i32, MPACK_TAG_SIZE_I32, (int32_t )value);
}
void mpack_write_i64(mpack_writer_t* writer, int64_t value) {
    MPACK_WRITE_ENCODED(mpack_encode_i64, MPACK_TAG_SIZE_I64, value);
}
void mpack_write_int(mpack_writer_t* writer, int32_t value) {
    mpack_writer_track_element(writer);
    if (value >= -32) {
        MPACK_WRITE_ENCODED(mpack_encode_fixint, MPACK_TAG_SIZE_FIXINT, (int8_t)value);
    } else if (value >= INT8_MIN) {
        MPACK_WRITE_ENCODED(mpack_encode_i8, MPACK_TAG_SIZE_I8, (int8_t)value);
    } else if (value >= INT16_MIN) {
        MPACK_WRITE_ENCODED(mpack_encode_i16, MPACK_TAG_SIZE_I16, (int16_t)value);
    } else if (value >= INT32_MIN) {
        MPACK_WRITE_ENCODED(mpack_encode_i32, MPACK_TAG_SIZE_I32, (int32_t)value);
    }

}

void mpack_write_float(mpack_writer_t* writer, float value) {
    mpack_writer_track_element(writer);
    MPACK_WRITE_ENCODED(mpack_encode_float, MPACK_TAG_SIZE_FLOAT, value);
}

void mpack_write_double(mpack_writer_t* writer, double value) {
    mpack_writer_track_element(writer);
    MPACK_WRITE_ENCODED(mpack_encode_double, MPACK_TAG_SIZE_DOUBLE, value);
}

void mpack_start_array(mpack_writer_t* writer, uint32_t count) {
    mpack_writer_track_element(writer);

    if (count <= 15) {
        MPACK_WRITE_ENCODED(mpack_encode_fixarray, MPACK_TAG_SIZE_FIXARRAY, (uint8_t)count);
    } else if (count <= UINT16_MAX) {
        MPACK_WRITE_ENCODED(mpack_encode_array16, MPACK_TAG_SIZE_ARRAY16, (uint16_t)count);
    } else {
        MPACK_WRITE_ENCODED(mpack_encode_array32, MPACK_TAG_SIZE_ARRAY32, (uint32_t)count);
    }

    mpack_writer_track_push(writer, mpack_type_array, count);
}

void mpack_start_map(mpack_writer_t *writer, uint8_t count)
{
    uint8_t* u = (uint8_t*)writer->current;
    u[0] = (0x80 | count);
    writer->current += 1;
}

static void mpack_start_str_notrack(mpack_writer_t *writer, uint32_t count)
{
    if (count <= 31)
    {
        MPACK_WRITE_ENCODED(mpack_encode_fixstr, MPACK_TAG_SIZE_FIXSTR,
                            (uint8_t )count);

        // str8 is only supported in v5 or later.
    }
    else if (count <= UINT8_MAX
    )
    {
        MPACK_WRITE_ENCODED(mpack_encode_str8, MPACK_TAG_SIZE_STR8,
                            (uint8_t )count);

    }
    else if (count <= UINT16_MAX)
    {
        MPACK_WRITE_ENCODED(mpack_encode_str16, MPACK_TAG_SIZE_STR16,
                            (uint16_t )count);
    }
    else
    {
        MPACK_WRITE_ENCODED(mpack_encode_str32, MPACK_TAG_SIZE_STR32,
                            (uint32_t )count);
    }
}


static void mpack_start_str_notrackfix(mpack_writer_t *writer, uint32_t count)
{
    if (count <= 31)
    {
        MPACK_WRITE_ENCODED(mpack_encode_fixstr, MPACK_TAG_SIZE_FIXSTR,
                            (uint8_t )count);
    }
}

void mpack_start_str(mpack_writer_t *writer, uint32_t count)
{
    mpack_writer_track_element(writer);
    mpack_start_str_notrack(writer, count);
    mpack_writer_track_push(writer, mpack_type_str, count);
}

/*
 * Compound helpers and other functions
 */

void mpack_write_str(mpack_writer_t *writer, const char *data, uint32_t count)
{
    mpack_assert(data != NULL, "data for string of length %i is NULL",
                 (int)count);
    mpack_writer_track_element(writer);
    mpack_start_str_notrackfix(writer, count);
    mpack_write_native(writer, data, count);
}


void mpack_write_cstr(mpack_writer_t *writer, const char *cstr)
{
    mpack_assert(cstr != NULL, "cstr pointer is NULL");
    size_t length = mpack_strlen(cstr);
#if MPACK_DEBUG
    if (length > UINT32_MAX)
        mpack_writer_flag_error(writer, mpack_error_invalid);
#endif
    mpack_write_str(writer, cstr, (uint32_t) length);
}

void mpack_write_cstr_or_nil(mpack_writer_t *writer, const char *cstr)
{
    if (cstr)
        mpack_write_cstr(writer, cstr);
    else
        mpack_write_nil(writer);
}

#endif

/* mpack/mpack-reader.c.c */

#define MPACK_INTERNAL 1

/* #include "mpack-reader.h" */

#if MPACK_READER

static void mpack_reader_skip_using_fill(mpack_reader_t *reader, size_t count);

void mpack_reader_init(mpack_reader_t *reader, char *buffer, size_t size,
                       size_t count)
{
    mpack_assert(buffer != NULL, "buffer is NULL");

    mpack_memset(reader, 0, sizeof(*reader));
    reader->buffer = buffer;
    reader->size = size;
    reader->data = buffer;
    reader->end = buffer + count;

#if MPACK_DEBUG
    mpack_log("===========================\n");
    mpack_log("initializing reader with buffer size %i\n", (int)size);
#endif
}

void mpack_reader_init_error(mpack_reader_t *reader, mpack_error_t error)
{
    mpack_memset(reader, 0, sizeof(*reader));
    reader->error = error;

#if MPACK_DEBUG
    mpack_log("===========================\n");
    mpack_log("initializing reader error state %i\n", (int)error);
#endif
}

void mpack_reader_init_data(mpack_reader_t *reader, const char *data,
                            size_t count)
{
    mpack_assert(data != NULL, "data is NULL");

    mpack_memset(reader, 0, sizeof(*reader));
    reader->data = data;
    reader->end = data + count;

#if MPACK_DEBUG
    mpack_log("===========================\n");
    mpack_log("initializing reader with data size %i\n", (int)count);
#endif
}

void mpack_reader_set_fill(mpack_reader_t *reader, mpack_reader_fill_t fill)
{
    MPACK_STATIC_ASSERT(MPACK_READER_MINIMUM_BUFFER_SIZE >= MPACK_MAXIMUM_TAG_SIZE,
            "minimum buffer size must fit any tag!");

    if (reader->size == 0)
    {
        mpack_break("cannot use fill function without a writeable buffer!");
        mpack_reader_flag_error(reader, mpack_error_bug);
        return;
    }

    if (reader->size < MPACK_READER_MINIMUM_BUFFER_SIZE)
    {
        mpack_break("buffer size is %i, but minimum buffer size for fill is %i",
                    (int)reader->size, MPACK_READER_MINIMUM_BUFFER_SIZE);
        mpack_reader_flag_error(reader, mpack_error_bug);
        return;
    }

    reader->fill = fill;
}

void mpack_reader_set_skip(mpack_reader_t *reader, mpack_reader_skip_t skip)
{
    mpack_assert(reader->size != 0,
                 "cannot use skip function without a writeable buffer!");
    reader->skip = skip;
}

#if MPACK_STDIO
static size_t mpack_file_reader_fill(mpack_reader_t* reader, char* buffer, size_t count) {
    if (feof((FILE *)reader->context)) {
       mpack_reader_flag_error(reader, mpack_error_eof);
       return 0;
    }
    return fread((void*)buffer, 1, count, (FILE*)reader->context);
}

static void mpack_file_reader_skip(mpack_reader_t* reader, size_t count) {
    if (mpack_reader_error(reader) != mpack_ok)
        return;
    FILE* file = (FILE*)reader->context;

    // We call ftell() to test whether the stream is seekable
    // without causing a file error.
    if (ftell(file) >= 0) {
#if MPACK_DEBUG
        mpack_log("seeking forward %i bytes\n", (int)count);
#endif
        if (fseek(file, (long int)count, SEEK_CUR) == 0)
            return;
#if MPACK_DEBUG
        mpack_log("fseek() didn't return zero!\n");
#endif
        if (ferror(file)) {
            mpack_reader_flag_error(reader, mpack_error_io);
            return;
        }
    }

    // If the stream is not seekable, fall back to the fill function.
    mpack_reader_skip_using_fill(reader, count);
}

static void mpack_file_reader_teardown(mpack_reader_t* reader) {
    MPACK_FREE(reader->buffer);
    reader->buffer = NULL;
    reader->context = NULL;
    reader->size = 0;
    reader->fill = NULL;
    reader->skip = NULL;
    reader->teardown = NULL;
}

static void mpack_file_reader_teardown_close(mpack_reader_t* reader) {
    FILE* file = (FILE*)reader->context;

    if (file) {
        int ret = fclose(file);
        if (ret != 0)
            mpack_reader_flag_error(reader, mpack_error_io);
    }

    mpack_file_reader_teardown(reader);
}

void mpack_reader_init_stdfile(mpack_reader_t* reader, FILE* file, bool close_when_done) {
    mpack_assert(file != NULL, "file is NULL");

    size_t capacity = MPACK_BUFFER_SIZE;
    char* buffer = (char*)MPACK_MALLOC(capacity);
    if (buffer == NULL) {
        mpack_reader_init_error(reader, mpack_error_memory);
        if (close_when_done) {
            fclose(file);
        }
        return;
    }

    mpack_reader_init(reader, buffer, capacity, 0);
    mpack_reader_set_context(reader, file);
    mpack_reader_set_fill(reader, mpack_file_reader_fill);
    mpack_reader_set_skip(reader, mpack_file_reader_skip);
    mpack_reader_set_teardown(reader, close_when_done ?
            mpack_file_reader_teardown_close :
            mpack_file_reader_teardown);
}

void mpack_reader_init_filename(mpack_reader_t* reader, const char* filename) {
    mpack_assert(filename != NULL, "filename is NULL");

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        mpack_reader_init_error(reader, mpack_error_io);
        return;
    }

    mpack_reader_init_stdfile(reader, file, true);
}
#endif

mpack_error_t mpack_reader_destroy(mpack_reader_t *reader)
{

    // clean up tracking, asserting if we're not already in an error state

    if (reader->teardown)
        reader->teardown(reader);
    reader->teardown = NULL;

    return reader->error;
}

size_t mpack_reader_remaining(mpack_reader_t *reader, const char **data)
{
    if (mpack_reader_error(reader) != mpack_ok)
        return 0;

    if (data)
        *data = reader->data;
    return (size_t) (reader->end - reader->data);
}

void mpack_reader_flag_error(mpack_reader_t *reader, mpack_error_t error)
{
#if MPACK_DEBUG
    mpack_log("reader %p setting error %i: %s\n", reader, (int)error, mpack_error_to_string(error));
#endif
    if (reader->error == mpack_ok)
    {
        reader->error = error;
        reader->end = reader->data;
        if (reader->error_fn)
            reader->error_fn(reader, error);
    }
}

// Loops on the fill function, reading between the minimum and
// maximum number of bytes and flagging an error if it fails.
MPACK_NOINLINE static size_t mpack_fill_range(mpack_reader_t *reader, char *p,
                                              size_t min_bytes,
                                              size_t max_bytes)
{
    mpack_assert(reader->fill != NULL,
                 "mpack_fill_range() called with no fill function?");
    mpack_assert(min_bytes > 0, "cannot fill zero bytes!");
    mpack_assert(max_bytes >= min_bytes,
                 "min_bytes %i cannot be larger than max_bytes %i!",
                 (int)min_bytes, (int)max_bytes);

    size_t count = 0;
    while (count < min_bytes)
    {
        size_t read = reader->fill(reader, p + count, max_bytes - count);

        // Reader fill functions can flag an error or return 0 on failure. We
        // also guard against functions that -1 just in case.
        if (mpack_reader_error(reader) != mpack_ok)
            return 0;
        if (read == 0 || read == ((size_t) (-1)))
        {
            mpack_reader_flag_error(reader, mpack_error_io);
            return 0;
        }

        count += read;
    }
    return count;
}

MPACK_NOINLINE bool mpack_reader_ensure_straddle(mpack_reader_t *reader,
                                                 size_t count)
{
    mpack_assert(count != 0, "cannot ensure zero bytes!");
    mpack_assert(reader->error == mpack_ok,
                 "reader cannot be in an error state!");

    mpack_assert(
            count > (size_t )(reader->end - reader->data),
            "straddling ensure requested for %i bytes, but there are %i bytes " "left in buffer. call mpack_reader_ensure() instead",
            (int)count, (int)(reader->end - reader->data));

    // we'll need a fill function to get more data. if there's no
    // fill function, the buffer should contain an entire MessagePack
    // object, so we raise mpack_error_invalid instead of mpack_error_io
    // on truncated data.
    if (reader->fill == NULL)
    {
        mpack_reader_flag_error(reader, mpack_error_invalid);
        return false;
    }

    // we need enough space in the buffer. if the buffer is not
    // big enough, we return mpack_error_too_big (since this is
    // for an in-place read larger than the buffer size.)
    if (count > reader->size)
    {
        mpack_reader_flag_error(reader, mpack_error_too_big);
        return false;
    }

    // move the existing data to the start of the buffer
    size_t left = (size_t) (reader->end - reader->data);
    mpack_memmove(reader->buffer, reader->data, left);
    reader->end -= reader->data - reader->buffer;
    reader->data = reader->buffer;

    // read at least the necessary number of bytes, accepting up to the
    // buffer size
    size_t read = mpack_fill_range(reader, reader->buffer + left, count - left,
                                   reader->size - left);
    if (mpack_reader_error(reader) != mpack_ok)
        return false;
    reader->end += read;
    return true;
}

// Reads count bytes into p. Used when there are not enough bytes
// left in the buffer to satisfy a read.
MPACK_NOINLINE void mpack_read_native_straddle(mpack_reader_t *reader, char *p,
                                               size_t count)
{
    mpack_assert(count == 0 || p != NULL, "data pointer for %i bytes is NULL",
                 (int)count);

    if (mpack_reader_error(reader) != mpack_ok)
    {
        mpack_memset(p, 0, count);
        return;
    }

    size_t left = (size_t) (reader->end - reader->data);
#if MPACK_DEBUG
    mpack_log("big read for %i bytes into %p, %i left in buffer, buffer size %i\n",
            (int)count, p, (int)left, (int)reader->size);
#endif
    if (count <= left)
    {
        mpack_assert(
                0,
                "big read requested for %i bytes, but there are %i bytes " "left in buffer. call mpack_read_native() instead",
                (int)count, (int)left);
        mpack_reader_flag_error(reader, mpack_error_bug);
        mpack_memset(p, 0, count);
        return;
    }

    // we'll need a fill function to get more data. if there's no
    // fill function, the buffer should contain an entire MessagePack
    // object, so we raise mpack_error_invalid instead of mpack_error_io
    // on truncated data.
    if (reader->fill == NULL)
    {
        mpack_reader_flag_error(reader, mpack_error_invalid);
        mpack_memset(p, 0, count);
        return;
    }

    if (reader->size == 0)
    {
        // somewhat debatable what error should be returned here. when
        // initializing a reader with an in-memory buffer it's not
        // necessarily a bug if the data is blank; it might just have
        // been truncated to zero. for this reason we return the same
        // error as if the data was truncated.
        mpack_reader_flag_error(reader, mpack_error_io);
        mpack_memset(p, 0, count);
        return;
    }

    // flush what's left of the buffer
    if (left > 0)
    {
#if MPACK_DEBUG
        mpack_log("flushing %i bytes remaining in buffer\n", (int)left);
#endif
        mpack_memcpy(p, reader->data, left);
        count -= left;
        p += left;
        reader->data += left;
    }

    // if the remaining data needed is some small fraction of the
    // buffer size, we'll try to fill the buffer as much as possible
    // and copy the needed data out.
    if (count <= reader->size / MPACK_READER_SMALL_FRACTION_DENOMINATOR)
    {
        size_t read = mpack_fill_range(reader, reader->buffer, count,
                                       reader->size);
        if (mpack_reader_error(reader) != mpack_ok)
            return;
        mpack_memcpy(p, reader->buffer, count);
        reader->data = reader->buffer + count;
        reader->end = reader->buffer + read;

        // otherwise we read the remaining data directly into the target.
    }
    else
    {
#if MPACK_DEBUG
        mpack_log("reading %i additional bytes\n", (int)count);
#endif
        mpack_fill_range(reader, p, count, count);
    }
}

MPACK_NOINLINE static void mpack_skip_bytes_straddle(mpack_reader_t *reader,
                                                     size_t count)
{

    // we'll need at least a fill function to skip more data. if there's
    // no fill function, the buffer should contain an entire MessagePack
    // object, so we raise mpack_error_invalid instead of mpack_error_io
    // on truncated data. (see mpack_read_native_straddle())
    if (reader->fill == NULL)
    {
#if MPACK_DEBUG
        mpack_log("reader has no fill function!\n");
#endif
        mpack_reader_flag_error(reader, mpack_error_invalid);
        return;
    }

    // discard whatever's left in the buffer
    size_t left = (size_t) (reader->end - reader->data);
#if MPACK_DEBUG
    mpack_log("discarding %i bytes still in buffer\n", (int)left);
#endif
    count -= left;
    reader->data = reader->end;

    // use the skip function if we've got one, and if we're trying
    // to skip a lot of data. if we only need to skip some tiny
    // fraction of the buffer size, it's probably better to just
    // fill the buffer and skip from it instead of trying to seek.
    if (reader->skip && count > reader->size / 16)
    {
#if MPACK_DEBUG
        mpack_log("calling skip function for %i bytes\n", (int)count);
#endif
        reader->skip(reader, count);
        return;
    }

    mpack_reader_skip_using_fill(reader, count);
}

void mpack_skip_bytes(mpack_reader_t *reader, size_t count)
{
    if (mpack_reader_error(reader) != mpack_ok)
        return;
#if MPACK_DEBUG
    mpack_log("skip requested for %i bytes\n", (int)count);
#endif
    mpack_reader_track_bytes(reader, count);

    // check if we have enough in the buffer already
    size_t left = (size_t) (reader->end - reader->data);
    if (left >= count)
    {
#if MPACK_DEBUG
        mpack_log("skipping %i bytes still in buffer\n", (int)count);
#endif
        reader->data += count;
        return;
    }

    mpack_skip_bytes_straddle(reader, count);
}

MPACK_NOINLINE static void mpack_reader_skip_using_fill(mpack_reader_t *reader,
                                                        size_t count)
{
    mpack_assert(reader->fill != NULL, "missing fill function!");
    mpack_assert(reader->data == reader->end,
                 "there are bytes left in the buffer!");
    mpack_assert(reader->error == mpack_ok,
                 "should not have called this in an error state (%i)",
                 reader->error);
#if MPACK_DEBUG
    mpack_log("skip using fill for %i bytes\n", (int)count);
#endif

    // fill and discard multiples of the buffer size
    while (count > reader->size)
    {
#if MPACK_DEBUG
        mpack_log("filling and discarding buffer of %i bytes\n", (int)reader->size);
#endif
        if (mpack_fill_range(reader, reader->buffer, reader->size, reader->size)
                < reader->size)
        {
            mpack_reader_flag_error(reader, mpack_error_io);
            return;
        }
        count -= reader->size;
    }

    // fill the buffer as much as possible
    reader->data = reader->buffer;
    size_t read = mpack_fill_range(reader, reader->buffer, count, reader->size);
    if (read < count)
    {
        mpack_reader_flag_error(reader, mpack_error_io);
        return;
    }
    reader->end = reader->data + read;
#if MPACK_DEBUG
    mpack_log("filled %i bytes into buffer; discarding %i bytes\n", (int)read, (int)count);
#endif
    reader->data += count;
}

void mpack_read_bytes(mpack_reader_t* reader, char* p, size_t count) {
    mpack_assert(p != NULL, "destination for read of %i bytes is NULL", (int)count);
    mpack_reader_track_bytes(reader, count);
    mpack_read_native(reader, p, count);
}


static void mpack_read_cstr_unchecked(mpack_reader_t *reader, char *buf,
                                      size_t buffer_size, size_t byte_count)
{
    mpack_assert(buf != NULL, "destination for read of %i bytes is NULL",
                 (int)byte_count);
    mpack_assert(
            buffer_size >= 1,
            "buffer size is zero; you must have room for at least a null-terminator");

    if (mpack_reader_error(reader))
    {
        buf[0] = 0;
        return;
    }

    if (byte_count > buffer_size - 1)
    {
        mpack_reader_flag_error(reader, mpack_error_too_big);
        buf[0] = 0;
        return;
    }

    mpack_reader_track_str_bytes_all(reader, byte_count);
    mpack_read_native(reader, buf, byte_count);
    buf[byte_count] = 0;
}

void mpack_read_cstr(mpack_reader_t *reader, char *buf, size_t buffer_size,
                     size_t byte_count)
{
    mpack_read_cstr_unchecked(reader, buf, buffer_size, byte_count);

    // check for null bytes
    if (mpack_reader_error(reader) == mpack_ok
            && !mpack_str_check_no_null(buf, byte_count))
    {
        buf[0] = 0;
        mpack_reader_flag_error(reader, mpack_error_type);
    }
}

#ifdef MPACK_MALLOC
// Reads native bytes with error callback disabled. This allows MPack reader functions
// to hold an allocated buffer and read native data into it without leaking it in
// case of a non-local jump (longjmp, throw) out of an error handler.
static void mpack_read_native_noerrorfn(mpack_reader_t *reader, char *p,
                                        size_t count)
{
    mpack_assert(reader->error == mpack_ok,
                 "cannot call if an error is already flagged!");
    mpack_reader_error_t error_fn = reader->error_fn;
    reader->error_fn = NULL;
    mpack_read_native(reader, p, count);
    reader->error_fn = error_fn;
}

char* mpack_read_bytes_alloc_impl(mpack_reader_t *reader, size_t count,
                                  bool null_terminated)
{

    // track the bytes first in case it jumps
    mpack_reader_track_bytes(reader, count);
    if (mpack_reader_error(reader) != mpack_ok)
        return NULL;

    // cannot allocate zero bytes. this is not an error.
    if (count == 0 && null_terminated == false)
        return NULL;

    // allocate data
    char *data = (char*) MPACK_MALLOC(count + (null_terminated ? 1 : 0)); // TODO: can this overflow?
    if (data == NULL)
    {
        mpack_reader_flag_error(reader, mpack_error_memory);
        return NULL;
    }

    // read with error callback disabled so we don't leak our buffer
    mpack_read_native_noerrorfn(reader, data, count);

    // report flagged errors
    if (mpack_reader_error(reader) != mpack_ok)
    {
        MPACK_FREE(data);
        if (reader->error_fn)
            reader->error_fn(reader, mpack_reader_error(reader));
        return NULL;
    }

    if (null_terminated)
        data[count] = '\0';
    return data;
}
#endif


static size_t mpack_parse_tag(mpack_reader_t* reader, mpack_tag_t* tag) {
    mpack_assert(reader->error == mpack_ok, "reader cannot be in an error state!");

#if MPACK_DEBUG
    if (!mpack_reader_ensure(reader, 1))
        return 0;
#endif
    uint8_t type = mpack_load_u8(reader->data);

    switch (type >> 4) {
    // positive fixnum ( num < 127)
        case 0x0: case 0x1: case 0x2: case 0x3:
        case 0x4: case 0x5: case 0x6: case 0x7:
            tag->type = mpack_type_uint;
            tag->v.u = type;
            return 1;
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_INTS
        case 0xe: case 0xf: // negative fixnum
            tag->type = mpack_type_int;
            tag->v.i = (int8_t)type;
            return 1;
#endif
        case 0x8: // fixmap
            tag->type = mpack_type_map;
            tag->v.n = (type & ~0xf0u);
            return 1;
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_ARRAYS
        case 0x9:  // fixarray
            tag->type = mpack_type_array;
            tag->v.n = (type & ~0xf0u);
            return 1;
#endif
        case 0xa: case 0xb:  // fixstr
            tag->type = mpack_type_str;
            tag->v.l = (type & ~0xe0u);
            return 1;
        default: // not one of the common infix types
            break;
    }

    // handle individual type tags
    switch (type) {
        case 0xc0: // nil
            tag->type = mpack_type_nil;
            return 1;
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_BOOL
        case 0xc2: case 0xc3: // bool
            tag->type = mpack_type_bool;
            tag->v.b = (bool) (type & 1);
            return 1;
#endif
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_FLOAT
        case 0xca: // float
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_FLOAT))
                return 0;
            *tag = mpack_tag_make_float(mpack_load_float(reader->data + 1));
            return MPACK_TAG_SIZE_FLOAT;
#endif
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_DOUBLE
        case 0xcb: // double
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_DOUBLE))
                return 0;
            *tag = mpack_tag_make_double(mpack_load_double(reader->data + 1));
            return MPACK_TAG_SIZE_DOUBLE;
#endif

#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_UINTS && MPACK_DECODE_SIZE_8_BITS
        case 0xcc:  // uint8
#if MPACK_DEBUG
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_U8))
                return 0;
#endif
            tag->type = mpack_type_uint;
            tag->v.u =  mpack_load_u8(reader->data + 1);
            return MPACK_TAG_SIZE_U8;
#endif
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_UINTS && MPACK_DECODE_SIZE_16_BITS
        case 0xcd: // uint16
#if MPACK_DEBUG
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_U16))
                return 0;
#endif
            tag->type = mpack_type_uint;
            tag->v.u =  mpack_load_u16(reader->data + 1);
            return MPACK_TAG_SIZE_U16;
#endif
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_UINTS && MPACK_DECODE_SIZE_32_BITS
            case 0xce: // uint32
#if MPACK_DEBUG
                if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_U32))
                    return 0;
#endif
                tag->type = mpack_type_uint;
                tag->v.u =  mpack_load_u32(reader->data + 1);
                return MPACK_TAG_SIZE_U32;
#endif

#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_UINTS && MPACK_DECODE_SIZE_64_BITS
        case 0xcf: // uint64
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_U64))
                return 0;
            *tag = mpack_tag_make_uint(mpack_load_u64(reader->data + 1));
            return MPACK_TAG_SIZE_U64;
#endif


#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_INTS && MPACK_DECODE_SIZE_8_BITS
        case 0xd0: // int8
#if MPACK_DEBUG
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_I8))
                return 0;
#endif
            tag->type = mpack_type_int;
            tag->v.i = (int8_t)mpack_load_i8(reader->data + 1);
            return MPACK_TAG_SIZE_I8;
#endif
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_INTS && MPACK_DECODE_SIZE_16_BITS
        case 0xd1: // int16
#if MPACK_DEBUG
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_I16))
                return 0;
#endif
            tag->type = mpack_type_int;
            tag->v.i = (int16_t)mpack_load_i16(reader->data + 1);
            return MPACK_TAG_SIZE_I16;
#endif
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_INTS && MPACK_DECODE_SIZE_32_BITS
        case 0xd2: // int32
#if MPACK_DEBUG
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_I32))
                return 0;
#endif
            tag->type = mpack_type_int;
            tag->v.i = (int32_t)mpack_load_i32(reader->data + 1);
            return MPACK_TAG_SIZE_I32;
#endif
#if !MPACK_OPTIMIZE_FOR_SIZE || MPACK_INTS && MPACK_DECODE_SIZE_64_BITS
        // int64
        case 0xd3:
#if MPACK_DEBUG
            if (!mpack_reader_ensure(reader, MPACK_TAG_SIZE_I64))
                return 0;
#endif
            tag->type = mpack_type_int;
            tag->v.i = (int64_t)mpack_load_i64(reader->data + 1);
            return MPACK_TAG_SIZE_I64;
#endif
        default:
            break;
    }

    return 0;
}

mpack_tag_t mpack_read_tag(mpack_reader_t *reader)
{
#if MPACK_DEBUG
    mpack_log("reading tag\n");
    // make sure we can read a tag
    if (mpack_reader_error(reader) != mpack_ok)
        return mpack_tag_make_nil();
    if (mpack_reader_track_element(reader) != mpack_ok)
        return mpack_tag_make_nil();
#endif

    mpack_tag_t tag = MPACK_TAG_ZERO;
    size_t count = mpack_parse_tag(reader, &tag);
    if (count == 0)
    {
        tag.type = mpack_type_nil;
        return tag;
    }

    reader->data += count;
    return tag;
}

mpack_tag_t mpack_peek_tag(mpack_reader_t *reader)
{
#if MPACK_DEBUG
    mpack_log("peeking tag\n");
#endif
    // make sure we can peek a tag
    if (mpack_reader_error(reader) != mpack_ok)
        return mpack_tag_make_nil();
    if (mpack_reader_track_peek_element(reader) != mpack_ok)
        return mpack_tag_make_nil();

    mpack_tag_t tag = MPACK_TAG_ZERO;
    if (mpack_parse_tag(reader, &tag) == 0)
        return mpack_tag_make_nil();
    return tag;
}

void mpack_discard(mpack_reader_t *reader)
{
    mpack_tag_t var = mpack_read_tag(reader);
    if (mpack_reader_error(reader))
        return;
    switch (var.type)
    {
    case mpack_type_str:
        mpack_skip_bytes(reader, var.v.l);
        mpack_done_str(reader);
        break;
        case mpack_type_array: {
            for (; var.v.n > 0; --var.v.n) {
                mpack_discard(reader);
                if (mpack_reader_error(reader))
                    break;
            }
            mpack_done_array(reader);
            break;
        }
    case mpack_type_map:
    {
        for (; var.v.n > 0; --var.v.n)
        {
            mpack_discard(reader);
            mpack_discard(reader);
            if (mpack_reader_error(reader))
                break;
        }
        mpack_done_map(reader);
        break;
    }
    default:
        break;
    }
}

#endif

/* clang-format on */
