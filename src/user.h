#pragma once
#include<pqxx/pqxx>
#include<string>
#include<ctime>
#include "book.h"



using namespace std;
using namespace pqxx;

class user : public book{
public:
	int user_id;
	string user_name;
	string all_book[5];

	void add_user();
	void print_user();
	void borrow_book();
	void return_book();
	void view_user();
	void start_user();

};
