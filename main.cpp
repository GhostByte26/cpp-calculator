#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <limits>
// Helper functions

double addNumbers(double num1, double num2)
{
    return num1 + num2;
}
double subtractNumbers(double num1, double num2)
{
    return num1 - num2;
}
double multiplyNumbers(double num1, double num2)
{
    return num1 * num2;
}
double divideNumbers(double num1, double num2)
{
    return num1 / num2;
}
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
// Get valid operation symbol
char getOperation()
{
    char op;
    std::cout << "Please enter the desired operation symbol(+,-,*,/)\n";
    std::cin >> op;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the buffer
    return op;
}

// Perform operation and print result
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
            std::cout << "The division is: \n";
        }
        else
        {
            std::cout << "Error: Division by zero is not allowed \n";
        }
        break;
    default:
        std::cout << "Invalid operator: Please use(+,-,*,/) \n";
        break;
    }
}

// Main loop

int main()
{
    while (true)
    {
        double num1 = getValidNumber("Please enter the first number or type exit to quit");
        double num2 = getValidNumber("Please enter the second number or type exit to quit");
        char operation = getOperation();

        performOperation(operation, num1, num2);

        std::string again;
        std::cout << "Do you want to perform another calculation (yes/no)\n";
        std::getline(std::cin, again);
        std::transform(again.begin(), again.end(), again.begin(), ::tolower);

        if (again == "no" || again == "exit")
        {
            std::cout << "Exiting calculator goodbye! \n";
            break;
        }
        std::cout << "\n"; // Prints a new line
    }
    return 0;
}
