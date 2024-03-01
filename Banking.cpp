#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <limits>
#include<vector>
using namespace std;
// To be done
//  try block for entering money without name of bank or user

class ui
{
public:
    void printup()
    {
        cout << " ";
        for (int i = 0; i < 60; i++)
        {
            cout << "_";
        }
        cout << endl;
    }

    void printmid()
    {
        cout << "|";
        for (int i = 0; i < 60; i++)
        {
            cout << "-";
        }
        cout << "|";
        cout << endl;
    }
    void printdown()
    {
        cout << " ";
        for (int i = 0; i < 60; i++)
        {
            cout << "¯";
        }
        cout << endl;
    }
    void printmain(string a)
    {
        cout << "|";
        cout << setw(60) << a << "|" << endl;
    }
    void printmain(string a[2])
    {
        cout << "|";
        cout << setw(30) << a[0] << "|" << setw(30 - 1) << a[1] << "|" << endl;
    }

    void printmain(string a[3], int t)
    {

        cout << "|";
        cout << setw(20) << a[0] << "|" << setw(19) << a[1] << "|" << setw(19) << a[2] << "|" << endl;
    }

    void print(string a[], int s)
    {
        printup();

        for (int i = 0; i < s - 1; i++)
        {
            printmain(a[i]);
            printmid();
        }
        printmain(a[s - 1]);
        printdown();
    }

    void print(string a[][2], int s)
    {
        printup();
        for (int i = 0; i < s - 1; i++)
        {
            printmain(a[i]);
            printmid();
        }
        printmain(a[s - 1]);
        printdown();
    }

    void print(string a[][3], int s)
    {
        printup();
        for (int i = 0; i < s - 1; i++)
        {
            printmain(a[i], 3);
            printmid();
        }
        printmain(a[s - 1], 3);
        printdown();
    }
};

struct Date
{
public:
    unsigned int day, month;
    unsigned int year;
} Today;

int age(struct Date &DOB)
{
    unsigned short int a1 = Today.year - DOB.year - 1;
    if ((Today.month - DOB.month) < 0)
    {
        a1++;
    }
    else if ((Today.month - DOB.month) == 0)
    {

        if ((Today.day - DOB.day <= 0))
        {
            a1++;
        }
    }
    return a1;
}
void Disp_Date(Date a)
{
    cout << a.day << " " << a.month << " " << a.year << endl;
}
void Copy_Date(Date &t, Date c)
{
    t.day = c.day;
    t.month = c.month;
    t.year = c.year;
}

// Class Bank
class Bank : public ui
{
protected:
    string Bank_Name; // Name of bank
    string Affiltrated_To;

    long double Amount_in_Bank;

    // converting data of bank to string[]

    void Bank_Details()
    {
        string Bank_Inside_Details[3][2] = {{"Bank_Name", Bank_Name}, {"Affiltrated_To", Affiltrated_To}, {"Amount_in_Bank", to_string(Amount_in_Bank)}};
        print(Bank_Inside_Details, 3);
    }

    string Bank_name()
    { // Returning Name
        return Bank_Name;
    }
    long double Amount_in_bank()
    { // returning amount
        return Amount_in_Bank;
    }

    // constructor to create bank details
    void Bank_N(string k, long double kp)
    {
        Bank_Name = k;
        Affiltrated_To = "R.B.I";
        Amount_in_Bank = kp;
    }
    Bank(long double kp, string k) : Bank_Name(k), Affiltrated_To("R.B.I"), Amount_in_Bank(kp)
    {
    }
    Bank(long double kp) : Affiltrated_To("R.B.I"), Amount_in_Bank(kp)
    {
    }

public:
    Bank() : Affiltrated_To("R.B.I")
    {
        Amount_in_Bank = 10000000;
    }
    string Bank_Name_Open_To_Everyone=Bank_Name;
};

// staff details

class Employee : protected Bank
{ // giving acess to bank for removing the ambiguity
protected:
    string Emp_Id; // id
    string Name;
    struct Date Date_of_joining; // date of joining
    struct Date DOB;             // date of birth

    double salary; // salary count

public:
    Employee()
    {
        Copy_Date(Date_of_joining, Today); // Defaut date
    }
    Employee(string k) : Name(k)
    {
        Copy_Date(Date_of_joining, Today);
    }

    Employee(string k, string kp) : Name(k), Emp_Id(kp)
    {
        Copy_Date(Date_of_joining, Today);
    }

    Employee(string k, string kp, Date tp, double sal) : Name(k), Emp_Id(kp), salary(sal)
    {
        Copy_Date(Date_of_joining, Today);
        Copy_Date(DOB, tp);
    }

    Employee(string k, string kp, double sal, Date tp) : Name(k), Emp_Id(kp), salary(sal)
    {
        Copy_Date(Date_of_joining, Today);
        Copy_Date(DOB, tp);
    }

