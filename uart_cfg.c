#include "uart_cfg.h"
#include <stdio.h>

void print_project_pinout(void) {
    printf("\n--- PROJECT PINOUT ---\n");
    printf("  PIN NAME   |  GPIO  |  FUNCTION\n");
    printf("  -----------|--------|----------\n");
    printf("  EXAMPLE    |  0     |  UART TX\n");
    // ... users will fill this with N64/HDMI pins
}

void print_project_status(void) {
    printf("\n--- SYSTEM STATUS ---\n");
    printf("  Status: Operational\n");
}