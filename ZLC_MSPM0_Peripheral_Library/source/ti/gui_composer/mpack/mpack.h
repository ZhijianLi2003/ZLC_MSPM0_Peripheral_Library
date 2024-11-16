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

/* clang-format off */

#ifndef MPACK_H
#define MPACK_H 1

#define MPACK_AMALGAMATED 1
#define MPACK_RELEASE_VERSION 1

#if defined(MPACK_HAS_CONFIG) && MPACK_HAS_CONFIG
#include "mpack-config.h"
#endif

/* mpack/mpack-defaults.h.h */

/**
 * @name Features
 * @{
 */

/**
 * @def MPACK_READER
 *
 * Enables compilation of the base Tag Reader.
 */
#ifndef MPACK_READER
#define MPACK_READER 1
#endif

/**
 * @def MPACK_WRITER
 *
 * Enables compilation of the Writer.
 */
#ifndef MPACK_WRITER
#define MPACK_WRITER 1
#endif

/*
 * Maximum string length for RX
 */
#ifndef MPACK_MAX_STR_LEN
#define MPACK_MAX_STR_LEN 30
#endif

/*
 * Maximum number of key-value pairs that one map can hold
 */
#ifndef MPACK_MAX_MAP_SIZE
#define MPACK_MAX_MAP_SIZE 16
#endif

/*
 * Enable optimizations to minimize code size.
 * Enabling this option while allow for optimizations in the mpack decoder to
 * reduce code size. There are two main ways to configure the decoder to reduce
 * code size: 1) Modify the allowed data sizes to decode, 2) Modify the allowed
 * data types to decode. By reducing the amount of alloweable data sizes and data
 * types, the user can reduce the code size of their application.
 * When optimizations are disabled, then all data sizes (8, 16, 32, and 64 bits)
 * and supported data types (uints, ints, bools, arrays) are enabled in the decoder.
 */
#ifndef MPACK_OPTIMIZE_FOR_SIZE
#define MPACK_OPTIMIZE_FOR_SIZE 0
#endif
#if MPACK_OPTIMIZE_FOR_SIZE

 // Enable allowed data sizes to decode.
 // When enabled, mpack will decode data only for the data sizes that are enabled.
 // ex. If MPACK_DECODE_SIZE_16_BITS is enabled, then all received incoming data
 // must be 16-bits. Additionally, more than one of the `MPACK_DECODE_SIZE` macro
 // can be enabled at a time.It will not recognize data tagged as 8 bits or 32 bits.
 // This does not affect decoding of non-integer data types, such as maps, bools, strings, etc.
 // IMPORTANT NOTE: GUI Composer be default will send data in the smallest data type, so **the GUI
 // must modified to send all data as a specific data type**. The GUI can be easily
 //  modified to make this change and is discussed in more detail in the User's Guide.
#define MPACK_DECODE_SIZE_8_BITS  0
#define MPACK_DECODE_SIZE_16_BITS 1
#define MPACK_DECODE_SIZE_32_BITS 0
#define MPACK_DECODE_SIZE_64_BITS 0

 // Enable allowed data types for both decoding.
 // If mpack receives a data type that is not enabled, it will result in an error.
 // Disabling data types that you are not using or do not expect to receive
 // can reduce the code size.
#define MPACK_UINTS 1
#define MPACK_INTS 1
#define MPACK_BOOL 1
#define MPACK_ARRAYS 0

#endif // MPACK_OPTIMIZE_FOR_SIZE


/*
 * Enable native encoding/decoding of 32-bit floats
 */
#ifndef MPACK_FLOAT
#define MPACK_FLOAT 0
#endif

/*
 * Enable native encoding/decoding of doubles
 */
#ifndef MPACK_DOUBLE
#define MPACK_DOUBLE 0
#endif

/*
 * Enable internal error checking
 */
#ifndef MPACK_DEBUG
#define MPACK_DEBUG 0
#endif

/**
 * @}
 */


/**
 * @name Dependencies
 * @{
 */

/**
 * @def MPACK_HAS_CONFIG
 *
 * Enables the use of an @c mpack-config.h configuration file for MPack.
 * This file must be in the same folder as @c mpack.h, or it must be
 * available from your project's include paths.
 */
// This goes in your project settings.

/**
 * @def MPACK_STDLIB
 *
 * Enables the use of C stdlib. This allows the library to use malloc
 * for debugging and in allocation helpers.
 */
#ifndef MPACK_STDLIB
#define MPACK_STDLIB 1
#endif


/**
 * @}
 */


/**
 * @name System Functions
 * @{
 */

/**
 * @def MPACK_MALLOC
 *
 * Defines the memory allocation function used by MPack. This is used by
 * helpers for automatically allocating data the correct size, and for
 * debugging functions. If this macro is undefined, the allocation helpers
 * will not be compiled.
 *
 * The default is @c malloc() if @ref MPACK_STDLIB is enabled.
 */
/**
 * @def MPACK_FREE
 *
 * Defines the memory free function used by MPack. This is used by helpers
 * for automatically allocating data the correct size. If this macro is
 * undefined, the allocation helpers will not be compiled.
 *
 * The default is @c free() if @ref MPACK_MALLOC has not been customized and
 * @ref MPACK_STDLIB is enabled.
 */
/**
 * @def MPACK_REALLOC
 *
 * Defines the realloc function used by MPack. It is used by growable
 * buffers to resize more efficiently.
 *
 * The default is @c realloc() if @ref MPACK_MALLOC has not been customized and
 * @ref MPACK_STDLIB is enabled.
 *
 * This is optional, even when @ref MPACK_MALLOC is used. If @ref MPACK_MALLOC is
 * set and @ref MPACK_REALLOC is not, @ref MPACK_MALLOC is used with a simple copy
 * to grow buffers.
 */
#if defined(MPACK_STDLIB) && MPACK_STDLIB && !defined(MPACK_MALLOC)
#define MPACK_MALLOC malloc
#define MPACK_REALLOC realloc
#define MPACK_FREE free
#endif

/**
 * @}
 */


/**
 * @name Debugging Options
 */

/**
 * @def MPACK_DEBUG
 *
 * Enables debug features. You may want to wrap this around your
 * own debug preprocs. By default, this is enabled if @c DEBUG or @c _DEBUG
 * are defined. (@c NDEBUG is not used since it is allowed to have
 * different values in different translation units.)
 */
#if !defined(MPACK_DEBUG) && (defined(DEBUG) || defined(_DEBUG))
#define MPACK_DEBUG 0
#endif


/**
 * Set this to 1 to implement a custom @ref mpack_assert_fail() function.
 * See the documentation on @ref mpack_assert_fail() for details.
 *
 * Asserts are only used when @ref MPACK_DEBUG is enabled, and can be
 * triggered by bugs in MPack or bugs due to incorrect usage of MPack.
 */
#ifndef MPACK_CUSTOM_ASSERT
#define MPACK_CUSTOM_ASSERT 0
#endif

/**
 * @}
 */


/**
 * @name Miscellaneous Options
 * @{
 */

/**
 * Stack space in bytes to use when initializing a reader or writer
 * with a stack-allocated buffer.
 */
#ifndef MPACK_STACK_SIZE
#define MPACK_STACK_SIZE 4096
#endif

/**
 * Buffer size to use for allocated buffers (such as for a file writer.)
 *
 * Starting with a single page and growing as needed seems to
 * provide the best performance with minimal memory waste.
 * Increasing this does not improve performance even when writing
 * huge messages.
 */
#ifndef MPACK_BUFFER_SIZE
#define MPACK_BUFFER_SIZE 100
#endif

/**
 * Minimum size of an allocated node page in bytes.
 *
 * The children for a given compound element must be contiguous, so
 * larger pages than this may be allocated as needed. (Safety checks
 * exist to prevent malicious data from causing too large allocations.)
 *
 * See @ref mpack_node_data_t for the size of nodes.
 *
 * Using as many nodes fit in one memory page seems to provide the
 * best performance, and has very little waste when parsing small
 * messages.
 */
#ifndef MPACK_NODE_PAGE_SIZE
#define MPACK_NODE_PAGE_SIZE 4096
#endif

/**
 * The initial depth for the node parser. When MPACK_MALLOC is available,
 * the node parser has no practical depth limit, and it is not recursive
 * so there is no risk of overflowing the call stack.
 */
#ifndef MPACK_NODE_INITIAL_DEPTH
#define MPACK_NODE_INITIAL_DEPTH 8
#endif

/**
 * The maximum depth for the node parser if @ref MPACK_MALLOC is not available.
 */
#ifndef MPACK_NODE_MAX_DEPTH_WITHOUT_MALLOC
#define MPACK_NODE_MAX_DEPTH_WITHOUT_MALLOC 32
#endif

/**
 * @}
 */


/**
 * @}
 */


/* mpack/mpack-platform.h.h */

/**
 * @file
 *
 * Abstracts all platform-specific code from MPack. This contains
 * implementations of standard C functions when libc is not available,
 * as well as wrappers to library functions.
 */

#ifndef MPACK_PLATFORM_H
#define MPACK_PLATFORM_H 1



/* Pre-include checks */

#if defined(_MSC_VER) && _MSC_VER < 1800 && !defined(__cplusplus)
#error "In Visual Studio 2012 and earlier, MPack must be compiled as C++. Enable the /Tp compiler flag."
#endif

#if defined(WIN32) && defined(MPACK_INTERNAL) && MPACK_INTERNAL
#define _CRT_SECURE_NO_WARNINGS 1
#endif



/* Doxygen preprocs */
#if defined(MPACK_DOXYGEN) && MPACK_DOXYGEN
#define MPACK_HAS_CONFIG 0
// We give these their default values of 0 here even though they are defined to
// 1 in the doxyfile. Doxygen will show this as the value in the docs, even
// though it ignores it when parsing the rest of the source. This is what we
// want, since we want the documentation to show these defaults but still
// generate documentation for the functions they add when they're on.
#endif



/* Include the custom config file if enabled */

#if defined(MPACK_HAS_CONFIG) && MPACK_HAS_CONFIG
/* #include "mpack-config.h" */
#endif

/*
 * Now that the optional config is included, we define the defaults
 * for any of the configuration options and other switches that aren't
 * yet defined.
 */
#if defined(MPACK_DOXYGEN) && MPACK_DOXYGEN
/* #include "mpack-defaults-doxygen.h" */
#else
/* #include "mpack-defaults.h" */
#endif

/*
 * All remaining configuration options that have not yet been set must
 * be defined here in order to support -Wundef.
 */
#ifndef MPACK_CUSTOM_BREAK
#define MPACK_CUSTOM_BREAK 0
#endif
#ifndef MPACK_EMIT_INLINE_DEFS
#define MPACK_EMIT_INLINE_DEFS 0
#endif
#ifndef MPACK_AMALGAMATED
#define MPACK_AMALGAMATED 0
#endif
#ifndef MPACK_RELEASE_VERSION
#define MPACK_RELEASE_VERSION 0
#endif
#ifndef MPACK_INTERNAL
#define MPACK_INTERNAL 0
#endif
#ifndef MPACK_NO_BUILTINS
#define MPACK_NO_BUILTINS 0
#endif



/* System headers (based on configuration) */

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <limits.h>

#if MPACK_STDLIB
#include <string.h>
#include <stdlib.h>
#endif



/*
 * Header configuration
 */

#ifdef __cplusplus
    #define MPACK_EXTERN_C_START extern "C" {
    #define MPACK_EXTERN_C_END   }
#else
    #define MPACK_EXTERN_C_START /* nothing */
    #define MPACK_EXTERN_C_END   /* nothing */
#endif

/* GCC versions from 4.6 to before 5.1 warn about defining a C99
 * non-static inline function before declaring it (see issue #20) */
#ifdef __GNUC__
    #if (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
        #ifdef __cplusplus
            #define MPACK_DECLARED_INLINE_WARNING_START \
                _Pragma ("GCC diagnostic push") \
                _Pragma ("GCC diagnostic ignored \"-Wmissing-declarations\"")
        #else
            #define MPACK_DECLARED_INLINE_WARNING_START \
                _Pragma ("GCC diagnostic push") \
                _Pragma ("GCC diagnostic ignored \"-Wmissing-prototypes\"")
        #endif
        #define MPACK_DECLARED_INLINE_WARNING_END \
            _Pragma ("GCC diagnostic pop")
    #endif
