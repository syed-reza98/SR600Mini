OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(appimg_enter)
EXTERN(appimg_enter)
EXTERN(appimg_exit)
EXTERN(appimg_get_param)
EXTERN(appimg_set_param)
PROVIDE(appimg_get_param = 0);
PROVIDE(appimg_set_param = 0);
MEMORY {
    flash (rx): ORIGIN = 0x60370000, LENGTH = 0x170000
    ram (rwx): ORIGIN = 0x80000000 +0xfa0000, LENGTH = 0x60000
}
SECTIONS {
    . = ORIGIN(flash);
    __flash_start = .;
    .imageheader : {
        LONG(0x41505032) LONG(0) LONG(0) KEEP(*(.rodata.core_stub.header))
        LONG(2) LONG(__corestub_load_start - __flash_start) LONG(__corestub_end - __corestub_start) LONG(__corestub_start)
        LONG(4) LONG(__text_load_start - __flash_start) LONG(__text_end - __text_start) LONG(__text_start)
        LONG(4) LONG(__init_array_load_start - __flash_start) LONG(__init_array_end - __init_array_start) LONG(__init_array_start)
        LONG(1) LONG(__data_load_start - __flash_start) LONG(__data_end - __data_start) LONG(__data_start)
        LONG(3) LONG(0) LONG(__bss_end - __bss_start) LONG(__bss_start)
        LONG(0) LONG(0) LONG(0) LONG(0)
     } > flash
     ASSERT(SIZEOF(.imageheader) == 128, "invalid app image header")
    . = ORIGIN(ram);
    __ram_start = .;
    .corestub ALIGN(0x20) : {
        __corestub_start = .;
        *(.text.core_stub.*)
        __corestub_end = .;
        . = ALIGN(0x20);
        __corestub_load_start = LOADADDR(.corestub);
    } AT>flash
    .data ALIGN(0x20) : {
        __data_start = .;
        *(.data .data.* .gnu.linkonce.d.*)
        __data_end = .;
        . = ALIGN(0x20);
        __data_load_start = LOADADDR(.data);
    } AT>flash
    .bss ALIGN(0x20) : {
        __bss_start = .;
        *(.bss .bss.* COMMON .scommon .sbss .sbss.* .sbss2 .sbss2.* .gnu.linkonce.b.*)
        __bss_end = .;
        . = ALIGN(0x20);
    }
    . = LOADADDR(.corestub) + SIZEOF(.corestub) + SIZEOF(.data);
    .text ALIGN(0x20) : {
        __text_start = .;
        *(.text .text.* .gnu.linkonce.t.* .rdata .rodata .rodata.* .gnu.linkonce.r.* .glue_7 .glue_7t .vfp11_veneer .v4_bx)
        __text_end = .;
        . = ALIGN(0x20);
        __text_load_start = LOADADDR(.text);
    } > flash
    .init_array ALIGN(0x20) : {
        __init_array_start = .;
        KEEP(*(.init_array*))
        __init_array_end = .;
        . = ALIGN(0x20);
        __init_array_load_start = LOADADDR(.init_array);
    } > flash
    __flash_end = ADDR(.init_array) + SIZEOF(.init_array);
    __ram_end = ADDR(.bss) + SIZEOF(.bss);
    ASSERT(__flash_end <= ORIGIN(flash) + LENGTH(flash), "FLASH overflow")
    ASSERT(__ram_end <= ORIGIN(ram) + LENGTH(ram), "RAM overflow")
    .comment 0 : { *(.comment) }
    /DISCARD/ : { *(.dynstr*) }
    /DISCARD/ : { *(.dynamic*) }
    /DISCARD/ : { *(.plt*) }
    /DISCARD/ : { *(.interp*) }
    /DISCARD/ : { *(.gnu*) }
}
