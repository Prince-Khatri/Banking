#include<iostream>
#include<cstring>
#include<iomanip>
#include<sstream>
using namespace std;
//To be done 
// try block for entering money without name of bank or user

class ui{
    public:
    void printup(){
    cout<<" ";
    for (int i=0;i<60;i++){
        cout<<"_";
    }
    cout<<endl;
}

void printmid(){
    cout<<"|";
    for(int i=0;i<60;i++){
        cout<<"-";
    }
    cout<<"|";
    cout<<endl;
}
void printdown(){
    cout<<" ";
    for (int i=0;i<60;i++){
        cout<<"¯";
        
    }
    cout<<endl;
}
void printmain(string a){
    cout<<"|";
    cout<<setw(60)<<a<<"|"<<endl;

}
void printmain(string a[2]){
    cout<<"|";
    cout<<setw(30)<<a[0]<<"|"<<setw(30-1)<<a[1]<<"|"<<endl;
}

void printmain(string a[3],int t){
    
    cout<<"|";
    cout<<setw(20)<<a[0]<<"|"<<setw(19)<<a[1]<<"|"<<setw(19)<<a[2]<<"|"<<endl;
}

void print(string a[],int s){
    printup();
    
    for (int i=0;i<s-1;i++){
        printmain(a[i]);
        printmid();
    }
    printmain(a[s-1]);
    printdown();
}

void print(string a[][2],int s){
    printup();
    for(int i=0;i<s-1;i++){
        printmain(a[i]);
        printmid();
    }
    printmain(a[s-1]);
    printdown();
    
}

void print(string a[][3],int s){
    printup();
    for(int i=0;i<s-1;i++){
        printmain(a[i],3);
        printmid();
    }
    printmain(a[s-1],3);
    printdown();
    
}
};



struct Date{
    public:

    unsigned int day,month;
    unsigned int year;}
    Today;
    

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
void Copy_Date(Date &t,Date c){
    t.day=c.day;
    t.month=c.month;
    t.year=c.year;
}



//Class Bank
class Bank:public ui{
    protected:
    string Bank_Name;//Name of bank
    string Affiltrated_To;

    long double Amount_in_Bank;
    
    //converting data of bank to string[]
    

    void Bank_Details(){
        string Bank_Inside_Details[3][2]={{"Bank_Name",Bank_Name},{"Affiltrated_To",Affiltrated_To},{"Amount_in_Bank",to_string(Amount_in_Bank)}};
        print(Bank_Inside_Details,3);
    }
    
    
    string Bank_name(){//Returning Name
        return Bank_Name;
    }
    long double Amount_in_bank(){//returning amount
        return Amount_in_Bank;
    }
    
    //constructor to create bank details
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
    Bank():Affiltrated_To("R.B.I"){
        Amount_in_Bank=10000000;
    }

    

};



//staff details

class Employee:protected Bank{//giving acess to bank for removing the ambiguity
    protected:
    string Emp_Id;//id
    string Name;
    struct Date Date_of_joining;//date of joining
    struct Date DOB;//date of birth
    
    double salary;//salary count

    public:
    Employee(){
        Copy_Date(Date_of_joining,Today);//Defaut date
        
    }
    Employee(string k):Name(k){
        Copy_Date(Date_of_joining,Today);
        
        
    }

    Employee(string k,string kp):Name(k),Emp_Id(kp){
        Copy_Date(Date_of_joining,Today);
    }
    
    Employee(string k,string kp,Date tp,double sal):Name(k),Emp_Id(kp),salary(sal){
        Copy_Date(Date_of_joining,Today);
        Copy_Date(DOB,tp);
    }


    Employee(string k,string kp,double sal,Date tp):Name(k),Emp_Id(kp),salary(sal){
        Copy_Date(Date_of_joining,Today);
        Copy_Date(DOB,tp);
    }
    
