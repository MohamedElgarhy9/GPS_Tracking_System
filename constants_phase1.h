#ifndef CONSTANTS_PHASE1_H_INCLUDED
#define CONSTANTS_PHASE1_H_INCLUDED

#define  PI  3.141592654
#define clear_display     0x01
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define DisplayOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define left							0x80
#define middle						0x81
#define right							0x82
#define CPAC (*((volatile uint32_t *)0xE000ED88))

#endif