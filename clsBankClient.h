#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include <chrono>
#include "Global.h"
#include "clsUser.h"
#include "../course-10/clsString.h"

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _ConvetClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("D:\\notat\\Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {
                if (Line != "")
                {
                    clsBankClient Client = _ConvertLinetoClientObject(Line);

                    vClients.push_back(Client);
                }
                
            }

            MyFile.close();

        }

        return vClients;

    }

    void _SaveCleintsDataToFile(vector <clsBankClient>& vClients)
    {

        fstream MyFile;
        MyFile.open("D:\\notat\\Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if(C.MarkedForDelete() == false)
                {
                    DataLine = _ConvetClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddDataLineToFile(string  DataLine)
    {
        fstream MyFile;
        MyFile.open("D:\\notat\\Clients.txt", ios::out | ios::app); // Append mode

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();
        }

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvetClientObjectToLine(*this));
    }


    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _GetNowTime()
    {
        auto now = chrono::system_clock::now();

        time_t currentTime = chrono::system_clock::to_time_t(now);

        string CrrTime = ctime(&currentTime);

        CrrTime.erase(CrrTime.end() - 1);

        return CrrTime;
    }

    string _GetTransferRecordLine(clsBankClient& DestinationClient, double Amount, string Separator = "#//#")
    {
        string RecordLine = "";

        RecordLine += _GetNowTime() + Separator;
        RecordLine += this->AccountNumber() + Separator;
        RecordLine += DestinationClient.AccountNumber() + Separator;
        RecordLine += to_string(Amount) + Separator;
        RecordLine += to_string(this->AccountBalance) + Separator;
        RecordLine += to_string(DestinationClient.AccountBalance) + Separator;
        RecordLine += CurrentUser.UserName;
         
        return RecordLine;
    }

    void _SaveTransferRecordLineToFile(clsBankClient& DestinationClient, double Amount)
    {
        string DataLine = _GetTransferRecordLine(DestinationClient, Amount);

        fstream File;

        File.open("TransferLog.txt", ios::out | ios::app); // append mode
        if (File.is_open())
        {
            File << DataLine << endl;
        }
        File.close();
    }

public:

    struct stTransferLogInfo
    {
        string DateTime;
        string SourceAccNumber;
        string DestinationAccNumber;
        double Amount;
        double SourceAccbalance;
        double DestinationAccbalance;
        string UserName;

    
    };

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    bool MarkedForDelete()
    {
        return _MarkedForDelete;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;

        MyFile.open("D:\\notat\\Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("D:\\notat\\Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
            case enMode::EmptyMode:
            {
                return enSaveResults::svFaildEmptyObject;
            }

            case enMode::UpdateMode:
            {
                _Update();

                return enSaveResults::svSucceeded;

                break;
            }

            case enMode::AddNewMode:
            {
                if (IsClientExist(AccountNumber()))
                {
                    return enSaveResults::svFaildAccountNumberExists;
                }
                else
                {
                    _AddNew();
                    this->_Mode = enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                    break;
                }
            
            }
        }
    }

    static clsBankClient GetAddNewClient(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }

        _SaveCleintsDataToFile(vClients);
        *this = _GetEmptyClientObject();

        return true;
    }

    void Deposit(double Amount)
    {
        AccountBalance += Amount;

        Save();
    }

    void WithDraw(double Amount)
    {
        AccountBalance -= Amount;
        Save();
    }

    bool Transfer(double Amount, clsBankClient &DestinationClient)
    {
        if (Amount > this->AccountBalance)
        {
            return false;
        }
        else
        {
            this->WithDraw(Amount);
            DestinationClient.Deposit(Amount);
            _SaveTransferRecordLineToFile(DestinationClient, Amount);
            return true;
        }

    }

    static vector <clsBankClient> GetClientsList()
    {   
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = GetClientsList();
        double TotalBalances = 0;

        for (clsBankClient& C : vClients)
        {
            TotalBalances += C.AccountBalance;
        }
        return TotalBalances;
    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    static stTransferLogInfo ConvertTransferRecordLineToInfo(string Text, string Separator = "#//#")
    {
        vector <string> SplittedText = clsString::Split(Text, Separator);

        stTransferLogInfo Info; 

        if (SplittedText.size() < 7)
            return Info;

        Info.DateTime = SplittedText[0];
        Info.SourceAccNumber = SplittedText[1];
        Info.DestinationAccNumber = SplittedText[2];
        Info.Amount = stod(SplittedText[3]);
        Info.SourceAccbalance = stod(SplittedText[4]);
        Info.DestinationAccbalance = stod(SplittedText[5]);
        Info.UserName = SplittedText[6];

        return Info;
    }

    static vector< stTransferLogInfo > LoadLoadTransferRecordFromFile()
    {
        fstream File;

        File.open("TransferLog.txt", ios::in); // READ MODE

        vector <stTransferLogInfo> vTransferInfo;

        string Line = "";

        if (File.is_open())
        {
            while (getline(File, Line))
            {
                if (Line != "") { vTransferInfo.push_back(ConvertTransferRecordLineToInfo(Line));}
            }
            File.close();
        }

        return vTransferInfo;
    }

};

