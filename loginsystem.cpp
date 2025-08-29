#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"       Welcome To Thr LOGIN Page       \n\n\n";
    cout<<"              MENU              \n\n\n";
    cout<<"Press 1 for LOGIN                    "<<endl;
    cout<<"Press 2 to REGISTER                  "<<endl;
    cout<<"Press 3 if you FORGOT your password  "<<endl;
    cout<<"Press 4 to EXIT                      "<<endl;
    cout<<"Please enter your choice:"<<endl;
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout<<"\t\t\t Thankyou!  \n\n";
            break;

        defalut:
            system("cls");
            cout<<"\t\t\t  Please select from the options given below \n"<<endl;
            main();
    }    
}


void login(){
    int count;
    string userId, password, id, pass;
    system("cls");
    cout<<"Please enter the username and password :"<<endl;
    cout<<"USERNAME :\n";
    cin>>userId;
    cout<<"PASSWORD :\n";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass){
        if(id==userId && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1){
        cout<<userId<<"\n Your LOGIN is successful \n Thanks for logging in !\n";
        main();
    }else{
        cout<<"\n Login Error \n Please check your username and password\n";
        main();
    }
}

void registration(){
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout<<"\t\t\t Enter the username:";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password:";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\t\t\t Registration is Successful !\n\n\n";
    main();

}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries\n";
    cout<<"Press 1 to search your id bh username "<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t Enter your choice:";
    cin>>option;
    switch(option){
        case 1:{
            int count=0;
            string suserId, sid, spass;
            cout<<"\t\t\t Enter the username which your remembered:";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sid>>spass){
                if(sid==suserId){
                    count=1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n Your account is found!\n";
                cout<<"\n\n Your password is:"<<spass;
                main();
            }
            break;
        }

        case 2:{
            main();
        }

        default:
            cout<<"\t\t\t Wrong choice! Please try again"<<endl;
            forgot();
    }
}