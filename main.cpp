/*  Add the Instructions as referenced by No 3 of the assignment
 *  Your name
 *  Date of program creation;
 *  Purpose/functionality of the program.
 */



#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;


class BankAccount
{
private:
        double accountBalance=0.0;
        int accountNumber=0;
        string firstName="";
        string lastName="";
        string accountType="";


public:
    BankAccount() {

    }
    virtual double getAccountBalance(){

        return accountBalance;

    }
    virtual int getAccountNumber(){


        return accountNumber;


    }
    virtual string getAccountUserFirstName(){


        return firstName;

    }
    virtual string getAccountUserLastName(){


        return lastName;

    }
    virtual void setDepositAmount(double deposit){



    }

    virtual void setWithdrawAmount(double amount){
    }
    virtual void setFirstName(string & fName){
        firstName=fName;

    }
    virtual void setLastName(string & lName){


        lastName=lName;


    }
    virtual void setCheckIncrement(double increment){

    }
    virtual void setAddProfit(double profit){

    }
    virtual string getAccountType(){

     return accountType;   }
    virtual void setAddProfitToBalance(){

    }


};

//----------------------------------------->
//->we declare the class as final so no other class could derive from it
class CheckingAccount final:public BankAccount
{
private:

   double accountBalance=0.0;
   long  accountNumber;
   string firstName="" ;
   string lastName ="";
   string accountType="Checking Account";
   int numberOfChecks=0;
public:
        CheckingAccount(string fName,string lName,long accNo,double deposit):firstName(fName),
        lastName(lName),
        accountNumber(accNo),
        accountBalance(deposit){

        }

        string getAccountType(){
            return accountType;
        }

        double getAccountBalance() {

            return accountBalance;

        }
         int getAccountNumber(){


            return accountNumber;


        }
        string getAccountUserFirstName(){


            return firstName;

        }
        string getAccountUserLastName(){


            return lastName;

        }

        void setFirstName(string & fName){

           firstName=fName;


        }
        void setLastName(string & lName){
            lastName=lName;


        }
        void setDepositAmount(double deposit){

            //->Increament the account balance
            accountBalance+=deposit;

        }

        void setWithdrawAmount(double amount){

            //->withdraw cash

            //->Make sure there is sufficient funds to withdraw

            //->decrement accountBalance in relation to the amount withdrawn ->//
            if (amount<=accountBalance){
                accountBalance-=amount;

                std::cout<<"You have succesfully withdrawn  "<<amount <<"  Your Balance is  "<<accountBalance<<std::endl;
            }
            else {
                std::cout<<"Sorry,There is no sufficient funds to withdraw"<<std::endl;
            }




        }




        void setCheckIncrement(int increment){
            //->Increment checks

            numberOfChecks+=increment;

        }



};


class SavingsAccount final:public BankAccount
{
private:

    double accountBalance=0.0;
    long  accountNumber;
    string firstName;
    string lastName ;

    double accruedProfit=0.0;

    string accountType="Savings Account";


public:
    SavingsAccount(string firstName,string lastName,long accountNo,double deposit):firstName(firstName),
        lastName(lastName),
        accountNumber(accountNo),
        accountBalance(deposit){

        }

    string getAccountType(){
        return accountType;
    }
    double getAccountBalance(){

        return accountBalance;

    }
    int getAccountNumber(){

        return accountNumber;

    }
    string getAccountUserFirstName(){

        return firstName;

    }
    string getAccountUserLastName(){

        return lastName;

    }


    void setDepositAmount(int deposit){

        //->Increament the account balance
        accountBalance+=deposit;

    }

    void setFirstName(string & fName){

       firstName=fName;


    }
    void setLastName(string & lName){
        lastName=lName;


    }
    void setWithdrawAmount(double amount){

        //->withdraw cash

        //->Make sure there is sufficient funds to withdraw

        //->decrement accountBalance in relation to the amount withdrawn ->//
        if (amount<=accountBalance){
            accountBalance-=amount;

            std::cout<<"You have succesfully withdrawn  "<<amount <<"  Your Balance is  "<<accountBalance<<std::endl;
        }
        else {
            std::cout<<"Sorry,There is no sufficient funds to withdraw"<<std::endl;
        }




    }