#endif
#ifndef MPACK_DECLARED_INLINE_WARNING_START
    #define MPACK_DECLARED_INLINE_WARNING_START /* nothing */
    #define MPACK_DECLARED_INLINE_WARNING_END /* nothing */
#endif

/* GCC versions before 4.8 warn about shadowing a function with a
 * variable that isn't a function or function pointer (like "index") */
#ifdef __GNUC__
    #if (__GNUC__ < 4) || (__GNUC__ == 4 && __GNUC_MINOR__ < 8)
        #define MPACK_WSHADOW_WARNING_START \
            _Pragma ("GCC diagnostic push") \
            _Pragma ("GCC diagnostic ignored \"-Wshadow\"")
        #define MPACK_WSHADOW_WARNING_END \
            _Pragma ("GCC diagnostic pop")
    #endif
#endif
#ifndef MPACK_WSHADOW_WARNING_START
    #define MPACK_WSHADOW_WARNING_START /* nothing */
    #define MPACK_WSHADOW_WARNING_END /* nothing */
#endif

#define MPACK_HEADER_START \
    MPACK_EXTERN_C_START \
    MPACK_WSHADOW_WARNING_START \
    MPACK_DECLARED_INLINE_WARNING_START

#define MPACK_HEADER_END \
    MPACK_DECLARED_INLINE_WARNING_END \
    MPACK_WSHADOW_WARNING_END \
    MPACK_EXTERN_C_END

MPACK_HEADER_START



/* Miscellaneous helper macros */

#define MPACK_UNUSED(var) ((void)(var))

#define MPACK_STRINGIFY_IMPL(arg) #arg
#define MPACK_STRINGIFY(arg) MPACK_STRINGIFY_IMPL(arg)

// This is a workaround for MSVC's incorrect expansion of __VA_ARGS__. It
// treats __VA_ARGS__ as a single preprocessor token when passed in the
// argument list of another macro unless we use an outer wrapper to expand it
// lexically first. (For safety/consistency we use this in all variadic macros
// that don't ignore the variadic arguments regardless of whether __VA_ARGS__
// is passed to another macro.)
//     https://stackoverflow.com/a/32400131
#define MPACK_EXPAND(x) x

// Extracts the first argument of a variadic macro list, where there might only
// be one argument.
#define MPACK_EXTRACT_ARG0_IMPL(first, ...) first
#define MPACK_EXTRACT_ARG0(...) MPACK_EXPAND(MPACK_EXTRACT_ARG0_IMPL( __VA_ARGS__ , ignored))

// Stringifies the first argument of a variadic macro list, where there might
// only be one argument.
#define MPACK_STRINGIFY_ARG0_impl(first, ...) #first
#define MPACK_STRINGIFY_ARG0(...) MPACK_EXPAND(MPACK_STRINGIFY_ARG0_impl( __VA_ARGS__ , ignored))



/*
 * Definition of inline macros.
 *
 * MPack does not use static inline in header files; only one non-inline definition
 * of each function should exist in the final build. This can reduce the binary size
 * in cases where the compiler cannot or chooses not to inline a function.
 * The addresses of functions should also compare equal across translation units
 * regardless of whether they are declared inline.
 *
 * The above requirements mean that the declaration and definition of non-trivial
 * inline functions must be separated so that the definitions will only
 * appear when necessary. In addition, three different linkage models need
 * to be supported:
 *
 *  - The C99 model, where a standalone function is emitted only if there is any
 *    `extern inline` or non-`inline` declaration (including the definition itself)
 *
 *  - The GNU model, where an `inline` definition emits a standalone function and an
 *    `extern inline` definition does not, regardless of other declarations
 *
 *  - The C++ model, where `inline` emits a standalone function with special
 *    (COMDAT) linkage
 *
 * The macros below wrap up everything above. All inline functions defined in header
 * files have a single non-inline definition emitted in the compilation of
 * mpack-platform.c. All inline declarations and definitions use the same MPACK_INLINE
 * specification to simplify the rules on when standalone functions are emitted.
 * Inline functions in source files are defined MPACK_STATIC_INLINE.
 *
 * Additional reading:
 *     http://www.greenend.org.uk/rjk/tech/inline.html
 */

#if defined(__cplusplus)
    // C++ rules
    // The linker will need COMDAT support to link C++ object files,
    // so we don't need to worry about emitting definitions from C++
    // translation units. If mpack-platform.c (or the amalgamation)
    // is compiled as C, its definition will be used, otherwise a
    // C++ definition will be used, and no other C files will emit
    // a defition.
    #define MPACK_INLINE inline

#elif defined(_MSC_VER)
    // MSVC 2013 always uses COMDAT linkage, but it doesn't treat 'inline' as a
    // keyword in C99 mode. (This appears to be fixed in a later version of
    // MSVC but we don't bother detecting it.)
    #define MPACK_INLINE __inline
    #define MPACK_STATIC_INLINE static __inline

#elif defined(__GNUC__) && (defined(__GNUC_GNU_INLINE__) || \
        !defined(__GNUC_STDC_INLINE__) && !defined(__GNUC_GNU_INLINE__))
    // GNU rules
    #if MPACK_EMIT_INLINE_DEFS
        #define MPACK_INLINE inline
    #else
        #define MPACK_INLINE extern inline
    #endif

#else
    // C99 rules
    #if MPACK_EMIT_INLINE_DEFS
        #define MPACK_INLINE extern inline
    #else
        #define MPACK_INLINE inline
    #endif
#endif

#ifndef MPACK_STATIC_INLINE
#define MPACK_STATIC_INLINE static inline
#endif

#ifdef MPACK_OPTIMIZE_FOR_SPEED
    #error "You should define MPACK_OPTIMIZE_FOR_SIZE, not MPACK_OPTIMIZE_FOR_SPEED."
#endif



/*
 * Prevent inlining
 *
 * When a function is only used once, it is almost always inlined
 * automatically. This can cause poor instruction cache usage because a
 * function that should rarely be called (such as buffer exhaustion handling)
 * will get inlined into the middle of a hot code path.
 */

#if !MPACK_NO_BUILTINS
    #if defined(_MSC_VER)
        #define MPACK_NOINLINE __declspec(noinline)
    #elif defined(__GNUC__) || defined(__clang__)
        #define MPACK_NOINLINE __attribute__((noinline))
    #endif
#endif
#ifndef MPACK_NOINLINE
    #define MPACK_NOINLINE /* nothing */
#endif



/* Some compiler-specific keywords and builtins */

#if !MPACK_NO_BUILTINS
    #if defined(__GNUC__) || defined(__clang__)
        #define MPACK_UNREACHABLE __builtin_unreachable()
        #define MPACK_NORETURN(fn) fn __attribute__((noreturn))
        #define MPACK_RESTRICT __restrict__
    #elif defined(_MSC_VER)
        #define MPACK_UNREACHABLE __assume(0)
        #define MPACK_NORETURN(fn) __declspec(noreturn) fn
        #define MPACK_RESTRICT __restrict
    #endif
#endif

#ifndef MPACK_RESTRICT
#ifdef __cplusplus
#define MPACK_RESTRICT /* nothing, unavailable in C++ */
#else
#define MPACK_RESTRICT restrict /* required in C99 */
#endif
#endif

#ifndef MPACK_UNREACHABLE
#define MPACK_UNREACHABLE ((void)0)
#endif
#ifndef MPACK_NORETURN
#define MPACK_NORETURN(fn) fn
#endif



/*
 * Likely/unlikely
 *
 * These should only really be used when a branch is taken (or not taken) less
 * than 1/1000th of the time. Buffer flush checks when writing very small
 * elements are a good example.
 */

#if !MPACK_NO_BUILTINS
    #if defined(__GNUC__) || defined(__clang__)
        #ifndef MPACK_LIKELY
            #define MPACK_LIKELY(x) __builtin_expect((x),1)
        #endif
        #ifndef MPACK_UNLIKELY
            #define MPACK_UNLIKELY(x) __builtin_expect((x),0)
        #endif
    #endif
#endif

#ifndef MPACK_LIKELY
    #define MPACK_LIKELY(x) (x)
#endif
#ifndef MPACK_UNLIKELY
    #define MPACK_UNLIKELY(x) (x)
#endif



/* Static assert */

#ifndef MPACK_STATIC_ASSERT
    #if defined(__cplusplus)
        #if __cplusplus >= 201103L
            #define MPACK_STATIC_ASSERT static_assert
        #endif
    #elif defined(__STDC_VERSION__)
        #if __STDC_VERSION__ >= 201112L
            #define MPACK_STATIC_ASSERT _Static_assert
        #endif
    #endif
#endif

#if !MPACK_NO_BUILTINS
    #ifndef MPACK_STATIC_ASSERT
        #if defined(__has_feature)
            #if __has_feature(cxx_static_assert)
                #define MPACK_STATIC_ASSERT static_assert
            #elif __has_feature(c_static_assert)
                #define MPACK_STATIC_ASSERT _Static_assert
            #endif
        #endif
    #endif

    #ifndef MPACK_STATIC_ASSERT
        #if defined(__GNUC__)
            #if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
                #ifndef __cplusplus
                    #if __GNUC__ >= 5
                    #define MPACK_IGNORE_PEDANTIC "GCC diagnostic ignored \"-Wpedantic\""
                    #else
                    #define MPACK_IGNORE_PEDANTIC "GCC diagnostic ignored \"-pedantic\""
                    #endif
                    #define MPACK_STATIC_ASSERT(expr, str) do { \
                        _Pragma ("GCC diagnostic push") \
                        _Pragma (MPACK_IGNORE_PEDANTIC) \
                        _Pragma ("GCC diagnostic ignored \"-Wc++-compat\"") \
                        _Static_assert(expr, str); \
                        _Pragma ("GCC diagnostic pop") \
                    } while (0)
                #endif
            #endif
        #endif
    #endif

    #ifndef MPACK_STATIC_ASSERT
        #ifdef _MSC_VER
            #if _MSC_VER >= 1600
                #define MPACK_STATIC_ASSERT static_assert
            #endif
        #endif
    #endif
#endif

#ifndef MPACK_STATIC_ASSERT
    #define MPACK_STATIC_ASSERT(expr, str) (MPACK_UNUSED(sizeof(char[1 - 2*!(expr)])))
#endif



/* _Generic */

#ifndef MPACK_HAS_GENERIC
    #if defined(__clang__) && defined(__has_feature)
        // With Clang we can test for _Generic support directly
        // and ignore C/C++ version
        #if __has_feature(c_generic_selections)
            #define MPACK_HAS_GENERIC 1
        #else
            #define MPACK_HAS_GENERIC 0
        #endif
    #endif
#endif

#ifndef MPACK_HAS_GENERIC
    #if defined(__STDC_VERSION__)
        #if __STDC_VERSION__ >= 201112L
            #if defined(__GNUC__) && !defined(__clang__)
                // GCC does not have full C11 support in GCC 4.7 and 4.8
                #if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 9)
                    #define MPACK_HAS_GENERIC 1
                #endif
            #else
                // We hope other compilers aren't lying about C11/_Generic support
                #define MPACK_HAS_GENERIC 1
            #endif
        #endif
    #endif
#endif

#ifndef MPACK_HAS_GENERIC
    #define MPACK_HAS_GENERIC 0
#endif



/*
 * Finite Math
 *
 * -ffinite-math-only, included in -ffast-math, breaks functions that
 * that check for non-finite real values such as isnan() and isinf().
 *
 * We should use this to trap errors when reading data that contains
 * non-finite reals. This isn't currently implemented.
 */

#ifndef MPACK_FINITE_MATH
#if defined(__FINITE_MATH_ONLY__) && __FINITE_MATH_ONLY__
#define MPACK_FINITE_MATH 1
#endif
#endif

#ifndef MPACK_FINITE_MATH
#define MPACK_FINITE_MATH 0
#endif



/*
 * Endianness checks
 *
 * These define MPACK_NHSWAP*() which swap network<->host byte
 * order when needed.
 *
 * We leave them undefined if we can't determine the endianness
 * at compile-time, in which case we fall back to bit-shifts.
 *
 * See the notes in mpack-common.h.
 */

