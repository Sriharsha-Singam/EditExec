#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "elf.h"
#include "pe.h"

#include "DataStructureLibs/vector.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat="

#define BUFFER_SIZE 1024

union BUFFER_UNION {
    uint8_t one[BUFFER_SIZE];
    uint16_t two[BUFFER_SIZE/2];
    uint32_t four[BUFFER_SIZE/4];
} buffer;


//uint8_t buffer[BUFFER_SIZE];
//uint16_t buffer_2byte[BUFFER_SIZE/2];
//uint32_t buffer_4byte[BUFFER_SIZE/4];

uint8_t get_bit (uint8_t value, uint8_t bit) {
    uint8_t mask = (0x1) << bit;
    mask = value & mask;
    mask = mask >> (bit);
    return mask;
}

uint8_t get_byte (uint8_t value, uint8_t part) {
    uint8_t ret = (0xF) << (4 * part);
    ret = value & ret;
    ret = ret >> (4 * part);
    return ret;
}

void check_file_type() {
    if (buffer.two[0] == PE_FILE_SIGNATURE) printf("PE DOS File Detected\n");
    else if (buffer.four[0] == ELF_MAGIC_NUMBER) printf("ELF File Detected\n");
    else printf("Unknown File Type\n");
}

void file_read() {
    memset(buffer.one, 0, BUFFER_SIZE);

//    FILE* file = fopen("/src/checktool-windows-1.0.0/checktool.exe", "rb");
    FILE* file = fopen("./test/test", "rb");

    fseek(file, 0, SEEK_SET);

    size_t read_bytes = 1;
    size_t total_bytes_read = 0;
    while (read_bytes > 0) {
        read_bytes = fread(buffer.one, sizeof(uint8_t), BUFFER_SIZE, file);

        if (total_bytes_read == 0) check_file_type();
        printf("Read Bytes: %d\n", read_bytes);
        for (uint16_t i = 0; i < read_bytes; i++) {
            fprintf(stdout, "0x%0.4X => 0x%0.4X:0x%X(%u%u%u%u)  ", total_bytes_read, (total_bytes_read*8)+8, get_byte(buffer.one[i], 1), get_bit(buffer.one[i], 7), get_bit(buffer.one[i], 6), get_bit(buffer.one[i], 5), get_bit(buffer.one[i], 4));
            fprintf(stdout, "0x%0.4X:0x%X(%u%u%u%u)\n", (total_bytes_read*8)+4, get_byte(buffer.one[i], 0), get_bit(buffer.one[i], 3), get_bit(buffer.one[i], 2), get_bit(buffer.one[i], 1), get_bit(buffer.one[i], 0));
            total_bytes_read++;
//            if (total_bytes_read > 10) return;
        }
        memset(buffer.one, 0, BUFFER_SIZE);
//        if (total_bytes_read > 2048) return;
    }

    fclose(file);
}

int main() {
    file_read();
//    printf("\n");
//    buffer.one[0] = 0x54;
//    buffer.one[1] = 0x29;
//    printf("%d, 0x%X\n", sizeof(buffer), buffer.two[0]);
    return 0;
}
#pragma GCC diagnostic pop