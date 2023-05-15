 void login(){                                    // takes the username and password as input using the cin statement

      cout << "Enter The Username : ";
      cin >> id;                                          //initialized globally in gikipay function.

      cout << "Enter The Password : ";
      cin >> password;                                 //initialized globally in gikipay function.
   }
   
   
   
	 int verify(){ //checks the username and password based on the choice variable
      char a;
      if (choice == 1) {
         
		 if ((strcmp(id, "admin") == 0 && strcmp(password, "admin") == 0)) { 
		     //strcmp(id, "admin") compares the string stored in the id variable with the string "admin". The strcmp() function returns 0 if the two strings are identical.
         //In summary, the condition if ((strcmp(id, "admin") == 0 && strcmp(password, "admin") == 0)) checks if both the username and password are "admin". If they are, the condition evaluates to true, indicating that the login is successful.





            cout << "You Have Successfully Logged In : " << '"' << id << '"' << endl;
            time_t t;
            time( & t);

            cout << "Logged In Time : " << ctime( & t);

            cout << "Press any key to continue .... ";
            getch();          
            return 1;
         } else
            return 0;
      } else if (choice == 2) {
         if (strcmp(id, "user") == 0 && strcmp(password, "user") == 0)
         //checks if both the username and password are "user". If they are, the condition evaluates to true, indicating that the login is successful.{

            cout << "You Have Successfully Logged In : " << '"' << id << '"' << endl;
            time_t t;
            time( & t);

            cout << "Logged In Time : " << ctime( & t);

            cout << "Press any key to continue .... ";
            getch();
            return 1;
         } else
            return 0;
      }
      return 0;
   }




   void about(){ //function displays some information about the bank management system and the team members. 
                //It then waits for a keypress to return to the main menu
   	
   	  cout << " ABOUT US ";
	  cout<<endl;
	  
      cout << "It is a  Bank Management System Project for our 2nd Semester based on C++ programming language.";
      cout<<endl;
      	
      cout << "Members of Our Team: ";
      cout<<endl;
      	
      	
      	
      cout << "[1] . Saba Hareem Shaikh";
      cout<<endl;
      	
      cout << "[2] . Syed Mojiz Zaidi";
      cout<<endl;
      	
      cout<<"[3] .  Dua Tahir";
      cout<<endl;
      
      cout<<"[4] . Muhammad Abdullah";
      cout<<endl;
      
      
      cout << "Press any key to return back to main menu. ";
      char z = getch();
      
      if (z == 13) {
         main();
      }
   }
   
   
   
   
   
   
   
   
  

// module for viewing account details
void gikipay::view() {
   int i = 7;
   record rec;
   //read from the file
   ifstream f;
   f.open("record.bin", ios::in | ios::binary); //open file for read only

   cout << " CUSTOMERS LIST ";
   cout << endl;

   /* f.read() = for reading binary data
    This reads the contents of a class variable from the file and stores it in the variable rec.
    The f.read() function will keep returning 1 until there are records in the file.
    As soon as the EOF is encountered f.read() will return a value less than 1 and
    the condition in the while loop become false and the control comes out of the while loop.

   
   
/*f: It is an object of std::ifstream class, which is used to read data from a file.
.read(): It is a member function of std::ifstream class, which is used to read a specified number 
of bytes from a file and store them in a memory buffer.

reinterpret_cast<char*>(&rec): It is a type-casting operator that casts a pointer to an object of type 
record to a pointer to a char type. 

This is done because the .read() function expects a char* type buffer as its first argument.

sizeof(rec): It is an operator that returns the size of the record object in bytes. 
This is the number of bytes that will be read from the file.

while: It is a loop construct that repeatedly executes a block of statements as long as the specified condition is true.

f.read(...) inside the while loop: This reads a chunk of binary data from the file into the rec object, 

then returns true if the read operation was successful, 
and false if the end of file (EOF) has been reached.

Therefore, the while loop will continue to read data from the file until it reaches the end of file, storing each record object in the rec variable.
	
 while (f.read(reinterpret_cast < char * > ( & rec), sizeof(rec)))
*/
   
   while (f.read(reinterpret_cast < char * > ( & rec), sizeof(rec)))
   //In summary, the while loop iterates over the file, reading chunks of binary data into the rec object using the read() function.
   //The loop continues until the end of the file is reached, processing each record read from the file.{

      cout << "A/C No:";
      cout << endl;
      cout << rec.account;
      cout << endl;

      cout << "Account Name:";
      cout << endl;
      cout << rec.name;
      cout << endl;

      cout << "UserID: ";

      for (int r = 0; r < 10; r++) {
         cout << (int) rec.UserID[r];
      }
      cout << endl;

      cout << "Email Address:";
      cout << endl;
      cout << rec.email;
      cout << endl;

      cout << "Phone No.:";
      cout << endl;
      cout << rec.phone;
      cout << endl;

      cout << "Balance:";
      cout << endl;
      cout << rec.balance << "$";
      cout << endl;
      
   }
   
   f.close();
   int x;
   cout << "Press [Enter] to return back to main menu. ";
   x = getch();
   if (x == 13) {                            // 13 = '\r' i.e carriage return
      main();
   } else
      view();
};



//module to check whether the entered account is in the database or not
int ca(int a) {
   record rec;
   //read binary
   ifstream f;
   f.open("record.bin", ios::in | ios::binary);
   while (!f.eof()) {
      f.read(reinterpret_cast < char * > ( & rec), sizeof(rec)); //whatever &rec is treat it as char *
      //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

      if (a == rec.account) {
         f.close();
         return 1;
      }
   }
   f.close();
   return 0;}
