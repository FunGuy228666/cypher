#include "cyph_lib.hpp"


uint8_t* cypher(uint8_t* data, uint8_t* key, int block_size, int len, uint64_t& out_len_o, int rounds = 1) {
    uint8_t* out = cypher_i(data, key, block_size, len, rounds);
    int out_len = len / block_size;
    if (len % block_size != 0) out_len++;
    uint8_t* out_r = new uint8_t[(out_len * block_size)];
    out_len_o = out_len * block_size;
    memcpy(out_r, out, out_len * block_size);
    free(out);
    return out_r;
}

uint8_t* decypher(uint8_t* data, uint8_t* key, int block_size, int len, uint64_t& out_len_o, int rounds = 1) {
    uint8_t* key_buff = (uint8_t* ) malloc(block_size);
    memcpy(key_buff, key, block_size);
    uint64_t out_len;
    uint8_t* out = decypher_i(data, key_buff, block_size, len, &out_len, rounds);
    uint8_t* out_r = new uint8_t[out_len];
    memcpy(out_r, out, out_len);
    out_len_o = out_len;
    free(out);
    free(key_buff);
    return out_r;
}