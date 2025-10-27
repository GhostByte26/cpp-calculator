/*
===================================================
🧮  C++ Scientific Calculator
Author: Gilberto Medina (GhostByte26)
Date: October 2025

Description:
A console-based calculator that performs both basic and
scientific operations, including:
+ Addition, Substraction, Multiplication, Division
^ Power, Square Root, Modulus (Integer & decimal)
a Absolute value
f Factorial (with overflow protection)

Features:
-Input validation and safe exit commands
-Handles division/modulos by zero
-Supports both integer and floating-point modulus
-Consistent decimal precision formatting
-Looped user interaction ('yes/no' continuation)
-Factorial limited to safe range for 'long' data type

Usage:
Type "exit" at any prompt to quit.
====================================================
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numbers>
#include <iomanip>
// ==========================================================
// ===== Helper Functions (Mathematical Operations) =====
// ==========================================================

// Adds two numbers
double addNumbers(double num1, double num2)
{
    return num1 + num2;
}
// Substract the second number from the first one
double subtractNumbers(double num1, double num2)
{
    return num1 - num2;
}
// Multiplies two numbers
double multiplyNumbers(double num1, double num2)
{
    return num1 * num2;
}
// Divides num1 from num2 (handled safely in main)
double divideNumbers(double num1, double num2)
{
    return num1 / num2;
}
// Raises num1 to the power of num2
double power(double num1, double num2)
{
    double result = std::pow(num1, num2);
    return result;
}
// Returns the square root of num1
double sqrtNumber(double num1)
{
    double result = sqrt(num1);
    return result;
}
// Computes integer modulus (remainder)
int calculateModulus(int num1, int num2)
{

    return num1 % num2;
}
// Calculates sine (input assumed in radians)
double sineCalculator(double num1)
{
    double result = sin(num1);
    return result;
}
// Calculates cosine
double cosineCalculator(double num1)
{
    double result = cos(num1);
    return result;
}
// Calculates tangent
double tangentCalculator(double num1)
{
    double result = tan(num1);
    return result;
}
// Returns the absolute value of num1
double absoluteValue(double num1)
{
    double result = fabs(num1);
    return std::fabs(num1);
}
// Computes factorial of a positive number
//(Asumes input validated before calling)
long factorial(long num1)
{
    long result = 1;
    for (int i = 1; i <= num1; i++)
    {
        result *= i;
    }
    return result;
}

// ==========================================================
// ===== Input Validation Functions =====
// ==========================================================
double getValidNumber(const std::string &prompt)
{
    std::string input;
    double number;
    bool validInput = false;

    while (!validInput)
    {
        std::cout << prompt << "\n";
        std::getline(std::cin, input);

        // Lowercase conversion
        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c)
                       { return std::tolower(c); });

        if (input == "exit")
        {
            std::cout << "Exiting calculator goodbye\n";
            exit(0);
        }
        try
        {
            number = std::stod(input);
            validInput = true;
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid input. Please enter a valid number. \n";
        }
    }
    return number;
}
// =====Prompts user to select a Symbol Operation =====
char getOperation()
{
    char op;
    std::cout << "Please enter the desired operation symbol(+,-,*,/,^,r,%,s,c,t,a,f)\n";
    std::cin >> op;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the buffer
    return op;
}

// ===== Operation Execution =====

// Perform operation for two number cases(+, -, *, /, %, ^)
void performOperation(char op, double num1, double num2)
{
    double result;

    switch (op)
    {
    case '+':
        result = addNumbers(num1, num2);
        std::cout << "The result of the sum is: " << result << '\n';
        break;
    case '-':
        result = subtractNumbers(num1, num2);
        std::cout << "The subtraction is: " << result << '\n';
        break;
    case '*':
        result = multiplyNumbers(num1, num2);
        std::cout << "The multiplication is: " << result << '\n';
        break;
    case '/':
        if (num2 != 0)
        {
            result = divideNumbers(num1, num2);
            std::cout << "The division is: " << result << '\n';
        }
        else
        {
            std::cout << "Error: Division by zero is not allowed \n";
        }
        break;
    case '^':
        result = power(num1, num2);
        std::cout << "The exponential is: " << result << '\n';
        break;
    case '%':
        // Guard clause: Prevent modulus by zero
        if (num2 == 0)
        {
            std::cout << "Error: Modulus by zero is not alowed.\n";
            break;
        }
        // Choose integer or floating-point modulus based on input
        if (num1 == static_cast<int>(num1) && num2 == static_cast<int>(num2))
        {
            int result = calculateModulus(static_cast<int>(num1), static_cast<int>(num2));
            std::cout << "The reminder is: " << result << '\n';
        }
        else
        {
            double result = std::fmod(num1, num2);
            std::cout << "The decimal remainder is: " << result << '\n';
        }
        break;

    default:
        std::cout << "Invalid operator: Please use(+,-,*,/,^,r,%,s,c,t,a,f) \n";
        break;
    }
}

// ==========================================================
// ===== Main Program Loop =====
// ==========================================================

int main()
{
    // Configure output format to show 3 decimal places consistently
    std::cout << std::fixed << std::setprecision(3);
    while (true)
    {
        bool validInput = false;
        double num1;
        double num2;
        // Prompts the user for the first number and determines if a second input is needed.

        num1 = getValidNumber("Please enter the first number or type exit to quit");
        char operation = getOperation();
        // Handles single-number operations (square root, sine, etc.) and validates negative input.

        if (operation == 'r' || operation == 'R')
        {
            if (num1 < 0)
            {
                std::cout << "Error: Negative value are not accepted. Please enter a positive value \n";
            }

            else
            {
                double result = sqrtNumber(num1);
                std::cout << "The square root is: " << result << '\n';
            }
        }
        else if (operation == 's' || operation == 'S')
        {
            double result = sineCalculator(num1);
            std::cout << "The sine is: " << result << '\n';
        }
        else if (operation == 'c' || operation == 'C')
        {
            double result = cosineCalculator(num1);
            std::cout << "The cosine is: " << result << '\n';
        }
        else if (operation == 't' || operation == 'T')
        {
            double result = tangentCalculator(num1);
            std::cout << "The tangent is: " << result << '\n';
        }
        else if (operation == 'a' || operation == 'A')
        {
            double result = absoluteValue(num1);
            std::cout << "The absolute value is: " << result << '\n';
        }
        else if (operation == 'f' || operation == 'F')
        {
            // Validate that the number is within a safe range
            while (num1 < 0)
            {

                std::cout << "Invalid input: Please enter a positive number \n";
                num1 = getValidNumber("Please enter a positive number or type exit to quit");
            }
            if (num1 > 20)
            {
                std::cout << "Error: Factorial too large to compute";
            }
            else
            {

                long result = factorial(static_cast<long>(num1));
                std::cout << "The factorial is: " << result << '\n';
            }
        }
        // ===== Two Number Operations =====
        else
        {
            num2 = getValidNumber("Please enter the second number or type exit to quit");
            // Calls function that makes the operation takes 3 arguments operation, number 1 and number 2
            performOperation(operation, num1, num2);
        }

        // Ask's the user if they want to keep making calculations while input is not valid
        while (!validInput)
        {
            std::string again;
            std::cout << "Do you want to perform another calculation (yes/no)\n";
            std::getline(std::cin, again);
            std::transform(again.begin(), again.end(), again.begin(), ::tolower);
            if (again == "yes")
            {
                validInput = true;
            }

            else if (again == "no" || again == "exit")
            {

                std::cout << "Exiting calculator goodbye! \n";
                validInput = true;
                return 0;
            }
            else
            {
                std::cout << "Invalid input please type yes or no\n";
            }

            std::cout << "\n"; // Prints a new line
        }
    }
    return 0;
}