    //->Track profit earned after a month
    void setAddProfitToBalance(){

        accountBalance+= accruedProfit;

        std::cout<<"SUCCESTULLY ADDED THE ACCRUEDPROFIT TO THE ACCOUNT BALANCE"<<std::endl;

    }

    void setAddProfit(double profit){
        //->Balance added to profit at the end of the month

        accruedProfit+=profit;
    }
};

//----------------------------------------->
/*
long generateAccountNumber(){

return;
}
*/
int main(int argc, char *argv[])
{


std::vector<BankAccount*> accounts;
while (1){
    string option="";

    std::cout<<"[----------------------MAIN MENU ---------------------------]"<<std::endl;
    std::cout<<"[ Choose 'a' :To Display a list of existing bank accounts ]"<<std::endl;

    std::cout<<"[ Choose 'b'  :To Add a new bank account ]"<<std::endl;

    std::cout<<"[ Choose 'c'  :Edit an existing bank account ]"<<std::endl;

    std::cout<<"[ Choose 'd'  :Exit the program ]"<<std::endl;

    std::cout<<">>> : ";

    cin>>option;

    //std::cout<<"\n"<<std::endl;



    if(option == "a") {

        if(!accounts.empty()){
        std::cout<<"ACC NO. :"<<" FIRST-NAME :"<<" LAST-NAME :"<<" BALANCE "<<" ACCOUNT-TYPE "<<std::endl;
        std::cout<<"------------------------------------------------------"<<std::endl;
        for (auto & account:accounts){

            std::cout<<account->getAccountNumber()
            <<"         "<<
            account->getAccountUserFirstName()
            <<"         "<<
            account->getAccountUserLastName()
            <<"         "<<
            account->getAccountBalance()
            <<"         "<<
            account->getAccountType()<<std::endl;

            std::cout<<std::endl;
            std::cout<<"------------------------------------------------------"<<std::endl;
        }
        }
        else std::cerr<<"No available accounts yet ....................."<<std::endl;




    }
    else if (option=="b"){

        CheckingAccount *checking;
        SavingsAccount  *saving;

        if(accounts.size()<6){
            string accountType;
            int checks;
            string firstName;
            string lastName;
            double deposit;
            std::cout<<"[ Choose 'k' for a checkin account and 's' for a saving account ]"<<std::endl;
            std::cout<<">>> : ";
            cin>>accountType;
            if (accountType=="k") {

                std::cout<<"[INFO] OPENING A CHECKING ACCOUNT ---->"<<std::endl;

                std::cout<<"USER FIRSTNAME  : ";
                cin>>firstName;
                std::cout<<"USER LASTNAME   : ";
                cin>>lastName;
                //->balance equals initial deposit

                std::cout<<"DEPOSIT AMOUNT  : ";

                std::cin>>deposit;


               


                int accountNo;

               // long accountNo=generateAccountNumber();


                    accountNo=accounts.size()+1;



                //CheckingAccount checking(firstName,lastName,accountNo);


                checking = new CheckingAccount(firstName,lastName,accountNo,deposit);



                //std::cout<<"////" << checking->getAccountUserFirstName()<<endl;

                accounts.push_back(checking);
                }

             else if(accountType=="s"){


                std::cout<<"[INFO] OPENING A SAVINGS ACCOUNT ---->"<<std::endl;

                std::cout<<"USER FIRSTNAME  : ";
                cin>>firstName;
                std::cout<<"USER LASTNAME   : ";
                cin>>lastName;
                                //->balance equals initial deposit
                std::cout<<"DEPOSIT AMOUNT  : ";

                std::cin>>deposit;


                int accountNo;

               // long accountNo=generateAccountNumber();


                    accountNo=accounts.size()+1;





                //long accountNo=generateAccountNumber();

               saving = new SavingsAccount(firstName,lastName,accountNo,deposit);

                accounts.push_back(saving);

                }
            }
          else {


                std::cout<<"[ INFO ] Cannot add more than 5 accounts"<<std::endl;

              }






    }
else if (option=="c"){


        if(accounts.size()<5)

        {

            int accountNo;
            std::cout<<"[ INFO ] INPUT ACCOUNT NO "<<std::endl;
            std::cout<<">>> : ";

            cin>>accountNo;
            //->search for account
            //->use vector index number to track account no NOTE ACCOUNT NUMBERS START WITH ONE so we subtract one to get the position in our
            //        vector
            BankAccount *account;

            try{

                 account =accounts.at((int)accountNo-1);
            }
            catch(...){

                std::cout<<"Account with account no "<< accountNo <<"Does not exist " <<std::endl;

                account=nullptr;

            }

            //->check if account is not equal null cause if it does then the index doesnt exist



            if (account!= NULL){

                    //-display account information

                    std::cout<<"ACC NO . :"<<" FIRST-NAME  :"<<" LAST-NAME :"<<" BALANCE "<<" ACCOUNT-TYPE "<<std::endl;
                    std::cout<<"--------------------------------------------------------------------------"<<std::endl;


                    std::cout<<account->getAccountNumber()
                    <<"         "<<
                    account->getAccountUserFirstName()
                    <<"         "<<
                    account->getAccountUserLastName()
                    <<"         "<<
                    account->getAccountBalance()
                    <<"         "<<
                    account->getAccountType()<<std::endl;

                    std::cout<<std::endl;
                    std::cout<<"---------------------------------------------------------"<<std::endl;


                    //-------> Edit details ----------------------------

                    std::cout<<"[ - [INFO] - ] CHOOSE 'f' to edit firstname , CHOOSE 'l' to edit lastname ,"
                               " CHOOSE 'd' to deposit, CHOOSE 'w' to withdraw, CHOOSE 'i' To INCREMENT NUMBER OF CHECKS(Checking Accounts)"
                               " 'p' to Add profits (Savings Accounts) to Add profits to balance CHOOSE 'm' (Savings Account) "<<std::endl;


                    string option;
                    std::cout<<">>> : "<<std::endl;
                    cin>>option;

                    if(option== "f"){
                        string fName;

                        std::cout<<" CHANGE THE FIRSTNAME : "<<std::endl;
                        std::cout<<">>> : ";
                        cin>>fName;

                        account->setFirstName(fName);
                    }
                    else if (option== "l") {
                        string lName;
                        std::cout<<" CHANGE THE LASTNAME : "<<std::endl;
                        std::cout<<">>> : ";
                        cin>>lName;

                        account->setLastName(lName);

                    }
                    else if (option == "d") {
                        double amount ;
                        std::cout<<" DEPOSIT INTO THE ACCOUNT : "<<std::endl;
                        std::cout<<">>> : ";
                        cin>>amount;

                        account->setDepositAmount(amount);

                    }
                    else if (option== "w") {

                        double amount ;
                        std::cout<<" DEPOSIT INTO THE ACCOUNT : "<<std::endl;
                        std::cout<<">>> : "; cin>>amount;

                        account->setWithdrawAmount(amount);


                    }


                else if ((option == "i")) {
                   //->check whether the account is a checking or saving account
                    if ( dynamic_cast<CheckingAccount*>( account )){
                       // std::cout<<"PROFIT ----"<<std::endl;

                        //->ask the user to increment the number of checks
                        int i ;
                        std::cout<<"ENTER NO OF CHECKS WRITTEN : "<<std::endl;
                        std::cout<<">>> : ";
                        cin>>i;
                        account->setCheckIncrement(i);



                    }

                }
                //->otherwise the account is a savings account so we have an
                else if(option == "p"){

                    double profit;
                    if ( dynamic_cast<SavingsAccount*>( account )){
                                      // std::cout<<"PROFIT ----"<<std::endl;
                        std::cout<<"[INFO ] PROFIT AMOUNT "<<std::endl;
                        std::cout<<">>> : ";
                        cin>>profit;
                        account->setAddProfit(profit);





                      }


                 }

                  else if(option == "m"){

                            //->if the user chooses m then we want to add the total profits to date with the balance
                        if ( dynamic_cast<SavingsAccount*>( account )){
                                          // std::cout<<"PROFIT ----"<<std::endl;


                             account->setAddProfitToBalance();


                          }


                    }




        else{

            std::cout<<"account does not exist"<<std::endl;

        }



     }

}

}
else if (option=="d"){

          std::cout<<"[INFO] EXITING PROGRAM --->"<<std::endl;

          return -1;

    }


}//END OF WHILE LOOP


    //->vector to keep track







    return EXIT_SUCCESS;
}
