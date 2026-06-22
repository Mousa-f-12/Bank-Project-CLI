#pragma once

#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{

private:

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

	static bool _MakeSureUpdateCurrencyRate()
	{
		char Answer;
		Answer = clsInputValidate::ReadChar("Are You Sure To Update This Currency? [y/n] :");
		return (Answer == 'Y' || Answer == 'y');
	}

public:


	static void UpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("Update Currency Rate Screen");

		string CurrencyCode = clsInputValidate::ReadString("\nEnter Currency Code : ");

		clsCurrency Currency = clsCurrency::FinByCurrencyCode(CurrencyCode);

		if (!Currency.IsEmpty())
		{
			_PrintCurrencyInfo(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found\n";
		}

		if (_MakeSureUpdateCurrencyRate())
		{
			float NewRate = clsInputValidate::ReadIntNumber<float>("\nEnter New Currency Rate : ");

			Currency.UpdateCurrencyRate(NewRate);

			_PrintCurrencyInfo(Currency);

			cout << "\n\nUpdated Successfuly\n";
		}
		else
		{
			cout << "\nOperation Cancelled\n";
		}
	}






};

