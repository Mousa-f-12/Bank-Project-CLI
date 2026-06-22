#pragma once

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"	



class clsUpdateUserScreen : protected clsScreen
{

private:

	static short _ReadPermissions()
	{
		short Permissions = 0;
		char Answer;

		cout << "\nDid You Wanna Give Him ";
		Answer = clsInputValidate::ReadChar("Full Access : [y / n] \n");

		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		Answer = clsInputValidate::ReadChar("Access To Client List : [y / n] \n");

		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::ClientList;
		}

		Answer = clsInputValidate::ReadChar("Access To AddClient : [y / n] \n");

		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::AddClient;
		}

		Answer = clsInputValidate::ReadChar("Access To Delete Client : [y / n] \n");

		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::DeleteClient;
		}

		Answer = clsInputValidate::ReadChar("Access To Update Client : [y / n] \n");

		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::UpdateClient;
		}

		Answer = clsInputValidate::ReadChar("Access To Transactions Screen : [y / n] \n");

		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::Transactions;
		}

		Answer = clsInputValidate::ReadChar("Access To Manage Users Screen : [y / n] \n");

		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::ManageUsers;
		}


		Answer = clsInputValidate::ReadChar("Access To Register Log : [y / n] \n");

		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::RegisterLog;
		}

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		User.FirstName = clsInputValidate::ReadString("Enter First Name: ");
		User.LastName = clsInputValidate::ReadString("Enter Last Name: ");
		User.Email = clsInputValidate::ReadString("Enter Email: ");
		User.Phone = clsInputValidate::ReadString("Enter Phone: ");
		User.Password = clsInputValidate::ReadString("Enter Password: ");
		User.Permissions = _ReadPermissions();

	}

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

	static bool _ShowUpdateMessage()
	{
		char Answer;
		cout << "\nAre You Sure Wanna Update This User? [y/n]";
		cin >> Answer;

		return (Answer == 'Y' || Answer == 'y');
	}

public:

	static void UpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");

		string UserName = clsInputValidate::ReadString("Enter User Name : ");

		while (!clsUser::IsUserExist(UserName))
		{
			UserName = clsInputValidate::ReadString("User Not Exists, Try Again : ");
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		if (_ShowUpdateMessage())
		{
			_ReadUserInfo(User);

			clsUser::enSaveResults ResultSave = User.Save();

			switch (ResultSave)
			{
			case clsUser::enSaveResults::svFaildEmptyObject:
			{

				cout << "\nFaild To Update User Is Empty\n";
			}

			case clsUser::enSaveResults::svSucceeded:
			{

				cout << "\nSuccessfuly Updated\n";
			}
			}
		}
		else
		{
			cout << "\nOperation Calncelled\n";
		}
	}

};

