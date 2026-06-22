#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../course-10/clsString.h"

using namespace std;


class clsCurrency
{

private:

	// Enum & Struct //

	enum _enMode { _eEmptyMode = 0, _eUpdateMode = 1 };


	// MemberMethods //

	_enMode _Mode;
	string _CurrencyName;      // ReadOnly
	string _CurrencyCode;     // ReadOnly
	string _CurrencyContry;  // ReadOnly
	float  _CurrencyRate;    // UpdateMode

	// MemberMethods // 

	static clsCurrency _ConvertLineToCurrencyObject(string Text, string Separator = "#//#")
	{
		vector <string> FetchedData = clsString::Split(Text, Separator);

		if (FetchedData.size() < 4)
			return _GetEmptyObject();

		return clsCurrency(_enMode::_eUpdateMode, FetchedData[0], FetchedData[1], FetchedData[2], stod(FetchedData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{
		string DataLine = "";

		DataLine += Currency.CurrencyContry() + Separator;
		DataLine += Currency.CurrencyCode() + Separator;
		DataLine += Currency.CurrencyName() + Separator;
		DataLine += to_string(Currency.CurrencyRate());

		return DataLine;
	}

	static vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{
		fstream File;
		string Line;
		vector <clsCurrency> vCurrencies;

		File.open("Currencies.txt", ios::in); // ReadMode

		if (File.is_open())
		{
			while (getline(File, Line))
			{
				if (Line != "")
				{
					clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
					vCurrencies.push_back(Currency);
				}
			}
			File.close();
		}
		return vCurrencies;
	}

	static void _SaveCurrenciesDataToFile(vector <clsCurrency>& vCurrencies)
	{
		fstream File;

		File.open("Currencies.txt", ios::out); // ReadMode

		if (File.is_open())
		{
			for (clsCurrency& C : vCurrencies)
			{
				File << _ConvertCurrencyObjectToLine(C) << endl;
			}
			File.close();
		}
	}

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(_enMode::_eEmptyMode, "", "", "", 0);
	}

	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == this->CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrenciesDataToFile(vCurrencies);
	}

public:

	clsCurrency(_enMode Mode, string CurrencyContry, string CurrencyCode, string CurrencyName, float CurrencyRate)
	{
		_Mode = Mode;
		_CurrencyName = CurrencyName;
		_CurrencyCode = CurrencyCode;
		_CurrencyContry = CurrencyContry;
		_CurrencyRate = CurrencyRate;
	}

	// Setters 

	void UpdateCurrencyRate(float Rate)
	{
		_CurrencyRate = Rate;
		_Update();
	}

	// Getters

	float CurrencyRate() const
	{
		return _CurrencyRate;
	}

	string CurrencyName() const
	{
		return _CurrencyName;
	}

	string CurrencyCode() const
	{
		return _CurrencyCode;
	}

	string CurrencyContry() const
	{
		return _CurrencyContry;
	}

	bool IsEmpty()
	{
		return (_Mode == _enMode::_eEmptyMode);
	}

	float ConvertCurrencyToUSD(float Amount)
	{
		return Amount / this->CurrencyRate();
	}

	float ConvertUSDToCurrency(float USDAmount)
	{
		return this->CurrencyRate()* USDAmount;
	}

	static clsCurrency FinByCurrencyCountry(string CurrencyCountry)
	{
		CurrencyCountry = clsString::UpperAllString(CurrencyCountry);

		fstream File;
		string Line;

		File.open("Currencies.txt", ios::in); // ReadMode

		if (File.is_open())
		{
			while (getline(File, Line))
			{
				if (Line != "")
				{
					clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

					if (clsString::UpperAllString(Currency.CurrencyContry()) == CurrencyCountry)
					{
						return Currency;
					}
				}
			}
			File.close();
			return _GetEmptyObject();
		}
	}

	static clsCurrency FinByCurrencyCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream File;
		string Line;

		File.open("Currencies.txt", ios::in); // ReadMode

		if (File.is_open())
		{
			while (getline(File, Line))
			{
				if (Line != "")
				{
					clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

					if (Currency.CurrencyCode() == CurrencyCode)
					{
						return Currency;
					}
				}
			}
			File.close();
			return _GetEmptyObject();
		}
	}

	static bool isCurrencyExists(string CurrencyCode)
	{
		clsCurrency Currency = FinByCurrencyCode(CurrencyCode);

		return (!Currency.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
		return vCurrencies;
	}


};

