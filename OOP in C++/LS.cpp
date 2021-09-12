#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
void ClearScreen()
{
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

class User
{
public:
	std::string firstname;
	std::string lastname;
	int count;
  	int count1;
	virtual std::string position()
	{
		return "guest";
	};
	std::string fullname()
	{
		return firstname + " " + lastname;
	};
};

class Cashier : public User
{
public:
	std::string employee_id;
	std::string password;
	Cashier(std::string fn, std::string ln, std::string id, std::string pw)
	{
		this->firstname = fn;
		this->lastname = ln;
		this->employee_id = id;
		this->password = pw;
	};

	std::string position()
	{	
		time_t current = time(0);
	  	tm *ltm = localtime(&current);
		ofstream a_file ( "LoginL.txt", ios::app );
		a_file << "Cashier\t\t\t\t"<<ltm->tm_mon<<"/"<<ltm->tm_mday<<"/"<<1900 + ltm->tm_year<<"    "<<ltm->tm_hour<<":"<<ltm->tm_min<<endl;
		a_file.close();
		return "cashier";
		
	};
};
class Admin : public User
{
public:
	std::string employee_id;
	std::string password;
	Admin(std::string fn, std::string ln, std::string id, std::string pw)
	{
		this->firstname = fn;
		this->lastname = ln;
		this->employee_id = id;
		this->password = pw;
	};

	std::string position()
	{
		time_t current = time(0);
	  	tm *ltm = localtime(&current);
		ofstream a_file ( "LoginL.txt", ios::app );
		a_file << "Admin\t\t\t\t"<<ltm->tm_mon<<"/"<<ltm->tm_mday<<"/"<<1900 + ltm->tm_year<<"    "<<ltm->tm_hour<<":"<<ltm->tm_min<<endl;
		a_file.close();
		return "Admin";
		
	};
};
class User_logs : public User
{
public:
	std::string employee_id;
	std::string password;
	User_logs(std::string fn, std::string ln, std::string id, std::string pw)
	{
		this->firstname = fn;
		this->lastname = ln;
		this->employee_id = id;
		this->password = pw;
	};

	std::string position()
	{
		
		return "User_logs";
		
	};
};
class Head{
public:
	static std::string Header()
	{
		return "   MCJOLLIBEE \n Lipa city, Batangas\n";
	};
	static std::string Header(User user)
	{
		return "   MCJOLLIBEE \n Lipa city, Batangas\n" + std::string(" welcome " + user.position() + "\n\n\n");
	};
	static std::string Header(Cashier cashier){
	return "   MCJOLLIBEE \n Lipa city, Batangas\n" + std::string(" welcome " + cashier.position() + "\n\n\n");
	};
	static std::string Header(Admin admin){
	return "   MCJOLLIBEE \n Lipa city, Batangas\n" + std::string(" welcome " + admin.position() + "\n\n\n");
	};

	
	
	
};
Cashier create_user()
{
	
	std::string password;
		string line;
		string text[1];
			ifstream offile;
			int counter1 ;
			offile.open("Cashier.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					text[counter1] = line;
					counter1++;
					
				}
			}
			
			offile.close();
	Cashier cashier("john", "doe", text[0], text[0]);
	while (true)
	{
		std::cout << "\nenter password: ";
		std::cin >> password;
		if (password == cashier.password){
				break;
				
		}
		
		std::cout << "\nwrong password\n";
		Sleep(3000);
	}

		return cashier;
	

};
Admin create_user1(){
	std::string password;
		string line;
		string text[1];
			ifstream offile;
			int counter1 ;
			offile.open("Admin.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					text[counter1] = line;
					counter1++;
					
				}
			}
			
			offile.close();
	Admin admin("Admin", "Admin", text[0],text[0]);
	while (true)
	{
		std::cout << "\nenter password: ";
		std::cin >> password;
		if (password == admin.password){	
				break;		
		}
		std::cout << "\nwrong password\n";
		Sleep(3000);
	}
		
		return admin;
};


class Order
{
public:
	std::string foodname;
	double price;
	int quantity;
	Order(std::string fn, int price, int quantity)
	{
		this->foodname = fn;
		this->price = price;
		this->quantity = quantity;
	};
	bool operator==(Order ordr)
	{
		if (ordr.foodname == this->foodname)
			return true;
		return false;
	}
};

