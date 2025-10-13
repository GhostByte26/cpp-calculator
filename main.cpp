#include <iostream>
#include <string>

int main()
{
    std::string num1str;
    std::string num2str;
    char operation;
    double num1;
    double num2;

    bool validInput = false;
    bool validInput2 = false;

    while (!validInput)
    {

        std::cout << "Please enter the first number \n";
        getline(std::cin, num1str);
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
    std::cin.get(operation);

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
    return 0;
}
