#pragma once

#include <iostream>
#include "clsScreen.h"
#include "../course-10/clsString.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMenuScreen : protected clsScreen
{

private:

	enum _enCurrencyExchangeMenu { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenu = 5 };

	static void _GoBackToExchangeMenu()
	{
		cout << "\n\n\nPress Any Button To Go Back To Exchange Menu...\n";
		system("Color 07");
		system("pause > 0");
		system("cls");
		ShowCurrencyExchangeScreen();
	}

	static void _CurrenciesListScreen()
	{
		//cout << "We Are Working on this screen right now";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _FindCurrencyScreen()
	{
		//cout << "We Are Working on this screen right now";
		clsFindCurrencyScreen::FindCurrencyScreen();
	}

	static void _UpdateRateScreen()
	{
		//cout << "We Are Working on this screen right now";
		clsUpdateCurrencyRateScreen::UpdateCurrencyRateScreen();
	}

	static void _CurrencyCalculatorScreen()
	{
		cout << "We Are Working on this screen right now";
		clsCurrencyCalculatorScreen::CurrencyCalculatorScreen();
	}


	static void _PreformExchangeMenuOption(_enCurrencyExchangeMenu Option)
	{
		switch (Option)
		{
		case _enCurrencyExchangeMenu::eListCurrencies:
		{
			system("cls");
			_CurrenciesListScreen();
			_GoBackToExchangeMenu();
			break;
		}

		case _enCurrencyExchangeMenu::eFindCurrency:
		{
			system("cls");
			_FindCurrencyScreen();
			_GoBackToExchangeMenu();
			break;
		}

		case _enCurrencyExchangeMenu::eUpdateRate:
		{
			system("cls");
			_UpdateRateScreen();
			_GoBackToExchangeMenu();
			break;
		}

		case _enCurrencyExchangeMenu::eCurrencyCalculator:
		{
			system("cls");
			_CurrencyCalculatorScreen();
			_GoBackToExchangeMenu();
			break;
		}

		case _enCurrencyExchangeMenu::eMainMenu:
		{
			system("cls");
			break;
		}

		}
	}

public:

	static void ShowCurrencyExchangeScreen()
	{
		_DrawScreenHeader("Currency Exchange Screen");

		cout << "\n\n\t\t\t\t===============================================\n";
		cout << "\t\t\t\t===============================================\n\n";
		cout << "\t\t\t\t\t  [1] List Currencies.\n";
		cout << "\t\t\t\t\t  [2] Find Currency.\n";
		cout << "\t\t\t\t\t  [3] Update Rate.\n";
		cout << "\t\t\t\t\t  [4] Currency Calculator.\n";
		cout << "\t\t\t\t\t  [5] Main Menu.\n\n";
		cout << "\t\t\t\t===============================================\n";
		cout << "\t\t\t\t===============================================\n\n";

		_PreformExchangeMenuOption(_enCurrencyExchangeMenu(clsInputValidate::ReadIntNumberBetween(1, 5, "Choose Number From 1 to 5")));
	}



};

class clsCurrencyExchangeScreen
{
};