    Employee(string k, string kp, Date tp) : Name(k), Emp_Id(kp)
    {
        Copy_Date(Date_of_joining, Today);
        Copy_Date(DOB, tp);
    }

    Employee(string k, string kp, double sal) : Name(k), Emp_Id(kp), salary(sal)
    {
        Copy_Date(Date_of_joining, Today);
    }

    void Display_Employee_Details()
    {
        // creating string which helps in out output table
        ostringstream ocp, ocp2;
        ocp << setfill('0') << setw(2) << Date_of_joining.day << '/' << setfill('0') << setw(2) << Date_of_joining.month << '/' << Date_of_joining.year;
        ocp2 << setfill('0') << setw(2) << DOB.day << '/' << setfill('0') << setw(2) << DOB.month << '/' << DOB.year;
        string Employee_Data[6][2] = {{"Name ", Name}, {"Employee ID ", Emp_Id}, {"Salary ", to_string(salary)}, {"Date Of Joining ", ocp.str()}, {"DOB ", ocp2.str()},{"Age",to_string(age(DOB))}};
        print(Employee_Data, 6);
    }
};

class Manager : public Employee
{
protected:
    unsigned short int Rate;

public:
    Manager()
    {
        Rate = 7;
    }
    Manager(string k, string kp) : Employee(k, kp)
    {
        Rate = 7;
    }
    Manager(string k, string kp, Date tp, double sal) : Employee(k, kp, tp, sal)
    {
        Rate = 7;
    }

    // Bank name manipaluation

    // assning value
    void Bank_N(string k)
    {
        // entering bank name
        Bank_Name = k;
    }

    // using value
    void Disp_Bank_N()
    {
        string css[1][2] = {{"Bank Name ", Bank_Name}};
        print(css, 1);
    }

    // printing value
    string Bank_N()
    { // for giving the value to any input
        return Bank_name();
    }

    // Amount Maniplutation

    void Amount_in_B(long double ip)
    {
        Amount_in_Bank = ip;
    }

    void Disp_Amount()
    {
        // display amount in bank
        ostringstream oss;
        oss << fixed << setprecision(2) << Amount_in_Bank;
        string tp[1][2] = {"Amount in Bank ", oss.str()};
        print(tp, 1);
    }

    long double Amount_in_B()
    {
        return Amount_in_bank();
    }

    // rate

    // assinging value
    void rate(unsigned short int lp)
    {
        Rate = lp;
    }

    // using value
    unsigned short int rate()
    {
        return Rate;
    }
    // displaying rate
    void Disp_Rate()
    {
        ostringstream oss;
        oss << Rate << " %";
        string kp[1][2] = {"Rate per year ", oss.str()};

        print(kp, 1);
    }

    // void Bank_N(string k);
    // void Disp_Bank_N();
    // string Bank_N();

    // void Disp_Amount();
    // void Amount_in_B(long double ip);
    // long double Amount_in_B();

    // void Rate(unsigned short int lp);
    // void Disp_Rate();
    // unsigned short int Rate();
};



class Account{
    protected:
    string Account_No;
    string Account_Password;
    string IFSC;
    double Amount;
    Date Date_Of_Opening;

    public:
    Account(){};
    Account(string no,string pass,string ifsc,Date date,double cash):Account_No(no),Account_Password(pass),IFSC(ifsc) {
        Copy_Date(Date_Of_Opening,date);
    }


};

class Saving_Account:protected Account{
    public:
    ui a;
    
    vector<string>Statement;
    void withdraw(double cash){
        Amount-=cash;//change in money 
        ostringstream oss;//string for statement
        //statement for withdrawl
        oss<<setw(30)<<"Amount Withdrawn "<<fixed<<setprecision(0)<<cash<<" On "<<setw(2)<<setfill('0')<<Today.day<<'/'<<setfill('0')<<setw(2)<<Today.month<<'/'<<setw(4)<<setfill('0')<<Today.year<<setw(20)<<setfill(' ');
        Statement.push_back(oss.str());
        ostringstream opp;
        //balance
        opp<<setw(35)<<"Balance "<<fixed<<setw(11)<<setprecision(0)<<Amount<<setw(14)<<"";
        Statement.push_back(opp.str());
    }
    void deposit(double cash){
        Amount+=cash;//cahnege in money
        ostringstream oss;//string for statement
        //statement for deposit
        oss<<"Amount deposit "<<fixed<<setprecision(0)<<cash<<" On "<<setw(2)<<setfill('0')<<Today.day<<'/'<<setfill('0')<<setw(2)<<Today.month<<'/'<<setw(4)<<setfill('0')<<Today.year;
        Statement.push_back(oss.str());
        ostringstream opp;
        //statement for withdrawl
        opp<<setw(35)<<"Balance "<<fixed<<setw(11)<<setprecision(0)<<Amount<<setw(14)<<"";
        Statement.push_back(opp.str());

    }
    Saving_Account(){}


