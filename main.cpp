/* Ch12 #10 Password Verifier 
Imagine you are developing a software package that requires users to enter their own passwords.
Your software requires that user's passwords meet the following criteria:
- The password should be at least 6 characters long
- The password should contain at least 1 uppercase and 1 lowercase
- The password should have at least one digit

Write a program that asks for a password and then verfiies that it meets the stated criteria.
If it doesn't, the program should display a message telling th euser why. */

//START
#include <iostream> // includes i/o stream library for input and output operations
#include <cctype> // includes charater handling library for isupper, islower, isdigit


//INPUT VALIDATION FUNCTIONS FOR STRING CHARACTERISTICS USES CCTYPE
bool isValidPassword(const std::string& password) {
    //CHECKS LENGTH
    if (password.length() < 6) {
        std::cout << "Error: Password must be at least 6 characters long." << std::endl;
        return false;
    }

    //CHECKS UPPERCASE
    bool hasUppercase = false;
    for (char ch : password) {
        if (std::isupper(ch)) {
            hasUppercase = true;
            break;
        }
    }
    if (!hasUppercase) {
        std::cout << "Error: Password must contain at least one uppercase letter." << std::endl;
        return false;
    }

    //CHECKS LOWERCASE
    bool hasLowercase = false;
    for (char ch : password) {
        if (std::islower(ch)) {
            hasLowercase = true;
            break;
        }
    }
    if (!hasLowercase) {
        std::cout << "Error: Password must contain at least one lowercase letter." << std::endl;
        return false;
    }

    //CHECKS DIGIT
    bool hasDigit = false;
    for (char ch : password) {
        if (std::isdigit(ch)) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        std::cout << "Error: Password must contain at least one digit." << std::endl;
        return false;
    }

    return true;
}

//MAIN
int main() {
    std::cout << "***** PASSWORD TESTER PROGRAM ******" << std::endl;
    std::string password;
    do {
        std::cout << "Enter your password: ";
        std::cin >> password;
    } while (!isValidPassword(password));

    std::cout << "You entered a valid password." << std::endl;
    return 0;
}
//END