#   Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

from Crypto.Cipher import AES
from enum import Enum
import hashlib

class cipherMode(Enum):
    MODE_GCM = 0x0040
    MODE_CTR = 0x0030

def hex_string_to_txt(filename, hex_string): 
    o = open(filename, 'w')
    o.write("@00000010\n")
    i = 0
    for x in range(0, len(hex_string), 2): 
        o.write(hex_string[x] + hex_string[x+1])
        if(i < 15): 
            o.write(" ")
        else :
            o.write("\n")
        i = (i + 1) % 16
    if(i != 0): 
        # pad out header to nearest 128-bit buffer such that 
        # UniFlash doesn't complain
        while i < 15: 
            o.write("00 ")
            i += 1
        o.write("00\n")
    # o.write('q')
    o.close()

def old_gcm_header(): 
    #get key from private key-type file
    key = bytes.fromhex("feffe992 8665731c 6d6a8f94 67308308")
    nonce = bytes.fromhex("cafebabe facedbad decaf888")
    aad = bytes.fromhex("feedface deadbeef feedface deadbeef abaddad2")
    plaintext = bytes.fromhex("d9313225 f88406e5 a55909c5 aff5269a \
                                86a7a953 1534f7da 2e4c303d 8a318a72 \
                                1c3c0c95 95680953 2fcf0e24 49a6b525 \
                                b16aedf5 aa0de657 ba637b39")

    #calculate the key hash
    key_hash = hashlib.sha256(key).hexdigest()

    cipher = AES.new(key, AES.MODE_GCM, nonce)
    cipher.update(aad)
    (ciphertext, tag) = cipher.encrypt_and_digest(plaintext)

    #numbers are given in 16-bit little endian
    first_type = "9901004000"
    second_key = "55002000" + key_hash
    third_tag =  "50001000" + tag.hex()
    fourth_iv =  "51000C00" + nonce.hex()
    fifth_aad =  "52001400" + aad.hex()
    hex_string_to_txt(first_type + second_key + third_tag + fourth_iv + fifth_aad)

class Encryptor: 
    mode = AES.MODE_GCM
    key = bytes.fromhex("feffe992 8665731c 6d6a8f94 67308308")
    nonce = bytes.fromhex("cafebabe facedbad decaf888")
    aad = bytes.fromhex("feedface deadbeef feedface deadbeef abaddad2")

    def __init__(self, cipherfile):
        self.cipherfile = cipherfile
        self.cipher = AES.new(Encryptor.key, Encryptor.mode, Encryptor.nonce)
        self.cipher.update(Encryptor.aad)
        self.length = b'\x00\x00\x00\x00'



    def update(self, aad): 
        self.cipher.update(aad)

    def encrypt(self, plaintext):
        return self.cipher.encrypt(plaintext)
    
    def digest(self): 
        return self.cipher.digest()
    
    def set_image_length(self, length): 
        self.length = length.to_bytes(4, byteorder='little')

    def generate_header(self):
        tag = self.cipher.digest()

        key_hash = hashlib.sha256(Encryptor.key).hexdigest()

        first_type = "99994000"
        second_key = "55002000" + key_hash
        third_tag =  "50001000" + tag.hex()
        fourth_iv =  "51000C00" + Encryptor.nonce.hex()
        fifth_length = "52000400" + self.length.hex()
        sixth_aad =  "53001400" + Encryptor.aad.hex()
        end_of_header = "AAAA"
        hex_string_to_txt(self.cipherfile, first_type + second_key + third_tag + fourth_iv + 
                          fifth_length + sixth_aad + end_of_header)



