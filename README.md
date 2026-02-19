# RP2350 UART Crash Diagnostics

A professional-grade **HardFault Handler** and diagnostic tool designed specifically for the **RP2350 (Raspberry Pi Pico 2 / Pico 2 W)**. This tool captures the exact state of the processor at the moment of a critical system crash and provides a detailed register dump via UART.

## 🚀 Key Features

* **Full Register Dump:** Automatically captures and prints core registers (`r0-r12`, `LR`, `PC`, `xPSR`) during a fault.
* **Kernel Diagnostics:** Leverages ARM Cortex-M33 system registers (NVIC, ICSR) to pinpoint the cause of the exception.
* **Optimized for Pico 2 W:** Default configuration uses diagnostic pins (GPIO 20/21) for UART logging.
* **Zero Dependencies:** Lightweight C++ implementation that integrates directly into the Raspberry Pi Pico SDK.

## 🛠️ Installation & Usage

### 1. Integrate the Header
Copy `uart_diag.h` into your project directory and include it in your `main.cpp`:

```cpp
#include "pico/stdlib.h"
#include "uart_diag.h"

int main() {
    // Standard initialization
    stdio_init_all();
    
    // Your n64_pico_project logic here
    while (true) {
        // ...
    }
}

2. Configure UART


​Ensure your UART interface is initialized before potential crashes occur. The handler will use the configured UART to transmit the crash report.


​📟 Example Diagnostic Log


​When the RP2350 encounters a HardFault (e.g., illegal memory access), the serial terminal will output:
--- !!! CRASH DUMP DETECTED !!! ---
Exception Type: HardFault
R0:  0x00000000    R1:  0x20001234
R2:  0x00000001    R3:  0x10000F00
R12: 0x20040000    LR:  0x100004BF
PC:  0x100005A2    xPSR:0x01000000
--- END OF DUMP ---

🏗️ Technical Specs




​Architecture: ARM Cortex-M33 / Hazard3 RISC-V (RP2350)


​Target Hardware: Raspberry Pi Pico 2 / Pico 2 W


​Language: C++


​Platform: Raspberry Pi Pico SDK 2.x




​Developed as part of the n64_pico_project for advanced debugging and hardware-level stability.


