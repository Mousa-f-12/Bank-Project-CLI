#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#include <iomanip>

class clsDeleteClientScreen : protected clsScreen
{

private:

	static bool _ShowDeleteMessage()
	{
		char Answer;
		cout << "\nAre You Sure Wanna Delete This Client? [y/n]";
		cin >> Answer;

		return (Answer == 'Y' || Answer == 'y');
	}

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
	
public:

	static void DeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::DeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			AccountNumber = clsInputValidate::ReadString("Client Not Exists, Try Again: ");
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		if (_ShowDeleteMessage()) {

			if (Client.Delete())
			{
				system("cls");
				system("Color 2F");
				cout << "\nClient Deleted Successfuly\n";
			}
			else
			{
				system("cls");
				cout << "Withdraw Succeed";
				system("Color 4F");
				cout << "\nClient Not Deleted\n";
			}
		}
	}

};

