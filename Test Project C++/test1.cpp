#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>                 
#include <fstream>
#include <algorithm>      

using namespace std;

class ABook{						//kailangan daw gumamit ng class. Search nyo na din kung para saan ang class tapos pag-usapan nalang natin

public:								//laging magkasama ang class at public (pati private, pero di tayo gagamit nun dito)
    ABook()
      {
         count=0;
      }

   void AddEntry();
   void DispAll();
   void DispEntry(int i);
   void DeleteEntry();                           
   void SearchLast();				//Di pa napapalabas yung NOT FOUND!
   void SearchFirst();            
   void SearchEmailAddress();     
   void SearchPhoneNum();
   // void EditContact();           //  Wala pa tayo neto.

   int Menu();

   struct EntryStruct				// Pwede ata gawin natin tong input file, prang may mastotorage sa "txt. file" gagamit ng notepad
   {
      char FirstName[15];
      char LastName[15];
      char Birthday[15];
      char PhoneNum[15];
      char Email[15];
   };

   EntryStruct entries[100];
   int count;
};


void ABook::AddEntry()
{

   cout << "Enter First Name: ";
   ofstream a_file ( "contacts.txt", ios::app );			//Babasahin niya yung contacts.txt na file
   cin >> entries[count].FirstName;
   a_file << entries[count].FirstName << "\n";				// Ilalagay nya yung input sa .txt file
cin.clear();
cin.sync();
   cout << "Enter Last Name: ";
   cin >> entries[count].LastName;
   a_file << entries[count].LastName << "\n";				//ganun din dito
cin.clear();
cin.sync();
   cout << "Enter Date of Birth: ";
   cin >> entries[count].Birthday;
   a_file << entries[count].Birthday << "\n";
cin.clear();
cin.sync();
    cout << "Enter Phone Number: ";
   cin >> entries[count].PhoneNum;
   a_file << entries[count].PhoneNum << "\n";
cin.clear();
cin.sync();
   cout << "Enter Email: ";
   cin >> entries[count].Email;
   a_file << entries[count].Email << "\n";
   a_file.close();

   ++count;                                                
}



void ABook::DispEntry(int i)
{   
ifstream a_file ( "contacts.txt" );
	a_file>> entries[i].FirstName;										// di ko pa sure kung gumagana
	a_file>> entries[i].LastName; 
	a_file>> entries[i].Birthday; 
	a_file>> entries[i].PhoneNum; 
	a_file>> entries[i].Email;              
   cout << "First name : " << entries[i].FirstName << endl;
   cout << "Last name : " << entries[i].LastName << endl;
   cout << "Date of birth : " << entries[i].Birthday << endl;
   cout << "Phone number : " << entries[i].PhoneNum << endl;
   cout << "Email: " << entries[i].Email << endl;
}

void ABook::DispAll()
{
   cout << "Number of Entries : " << count << endl;

   for(int i = 0;i < count;++i)
   	  {cout << endl;
      DispEntry(i); }
}

void ABook::DeleteEntry()     // KULANG PA TONG PART NA TO! (Christer: Di ko mabura yung laman ng .txt file, tsaka yung code mo Ry, di naman nag-dedelete ng entry)
{
 	char FirstName [32];
  cout << "Enter the first name of the contact you want to be deleted: ";
   cin >> FirstName;
   cout << endl;

   for(int i = 0;i < count;++i)
   {
      if(strcmp(FirstName, entries[i].FirstName) == 0)
      {
      	
         cout << "Deleted";
		 cout << endl;
		 }
  
                                                 
}
}
								 // SIMULA DITO, KUlANG LANG KUNG MSASABING NOT FOUND NA ISAHAN.
								 
