#include "stdlib.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <immintrin.h>

void rearrange(uint8_t *inp, uint8_t *rt, uint8_t *out, int len);

void derearrange(uint8_t *inp, uint8_t *rt, uint8_t *out, int len);

void xor_with_key(uint8_t *inp, uint8_t *key, uint8_t *out, int len);

void rotate(uint8_t *inp, uint8_t *temp, int n, int len);

void cyph_blocks(uint8_t *data, uint8_t *rt, uint8_t *key, uint8_t *rtn, uint8_t *keyn, uint8_t *out, uint8_t *temp, uint8_t *temp2, int block_size, int len, int rounds);

void decyph_blocks(uint8_t *data, uint8_t *rt, uint8_t *key, uint8_t *rtn, uint8_t *keyn, uint8_t *out, uint8_t *temp, uint8_t *temp2, int block_size, int len, int rounds);

uint8_t* cypher_i(uint8_t *data, uint8_t *key, int block_size, uint64_t len, int rounds);

uint8_t* decypher_i(uint8_t *data, uint8_t *key, int block_size, uint64_t len, uint64_t* out_len_o, int rounds);

int inp_to_n_rot(uint8_t* inp, int max_n, int len);

int find_dups(uint8_t* data, int len, uint8_t* out);

void sort(uint8_t* arr, int len);

void key_to_rt(uint8_t* key, int len, uint8_t* out);

void key_expansion(uint8_t* key, uint8_t** out, int rounds, int block_size);

void rotate_sse(uint8_t* inp, uint8_t* out, int n);