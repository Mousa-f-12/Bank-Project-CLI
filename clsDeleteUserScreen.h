#pragma once

#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"


class clsDeleteUserScreen : protected clsScreen
{

private:

	static void _PrintUser(clsUser User)
	{
		cout << "\n______________________________________________\n";
		cout << "First Name  : " << User.FirstName << "\n";
		cout << "Last Name   : " << User.LastName << "\n";
		cout << "Full Name   : " << User.FullName() << "\n";
		cout << "Email       : " << User.Email << "\n";
		cout << "Phone       : " << User.Phone << "\n";
		cout << "Password    : " << User.Password << "\n";
		cout << "Permissions : " << User.Permissions << "\n";
		cout << "\n______________________________________________\n";
	}

	static bool _ShowDeleteMessage()
	{
		char Answer;
		cout << "\nAre You Sure Wanna Delete This User? [y/n]";
		cin >> Answer;

		return (Answer == 'Y' || Answer == 'y');
	}

public:

	static void DeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");

		string Username = clsInputValidate::ReadString("Enter Uesr Name : ");

		while (!clsUser::IsUserExist(Username))
		{
			Username = clsInputValidate::ReadString("User Not Exists, Try Again : ");
		}
		
		clsUser User = clsUser::Find(Username);

		_PrintUser(User);

		if (_ShowDeleteMessage())
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfuly\n";
			}
			else
			{
				cout << "\nError";
			}
			
		}
		else
		{
			cout << "\nOperation Cancelled";
		}

	}


};

