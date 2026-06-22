#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtils.h"


class clsDepositScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.GetPinCode();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static bool _ConfirmTransaction()
	{
		char Answer;
		Answer = clsInputValidate::ReadChar("Are You Sure To Conferm This Transactoin [y/n] : ");
		return(Answer == 'y' || Answer == 'Y');
	}

public:

	static void DepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Account Number: ");

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			AccountNumber = clsInputValidate::ReadString("Client Doesn't Exists, Try Another one : ");
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		double Amount = clsUtils::ReadPositiveDoubleNumber("Enter Deposite Amount : ");

		if (_ConfirmTransaction())
		{
			Client.Deposit(Amount);
			_PrintClient(Client);

			system("cls");
			cout << "Withdraw Succeed";
			system("Color 2F");
		}
		else
		{
			system("cls");
			system("Color 60");
			cout << "\Operation Cancelled\n";
		}
	};
};