#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#include <iomanip>

class clsUpdateClientScreen : clsScreen
{

private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		Client.FirstName = clsInputValidate::ReadString("Enter First Name: ");
		Client.LastName = clsInputValidate::ReadString("Enter Last Name: ");
		Client.Email = clsInputValidate::ReadString("Enter Email: ");
		Client.Phone = clsInputValidate::ReadString("Enter Phone: ");
		Client.PinCode = clsInputValidate::ReadString("Enter PinCode: ");
		Client.AccountBalance = clsInputValidate::ReadIntNumber<double>("Enter Balance: ");
	}

	static bool _ShowUpdateMessage()
	{
		char Answer;
		cout << "\nAre You Sure Wanna Update This Client? [y/n] : ";
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

	static void UpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::UpdateClient))
		{
			return;
		}

		_DrawScreenHeader("Update Client Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			AccountNumber = clsInputValidate::ReadString("Client Not Exists, Try Again: ");
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		if (_ShowUpdateMessage())
		{
			_ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResult = Client.Save();
			
			switch (SaveResult)
			{
				case clsBankClient::enSaveResults::svSucceeded:
				{
					system("cls");
					system("Color 2F");
					cout << "\nClient Updated Successfuly\n\n---------\n\nNew Client...";
					_PrintClient(Client);
					break;
				}

				case clsBankClient::enSaveResults::svFaildEmptyObject:
				{
					system("cls");
					system("Color 4F");
					cout << "\nError\n";
					break;
				}
			}
		}
	}
};

