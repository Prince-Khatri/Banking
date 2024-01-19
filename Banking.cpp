#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
//To be done 
// try block for entering money without name of bank or user





struct Date{
    public:

    unsigned int day,month;
    unsigned int year;}Today;
    

int age(struct Date &DOB){
    unsigned short int a1=Today.year-DOB.year-1;    
    if((Today.month-DOB.month)>0){
        a1++;
    }
    else if((Today.month-DOB.month)==0){
    
    if ((Today.day-DOB.day>=0)){
        a1++;}}
    return a1;
}
void Disp_Date(Date a){
    cout<<a.day<<" "<<a.month<<" "<<a.year<<endl;

}




//Class Bank
class Bank{
    protected:
    string Bank_Name;//Name of bank
    string Affiltrated_To;

    long double Amount_in_Bank;
    
    string Bank_name(){//Returning Name
        return Bank_Name;
    }
    long double Amount_in_bank(){//returning amount
        return Amount_in_Bank;
    }
    protected:
    void Bank_N(string k,long double kp){
        Bank_Name=k;
        Affiltrated_To="R.B.I";
        Amount_in_Bank=kp;
    }
    Bank(long double kp,string k):Bank_Name(k),Affiltrated_To("R.B.I"),Amount_in_Bank(kp){
    }
    Bank(long double kp):Affiltrated_To("R.B.I"),Amount_in_Bank(kp){
    }
    public:
    Bank():Affiltrated_To("R.B.I"){}

    

};



//staff details

class Employee{
    protected:
    string Emp_Id;//id
    string Name;
    struct Date Date_of_joining,DOB;//date of joining
    double salary;//salary count
    public:
    Employee(){
        Date_of_joining=Today;//Defaut date
        
    }
    Employee(string k):Name(k){
        
        
    }

    Employee(string k,string kp):Name(k),Emp_Id(kp){}
    
    Employee(string k,string kp,Date tp,double sal):Name(k),Emp_Id(kp),Date_of_joining(tp),salary(sal){}


    Employee(string k,string kp,double sal,Date tp):Name(k),Emp_Id(kp),Date_of_joining(tp),salary(sal){}
    
    Employee(string k,string kp,Date tp):Name(k),Emp_Id(kp),Date_of_joining(tp){}
    Employee(string k,string kp,double sal):Name(k),Emp_Id(kp),salary(sal){}
    // Employee(string k,string kp):Name(k),Emp_Id(kp){}
    // Employee(string k,string kp):Name(k),Emp_Id(kp){}

    
    void Disp__(){
        cout<<endl<<"Name:"<<Name;
        cout<<endl<<"Empl_ID:"<<Emp_Id;
        cout<<endl<<"salary:"<<salary;
        cout<<endl<<"Date_of_joining";
        

    }
    
};

class Manager:protected Employee,protected Bank{
    protected:
    unsigned short int Rate=7;


    public:
    Manager(){}
    Manager(string k,string kp):Employee(k,kp){
    }
    Manager(string k,string kp,Date tp,double sal):Employee(k,kp,tp,sal){}
    

    
    // void Bank_N(string k);
    // void Disp_Bank_N();
    // string Bank_N();

    // void Disp_Amount();
    // void Amount_in_B(long double ip);
    // long double Amount_in_B();

    // void Rate(unsigned short int lp);
    // void Disp_Rate();
    // unsigned short int Rate();


    void Bank_N(string k){
        //entering bank name
    Bank_Name=k;

    }
    void Disp_Bank_N(){
        cout<<Bank_Name<<endl;
    }
    string Bank_N(){//for giving the value to any input
        return Bank_name();

    }

    //Amount Maniplutation



    void Amount_in_B(long double ip){
        Amount_in_Bank=ip;
         
    }

    void Disp_Amount(){
        //display anount in bank
        cout<<Amount_in_Bank<<endl;
    }
    long double Amount_in_B(){
        return Amount_in_bank();
    }

    //rate

    void rate(unsigned short int lp){
        Rate=lp;
    }
    unsigned short int rate(){
        return Rate;
    }
    void Disp_Rate(){
        cout<<Rate<<"%"<<endl;
    }


    


};



int main(){
    Today.day=16;
    Today.month=1;
    Today.year=2024;
    Date dob;
    dob.day=13;
    dob.month=10;
    dob.year=2004;


    
    Employee M("Prince");
    Employee M2("Prince2","1MS23Is021-T");
    Employee M3("Prince3","1MS23Is021-T",dob);
    Employee M4("Prince4","1MS23Is021-T",dob,1000000);
    Employee M5("Prince","1MS23Is021-T",100000000);
    
    
    

    
    
    
    
    // M.Bank_N("S.B.I.");
    // M.Disp_Bank_N();
    // M.Amount_in_B(999999);

    return 0;
}

