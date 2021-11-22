#include <iostream>
#include <pqxx/pqxx> 
#include <string>


using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
   
   string sql;
   try {
      char buf[100];
      connection C("dbname = postgres user = postgres password = nithish2402 \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      work W(C);
      

       const char *insert_sql = "INSERT INTO BOOK VALUES (1111, 20, true,  \'HELLO WORLD\');";
       W.exec(insert_sql);
     /* int n;
      cout<<"enter";
      cin>>n;
      snprintf(buf, sizeof(buf), "DELETE FROM BOOK WHERE ID = %d", n);
      W.exec(buf);
       W.commit();
*/
       cout << "Insertion in table was successful"<<endl;

     // C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}