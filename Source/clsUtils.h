#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class clsUtils
{

private:

	enum enPerfect { Perfect = 1, NotPerfect = 2 };

	enum EnRandomGenerateType { Digit = 1, SpecialChar = 2, LowerLetter = 3, UpperLetter = 4, Mix = 5 };

	enum enPrime { Prime = 1, NotPrime = 2 };

	static EnRandomGenerateType ReadRandomSymbol()
	{
		int Number;

		cout << "[1] Number\n"
			<< "[2] SpecialChar\n"
			<< "[3] LowerLetter\n"
			<< "[4] UpperLetter\n"
		    << "[5] Mix\n\n";
		cout << "Choose from 1 to 5 : ";
		cin >> Number;

		return(EnRandomGenerateType)Number;
	}

public:

	static enPrime CheckPrime(int Number)
	{
		if (Number == 1) return enPrime::NotPrime;

		if (Number == 2) return enPrime::Prime;

		for (int i = 2; i <= Number / 2; i++)
		{
			if (Number % i == 0)
			{
				return enPrime::NotPrime;
			}
		}
		return enPrime::Prime;
	}

	static void SrandSeed()
	{
		srand(time(0));
	}

	static int ReadNumber(string Message)
	{
		int Number;

		cout << Message;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

			cout << "Enter Valid Number: ";
			cin >> Number;
		}

		return Number;

	}

	static int ReadPositiveNumber(string Message)
	{
		int Number;
		do
		{
			Number = ReadNumber(Message);
		} while (Number < 1);

		return Number;
	}

	static double ReadPositiveDoubleNumber(string Message)
	{
		double Number;
		do
		{
			Number = ReadNumber(Message);
		} while (Number < 1);

		return Number;
	}

	static int ReadNumberUntilNo(int Number)
	{
		char Again = 'y';

		do {

			int Number = ReadPositiveNumber("Enter a Number: ");


			cout << "Want To Add Another Number Y/N : ";
			cin >> Again;
		} while (Again == 'Y' || Again == 'y');

		return Number;
	}

	static int ReadPositiveNumber(string Message, int NumberOfElement)
	{
		int Number;

		do
		{
			cout << Message << " " << NumberOfElement << "\n";
			cin >> Number;
		} while (Number < 1);

		return Number;
	}

	static int ReadNumberInRange(int Min, int Max)
	{
		int Number = 0;

		do
		{
			cout << "Enter Number Between " << Min << "-" << Max << " : ";
			cin >> Number;
		} while (!(Number >= Min && Number <= Max));

		return Number;
	}

	static bool IsPrime(int Number)
	{
		if (Number <= 1) return false;
		if (Number == 2) return true;
		if (Number % 2 == 0) return false;

		for (int i = 3; i <= round(sqrt(Number)); i = i + 2)
		{
			if (Number % i == 0) return false;
		}

		return true;
	}

	static enPerfect CheckPerfectNumber(int Number)
	{
		int Sum = 0;
		for (int i = 1; i <= round(Number / 2); i++)
		{
			if (Number % i == 0)
			{
				Sum += i;
			}
		}
		if (Sum == Number)
			return enPerfect::Perfect;

		return enPerfect::NotPerfect;
	}

	static int ReverseNumber(int Number)
	{
		int Remainder = 0, Number2 = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}
		return Number2;
	}

	static int CountNumberFrequency(int Number, int Target)
	{
		int Frequency = 0, Remainder = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			if (Target == Remainder)
			{
				Frequency += 1;
			}
			Number = Number / 10;
		}
		return Frequency;
	}

	static int LetterPatern()
	{
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					cout << char(i)
						<< char(j)
						<< char(k);
					cout << "\n";
				}
			}




		}



		return 0;
	}

	static bool CheckPassword(string Password, string Word)
	{
		return Password == Word;
	}

	static string EncryptedText(string Text, int Key)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + Key);
		}
		return Text;
	}

	static int GenerateRandomNumberFromTo(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	static void RandomNumberFromTo()
	{
		int Times = ReadPositiveNumber("how many Random Numbers you want: ");
		int From = ReadPositiveNumber("Generate From: ");
		int To = ReadPositiveNumber("Generate To: ");

		for (int i = 1; i <= Times; i++)
		{
			cout << GenerateRandomNumberFromTo(From, To) << "\n";
		}
	}

	static char GetRandomCharacter(EnRandomGenerateType Input)
	{
		switch (Input)
		{
		case EnRandomGenerateType::Digit:
			return (char)(rand() % (57 - 48 + 1) + 48);
		case EnRandomGenerateType::LowerLetter:
			return (char)(rand() % (122 - 97 + 1) + 97);
		case EnRandomGenerateType::UpperLetter:
			return (char)(rand() % (90 - 65 + 1) + 65);
		case EnRandomGenerateType::SpecialChar:
			return (char)(rand() % (47 - 33 + 1) + 33);
		case EnRandomGenerateType::Mix:
			return GetRandomCharacter(EnRandomGenerateType(GenerateRandomNumberFromTo(1, 4)));
		default:
			return ' ';
		}
	}

	static char GetRandomCharacter()
	{
		return GetRandomCharacter(ReadRandomSymbol());
	}

	static string GenerateWord(EnRandomGenerateType CharType, int length)
	{
		string Word;

		for (int j = 1; j <= length; j++)
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey(EnRandomGenerateType CharType)
	{
		string Key = "";

		for (int i = 1; i <= 4; i++)
		{
			Key += GenerateWord(CharType, 4);

			if (i < 4)
			{
				Key += "-";
			}
		}
		return Key;
	}

	static string PrintNumberFrommat(int i)
	{
		if (i <= 9)
		{
			return "0" + to_string(i);
		}
		else
		{
			return to_string(i);
		}
	}

	static void GenerateKeys(EnRandomGenerateType CharType)
	{
		int KeysNumber = ReadPositiveNumber("Enter How Many Keys: ");
		for (int i = 1; i <= KeysNumber; i++)
		{
			cout << "key [" << PrintNumberFrommat(i) << "] " << GenerateKey(CharType) << "\n";
		}
	}

	static void ReadAarry(vector <int>& Arr, int ArrLenght)
	{
		int Item;

		for (int i = 0; i < ArrLenght; i++)
		{
			cout << "Enter Item Number [" + to_string(i + 1) + "] : ";
			cin >> Item;

			Arr.push_back(Item);
		}
	}

	static void FillAarryWithRandomNumbers(vector <int>& Arr, int ArrLenght)
	{
		for (int i = 0; i < ArrLenght; i++)
		{	
			Arr.push_back(GenerateRandomNumberFromTo(1, 100)) ;
		}
	}

	static void FillAarryWithOrderdNumbers(vector <int> &Arr, int ArrLenght)
	{
		for (int i = 0; i < ArrLenght; i++)
		{
			Arr.push_back(i + 1);
		}
	}

	static int NumberFrequncyInArray(vector <int>& Arr, int Target)
	{
		int Counter = 0;

		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] == Target)
			{
				Counter++;
			}
		}
		return Counter;
	}

	static int MaxNumberArray(vector <int>& Arr)
	{
		int MaxNumber = 0;

		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] > MaxNumber)
			{
				MaxNumber = Arr[i];
			}
		}
		return MaxNumber;
	}

	static int MinNumberArray(vector <int>& Arr)
	{
		int MinNumber = Arr[0];

		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] < MinNumber)
			{
				MinNumber = Arr[i];
			}
		}
		return MinNumber;
	}

	static int SumNumbersArray(vector <int>& Arr)
	{
		int Sum = 0;

		for (int i = 0; i < Arr.size(); i++)
		{
			Sum += Arr[i];
		}
		return Sum;
	}

	static float AvrageNumbersArray(vector <int>& Arr)
	{
		return  (float)SumNumbersArray(Arr) / Arr.size();
	}

	static void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static vector <int> SumTwoArrs(vector <int>& Arr1, vector <int>& Arr2)
	{
		vector <int> Arr3;
		int Length = 0;

		Length = (Arr1.size() < Arr2.size()) ? Arr1.size() : Arr2.size();
		
		for (int i = 0; i < Length; i++)
		{
			Arr3.push_back(Arr1[i] + Arr2[i]);
		}

		return Arr3;
	}

	static void ArrayShuffle(vector <int>& Arr)
	{
		for (int i = 0; i < Arr.size(); i++)
		{
			Swap(Arr[GenerateRandomNumberFromTo(1, Arr.size() - 1)], Arr[GenerateRandomNumberFromTo(1, Arr.size() - 1)]);
		}
	}

	static vector <int> ArrayReverse(vector <int>& Arr)
	{
		vector <int> ReversedArray;

		for (int i = 0; i < Arr.size(); i++)
		{
			ReversedArray.push_back(Arr[Arr.size() - 1 - i]);
		}
		return ReversedArray;
	}

	static void FillAarryWithRandomKeys(vector <string>& Arr, int ArrLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			string Key = GenerateKey(EnRandomGenerateType::UpperLetter);

			Arr.push_back(Key);
		}
	}

	static int FindNumberPosition(vector <int>& Arr, int Target)
	{
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] == Target)
			{
				return i;
			}
		}
		return -1;
	}

	static void AddElementArray(int Number, vector <int>& Arr)
	{
		Arr.push_back(Number);
	}

	static void CopyArray(vector <int>& Arr, vector <int>& Arr2)
	{
		for (int i = 0; i < Arr.size(); i++)
		{
			AddElementArray(Arr[i], Arr2);
		}
	}

	static bool IsNumberInArray(vector <int>& Arr, int Number)
	{
		return FindNumberPosition(Arr, Number) != -1;
	}

	static void CopyDisticNumberToArray(vector <int>& Arr1, vector <int>& Arr2)
	{
		for (int i = 0; i < Arr1.size(); i++)
		{
			if (!IsNumberInArray(Arr2, Arr1[i]))
			{
				AddElementArray(Arr1[i], Arr2);
			}
		}
	}

	static int IsOddNumberInArray(vector <int>& Arr, int ReadTimes)
	{
		int Counter = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] % 2 != 0)
			{
				Counter++;
			}

		}
		return Counter;
	}

	static int CountPositive(vector <int>& Arr)
	{
		int Counter = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] >= 0)
			{
				Counter++;
			}

		}
		return Counter;
	}

	static bool IsPalendromeArray(vector <int>& Arr)
	{
		for (int i = 0; i < Arr.size() / 2; i++)
		{
			if (Arr[i] != Arr[Arr.size() - 1 - i])
			{
				return false;
			}
		}
		return true;
	}

	static float Abs(float Num)
	{
		if (Num < 0)
		{
			return Num * -1;
		}

		return Num;
	}

	static float GetNumberFraction(float Number)
	{
		return Number - (int)Number;
	}

	static int MyRound(float Number)
	{
		int IntPart = (int)Number;
		float Fraction = GetNumberFraction(Number);

		if (Abs(Fraction) >= 0.5)
		{
			if (Number >= 0) return IntPart + 1;
			else
			{
				return IntPart - 1;
			}
		}
		return IntPart;
	}

	static int MyFloor(float Number)
	{
		if (Number >= 0) return (int)Number;
		return (int)Number - 1;
	}

	static int MyCeil(float Number)
	{
		float Fraction = GetNumberFraction(Number);

		if (Fraction > 0)
		{
			if (Number > 0)
			{
				return (int)Number + 1;
			}
			else
			{
				return Number;
			}
		}
		return Number;
	}

	static float MySqrt(float Number)
	{
		return pow(Number, .5);
	}

	static void CopyPrimeNumbersToArray(vector <int>& Arr, vector <int>& Arr2)
	{
		int Counter = 0;

		for (int i = 0; i < Arr.size(); i++)
		{
			if (CheckPrime(Arr[i]) == enPrime::Prime)
			{
				Arr2[Counter] = Arr[i];
				Counter++;
			}
		}
	}

	static void PrintArray(vector <int>& Arr)
	{
		for (int &A : Arr)
		{
			cout << A << "  ";
		}
	}

	static string ConvertNumberToText(int Number)
	{

		if (Number == 0) { return ""; }

		if (Number >= 1 && Number <= 19)
		{
			string Numbers[20] = {
				"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
				"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
				"Seventeen", "Eighteen", "Nineteen" };

			return Numbers[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string Tens[10] = {
				"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

			return Tens[Number / 10] + " " + ConvertNumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Handred " + ConvertNumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return ConvertNumberToText(Number / 100) + "Hundred " + ConvertNumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + ConvertNumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return ConvertNumberToText(Number / 1000) + "Thousand " + ConvertNumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + ConvertNumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return ConvertNumberToText(Number / 1000000) + "Millions " + ConvertNumberToText(Number % 1000000);
		}

		return "This Is Too Big Number";

	}

};
