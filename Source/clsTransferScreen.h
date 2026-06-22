#pragma once

#include "clsScreen.h"
#include "clsUser.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iostream>
#include "clsTransferLog.h"


class clsTransferScreen : protected clsScreen
{

private:

	static void _PrintShortClientInfo(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient LoadAndValidateClient(string Message)
	{
		string AccountNumber = clsInputValidate::ReadString(Message);

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			AccountNumber = clsInputValidate::ReadString("Client Not Exists, Try Another one : ");
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return Client;
	}

	static bool _ConfirmTransaction()
	{
		char Answer;
		Answer = clsInputValidate::ReadChar("Are You Sure To Conferm This Transactoin [y/n] : ");
		return(Answer == 'y' || Answer == 'Y');
	}

	static double ReadAmount(clsBankClient Client)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadIntNumber<double>();

		while (Amount > Client.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadIntNumber<double>();
		}
		return Amount;

	}

public:

	static void TransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		clsBankClient SourceClient = LoadAndValidateClient("Enter Account Number Wanna Transfer From : ");

		_PrintShortClientInfo(SourceClient);

		clsBankClient DestinationClient = LoadAndValidateClient("Enter Account Number Wanna Transfer To : ");

		_PrintShortClientInfo(DestinationClient);

		double Amount = ReadAmount(SourceClient);


		if (_ConfirmTransaction())
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				_PrintShortClientInfo(SourceClient);

				_PrintShortClientInfo(DestinationClient);
			}
			else
			{
				cout << "\nTransfer Faild Amount Exeeds Balance\n";
			}		
			return;
		}
		
		cout << "\nOperation Cancelled\n";
	}

};

