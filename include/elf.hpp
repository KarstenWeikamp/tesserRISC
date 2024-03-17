#include <cstdint>
#include <vector>

namespace tesserRISC
{
    namespace ELFFile
    {
// Valid file must have `0x7F 0x45 0x4c 0x46` => 0x7F and 'ELF' in ASCII as its first four bytes
#define ELF_MAGIC_BYTES = 0x7F454c46

        /**
         * @brief Represents the header of an ELF file.
         */
        struct ElfHeader
        {
            /**
             * @brief Indicates whether the file has the correct magic number.
             *        A valid file must have `0x7F 0x45 0x4C 0x46` (0x7F and 'ELF' in ASCII) as its first four bytes.
             */
            bool m_magic;

            /**
             * @brief Specifies the format of the ELF file (32-bit or 64-bit).
             *        This byte is set to either 1 or 2 to signify 32-bit or 64-bit format, respectively.
             */
            uint8_t EI_CLASS;

            /**
             * @brief Specifies the endianness of the ELF file (little or big endian).
             *        This byte is set to either 1 or 2 to signify little or big endianness, respectively.
             *        This affects the interpretation of multi-byte fields starting with offset 0x10.
             */
            uint8_t EI_DATA;

            /**
             * @brief Specifies the version of the ELF file.
             *        Set to 1 for the original and current version of ELF.
             */
            uint8_t EI_VERSION;
            uint16_t e_type;      // Type of the ELF file
            uint16_t e_machine;   // Target architecture of the ELF file
            uint64_t e_version;   // Version of the ELF file
            uint64_t e_entry;     // Entry point virtual address
            uint64_t e_phoff;     // Program header table offset
            uint64_t e_shoff;     // Section header table offset
            uint32_t e_flags;     // Processor-specific flags
            uint16_t e_ehsize;    // Size of this ELF header
            uint16_t e_phentsize; // Size of a program header table entry
            uint16_t e_phnum;     // Number of program header table entries
            uint16_t e_shentsize; // Size of a section header table entry
            uint16_t e_shnum;     // Number of section header table entries
            uint16_t e_shstrndx;  // Section header table index of the entry associated with the section name string table
        };

        /**
         * @brief Represents a program header entry in an executable file.
         */
        struct ProgramHeader
        {
            uint32_t p_type;   // The type of the program header entry.
            uint32_t p_flags;  // The flags of the program header entry.
            uint64_t p_offset; // The offset of the segment in the file.
            uint64_t p_vaddr;  // The virtual address of the segment in memory.
            uint64_t p_paddr;  // The physical address of the segment in memory.
            uint64_t p_filesz; // The size of the segment in the file.
            uint64_t p_memsz;  // The size of the segment in memory.
            uint64_t p_align;  // The alignment of the segment in memory.
        };

        struct SectionHeader
        {
            uint32_t sh_name;      // An offset to a string in the.shstrtab section that represents the name of this section.
            uint32_t sh_type;      // Identifies the type of this header
            uint64_t sh_flags;     // Identifies the attibutes of this section
            uint64_t sh_addr;      // Virtual address of the section in memory, for sections that are loaded.
            uint64_t sh_offset;    // Offset of the section in the file image.
            uint64_t sh_size;      // Size in bytes of the section in the file image. May be 0.
            uint32_t sh_link;      // Contains the section index of an associated section. This field is used for several purposes, depending on the type of section.
            uint32_t sh_info;      // Contains extra information about the section. This field is used for several purposes, depending on the type of section.
            uint64_t sh_addralign; // Contains the required alignment of the section. This field must be a power of two.
            uint64_t sh_entsize;   // Contains the size, in bytes, of each entry, for sections that contain fixed-size entries. Otherwise, this field contains zero.
        };

        class ELFFile
        {
        private:
            struct ElfHeader m_header;
            std::vector<SectionHeader> m_section_header_table;
            std::vector<ProgramHeader> m_program_header_table;
        };
    }
}