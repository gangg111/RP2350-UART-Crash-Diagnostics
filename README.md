# 🚀 UART Manager Kernel
### Professional Menu & Command Dispatcher for RP2040 & RP2350

A lightweight, non-blocking UART communication framework for Raspberry Pi Pico projects. This "Kernel" separates core logic from hardware configuration, making your code clean, modular, and easy to port between different projects (N64, HDMI, Sensors, etc.).

---

## 📁 Project Structure
The system is divided into two layers:

1.  **The Kernel (`uart_manager.cpp/h`)**: The engine that handles input, ANSI terminal formatting, and command routing. **Do not modify this for new projects.**
2.  **The Config (`uart_cfg.c/h`)**: The user-defined layer. This is where you put your project-specific pinout tables and status messages.

## 📍 Command Interface
| Key | Function | Description |
|:---:|:---|:---|
| **`p`** | **Show Pinout** | Displays the hardware wiring map (defined in `uart_cfg.c`) |
| **`s`** | **Show Status** | Displays system telemetry and hardware health |
| **`h`** | **Help / Reset** | Clears the terminal screen and shows the command menu |

---

## 🛠 Integration Guide

### 1. Project Setup
Add the files to your `CMakeLists.txt`. This kernel works on both **RP2040** and **RP2350**.

```cmake
# Add these files to your executable
add_executable(${PROJECT_NAME}
    main.cpp
    uart_manager.cpp
    uart_cfg.c
)

# 2. Main Loop Implementation
  Call the handler in your main loop using getchar_timeout_us(0) to ensure non-blocking operation.

#include "uart_manager.h"

int main() {
    stdio_init_all();

    while (true) {
        // Non-blocking UART read
        int cmd = getchar_timeout_us(0);
        
        if (cmd != PICO_ERROR_TIMEOUT) {
            handle_uart_input(cmd);
        }

        // Your time-critical tasks (Video/Audio) continue running here
    }
}

# 3. Customizing for your Hardware
  Edit uart_cfg.c to describe your specific wiring.

void print_project_pinout(void) {
    printf("\n--- PROJECT PINOUT MAP ---\n");
    printf("  SIGNAL      |  GPIO  |  DIRECTION\n");
    printf("  ------------|--------|-----------\n");
    printf("  DATA_BUS    |  0-7   |  In/Out\n");
    printf("  STATUS_LED  |  25    |  Output\n");
}

#⚡ Multi-Platform Support
This kernel is fully compatible with:
Raspberry Pi Pico (RP2040)
Raspberry Pi Pico 2 / 2 W (RP2350)
Pico-W / Pico-2-W (Supports LED control via CYW43 architecture)

#🖥 Terminal Compatibility
For the best experience (including colors and screen clearing), use a terminal that supports ANSI Escape Codes, such as:
    PuTTY
    Tera Term
    VS Code Serial Monitor

® by DriftKing
