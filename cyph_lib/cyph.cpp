#include "cyph.hpp"
#include "stdio.h"
void rearrange(int *inp, int *rt, int *out, int len) {
    for (int i = 0; i < len; i++) out[i] = inp[rt[i]];
}
void derearrange(int *inp, int *rt, int *out, int len) {
    for (int i = 0; i < len; i++) out[rt[i]] = inp[i];
}
void xor_with_key(int *inp, int *key, int *out, int len) {
    for (int i = 0; i < len; i++) out[i] = key[i] ^ inp[i];
}
void mymemcpy(int *dst, int *src, int len) {
    for (int i = 0; i < len; i++) dst[i] = src[i];
}
void mymemset(int *dst, int val, int len) {
    for (int i = 0; i < len; i++) dst[i] = val;
}
void rotate(int *inp, int *temp, int n, int len) {
    mymemcpy(temp, inp, len);
    for (int i = n; i < len; i++) inp[i-n] = temp[i];
    for (int i = len-n; i < len; i++) inp[i] = temp[i-(len-n)];
}
int inp_to_n_rot(int* inp, int max_n, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) sum += inp[i];
    if (sum < 0) sum *= -1;
    return sum % (max_n-2) + 1;
}
void cyph_blocks(int *data, int *rt, int *key, int *rtn, int *keyn, int *out, int *temp, int *temp2, int block_size, int len) {
    int blocks = len / block_size;
    if (len % block_size != 0) blocks++;
    mymemcpy(keyn, key, block_size);
    mymemcpy(rtn, rt, block_size);
    for (int i = 0; i < len / block_size; i++) {
        xor_with_key(data+(i*block_size), keyn, temp, block_size);
        rearrange(temp, rtn, out+(i*block_size), block_size);
        mymemcpy(keyn, out+(i*block_size), block_size);
        rotate(rtn, temp, inp_to_n_rot(data+(i*block_size), block_size-1, block_size), block_size);
    }
    if (len % block_size != 0) {
        mymemset(temp, 0, block_size);
        mymemcpy(temp, data+((blocks-1)*block_size), len % block_size);
        xor_with_key(temp, keyn, temp2, block_size);
        rearrange(temp2, rtn, out+((blocks-1)*block_size), block_size);
    }
}
void decyph_blocks(int *data, int *rt, int *key, int *rtn, int *keyn, int *out, int *temp, int *temp2, int block_size, int len) {
    mymemcpy(keyn, key, block_size);
    mymemcpy(rtn, rt, block_size);
    for (int i = 0; i < len / block_size; i++) {
        mymemcpy(temp2, data+(i*block_size), block_size);
        derearrange(data+(i*block_size), rtn, temp, block_size);
        xor_with_key(temp, keyn, out+(i*block_size), block_size);
        mymemcpy(keyn, temp2, block_size);
        rotate(rtn, temp2, inp_to_n_rot(out+(i*block_size), block_size-1, block_size), block_size);
    }
}
int* cypher_i(int *data, int *rt, int *key, int block_size, int len) {
    int *temp = (int *)malloc(sizeof(int) * block_size);
    int *temp2 = (int *)malloc(sizeof(int) * block_size);
    int *rtn = (int *)malloc(sizeof(int) * block_size);
    int *keyn = (int *)malloc(sizeof(int) * block_size);
    int out_len = len / block_size;
    if (len % block_size != 0) out_len++;
    int *out = (int *)malloc(sizeof(int) * out_len * block_size);
    cyph_blocks(data, rt, key, rtn, keyn, out, temp, temp2, block_size, len);
    free(temp);
    free(temp2);
    free(rtn);
    free(keyn);
    return out;
}
int* decypher_i(int *data, int *rt, int *key, int block_size, int len) {
    int *temp = (int *)malloc(sizeof(int) * block_size);
    int *temp2 = (int *)malloc(sizeof(int) * block_size);
    int *rtn = (int *)malloc(sizeof(int) * block_size);
    int *keyn = (int *)malloc(sizeof(int) * block_size);
    int out_len = len / block_size;
    if (len % block_size != 0) out_len++;
    int *out = (int *)malloc(sizeof(int) * out_len * block_size);
    decyph_blocks(data, rt, key, rtn, keyn, out, temp, temp2, block_size, len);
    int new_len = out_len * block_size;
    while (out[new_len-1] == 0) new_len--;
    //for (int i = 0; i < 64; i++) std::cout << out[i] << ", ";
    int *out_n = (int *)malloc(sizeof(int) * (new_len+1));
    out_n[0] = new_len;
    memcpy(out_n+1, out, new_len*sizeof(int));
    free(out);
    free(temp);
    free(temp2);
    free(rtn);
    free(keyn);
    return out_n;
}
