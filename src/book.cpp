/*#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED*/
//#include"user.h"
#include"book.h"
#include<iostream>
#include<pqxx/pqxx>
#include<string>
using namespace std;
using namespace pqxx;

// try {
      //char buf[100];
      connection C("dbname = postgres user = postgres password = nithish2402 \
      hostaddr = 127.0.0.1 port = 5432");
      /*if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         //return 1;
      }*/
void book::print_option(){
		cout<<"\nEnter the option\n";
		cout<<"\n1:Add book\n2:Remove book\n3:Modify book\n4:View all book\nAny other key to end the Program\n";
		int option;
		cin>>option;
		if(option==1){
			add_book();
		}
		else if(option==2){
			remove_book();
		}
		else if(option==3){
			modify_book();
		}
		else if(option==4){
			view_book();
		}
		else{
			cout<<"\n****Thank you for your time****\n"<<endl;
		}
	}

	void book::add_book(){
		
		cout<<"\nEnter the Book ID:";
		cin>>book_id;
		cout<<"\nEnter the renting cost of the book per day:";
		cin>>cost;
		cout<<"\nEnter the name of the book:";
		cin>> book_name;
		cout<<"\nEnter the Author name of the book:";
		cin>>author_name;

		cout<<book_id<<book_name<<cost<<author_name<<"\n";
		char buf[100];
		work W(C);
		snprintf(buf, sizeof(buf), "INSERT INTO BOOK VALUES(%d, %d, '%s', '%s');",book_id,cost,book_name.c_str(),author_name.c_str());
		W.exec(buf);
       	W.commit();
       	print_option();
	}
	void book::remove_book(){
		
		cout<<"\nEnter the Book ID to remove:";
		cin>>book_id;
		work W(C);
		char buf[100];
		snprintf(buf, sizeof(buf), "DELETE FROM BOOK WHERE ID = %d;", book_id);
      	W.exec(buf);
       	W.commit();
       	print_option();
	}
	void book::modify_book(){
		cout<<"\nEnter the Book ID to Modify:";
		cin>>book_id;
		cout<<"\nEnter the option to Modify";
		cout<<"\n1:Book Name\n2:Author Name\n3:Cost of Book:";
		int modify_option;
		cin>>modify_option;
		if(modify_option==1){
			cout<<"\n1:Book Nam\n2:Aut";
		}
		else if(modify_option==2){
			cout<<"\n1:Book Nae\n2:Aut";
		}
		else if(modify_option==3){
			cout<<"\n1:Book Nme\n2:Aut";
		}
		else{
			print_option();
		}
	}
	void book::view_book(){
		
		string sql = "SELECT * from BOOK";
		nontransaction N(C);
      	result R( N.exec( sql ));
      
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
         cout << "BOOK ID = " << c[0].as<int>() << endl;
         cout << "BOOK COST/DAY = " << c[1].as<int>() << endl;
         cout << "BOOK NAME = " << c[2].as<string>() << endl;
         cout << "AUTHOR NAME = " << c[3].as<string>() << endl;
         //cout << "BORROW DATE = " << c[4].as<string>() << endl;
         //cout << "DUE DATE = " <<c[5].as<string>()<<endl;
         cout<<"\n";
      }
	}
	