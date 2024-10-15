/*Di Fei Lin
10/15/24
homework 3  */
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
    
    string WorD;//withdrawl or deposit 

    myInput.open("transaction.txt");//open the file 

    myInput>>moneyTotal;

   for (int i = 0; i < 7; i++){ // it ends when the numbers of transactions hits 0

    myInput>>WorD>>transactionMoney;

    if (WorD == "D"){ // if debit subtraction 

        cout<<fixed<<showpoint;//set to two decimal points 
        cout<<setprecision(2);
        cout<<"Deposit: "<<transactionMoney<<endl;//prints deposit 
        cout<<"New Account balance: $" <<moneyTotal+transactionMoney<<endl;///prints new amount 
        moneyTotal = moneyTotal+transactionMoney;//add to ending balance 
        debit = debit + transactionMoney;// totals the debit deduction amount 
    }

    else {

        cout<<fixed<<showpoint;//set to two decimal points 
        cout<<setprecision(2);
        cout<<"Withdrawl: "<<transactionMoney<<endl;//print withdrawl amount 
        cout<<"New Account balance: $" <<moneyTotal-transactionMoney<<endl;//prints new amount 
        moneyTotal = moneyTotal-transactionMoney;//adds to the amount money left 
        credit = credit+transactionMoney;//totals the debit deduction amount 
    }

    }

    cout<<"Total credit addition: $"<<credit<<endl;//prints total credit amount 
    cout<<"Total debit deduction: $"<<debit<<endl;//prints total debit deductions 

    return 0;

}
/*Withdrawl: 200.00
New Account balance: $4800.00
Withdrawl: 800.00
New Account balance: $4000.00
Withdrawl: 40.00
New Account balance: $3960.00
Deposit: 90.00
New Account balance: $4050.00
Deposit: 100.00
New Account balance: $4150.00
Deposit: 1000.00
New Account balance: $5150.00
Withdrawl: 20.00
New Account balance: $5130.00
Total credit addition: $1060.00
Total debit deduction: $1190.00*/