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

void Input_date(Date&a){
    

    cout<<setw(20)<<"Enter In form dd mm yyyy:";
    cin>>a.day>>a.month>>a.year;

}
// Class Bank
class Bank : public ui
{
protected:
    string Bank_Name; // Name of bank let it be 1
    string Affiltrated_To;
    static vector<string> Bank_Logs;


    static long double Amount_in_Bank;
    //as this will not change as the no of user will change which will create many time of data for diff bank

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
    Bank(
         string k) : Bank_Name(k), Affiltrated_To("R.B.I")
    {
    // , Amount_in_Bank(kp)
        // long double kp
    }
    // Bank(long double kp) : Affiltrated_To("R.B.I"), Amount_in_Bank(kp)
    // {
    // }

public:
    Bank() : Affiltrated_To("R.B.I")
    {
        Amount_in_Bank = 10000000;
    }
    string Bank_Name_Open_To_Everyone=Bank_Name;
};

// staff details

class Employee 
{ // giving acess to bank for removing the ambiguity
protected:
    string Emp_Id; // id
    string Name;
    string Job_Role;
    struct Date Date_of_joining; // date of joining
    struct Date DOB;             // date of birth
    ui Printer;
    double salary; // salary count

    
public:
    Employee()
    {
        Copy_Date(Date_of_joining, Today);
         // Defaut date
    }

    Employee(string k) : Name(k)
    {
        Copy_Date(Date_of_joining, Today);
    }

    Employee(string k, string kp,string km) : Name(k), Emp_Id(kp),Job_Role(km)
    {
        Copy_Date(Date_of_joining, Today);
    }

    Employee(string k, string kp,string km, Date tp, double sal) : Name(k), Emp_Id(kp),Job_Role(km), salary(sal)
    {
        Copy_Date(Date_of_joining, Today);
        Copy_Date(DOB, tp);
    }

    // MAx use
    Employee(string k, string kp,string km, double sal, Date tp,Date tg) : Name(k), Emp_Id(kp),Job_Role(km), salary(sal)
    {
        Copy_Date(Date_of_joining, tg);
        Copy_Date(DOB, tp);
    }

    Employee(string k, string kp,string km, Date tp) : Name(k), Emp_Id(kp),Job_Role(km)
    {
        Copy_Date(Date_of_joining, Today);
        Copy_Date(DOB, tp);
    }

    Employee(string k, string kp,string km, double sal) : Name(k), Emp_Id(kp),Job_Role(km), salary(sal)
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
        Printer.print(Employee_Data, 6);
    }
};

class Manager : public Employee,public Bank
{
protected:
    unsigned short int Rate;
    // vector<Employee>Employee_List;
    // vector<User>User_List;


public:
    Manager()
    {
        Rate = 7;
    }//copy
    Manager(string k, string kp,string km) : Employee(k, kp,km)
    {
        Rate = 7;
    }
    Manager(string k, string kp,string km, Date tp, Date tg,double sal) : Employee(k, kp,km,sal, tp, tg )
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
    void Disp_Bank_Logs(){
        
        string cp[Bank_Logs.size()+1];
        for(size_t i=0;i<Bank_Logs.size();i++){
            cp[i]=Bank_Logs[i];

        }
        ostringstream occ;
        occ<<"Amount in Bank : "<<setprecision(2)<<Amount_in_Bank;
        cp[Bank_Logs.size()]=occ.str();

        print(cp,Bank_Logs.size()+1);
        
    }

