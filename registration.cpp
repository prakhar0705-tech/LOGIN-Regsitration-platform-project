#include<bits/stdc++.h>
using namespace std;


class temp{
    string userName,Email,Password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void signup();
    void forgot();
}
   

obj;

int main(){
    char choice;
    cout<<"\n 1. Login";
    cout<<"\n 2. Sign-up";
    cout<<"\n 3. Forget Password";
    cout<<"\n 4. Exit";
    cout<<"\n Enter Your Choice ::";
    cin>>choice;

    switch(choice){
         case '1':
            obj.login();
        break;
        case '2':
            obj.signup();
        break;
        case '3':
            obj.forgot();
        break;
        case '4':
            return 0;
        break;
        default:
        cout <<"Invalid Selection.......";
        


    }
   
}

void temp :: signup(){
    cin.ignore();
    cout<<"\nEnter Your User Name :: ";
    getline(cin,userName);
    cout<<"\nEnter Your Email Address :: ";
    getline(cin,Email);
    cout<<"\nEnter Your Password :: ";
    getline(cin,Password);

    file.open("loginData.text", ios :: out| ios :: app);
    file<<userName<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}

void temp :: login(){
    string searchName,searchPass;
    cin.ignore();
    cout<<"----------LOGIN----------"<<endl;
    cout<<"Enter Your UserName :: \n";
    getline(cin,searchName);
    cout<<"Enter Your Password :: \n";
    getline(cin,searchPass);

    file.open("loginData.text",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof()){
        if(userName==searchName){
            if(Password==searchPass){
                cout<<"\nAccount Login Sucessfully......!";
                cout<<"\nUsername ::"<<userName<<endl;
                cout<<"\nEmail ::"<<Email<<endl;
            }else{
                cout<<"Password is Incorrect....!";
            }          
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    }
    file.close();

}
void temp :: forgot(){
    cin.ignore();
    cout<<"\nEnter Your Name :: ";
    getline(cin,searchName);
    cout<<"\nEnter Your Email :: ";
    getline(cin,searchEmail);

    file.open("loginData.text",ios::in );
    // getline(file,userName,'*');
    // getline(file,Email,'*');
    // getline(file,Password,'\n');
    bool found = false;
    while(getline(file,userName,'*')&&
        getline(file,Email,'*')&&
        getline(file,Password,'\n')){
       
        if(userName==searchName&&Email==searchEmail){
            
            cout<<"\nAccount Found...."<<endl;
            cout<<"\nYour Password :: "<<Password<<endl;
            found = true;
        }
        // else{
        //     cout<<"not found....";
        // }
        

        //     }else{
        //         cout<<"Not Found....\n";
        //     }
        // }else{
        //     cout<<"\nNot Found....\n";
        // }
        // getline(file,userName,'*');
        // getline(file,Email,'*');
        // getline(file,Password,'\n');

    }
    if(!found){
        cout<<"\n Account not Found ";

    }

    file.close();
    
}