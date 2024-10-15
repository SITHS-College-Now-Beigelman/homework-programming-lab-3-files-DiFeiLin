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

    int TotalD = 0; // total number of deposits 
    int TotalW = 0; // total number of withrdrawl

    ifstream myInput;//identify the input and output file 
    ofstream myOutput;
    string WorD; // withdrawl or deposit

    myInput.open("transaction.txt");//open the file 
    myOutput.open("bankstatment.txt");//open the bankstatement
    myInput>>moneyTotal; // money total is 5000

    myOutput<<setfill('.');//set fill for the statement 
    myOutput<<"STARTING BALANCE: $ 5000.00"<<endl;//starting balance 
    myOutput<<"TYPE"<<setw(12)<<"AMOUNT"<<setw(28)<<"BALANCE"<<endl;//the format 
    while (!myInput.eof()){ // it ends when the numbers of transactions hits 0

    myInput>>WorD>>transactionMoney; //reads the input 

    if (WorD == "D"){ // if debit subtraction 

        myOutput<<fixed<<showpoint;//sets to two decimal points 
        myOutput<<setprecision(2);
        myOutput<<"D"<<setw(14)<<transactionMoney<<setw(29)<<moneyTotal+transactionMoney<<endl;//prints the deposit statement 
        moneyTotal = moneyTotal+transactionMoney;//update the moneytotal 
        debit = debit + transactionMoney;// totals the debit deduction amount 
        TotalD = TotalD+1;//add one to total deposit 

    }

    else {

        myOutput<<fixed<<showpoint;//set to two decimal points
        myOutput<<setprecision(2);
        myOutput<<"W"<<setw(14)<<transactionMoney<<setw(29)<<moneyTotal-transactionMoney<<endl;//prints the withdrawl statement 
        moneyTotal = moneyTotal-transactionMoney;//adds to the amount money left 
        credit = credit+transactionMoney;//totals the credit  deduction amount 
        TotalW = TotalW+1;//add one to total withdrawl 
    }

    }
    myOutput<<"Ending Balance: $"<<moneyTotal<<endl;//prints ending balance 
    myOutput<<"Total credit addition: $"<<credit<<endl;//prints total credit amount 
    myOutput<<"Total debit deduction: $"<<debit<<endl;//prints total debit deductions 
    myOutput<<"Amount of credit transactions: "<<TotalD<<endl;//prints total credit amount 
    myOutput<<"Amount of debit transactions: "<<TotalW<<endl;//prints total debit deductions 
    return 0;

}
/*STARTING BALANCE: $ 5000.00
TYPE......AMOUNT.....................BALANCE
W........200.00......................4800.00
W........800.00......................4000.00
W.........40.00......................3960.00
D.........90.00......................4050.00
D........100.00......................4150.00
D.......1000.00......................5150.00
W.........20.00......................5130.00
Ending Balance: $5130.00Total credit addition: $1060.00
Total debit deduction: $1190.00
Amount of credit transactions: 3
Amount of debit transactions: 4
*/