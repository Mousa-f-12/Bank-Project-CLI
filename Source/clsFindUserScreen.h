#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"




class clsFindUserScreen : protected clsScreen
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

public:

	static void FindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");

		string UserName = clsInputValidate::ReadString("Enter User Name : ");

		while (!clsUser::IsUserExist(UserName))
		{
			UserName = clsInputValidate::ReadString("User Not Exists, Try Again : ");
		}

		clsUser User = clsUser::Find(UserName);


		if (User.IsEmpty())
		{
			cout << "\nUser Not Found\n";
		}
		else
		{
			cout << "\nUser Found\n";
		}

		_PrintUser(User);
	}
};

