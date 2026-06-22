#pragma once

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"


// Add new User

// 1 - check if user exists 
// 2 - get empty User
// 3 - get empty User by ref
// 4 - save User to users and make the mode update mode


class clsAddNewUserScreen : protected clsScreen
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

public:

	static void AddNewUserScreen()
	{

		_DrawScreenHeader("Add New User Screen");

		string UserName = clsInputValidate::ReadString("Enter New UserNam : ");

		while (clsUser::IsUserExist(UserName))
		{
			UserName = clsInputValidate::ReadString("UserName Allrady Exists, Enter Another One : ");
		}

		clsUser User = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(User);

		clsUser::enSaveResults ResultSave =  User.Save();

		switch (ResultSave)
		{
		case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "Invalid, Empty User Sorry, Try Again\n";
			}

		case clsUser::enSaveResults::svFaildUserExists:
			{
				cout << "Invalid, User Allrady Exists, Try Again\n";
			}

			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "Successfuly Added\n";
			}
		}
	}


};