    void manager(){
        cout<<setw(30)<<"Enter Emp_Id : ";
        cin>>Emp_Id;
        cout<<setw(30)<<"Enter Name : ";
        cin>>Name;
        cout<<"Enter Date of Joining";
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



class Account:protected Bank{
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

class Saving_Account:public Account{
    public:
    
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
        Amount_in_Bank-=cash;
        ostringstream oss2,oss1;

        oss2<<Account_No<<" WithDrawed "<<setprecision(2)<<cash<<" on "<<Today.day<<" "<<Today.month<<" "<<Today.year;
        oss1<<" Amount : "<<Amount_in_Bank;
        Bank_Logs.push_back(oss2.str());
        Bank_Logs.push_back(oss1.str());

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

        ostringstream oss1,oss2;
        oss2<<Account_No<<" Deposited "<<setprecision(2)<<cash<<" on "<<Today.day<<" "<<Today.month<<" "<<Today.year;
        oss1<<" Amount : "<<Amount_in_Bank;
        Bank_Logs.push_back(oss2.str());
        Bank_Logs.push_back(oss1.str());

    }
    Saving_Account(string no,string pass,string ifsc,double cash):Account( no,pass, ifsc,Today,cash){
        deposit(cash);

    }
    Saving_Account(){}
    void Display_Statement(){
        string cp[Statement.size()+1];
        for(size_t i=0;i<Statement.size();i++){
            cp[i]=Statement[i];

        }
        ostringstream occ;
        occ<<"Balance "<<setprecision('0')<<Amount;
        cp[Statement.size()]=occ.str();

        print(cp,Statement.size()+1);

    }


    



};

class User :public ui
{
protected:
    string Name;
    string C_Id;
    string Aadhar_No;
    struct Date DOB;
    string Work;
    string Address;
    Saving_Account S;//Details of bank account;


public:
    User():S () {}
    User(string tp, string cp, string kp, string np, string bp, Date mp) : Name(tp), C_Id(cp), Aadhar_No(kp), Work(np), Address(bp)
    {
        Copy_Date(DOB, mp);
    }
    void Display_User_Details()
{
    ostringstream oss;
    oss<<setw(2)<<setfill('0')<<DOB.day<<"/"<<setfill('0')<<setw(2)<<DOB.month<<"/"<<setw(4)<<setfill('0')<<DOB.year;
    string details[6][2]={{"Name ",Name},{"Customer Id ",C_Id},{"Aadhar Number ",Aadhar_No},{"DOB ",oss.str()},{"Work ",Work},{"Address",Address}};
    print(details,6);

}
    
    

};


// void create_user(){
//
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
//
//     cout<<setfill(' ')<<"|"<<setw(30)<<setfill(' ')<<"Proffession|"<<setfill(' ')<<setw(30)<<Work<<"|"<<endl;
//     cout<<" ";
//     for (int i=0;i<60;i++)
//         cout<<"¯";
//     cout<<endl;
// }
//
// int main(){
//
//     User k;
//     k.create_user();
//     k.Disp_User_details();
//     return 0;
// }

long double Bank::Amount_in_Bank=10000000;

// void Input(){
//     //Emp_Id,Name,Date_of_joining,DOB,Salary,Rate,Bank_name,Bank_amount,Bank_logs,Bank_affiltration


// }

// void Input_detalis(){
//     ui Input;
//     while(true){
//     string a[][3]={"Input Data for ","1. Employee","2. User"};
//     Input.print(a,1);
//         int choice;
//         cin>>choice;
//         if(choice%2){
//             string pl[1]={"Enter Details For Employee"};
//             Input.print(pl,1);
//             cout>>setw(20)>>"Emp_Id :";
//             string Emp_Id; 
//             string Name;
//             struct Date Date_of_joining; 
//             struct Date DOB;             
//     double salary;
//             cin          
//         }
//     }
// }

bool input_check(string a,string b="y"){
    try{
        if(a!=b){
            throw a;
        }

    }
    catch(string msg){
        ostringstream oss;
        oss<<"Error!!\tWrong Input\t"<<msg<<endl;
        string erro[1];
        erro[0]=oss.str();
        ui printer;
        printer.print(erro,1);
        return false;

    }
    catch(...){
        cout<<setw(50)<<"Error!!!\tUnexpected Error"<<endl;
        return false;
    }
    return true;

}



void manager_setup(vector<Manager> &M){
    int noOfManager;
    cout<<endl<<setw(30)<<"Enter no of Manager: ";
    try{
        cin>>noOfManager;
        if(noOfManager<=0){
            throw noOfManager;
        }
    }
    catch(int a){

        cerr<<endl<<setw(80)<<"Kindly enter valid No. of Managers \t,otherwise the Bank would be Robbed :)"<<endl;
    
    }

    for(int i=0;i<noOfManager;i++){
        // Temp details
        string Emp_Id1; 
        string Name1;
        string Job_Role1;
        struct Date DOJ1; 
        struct Date DOB1;             
        double salary1;
        
        if(!i){
        cout<<"\nEnter Details For `Head Manager`:\n";
        }
        else{
            cout<<setw(50)<<"\nEnter Details For Manager "<<i<<":"<<endl;
        } 

        cout << setw(40) << "Enter Name: ";
        cin >> Name1;
        
        cout << setw(40) << "Enter EmpId: ";
        cin >> Emp_Id1;

        cout << setw(40) << "Enter Job Role: ";
        cin >> Job_Role1;

        cout << "Hint: DD MM YYYY" << endl;
        cout << setw(40) << "Enter DOJ: ";
        cin >> DOJ1.day >> DOJ1.month >> DOJ1.year;

        cout << setw(40) << "Enter DOB: ";
        cin >> DOB1.day >> DOB1.month >> DOB1.year;

        cout<< setw(40)<< "Enter salary: ";
        cin>>salary1;

        

        Manager M1(Name1,Emp_Id1,Job_Role1,DOB1,DOJ1,salary1);
        
        M.push_back(M1);
    
    }






    
}

int main(){
    Today.day=16;
    Today.month=1;
    Today.year=2024;
    Date dob;
    dob.day=2;
    dob.month=10;
    dob.year=2003;
    Date DOJ;
    Input_date(DOJ);
    Disp_Date(DOJ);
    

        



    return 0;
}





//last snippet i was working was at statement and bank logs 
// bank logs were given the static type and data is added in them using the same deposit and withdraw funtion
//last snippet i was working was making an "manager" function in Manager to get input
// wasnt able to complete this project as this project is going to be my tech debt;
 

//let's start counting days now i am working ont this project
// day X+0 #day1
/*  
    #day1
        today i am going to work according to the new function i need 
        manager_setup{
            -no. of managers and their details;
        
        }

        manager search; currenlty not needed when needed we will make it
        
    */

// Task for #day2

/*
    #day2
        i will be working on the user setup linking this with one of the manager
        just by giving an id of manager to him dont know how but will configure;

        and account setup would be done with this so get tuned
    
    */






    