void ABook::SearchLast ()
{
   char LastName[32];
   cout << "Enter Last Name : ";
   cin >> LastName;
   cout << endl;

   for(int i = 0;i < count;++i)
   {
      if(strcmp(LastName, entries[i].LastName) == 0)    	// NAGLAGAY AKO DITO NG ELSE IF, tapos baliktad n "!=0" kaso kapag marami ng na-add contact.
      {														//MMay lalabas na found, kaso may lumalabas din na not found"
      														// AKo nalang bahala dito. - RY
         cout << "Found " << endl ;
         DispEntry(i);
         cout << endl;
      }

   }
}

void ABook::SearchFirst()
{
   char FirstName[32];
   cout << "Enter First Name : ";
   cin >> FirstName;
   cout << endl;
   
   for(int i = 0;i < count;++i)
   {
      if(strcmp(FirstName, entries[i].FirstName) == 0)
      {
         cout << "Found " << endl ;
         DispEntry(i);
         cout << endl;
      }
         else if(strcmp(FirstName, entries[i].FirstName) != 0)
       {
         cout << "Not Found" << endl ;
         cout << endl;
      }
   }
}

void ABook::SearchEmailAddress()
{
   char Email[32];
   cout << "Enter Email : ";
   cin >> Email;
   cout << endl;

   for(int i = 0;i < count;++i)
   {
      if(strcmp(Email, entries[i].Email) == 0)
      {
         cout << "Found " << endl ;
         DispEntry(i);
         cout << endl;
      }
         else if(strcmp(Email, entries[i].Email) != 0)
       {
         cout << "Not Found" << endl ;
         cout << endl;
      }
   }
}

void ABook::SearchPhoneNum()
{
   char PhoneNum[32];
   cout << "Enter Phone Number : ";
   cin >> PhoneNum;
   cout << endl;

   for(int i = 0;i < count;++i)
   {
      if(strcmp(PhoneNum, entries[i].PhoneNum) == 0)
      {
         cout << "Found " << endl ;
         DispEntry(i);
         cout << endl;
      }
         else if(strcmp(PhoneNum, entries[i].PhoneNum) != 0)
       {
         cout << "Not Found" << endl ;
         cout << endl;
      }
   }
}


ABook AddressBook;

int Menu()
{
   int num, choice;
   bool BoolQuit = false;

   while(BoolQuit == false)
   {                     

      cout << "Address Book Menu" << endl;
      cout << "(1) Add Contact" << endl;
      cout << "(2) Edit Contact" << endl;
      cout << "(3) Delete Contact" << endl;
      cout << "(4) View Contacts" << endl;
      cout << "(5) Search Address Book" << endl;
      cout << "(6) Exit" << endl;
      cout << endl;

        cout << "Please enter your selection (1-6) and press enter: ";      
      cin >> num;
      cout << endl;

      if (num == 1)
         AddressBook.AddEntry();
      /*else if (num == 2)									//di pa pwedeng gamitin kasi kulang pa
         AddressBook.EditContact();*/
      else if (num == 3)
         AddressBook.DeleteEntry();
		else if (num == 4)
         AddressBook.DispAll();
      else if (num == 5)
      {
	  	cout << "Search the Address Book : " << endl;
      	cout << "(1) By Last Name" << endl;
      	cout << "(2) By First Name" << endl;
      	cout << "(3) By Email Address" << endl;
      	cout << "(4) By Phone Number" << endl;
      	cout << endl;
      		cout << "Please enter how do you want to search: ";
      		cin >> choice;
      		cout << endl;
      		
      	switch (choice)
      	 {
      	 	case 1: AddressBook.SearchLast();
      	 	break;
      	 	case 2: AddressBook.SearchFirst();
      	 	break;
      	 	case 3: AddressBook.SearchEmailAddress();
      	 	break;
      	 	case 4: AddressBook.SearchPhoneNum();
      	 	break;
		   }
		}
      else if (num == 6)
         BoolQuit = true  ;
      else
         cout << "Please enter a number (1-6) and press enter: " << endl;

      cout << endl;                                                            
   }

   return 0;
}

int main (){
   Menu();
	
   return 0;
}
