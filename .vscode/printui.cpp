#include<iostream>
#include<iomanip>
using namespace std;

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

int main(){
    // printup();
    // printmid();printdown();
    // print("Prince kahtri is very good boy");
    string c3[][3]={"Prince","Khatri","   ","khjnfv","mdnfncm","mcndjnccs z x ds"};
    string c2[][2]={"Prince","Khatri","   ","khjnfv","mdnfncm","mcndjnccs z x ds"};
    string c1[]={"Prince","Khatri","   ","khjnfv","mdnfncm","mcndjnccs z x ds"};
    size_t s1=sizeof(c1)/sizeof(c1[0]);
    size_t s2=sizeof(*c2)/sizeof(*c2[0]);
    size_t s3=sizeof(*c3)/sizeof(*c3[0]);

    
    // cout<<s;
    // for (int i=0;i<s;i++){
    //     cout<<c[i];
    //     cout<<endl;
    // }

    print(c1,s1);
    print(c2,s2);
    print(c3,s3);

    return 0;
}