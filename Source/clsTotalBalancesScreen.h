#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtils.h"
#include <iomanip>

class clsTotalBalancesScreen : protected clsScreen
{

private:

	static void _PrintShortClientRecordLine(clsBankClient Client)
	{
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void GetTotalBalances()
	{
		_DrawScreenHeader("Total Balances Screen");

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		for (int i = 0; i < vClients.size(); i++)
		{
			_PrintShortClientRecordLine(vClients[i]);
			cout << endl;
		}

		double TotalBalances = clsBankClient::GetTotalBalances();

		cout << "\n\n\t Total Balances is : " << TotalBalances << endl;
		cout << "(" << clsUtils::ConvertNumberToText(TotalBalances) << ")\n";

	}
};

