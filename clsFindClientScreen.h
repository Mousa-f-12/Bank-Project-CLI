#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"

class clsFindClientScreen : protected clsScreen
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

public:

	static void FindClientScreen()
	{
		if (!CheckAccessRights(clsUser::FindClient))
		{
			return;
		}

		_DrawScreenHeader("Find Client Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			AccountNumber = clsInputValidate::ReadString("Client Not Exists, Try Again : ");
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (Client.IsEmpty())
		{
			cout << "Client Not Found";
		}
		else
		{
			_PrintClient(Client);
		}

		
	}

};

	