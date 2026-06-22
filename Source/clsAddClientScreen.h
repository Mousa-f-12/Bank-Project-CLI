#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsFindClientScreen.h"

class clsAddClient : protected clsScreen
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

	static void _PrintClient(clsBankClient &Client)
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

	static void AddNewClientScreen() 
	{

		if (!CheckAccessRights(clsUser::AddClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("Add Client Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Account Number: ");

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			AccountNumber = clsInputValidate::ReadString("Client Alrady Exists, Try Another one : ");
		}

		clsBankClient Client = clsBankClient::GetAddNewClient(AccountNumber);

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult = Client.Save();

		switch (SaveResult)
		{
			case clsBankClient::enSaveResults::svSucceeded:
			{
				system("cls");
				system("Color 2F");
				cout << "\nClient Added Successfuly\n";
				_PrintClient(Client);
				break;
			}

			case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			{
				system("cls");
				system("Color 60");
				cout << "\nClient Alrady Exists\n";
				break;
			}
		}
	};
};

