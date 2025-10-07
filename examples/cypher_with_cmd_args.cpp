#include <iostream>
#include <fstream>
#include <filesystem>
#include "cyph_lib/cyph_lib.cpp"

int main(int argc, char* argv[]) {
    int file_inp_ind = -1;
    int file_out_ind = -1;
    int file_key_ind = -1;
    int encode = 1;
    int block_size = 32;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-i")) file_inp_ind = i+1;
        else if (!strcmp(argv[i], "-o")) file_out_ind = i+1;
        else if (!strcmp(argv[i], "-k")) file_key_ind = i+1;
        else if (!strcmp(argv[i], "-b")) block_size = atoi(argv[i+1]);
        else if (!strcmp(argv[i], "-d")) encode = 0;
        else if (!strcmp(argv[i], "-e")) encode = 1;
        else if (!strcmp(argv[i], "-h")) {
            std::cout << "The usage is command [options]\nThe options include\n -i - the input file\n -k - a file with the key\n -o - the output file\n -b - for block size, allowed sizes are 16, 32, 64, 128, 256\n -e - for encoding\n -d - for decoding\n -h - to show the help message" << std::endl;
            return 0;
        }
    }
    if (file_inp_ind == -1 || file_out_ind == -1 || file_key_ind == -1) return -1;
    auto size = std::filesystem::file_size(argv[file_inp_ind]);
    std::ifstream in(argv[file_inp_ind], std::ios::binary);
    char* data_bytes = new char[size];
    in.read(data_bytes, size);
    int* data = new int[size];
    for (int i = 0; i < size; i++) data[i] = data_bytes[i];
    auto size_k = std::filesystem::file_size(argv[file_key_ind]);
    std::ifstream in_k(argv[file_key_ind], std::ios::binary);
    if (size_k > block_size) size_k = block_size;
    char* key_bytes = new char[size_k];
    in_k.read(key_bytes, size_k);
    int* key = new int[size_k];
    for (int i = 0; i < size_k; i++) key[i] = key_bytes[i];
    if (encode) {
        int* encoded = cypher(data, key, block_size, size);
        char* encoded_c = new char[encoded[0]];
        for (int i = 0; i < encoded[0]; i++) encoded_c[i] = encoded[i+1];
        std::ofstream outFile(argv[file_out_ind], std::ios::out | std::ios::binary);
        outFile.write(encoded_c, encoded[0]);
        outFile.close();
        delete[] encoded, encoded_c;
    }
    else {
        int* decoded = decypher(data, key, block_size, size);
        char* decoded_c = new char[decoded[0]];
        for (int i = 0; i < decoded[0]; i++) decoded_c[i] = decoded[i+1];
        std::ofstream outFile(argv[file_out_ind], std::ios::out | std::ios::binary);
        outFile.write(decoded_c, decoded[0]);
        outFile.close();
        delete[] decoded, decoded_c;
    }
    delete[] data_bytes, data, key_bytes, key;
}