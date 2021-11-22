#include<iostream>
#include<pqxx/pqxx>
#include<string>
#include<ctime>


using namespace std;
using namespace pqxx;

class user{
public:
	int user_id;
	string user_name;
	string[] all_book;

	int n;

}