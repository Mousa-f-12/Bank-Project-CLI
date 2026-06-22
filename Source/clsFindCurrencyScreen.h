#pragma once

#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{
private:

	enum _enFindBy {eCurrencyCountry = 1, eCurrencyCode};

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

	static void _ByCurrencyCountry()
	{
		string CountryName = clsInputValidate::ReadString("\nEnter Country Name : ");

		clsCurrency Currency = clsCurrency::FinByCurrencyCountry(CountryName);

		if (!Currency.IsEmpty())
		{
			_PrintCurrencyInfo(Currency);
		}
		else{
			cout << "\nCurrency Not Found\n";
		}
	}

	static void _ByCurrencyCode()
	{
		string CurrencyCode = clsInputValidate::ReadString("\nEnter Currency Code : ");

		clsCurrency Currency = clsCurrency::FinByCurrencyCode(CurrencyCode);

		if (!Currency.IsEmpty())
		{
			_PrintCurrencyInfo(Currency);
		}
		else {
			cout << "\nCurrency Not Found\n";
		}
	}

	static void PrefomreFindBy(_enFindBy Option)
	{
		switch (Option)
		{
			case _enFindBy::eCurrencyCountry:
			{
				_ByCurrencyCountry();
				break;
			}

			case _enFindBy::eCurrencyCode:
			{
				_ByCurrencyCode();
				break;
			}
		}
	}

public:

	static void FindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		cout << "\n--------------------------------------------------------\n";
		cout << "Find By [1] Currency Country Name, [2] Currency Code";
		cout << "\n--------------------------------------------------------\n";

		PrefomreFindBy(_enFindBy(clsInputValidate::ReadIntNumberBetween(1, 2, "Choose [ 1 - 2 ]")));
	}

};

