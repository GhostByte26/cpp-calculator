🧮 C++ Scientific Calculator

A simple yet powerful console-based calculator written in modern C++, supporting both basic and scientific operations.
It takes user input, validates it, and performs calculations using modular functions and a structured switch-case design.

⚙️ Features
🧩 Core Functionality

✅ Input validation using std::stod and exception handling

➕ Addition

➖ Subtraction

✖️ Multiplication

➗ Division (with divide-by-zero protection)

🔺 Power / Exponentiation (^)

🟰 Square Root (r) — only accepts non-negative values

🧮 Modulus (%) — supports integer and floating-point inputs

🧭 Trigonometric Functions:

Sine (s)

Cosine (c)

Tangent (t)

🧱 Absolute Value (a)

🧬 Factorial (f) — overflow protection above 20

🔁 Loops to allow multiple calculations without restarting

🧠 Smart Features

🧾 Graceful error handling for invalid or unexpected input

🔡 Case-insensitive commands for exit, yes, no

💡 Consistent formatting using std::setprecision(3)

🔒 Safeguards for divide-by-zero and factorial overflow

🧮 Modulus detects type and adjusts automatically

🧱 Project Structure (Modular Design)
calculator/
├── include/               # Header files
│   ├── add.h
│   ├── subtract.h
│   ├── multiply.h
│   ├── division.h
│   └── ... more .h files
├── src/                   # Function definitions
│   ├── add.cpp
│   ├── subtract.cpp
│   ├── multiply.cpp
│   ├── division.cpp
│   └── ... more .cpp files
├── main.cpp               # Main interface logic
├── calculator.exe         # Executable (on Windows)
└── README.md              # This file

🚀 How to Compile and Run

💡 Ensure you have a working C++ compiler like g++.

1. Clone the repository:
git clone https://github.com/GhostByte26/cpp-calculator.git

2. Compile:
g++ -Iinclude src/*.cpp main.cpp -o calculator

3. Run:
# On Linux/macOS:
./calculator

# On Windows (PowerShell or CMD):
.\calculator.exe

🧩 Example Session
Please enter the first number or type exit to quit:
> 5

Please enter the operation symbol (+, -, *, /, ^, r, %, s, c, t, a, f):
> ^

Please enter the second number or type exit to quit:
> 3

The exponential is: 125.000

Do you want to perform another calculation (yes/no)?
> yes

👨‍💻 Author

Gilberto Medina (GhostByte26)
📅 October 2025
🧠 Built with care and continuous learning in C++

✅ Next Goals

 Add OOP version using classes

 Add angle toggle (Degrees ↔ Radians)

 Store calculation history

 Add UI front-end (maybe with SFML or a web UI wrapper)

🔗 License

MIT License — open source and free to use, modify, and learn from.