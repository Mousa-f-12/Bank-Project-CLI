#pragma once

#include <fstream>
#include <iomanip>
#include <vector>

#include "clsBankClient.h"
#include "clsScreen.h"
#include "../course-10/clsString.h"

class clsTransferLogScreen : protected clsScreen
{


private:    
        
	static void _PrintTransferLogRow(clsBankClient::stTransferLogInfo& Info)
	{
		cout << "\t| " << setw(22) << left << Info.DateTime;
		cout << "| " << setw(12) << left << Info.SourceAccNumber;
		cout << "| " << setw(12) << left << Info.DestinationAccNumber;
		cout << "| " << setw(10) << left << Info.Amount;
		cout << "| " << setw(10) << left << Info.SourceAccbalance;
		cout << "| " << setw(10) << left << Info.DestinationAccbalance;
		cout << "| " << setw(12) << left << Info.UserName;
		cout << "|\n";
	}

public:

    static void TransferLogScreen()
    {
        _DrawScreenHeader("Transfer Log Screen");

        vector<clsBankClient::stTransferLogInfo> vTransferLogInfo =
            clsBankClient::LoadLoadTransferRecordFromFile();

        const string line =
            "\t-----------------------------------------------------------------------------------------------\n";

        cout << "\n\tTransfer Log List (" << vTransferLogInfo.size() << " records)\n\n";

        cout << line;

        cout << "\t| " << setw(22) << left << "Date/Time"
            << "| " << setw(12) << left << "S.Acc"
            << "| " << setw(12) << left << "D.Acc"
            << "| " << setw(10) << left << "Amount"
            << "| " << setw(10) << left << "S.Balance"
            << "| " << setw(10) << left << "D.Balance"
            << "| " << setw(12) << left << "User"
            << "|\n";

        cout << line;

        for (auto& Info : vTransferLogInfo)
        {
            _PrintTransferLogRow(Info);
        }

        cout << line;
    }


};

