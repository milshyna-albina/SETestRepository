#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

bool isInteger(const string& input)
{
    if (input.empty()) {
        throw invalid_argument("Input is empty.");
    }
    for (unsigned int i = (input[0] == '-' ? 1 : 0); i < input.length(); i++) {
        if (!isdigit(input[i])) {
            throw invalid_argument("Input is not a valid integer.");
        }
    }
    return true;
}

int validateN(const string& input)
{
    if (!isInteger(input)) {
        throw invalid_argument("'n' must be a valid integer.");
    }

    int n = stoi(input);
    if (n <= 2) {
        throw out_of_range("'n' must be greater than 2.");
    }
    return n;
}

double validateNumber(const string& input)
{
    if (input.empty() || (input == "." || input == ",")) {
        throw invalid_argument("Input must be a valid number.");
    }

    for (unsigned int i = (input[0] == '-' ? 1 : 0); i < input.length(); i++) {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != ',') {
            throw invalid_argument("Input must be a valid number.");
        }
    }

    return stod(input);
}

double validateStep(double step)
{
    if (step <= 0) {
        throw invalid_argument("'step' must be greater than 0.");
    }
    return step;
}

double validateRange(double a, double b)
{
    if (b <= a) {
        throw invalid_argument("'b' must be greater than 'a'.");
    }
    return b;
}

double SimpleAlgorithm(int n, double x)
{
    double y = 0;
    if (x < 0) {
        for (int i = 2; i <= n; i++) {
            y += pow((i - 3 + x), 2);
        }
    }
    else {
        for (int i = 0; i <= n; i++) {
            double p = 1;
            for (int j = 1; j <= (n - 1); j++) {
                p *= (i + j) / (2.0 * pow((1 + x), 2));
            }
            y += p;
        }
    }

    return y;
}

double ExtendedAlgorithm(int n, double a, double b, double step)
{
    double y, result = 0;
    for (double x = a; x <= b; x += step) {
        y = 0;
        if (x < 0) {
            for (int i = 2; i <= n; i++) {
                y += pow((i - 3 + x), 2);
            }
        }
        else {
            for (int i = 0; i <= n; i++) {
                double p = 1;
                for (int j = 1; j <= (n - 1); j++) {
                    p *= (i + j) / (2.0 * pow((1 + x), 2));
                }
                y += p;
            }
        }
        cout << defaultfloat << setprecision(15);
        cout << "If x = " << x << "; then y = " << y << endl;
        result += y;
    }
    return result;
}

int main()
{
    int choice, n;
    double a, b, step, x;
    string repeat;

    while (true) {

        cout << "Choose an algorithm:\n";
        cout << "1. Simple version with x and n.\n";
        cout << "2. Extended version with n, a, b and step.\n";
        cout << "Enter your choice (1 or 2): ";

        string inputChoice;
        getline(cin, inputChoice);

        try {
            if (!isInteger(inputChoice)) {
                throw invalid_argument("Invalid choice. Please choose 1 or 2.");
            }

            choice = stoi(inputChoice);
            if (choice == 1) {
                while (true) {
                    string inputN;
                    cout << "Input n > 2, n = ";
                    getline(cin, inputN);

                    try {
                        n = validateN(inputN);
                        break;
                    }
                    catch (const exception& err) {
                        cout << err.what() << endl;
                    }
                }

                while (true) {
                    string inputX;
                    cout << "Input x = ";
                    getline(cin, inputX);

                    try {
                        x = validateNumber(inputX);
                        break;
                    }
                    catch (const exception& err) {
                        cout << err.what() << endl;
                    }
                }

                cout << "Result = " << SimpleAlgorithm(n, x) << endl;
            }
            else if (choice == 2) {

                while (true) {
                    string inputN;
                    cout << "Input n > 2, n = ";
                    getline(cin, inputN);

                    try {
                        n = validateN(inputN);
                        break;
                    }
                    catch (const exception& err) {
                        cout << err.what() << endl;
                    }
                }

                while (true) {
                    string inputA;
                    cout << "Input a = ";
                    getline(cin, inputA);

                    try {
                        a = validateNumber(inputA);
                        break;
                    }
                    catch (const exception& err) {
                        cout << err.what() << endl;
                    }
                }

                while (true) {
                    string inputB;
                    cout << "Input b > a, b = ";
                    getline(cin, inputB);

                    try {
                        b = validateNumber(inputB);
                        b = validateRange(a, b);
                        break;
                    }
                    catch (const exception& err) {
                        cout << err.what() << endl;
                    }
                }

                while (true) {
                    string inputStep;
                    cout << "Input step > 0, step = ";
                    getline(cin, inputStep);

                    try {
                        step = validateNumber(inputStep);
                        step = validateStep(step);
                        break;
                    }
                    catch (const exception& err) {
                        cout << err.what() << endl;
                    }
                }

                cout << "General result = " << ExtendedAlgorithm(n, a, b, step) << endl;
            }
            else {
                throw invalid_argument("Invalid choice. Please choose 1 or 2.");
            }
        }
        catch (const exception& err) {
            cout << err.what() << endl;
            continue;
        }

        while (true) {
            try {
                cout << "Do you want to run the program again? (y/n): ";
                getline(cin, repeat);

                if (repeat.empty() || (repeat != "y" && repeat != "Y" && repeat != "n" && repeat != "N")) {
                    throw invalid_argument("Invalid input. Please enter 'y' or 'n'.");
                }

                if (repeat == "N" || repeat == "n") {
                    return 0;
                }

                break;
            }
            catch (const invalid_argument& err) {
                cout << err.what() << endl;
            }
        }
        if (repeat == "N" || repeat == "n") {
            break;
        }
    }

    return 0;
}

