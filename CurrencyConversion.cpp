// Chau Tran
// Description:
// This is my first C++ project.
// A console app that exchange from Euro to Dollar and vice versa

#include <iostream>
#include <istream>
#include <sstream>
#include <string>

// 

const double DOLLAR_TO_EURO = 0.93;

double RoundMoney(double inVal);
double DoConversion(char fromCurrency, char toCurrency, double inMoney);
char ValidateCurrency(std::string currencyString);
void StartBankTeller();


int main()
{
    
    StartBankTeller();

    return 0;
}



double RoundMoney(double inVal)
{
    // round to second decimal
    return std::ceil(inVal * 100) / 100;
}

double DoConversion(char fromCurrency, char toCurrency, double inMoney)
{
    double outMoney = 0;
    switch (fromCurrency)
    {
    case 'D':
        switch (toCurrency)
        {
        case 'E':
            outMoney = inMoney * DOLLAR_TO_EURO;
            break;
        default:
            //StartBankTeller();

            break;
        }

        break;
    case 'E':
        switch (toCurrency)
        {
        case 'D':
            outMoney = inMoney / DOLLAR_TO_EURO;
            break;
        default:
            //StartBankTeller();
            break;
        }
        break;
    default:
        //StartBankTeller();

        break;

    }
    outMoney = RoundMoney(outMoney);
    return outMoney;
}

char ValidateCurrency(std::string currencyString)
{
    if (currencyString.length() != 1)
    {
        std::cout << "Please enter a valid character\n";
        StartBankTeller();
    }
    else if (std::toupper(currencyString.front()) != 'D' ||
        std::toupper(currencyString.front()) != 'E')
    {
        std::cout << "The currency is not valid. Please enter a valid character\n";
        StartBankTeller();
    }
    return std::toupper(currencyString.front());
}

void StartBankTeller()
{
    std::string fromCurrencyString;
    std::string toCurrencyString;

    char fromCurrency;
    char toCurrency;

    double inMoney = 0;
    double outMoney = 0;
    std::cout << "*******************************\n";
    std::cout << "Welcome to ChauBank's currency exchange service." << '\n';
    std::cout << "What currency do you want to exchange from? (D/E)";
    std::getline(std::cin >> std::ws, fromCurrencyString);

    fromCurrency = ValidateCurrency(fromCurrencyString);

    std::cout << "What currency do you want to exchange to? (D/E)";
    std::getline(std::cin >> std::ws, toCurrencyString);

    toCurrency = ValidateCurrency(toCurrencyString);

    std::cout << "How much do you want to exchange? ";
    std::cin >> inMoney;

    if (std::cin.fail())
    {
        std::cout << "Please enter a valid number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        StartBankTeller();
    }


    if (fromCurrency == toCurrency)
        outMoney = inMoney;
    else
        outMoney = DoConversion(fromCurrency, toCurrency, inMoney);


    std::cout << "You have " << outMoney << toCurrency << '\n';
    std::cout << "Thank you for using ChauExchange. Have a good day!\n";

    StartBankTeller();
}
