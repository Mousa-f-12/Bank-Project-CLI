#pragma once

#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsLoginRegister.h"



class clsShowLoginScreen : protected clsScreen
{



public:

	static bool ShowLoginScreen()
	{

		_DrawScreenHeader("Login Screen");

		bool LoginFlag = false;
		short FaildCounter = 3;

		do
		{
			if (LoginFlag)
			{
				if (FaildCounter == 1)
				{
					cout << "\nYou Are Locked";
					return false;
				}
				FaildCounter--;
				cout << "\nInvalid Password/UserName, Try Again\n";
				cout << "\nYou Have More " << FaildCounter << " Tries\n";
			}

			string UserName = clsInputValidate::ReadString("\nEnter User Name : ");
			string Password = clsInputValidate::ReadString("\nEnter Password  : ");


			clsUser User = clsUser::Find(UserName, Password);

			LoginFlag = User.IsEmpty();

			CurrentUser = User;

			

		} while (LoginFlag);
		
		
		system("cls");

		clsLoginRegister::RegisterLogin(CurrentUser);

		clsMainScreen::ShowMainMenuScreen();

		return true;
	}


};

