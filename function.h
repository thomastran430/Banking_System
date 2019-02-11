#ifndef BANKING_PROJECT_FUNCTION_H
#define BANKING_PROJECT_FUNCTION_H
#endif
#include "header.h"

void menu(int *num)
{
    int select = 0;
    cout << "Welcome! Select options below:" << endl
         << "\t1. Make new account." << endl
         << "\t2. Deposit to an account." << endl
         << "\t3. Withdraw from an account." << endl
         << "\t4. Transfer money." << endl
         << "\t5. Print account." << endl
         << "\t6. Activate/Deactivate an account." << endl
         << "\t7. Delete an account." << endl
         << "\t8. Display all accounts." << endl
         << "\t9. Quit." << endl
         << "Selection:\t";
    cin >> select;
    *num = select;
}

void makeAccount(vector <Account> &Accounts)
{
    Account x;
    srand((unsigned) time(0));
    x.AccountNumber = 1000 + rand()%8999;

    cout << "Creating bank account number " << x.AccountNumber << endl;
    cout << "Enter first name: ";
    cin >> x.firstName;
    cout << "Enter last name: ";
    cin >> x.lastName;
    cout << "Enter starting balance: ";
    cin >> x.accountBalance;
    Accounts.push_back(x);
}

void printAccount(vector <Account> &Accounts)
{
    int account_number;
    cout << "Enter the account number for the account that you would like to view: " ;
    cin >> account_number;
    bool active = false;
    for (int i = 0; i < Accounts.size(); i++)
    {
        if (Accounts[i].AccountNumber == account_number)
        {
            active = true;
            cout << "Account number: " << account_number << setw(12)
                 << "Balance: " << Accounts[i].accountBalance << endl
                 << "Last name: " << Accounts[i].lastName << setw(20)
                 << "First name: " << Accounts[i].firstName << endl;
        }
    }
    if(!active)
    {
        cout << "The account with account number " << account_number << " does not exist" << endl;
    }
}

void transfer(vector <Account> &Accounts)
{
    int sending_account;
    int receiving_account;
    double transfer_amount;
    cout << "Enter account number for the sender: ";
    cin >> sending_account;
    bool active1 = false;
    bool active2 = false;

    for (int i = 0; i < Accounts.size(); i++)
    {
        for (int j = 0; j < Accounts.size(); j++)
        {
            if (sending_account == Accounts[i].AccountNumber)
            {
                active1 = true;
                cout << "Enter account number for the receiver: ";
                cin >> receiving_account;

                if (receiving_account == Accounts[j].AccountNumber)
                {
                    active2 = true;
                    cout << "Enter amount to be transferred: ";
                    cin >> transfer_amount;

                    if (transfer_amount <= Accounts[i].accountBalance)
                    {
                        Accounts[i].accountBalance = Accounts[i].accountBalance - transfer_amount;
                        Accounts[j].accountBalance = Accounts[j].accountBalance + transfer_amount;
                        cout << "The new balance on account number " << Accounts[i].AccountNumber << " is "
                             << Accounts[i].accountBalance << endl
                             << "The new balance on account number " << Accounts[j].AccountNumber << " is "
                             << Accounts[j].accountBalance << endl;
                    }
                    else
                    {
                        cout << "The amount that you wish to transfer exceeds the account balance of the sender"
                             << endl;
                    }
                }
                if(!active2)
                {
                    cout << "The account with account number " << receiving_account << " does not exist" << endl;
                }
            }
        }
    }
    if(!active1)
    {
        cout << "The account with account number " << sending_account << " does not exist" << endl;
    }
}

void PrintAllAccounts(vector <Account> &Accounts)
{
    for (int i = 0; i < Accounts.size(); i++)
    {
        cout << "Account number: " << Accounts[i].AccountNumber << setw(12)
             << "Balance: " << Accounts[i].accountBalance << endl
             << "Last name: " << Accounts[i].lastName << setw(20)
             << "First name: " << Accounts[i].firstName << endl << endl;
    }
}

void depositAccount(vector <Account> &Accounts)
{
    int deposit_account;
    double deposit_amount;
    cout << "Enter account number for deposit: ";
    cin >> deposit_account;
    bool active = false;

    for(int i = 0; i < Accounts.size(); i++)
    {
        if (Accounts[i].AccountNumber == deposit_account)
        {
            active = true;
            cout << "Enter amount to be deposited: ";
            cin >> deposit_amount;
            Accounts[i].accountBalance = Accounts[i].accountBalance + deposit_amount;
            cout << "The new balance on account number " << Accounts[i].AccountNumber << " is " << Accounts[i].accountBalance << endl;
        }
    }
    if(!active)
    {
        cout << "The account with account number " << deposit_account << " does not exist" << endl;
    }
}

void ActiveDeactive(vector <Account> &Accounts)
{
    int account_number;
    cout << "Enter the account number that you would like to activate or deactivate: ";
    cin >> account_number;
    vector<Account>::iterator i;

    for (i = Accounts.begin(); i != Accounts.end(); i++)
    {
        if ((*i).AccountNumber == account_number)
        {
            if ((*i).active == true)
            {
                (*i).active = false;
                cout << "Account number " << account_number << " is now deactivated" << endl;
            }
            else
            {
                (*i).active = true;
                cout << "Account number " << account_number << " is now activated" << endl;
            }
        }
    }
}

void withdrawAccount(vector <Account> &Accounts)
{
    int withdraw_account;
    double withdraw_amount;
    cout << "Enter account number for withdrawal: ";
    cin >> withdraw_account;
    bool active = false;

    for( int i = 0; i < Accounts.size(); i++)
    {
        if (Accounts[i].AccountNumber == withdraw_account)
        {
            active = true;
            cout << "Enter amount to be withdrawn: ";
            cin >> withdraw_amount;
            if (withdraw_amount <= Accounts[i].accountBalance)
            {
                Accounts[i].accountBalance = Accounts[i].accountBalance - withdraw_amount;
                cout << "The new balance on account number " << Accounts[i].AccountNumber << " is " << Accounts[i].accountBalance << endl;
            }
            else
            {
                cout << "The amount that you wish to withdraw exceeds the account balance" << endl;
            }
        }
    }
    if(!active)
    {
        cout << "The account with account number " << withdraw_account << " does not exist" << endl;
    }
}

void sortAccounts(vector <Account> &Accounts)
{
    for (int i = 0; i < Accounts.size(); i++)
    {
        for (int j = i + 1; j < Accounts.size(); j++)
        {
            if(Accounts[j].AccountNumber < Accounts[i].AccountNumber)
            {
                Account temp = Accounts[i];
                Accounts[i] = Accounts[j];
                Accounts[j] = temp;
            }
        }
    }
}

void deleteAccount(vector <Account> &Accounts)
{
    int delete_account;
    cout << "Enter account number to be deleted: ";
    cin >> delete_account;
    bool active = false;

    for (int i = 0; i < Accounts.size(); i++)
    {
        if (Accounts[i].AccountNumber == delete_account)
        {
            Accounts.erase(Accounts.begin()+i);
            cout << "Account number " << delete_account << " has been deleted" << endl;
            active = true;
            break;
        }
    }
    if(!active)
    {
        cout << "The account with account number " << delete_account << " does not exist" << endl;
    }
}