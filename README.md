<h1>🚀 UART Manager Kernel</h1>
<h3>Professional Menu & Command Dispatcher for RP2040 & RP2350</h3>

<p>A lightweight, non-blocking UART communication framework for Raspberry Pi Pico projects. This "Kernel" separates core logic from hardware configuration, making your code clean, modular, and easy to port between different projects (HDMI, Sensors, etc.).</p>

<hr>

<h2>📁 Project Structure</h2>
<p>The system is divided into two layers:</p>
<ul>
    <li><strong>The Kernel (<code>uart_manager.cpp/h</code>)</strong>: The engine that handles input, ANSI terminal formatting, and command routing. <strong>Do not modify this for new projects.</strong></li>
    <li><strong>The Config (<code>uart_cfg.c/h</code>)</strong>: The user-defined layer. This is where you put your project-specific pinout tables and status messages.</li>
</ul>

<h2>📍 Command Interface</h2>
<table>
    <thead>
        <tr>
            <th>Key</th>
            <th>Function</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><strong>p</strong></td>
            <td><strong>Show Pinout</strong></td>
            <td>Displays the hardware wiring map (defined in <code>uart_cfg.c</code>)</td>
        </tr>
        <tr>
            <td><strong>s</strong></td>
            <td><strong>Show Status</strong></td>
            <td>Displays system telemetry and hardware health</td>
        </tr>
        <tr>
            <td><strong>h</strong></td>
            <td><strong>Help / Reset</strong></td>
            <td>Clears the terminal screen and shows the command menu</td>
        </tr>
    </tbody>
</table>

<hr>

<h2>🛠 Integration Guide</h2>

<h3>1. Project Setup</h3>
<p>Add the files to your <code>CMakeLists.txt</code>. This kernel works on both <strong>RP2040</strong> and <strong>RP2350</strong>.</p>

<pre><code>
# Add these files to your executable
add_executable(${PROJECT_NAME}
    main.cpp
    uart_manager.cpp
    uart_cfg.c
)
</code></pre>

<h3>2. Main Loop Implementation</h3>
<p>Call the handler in your main loop using <code>getchar_timeout_us(0)</code> to ensure non-blocking operation.</p>

<pre><code>
#include "uart_manager.h"

int main() {
    stdio_init_all();

    while (true) {
        int cmd = getchar_timeout_us(0);
        if (cmd != PICO_ERROR_TIMEOUT) {
            handle_uart_input(cmd);
        }
        // Your other tasks continue running here
    }
}
</code></pre>

<h3>3. Customizing for your Hardware</h3>
<p>Edit <code>uart_cfg.c</code> to describe your specific wiring.</p>

<pre><code>
void print_project_pinout(void) {
    printf("\n--- PROJECT PINOUT MAP ---\n");
    printf("  SIGNAL      |  GPIO  |  DIRECTION\n");
    printf("  ------------|--------|-----------\n");
    printf("  DATA_BUS    |  0-7   |  In/Out\n");
    printf("  STATUS_LED  |  25    |  Output\n");
}
</code></pre>

<hr>

<h2>⚡ Multi-Platform Support</h2>
<ul>
    <li>Raspberry Pi Pico (RP2040)</li>
    <li>Raspberry Pi Pico 2 / 2 W (RP2350)</li>
    <li>Pico-W / Pico-2-W (Supports LED control via CYW43 architecture)</li>
</ul>

<h2>🖥 Terminal Compatibility</h2>
<p>For the best experience, use a terminal that supports <strong>ANSI Escape Codes</strong> (PuTTY, Tera Term, VS Code).</p>

<hr>
<p><strong>® by DriftKing</strong></p>
