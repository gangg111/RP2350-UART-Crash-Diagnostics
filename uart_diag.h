#ifndef UART_DIAG_H
#define UART_DIAG_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/sync.h"

#define DIAG_UART_ID      uart1
#define DIAG_UART_TX_PIN  20
#define DIAG_UART_RX_PIN  21
#define DIAG_BAUD_RATE    115200

static inline void uart_diag_puts(const char *s) {
    uart_puts(DIAG_UART_ID, s);
    uart_tx_wait_blocking(DIAG_UART_ID);
}

extern "C" {
    void hard_fault_handler_c(uint32_t* hardfault_args) {
        uint core_id = get_core_num();
        volatile uint32_t cfsr  = *(volatile uint32_t*)0xE000ED28;
        volatile uint32_t hfsr  = *(volatile uint32_t*)0xE000ED2C;
        volatile uint32_t bfar  = *(volatile uint32_t*)0xE000ED38;
        uint32_t stacked_pc = hardfault_args[6];

        uart_diag_puts("\n*** KERNEL CRASH DETECTED ***\n");
        char buf[128];
        sprintf(buf, "CORE:  %u\nPC:    0x%08lX\n", core_id, (unsigned long)stacked_pc);
        uart_diag_puts(buf);

        if (cfsr & 0x82) {
            sprintf(buf, "BUS FAULT ADDR: 0x%08lX\n", (unsigned long)bfar);
            uart_diag_puts(buf);
        }
        if (cfsr & 0x01000000) uart_diag_puts("CAUSE: Usage Fault\n");
        if (hfsr & 0x40000000) uart_diag_puts("CAUSE: SDK Assert Failed\n");

        uart_diag_puts("*****************************\n");
        while (1) { __asm("bkpt #0"); }
    }

    void __attribute__((naked)) HardFault_Handler(void) {
        __asm volatile ("mrs r0, msp\nb hard_fault_handler_c\n");
    }
}
#endif
