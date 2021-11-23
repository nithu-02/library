#include<iostream>
#include<pqxx/pqxx>
#include<string>

#include"book.h"
#include "user.h"



using namespace std;
using namespace pqxx;

bool password_checker(string str){
	string pass = "admin@123";
	if(str==pass){
		return true;
	}
	
	return false;
}
void print_choice() {
		int choice;
		cout<<"\nChoose your role\n1:Admin\n2:User\nAny other key to exit"<<endl;
		cin>> choice;
		if(choice==1){
			string password;
			cout<<"\nEnter the password:";
			cin>>password;
			if(password_checker(password)){
					book obj;
					obj.print_option();
			}
			else{
				cout<<"Password is Incorrect try again";
				print_choice();
			}

		}
		else if(choice==2){
			user obja;
			obja.start_user();

		}
		else{
			cout<<"\n****Thank you for your time****\n"<<endl;
		}
}

int main(int argc, char* argv[]){

       try {
      connection C("dbname = postgres user = postgres password = nithish2402 \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         
      }
      //C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
     
   }
      /*if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }*/
	cout<<"Welcome to the Library\n";
	print_choice();
	return 0;
}
