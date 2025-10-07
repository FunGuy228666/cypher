#include "stdlib.h"

void rearrange(int *inp, int *rt, int *out, int len);

void derearrange(int *inp, int *rt, int *out, int len);

void xor_with_key(int *inp, int *key, int *out, int len);

void mymemcpy(int *dst, int *src, int len);

void mymemset(int *dst, int val, int len);

void rotate(int *inp, int *temp, int n, int len);

void cyph_blocks(int *data, int *rt, int *key, int *rtn, int *keyn, int *out, int *temp, int *temp2, int block_size, int len);

void decyph_blocks(int *data, int *rt, int *key, int *rtn, int *keyn, int *out, int *temp, int *temp2, int block_size, int len);

int* cypher(int *data, int *rt, int *key, int block_size, int len);

int* decypher(int *data, int *rt, int *key, int block_size, int len);

int inp_to_n_rot(int* inp, int max_n, int len);

