#pragma once

#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


class clsCurrencyCalculatorScreen : protected clsScreen
{
	
private:

	static clsCurrency _ReadAndValidateCurrency(string Message)
	{
		string Currency1Code = clsInputValidate::ReadString(Message);

		while (!clsCurrency::isCurrencyExists(Currency1Code))
		{
			string Currency1Code = clsInputValidate::ReadString("\nCurrency Not Exists, Enter Another One : ");
		}

		clsCurrency Currency = clsCurrency::FinByCurrencyCode(Currency1Code);

		return Currency;
	}

	static void _PrintCurrencyInfo(const clsCurrency& Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "---------------------------------\n";
		cout << "Country  : " << Currency.CurrencyContry() << endl;
		cout << "Code     : " << Currency.CurrencyCode() << endl;
		cout << "Name     : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) : " << Currency.CurrencyRate() << endl;
		cout << "---------------------------------\n";
	}

	static void _PrintCalculationResults(clsCurrency Currency1, clsCurrency Currency2, float Amount)
	{
		float USDAmount = Currency1.ConvertCurrencyToUSD(Amount);

		_PrintCurrencyInfo(Currency1);
		cout << "\n\nConverted To USD \n-----------------\n";
		cout << Currency1.CurrencyCode() << " " << Amount << " = " << USDAmount << "\n\n";


		if (Currency2.CurrencyCode() != "USD")
		{
			cout << "Converting From USD To..." << Currency2.CurrencyCode() << endl;

			_PrintCurrencyInfo(Currency2);
			cout << Currency1.CurrencyCode() << " " << Amount << " = " << Currency2.ConvertUSDToCurrency(USDAmount);
		}
	}

	

public:

	static void CurrencyCalculatorScreen()
	{
		_DrawScreenHeader("Currency Calculator Screen");
		
		clsCurrency Currency1 = _ReadAndValidateCurrency("\nEnter Currency Code 1 : ");

		clsCurrency Currency2 = _ReadAndValidateCurrency("\nEnter Currency Code 1 : ");

		float Amount = clsInputValidate::ReadIntNumber<float>("\nEnter Exchange Amount : ");

		_PrintCalculationResults(Currency1, Currency2, Amount);
	}

};