class Orders
{
	std::string OR;
	double cash;
	double change;
	Cashier *cashier;
	Admin *admin;
	
public:
	static Order bfs;
	static Order css;
	static Order crs;
	static Order brs;
	static Order frs;
	static std::vector<Order> mymenu;
	std::vector<Order> orders;

	void assign_user(Cashier cashr)
	{
		cashier = &cashr;
	};
	void assign_user1(Admin admn)
	{
		admin = &admn;
	};
	void insert_order(Order order)
	{
		for (int i = 0; i < orders.size(); i++)
		{
			if (orders[i] == order)
			{
				orders[i].quantity += 1;
				return;
			}
		}
		order.quantity = 1;
		orders.push_back(order);
	};
	
	int toInt(string str){
	 int num = 0,size = str.size();
				  
				  for(int i = 0 ,k = size; i < size ; i++){
				  	num+=(str[--k]-'0')*pow(10,i);
				  	
				  }
				  return num;
	};
	sett();
	double compute_total()
	{
		double accumulator = 0;
		for (Order order : orders)
		{
			accumulator += (order.price * order.quantity);
		}
		return accumulator;
	};
	void display_menu()
	{
		
		for (int i = 0; i < mymenu.size(); i++)
		{
			std::cout << " \n [" << i + 1 << "] "
					  << mymenu[i].foodname << " " << mymenu[i].price;
		}
		std::cout << "\n\n";
	};
	void display_orders()
	{
		for (int i = 0; i < orders.size(); i++)
		{
			std::cout << " \norder number: " << i + 1 << "   "
					  << orders[i].foodname << " " << orders[i].price << "      quantity: " << orders[i].quantity << "\n";
		}
	}
	//code this
	void stocks_menu(){
	int k;
		do{
		
			ClearScreen();
			int exit = 0;
			std::cout << Head::Header(*admin);
			std::cout << "[0]Add stocks \n[1]View stocks \n[2]Modify stocks\n[3]Exit \n\t\t\tEnter[0/1/2/3]:";
			std::cin >> k;
			if(k == 0){
				do{	
				system("cls");
				update_stocks();	
				string any;
				std::cout << "\ninput anything to exit:";
				std::cin >> any;
				exit = 1;
				}while(exit != 1);
			}
			else if(k == 1){
					do{	
				system("cls");
				view_stocks();	
				string any;
				std::cout << "\ninput anything to exit:";
				std::cin >> any;
				exit = 1;
				}while(exit != 1);
			}else if(k == 2){
				do{	
				system("cls");
				update_price();	
				string any;
				std::cout << "\ninput anything to exit:";
				std::cin >> any;
				exit = 1;
				}while(exit != 1);
			}
			
		
		}while(k != 3);
	}
	void admin_menu(){
			int k ;
			do
			{
			ClearScreen();
			std::cout << Head::Header(*admin);
			std::cout << "[1]Generate user logs \n[2]Generate Report \n[3]Manage Inventory\n[4]Change Password\n[0]exit \n\t\t\tEnter[1/2/3/4/0]:";
			std::cin >> k;
			int exit = 0;
			try{
				if(k == 1){
				do{
					system("cls");
					string any;
					logs();
					std::cout << "input anything to exit:";
					std::cin >> any;
					exit = 1;
				}while(exit != 1);
			}else if(k == 2){
				do{
				system("cls");
				report_menu();
				exit = 1;
				}while(exit != 1);
			}else if(k == 3){
				do{		
				system("cls");
				stocks_menu();			
				exit = 1;
				}while(exit != 1);
			}else if(k==4){
				do{		
				system("cls");
				Pasword_menu();
				exit = 1;
				}while(exit != 1);
			}
			}
		
			catch (...)
			{
			}
	}while(k != 0);
	system("cls");
}
	void logs(){
		cout << "   MCJOLLIBEE \n Lipa city, Batangas\n" + std::string("    User logs\n\n\n");
		std::string line;
		std::string text[1000];
			ifstream offile;
			int counter1 ;
			offile.open("LoginL.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					text[counter1] = line;
					counter1++;
					
				}
			}
			offile.close();
			for(int j = 0; j < counter1; j++){
				cout << text[j] << endl;
			
			}
			
	}
	void report_menu(){
			int k;
 			do{	
 			
			ClearScreen();
			std::cout << Head::Header(*admin);
			int exit = 0;
			std::cout << "[1]Sales Report \n[2]Inventory Report \n[0]exit \n\t\t\tEnter[1/2/0]:";
			std::cin >> k;
			if(k == 1){
			do{
					system("cls");
					string any;
					report();
					std::cout << "\ninput anything to exit:";
					std::cin >> any;
					exit = 1;
				}while(exit != 1);
			}if(k == 2){
			do{
					system("cls");
					string any;
					Inventory_report();
					std::cout << "\ninput anything to exit:";
					std::cin >> any;
					exit = 1;
				}while(exit != 1);
		}
	}while(k != 0);
}
	void report(){
		cout << "   MCJOLLIBEE \n Lipa city, Batangas\n" + std::string("    Sales Report\n\n\n");
		std::string line;
		std::string text[1000];
			ifstream offile;
			int counter1 ;
			offile.open("sales.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					text[counter1] = line;
					counter1++;
					
				}
			}
			offile.close();
			for(int j = 0; j < counter1; j++){
				cout << text[j] << endl;
			
			}
			
	
	}
	void Inventory_report(){
		cout << "   MCJOLLIBEE \n Lipa city, Batangas\n" + std::string("    Inventory Report\n\n\n");
		std::string line;
		std::string text[1000];
			ifstream offile;
			int counter1 ;
			offile.open("Inventory_report.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					text[counter1] = line;
					counter1++;
					
				}
			}
			offile.close();
			for(int j = 0; j < counter1; j++){
				cout << text[j] << endl;
			
			}
			string x;
			cout << "Reorder Point of initial count:Generate?[Y/N]:";
			cin >> x;
			if(x == "Y"||x == "y"){
				reorder();
			}
	}
	void reorder(){
	cout << "   MCJOLLIBEE \n Lipa city, Batangas\n" + std::string("    Items for Reorder\n\n\n");
		string line;
	 ifstream offile;
	 
	 string getcontent[1000];
	 string Input_Id,qwe,asd;
   	 int count1,count2;
   	 count2 = count1;
   	 system("cls");
			
			offile.open("Inventory_report.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					getcontent[count1] = line;
					count1++;
					
				}
			}
			offile.close();
			cout << "   MCJOLLIBEE \n Lipa city, Batangas\n" + std::string(" Items for Reorder\n\n\n");
			cout << "ITEMS\t\t\t\t\t\t\tNO OR ORDER"<<endl;
			for(int i =0; i <= 5; i++){
			for(int j = 0; j < count1; j++){
				if(getcontent[j] == "ID:"+to_string(i)){
				double sub,sub2,solve;
				
				sub = toInt(getcontent[j+4].substr(8,14))*.25;
				sub2 = toInt(getcontent[j+5].substr(7,12));
				if(sub2 <= sub){
					solve = 	 toInt(getcontent[j+4].substr(8,14))- sub2;
					cout << "["<< i << "]" << getcontent[j+1].substr(9,40) <<"\t\t\t\t\t" << solve << endl;
				}
				
			  }}}
	}
	void update_stocks(){
	string line;
	 ifstream offile;
	 
	 string getcontent[1000];
	 string Input_Id,qwe,asd;
   	 cout << "Input the ID of the item you want to update:";
   	 cin >>Input_Id;
   	 qwe = "ID:" + Input_Id;
   	 int count1,count2;
   	 count2 = count1;
   	 system("cls");
			
			offile.open("Inventory.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					getcontent[count1] = line;
					count1++;
					
				}
			}
			offile.close();
				
			for(int j = 0; j < count1; j++){
			
			  if(getcontent[j] == qwe){
			  	cout << "\ncurrent item";
				for (int i = 0 ; i < 7; i++){
					cout <<"\n"<<getcontent[j+(i-1)];
				}
				int sub;
				cout << "\nInput the quantity update of the item:";
				cin >> asd;
				getcontent[j+4]=  "Quantity:"+asd;
				ofstream a_file ("Inventory.txt");
				for(int j = 0; j < count1-1; j++){
				
				if(j == count1 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				inChange(Input_Id,asd);
				a_file << "================================";
				cout << "\nUpdated succesfully" << endl;
					cout << "\nupdated item";
				for (int i = 0 ; i < 7; i++){
					cout <<"\n"<<getcontent[j+(i-1)];
				}
				a_file.close();
				
				break;
			  }	
			
		
				
			}
		
				
					
				
				
				
			
		};	
		void view_stocks(){
		string line, text[1000];
		ifstream offile;
		int counter1 = 0;
		offile.open("Inventory.txt");
		if (offile.is_open()){
			while(!offile.eof()){
				getline(offile,line);
				text[counter1] = line;
				counter1++;
					
				}
			}
			offile.close();
			for(int j = 0; j < counter1; j++){
				cout << text[j] << endl;
				
				
			}
		}
	void update_price(){
	 string line;
	 ifstream offile;
	 
	 string getcontent[1000];
	 string Input_Id,qwe,asd;
   	 cout << "Input the ID of the item you want to update:";
   	 cin >>Input_Id;
   	 qwe = "ID:" + Input_Id;
   	 int count1,count2;
   	 count2 = count1;
   	 
			
			offile.open("Inventory.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					getcontent[count1] = line;
					count1++;
					
				}
			}
			offile.close();
			
			for(int j = 0; j < count1; j++){
				
			  if(getcontent[j] == qwe){
			  	cout << "\ncurrent item";
				for (int i = 0 ; i < 7; i++){
					cout <<"\n"<<getcontent[j+(i-1)];
				}
				
				cout << "Input the price update of the item:";
				cin >> asd;
				getcontent[j+3] =  "Price:"+asd;
				
				ofstream a_file ("Inventory.txt");
				for(int j = 0; j < count1-1; j++){
				
				if(j == count1 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "=================";
				cout << "Updated succesfully" << endl;
				cout << "\nupdated item";
				for (int i = 0 ; i < 7; i++){
					cout <<"\n"<<getcontent[j+(i-1)];
				}
				
				a_file.close();
				break;
			  }	
			
		
				
			}
		
				
					
				
				
				
			
		};
	void Pasword_menu(){
			int k;
			do{	
 			string pass;
			ClearScreen();
			std::cout << Head::Header(*admin);
			int exit = 0;
			std::cout << "[1]Admin \n[2]Cashier \n[0]exit \n\t\t\tEnter[1/2/0]:";
			std::cin >> k;
			if(k == 1){
				do{
					ClearScreen();
					cout <<"Enter the new password:";
					cin  >>pass;
					std::ofstream outfile("Admin.txt");
					outfile << pass;
					outfile.close();
					exit = 1;
				}while(exit != 1);
			}if(k == 2){
				do{
					ClearScreen();
					cout <<"Enter the new password:";
					cin  >>pass;
					std::ofstream outfile("Cashier.txt");
					outfile << pass;
					outfile.close();
					exit = 1;
				}while(exit != 1);
			}
			}while(k != 0);
	}
		//start for managing stocks
	int inChange(string Input_id,string asd){
		 string line;
	 ifstream offile;
	 
	 string getcontent[1000];
	 string qwe;
   	 cout << "Input the ID of the item you want to update:";
   	 
   	 qwe = "ID:" + Input_id;
   	 int count1,count2;
   	 count2 = count1;
   	 system("cls");
			
			offile.open("Inventory_report.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					getcontent[count1] = line;
					count1++;
					
				}
			}
			offile.close();
				
			for(int j = 0; j < count1; j++){
			
			  	if(getcontent[j] == qwe){
			
				
				
				getcontent[j+5]=  "Actual:" +asd;
				ofstream a_file ("Inventory_report.txt");
				for(int j = 0; j < count1-1; j++){
				
				if(j == count1 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "================================";
				a_file.close();
				break;
			  }	
			
		}
	}
	 int change1(string Input_id,int asd){
	 string line;
	 ifstream offile;
	 
	 string getcontent[1000];
	 string qwe;
   	 cout << "Input the ID of the item you want to update:";
   	 
   	 qwe = "ID:" + Input_id;
   	 int count1,count2;
   	 count2 = count1;
   	 system("cls");
			
			offile.open("Inventory.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					getcontent[count1] = line;
					count1++;
					
				}
			}
			offile.close();
				
			for(int j = 0; j < count1; j++){
			
			 
				int sub = toInt(getcontent[j+5].substr(9,14))- asd;
				getcontent[j+5]=  "Quantity:" + to_string(sub);
				ofstream a_file ("Inventory.txt");
				for(int j = 0; j < count1-1; j++){
				
				if(j == count1 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "================================";
				a_file.close();
				break;
			  }	
			
		
				
			
}
int change2(string Input_id,int asd){
	 string line;
	 ifstream offile;
	 
	 string getcontent[1000];
	 string qwe;
   	 cout << "Input the ID of the item you want to update:";
   	 
   	 qwe = "ID:" + Input_id;
   	 int count1,count2;
   	 count2 = count1;
   	 system("cls");
			
			offile.open("Inventory_report.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					getcontent[count1] = line;
					count1++;
					
				}
			}
			offile.close();
				
			for(int j = 0; j < count1; j++){
			
			  	if(getcontent[j] == qwe){
			
				
				int sub = toInt(getcontent[j+5].substr(7,12))- asd;
				getcontent[j+5]=  "Actual:" + to_string(sub);
				ofstream a_file ("Inventory_report.txt");
				for(int j = 0; j < count1-1; j++){
				
				if(j == count1 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "================================";
				a_file.close();
				break;
			  }	
			
		}
				
			
}
int change3(string Input_id,int asd){
	 string line;
	 ifstream offile;
	 
	 string getcontent[1000];
	 string qwe;
   	 cout << "Input the ID of the item you want to update:";
   	 
   	 qwe = "ID:" + Input_id;
   	 int count1,count2;
   	 count2 = count1;
   	 system("cls");
			
			offile.open("Inventory_report.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					getcontent[count1] = line;
					count1++;
					
				}
			}
			offile.close();
				
			for(int j = 0; j < count1; j++){
			
			 	if(getcontent[j] == qwe){
			
				int sub = toInt(getcontent[j+3].substr(6,10))+asd;
				getcontent[j+3]=  "Sales:" + to_string(sub);
				ofstream a_file ("Inventory_report.txt");
				for(int j = 0; j < count1-1; j++){
				
				if(j == count1 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "================================";
				a_file.close();
				break;
			  }	
			
	}
				
			
}
int change4(string Input_id,int asd){
	 string line;
	 ifstream offile;
	 
	 string getcontent[1000];
	 string qwe;
   	 cout << "Input the ID of the item you want to update:";
   	 
   	 qwe = "ID:" + Input_id;
   	 int count1,count2;
   	 count2 = count1;
   	 system("cls");
			
			offile.open("Inventory_report.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					getcontent[count1] = line;
					count1++;
					
				}
			}
			offile.close();
				
			for(int j = 0; j < count1; j++){
			
			 	if(getcontent[j] == qwe){
				
				int sub = toInt(getcontent[j+2].substr(6,10))+asd;
				getcontent[j+2]=  "Waste:" + to_string(sub);
				ofstream a_file ("Inventory_report.txt");
				for(int j = 0; j < count1-1; j++){
				
				if(j == count1 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "================================";
				a_file.close();
				break;
			  }	
			
	}
				
			
}
//end of managing stocks
	void order_menu()
	{
		int Total,Quantity=0,Quantity1=0,Quantity2=0,Quantity3=0,Quantity4=0,Quantity5=0,Price=0;
		std::string k;
		do
		{
			int quantity1,quantity2,quantity3,quantity4,quantity5;
			ClearScreen();
			std::cout << Head::Header(*cashier);
			display_menu();
			display_orders();
			std::cout << "Total: " << compute_total() << " \n [X] Exit \n [V] void order \n [O] pay total \n"
					  << "\n\n";
			std::cin >> k;
			try
			{
				switch (std::stoi(k))
				{
				case 1:
					insert_order(mymenu[0]);
						Quantity++;
  						Quantity1+=1;
  						quantity1=1;
 				 		change1(k,quantity1);
						change2(k,quantity1);
 
					break;
				case 2:
					insert_order(mymenu[1]);
					Quantity++;
  					Price += 100;
  					Quantity2++;
  					quantity2=1;
  					change1(k,quantity2);
					change2(k,quantity2);
					break;
				case 3:
					insert_order(mymenu[2]);
					Quantity++;
  					Price += 100;
  					Quantity3++;
  					quantity3=1;
  					change1(k,quantity3);
					change2(k,quantity3);
					break;
				case 4:
					insert_order(mymenu[3]);
						Quantity4++;
  						Price += 100;
   						Quantity4++;
 					  	quantity4=1;
   					  	change1(k,quantity4);
   						change2(k,quantity4);
					break;
				case 5:
					insert_order(mymenu[4]);
					Quantity++;
 				 	Price += 100;
 				 	Quantity5++;
 				 	quantity5=1;
				  	change1(k,quantity5);
					change2(k,quantity5);
					break;
				default:
					std::cout << " insert valid value";
					break;
				}
			}
			catch (...)
			{
			}

			if (k == "V" || k == "v")
			{
				while (true)
				{
					if (void_order())
					{
						ClearScreen();
						std::cout << "\nvoid complete! ";
						orders.clear();
							if(Quantity1!=0){
  						change4("1",Quantity1);
						}if(Quantity2!=0){
  						change4("2",Quantity2);
						}if(Quantity3!=0){
					  	change4("3",Quantity3);
						}if(Quantity4!=0){
  						change4("4",Quantity4);
						}if(Quantity5!=0){
  						change4("5",Quantity5);
						}
						Sleep(3000);
						break;
					}
					else
					{
						std::cout << "\nwrong pin!";
						system("cls");
						break;
					}
				}
			}
			else if (k == "O" || k == "o")
			{
				bool ok = calculate_order();
				if (ok)
				{
					print_OR();
					orders.clear();
					std::cout << "\norder complete!";
						if(Quantity1!=0){
 					 	change3("1",Quantity1);
						}if(Quantity2!=0){
 					 	change3("2",Quantity2);
						}if(Quantity3!=0){
 					 	change3("3",Quantity3);
						}if(Quantity4!=0){
					  	change3("4",Quantity4);
						}if(Quantity5!=0){
					  	change3("5",Quantity5);
						}
					break;
				}
			}
		} while (k != "X" && k != "x");
		system("cls");
		orders.clear();
		std::cout << "\nthank you!\n";
		Sleep(3000);
	}

	bool void_order()
	{
		std::cout << "Manager's PIN: ";
		std::string managerpin;
		std::cin >> managerpin;
		if (managerpin == "123")
			return true;
		return false;
	}
	bool calculate_order()
	{
		if (orders.size() == 0)
		{
			std::cout << "\n no orer has been set. try again \n";
			Sleep(3000);
			return false;
		}
		std::string holder;
		while (true)
		{
			ClearScreen();
			std::cout << Head::Header(*cashier);
			display_menu();
			display_orders();
			std::cout << "Total: " << compute_total() << "\n enter cash ( [C] for cancel ): ";
			std::cin >> holder;
			try
			{
				cash = std::stod(holder);
				if (cash < compute_total())
				{
					std::cout << "\ninsufficient amount entered \n";
					Sleep(3000);
				}
				else
				{
					change = cash - compute_total();
					break;
				}
			}
			catch (...)
			{
				if (holder == "c" || holder == "C")
				{
					std::cout << "\n cancelled\n";
					Sleep(3000);
					return false;
				}
				else
				{
					std::cout << "\n enter valid amount \n";
				}
			}
		}
		std::cout << "\nprint OR?(Y/N)\n";

		while (true)
		{
			std::cin >> OR;
			if (OR == "Y" || OR == "y" || OR == "N" || OR == "n")
				break;
			std::cout << "\nenter valid value\n";
		}
		bool ans = final_question();
		if (!ans)
			return false;
		return true;
	};
	void print_OR()
	{
		if (OR == "Y" || OR == "y")
		{
			std::ofstream outfile("sales.txt", ios::app );
			outfile << "\n===================================================\n";
			outfile << "cashier name: " << cashier->fullname() << "\nemployee number: " << cashier->employee_id << "\n";
			for (int i = 0; i < orders.size(); i++)
			{
				outfile << " \norder number: " << i + 1 << "\n" <<"Order:"
						<< orders[i].foodname << " " << orders[i].price << "      quantity: " << orders[i].quantity << "\n";
			}
			outfile << "Total: " << compute_total() << "\ncash: " << cash << "\nchange: " << change;
			outfile << "\n===================================================\n";
			outfile.close();
		}
	};

	bool final_question()
	{
		ClearScreen();
		std::cout << Head::Header(*cashier);
		display_menu();
		display_orders();
		std::cout << "Total: " << compute_total() << "\ncash: " << cash << "\nchange: " << change
				  << "\ngenerate OR: " << OR << "\nConfirm(Y)/Cancel(any key): ";
		std::string confirm;
		std::cin >> confirm;
		if (confirm == "Y" || confirm == "y")
			return true;
		return false;
	}
};

int toInt(string str){
	 int num = 0,size = str.size();
				  
				  for(int i = 0 ,k = size; i < size ; i++){
				  	num+=(str[--k]-'0')*pow(10,i);
				  	
				  }
				  return num;
}
		string a[1000],d[1000];
		int b[1000],c[1000];
void sett(){

		string line, text[1000];
		ifstream offile;
		int counter1 = 0;
		string sub;
		offile.open("Inventory.txt");
	
		int b1,c1;
		int i = 0;
		if (offile.is_open()){
			while(!offile.eof()){
				getline(offile,line);
				text[counter1] = line;
				counter1++;
					
				}
			}
			offile.close();
			for(int j = 0; j < counter1; j++ ){
				 
					if(text[j].substr(0,4) == "Tag:"){
					d[j]=text[j].substr(4,8);
					
					}
				
					if(text[j].substr(0,9) == "ItemName:"){
					a[j]=text[j].substr(9,40);
					
					}
				
					if (text[j].substr(0,6) == "Price:"){
					b[j]=toInt(text[j].substr(6,11));
					
					}
					if (text[j].substr(0,9) == "Quantity:"){
					c[j]= toInt(text[j].substr(9,14));
					
					}
				
				
				
			}
	
		}
	
	Order Orders::bfs = Order(a[3], b[4], c[5]);
	Order Orders::css = Order(a[10], b[11], c[12]);
	Order Orders::crs = Order(a[17], b[18], c[19]);
	Order Orders::brs = Order(a[24], b[25], c[26]);
	Order Orders::frs = Order(a[31], b[32], c[33]);
std::vector<Order> Orders::mymenu = {Orders::bfs, Orders::css, Orders::crs, Orders::brs, Orders::frs};
int main()
{
	ClearScreen();
	sett();
	Orders::bfs = Order(a[3], b[4], c[5]);
	Orders::css = Order(a[10], b[11], c[12]);
	Orders::crs = Order(a[17], b[18], c[19]);
	Orders::brs = Order(a[24], b[25], c[26]);
	Orders::frs = Order(a[31], b[32], c[33]);
	Orders::mymenu = {Orders::bfs, Orders::css, Orders::crs, Orders::brs, Orders::frs};
	Orders menu;
	
	while (true)
	{	
		std::cout << "    welcome!\n";
		std::cout << Head::Header();
		std::string c;
		std::cout << "\nEnter User:";
		std::cin >> c;
		if(c == "Cashier"){
		Cashier employee = create_user();
		system("cls");
		menu.assign_user(employee);
		menu.order_menu();
		}else if(c == "Admin"){
			Admin employee = create_user1();
			system("cls");
			menu.assign_user1(employee);
			menu.admin_menu();
		}
	
}
}
/*

1.) 7 classes has been generated. those are: User, Cashier,Admin,User_logs which inherits from User, Order,
		Orders and Head for header of page
2.) inheritance has been used to the user ,cashier class,admin class and user_logs class. it is used to pass the firstname, lastname and fullname
		properties of the parent , which in this case is the User class,and overriden the position method.
3.) no abstract class has been used in this activity, only abstract method has been used to override the position
		property of the User
4.) yes, it is used to hide the properties that is not supposed to be set directly
5.) we did not have to use destructor since c++ implicitly delete the object. constructor however, has been used to
		 assign the values of the protected fields
6.) yes we have applied oviridding and overloading in the program by using a math function created by the programmer toInt() is one of the example of oviridding same for change(),change2() 
	Overidding has been used to get the data needed from the user to perform functions.

*/