#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        #define MPACK_NHSWAP16(x) (x)
        #define MPACK_NHSWAP32(x) (x)
        #define MPACK_NHSWAP64(x) (x)
    #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

        #if !MPACK_NO_BUILTINS
            #if defined(__clang__)
                #ifdef __has_builtin
                    // Unlike the GCC builtins, the bswap builtins in Clang
                    // significantly improve ARM performance.
                    #if __has_builtin(__builtin_bswap16)
                        #define MPACK_NHSWAP16(x) __builtin_bswap16(x)
                    #endif
                    #if __has_builtin(__builtin_bswap32)
                        #define MPACK_NHSWAP32(x) __builtin_bswap32(x)
                    #endif
                    #if __has_builtin(__builtin_bswap64)
                        #define MPACK_NHSWAP64(x) __builtin_bswap64(x)
                    #endif
                #endif

            #elif defined(__GNUC__)

                // The GCC bswap builtins are apparently poorly optimized on older
                // versions of GCC, so we set a minimum version here just in case.
                //     http://hardwarebug.org/2010/01/14/beware-the-builtins/

                #if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
                    #define MPACK_NHSWAP64(x) __builtin_bswap64(x)
                #endif

                // __builtin_bswap16() was not implemented on all platforms
                // until GCC 4.8.0:
                //     https://gcc.gnu.org/bugzilla/show_bug.cgi?id=52624
                //
                // The 16- and 32-bit versions in GCC significantly reduce performance
                // on ARM with little effect on code size so we don't use them.

            #endif
        #endif
    #endif

#elif defined(_MSC_VER) && defined(_WIN32) && !MPACK_NO_BUILTINS

    // On Windows, we assume x86 and x86_64 are always little-endian.
    // We make no assumptions about ARM even though all current
    // Windows Phone devices are little-endian in case Microsoft's
    // compiler is ever used with a big-endian ARM device.

    #if defined(_M_IX86) || defined(_M_X64) || defined(_M_AMD64)
        #define MPACK_NHSWAP16(x) _byteswap_ushort(x)
        #define MPACK_NHSWAP32(x) _byteswap_ulong(x)
        #define MPACK_NHSWAP64(x) _byteswap_uint64(x)
    #endif

#endif

#if defined(__FLOAT_WORD_ORDER__) && defined(__BYTE_ORDER__)

    // We check where possible that the float byte order matches the
    // integer byte order. This is extremely unlikely to fail, but
    // we check anyway just in case.
    //
    // (The static assert is placed in float/double encoders instead
    // of here because our static assert fallback doesn't work at
    // file scope)

    #define MPACK_CHECK_FLOAT_ORDER() \
        MPACK_STATIC_ASSERT(__FLOAT_WORD_ORDER__ == __BYTE_ORDER__, \
            "float byte order does not match int byte order! float/double " \
            "encoding is not properly implemented on this platform.")

#endif

#ifndef MPACK_CHECK_FLOAT_ORDER
    #define MPACK_CHECK_FLOAT_ORDER() /* nothing */
#endif


/*
 * Here we define mpack_assert() and mpack_break(). They both work like a normal
 * assertion function in debug mode, causing a trap or abort. However, on some platforms
 * you can safely resume execution from mpack_break(), whereas mpack_assert() is
 * always fatal.
 *
 * In release mode, mpack_assert() is converted to an assurance to the compiler
 * that the expression cannot be false (via e.g. __assume() or __builtin_unreachable())
 * to improve optimization where supported. There is thus no point in "safely" handling
 * the case of this being false. Writing mpack_assert(0) rarely makes sense (except
 * possibly as a default handler in a switch) since the compiler will throw away any
 * code after it. If at any time an mpack_assert() is not true, the behaviour is
 * undefined. This also means the expression is evaluated even in release.
 *
 * mpack_break() on the other hand is compiled to nothing in release. It is
 * used in situations where we want to highlight a programming error as early as
 * possible (in the debugger), but we still handle the situation safely if it
 * happens in release to avoid producing incorrect results (such as in
 * MPACK_WRITE_TRACKING.) It does not take an expression to test because it
 * belongs in a safe-handling block after its failing condition has been tested.
 *
 * If stdio is available, we can add a format string describing the error, and
 * on some compilers we can declare it noreturn to get correct results from static
 * analysis tools. Note that the format string and arguments are not evaluated unless
 * the assertion is hit.
 *
 * Note that any arguments to mpack_assert() beyond the first are only evaluated
 * if the expression is false (and are never evaluated in release.)
 *
 * mpack_assert_fail() and mpack_break_hit() are defined separately
 * because assert is noreturn and break isn't. This distinction is very
 * important for static analysis tools to give correct results.
 */

