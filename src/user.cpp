#include<iostream>
#include<pqxx/pqxx>
#include<string>
#include<ctime>
#include"user.h"
//#include"book.h"


using namespace std;
using namespace pqxx;


connection C("dbname = postgres user = postgres password = nithish2402 \
      hostaddr = 127.0.0.1 port = 5432");

void user::start_user(){
	cout<<"\nEnter your option\n1:Existing User\n2:New User\n";
	int user_option;
	cin>>user_option;
	if(user_option==1){
		add_user();
	}
	else if(user_option==2){
		print_user();
	}
	else{
		cout<<"\nChoose a valid option\n";
		start_user();
	}
}

void user::print_user(){
	cout<<"\n1:Borrow book\n2:Return Book\n3:View Details\nAny other key to end";
	int user_choice;
	cin>>user_choice;
	if(user_choice==1){
		borrow_book();
	}
	else if(user_choice==2){
		return_book();
	}
	else if(user_choice==3){
		view_user();
	}
	else{
		cout<<"\nThank you for using Library Services\n";
	}

}
void user::add_user(){
	cout<<"\nEnter user id:";
	cin>>user_id;
	cout<<"\nEnter user name:";
	cin>>user_name;

	char buf[100];
		work W(C);
		snprintf(buf, sizeof(buf), "INSERT INTO USER VALUES(%d,'%s');",user_id,user_name.c_str());
		W.exec(buf);
       	W.commit();
       print_user();

}

void user::borrow_book(){
	cout<<"\nEnter the book ID to borrow:";
	cin>>book_id;
}

void user::return_book(){

}
void user::view_user(){
	cout<<"\nEnter the user ID:";

}
