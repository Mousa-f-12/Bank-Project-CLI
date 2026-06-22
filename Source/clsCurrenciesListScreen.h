#pragma once
#include <iostream>
#include <vector>
#include "clsCurrency.h"
#include <iomanip>
#include "clsScreen.h"

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
public:

    static void ShowCurrenciesListScreen()
    {

        _DrawScreenHeader("Currencies List Screen");

        vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        string line = "\t\t----------------------------------------------------------------------------------------";

        cout << "\n" << line << endl;

        cout << "\t\tCurrencies Count ("
            << vCurrencies.size()
            << ") Currency/ies.\n";

        cout << line << endl;

        // Header
        cout << "\t\t"
            << left << setw(30) << "Country Name" << " | "
            << left << setw(15) << "Currency Code" << " | "
            << left << setw(30) << "Currency Name" << " | "
            << left << setw(10) << "Rate(1$)"
            << endl;

        cout << line << endl;



        if (vCurrencies.size() == 0)
        {
            cout << "No Currencies in the list \n";
        }
        else
        {
            // Rows

            for (clsCurrency& Currency : vCurrencies)
            {
                cout << "\t\t"
                    << left << setw(30) << Currency.CurrencyContry() << " | "
                    << left << setw(15) << Currency.CurrencyCode() << " | "
                    << left << setw(30) << Currency.CurrencyName() << " | "
                    << left << setw(10) << Currency.CurrencyRate()
                    << endl;
            }
        }

        cout << line << endl;
    }
};
