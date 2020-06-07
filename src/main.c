
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------


    // the vblank interrupt must be enabled for VBlankIntrWait() to work
    // since the default dispatcher handles the bios flags no vblank handler
    // is required
    irqInit();
    irqEnable(IRQ_VBLANK);
    const char * buffer = malloc(sizeof(char)*50);
    int count = 0;
    consoleDemoInit();

    // ansi escape sequence to set print co-ordinates
    // /x1b[line;columnH
    iprintf("\x1b[10;10HHello World!\n");
    iprintf("\x1b[11;10HHello World!\n");

    while (1) {
        VBlankIntrWait();
        sprintf(buffer, "\x1b[5;5Hcount: %d\n",count++);
        iprintf(buffer);
    }
}

