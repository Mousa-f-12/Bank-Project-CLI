#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include <vector>
#include  "../course-10/clsDate.h"


class clsInputValidate
{
private:

	static void _CleanUpCin()
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

public:

	template<typename NumberType> static bool IsNumberBetween(NumberType Number, NumberType From, NumberType To, bool IncludeFromAndTo = true)
	{
		return (IncludeFromAndTo) ? (Number >= From && Number <= To) : (Number > From && Number < To);
	}

	static bool IsDateBetween(const clsDate &Date, clsDate &From, clsDate &To)
	{
		if (!From.IsDateBeforeDate2(To))
			clsDate::SwapDates(From, To);
		return (From.IsDateBeforeDate2(Date) && To.IsDateAfterDate2(Date));
	};

	template<typename NumberType> static NumberType ReadIntNumber(string InputMessage = "Enter Int Number : ", string ErrorMessage = "Invalid Number, Try Again : ")
	{
		NumberType Number = 0;

		cout << InputMessage;
		cin >> Number;

		while (cin.fail())
		{
			_CleanUpCin();

			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	};

	static string ReadString(string InputMessage = "Enter String : ")
	{
		string str = "";

		cout << InputMessage;
		getline(cin >> ws, str);
		return str;
	};

	static char ReadChar(string InputMessage = "Enter Char : ")
	{
		char C;
		cout << InputMessage;
		cin >> C;
		return C;
	};

	template<typename NumberType> static int ReadIntNumberBetween(NumberType From, NumberType To,
		string ErrorMessage = "Invalid, Enter Number Between ", bool IncludeFromAndTo = true)
	{
		NumberType Number = ReadIntNumber<int>("Enter Number Between [" + to_string(From) + " - " + to_string(To) + "] : ");

		string Message = ErrorMessage + " [" + to_string(From) + " And " + to_string(To) + "] : ";

		while (!(IsNumberBetween(Number, From, To, IncludeFromAndTo)))
		{
			Number = ReadIntNumber<int>(Message);
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
		
};

