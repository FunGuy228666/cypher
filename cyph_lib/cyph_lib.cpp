#include "cyph.cpp"
#include "stdlib.h"
#include "string.h"

int supported_block_sizes[] = {16, 32, 64, 128, 256};

int rt16[] = {6, 15, 8, 10, 11, 12, 7, 3, 1, 2, 14, 0, 4, 13, 5, 9};
int rt32[] = {10, 6, 24, 17, 19, 28, 7, 2, 8, 25, 16, 26, 18, 13, 0, 3, 11, 30, 12, 20, 4, 1, 31, 5, 9, 15, 14, 21, 22, 27, 29, 23};
int rt64[] = {21, 56, 32, 33, 41, 46, 38, 37, 17, 43, 47, 29, 34, 9, 49, 11, 54, 8, 55, 10, 7, 15, 5, 16, 39, 30, 61, 23, 51, 60, 59, 14, 0, 53, 42, 28, 52, 57, 40, 25, 1, 22, 13, 4, 31, 44, 26, 62, 36, 58, 20, 45, 27, 35, 50, 63, 48, 12, 2, 19, 24, 18, 6, 3};
int rt128[] = {105, 15, 16, 68, 31, 29, 45, 6, 90, 88, 49, 110, 23, 71, 89, 107, 24, 38, 69, 75, 87, 74, 19, 5, 93, 9, 115, 85, 4, 125, 44, 91, 67, 41, 83, 96, 26, 101, 50, 18, 22, 66, 80, 92, 76, 47, 116, 95, 73, 120, 123, 54, 20, 111, 21, 70, 65, 53, 37, 122, 114, 100, 46, 82, 35, 8, 124, 32, 118, 12, 77, 39, 98, 51, 40, 99, 2, 7, 126, 103, 57, 60, 52, 117, 11, 64, 10, 121, 0, 104, 25, 109, 1, 102, 78, 86, 36, 72, 97, 14, 33, 34, 81, 56, 48, 127, 30, 94, 13, 43, 58, 112, 17, 106, 84, 113, 27, 62, 55, 3, 63, 59, 79, 42, 108, 28, 119, 61};
int rt256[] = {54, 48, 121, 92, 33, 159, 214, 90, 255, 232, 123, 181, 111, 97, 228, 250, 172, 88, 187, 26, 23, 156, 190, 137, 124, 8, 114, 125, 101, 192, 246, 134, 36, 179, 248, 71, 13, 183, 209, 204, 160, 150, 153, 122, 75, 185, 7, 27, 163, 212, 50, 213, 25, 10, 210, 221, 186, 129, 154, 2, 56, 1, 127, 93, 169, 55, 91, 241, 59, 65, 44, 222, 224, 9, 211, 178, 14, 229, 57, 149, 215, 110, 42, 142, 193, 188, 28, 119, 145, 194, 161, 41, 116, 87, 12, 225, 252, 76, 109, 251, 61, 231, 103, 205, 157, 112, 3, 38, 117, 216, 180, 128, 174, 170, 37, 73, 80, 182, 175, 201, 136, 51, 39, 40, 196, 34, 171, 15, 62, 253, 164, 30, 120, 237, 218, 69, 200, 6, 242, 46, 95, 22, 77, 16, 66, 113, 4, 131, 82, 148, 226, 35, 132, 31, 152, 144, 105, 208, 99, 68, 72, 206, 249, 60, 118, 158, 202, 139, 100, 223, 49, 143, 168, 84, 198, 133, 70, 102, 173, 83, 140, 165, 94, 240, 230, 0, 126, 115, 52, 5, 227, 67, 18, 45, 53, 29, 167, 238, 85, 245, 98, 64, 104, 233, 189, 89, 96, 162, 146, 43, 81, 32, 19, 63, 199, 86, 244, 21, 235, 78, 138, 191, 207, 220, 141, 203, 155, 107, 74, 151, 236, 79, 219, 195, 247, 24, 184, 20, 177, 108, 17, 176, 106, 135, 254, 58, 166, 217, 11, 47, 239, 197, 130, 147, 234, 243};

int* cypher(int* data, int* key, int block_size, int len, int* rt=0) {
    int* rt_used;
    int block_size_used = 32;
    if (rt != 0) {
        rt_used = rt;
        block_size_used = block_size;
    }
    else {
        for (int i = 0; i < sizeof(supported_block_sizes) / sizeof(int); i++) {
            if (block_size == supported_block_sizes[i]) block_size_used = block_size;
        }
        switch (block_size_used) {
            case 16:
                rt_used = rt16;
                break;
            case 32:
                rt_used = rt32;
                break;
            case 64:
                rt_used = rt64;
                break;
            case 128:
                rt_used = rt128;
                break;
            case 256:
                rt_used = rt256;
                break;
        }
    }
    int* out = cypher_i(data, rt_used, key, block_size_used, len);
    int out_len = len / block_size_used;
    if (len % block_size_used != 0) out_len++;
    int* out_r = new int[(out_len * block_size + 1)];
    out_r[0] = out_len * block_size;
    memcpy(out_r+1, out, out_len * block_size * sizeof(int));
    free(out);
    return out_r;
}

int* decypher(int* data, int* key, int block_size, int len, int* rt=0) {
    int* rt_used;
    int block_size_used = 32;
    if (rt != 0) {
        rt_used = rt;
        block_size_used = block_size;
    }
    else {
        for (int i = 0; i < sizeof(supported_block_sizes) / sizeof(int); i++) {
            if (block_size == supported_block_sizes[i]) block_size_used = block_size;
        }
        switch (block_size_used) {
            case 16:
                rt_used = rt16;
                break;
            case 32:
                rt_used = rt32;
                break;
            case 64:
                rt_used = rt64;
                break;
            case 128:
                rt_used = rt128;
                break;
            case 256:
                rt_used = rt256;
                break;
        }
    }
    int* key_buff = (int* ) malloc(block_size_used * sizeof(int));
    memcpy(key_buff, key, block_size_used * sizeof(int));
    int* out = decypher_i(data, rt_used, key_buff, block_size_used, len);
    int* out_r = new int[out[0]+1];
    memcpy(out_r, out, (out[0]+1)*sizeof(int));
    free(out);
    free(key_buff);
    return out_r;
}