#pragma once
#include "../course-10/clsDate.h"
#include "clsUser.h"
#include "clsUtils.h"
#include <chrono>
#include <ctime>
#include <fstream>



class clsLoginRegister
{

private:

	static string _GetNowTime()
	{
		auto now = chrono::system_clock::now();

		time_t currentTime = chrono::system_clock::to_time_t(now);

		string CrrTime = ctime(&currentTime);

		CrrTime.erase(CrrTime.end() - 1);

		return CrrTime;
	}

	static string _ConvertUserLoginRecordLine(clsUser &CurrentUser, string Separator = "#//#")
	{
		string DateLine = "";

		DateLine += _GetNowTime() + Separator;
		DateLine += CurrentUser.UserName + Separator;
		DateLine += clsUtils::EncryptedText(CurrentUser.Password, 5) + Separator;
		DateLine += to_string(CurrentUser.Permissions);

		return DateLine;
	}

	static void _SaveUserLoginRecordLineToFile(clsUser &CurrentUser)
	{
		fstream File;

		string DataLine = _ConvertUserLoginRecordLine(CurrentUser);

		File.open("D:\\notat\\RegisterLog.txt", ios::out | ios::app); // append mode

		if (File.is_open())
		{
			File << DataLine << endl;
		}
		File.close();
	}


public:

	static void RegisterLogin(clsUser& CurrentUser)
	{
		_SaveUserLoginRecordLineToFile(CurrentUser);
	}
};

