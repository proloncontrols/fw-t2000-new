 
/* Include */
INCLUDE ..\Common\project.ld

/* Memory sections */
MEMORY
{
  /* RAM */
  ITCMRAM       (xrw) : ORIGIN = 0x00000000,             LENGTH = 64K
  DTCMRAM       (xrw) : ORIGIN = 0x20000000,             LENGTH = 128K
  RAM_SHARED    (xrw) : ORIGIN = SHARED_RAM_ORIGIN,      LENGTH = SHARED_RAM_LENGTH
  RAM_D1        (xrw) : ORIGIN = 0x24000400,             LENGTH = 320K-1K
  RAM_D2        (xrw) : ORIGIN = 0x30000000,             LENGTH = 32K
  RAM_D3        (xrw) : ORIGIN = 0x38000000,             LENGTH = 16K

  /* EEPROM */
  DATA          (xrw) : ORIGIN = DATA_ORIGIN,            LENGTH = DATA_LENGTH

  /* FLASH */
  BOOTL_VECTORS (rx)  : ORIGIN = BOOTL_VECTORS_ORIGIN,   LENGTH = BOOTL_VECTORS_LENGTH
  BOOTL_SHARED  (rx)  : ORIGIN = BOOTL_SHARED_ORIGIN,    LENGTH = BOOTL_SHARED_LENGTH
  BOOTL_HEADER  (rx)  : ORIGIN = BOOTL_HEADER_ORIGIN,    LENGTH = BOOTL_HEADER_LENGTH
  BOOTL_CODE    (rx)  : ORIGIN = BOOTL_CODE_ORIGIN,      LENGTH = BOOTL_CODE_LENGTH
  BOOTL_FOOTER  (rx)  : ORIGIN = BOOTL_FOOTER_ORIGIN,    LENGTH = BOOTL_FOOTER_LENGTH

  BOOTU_VECTORS (rx)  : ORIGIN = BOOTU_VECTORS_ORIGIN,   LENGTH = BOOTU_VECTORS_LENGTH
  BOOTU_SHARED  (rx)  : ORIGIN = BOOTU_SHARED_ORIGIN,    LENGTH = BOOTU_SHARED_LENGTH
  BOOTU_HEADER  (rx)  : ORIGIN = BOOTU_HEADER_ORIGIN,    LENGTH = BOOTU_HEADER_LENGTH
  BOOTU_CODE    (rx)  : ORIGIN = BOOTU_CODE_ORIGIN,      LENGTH = BOOTU_CODE_LENGTH
  BOOTU_FOOTER  (rx)  : ORIGIN = BOOTU_FOOTER_ORIGIN,    LENGTH = BOOTU_FOOTER_LENGTH
}

/* Entry Point */
ENTRY(Reset_Handler)

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM_D1) + LENGTH(RAM_D1);	/* end of "RAM_D1" Ram type memory */

_Min_Heap_Size = 0x1000;	/* required amount of heap  */
_Min_Stack_Size = 0x1000;	/* required amount of stack */

/* Sections */
SECTIONS
{
  /*=============== EEPROM data memory ==========================================================*/
  .app_data ORIGIN(DATA) :
  {
    . = ALIGN(4);
    KEEP(*(.app_data))
    . = ALIGN(4);
  } >DATA

  /*=============== The startup code into "FLASH" Rom type memory ===============================*/
  .isr_vector ORIGIN(BOOTU_VECTORS) :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
  } >BOOTU_VECTORS

  /*=============== BootUpdater/product information =============================================*/
  .shared_flash ORIGIN(BOOTU_SHARED) :
  {
    . = ALIGN(4);
    KEEP(*(.shared_flash))
    . = ALIGN(4);
  } >BOOTU_SHARED

  /*=============== BootUpdader header ==========================================================*/
  .app_header ORIGIN(BOOTU_HEADER) :
  {
    . = ALIGN(4);
    KEEP(*(.app_header))
    . = ALIGN(4);
  } >BOOTU_HEADER

  /* The program code and other data into "INTERNAL FLASH" Rom type memory */
  .text ORIGIN(BOOTU_CODE) :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
    *(.eh_frame)

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */
  } >BOOTU_CODE

  /* Constant data into "FLASH" Rom type memory */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >BOOTU_CODE

  .ARM.extab   : { 
    . = ALIGN(4);
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    . = ALIGN(4);
  } >BOOTU_CODE
  
  .ARM : {
    . = ALIGN(4);
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
    . = ALIGN(4);
  } >BOOTU_CODE

  .preinit_array     :
  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    . = ALIGN(4);
  } >BOOTU_CODE
  
  .init_array :
  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
    . = ALIGN(4);
  } >BOOTU_CODE
  
  .fini_array :
  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
    . = ALIGN(4);
  } >BOOTU_CODE

  /* Used by the startup to initialize data */
  _sidata = LOADADDR(.data);

  /* Initialized data sections into "RAM_D1" Ram type memory */
  .data : 
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */
    
  } >RAM_D1 AT> BOOTU_CODE

  /*=============== BootUpdater footer ==========================================================*/
  .app_footer ORIGIN(BOOTU_FOOTER) :
  {
    . = ALIGN(4);
    KEEP(*(.app_footer))
    . = ALIGN(4);
  } >BOOTU_FOOTER

  /*=============== Shared RAM ==================================================================*/
  .shared_ram :
  {
	. = ALIGN(4);
    KEEP(*(.shared_ram))
	. = ALIGN(4);
  } >RAM_SHARED

  /* Uninitialized data section into "RAM_D1" Ram type memory */
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss section */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM_D1

  /* 32bit aligned data buffer used to program a flash memory page */
  .flash_page  (NOLOAD) :
  {
	. = ALIGN(4);
    *(.flash_page)
	. = ALIGN(4);
  } >RAM_D1

  /* User_heap_stack section, used to check that there is enough "RAM_D1" Ram  type memory left */
  ._user_heap_stack :
  {
    . = ALIGN(8);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >RAM_D1

  /* Remove information from the compiler libraries */
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }
}
