#pragma once
#include <iostream>
#include "Global.h"
#include "../course-10/clsDate.h"

using namespace std;

class clsScreen
{ 

protected:

	static void _DrawScreenHeader(string Title, string Subtitle = "")
	{
		cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t\t" << Title;
		if (Subtitle != "")
			cout << "\n \t\t\t\t\t\t" << Subtitle;
		cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

		clsDate Date;
		cout << "\t\t\t" + to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
			
		if (!CurrentUser.IsEmpty())
			cout << "\t\t\t\t\t\t UserName : " << CurrentUser.UserName << endl;
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (CurrentUser.CheckAccessPermission(Permission))
		{
			return true;
		}
		else
		{
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\t\t\t" << "Access Denied! Contact Your Admin";
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
			return false;
		}
	}

};

