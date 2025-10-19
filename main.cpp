#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <limits>

int main()
{
    while (true)
    {
        std::string num1str;
        std::string num2str;
        char operation;
        double num1;
        double num2;

        bool validInput = false;
        bool validInput2 = false;

        while (!validInput) // Input validation loop for the first number and option to exit
        {

            std::cout << "Please enter the first number or type exit to quit \n";
            getline(std::cin, num1str); // Lowercase conversion for exit check, best used with getline to capture full input
            std::transform(num1str.begin(), num1str.end(), num1str.begin(), [](unsigned char c)
                           { return std::tolower(c); });
            if (num1str == "exit")
            {
                std::cout << "Exiting calculator goodbye!\n";
                return 0;
            }
            try
            {
                num1 = std::stod(num1str);
                validInput = true;
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid input. Please enter a valid number \n";
            }
        }
        while (!validInput2)
        {
            std::cout << "Please enter the second number \n";
            getline(std::cin, num2str);
            try
            {
                num2 = std::stod(num2str);
                validInput2 = true;
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid input. Please enter a valid number \n";
            }
        }
        std::cout << "Please enter the operation symbol(+,-,*,/)\n";
        std::cin.get(operation);                                            // Used to read a single character input for operation
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        switch (operation)
        {
        case '+':
            std::cout << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 != 0)
            {
                std::cout << num1 / num2 << "\n";
            }
            else
            {
                std::cout << " Error: Division by zero is not allowed. \n";
            }
            break;
        default:
            std::cout << "Invalid operation symbol. Please use on of (+,-,*,/)\n";
            break;
        }
        // Ask to continue operations or exit
        std::string again;
        std::cout << "Do you want to perform another calaculation? (yes/no): \n";
        getline(std::cin, again);
        std::transform(again.begin(), again.end(), again.begin(), ::tolower);
        if (again == "no" || again == "exit")
        {
            std::cout << "Exiting calculator goodbye!\n";
            break;
        }
        std::cout << "\n";
    }
    return 0;
}