#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

    enum enManageUsersMenuOptions { eUsersList = 1, eAddUSer = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eBackToMainMeue = 6 };

    static short _ReadManageMenuOption()
    {
        short Choice;

        cout << "\t\t\t\t\tChoose From [1 to 6] : ";
        cin >> Choice;

        return Choice;
    }

    static void _GoBackToManageMenue()
    {
        cout << "\n\n\nPress Any Button To Go Back To Main Menu...\n";
        system("Color 07");
        system("pause > 0");
        system("cls");
        ShowManageMenu();

    }

    static void _ShowUsersListScreen()
    {
        //cout << "We are working on this screen right now it will take some time";
        clsUsersListScreen::ShowUsersListScreen();
    }

    static void _ShowAddUsersScreen()
    {
        //cout << "We are working on this screen right now it will take some time";
        clsAddNewUserScreen::AddNewUserScreen();
    }

    static  void _ShowDeleteUserScreen()
    {
        //cout << "We are working on this screen right now it will take some time";
        clsDeleteUserScreen::DeleteUserScreen();
    }

    static  void _ShowUpdateUserScreen()
    {
        //cout << "We are working on this screen right now it will take some time";
        clsUpdateUserScreen::UpdateUserScreen();
    }

    static  void _FindUserScreen()
    {
        //cout << "We are working on this screen right now it will take some time";
        clsFindUserScreen::FindUserScreen();
    }

    static  void _PreformManageMenuOption(enManageUsersMenuOptions Choice)
    {
        switch (Choice)
        {
        case enManageUsersMenuOptions::eUsersList:
            system("cls");
            _ShowUsersListScreen();
            _GoBackToManageMenue();
            break;

        case enManageUsersMenuOptions::eAddUSer:
            system("cls");
            _ShowAddUsersScreen();
            _GoBackToManageMenue();
            break;

        case enManageUsersMenuOptions::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageMenue();
            break;

        case enManageUsersMenuOptions::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageMenue();
            break;

        case enManageUsersMenuOptions::eFindUser:
            system("cls");
            _FindUserScreen();
            _GoBackToManageMenue();
            break;

        case enManageUsersMenuOptions::eBackToMainMeue:
        {
            system("cls");
        }
            break;

        default:
            break;
        }
    }

	
public:

    static  void ShowManageMenu()
    {
        if (!CheckAccessRights(clsUser::ManageUsers))
        {
            return;
        }

        _DrawScreenHeader("Manage Users Screen");
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t[1] List Users.\n";
        cout << "\t\t\t\t\t\t[2] Add User.\n";
        cout << "\t\t\t\t\t\t[3] Delete User.\n";
        cout << "\t\t\t\t\t\t[4] Update User.\n";
        cout << "\t\t\t\t\t\t[5] Find User.\n";
        cout << "\t\t\t\t\t\t[6] MainMenu.\n";
        cout << "\t\t\t\t===============================================\n";
        cout << "\t\t\t\t===============================================\n";

        _PreformManageMenuOption(enManageUsersMenuOptions(_ReadManageMenuOption()));
    }


};

