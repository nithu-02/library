
#pragma once
#include<string>
//#include<ctime>


using namespace std;



class book 
{
public:
	
	int book_id;
	int cost;
	string book_name;
	string author_name;
	string borrow_date;
	string due_date;
	void add_book();
	void remove_book();
	void modify_book();
	void print_option();
	void view_book();


	
};
