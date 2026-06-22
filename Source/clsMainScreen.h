#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsAddClientScreen.h"
#include "clsClientsListScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsFindClientScreen.h"
#include "clsManageUsersScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsRegisterLogScreen.h"
#include "clsCurrencyExchangeMenuScreen.h"


class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2,
        eDeleteClient = 3,eUpdateClient = 4,
        eFindClient = 5,eShowTransactionsMenue = 6,
        eManageUsers = 7, eRegisterLog = 8,
        eCurrencyExchange = 9, eLogout = 10
    };

    static void _GoBackToMainMenu()
    {
        cout << "\n\n\nPress Any Button To Go Back To Main Menu...\n";
        system("Color 07");
        system("pause > 0");
        system("cls");
        ShowMainMenuScreen();
    }

    static void _ShowAllClientScreen()
    {
        //cout << "Show All Client List Coming soon...";
        clsClientsList::GetClientsListScreen();
    }

    static void _ShowAddClientScreen()
    {
        //cout << "Add Client Feature Coming soon...";
        clsAddClient::AddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "Delete Client Feature Coming soon...";
        clsDeleteClientScreen::DeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "Update Client Feature Coming soon...";
        clsUpdateClientScreen::UpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        //cout << "Find Client Feature Coming soon...";
        clsFindClientScreen::FindClientScreen();
    }

    static void _ShowTransacionsScreen()
    {
        //cout << "Transaction Screen Coming soon...";
        clsTransactionScreen::ShowTransactionScreen();
    }

    static void _ShowManageUsersScreen()
    {
        //cout << "Manage Users Screen Coming soon...";
        clsManageUsersScreen::ShowManageMenu();
    }

    static void _ShowRegisterLogScreen()
    {
        clsRegisterLogScreen::PrintRegisterLogScreen();
    }

    static void _ShowCureencyExchangeMenuScreen()
    {
        //cout << "LogOut Screen Coming soon...";
        clsCurrencyExchangeMenuScreen::ShowCurrencyExchangeScreen();
    }

    static void _ShowLogOutScreen()
    {
        //cout << "LogOut Screen Coming soon...";

        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions Option)
    {
        switch (Option)
        {
            case enMainMenueOptions::eListClients:
            {
                system("cls");
                _ShowAllClientScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eAddNewClient:
            {
                system("cls");
                _ShowAddClientScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eDeleteClient:
            {
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eUpdateClient:
            {
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eFindClient:
            {
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eShowTransactionsMenue:
            {
                system("cls");
                _ShowTransacionsScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eManageUsers:
            {
                system("cls");
                _ShowManageUsersScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eRegisterLog:
            {
                system("cls");
                _ShowRegisterLogScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eCurrencyExchange:
            {
                system("cls");
                _ShowCureencyExchangeMenuScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::eLogout:
            {
                system("cls");
                _ShowLogOutScreen();
                break;
            }
        }
    }

public:

	static void ShowMainMenuScreen()
	{
        _DrawScreenHeader("Main Menue");
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t[1] Show Client List.\n";
        cout << "\t\t\t\t\t[2] Add New Client.\n";
        cout << "\t\t\t\t\t[3] Delete Client.\n";
        cout << "\t\t\t\t\t[4] Update Client Info.\n";
        cout << "\t\t\t\t\t[5] Find Client.\n";
        cout << "\t\t\t\t\t[6] Transactions.\n";
        cout << "\t\t\t\t\t[7] Manage Users.\n";
        cout << "\t\t\t\t\t[8] Register Log.\n";
        cout << "\t\t\t\t\t[9] Exchange Currency.\n";
        cout << "\t\t\t\t\t[10] LogOut.\n";
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t===============================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)clsInputValidate::ReadIntNumberBetween(1, 10, "\t\t\t\tEnter Number between", true));
	}
	
};

