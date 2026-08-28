#include <ch554.h>

void delay_us(uint16_t us) {
    while (us--) {
        __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
    }
}

void delay_ms(uint16_t ms) {
    while (ms--) {
        delay_us(1000);
    }
}

void reset_all_pins(void) {
    P1_MOD_OC &= ~((1<<4) | (1<<5) | (1<<6) | (1<<7));
    P1_DIR_PU &= ~((1<<4) | (1<<5) | (1<<6) | (1<<7));

    P3_MOD_OC &= ~((1<<0) | (1<<1) | (1<<2) | (1<<4));
    P3_DIR_PU &= ~((1<<0) | (1<<1) | (1<<2) | (1<<4));
}

void set_pin(uint8_t pin_idx, uint8_t level) {
    switch(pin_idx) {
        case 0: 
            P3_DIR_PU |= (1<<4);
            P3_MOD_OC &= ~(1<<4);
            if(level) P3 |= (1<<4); else P3 &= ~(1<<4);
            break;
        case 1: 
            P3_DIR_PU |= (1<<2);
            P3_MOD_OC &= ~(1<<2);
            if(level) P3 |= (1<<2); else P3 &= ~(1<<2);
            break;
        case 2:
            P1_DIR_PU |= (1<<4);
            P1_MOD_OC &= ~(1<<4);
            if(level) P1 |= (1<<4); else P1 &= ~(1<<4);
            break;
        case 3: 
            P1_DIR_PU |= (1<<5);
            P1_MOD_OC &= ~(1<<5);
            if(level) P1 |= (1<<5); else P1 &= ~(1<<5);
            break;
        case 4: 
            P1_DIR_PU |= (1<<6);
            P1_MOD_OC &= ~(1<<6);
            if(level) P1 |= (1<<6); else P1 &= ~(1<<6);
            break;
        case 5:
            P1_DIR_PU |= (1<<7);
            P1_MOD_OC &= ~(1<<7);
            if(level) P1 |= (1<<7); else P1 &= ~(1<<7);
            break;
        case 6: 
            P3_DIR_PU |= (1<<1);
            P3_MOD_OC &= ~(1<<1);
            if(level) P3 |= (1<<1); else P3 &= ~(1<<1);
            break;
        case 7: 
            P3_DIR_PU |= (1<<0);
            P3_MOD_OC &= ~(1<<0);
            if(level) P3 |= (1<<0); else P3 &= ~(1<<0);
            break;
    }
}

// ASCII Art Bitmaps (8 rows x 7 columns)
// Bit 0 corresponds to Column 0 (ROW7), Bit 6 corresponds to Column 6 (ROW0)
__code const uint8_t HEART_FRAME[8] = {
    0b01100110, //  . * * . . * * .
    0b11111111, //  * * * * * * * *
    0b11111111, //  * * * * * * * *
    0b11111111, //  * * * * * * * *
    0b01111110, //  . * * * * * * .
    0b00111100, //  . . * * * * . .
    0b00011000, //  . . . * * . . .
    0b00000000  //  . . . . . . . .
};

__code const uint8_t SMILEY_FRAME[8] = {
    0b00111100, //  . . * * * * . .
    0b01000010, //  . * . . . . * .
    0b10100101, //  * . * . . * . *
    0b10000001, //  * . . . . . . *
    0b10100101, //  * . * . . * . *
    0b10011001, //  * . . * * . . *
    0b01000010, //  . * . . . . * .
    0b00111100  //  . . * * * * . .
};

// Charlieplex scanning function: scans 1 frame over a set duration
void display_bitmap(const uint8_t *bitmap, uint16_t duration_ms) {
    uint16_t cycles = duration_ms; // each full 8-row cycle takes ~800us (~1ms)
    
    while(cycles--) {
        for (uint8_t row = 0; row < 8; row++) {
            uint8_t row_data = bitmap[row];
            
            // Activate the row by driving it HIGH
            for (uint8_t col = 0; col < 8; col++) {
                if (row == col) continue; // Cannot drive self in Charlieplexing
                
                // If the bit for this LED is 1, light it by sinking the column pin
                if (row_data & (1 << (col > row ? col - 1 : col))) {
                    reset_all_pins();
                    set_pin(row, 1); // Anode (VCC)
                    set_pin(col, 0); // Cathode (GND)
                    delay_us(100);   // Persistence pulse
                }
            }
        }
    }
    reset_all_pins();
}

void main(void) {
    // Set internal clock
    SAFE_MOD = 0x55;
    SAFE_MOD = 0xAA;
    CLOCK_CFG = CLOCK_CFG & ~MASK_SYS_CK_DIV | 0x06; // Standard 24MHz internal clock
    
    reset_all_pins();

    while (1) {
        display_bitmap(HEART_FRAME, 1000);  // Show Heart for 1 second
        display_bitmap(SMILEY_FRAME, 1000); // Show Smiley for 1 second
    }
}
