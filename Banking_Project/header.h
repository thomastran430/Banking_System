#ifndef BANKING_PROJECT_HEADER_H
#define BANKING_PROJECT_HEADER_H
#endif
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Account
{
    int AccountNumber;
    string lastName;
    string firstName;
    double accountBalance;
    bool active;
};

void menu(int*);
void makeAccount(vector <Account> &Accounts);
void printAccount(vector <Account> &Accounts);
void transfer(vector <Account> &Accounts);
void PrintAllAccounts(vector <Account> &Accounts);
void depositAccount(vector <Account> &Accounts);
void ActiveDeactive(vector <Account> &Accounts);
void withdrawAccount(vector <Account> &Accounts);
void sortAccounts(vector <Account> &Accounts);
void deleteAccount(vector <Account> &Accounts);