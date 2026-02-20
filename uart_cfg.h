#ifndef UART_CFG_H
#define UART_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

// Functions to be implemented by the user in uart_cfg.c
void print_project_pinout(void);
void print_project_status(void);

#ifdef __cplusplus
}
#endif

#endif