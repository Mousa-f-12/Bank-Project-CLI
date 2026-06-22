#include <iostream>;
#include "clsUtils.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include "clsShowLoginScreen.h"
#include <iomanip>

using namespace std;




int main()
{
	while (true)
	{
		if(!clsShowLoginScreen::ShowLoginScreen()) break;
	}
	
}