# 🧮 C++ Scientific Calculator

A simple yet powerful **console-based calculator** written in **C++**, supporting both **basic** and **scientific operations**.  
It takes user input, validates it, and performs calculations using modular functions and a structured switch-case design.
---
## ⚙️ Features

### 🧩 Core Functionality
- ✅ **Input validation** using `std::stod` and exception handling  
- ➕ Addition  
- ➖ Subtraction  
- ✖️ Multiplication  
- ➗ Division (handles division by zero gracefully)  
- 🔺 Power / Exponentiation (`^`)  
- 🟰 Square Root (`r`) — only accepts non-negative values  
- 🧮 Modulus (`%`) — supports both integer and floating-point remainders  
- 🧭 Trigonometric Functions: Sine (`s`), Cosine (`c`), Tangent (`t`)  
- 🧱 Absolute Value (`a`)  
- 🧬 Factorial (`f`) — with overflow protection for numbers above 20  
- 🔁 Loops to allow multiple calculations without restarting  

---

### 🧠 Smart Features
- 🧾 **Input prompts** handle invalid or unexpected values gracefully  
- 🏃 **Type `exit`** at any prompt to quit safely  
- 🔡 **Case-insensitive input** for `exit`, `yes`, and `no`  
- 💡 **Consistent precision** with 3 decimal places using `std::setprecision`  
- 🔒 **Guards against** divide-by-zero and invalid modulus  
- 🔢 **Factorial validation** ensures safe input and overflow control  


---
## 🚀 How to Compile and Run

💡 **Note:** Ensure you have a C++ compiler installed (e.g., g++).

1. Clone the repository:
git clone https://github.com/GhostByte26/cpp-calculator.git

2. Compile the code:
g++ calculator.cpp -o calculator

3. Run the program:
Linux/macOS

./calculator

Windows

calculator.exe

🧩 Example Usage
Please enter the first number or type exit to quit
> 5
Please enter the desired operation symbol (+,-,*,/,^,r,%,s,c,t,a,f)
> ^
Please enter the second number or type exit to quit
> 3
The exponential is: 125.000
Do you want to perform another calculation (yes/no)
> yes

🧠 Notes

Factorials above 20! are restricted to prevent overflow.

Modulus automatically detects whether to use integer or floating-point mode.

Output precision is set globally to 3 decimal places for consistent formatting.

👨‍💻 Author

Gilberto Medina (GhostByte26)
📅 October 2025
🧠 Built with care and continuous learning in C++
