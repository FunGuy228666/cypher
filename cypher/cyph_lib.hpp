#include "cyph.cpp"
#include "stdlib.h"
#include "string.h"
#include <iostream>

uint8_t* cypher(uint8_t* data, uint8_t* key, int block_size, int len, uint64_t& out_len_o, int rounds = 1);

uint8_t* decypher(uint8_t* data, uint8_t* key, int block_size, int len, uint64_t& out_len_o, int rounds = 1);