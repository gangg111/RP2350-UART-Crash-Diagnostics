#include "uart_manager.h"
#include "uart_cfg.h"
#include <stdio.h>
#include "pico/stdlib.h"

void handle_uart_input(int cmd) {
    switch(cmd) {
        case 'p':
            // Logic-agnostic call to the config file
            print_project_pinout();
            break;
        case 's':
            print_project_status();
            break;
        case 'h':
            printf("\033[2J\033[H"); // ANSI Clear Screen
            printf("--- COMMAND HELP ---\n");
            printf(" [p] Show Pinout\n");
            printf(" [s] Show Status\n");
            break;
    }
}
