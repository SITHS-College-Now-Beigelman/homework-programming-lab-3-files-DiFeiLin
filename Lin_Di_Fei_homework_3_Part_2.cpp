/*Di Fei Lin
10/7/24
Lab 5 */
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
    string typeTransaction; // identifies the variables 
    double transactionMoney;
    double moneyTotal;
    double credit = 0;//credit amount starts at 0
    double debit = 0;//debit amount startsat 0
    ifstream myInput;//identify the input and output file 
    ofstream myOutput;
    string WorD;
    myInput.open("transaction.txt");//open the file 
    myOutput.open("bankstatment.txt");
    myInput>>moneyTotal;
    myOutput<<setfill('.');
    myOutput<<"TYPE"<<setw(12)<<"AMOUNT"<<setw(27)<<"BALANCE";
    while (!myInput.eof()){ // it ends when the numbers of transactions hits 0

    myInput>>WorD>>transactionMoney;

    if (WorD == "D"){ // if debit subtraction 

        myOutput<<"Deposit: "<<transactionMoney<<endl;
        myOutput<<"New Account balance: $" <<moneyTotal-transactionMoney<<endl;
        moneyTotal = moneyTotal-transactionMoney;

        debit = debit + transactionMoney;// totals the debit deduction amount 
    }

    else {
        myOutput<<"Withdrawl: "<<transactionMoney<<endl;
        myOutput<<"New Account balance: $" <<moneyTotal+transactionMoney<<endl;// if credit addition 
        moneyTotal = moneyTotal+transactionMoney;//adds to the amount money left 

        credit = credit+transactionMoney;//totals the debit deduction amount 
    }
    }

    cout<<"Total credit addition: $"<<credit<<endl;//prints total credit amount 
    cout<<"Total debit deduction: $"<<debit<<endl;//prints total debit deductions 

    return 0;

}
/*Withdrawl: 200.00
New Account balance: $5200.00
Withdrawl: 800.00
New Account balance: $6000.00
Withdrawl: 40.00
New Account balance: $6040.00
Deposit: 90.00
New Account balance: $5950.00
Deposit: 100.00
New Account balance: $5850.00
Deposit: 1000.00
New Account balance: $4850.00
Withdrawl: 20.00
New Account balance: $4870.00
Withdrawl: 20.00
New Account balance: $4890.00
Total credit addition: $1080.00
Total debit deduction: $1190.00*/