#pragma once

#include <fstream>
#include <iomanip>
#include <vector>

#include "clsUser.h"
#include "clsScreen.h"
#include "../course-10/clsString.h"



class clsRegisterLogScreen : protected clsScreen
{
	
private:

	static void _PrintRegisterLog(clsUser::stLoginRegisterRecord& Info)
	{
		cout << "\t\t| " << setw(30) << left << Info.DateTime;
		cout << "| " << setw(20) << left << Info.UserName;
		cout << "| " << setw(15) << left << Info.Password;
		cout << "| " << setw(6) << left << Info.Permissions << "|";
		cout << endl;
		cout << "\t\t__________________________________________________________________________\n";
		
	}

public:

	static void PrintRegisterLogScreen()
	{

		_DrawScreenHeader("Transfer Log Screen");

		vector<clsUser::stLoginRegisterRecord> vRegisterLogInfo = clsUser::LoadRegisterRecordFromFile();

		cout << "\n\n\t\t\t\t\t  Register Log List ("
			<< vRegisterLogInfo.size() << ") User(s).\n";

		cout << "\t\t________________________________________________________";
		cout << "________________________________________\n" << endl;

		cout << "\t\t| " << setw(30) << left << "Date/Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(15) << left << "Password";
		cout << "| " << setw(6) << left << "Permissions |";
		cout << endl;

		cout << "\t\t________________________________________________________";
		cout << "________________________________________\n" << endl;

		for (clsUser::stLoginRegisterRecord& Info : vRegisterLogInfo)
		{
			_PrintRegisterLog(Info);
		}
	}

};