    Employee(string k,string kp,Date tp):Name(k),Emp_Id(kp){
        Copy_Date(Date_of_joining,Today);
        Copy_Date(DOB,tp);
    }
    
    Employee(string k,string kp,double sal):Name(k),Emp_Id(kp),salary(sal){
        Copy_Date(Date_of_joining,Today);
    }
    

    void Display_Employee_Details(){
        //creating string which helps in out output table
        ostringstream ocp,ocp2;
        ocp<<setfill('0')<<setw(2)<<Date_of_joining.day<<'/'<<setfill('0')<<setw(2)<<Date_of_joining.month<<'/'<<Date_of_joining.year;
        ocp2<<setfill('0')<<setw(2)<<DOB.day<<'/'<<setfill('0')<<setw(2)<<DOB.month<<'/'<<DOB.year;
        string Employee_Data[5][2]={{"Name ",Name}
                                    ,{"Employee ID ",Emp_Id}
                                    ,{"Salary ",to_string(salary)}
                                    ,{"Date Of Joining ",ocp.str()}
                                    ,{"DOB ",ocp2.str()}
                                    };
        print(Employee_Data,5);
    }
    
    

    
};

class Manager:protected Employee{
    protected:
    unsigned short int Rate;


    public:
    Manager(){
        Rate=7;
    }
    Manager(string k,string kp):Employee(k,kp){
        Rate=7;
    }
    Manager(string k,string kp,Date tp,double sal):Employee(k,kp,tp,sal){
        Rate=7;
    }
    

    
    //Bank name manipaluation
    
    //assning value
    void Bank_N(string k){
        //entering bank name
        Bank_Name=k;

    }
    
    //using value
    void Disp_Bank_N(){
        string css[1][2]={{"Bank Name ",Bank_Name}};
        print(css,1);
    }
    
    //printing value
    string Bank_N(){//for giving the value to any input
        return Bank_name();

    }

    //Amount Maniplutation

    

    void Amount_in_B(long double ip){
        Amount_in_Bank=ip;
         
    }

    void Disp_Amount(){
        //display amount in bank
        ostringstream oss;
        oss<<fixed<<setprecision(2)<<Amount_in_Bank;
        string tp[1][2]={"Amount in Bank ",oss.str()};
        print(tp,1);

    }
    
    long double Amount_in_B(){
        return Amount_in_bank();
    }

    //rate

    //assinging value
    void rate(unsigned short int lp){
        Rate=lp;
    }
    
    //using value
    unsigned short int rate(){
        return Rate;
    }
    //displaying rate
    void Disp_Rate(){
        ostringstream oss;
        oss<<Rate<<" %";
        string kp[1][2]={"Rate per year ",oss.str()};

        print(kp,1);

    }

    


};

    // void Bank_N(string k);
    // void Disp_Bank_N();
    // string Bank_N();

    // void Disp_Amount();
    // void Amount_in_B(long double ip);
    // long double Amount_in_B();

    // void Rate(unsigned short int lp);
    // void Disp_Rate();
    // unsigned short int Rate();


int main(){
    Today.day=16;
    Today.month=1;
    Today.year=2024;
    // Date dob;
    // dob.day=13;
    // dob.month=10;
    // dob.year=2004;

    

    
    Manager M1("Prince","IS0089");
    // Employee M2("Prince2","1MS23Is021-T");
    // Employee M3("Prince3","1MS23Is021-T",dob);
    // Employee M4("Prince4","1MS23Is021-T",dob,1000000);
    // Employee M5("Prince","1MS23Is021-T",100000000);
    // M.Display_Employee_Details();
    // M2.Display_Employee_Details();
    // M3.Display_Employee_Details();
    // M4.Display_Employee_Details();
    // M5.Display_Employee_Details();
    M1.Disp_Amount();
    M1.Bank_N("SBI");
    M1.Disp_Bank_N();
    M1.Disp_Rate();


    
    
    

    
    
    
    
    

    return 0;
}

