#include "cyph.hpp"

void rearrange(uint8_t *inp, uint8_t *rt, uint8_t *out, int len) {
    for (int i = 0; i < len; i++) out[i] = inp[rt[i]];
}
void derearrange(uint8_t *inp, uint8_t *rt, uint8_t *out, int len) {
    for (int i = 0; i < len; i++) out[rt[i]] = inp[i];
}
void xor_with_key(uint8_t *inp, uint8_t *key, uint8_t *out, int len) {
    for (int i = 0; i < len; i++) 
        out[i] = key[i] ^ inp[i];
}
void rotate_sse(uint8_t* inp, uint8_t* out, int n) {
    __m128i v = _mm_loadu_si128((__m128i* )inp);
    switch (n) {
        case 1:
            v = _mm_alignr_epi8 (v, v, 1);
            break;
        case 2:
            v = _mm_alignr_epi8 (v, v, 2);
            break;
        case 3:
            v = _mm_alignr_epi8 (v, v, 3);
            break;
        case 4:
            v = _mm_alignr_epi8 (v, v, 4);
            break;
        case 5:
            v = _mm_alignr_epi8 (v, v, 5);
            break;
        case 6:
            v = _mm_alignr_epi8 (v, v, 6);
            break;
        case 7:
            v = _mm_alignr_epi8 (v, v, 7);
            break;
        case 8:
            v = _mm_alignr_epi8 (v, v, 8);
            break;
        case 9:
            v = _mm_alignr_epi8 (v, v, 9);
            break;
        case 10:
            v = _mm_alignr_epi8 (v, v, 10);
            break;
        case 11:
            v = _mm_alignr_epi8 (v, v, 11);
            break;
        case 12:
            v = _mm_alignr_epi8 (v, v, 12);
            break;
        case 13:
            v = _mm_alignr_epi8 (v, v, 13);
            break;
        case 14:
            v = _mm_alignr_epi8 (v, v, 14);
            break;
        case 15:
            v = _mm_alignr_epi8 (v, v, 15);
            break;
        case 16:
            v = _mm_alignr_epi8 (v, v, 16);
            break;
    }
    _mm_storeu_si128((__m128i* )out, v);
}
#ifdef __AVX2__
void rotate_avx(uint8_t* inp, uint8_t* out, int n) {
    __m256i v = _mm256_loadu_si256((__m256i* )inp);
    switch (n) {
        case 1:
            v = _mm256_alignr_epi8 (v, v, 1);
            break;
        case 2:
            v = _mm256_alignr_epi8 (v, v, 2);
            break;
        case 3:
            v = _mm256_alignr_epi8 (v, v, 3);
            break;
        case 4:
            v = _mm256_alignr_epi8 (v, v, 4);
            break;
        case 5:
            v = _mm256_alignr_epi8 (v, v, 5);
            break;
        case 6:
            v = _mm256_alignr_epi8 (v, v, 6);
            break;
        case 7:
            v = _mm256_alignr_epi8 (v, v, 7);
            break;
        case 8:
            v = _mm256_alignr_epi8 (v, v, 8);
            break;
        case 9:
            v = _mm256_alignr_epi8 (v, v, 9);
            break;
        case 10:
            v = _mm256_alignr_epi8 (v, v, 10);
            break;
        case 11:
            v = _mm256_alignr_epi8 (v, v, 11);
            break;
        case 12:
            v = _mm256_alignr_epi8 (v, v, 12);
            break;
        case 13:
            v = _mm256_alignr_epi8 (v, v, 13);
            break;
        case 14:
            v = _mm256_alignr_epi8 (v, v, 14);
            break;
        case 15:
            v = _mm256_alignr_epi8 (v, v, 15);
            break;
        case 16:
            v = _mm256_alignr_epi8 (v, v, 16);
            break;
        case 17:
            v = _mm256_alignr_epi8 (v, v, 17);
            break;
        case 18:
            v = _mm256_alignr_epi8 (v, v, 18);
            break;
        case 19:
            v = _mm256_alignr_epi8 (v, v, 19);
            break;
        case 20:
            v = _mm256_alignr_epi8 (v, v, 20);
            break;
        case 21:
            v = _mm256_alignr_epi8 (v, v, 21);
            break;
        case 22:
            v = _mm256_alignr_epi8 (v, v, 22);
            break;
        case 23:
            v = _mm256_alignr_epi8 (v, v, 23);
            break;
        case 24:
            v = _mm256_alignr_epi8 (v, v, 24);
            break;
        case 25:
            v = _mm256_alignr_epi8 (v, v, 25);
            break;
        case 26:
            v = _mm256_alignr_epi8 (v, v, 26);
            break;
        case 27:
            v = _mm256_alignr_epi8 (v, v, 27);
            break;
        case 28:
            v = _mm256_alignr_epi8 (v, v, 28);
            break;
        case 29:
            v = _mm256_alignr_epi8 (v, v, 29);
            break;
        case 30:
            v = _mm256_alignr_epi8 (v, v, 30);
            break;
        case 31:
            v = _mm256_alignr_epi8 (v, v, 31);
            break;
        case 32:
            v = _mm256_alignr_epi8 (v, v, 32);
            break;
    }
    _mm256_storeu_si256((__m256i* )out, v);
}
#endif
#ifdef __AVX512BW__
void rotate_avx512(uint8_t* inp, uint8_t* out, int n) {
    __m512i v = _mm512_loadu_si512((__m512i* )inp);
    switch (n) {
        case 1:
            v = _mm512_alignr_epi8 (v, v, 1);
            break;
        case 2:
            v = _mm512_alignr_epi8 (v, v, 2);
            break;
        case 3:
            v = _mm512_alignr_epi8 (v, v, 3);
            break;
        case 4:
            v = _mm512_alignr_epi8 (v, v, 4);
            break;
        case 5:
            v = _mm512_alignr_epi8 (v, v, 5);
            break;
        case 6:
            v = _mm512_alignr_epi8 (v, v, 6);
            break;
        case 7:
            v = _mm512_alignr_epi8 (v, v, 7);
            break;
        case 8:
            v = _mm512_alignr_epi8 (v, v, 8);
            break;
        case 9:
            v = _mm512_alignr_epi8 (v, v, 9);
            break;
        case 10:
            v = _mm512_alignr_epi8 (v, v, 10);
            break;
        case 11:
            v = _mm512_alignr_epi8 (v, v, 11);
            break;
        case 12:
            v = _mm512_alignr_epi8 (v, v, 12);
            break;
        case 13:
            v = _mm512_alignr_epi8 (v, v, 13);
            break;
        case 14:
            v = _mm512_alignr_epi8 (v, v, 14);
            break;
        case 15:
            v = _mm512_alignr_epi8 (v, v, 15);
            break;
        case 16:
            v = _mm512_alignr_epi8 (v, v, 16);
            break;
        case 17:
            v = _mm512_alignr_epi8 (v, v, 17);
            break;
        case 18:
            v = _mm512_alignr_epi8 (v, v, 18);
            break;
        case 19:
            v = _mm512_alignr_epi8 (v, v, 19);
            break;
        case 20:
            v = _mm512_alignr_epi8 (v, v, 20);
            break;
        case 21:
            v = _mm512_alignr_epi8 (v, v, 21);
            break;
        case 22:
            v = _mm512_alignr_epi8 (v, v, 22);
            break;
        case 23:
            v = _mm512_alignr_epi8 (v, v, 23);
            break;
        case 24:
            v = _mm512_alignr_epi8 (v, v, 24);
            break;
        case 25:
            v = _mm512_alignr_epi8 (v, v, 25);
            break;
        case 26:
            v = _mm512_alignr_epi8 (v, v, 26);
            break;
        case 27:
            v = _mm512_alignr_epi8 (v, v, 27);
            break;
        case 28:
            v = _mm512_alignr_epi8 (v, v, 28);
            break;
        case 29:
            v = _mm512_alignr_epi8 (v, v, 29);
            break;
        case 30:
            v = _mm512_alignr_epi8 (v, v, 30);
            break;
        case 31:
            v = _mm512_alignr_epi8 (v, v, 31);
            break;
        case 32:
            v = _mm512_alignr_epi8 (v, v, 32);
            break;
        case 33:
            v = _mm512_alignr_epi8 (v, v, 33);
            break;
        case 34:
            v = _mm512_alignr_epi8 (v, v, 34);
            break;
        case 35:
            v = _mm512_alignr_epi8 (v, v, 35);
            break;
        case 36:
            v = _mm512_alignr_epi8 (v, v, 36);
            break;
        case 37:
            v = _mm512_alignr_epi8 (v, v, 37);
            break;
        case 38:
            v = _mm512_alignr_epi8 (v, v, 38);
            break;
        case 39:
            v = _mm512_alignr_epi8 (v, v, 39);
            break;
        case 40:
            v = _mm512_alignr_epi8 (v, v, 40);
            break;
        case 41:
            v = _mm512_alignr_epi8 (v, v, 41);
            break;
        case 42:
            v = _mm512_alignr_epi8 (v, v, 42);
            break;
        case 43:
            v = _mm512_alignr_epi8 (v, v, 43);
            break;
        case 44:
            v = _mm512_alignr_epi8 (v, v, 44);
            break;
        case 45:
            v = _mm512_alignr_epi8 (v, v, 45);
            break;
        case 46:
            v = _mm512_alignr_epi8 (v, v, 46);
            break;
        case 47:
            v = _mm512_alignr_epi8 (v, v, 47);
            break;
        case 48:
            v = _mm512_alignr_epi8 (v, v, 48);
            break;
        case 49:
            v = _mm512_alignr_epi8 (v, v, 49);
            break;
        case 50:
            v = _mm512_alignr_epi8 (v, v, 50);
            break;
        case 51:
            v = _mm512_alignr_epi8 (v, v, 51);
            break;
        case 52:
            v = _mm512_alignr_epi8 (v, v, 52);
            break;
        case 53:
            v = _mm512_alignr_epi8 (v, v, 53);
            break;
        case 54:
            v = _mm512_alignr_epi8 (v, v, 54);
            break;
        case 55:
            v = _mm512_alignr_epi8 (v, v, 55);
            break;
        case 56:
            v = _mm512_alignr_epi8 (v, v, 56);
            break;
        case 57:
            v = _mm512_alignr_epi8 (v, v, 57);
            break;
        case 58:
            v = _mm512_alignr_epi8 (v, v, 58);
            break;
        case 59:
            v = _mm512_alignr_epi8 (v, v, 59);
            break;
        case 60:
            v = _mm512_alignr_epi8 (v, v, 60);
            break;
        case 61:
            v = _mm512_alignr_epi8 (v, v, 61);
            break;
        case 62:
            v = _mm512_alignr_epi8 (v, v, 62);
            break;
        case 63:
            v = _mm512_alignr_epi8 (v, v, 63);
            break;
        case 64:
            v = _mm512_alignr_epi8 (v, v, 64);
            break;
    }
    _mm512_storeu_si512((__m512i* )out, v);
}
#endif
void rotate(uint8_t *inp, uint8_t *temp, int n, int len) {
    if (len == 16) {
        rotate_sse(inp, inp, n);
        return;
    }
    #ifdef __AVX2__
    if (len == 32) {
        rotate_avx(inp, inp, n);
        return;
    }
    #endif
    #ifdef __AVX512BW__
    if (len == 64) {
        rotate_avx512(inp, inp, n);
        return;
    }
    #endif
    memcpy(temp, inp, len);
    for (int i = n; i < len; i++) inp[i-n] = temp[i];
    for (int i = len-n; i < len; i++) inp[i] = temp[i-(len-n)];
}
void key_expansion(uint8_t* key, uint8_t** out, int rounds, int block_size) {
    uint8_t temp[block_size];
    memcpy(temp, key, block_size);
    if (rounds > block_size - 1) rounds = block_size - 1;
    for (int i = 0; i < rounds; i++) {
        rotate(temp, temp, 1, block_size);
        memcpy(out[i], temp, block_size);
    }
}
int inp_to_n_rot(uint8_t* inp, int max_n, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) sum += inp[i];
    if (sum < 0) sum *= -1;
    return sum % (max_n-2) + 1;
}
int find_dups(uint8_t* data, int len, uint8_t* out) {
    int keys[len];
    int map[len];
    memset(keys, 0, len * sizeof(int));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (keys[j] == data[i]) {
                map[j] += 1;
                break;
            }
            else if (keys[j] == 0) {
                keys[j] = data[i];
                map[j] = 1;
                break;
            }
        }
    }
    int dups_size = 0;
    for (int i = 0; i < len; i++) {
        if (map[i] > 1) {
            int dup = keys[i];
            for (int j = 0; j < len; j++) {
                if (out[j] == 0) {
                    out[j] = dup;
                    dups_size++;
                    break;
                }
            }
        }
    }
    return dups_size;
}
void sort(uint8_t* arr, int len) {
    uint8_t temp[len];
    for (int i = 0; i < len; i++) {
        int min = 100000000;
        int max;
        if (i != 0) max = temp[i-1];
        else max = -100000000;
        for (int j = 0; j < len; j++) {
            if (arr[j] < min && arr[j] > max) {
                min = arr[j];
            }
        }
        temp[i] = min;
    }
    memcpy(arr, temp, len);
}
void key_to_rt(uint8_t* key, int len, uint8_t* out) {
    uint8_t lkey[len];
    memcpy(lkey, key, len);
    uint8_t dups[len];
    memset(dups, 0, len);
    while (find_dups(lkey, len, dups)) {
        for (int i = 0; i < len; i++) {
            if (dups[i] == 0) break;
            int index = 0;
            for (int j = 0; j < len; j++) {
                if (dups[i] == lkey[j]) index++;
                if (dups[i] == lkey[j] && index > 1) lkey[j] += index - 1;
            }
        }
        memset(dups, 0, len);
    }
    uint8_t temp[len];
    memcpy(temp, lkey, len);
    sort(temp, len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (lkey[j] == temp[i]) {
                out[i] = j;
                break;
            }
        }
    }
}
void cyph_blocks(uint8_t *data, uint8_t *rt, uint8_t *key, uint8_t *rtn, uint8_t *keyn, uint8_t *out, uint8_t *temp, uint8_t *temp2, int block_size, int len, int rounds) {//, std::vector<std::vector<int>> & keys) {
    int blocks = len / block_size;
    if (len % block_size != 0) blocks++;
    memcpy(keyn, key, block_size);
    memcpy(rtn, rt, block_size);
    for (int i = 0; i < len / block_size; i++) {
        if (rounds > 1) {
            memcpy(temp, data+(i*block_size), block_size);
            uint8_t keys[rounds][block_size];
            uint8_t *pk[rounds];
            for (int i = 0; i < rounds; i++)
                pk[i] = keys[i];
            key_expansion(keyn, pk, rounds, block_size);
            for (int i = 0; i < rounds; i++) {
                xor_with_key(temp, keys[i], temp2, block_size);
                rearrange(temp2, rtn, temp, block_size);
            }
            memcpy(keyn, temp, block_size);
            memcpy(out+(i*block_size), temp, block_size);
            rotate(rtn, temp, inp_to_n_rot(data+(i*block_size), block_size-1, block_size), block_size);
        }
        else {
            xor_with_key(data+(i*block_size), keyn, temp, block_size);
            rearrange(temp, rtn, out+(i*block_size), block_size);
            memcpy(keyn, out+(i*block_size), block_size);
            rotate(rtn, temp, inp_to_n_rot(data+(i*block_size), block_size-1, block_size), block_size);
        }
    }
    if (len % block_size != 0) {
        if (rounds > 1) {
            memset(temp, 0, block_size);
            memcpy(temp, data+((blocks-1)*block_size), len % block_size);
            uint8_t keys[rounds][block_size];
            uint8_t *pk[rounds];
            for (int i = 0; i < rounds; i++)
                pk[i] = keys[i];
            key_expansion(keyn, pk, rounds, block_size);
            for (int i = 0; i < rounds; i++) {
                xor_with_key(temp, keys[i], temp2, block_size);
                rearrange(temp2, rtn, temp, block_size);
            }
            memcpy(out+((blocks-1)*block_size), temp, block_size);
        }
        else {
            memset(temp, 0, block_size);
            memcpy(temp, data+((blocks-1)*block_size), len % block_size);
            xor_with_key(temp, keyn, temp2, block_size);
            rearrange(temp2, rtn, out+((blocks-1)*block_size), block_size);
        }
    }
}
void decyph_blocks(uint8_t *data, uint8_t *rt, uint8_t *key, uint8_t *rtn, uint8_t *keyn, uint8_t *out, uint8_t *temp, uint8_t *temp2, int block_size, int len, int rounds) {
    memcpy(keyn, key, block_size);
    memcpy(rtn, rt, block_size);
    for (int i = 0; i < len / block_size; i++) {
        if (rounds > 1) {
            memcpy(temp2, data+(i*block_size), block_size);
            uint8_t keys[rounds][block_size];
            uint8_t *pk[rounds];
            for (int i = 0; i < rounds; i++)
                pk[i] = keys[i];
            key_expansion(keyn, pk, rounds, block_size);
            for (int i = 0; i < rounds; i++) {
                derearrange(temp2, rtn, temp, block_size);
                xor_with_key(temp, keys[rounds-i-1], temp2, block_size);
            }
            memcpy(keyn, data+(i*block_size), block_size);
            memcpy(out+(i*block_size), temp2, block_size);
            rotate(rtn, temp2, inp_to_n_rot(out+(i*block_size), block_size-1, block_size), block_size); 
        } else {
            memcpy(temp2, data+(i*block_size), block_size);
            derearrange(data+(i*block_size), rtn, temp, block_size);
            xor_with_key(temp, keyn, out+(i*block_size), block_size);
            memcpy(keyn, temp2, block_size);
            rotate(rtn, temp2, inp_to_n_rot(out+(i*block_size), block_size-1, block_size), block_size); 
        }
    }
}
uint8_t* cypher_i(uint8_t *data, uint8_t *key, int block_size, uint64_t len, int rounds) {
    uint8_t *temp = (uint8_t *)malloc(block_size);
    uint8_t *temp2 = (uint8_t *)malloc(block_size);
    uint8_t *rt = (uint8_t *)malloc(block_size);
    uint8_t *rtn = (uint8_t *)malloc(block_size);
    uint8_t *keyn = (uint8_t *)malloc(block_size);
    uint64_t out_len = len / block_size;
    if (len % block_size != 0) out_len++;
    uint8_t *out = (uint8_t *)malloc(out_len * block_size);
    key_to_rt(key, block_size, rt);
    cyph_blocks(data, rt, key, rtn, keyn, out, temp, temp2, block_size, len, rounds);//, keys);
    free(temp);
    free(temp2);
    free(rtn);
    free(keyn);
    return out;
}
uint8_t* decypher_i(uint8_t *data, uint8_t *key, int block_size, uint64_t len, uint64_t* out_len_o, int rounds) {
    uint8_t *temp = (uint8_t *)malloc(block_size);
    uint8_t *temp2 = (uint8_t *)malloc(block_size);
    uint8_t *rt = (uint8_t *)malloc(block_size);
    uint8_t *rtn = (uint8_t *)malloc(block_size);
    uint8_t *keyn = (uint8_t *)malloc(block_size);
    uint64_t out_len = len / block_size;
    if (len % block_size != 0) out_len++;
    uint8_t *out = (uint8_t *)malloc(out_len * block_size);
    key_to_rt(key, block_size, rt);
    decyph_blocks(data, rt, key, rtn, keyn, out, temp, temp2, block_size, len, rounds);
    uint64_t new_len = out_len * block_size;
    while (out[new_len-1] == 0) new_len--;
    uint8_t *out_n = (uint8_t *)malloc(new_len);
    *out_len_o = new_len;
    memcpy(out_n, out, new_len);
    free(out);
    free(temp);
    free(temp2);
    free(rtn);
    free(keyn);
    return out_n;
}