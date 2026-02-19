<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RP2350 UART Crash Diagnostics</title>
    <style>
        body {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Helvetica, Arial, sans-serif;
            line-height: 1.6;
            color: #c9d1d9;
            background-color: #0d1117;
            margin: 0;
            padding: 20px;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background: #161b22;
            padding: 40px;
            border-radius: 8px;
            border: 1px solid #30363d;
        }
        h1 {
            color: #58a6ff;
            border-bottom: 1px solid #30363d;
            padding-bottom: 10px;
        }
        h2 {
            color: #3fb950;
            margin-top: 30px;
        }
        code {
            background-color: rgba(110, 118, 129, 0.4);
            padding: 0.2em 0.4em;
            border-radius: 6px;
            font-family: "SFMono-Regular", Consolas, "Liberation Mono", Menlo, monospace;
            font-size: 85%;
        }
        pre {
            background-color: #010409;
            padding: 16px;
            border-radius: 6px;
            overflow: auto;
            border: 1px solid #30363d;
        }
        pre code {
            background-color: transparent;
            padding: 0;
            color: #e6edf3;
        }
        .features ul {
            list-style-type: square;
        }
        .footer {
            margin-top: 50px;
            font-size: 0.9em;
            color: #8b949e;
            text-align: center;
            border-top: 1px solid #30363d;
            padding-top: 20px;
        }
        .badge {
            display: inline-block;
            background: #238636;
            color: white;
            padding: 2px 10px;
            border-radius: 20px;
            font-size: 0.8em;
            font-weight: bold;
        }
    </style>
</head>
<body>

<div class="container">
    <span class="badge">RP2350 / Pico 2</span>
    <h1>RP2350 UART Crash Diagnostics</h1>
    <p>A lightweight, professional <strong>HardFault Handler</strong> and diagnostic tool for the RP2350 (Raspberry Pi Pico 2). This tool captures the CPU state at the moment of a critical system crash.</p>

    <h2>🚀 Features</h2>
    <div class="features">
        <ul>
            <li><strong>Full Register Dump:</strong> Captures core registers (r0-r12, LR, PC, xPSR).</li>
            <li><strong>Kernel Insights:</strong> Utilizes ARM Cortex-M33 system registers to identify crash causes.</li>
            <li><strong>Optimized for n64_pico_project:</strong> Configured for UART diagnostic pins (GPIO 20/21).</li>
        </ul>
    </div>

    <h2>🛠️ Implementation</h2>
    <p>Include the header in your <code>main.cpp</code> file:</p>
    <pre><code>#include "uart_diag.h"

int main() {
    stdio_init_all();
    // Your n64_pico_project logic
    return 0;
}</code></pre>

    <h2>📟 Example Output</h2>
    <pre><code>--- CRASH DUMP ---
R0:  0x00000000
R1:  0x20001234
PC:  0x100005A2
LR:  0x100004BF
--- END OF DUMP ---</code></pre>

    <div class="footer">
        Developed as part of the <strong>n64_pico_project</strong><br>
        Built for high-performance RP2350 applications.
    </div>
</div>

</body>
</html>
