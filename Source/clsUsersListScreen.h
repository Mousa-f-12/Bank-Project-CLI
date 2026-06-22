#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"


using namespace std;

class clsUsersListScreen : protected clsScreen
{

private:


public:

	static void ShowUsersListScreen()
	{
        _DrawScreenHeader("Users List Screen");

        vector<clsUser> vUsers = clsUser::GetUsersList();

        string line = "\t\t\t\t-----------------------------------------------";

        cout << "\n" << line << endl;

        cout << "\t\t\t\tUsers Count (" << vUsers.size() << ") User/s." << endl;

        cout << line << endl;

        // Header
        cout << "\t\t\t\t"
            << left << setw(15) << "UserName" << " | "
            << left << setw(12) << "Password" << " | "
            << left << setw(25) << "Permissions"
            << endl;

        cout << line << endl;

        // Rows
        for (clsUser& User : vUsers)
        {
            cout << "\t\t\t\t"
                << left << setw(15) << User.UserName << " | "
                << left << setw(12) << User.Password << " | "
                << left << setw(25) << User.Permissions
                << endl;
        }

        cout << line << endl;
	}

};