#if MPACK_DEBUG

    /**
     * @addtogroup config
     * @{
     */
    /**
     * @name Debug Functions
     */
    /**
     * Implement this and define @ref MPACK_CUSTOM_ASSERT to use a custom
     * assertion function.
     *
     * This function should not return. If it does, MPack will @c abort().
     *
     * If you use C++, make sure you include @c mpack.h where you define
     * this to get the correct linkage (or define it <code>extern "C"</code>.)
     *
     * Asserts are only used when @ref MPACK_DEBUG is enabled, and can be
     * triggered by bugs in MPack or bugs due to incorrect usage of MPack.
     */
    void mpack_assert_fail(const char* message);
    /**
     * @}
     */
    /**
     * @}
     */

    MPACK_NORETURN(void mpack_assert_fail_wrapper(const char* message));
    #if MPACK_STDIO
        MPACK_NORETURN(void mpack_assert_fail_format(const char* format, ...));
        #define mpack_assert_fail_at(line, file, exprstr, format, ...) \
                MPACK_EXPAND(mpack_assert_fail_format("mpack assertion failed at " file ":" #line "\n%s\n" format, exprstr, __VA_ARGS__))
    #else
        #define mpack_assert_fail_at(line, file, exprstr, format, ...) \
                mpack_assert_fail_wrapper("mpack assertion failed at " file ":" #line "\n" exprstr "\n")
    #endif

    #define mpack_assert_fail_pos(line, file, exprstr, expr, ...) \
            MPACK_EXPAND(mpack_assert_fail_at(line, file, exprstr, __VA_ARGS__))

    // This contains a workaround to the pedantic C99 requirement of having at
    // least one argument to a variadic macro. The first argument is the
    // boolean expression, the optional second argument (if provided) must be a
    // literal format string, and any additional arguments are the format
    // argument list.
    //
    // Unfortunately this means macros are expanded in the expression before it
    // gets stringified. I haven't found a workaround to this.
    //
    // This adds two unused arguments to the format argument list when a
    // format string is provided, so this would complicate the use of
    // -Wformat and __attribute__((format)) on mpack_assert_fail_format() if we
    // ever bothered to implement it.
    #define mpack_assert(...) \
            MPACK_EXPAND(((!(MPACK_EXTRACT_ARG0(__VA_ARGS__))) ? \
                mpack_assert_fail_pos(__LINE__, __FILE__, MPACK_STRINGIFY_ARG0(__VA_ARGS__) , __VA_ARGS__ , "", NULL) : \
                (void)0))

    void mpack_break_hit(const char* message);
    #if MPACK_STDIO
        void mpack_break_hit_format(const char* format, ...);
        #define mpack_break_hit_at(line, file, ...) \
                MPACK_EXPAND(mpack_break_hit_format("mpack breakpoint hit at " file ":" #line "\n" __VA_ARGS__))
    #else
        #define mpack_break_hit_at(line, file, ...) \
                mpack_break_hit("mpack breakpoint hit at " file ":" #line )
    #endif
    #define mpack_break_hit_pos(line, file, ...) MPACK_EXPAND(mpack_break_hit_at(line, file, __VA_ARGS__))
    #define mpack_break(...) MPACK_EXPAND(mpack_break_hit_pos(__LINE__, __FILE__, __VA_ARGS__))
#else
    #define mpack_assert(...) \
            (MPACK_EXPAND((!(MPACK_EXTRACT_ARG0(__VA_ARGS__))) ? \
                (MPACK_UNREACHABLE, (void)0) : \
                (void)0))
    #define mpack_break(...) ((void)0)
#endif


/* Wrap some needed libc functions */

#if MPACK_STDLIB
    #define mpack_memcmp memcmp
    #define mpack_memcpy memcpy
    #define mpack_memmove memmove
    #define mpack_memset memset
    #ifndef mpack_strlen
        #define mpack_strlen strlen
    #endif

#elif defined(__GNUC__) && !MPACK_NO_BUILTINS
    // there's not always a builtin memmove for GCC,
    // and we don't have a way to test for it
    #define mpack_memcmp __builtin_memcmp
    #define mpack_memcpy __builtin_memcpy
    #define mpack_memset __builtin_memset
    #define mpack_strlen __builtin_strlen

#elif defined(__clang__) && defined(__has_builtin) && !MPACK_NO_BUILTINS
    #if __has_builtin(__builtin_memcmp)
    #define mpack_memcmp __builtin_memcmp
    #endif
    #if __has_builtin(__builtin_memcpy)
    #define mpack_memcpy __builtin_memcpy
    #endif
    #if __has_builtin(__builtin_memmove)
    #define mpack_memmove __builtin_memmove
    #endif
    #if __has_builtin(__builtin_memset)
    #define mpack_memset __builtin_memset
    #endif
    #if __has_builtin(__builtin_strlen)
    #define mpack_strlen __builtin_strlen
    #endif
#endif

#ifndef mpack_memcmp
int mpack_memcmp(const void* s1, const void* s2, size_t n);
#endif
#ifndef mpack_memcpy
void* mpack_memcpy(void* MPACK_RESTRICT s1, const void* MPACK_RESTRICT s2, size_t n);
#endif
#ifndef mpack_memmove
void* mpack_memmove(void* s1, const void* s2, size_t n);
#endif
#ifndef mpack_memset
void* mpack_memset(void* s, int c, size_t n);
#endif
#ifndef mpack_strlen
size_t mpack_strlen(const char* s);
#endif

#if MPACK_DEBUG
/* Debug logging */
    #define mpack_log(...) ((void)0)
#endif

/* Make sure our configuration makes sense */
#if defined(MPACK_MALLOC) && !defined(MPACK_FREE)
    #error "MPACK_MALLOC requires MPACK_FREE."
#endif
#if !defined(MPACK_MALLOC) && defined(MPACK_FREE)
    #error "MPACK_FREE requires MPACK_MALLOC."
#endif
#ifndef MPACK_MALLOC

#endif



/* Implement realloc if unavailable */
#ifdef MPACK_MALLOC
    #ifdef MPACK_REALLOC
        MPACK_INLINE void* mpack_realloc(void* old_ptr, size_t used_size, size_t new_size) {
            MPACK_UNUSED(used_size);
            return MPACK_REALLOC(old_ptr, new_size);
        }
    #else
        void* mpack_realloc(void* old_ptr, size_t used_size, size_t new_size);
    #endif
#endif



/**
 * @}
 */

MPACK_HEADER_END

#endif


/* mpack/mpack-common.h.h */

/**
 * @file
 *
 * Defines types and functions shared by the MPack reader and writer.
 */

#ifndef MPACK_COMMON_H
#define MPACK_COMMON_H 1

/* #include "mpack-platform.h" */

#ifndef MPACK_PRINT_BYTE_COUNT
#define MPACK_PRINT_BYTE_COUNT 12
#endif

MPACK_HEADER_START



/**
 * @defgroup common Tags and Common Elements
 *
 * Contains types, constants and functions shared by both the encoding
 * and decoding portions of MPack.
 *
 * @{
 */

/* Version information */

#define MPACK_VERSION_MAJOR 1  /**< The major version number of MPack. */
#define MPACK_VERSION_MINOR 0  /**< The minor version number of MPack. */
#define MPACK_VERSION_PATCH 0  /**< The patch version number of MPack. */

/** A number containing the version number of MPack for comparison purposes. */
#define MPACK_VERSION ((MPACK_VERSION_MAJOR * 10000) + \
        (MPACK_VERSION_MINOR * 100) + MPACK_VERSION_PATCH)

/** A macro to test for a minimum version of MPack. */
#define MPACK_VERSION_AT_LEAST(major, minor, patch) \
        (MPACK_VERSION >= (((major) * 10000) + ((minor) * 100) + (patch)))

/** @cond */
#if (MPACK_VERSION_PATCH > 0)
#define MPACK_VERSION_STRING_BASE \
        MPACK_STRINGIFY(MPACK_VERSION_MAJOR) "." \
        MPACK_STRINGIFY(MPACK_VERSION_MINOR) "." \
        MPACK_STRINGIFY(MPACK_VERSION_PATCH)
#else
#define MPACK_VERSION_STRING_BASE \
        MPACK_STRINGIFY(MPACK_VERSION_MAJOR) "." \
        MPACK_STRINGIFY(MPACK_VERSION_MINOR)
#endif
/** @endcond */

/**
 * @def MPACK_VERSION_STRING
 * @hideinitializer
 *
 * A string containing the MPack version.
 */
#if MPACK_RELEASE_VERSION
#define MPACK_VERSION_STRING MPACK_VERSION_STRING_BASE
#else
#define MPACK_VERSION_STRING MPACK_VERSION_STRING_BASE "dev"
#endif

/**
 * @def MPACK_LIBRARY_STRING
 * @hideinitializer
 *
 * A string describing MPack, containing the library name, version and debug mode.
 */
#define MPACK_LIBRARY_STRING "MPack " MPACK_VERSION_STRING

/** @cond */
/**
 * @def MPACK_MAXIMUM_TAG_SIZE
 *
 * The maximum encoded size of a tag in bytes.
 */
#define MPACK_MAXIMUM_TAG_SIZE 9
/** @endcond */

#if MPACK_EXTENSIONS
/**
 * @def MPACK_TIMESTAMP_NANOSECONDS_MAX
 *
 * The maximum value of nanoseconds for a timestamp.
 *
 * @note This requires @ref MPACK_EXTENSIONS.
 */
#define MPACK_TIMESTAMP_NANOSECONDS_MAX 999999999
#endif

#endif
/**
 * Error states for MPack objects.
 *
 * When a reader, writer, or tree is in an error state, all subsequent calls
 * are ignored and their return values are nil/zero. You should check whether
 * the source is in an error state before using such values.
 */
typedef enum mpack_error_t {
    mpack_ok = 0,        /**< No error. */
    mpack_error_io = 2,  /**< The reader or writer failed to fill or flush, or some other file or socket error occurred. */
    mpack_error_invalid, /**< The data read is not valid MessagePack. */
    mpack_error_unsupported, /**< The data read is not supported by this configuration of MPack. (See @ref MPACK_EXTENSIONS.) */
    mpack_error_type,    /**< The type or value range did not match what was expected by the caller. */
    mpack_error_too_big, /**< A read or write was bigger than the maximum size allowed for that operation. */
    mpack_error_memory,  /**< An allocation failure occurred. */
    mpack_error_bug,     /**< The MPack API was used incorrectly. (This will always assert in debug mode.) */
    mpack_error_data,    /**< The contained data is not valid. */
    mpack_error_eof,     /**< The reader failed to read because of file or socket EOF */
} mpack_error_t;

/**
 * Converts an MPack error to a string. This function returns an empty
 * string when MPACK_DEBUG is not set.
 */
const char* mpack_error_to_string(mpack_error_t error);

/**
 * Defines the type of a MessagePack tag.
 *
 * Note that extension types, both user defined and built-in, are represented
 * in tags as @ref mpack_type_ext. The value for an extension type is stored
 * separately.
 */
typedef enum mpack_type_t {
    mpack_type_missing = 0, /**< Special type indicating a missing optional value. */
    mpack_type_nil,         /**< A null value. */
    mpack_type_bool,        /**< A boolean (true or false.) */
    mpack_type_int,         /**< A 64-bit signed integer. */
    mpack_type_uint,        /**< A 64-bit unsigned integer. */
    mpack_type_float,       /**< A 32-bit IEEE 754 floating point number. */
    mpack_type_double,      /**< A 64-bit IEEE 754 floating point number. */
    mpack_type_str,         /**< A string. */
    mpack_type_array,       /**< An array of MessagePack objects. */
    mpack_type_map,         /**< An ordered map of key/value pairs of MessagePack objects. */

} mpack_type_t;

/**
 * Converts an MPack type to a string. This function returns an empty
 * string when MPACK_DEBUG is not set.
 */
const char* mpack_type_to_string(mpack_type_t type);



/**
 * An MPack tag is a MessagePack object header. It is a variant type
 * representing any kind of object, and includes the length of compound types
 * (e.g. map, array, string) or the value of non-compound types (e.g. boolean,
 * integer, float.)
 *
 * If the type is compound (str, bin, ext, array or map), the contained
 * elements or bytes are stored separately.
 *
 * This structure is opaque; its fields should not be accessed outside
 * of MPack.
 */
typedef struct mpack_tag_t mpack_tag_t;

/* Hide internals from documentation */
/** @cond */
struct mpack_tag_t {
    mpack_type_t type; /*< The type of value. */

    /* The value for non-compound types. */
    union {
        uint64_t u; /*< The value if the type is unsigned int. */
        int64_t  i; /*< The value if the type is signed int. */
        double   d; /*< The value if the type is double. */
        float    f; /*< The value if the type is float. */
        bool     b; /*< The value if the type is bool. */
        /* The number of bytes if the type is str, bin or ext. */
        uint32_t l;
        /* The element count if the type is an array, or the number of
            key/value pairs if the type is map. */
        uint32_t n;
    } v;
};
/** @endcond */

/**
 * @name Tag Generators
 * @{
 */

/**
 * @def MPACK_TAG_ZERO
 *
 * An @ref mpack_tag_t initializer that zeroes the given tag.
 *
 * @warning This does not make the tag nil! The tag's type is invalid when
 * initialized this way. Use @ref mpack_tag_make_nil() to generate a nil tag.
 */

#define MPACK_TAG_ZERO {(mpack_type_t)0, {0}}

/** Generates a nil tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_nil(void) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_nil;
    return ret;
}

/** Generates a bool tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_bool(bool value) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_bool;
    ret.v.b = value;
    return ret;
}

/** Generates a bool tag with value true. */
MPACK_INLINE mpack_tag_t mpack_tag_make_true(void) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_bool;
    ret.v.b = true;
    return ret;
}

/** Generates a bool tag with value false. */
MPACK_INLINE mpack_tag_t mpack_tag_make_false(void) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_bool;
    ret.v.b = false;
    return ret;
}


/** Generates a signed int tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_int(int64_t value) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_int;
    ret.v.i = value;
    return ret;
}


/** Generates an unsigned int tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_uint(uint64_t value) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_uint;
    ret.v.u = value;
    return ret;
}

/** Generates a float tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_float(float value) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_float;
    ret.v.f = value;
    return ret;
}

/** Generates a double tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_double(double value) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_double;
    ret.v.d = value;
    return ret;
}



/** Generates an array tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_array(uint32_t count) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_array;
    ret.v.n = count;
    return ret;
}


/** Generates a map tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_map(uint32_t count) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_map;
    ret.v.n = count;
    return ret;
}

/** Generates a str tag. */
MPACK_INLINE mpack_tag_t mpack_tag_make_str(uint32_t length) {
    mpack_tag_t ret = MPACK_TAG_ZERO;
    ret.type = mpack_type_str;
    ret.v.l = length;
    return ret;
}

/**
 * @}
 */

/**
 * @name Tag Querying Functions
 * @{
 */

/**
 * Gets the type of a tag.
 */
MPACK_INLINE mpack_type_t mpack_tag_type(mpack_tag_t* tag) {
    return tag->type;
}

/**
 * Gets the boolean value of a bool-type tag. The tag must be of type @ref
 * mpack_type_bool.
 *
 * This asserts that the type in the tag is @ref mpack_type_bool. (No check is
 * performed if MPACK_DEBUG is not set.)
 */
MPACK_INLINE bool mpack_tag_bool_value(mpack_tag_t* tag) {
    mpack_assert(tag->type == mpack_type_bool, "tag is not a bool!");
    return tag->v.b;
}

/**
 * Gets the signed integer value of an int-type tag.
 *
 * This asserts that the type in the tag is @ref mpack_type_int. (No check is
 * performed if MPACK_DEBUG is not set.)
 *
 * @warning This does not convert between signed and unsigned tags! A positive
 * integer may be stored in a tag as either @ref mpack_type_int or @ref
 * mpack_type_uint. You must check the type first; this can only be used if the
 * type is @ref mpack_type_int.
 *
 * @see mpack_type_int
 */
MPACK_INLINE int64_t mpack_tag_int_value(mpack_tag_t* tag) {
    mpack_assert(tag->type == mpack_type_int, "tag is not an int!");
    return tag->v.i;
}

/**
 * Gets the unsigned integer value of a uint-type tag.
 *
 * This asserts that the type in the tag is @ref mpack_type_uint. (No check is
 * performed if MPACK_DEBUG is not set.)
 *
 * @warning This does not convert between signed and unsigned tags! A positive
 * integer may be stored in a tag as either @ref mpack_type_int or @ref
 * mpack_type_uint. You must check the type first; this can only be used if the
 * type is @ref mpack_type_uint.
 *
 * @see mpack_type_uint
 */
MPACK_INLINE uint64_t mpack_tag_uint_value(mpack_tag_t* tag) {
    mpack_assert(tag->type == mpack_type_uint, "tag is not a uint!");
    return tag->v.u;
}

/**
 * Gets the float value of a float-type tag.
 *
 * This asserts that the type in the tag is @ref mpack_type_float. (No check is
 * performed if MPACK_DEBUG is not set.)
 *
 * @warning This does not convert between float and double tags! This can only
 * be used if the type is @ref mpack_type_float.
 *
 * @see mpack_type_float
 */
MPACK_INLINE float mpack_tag_float_value(mpack_tag_t* tag) {
    mpack_assert(tag->type == mpack_type_float, "tag is not a float!");
    return tag->v.f;
}

/**
 * Gets the double value of a double-type tag.
 *
 * This asserts that the type in the tag is @ref mpack_type_double. (No check
 * is performed if MPACK_DEBUG is not set.)
 *
 * @warning This does not convert between float and double tags! This can only
 * be used if the type is @ref mpack_type_double.
 *
 * @see mpack_type_double
 */
MPACK_INLINE double mpack_tag_double_value(mpack_tag_t* tag) {
    mpack_assert(tag->type == mpack_type_double, "tag is not a double!");
    return tag->v.d;
}


/**
 * Gets the number of elements in an array tag.
 *
 * This asserts that the type in the tag is @ref mpack_type_array. (No check is
 * performed if MPACK_DEBUG is not set.)
 *
 * @see mpack_type_array
 */
MPACK_INLINE uint32_t mpack_tag_array_count(mpack_tag_t* tag) {
    mpack_assert(tag->type == mpack_type_array, "tag is not an array!");
    return tag->v.n;
}


/**
 * Gets the number of key-value pairs in a map tag.
 *
 * This asserts that the type in the tag is @ref mpack_type_map. (No check is
 * performed if MPACK_DEBUG is not set.)
 *
 * @see mpack_type_map
 */
MPACK_INLINE uint32_t mpack_tag_map_count(mpack_tag_t* tag) {
    mpack_assert(tag->type == mpack_type_map, "tag is not a map!");
    return tag->v.n;
}

/**
 * Gets the length in bytes of a str-type tag.
 *
 * This asserts that the type in the tag is @ref mpack_type_str. (No check is
 * performed if MPACK_DEBUG is not set.)
 *
 * @see mpack_type_str
 */
MPACK_INLINE uint32_t mpack_tag_str_length(mpack_tag_t* tag) {
    mpack_assert(tag->type == mpack_type_str, "tag is not a str!");
    return tag->v.l;
}

/**
 * @}
 */


/**
 * Compares two tags with an arbitrary fixed ordering. Returns 0 if the tags are
 * equal, a negative integer if left comes before right, or a positive integer
 * otherwise.
 *
 * \warning The ordering is not guaranteed to be preserved across MPack versions; do
 * not rely on it in persistent data.
 *
 * \warning Floating point numbers are compared bit-for-bit, not using the language's
 * operator==. This means that NaNs with matching representation will compare equal.
 * This behaviour is up for debate; see comments in the definition of mpack_tag_cmp().
 *
 * See mpack_tag_equal() for more information on when tags are considered equal.
 */
int mpack_tag_cmp(mpack_tag_t left, mpack_tag_t right);

/**
 * Compares two tags for equality. Tags are considered equal if the types are compatible
 * and the values (for non-compound types) are equal.
 *
 * The field width of variable-width fields is ignored (and in fact is not stored
 * in a tag), and positive numbers in signed integers are considered equal to their
 * unsigned counterparts. So for example the value 1 stored as a positive fixint
 * is equal to the value 1 stored in a 64-bit unsigned integer field.
 *
 * The "extension type" of an extension object is considered part of the value
 * and must match exactly.
 *
 * \warning Floating point numbers are compared bit-for-bit, not using the language's
 * operator==. This means that NaNs with matching representation will compare equal.
 * This behaviour is up for debate; see comments in the definition of mpack_tag_cmp().
 */
MPACK_INLINE bool mpack_tag_equal(mpack_tag_t left, mpack_tag_t right) {
    return mpack_tag_cmp(left, right) == 0;
}

/**
 * @}
 */


/** @cond */

/*
 * Helpers to perform unaligned network-endian loads and stores
 * at arbitrary addresses. Byte-swapping builtins are used if they
 * are available and if they improve performance.
 *
 * These will remain available in the public API so feel free to
 * use them for other purposes, but they are undocumented.
 */

MPACK_INLINE uint8_t mpack_load_u8(const char* p) {
    return (uint8_t)p[0];
}

MPACK_INLINE uint16_t mpack_load_u16(const char* p) {
    #ifdef MPACK_NHSWAP16
    uint16_t val;
    mpack_memcpy(&val, p, sizeof(val));
    return MPACK_NHSWAP16(val);
    #else
    return (uint16_t)((((uint16_t)(uint8_t)p[0]) << 8) |
           ((uint16_t)(uint8_t)p[1]));
    #endif
}

MPACK_INLINE uint32_t mpack_load_u32(const char* p) {
    #ifdef MPACK_NHSWAP32
    uint32_t val;
    mpack_memcpy(&val, p, sizeof(val));
    return MPACK_NHSWAP32(val);
    #else
    return (((uint32_t)(uint8_t)p[0]) << 24) |
           (((uint32_t)(uint8_t)p[1]) << 16) |
           (((uint32_t)(uint8_t)p[2]) <<  8) |
            ((uint32_t)(uint8_t)p[3]);
    #endif
}



MPACK_INLINE uint64_t mpack_load_u64(const char* p) {
    #ifdef MPACK_NHSWAP64
    uint64_t val;
    mpack_memcpy(&val, p, sizeof(val));
    return MPACK_NHSWAP64(val);
    #else
    return (((uint64_t)(uint8_t)p[0]) << 56) |
           (((uint64_t)(uint8_t)p[1]) << 48) |
           (((uint64_t)(uint8_t)p[2]) << 40) |
           (((uint64_t)(uint8_t)p[3]) << 32) |
           (((uint64_t)(uint8_t)p[4]) << 24) |
           (((uint64_t)(uint8_t)p[5]) << 16) |
           (((uint64_t)(uint8_t)p[6]) <<  8) |
            ((uint64_t)(uint8_t)p[7]);
    #endif
}

MPACK_INLINE void mpack_store_u8(char* p, uint8_t val) {
    uint8_t* u = (uint8_t*)p;
    u[0] = val;
}

MPACK_INLINE void mpack_store_u16(char* p, uint16_t val) {
    #ifdef MPACK_NHSWAP16
    val = MPACK_NHSWAP16(val);
    mpack_memcpy(p, &val, sizeof(val));
    #else
    uint8_t* u = (uint8_t*)p;
    u[0] = (uint8_t)((val >> 8) & 0xFF);
    u[1] = (uint8_t)( val       & 0xFF);
    #endif
}

MPACK_INLINE void mpack_store_u32(char* p, uint32_t val) {
    #ifdef MPACK_NHSWAP32
    val = MPACK_NHSWAP32(val);
    mpack_memcpy(p, &val, sizeof(val));
    #else
    uint8_t* u = (uint8_t*)p;
    u[0] = (uint8_t)((val >> 24) & 0xFF);
    u[1] = (uint8_t)((val >> 16) & 0xFF);
    u[2] = (uint8_t)((val >>  8) & 0xFF);
    u[3] = (uint8_t)( val        & 0xFF);
    #endif
}

MPACK_INLINE void mpack_store_u64(char* p, uint64_t val) {
    #ifdef MPACK_NHSWAP64
    val = MPACK_NHSWAP64(val);
    mpack_memcpy(p, &val, sizeof(val));
    #else
    uint8_t* u = (uint8_t*)p;
    u[0] = (uint8_t)((val >> 56) & 0xFF);
    u[1] = (uint8_t)((val >> 48) & 0xFF);
    u[2] = (uint8_t)((val >> 40) & 0xFF);
    u[3] = (uint8_t)((val >> 32) & 0xFF);
    u[4] = (uint8_t)((val >> 24) & 0xFF);
    u[5] = (uint8_t)((val >> 16) & 0xFF);
    u[6] = (uint8_t)((val >>  8) & 0xFF);
    u[7] = (uint8_t)( val        & 0xFF);
    #endif
}

MPACK_INLINE int8_t  mpack_load_i8 (const char* p) {return (int8_t) mpack_load_u8 (p);}
MPACK_INLINE int16_t mpack_load_i16(const char* p) {return (int16_t)mpack_load_u16(p);}
MPACK_INLINE int32_t mpack_load_i32(const char* p) {return (int32_t)mpack_load_u32(p);}
MPACK_INLINE int64_t mpack_load_i64(const char* p) {return (int64_t)mpack_load_u64(p);}
MPACK_INLINE void mpack_store_i8 (char* p, int8_t  val) {mpack_store_u8 (p, (uint8_t) val);}
MPACK_INLINE void mpack_store_i16(char* p, int16_t val) {mpack_store_u16(p, (uint16_t)val);}
MPACK_INLINE void mpack_store_i32(char* p, int32_t val) {mpack_store_u32(p, (uint32_t)val);}
MPACK_INLINE void mpack_store_i64(char* p, int64_t val) {mpack_store_u64(p, (uint64_t)val);}

MPACK_INLINE float mpack_load_float(const char* p) {
    MPACK_CHECK_FLOAT_ORDER();
    MPACK_STATIC_ASSERT(sizeof(float) == sizeof(uint32_t), "float is wrong size??");
    union {
        float f;
        uint32_t u;
    } v;
    v.u = mpack_load_u32(p);
    return v.f;
}
MPACK_INLINE void mpack_store_float(char* p, float value) {
    MPACK_CHECK_FLOAT_ORDER();
    union {
        float f;
        uint32_t u;
    } v;
    v.f = value;
    mpack_store_u32(p, v.u);
}


MPACK_INLINE double mpack_load_double(const char* p) {
    MPACK_CHECK_FLOAT_ORDER();
    MPACK_STATIC_ASSERT(sizeof(double) == sizeof(uint64_t), "double is wrong size??");
    union {
        double d;
        uint64_t u;
    } v;
    v.u = mpack_load_u64(p);
    return v.d;
}

MPACK_INLINE void mpack_store_double(char* p, double value) {
    MPACK_CHECK_FLOAT_ORDER();
    union {
        double d;
        uint64_t u;
    } v;
    v.d = value;
    mpack_store_u64(p, v.u);
}





/** @endcond */



/** @cond */

// Sizes in bytes for the various possible tags
#define MPACK_TAG_SIZE_FIXUINT  1
#define MPACK_TAG_SIZE_U8       2
#define MPACK_TAG_SIZE_U16      3
#define MPACK_TAG_SIZE_U32      5
#define MPACK_TAG_SIZE_U64      9
#define MPACK_TAG_SIZE_FIXINT   1
#define MPACK_TAG_SIZE_I8       2
#define MPACK_TAG_SIZE_I16      3
#define MPACK_TAG_SIZE_I32      5
#define MPACK_TAG_SIZE_I64      9
#define MPACK_TAG_SIZE_FLOAT    5
#define MPACK_TAG_SIZE_DOUBLE   9
#define MPACK_TAG_SIZE_FIXARRAY 1
#define MPACK_TAG_SIZE_ARRAY16  3
#define MPACK_TAG_SIZE_ARRAY32  5
#define MPACK_TAG_SIZE_FIXMAP   1
#define MPACK_TAG_SIZE_MAP16    3
#define MPACK_TAG_SIZE_MAP32    5
#define MPACK_TAG_SIZE_FIXSTR   1
#define MPACK_TAG_SIZE_STR8     2
#define MPACK_TAG_SIZE_STR16    3
#define MPACK_TAG_SIZE_STR32    5
#define MPACK_TAG_SIZE_BIN8     2
#define MPACK_TAG_SIZE_BIN16    3
#define MPACK_TAG_SIZE_BIN32    5
#define MPACK_TAG_SIZE_FIXEXT1  2
#define MPACK_TAG_SIZE_FIXEXT2  2
#define MPACK_TAG_SIZE_FIXEXT4  2
#define MPACK_TAG_SIZE_FIXEXT8  2
#define MPACK_TAG_SIZE_FIXEXT16 2
#define MPACK_TAG_SIZE_EXT8     3
#define MPACK_TAG_SIZE_EXT16    4
#define MPACK_TAG_SIZE_EXT32    6

// size in bytes for complete ext types
#define MPACK_EXT_SIZE_TIMESTAMP4 (MPACK_TAG_SIZE_FIXEXT4 + 4)
#define MPACK_EXT_SIZE_TIMESTAMP8 (MPACK_TAG_SIZE_FIXEXT8 + 8)
#define MPACK_EXT_SIZE_TIMESTAMP12 (MPACK_TAG_SIZE_EXT8 + 12)

/** @endcond */

#if MPACK_INTERNAL
/** @cond */



/* Miscellaneous string functions */

/**
 * Returns true if the given string has no null bytes.
 */
bool mpack_str_check_no_null(const char* str, size_t bytes);



/** @endcond */
#endif



/**
 * @}
 */

/**
 * @}
 */

MPACK_HEADER_END

#endif


/* mpack/mpack-writer.h.h */

/**
 * @file
 *
 * Declares the MPack Writer.
 */

#ifndef MPACK_WRITER_H
#define MPACK_WRITER_H 1

/* #include "mpack-common.h" */

MPACK_HEADER_START

#if MPACK_WRITER

/**
 * @defgroup writer Write API
 *
 * The MPack Write API encodes structured data of a fixed (hardcoded) schema to MessagePack.
 *
 * @{
 */

/**
 * @def MPACK_WRITER_MINIMUM_BUFFER_SIZE
 *
 * The minimum buffer size for a writer with a flush function.
 */
#define MPACK_WRITER_MINIMUM_BUFFER_SIZE 32

/**
 * A buffered MessagePack encoder.
 *
 * The encoder wraps an existing buffer and, optionally, a flush function.
 * This allows efficiently encoding to an in-memory buffer or to a stream.
 *
 * All write operations are synchronous; they will block until the
 * data is fully written, or an error occurs.
 */
typedef struct mpack_writer_t mpack_writer_t;

/**
 * The MPack writer's flush function to flush the buffer to the output stream.
 * It should flag an appropriate error on the writer if flushing fails (usually
 * mpack_error_io or mpack_error_memory.)
 *
 * The specified context for callbacks is at writer->context.
 */
typedef void (*mpack_writer_flush_t)(mpack_writer_t* writer, const char* buffer, size_t count);

/**
 * An error handler function to be called when an error is flagged on
 * the writer.
 *
 * The error handler will only be called once on the first error flagged;
 * any subsequent writes and errors are ignored, and the writer is
 * permanently in that error state.
 *
 * MPack is safe against non-local jumps out of error handler callbacks.
 * This means you are allowed to longjmp or throw an exception (in C++,
 * Objective-C, or with SEH) out of this callback.
 *
 * Bear in mind when using longjmp that local non-volatile variables that
 * have changed are undefined when setjmp() returns, so you can't put the
 * writer on the stack in the same activation frame as the setjmp without
 * declaring it volatile.
 *
 * You must still eventually destroy the writer. It is not destroyed
 * automatically when an error is flagged. It is safe to destroy the
 * writer within this error callback, but you will either need to perform
 * a non-local jump, or store something in your context to identify
 * that the writer is destroyed since any future accesses to it cause
 * undefined behavior.
 */
typedef void (*mpack_writer_error_t)(mpack_writer_t* writer, mpack_error_t error);

/**
 * A teardown function to be called when the writer is destroyed.
 */
typedef void (*mpack_writer_teardown_t)(mpack_writer_t* writer);

/* Hide internals from documentation */
/** @cond */

struct mpack_writer_t {
    mpack_writer_flush_t flush;       /* Function to write bytes to the output stream */
    mpack_writer_error_t error_fn;    /* Function to call on error */
    mpack_writer_teardown_t teardown; /* Function to teardown the context on destroy */
    void* context;                    /* Context for writer callbacks */

    char* buffer;         /* Byte buffer */
    char* current;        /* Current position within the buffer */
    char* end;            /* The end of the buffer */
    mpack_error_t error;  /* Error state */

    #ifdef MPACK_MALLOC
    /* Reserved. You can use this space to allocate a custom
     * context in order to reduce heap allocations. */
    void* reserved[2];
    #endif
};
MPACK_INLINE void mpack_writer_track_push(mpack_writer_t* writer, mpack_type_t type, uint64_t count) {
    MPACK_UNUSED(writer);
    MPACK_UNUSED(type);
    MPACK_UNUSED(count);
}
MPACK_INLINE void mpack_writer_track_pop(mpack_writer_t* writer, mpack_type_t type) {
    MPACK_UNUSED(writer);
    MPACK_UNUSED(type);
}
MPACK_INLINE void mpack_writer_track_element(mpack_writer_t* writer) {
    MPACK_UNUSED(writer);
}
MPACK_INLINE void mpack_writer_track_bytes(mpack_writer_t* writer, size_t count) {
    MPACK_UNUSED(writer);
    MPACK_UNUSED(count);
}

/** @endcond */

/**
 * @name Lifecycle Functions
 * @{
 */

/**
 * Initializes an MPack writer with the given buffer. The writer
 * does not assume ownership of the buffer.
 *
 * Trying to write past the end of the buffer will result in mpack_error_too_big
 * unless a flush function is set with mpack_writer_set_flush(). To use the data
 * without flushing, call mpack_writer_buffer_used() to determine the number of
 * bytes written.
 *
 * @param writer The MPack writer.
 * @param buffer The buffer into which to write MessagePack data.
 * @param size The size of the buffer.
 */
void mpack_writer_init(mpack_writer_t* writer, char* buffer, size_t size);

#ifdef MPACK_MALLOC
/**
 * Initializes an MPack writer using a growable buffer.
 *
 * The data is placed in the given data pointer if and when the writer
 * is destroyed without error. The data pointer is NULL during writing,
 * and will remain NULL if an error occurs.
 *
 * The allocated data must be freed with MPACK_FREE() (or simply free()
 * if MPack's allocator hasn't been customized.)
 *
 * @throws mpack_error_memory if the buffer fails to grow when
 * flushing.
 *
 * @param writer The MPack writer.
 * @param data Where to place the allocated data.
 * @param size Where to write the size of the data.
 */
void mpack_writer_init_growable(mpack_writer_t* writer, char** data, size_t* size);
#endif

/**
 * Initializes an MPack writer directly into an error state. Use this if you
 * are writing a wrapper to mpack_writer_init() which can fail its setup.
 */
void mpack_writer_init_error(mpack_writer_t* writer, mpack_error_t error);


/** @cond */

#define mpack_writer_init_stack_line_ex(line, writer) \
    char mpack_buf_##line[MPACK_STACK_SIZE]; \
    mpack_writer_init(writer, mpack_buf_##line, sizeof(mpack_buf_##line))

#define mpack_writer_init_stack_line(line, writer) \
    mpack_writer_init_stack_line_ex(line, writer)

/*
 * Initializes an MPack writer using stack space as a buffer. A flush function
 * should be added to the writer to flush the buffer.
 *
 * This is currently undocumented since it's not entirely useful on its own.
 */

#define mpack_writer_init_stack(writer) \
    mpack_writer_init_stack_line(__LINE__, (writer))

/** @endcond */

/**
 * Cleans up the MPack writer, flushing and closing the underlying stream,
 * if any. Returns the final error state of the writer.
 *
 * No flushing is performed if the writer is in an error state. The attached
 * teardown function is called whether or not the writer is in an error state.
 *
 * This will assert in tracking mode if the writer is not in an error
 * state and has any unclosed compound types. If you want to cancel
 * writing in the middle of a document, you need to flag an error on
 * the writer before destroying it (such as mpack_error_data).
 *
 * Note that a writer may raise an error and call your error handler during
 * the final flush. It is safe to longjmp or throw out of this error handler,
 * but if you do, the writer will not be destroyed, and the teardown function
 * will not be called. You can still get the writer's error state, and you
 * must call @ref mpack_writer_destroy() again. (The second call is guaranteed
 * not to call your error handler again since the writer is already in an error
 * state.)
 *
 * @see mpack_writer_set_error_handler
 * @see mpack_writer_set_flush
 * @see mpack_writer_set_teardown
 * @see mpack_writer_flag_error
 * @see mpack_error_data
 */
mpack_error_t mpack_writer_destroy(mpack_writer_t* writer);

/**
 * @}
 */

/**
 * @name Configuration
 * @{
 */

/**
 * Sets the custom pointer to pass to the writer callbacks, such as flush
 * or teardown.
 *
 * @param writer The MPack writer.
 * @param context User data to pass to the writer callbacks.
 *
 * @see mpack_writer_context()
 */
MPACK_INLINE void mpack_writer_set_context(mpack_writer_t* writer, void* context) {
    writer->context = context;
}

/**
 * Returns the custom context for writer callbacks.
 *
 * @see mpack_writer_set_context
 * @see mpack_writer_set_flush
 */
MPACK_INLINE void* mpack_writer_context(mpack_writer_t* writer) {
    return writer->context;
}

/**
 * Sets the flush function to write out the data when the buffer is full.
 *
 * If no flush function is used, trying to write past the end of the
 * buffer will result in mpack_error_too_big.
 *
 * This should normally be used with mpack_writer_set_context() to register
 * a custom pointer to pass to the flush function.
 *
 * @param writer The MPack writer.
 * @param flush The function to write out data from the buffer.
 *
 * @see mpack_writer_context()
 */
void mpack_writer_set_flush(mpack_writer_t* writer, mpack_writer_flush_t flush);

/**
 * Sets the error function to call when an error is flagged on the writer.
 *
 * This should normally be used with mpack_writer_set_context() to register
 * a custom pointer to pass to the error function.
 *
 * See the definition of mpack_writer_error_t for more information about
 * what you can do from an error callback.
 *
 * @see mpack_writer_error_t
 * @param writer The MPack writer.
 * @param error_fn The function to call when an error is flagged on the writer.
 */
MPACK_INLINE void mpack_writer_set_error_handler(mpack_writer_t* writer, mpack_writer_error_t error_fn) {
    writer->error_fn = error_fn;
}

/**
 * Sets the teardown function to call when the writer is destroyed.
 *
 * This should normally be used with mpack_writer_set_context() to register
 * a custom pointer to pass to the teardown function.
 *
 * @param writer The MPack writer.
 * @param teardown The function to call when the writer is destroyed.
 */
MPACK_INLINE void mpack_writer_set_teardown(mpack_writer_t* writer, mpack_writer_teardown_t teardown) {
    writer->teardown = teardown;
}

/**
 * @}
 */

/**
 * @name Core Writer Functions
 * @{
 */

/**
 * Flushes any buffered data to the underlying stream.
 *
 * If write tracking is enabled, this will break and flag @ref
 * mpack_error_bug if the writer has any open compound types, ensuring
 * that no compound types are still open. This prevents a "missing
 * finish" bug from causing a never-ending message.
 *
 * If the writer is connected to a socket and you are keeping it open,
 * you will want to call this after writing a message (or set of
 * messages) so that the data is actually sent.
 *
 * It is not necessary to call this if you are not keeping the writer
 * open afterwards. You can just call `mpack_writer_destroy()`, and it
 * will flush before cleaning up.
 *
 * This will assert if no flush function is assigned to the writer.
 */
void mpack_writer_flush_message(mpack_writer_t* writer);

/**
 * Returns the number of bytes currently stored in the buffer. This
 * may be less than the total number of bytes written if bytes have
 * been flushed to an underlying stream.
 */
MPACK_INLINE size_t mpack_writer_buffer_used(mpack_writer_t* writer) {
    return (size_t)(writer->current - writer->buffer);
}

/**
 * Returns the amount of space left in the buffer. This may be reset
 * after a write if bytes are flushed to an underlying stream.
 */
MPACK_INLINE size_t mpack_writer_buffer_left(mpack_writer_t* writer) {
    return (size_t)(writer->end - writer->current);
}

/**
 * Returns the (current) size of the buffer. This may change after a write if
 * the flush callback changes the buffer.
 */
MPACK_INLINE size_t mpack_writer_buffer_size(mpack_writer_t* writer) {
    return (size_t)(writer->end - writer->buffer);
}

/**
 * Places the writer in the given error state, calling the error callback if one
 * is set.
 *
 * This allows you to externally flag errors, for example if you are validating
 * data as you write it, or if you want to cancel writing in the middle of a
 * document. (The writer will assert if you try to destroy it without error and
 * with unclosed compound types. In this case you should flag mpack_error_data
 * before destroying it.)
 *
 * If the writer is already in an error state, this call is ignored and no
 * error callback is called.
 *
 * @see mpack_writer_destroy
 * @see mpack_error_data
 */
void mpack_writer_flag_error(mpack_writer_t* writer, mpack_error_t error);

/**
 * Queries the error state of the MPack writer.
 *
 * If a writer is in an error state, you should discard all data since the
 * last time the error flag was checked. The error flag cannot be cleared.
 */
MPACK_INLINE mpack_error_t mpack_writer_error(mpack_writer_t* writer) {
    return writer->error;
}

/**
 * Writes a MessagePack object header (an MPack Tag.)
 *
 * If the value is a map, array, string, binary or extension type, the
 * containing elements or bytes must be written separately and the
 * appropriate finish function must be called (as though one of the
 * mpack_start_*() functions was called.)
 *
 * @see mpack_write_bytes()
 * @see mpack_finish_map()
 * @see mpack_finish_array()
 * @see mpack_finish_str()
 * @see mpack_finish_ext()
 * @see mpack_finish_type()
 */
void mpack_write_tag(mpack_writer_t* writer, mpack_tag_t tag);

/**
 * @}
 */

/**
 * @name Integers
 * @{
 */

/** Writes an 8-bit integer in the most efficient packing available. */
void mpack_write_i8(mpack_writer_t* writer, int8_t value);

/** Writes a 16-bit integer in the most efficient packing available. */
void mpack_write_i16(mpack_writer_t* writer, int16_t value);

/** Writes a 32-bit integer in the most efficient packing available. */
void mpack_write_i32(mpack_writer_t* writer, int32_t value);

/** Writes a 64-bit integer in the most efficient packing available. */
void mpack_write_i64(mpack_writer_t* writer, int64_t value);

/** Writes an integer in the most efficient packing available up to 32 bits. */
void mpack_write_int(mpack_writer_t* writer, int32_t value);

/** Writes an 8-bit unsigned integer in the most efficient packing available. */
void mpack_write_u8(mpack_writer_t* writer, uint8_t value);

/** Writes an 16-bit unsigned integer in the most efficient packing available. */
void mpack_write_u16(mpack_writer_t* writer, uint16_t value);

/** Writes an 32-bit unsigned integer in the most efficient packing available. */
void mpack_write_u32(mpack_writer_t* writer, uint32_t value);

/** Writes an 64-bit unsigned integer in the most efficient packing available. */
void mpack_write_u64(mpack_writer_t* writer, uint64_t value);

/** Writes an unsigned integer in the most efficient packing available up to 32 bits. */
void mpack_write_uint(mpack_writer_t* writer, uint32_t value);

/**
 * @}
 */

/**
 * @name Other Basic Types
 * @{
 */

/** Writes a float. */
void mpack_write_float(mpack_writer_t* writer, float value);
/** Writes a double. */
void mpack_write_double(mpack_writer_t* writer, double value);

/** Writes a boolean. */
void mpack_write_bool(mpack_writer_t* writer, bool value);

/** Writes a boolean with value true. */
void mpack_write_true(mpack_writer_t* writer);

/** Writes a boolean with value false. */
void mpack_write_false(mpack_writer_t* writer);

/** Writes a nil. */
void mpack_write_nil(mpack_writer_t* writer);

/** Write a pre-encoded messagepack object */
void mpack_write_object_bytes(mpack_writer_t* writer, const char* data, size_t bytes);

/**
 * @}
 */

/**
 * @name Map and Array Functions
 * @{
 */

/**
 * Opens an array.
 *
 * `count` elements must follow, and mpack_finish_array() must be called
 * when done.
 *
 * @see mpack_finish_array()
 */
void mpack_start_array(mpack_writer_t* writer, uint32_t count);

/**
 * Opens a map.
 *
 * `count * 2` elements must follow, and mpack_finish_map() must be called
 * when done.
 *
 * Remember that while map elements in MessagePack are implicitly ordered,
 * they are not ordered in JSON. If you need elements to be read back
 * in the order they are written, consider use an array instead.
 *
 * @see mpack_finish_map()
 */
//void mpack_start_map(mpack_writer_t* writer, uint32_t count);
void mpack_start_map(mpack_writer_t* writer, uint8_t count);

#if MPACK_ARRAYS
/**
 * Finishes writing an array.
 *
 * This should be called only after a corresponding call to mpack_start_array()
 * and after the array contents are written.
 *
 * This will track writes to ensure that the correct number of elements are written.
 *
 * @see mpack_start_array()
 */
MPACK_INLINE void mpack_finish_array(mpack_writer_t* writer) {
    mpack_writer_track_pop(writer, mpack_type_array);
}
#endif

/**
 * Finishes writing a map.
 *
 * This should be called only after a corresponding call to mpack_start_map()
 * and after the map contents are written.
 *
 * This will track writes to ensure that the correct number of elements are written.
 *
 * @see mpack_start_map()
 */
MPACK_INLINE void mpack_finish_map(mpack_writer_t* writer) {
    mpack_writer_track_pop(writer, mpack_type_map);
}

/**
 * @}
 */

/**
 * @name Data Helpers
 * @{
 */

/**
 * Writes a string.
 *
 * To stream a string in chunks, use mpack_start_str() instead.
 *
 * MPack does not care about the underlying encoding, but UTF-8 is highly
 * recommended, especially for compatibility with JSON. You should consider
 * calling mpack_write_utf8() instead, especially if you will be reading
 * it back as UTF-8.
 *
 * You should not call mpack_finish_str() after calling this; this
 * performs both start and finish.
 */
void mpack_write_str(mpack_writer_t* writer, const char* str, uint32_t length);


/**
 * Writes a null-terminated string. (The null-terminator is not written.)
 *
 * MPack does not care about the underlying encoding, but UTF-8 is highly
 * recommended, especially for compatibility with JSON. You should consider
 * calling mpack_write_utf8_cstr() instead, especially if you will be reading
 * it back as UTF-8.
 *
 * You should not call mpack_finish_str() after calling this; this
 * performs both start and finish.
 */
void mpack_write_cstr(mpack_writer_t* writer, const char* cstr);

/**
 * Writes a null-terminated string, or a nil node if the given cstr pointer
 * is NULL. (The null-terminator is not written.)
 *
 * MPack does not care about the underlying encoding, but UTF-8 is highly
 * recommended, especially for compatibility with JSON. You should consider
 * calling mpack_write_utf8_cstr_or_nil() instead, especially if you will
 * be reading it back as UTF-8.
 *
 * You should not call mpack_finish_str() after calling this; this
 * performs both start and finish.
 */
void mpack_write_cstr_or_nil(mpack_writer_t* writer, const char* cstr);



/**
 * @}
 */

/**
 * @name Chunked Data Functions
 * @{
 */

/**
 * Opens a string. `count` bytes should be written with calls to
 * mpack_write_bytes(), and mpack_finish_str() should be called
 * when done.
 *
 * To write an entire string at once, use mpack_write_str() or
 * mpack_write_cstr() instead.
 *
 * MPack does not care about the underlying encoding, but UTF-8 is highly
 * recommended, especially for compatibility with JSON.
 */
void mpack_start_str(mpack_writer_t* writer, uint32_t count);

/**
 * Finishes writing a string.
 *
 * This should be called only after a corresponding call to mpack_start_str()
 * and after the string bytes are written with mpack_write_bytes().
 *
 * This will track writes to ensure that the correct number of elements are written.
 *
 * @see mpack_start_str()
 * @see mpack_write_bytes()
 */
MPACK_INLINE void mpack_finish_str(mpack_writer_t* writer) {
    mpack_writer_track_pop(writer, mpack_type_str);
}



/**
 * Finishes writing the given compound type.
 *
 * This will track writes to ensure that the correct number of elements
 * or bytes are written.
 *
 * This can be called with the appropriate type instead the corresponding
 * mpack_finish_*() function if you want to finish a dynamic type.
 */
MPACK_INLINE void mpack_finish_type(mpack_writer_t* writer, mpack_type_t type) {
    mpack_writer_track_pop(writer, type);
}

/**
 * @}
 */

/**
 * @}
 */

#endif

MPACK_HEADER_END

#endif

/* mpack/mpack-reader.h.h */

/**
 * @file
 *
 * Declares the core MPack Tag Reader.
 */

#ifndef MPACK_READER_H
#define MPACK_READER_H 1

/* #include "mpack-common.h" */

MPACK_HEADER_START

#if MPACK_READER

// The denominator to determine whether a read is a small
// fraction of the buffer size.
#define MPACK_READER_SMALL_FRACTION_DENOMINATOR 32

/**
 * @defgroup reader Reader API
 *
 * The MPack Reader API contains functions for imperatively reading dynamically
 * typed data from a MessagePack stream.
 *
 * See @ref docs/reader.md for examples.
 *
 * @note If you are not writing code for an embedded device (or otherwise do
 * not need maximum performance with minimal memory usage), you should not use
 * this. You probably want to use the @link node Node API@endlink instead.
 *
 * This forms the basis of the @link expect Expect API@endlink, which can be
 * used to interpret the stream of elements in expected types and value ranges.
 *
 * @{
 */

/**
 * @def MPACK_READER_MINIMUM_BUFFER_SIZE
 *
 * The minimum buffer size for a reader with a fill function.
 */
#define MPACK_READER_MINIMUM_BUFFER_SIZE 32

/**
 * A buffered MessagePack decoder.
 *
 * The decoder wraps an existing buffer and, optionally, a fill function.
 * This allows efficiently decoding data from existing memory buffers, files,
 * streams, etc.
 *
 * All read operations are synchronous; they will block until the
 * requested data is fully read, or an error occurs.
 *
 * This structure is opaque; its fields should not be accessed outside
 * of MPack.
 */
typedef struct mpack_reader_t mpack_reader_t;

/**
 * The MPack reader's fill function. It should fill the buffer with at
 * least one byte and at most the given @c count, returning the number
 * of bytes written to the buffer.
 *
 * In case of error, it should flag an appropriate error on the reader
 * (usually @ref mpack_error_io), or simply return zero. If zero is
 * returned, mpack_error_io is raised.
 *
 * @note When reading from a stream, you should only copy and return
 * the bytes that are immediately available. It is always safe to return
 * less than the requested count as long as some non-zero number of bytes
 * are read; if more bytes are needed, the read function will simply be
 * called again.
 *
 * @see mpack_reader_context()
 */
typedef size_t (*mpack_reader_fill_t)(mpack_reader_t* reader, char* buffer, size_t count);

/**
 * The MPack reader's skip function. It should discard the given number
 * of bytes from the source (for example by seeking forward.)
 *
 * In case of error, it should flag an appropriate error on the reader.
 *
 * @see mpack_reader_context()
 */
typedef void (*mpack_reader_skip_t)(mpack_reader_t* reader, size_t count);

/**
 * An error handler function to be called when an error is flagged on
 * the reader.
 *
 * The error handler will only be called once on the first error flagged;
 * any subsequent reads and errors are ignored, and the reader is
 * permanently in that error state.
 *
 * MPack is safe against non-local jumps out of error handler callbacks.
 * This means you are allowed to longjmp or throw an exception (in C++,
 * Objective-C, or with SEH) out of this callback.
 *
 * Bear in mind when using longjmp that local non-volatile variables that
 * have changed are undefined when setjmp() returns, so you can't put the
 * reader on the stack in the same activation frame as the setjmp without
 * declaring it volatile.
 *
 * You must still eventually destroy the reader. It is not destroyed
 * automatically when an error is flagged. It is safe to destroy the
 * reader within this error callback, but you will either need to perform
 * a non-local jump, or store something in your context to identify
 * that the reader is destroyed since any future accesses to it cause
 * undefined behavior.
 */
typedef void (*mpack_reader_error_t)(mpack_reader_t* reader, mpack_error_t error);

/**
 * A teardown function to be called when the reader is destroyed.
 */
typedef void (*mpack_reader_teardown_t)(mpack_reader_t* reader);

/* Hide internals from documentation */
/** @cond */

struct mpack_reader_t {
    void* context;                    /* Context for reader callbacks */
    mpack_reader_fill_t fill;         /* Function to read bytes into the buffer */
    mpack_reader_error_t error_fn;    /* Function to call on error */
    mpack_reader_teardown_t teardown; /* Function to teardown the context on destroy */
    mpack_reader_skip_t skip;         /* Function to skip bytes from the source */

    char* buffer;       /* Writeable byte buffer */
    size_t size;        /* Size of the buffer */

    const char* data;   /* Current data pointer (in the buffer, if it is used) */
    const char* end;    /* The end of available data (in the buffer, if it is used) */

    mpack_error_t error;  /* Error state */
};

/** @endcond */

/**
 * @name Lifecycle Functions
 * @{
 */

/**
 * Initializes an MPack reader with the given buffer. The reader does
 * not assume ownership of the buffer, but the buffer must be writeable
 * if a fill function will be used to refill it.
 *
 * @param reader The MPack reader.
 * @param buffer The buffer with which to read MessagePack data.
 * @param size The size of the buffer.
 * @param count The number of bytes already in the buffer.
 */
void mpack_reader_init(mpack_reader_t* reader, char* buffer, size_t size, size_t count);

/**
 * Initializes an MPack reader directly into an error state. Use this if you
 * are writing a wrapper to mpack_reader_init() which can fail its setup.
 */
void mpack_reader_init_error(mpack_reader_t* reader, mpack_error_t error);

/**
 * Initializes an MPack reader to parse a pre-loaded contiguous chunk of data. The
 * reader does not assume ownership of the data.
 *
 * @param reader The MPack reader.
 * @param data The data to parse.
 * @param count The number of bytes pointed to by data.
 */
void mpack_reader_init_data(mpack_reader_t* reader, const char* data, size_t count);


/**
 * @def mpack_reader_init_stack(reader)
 * @hideinitializer
 *
 * Initializes an MPack reader using stack space as a buffer. A fill function
 * should be added to the reader to fill the buffer.
 *
 * @see mpack_reader_set_fill
 */

/** @cond */
#define mpack_reader_init_stack_line_ex(line, reader) \
    char mpack_buf_##line[MPACK_STACK_SIZE]; \
    mpack_reader_init((reader), mpack_buf_##line, sizeof(mpack_buf_##line), 0)

#define mpack_reader_init_stack_line(line, reader) \
    mpack_reader_init_stack_line_ex(line, reader)
/** @endcond */

#define mpack_reader_init_stack(reader) \
    mpack_reader_init_stack_line(__LINE__, (reader))

/**
 * Cleans up the MPack reader, ensuring that all compound elements
 * have been completely read. Returns the final error state of the
 * reader.
 *
 * This will assert in tracking mode if the reader is not in an error
 * state and has any incomplete reads. If you want to cancel reading
 * in the middle of a document, you need to flag an error on the reader
 * before destroying it (such as mpack_error_data).
 *
 * @see mpack_read_tag()
 * @see mpack_reader_flag_error()
 * @see mpack_error_data
 */
mpack_error_t mpack_reader_destroy(mpack_reader_t* reader);

/**
 * @}
 */

/**
 * @name Callbacks
 * @{
 */

/**
 * Sets the custom pointer to pass to the reader callbacks, such as fill
 * or teardown.
 *
 * @param reader The MPack reader.
 * @param context User data to pass to the reader callbacks.
 *
 * @see mpack_reader_context()
 */
MPACK_INLINE void mpack_reader_set_context(mpack_reader_t* reader, void* context) {
    reader->context = context;
}

/**
 * Returns the custom context for reader callbacks.
 *
 * @see mpack_reader_set_context
 * @see mpack_reader_set_fill
 * @see mpack_reader_set_skip
 */
MPACK_INLINE void* mpack_reader_context(mpack_reader_t* reader) {
    return reader->context;
}

/**
 * Sets the fill function to refill the data buffer when it runs out of data.
 *
 * If no fill function is used, truncated MessagePack data results in
 * mpack_error_invalid (since the buffer is assumed to contain a
 * complete MessagePack object.)
 *
 * If a fill function is used, truncated MessagePack data usually
 * results in mpack_error_io (since the fill function fails to get
 * the missing data.)
 *
 * This should normally be used with mpack_reader_set_context() to register
 * a custom pointer to pass to the fill function.
 *
 * @param reader The MPack reader.
 * @param fill The function to fetch additional data into the buffer.
 */
void mpack_reader_set_fill(mpack_reader_t* reader, mpack_reader_fill_t fill);

/**
 * Sets the skip function to discard bytes from the source stream.
 *
 * It's not necessary to implement this function. If the stream is not
 * seekable, don't set a skip callback. The reader will fall back to
 * using the fill function instead.
 *
 * This should normally be used with mpack_reader_set_context() to register
 * a custom pointer to pass to the skip function.
 *
 * The skip function is ignored in size-optimized builds to reduce code
 * size. Data will be skipped with the fill function when necessary.
 *
 * @param reader The MPack reader.
 * @param skip The function to discard bytes from the source stream.
 */
void mpack_reader_set_skip(mpack_reader_t* reader, mpack_reader_skip_t skip);

/**
 * Sets the error function to call when an error is flagged on the reader.
 *
 * This should normally be used with mpack_reader_set_context() to register
 * a custom pointer to pass to the error function.
 *
 * See the definition of mpack_reader_error_t for more information about
 * what you can do from an error callback.
 *
 * @see mpack_reader_error_t
 * @param reader The MPack reader.
 * @param error_fn The function to call when an error is flagged on the reader.
 */
MPACK_INLINE void mpack_reader_set_error_handler(mpack_reader_t* reader, mpack_reader_error_t error_fn) {
    reader->error_fn = error_fn;
}

/**
 * Sets the teardown function to call when the reader is destroyed.
 *
 * This should normally be used with mpack_reader_set_context() to register
 * a custom pointer to pass to the teardown function.
 *
 * @param reader The MPack reader.
 * @param teardown The function to call when the reader is destroyed.
 */
MPACK_INLINE void mpack_reader_set_teardown(mpack_reader_t* reader, mpack_reader_teardown_t teardown) {
    reader->teardown = teardown;
}

/**
 * @}
 */

/**
 * @name Core Reader Functions
 * @{
 */

/**
 * Queries the error state of the MPack reader.
 *
 * If a reader is in an error state, you should discard all data since the
 * last time the error flag was checked. The error flag cannot be cleared.
 */
MPACK_INLINE mpack_error_t mpack_reader_error(mpack_reader_t* reader) {
    return reader->error;
}

/**
 * Places the reader in the given error state, calling the error callback if one
 * is set.
 *
 * This allows you to externally flag errors, for example if you are validating
 * data as you read it.
 *
 * If the reader is already in an error state, this call is ignored and no
 * error callback is called.
 */
void mpack_reader_flag_error(mpack_reader_t* reader, mpack_error_t error);

/**
 * Places the reader in the given error state if the given error is not mpack_ok,
 * returning the resulting error state of the reader.
 *
 * This allows you to externally flag errors, for example if you are validating
 * data as you read it.
 *
 * If the given error is mpack_ok or if the reader is already in an error state,
 * this call is ignored and the actual error state of the reader is returned.
 */
MPACK_INLINE mpack_error_t mpack_reader_flag_if_error(mpack_reader_t* reader, mpack_error_t error) {
    if (error != mpack_ok)
        mpack_reader_flag_error(reader, error);
    return mpack_reader_error(reader);
}

/**
 * Returns bytes left in the reader's buffer.
 *
 * If you are done reading MessagePack data but there is other interesting data
 * following it, the reader may have buffered too much data. The number of bytes
 * remaining in the buffer and a pointer to the position of those bytes can be
 * queried here.
 *
 * If you know the length of the MPack chunk beforehand, it's better to instead
 * have your fill function limit the data it reads so that the reader does not
 * have extra data. In this case you can simply check that this returns zero.
 *
 * Returns 0 if the reader is in an error state.
 *
 * @param reader The MPack reader from which to query remaining data.
 * @param data [out] A pointer to the remaining data, or NULL.
 * @return The number of bytes remaining in the buffer.
 */
size_t mpack_reader_remaining(mpack_reader_t* reader, const char** data);

/**
 * Reads a MessagePack object header (an MPack tag.)
 *
 * If an error occurs, the reader is placed in an error state and a
 * nil tag is returned. If the reader is already in an error state,
 * a nil tag is returned.
 *
 * If the type is compound (i.e. is a map, array, string, binary or
 * extension type), additional reads are required to get the contained
 * data, and the corresponding done function must be called when done.
 *
 * @note Maps in JSON are unordered, so it is recommended not to expect
 * a specific ordering for your map values in case your data is converted
 * to/from JSON.
 *
 * @see mpack_read_bytes()
 * @see mpack_done_array()
 * @see mpack_done_map()
 * @see mpack_done_str()
 * @see mpack_done_ext()
 */
mpack_tag_t mpack_read_tag(mpack_reader_t* reader);

/**
 * Parses the next MessagePack object header (an MPack tag) without
 * advancing the reader.
 *
 * If an error occurs, the reader is placed in an error state and a
 * nil tag is returned. If the reader is already in an error state,
 * a nil tag is returned.
 *
 * @note Maps in JSON are unordered, so it is recommended not to expect
 * a specific ordering for your map values in case your data is converted
 * to/from JSON.
 *
 * @see mpack_read_tag()
 * @see mpack_discard()
 */
mpack_tag_t mpack_peek_tag(mpack_reader_t* reader);

/**
 * @}
 */

/**
 * @name String and Data Functions
 * @{
 */

/**
 * Reads bytes from a string, binary blob or extension object, copying
 * them into the given buffer.
 *
 * A str, bin or ext must have been opened by a call to mpack_read_tag()
 * which yielded one of these types, or by a call to an expect function
 * such as mpack_expect_str() or mpack_expect_bin().
 *
 * If an error occurs, the buffer contents are undefined.
 *
 * This can be called multiple times for a single str, bin or ext
 * to read the data in chunks. The total data read must add up
 * to the size of the object.
 *
 * @param reader The MPack reader
 * @param p The buffer in which to copy the bytes
 * @param count The number of bytes to read
 */
void mpack_read_bytes(mpack_reader_t* reader, char* p, size_t count);

/**
 * Reads bytes from a string, ensures that the string contains no NUL
 * bytes, copies the bytes into the given buffer and adds a null-terminator.
 *
 * A string must have been opened by a call to mpack_read_tag() which
 * yielded a string, or by a call to an expect function such as
 * mpack_expect_str().
 *
 * The given byte count must match the size of the string as returned
 * by the tag or expect function. The string will only be copied if
 * the buffer is large enough to store it.
 *
 * If an error occurs, the buffer will contain an empty string.
 *
 * @note If you know the object will be a string before reading it,
 * it is highly recommended to use mpack_expect_cstr() instead.
 * Alternatively you could use mpack_peek_tag() and call
 * mpack_expect_cstr() if it's a string.
 *
 * @throws mpack_error_too_big if the string plus null-terminator is larger than the given buffer size
 * @throws mpack_error_type if the string contains a null byte.
 *
 * @see mpack_peek_tag()
 * @see mpack_expect_cstr()
 */
void mpack_read_cstr(mpack_reader_t* reader, char* buf, size_t buffer_size, size_t byte_count);


#ifdef MPACK_MALLOC
/** @cond */
// This can optionally add a null-terminator, but it does not check
// whether the data contains null bytes. This must be done separately
// in a cstring read function (possibly as part of a UTF-8 check.)
char* mpack_read_bytes_alloc_impl(mpack_reader_t* reader, size_t count, bool null_terminated);
/** @endcond */


#endif

/**
 * Returns true if it's a good idea to read the given number of bytes
 * in-place.
 *
 * If the read will be larger than some small fraction of the buffer size,
 * this will return false to avoid shuffling too much data back and forth
 * in the buffer.
 *
 * Use this if you're expecting arbitrary size data, and you want to read
 * in-place for the best performance when possible but will fall back to
 * a normal read if the data is too large.
 *
 * @see mpack_read_bytes_inplace()
 */
MPACK_INLINE bool mpack_should_read_bytes_inplace(mpack_reader_t* reader, size_t count) {
    return (reader->size == 0 || count <= reader->size / MPACK_READER_SMALL_FRACTION_DENOMINATOR);
}

/**
 * @}
 */

/**
 * @name Core Reader Functions
 * @{
 */
MPACK_INLINE void mpack_done_type(mpack_reader_t* reader, mpack_type_t type) {
    MPACK_UNUSED(reader);
    MPACK_UNUSED(type);
}

/**
 * Finishes reading an array.
 *
 * This will track reads to ensure that the correct number of elements are read.
 */
MPACK_INLINE void mpack_done_array(mpack_reader_t* reader) {
    mpack_done_type(reader, mpack_type_array);
}

/**
 * @fn mpack_done_map(mpack_reader_t* reader)
 *
 * Finishes reading a map.
 *
 * This will track reads to ensure that the correct number of elements are read.
 */
MPACK_INLINE void mpack_done_map(mpack_reader_t* reader) {
    mpack_done_type(reader, mpack_type_map);
}

/**
 * @fn mpack_done_str(mpack_reader_t* reader)
 *
 * Finishes reading a string.
 *
 * This will track reads to ensure that the correct number of bytes are read.
 */
MPACK_INLINE void mpack_done_str(mpack_reader_t* reader) {
    mpack_done_type(reader, mpack_type_str);
}

/**
 * Reads and discards the next object. This will read and discard all
 * contained data as well if it is a compound type.
 */
void mpack_discard(mpack_reader_t* reader);

/**
 * @}
 */


/**
 * @}
 */



#if MPACK_INTERNAL

bool mpack_reader_ensure_straddle(mpack_reader_t* reader, size_t count);

/*
 * Ensures there are at least @c count bytes left in the
 * data, raising an error and returning false if more
 * data cannot be made available.
 */
MPACK_INLINE bool mpack_reader_ensure(mpack_reader_t* reader, size_t count) {
bool status = false;

    mpack_assert(count != 0, "cannot ensure zero bytes!");
    mpack_assert(reader->error == mpack_ok, "reader cannot be in an error state!");

    if (count <= (size_t)(reader->end - reader->data))
        return true;
#if MPACK_DEBUG
    status = mpack_reader_ensure_straddle(reader, count);
#endif
    return status;
}

void mpack_read_native_straddle(mpack_reader_t* reader, char* p, size_t count);

// Reads count bytes into p, deferring to mpack_read_native_straddle() if more
// bytes are needed than are available in the buffer.
MPACK_INLINE void mpack_read_native(mpack_reader_t* reader, char* p, size_t count) {
    mpack_assert(count == 0 || p != NULL, "data pointer for %i bytes is NULL", (int)count);
#if MPACK_DEBUG
    if (count > (size_t)(reader->end - reader->data)) {
        mpack_read_native_straddle(reader, p, count);
    }
#endif
        mpack_memcpy(p, reader->data, count);
        reader->data += count;
}


#define MPACK_READER_TRACK(reader, error_expr) (MPACK_UNUSED(reader), mpack_ok)

MPACK_INLINE mpack_error_t mpack_reader_track_element(mpack_reader_t* reader) {
    return MPACK_READER_TRACK(reader, mpack_track_element(&reader->track, true));
}

MPACK_INLINE mpack_error_t mpack_reader_track_peek_element(mpack_reader_t* reader) {
    return MPACK_READER_TRACK(reader, mpack_track_peek_element(&reader->track, true));
}

MPACK_INLINE mpack_error_t mpack_reader_track_bytes(mpack_reader_t* reader, uint64_t count) {
    MPACK_UNUSED(count);
    return MPACK_READER_TRACK(reader, mpack_track_bytes(&reader->track, true, count));
}

MPACK_INLINE mpack_error_t mpack_reader_track_str_bytes_all(mpack_reader_t* reader, uint64_t count) {
    MPACK_UNUSED(count);
    return MPACK_READER_TRACK(reader, mpack_track_str_bytes_all(&reader->track, true, count));
}

#endif

#endif

MPACK_HEADER_END

#endif

/* clang-format on */

/**
 * @}
 */
