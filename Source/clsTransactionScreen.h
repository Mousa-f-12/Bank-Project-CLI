#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"


;class clsTransactionScreen : protected clsScreen
{
private:

    enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowTransfer = 4 , eShowTransferLog = 5 , eShowMainMenue = 6 };

    static short _ReadTransactionsMenueOption()
    {
        cout << "\t\t\t\t   Choose what do you want to do? [1 to 4]? ";
        short Choice = 0;
        cin >> Choice;

        return Choice;
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\n\nPress Any Button To Go Back To Main Menu...\n";
        system("pause > 0");
        system("Color 07");
        system("cls");
        ShowTransactionScreen();
    }

    static  void _ShowDepositScreen()
    {
        //cout << "Deposti Screen Will Be Here We Are Working On It.";

        clsDepositScreen::DepositScreen();
    }

    static  void _ShowWithDrawScreen()
    {
        //cout << "WithDraw Screen Will Be Here We Are Working On It.";
        clsWithdrawScreen::WithdrawScreen();
    }

    static  void _ShowTotalBalancesScreen()
    {
        //cout << "Total Balances Screen Will Be Here We Are Working On It.";
        clsTotalBalancesScreen::GetTotalBalances();
    }

    static  void _ShowTransferScreen()
    {
        //cout << "Total Balances Screen Will Be Here We Are Working On It.";
        clsTransferScreen::TransferScreen();
    }

    static  void _ShowTransferLogScreen()
    {
        //cout << "Total Balances Screen Will Be Here We Are Working On It.";
        clsTransferLogScreen::TransferLogScreen();
    }

    static void _PerfromeTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {

        }
        }
    }

public:

	static void ShowTransactionScreen()
	{
        if (!CheckAccessRights(clsUser::Transactions))
        {
            return;
        }

        _DrawScreenHeader("Transactions Screen");
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\tMain Menue Screen\n";
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t[1] Deposit.\n";
        cout << "\t\t\t\t\t\t[2] Withdraw.\n";
        cout << "\t\t\t\t\t\t[3] Total Balances.\n";
        cout << "\t\t\t\t\t\t[4] Transfer.\n";
        cout << "\t\t\t\t\t\t[5] Transfer Log.\n";
        cout << "\t\t\t\t\t\t[6] Main Menue.\n";
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t===============================================\n\n";
        _PerfromeTranactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());

	}

};

