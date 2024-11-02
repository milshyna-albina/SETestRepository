// Calculation of an expression with domain 1

#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>

using namespace std;

int inputN() 
{
    string input;
    int n;
    bool valid = false;

    while (!valid) {
        cout << "Input n > 2, n = ";
        cin >> input;

        if (input.empty() || (input[0] == '-' && input.length() == 1))
        {
            cout << "Error: 'n' must be a valid integer." << endl;
            continue;
        }

        bool isValidInteger = true;
        for (unsigned int i = (input[0] == '-' ? 1 : 0); i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                isValidInteger = false;
                break;
            }
        }

        if (isValidInteger)
        {
            n = stoi(input);
            if (n > 2)
            {
                return n;
            }
            else
            {
                cout << "Error: 'n' must be bigger than 2." << endl;
            }
        }
        else
        {
            cout << "Error: 'n' must be a valid integer." << endl;
        }
    }
}

double inputNumber(const string& message) 
{
    string input;
    double number;

    while (true) {
        cout << message;
        cin >> input;


        if (input.empty() || (input[0] == '-' && input.length() == 1)) {
            cout << "Error: Input must be a valid number." << endl;
            continue;
        }

        bool point = false;
        bool valid_number = true;

        for (unsigned int i = (input[0] == '-' ? 1 : 0); i < input.length(); i++) 
        {
            if (input[i] == '.' || input[i] == ',')
            {
                if (point) 
                {
                    valid_number = false;
                    break;
                }
                point = true;
            }
            else
            {
                if (!isdigit(input[i]))
                {
                    valid_number = false;
                    break;
                }
            }
        }

        if (valid_number) 
        {
            number = stod(input);
            return number;
        }
        else 
        {
            cout << "Error: Input must be a valid number." << endl;
        }
    }
}

void SimpleAlgorithm() 
{
    double y = 0;
    int n = inputN();
    double x = inputNumber("Input x = ");

    if (x < 0) 
    {
        for (int i = 2; i <= n; i++) 
        {
            y += pow((i - 3 + x), 2);
        }
    }
    else 
    {
        for (int i = 0; i <= n; i++) 
        {
            double p = 1;
            for (int j = 1; j <= (n - 1); j++) 
            {
                p *= (i + j) / (2.0 * pow((1 + x), 2));
            }
            y += p;
        }
    }

    cout << "Result = " << y << endl;
}

void ExtendedAlgorithm() 
{
    double y, result = 0;

    int n = inputN();

    double a = inputNumber("Input a = ");
    double b;
    while (true) 
    {
        b = inputNumber("Input b > a, b = ");
        if (b > a) 
        {
            break;
        }
        else 
        {
            cout << "Error: 'b' must be greater than 'a'." << endl;
        }
    }

    double step;
    while (true) 
    {
        step = inputNumber("Input step > 0, step = ");
        if (step > 0) 
        {
            break;
        }
        else 
        {
            cout << "Error: 'step' must be greater than 0." << endl;
        }
    }

    for (double x = a; x <= b; x += step) 
    {
        y = 0;

        if (x < 0) 
        {
            for (int i = 2; i <= n; i++) 
            {
                y += pow((i - 3 + x), 2);
            }
        }
        else 
        {
            for (int i = 0; i <= n; i++) 
            {
                double p = 1;
                for (int j = 1; j <= (n - 1); j++) 
                {
                    p *= (i + j) / (2.0 * pow((1 + x), 2));
                }
                y += p;
            }
        }
        cout << defaultfloat << setprecision(15);
        cout << "If x = " << x << "; then y = " << y << endl;
        result += y;
    }

    cout << "General result = " << result << endl;
}


int main()
{
    int choice;
    string repeat;

    while (true) 
    {
        cout << "Choose an algorithm:\n";
        cout << "1. Simple version with x and n.\n";
        cout << "2. Extended version with n, a, b and step.\n";
        cout << "Enter your choice (1 or 2): ";

        string inputChoice;
        getline(cin, inputChoice);

        if (!inputChoice.empty() && (inputChoice[0] != '-' || inputChoice.length() > 1)) 
        {
            bool isValidInteger = true;
            for (unsigned int i = (inputChoice[0] == '-' ? 1 : 0); i < inputChoice.length(); i++) 
            {
                if (!isdigit(inputChoice[i])) 
                {
                    isValidInteger = false;
                    break;
                }
            }

            if (isValidInteger) 
            {
                choice = stoi(inputChoice);
                if (choice == 1) 
                {
                    SimpleAlgorithm();
                }
                else if (choice == 2) 
                {
                    ExtendedAlgorithm();
                }
                else 
                {
                    cout << "Invalid input. Please choose 1 or 2.\n";
                    continue;
                }
            }
            else 
            {
                cout << "Invalid input. Please choose 1 or 2.\n";
                continue;
            }
        }
        else 
        {
            cout << "Invalid input. Please choose 1 or 2.\n";
            continue;
        }

        cout << "Do you want to run the program again? (y/n): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, repeat);

        while (repeat.empty() || (repeat != "Y" && repeat != "y" && repeat != "N" && repeat != "n")) 
        {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            getline(cin, repeat);
        }

        if (repeat == "N" || repeat == "n")
        {
            break;
        }
    }

    return 0;
}