    Saving_Account(string no,string pass,string ifsc,double cash):Account( no,pass, ifsc,Today,cash){
        deposit(cash);

    }
    void Display_Statement(){
        string cp[Statement.size()+1];
        for(size_t i=0;i<Statement.size();i++){
            cp[i]=Statement[i];

        }
        ostringstream occ;
        occ<<"Balance "<<setprecision('0')<<Amount;
        cp[Statement.size()]=occ.str();

        a.print(cp,Statement.size()+1);

    }

//     void Display_Statement(){
//     string cp[Statement.size() ];
//     for(size_t i = 0; i < Statement.size(); i++){
//         cp[i] = Statement[i];
//     }

    

//     print(cp, Statement.size() );
// }

};


class User : public Bank
{
protected:
    string Name;
    string C_Id;
    string Aadhar_No;
    struct Date DOB;
    string Work;
    string Address;
    Saving_Account S;

public:
    User() {}
    User(string tp, string cp, string kp, string np, string bp, Date mp) : Name(tp), C_Id(cp), Aadhar_No(kp), Work(np), Address(bp)
    {
        Copy_Date(DOB, mp);
    }
    void Display_User_Details()
{
    ostringstream oss;
    oss<<setw(2)<<setfill('0')<<DOB.day<<setfill('0')<<setw(2)<<DOB.month<<setw(4)<<setfill('0')<<DOB.year;
    string details[6][2]={{"Name ",Name},{"Customer Id ",C_Id},{"Aadhar Number ",Aadhar_No},{"DOB ",oss.str()},{"Work ",Work},{"Address",Address}};
    print(details,6);

}
    
    

};




// void create_user(){

//     cout<<setw(30)<<"Enter User Name :";
//     getline(cin,Name);
//     cout<<setw(30)<<"Enter C_Id:";
//     getline(cin,C_Id);
//     cout<<setw(30)<<"Enter Aadhar_No:";
//     getline(cin,Aadhar_No);
//     cout<<setw(30)<<"Enter DOB:";
//     cin>>DOB.day>>DOB.month>>DOB.year;
//     cin.ignore();
//     cout<<setw(30)<<"Enter Proffesion:";
//     getline(cin,Work);
//     cout<<endl;
// }
// void Disp_User_details(){
//     cout<<" ";
//     for (int i=0;i<60;i++){
//         cout<<"_";
//     }
//     cout<<endl;
//     cout<<"|"<<setw(30)<<"User Name|"<<setw(30)<<Name<<"|"<<endl;
//     line();
//     cout<<"|"<<setw(30)<<"Cust ID|"<<setw(30)<<C_Id<<"|"<<endl;
//     line();
//     cout<<"|"<<setw(30)<<"Aadhar No|"<<setw(30)<<Aadhar_No<<"|"<<endl;
//     line();
//     //dob disp setw,setfill
//     cout<<"|"<<setw(30)<<"DOB|";
//     for (int i=0;i<20;i++){
//         cout<<" ";
//     }
//     Disp_Date(DOB);
//     cout<<setfill(' ');
//     cout<<"|"<<endl;//date disp comp
//     line();

//     cout<<setfill(' ')<<"|"<<setw(30)<<setfill(' ')<<"Proffession|"<<setfill(' ')<<setw(30)<<Work<<"|"<<endl;
//     cout<<" ";
//     for (int i=0;i<60;i++)
//         cout<<"¯";
//     cout<<endl;
// }

// int main(){

//     User k;
//     k.create_user();
//     k.Disp_User_details();
//     return 0;
// }


int main(){
    Today.day=16;
    Today.month=1;
    Today.year=2024;
    Date dob;
    dob.day=13;
    dob.month=10;
    dob.year=2004;

    // Manager M1("Prince","IS0089");
    // Employee M2("Prince2","1MS23Is021-T");
    // Employee M3("Prince3","1MS23Is021-T",dob);
    // Manager M4("Prince4","1MS23Is021-T",dob,1000000);
    // Employee M5("Prince","1MS23Is021-T",100000000);
    // M.Display_Employee_Details();
    // M2.Display_Employee_Details();
    // M3.Display_Employee_Details();
    // M4.Display_Employee_Details();
    // M5.Display_Employee_Details();
    // M1.Disp_Amount();
    // M1.Bank_N("SBI");
    // M1.Disp_Bank_N();
    // M1.Disp_Rate();
    // M4.Display_Employee_Details();
    // Manager Lucky("Lucky","1MS23ME021",lucDOB,20000);
    // Lucky.Display_Employee_Details();

    User u("Prince","9009 2237 3892","5158 6166 7182","Student","Benguluru",dob);
    u.Display_User_Details();
    Saving_Account s("1MS23IS021-T","2God@2004","SBIN0021",5000);
    s.withdraw(200);
    s.deposit(500);
    s.withdraw(1000);
    s.deposit(10000);
    s.Display_Statement();
    Date lucDOB;
    lucDOB.day=1;
    lucDOB.month=8;
    lucDOB.year=2003;

    return 0;
}
