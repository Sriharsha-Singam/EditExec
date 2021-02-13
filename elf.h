//
// Created by Sriharsha Singam on 12/11/2020.
//

#ifndef EDITEXEC_ELF_H
#define EDITEXEC_ELF_H

#define EI_NIDENT 16

#define ELF_MAGIC_NUMBER 0x464C457F

//typedef struct {
//    unsigned char e_ident[EI_NIDENT];
//    uint16_t      e_type;
//    uint16_t      e_machine;
//    uint32_t      e_version;
//    ElfN_Addr     e_entry;
//    ElfN_Off      e_phoff;
//    ElfN_Off      e_shoff;
//    uint32_t      e_flags;
//    uint16_t      e_ehsize;
//    uint16_t      e_phentsize;
//    uint16_t      e_phnum;
//    uint16_t      e_shentsize;
//    uint16_t      e_shnum;
//    uint16_t      e_shstrndx;
//} ElfN_Ehdr;

#endif //EDITEXEC_ELF_H
