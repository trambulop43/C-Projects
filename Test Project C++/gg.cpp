#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>   
#include <ctime>
using namespace std;

class master{
	
	public:
		master(){
			string line, text[1000];
			ifstream offile;
			int counter1 = 0;
			offile.open("master.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					text[counter1] = line;
					counter1++;
					
				}
			}
			count1 = counter1;
			count = (counter1)/11;
			offile.close();
		
    	}
    	
    	void add();
    	void search();
    	void list();
    	void update();
    	void save();
    	void check();
    	void list2();
    	void list3();
		
		struct EntryStruct				
   		{
      	int ID;
		char desc[15];
		char supplierN[15];
		char IName[15];
		int Price;
		int qty;
		int ROrder;
		char category[15];
		char UOM[15];
   		};
   		
   		 EntryStruct entries[100];
  			int count;
  			int count1;
  			time_t current = time(0);
			string ct = ctime(&current);
			
		};
		
		
		
		


void master::add(){
	
	ofstream a_file ( "master.txt", ios::app );
	ofstream file ( "purchase.txt", ios::app );
	entries[count].ID = count+1;
	
	
	cout << "Enter Item Desc:";
	cin >> entries[count].desc;
	
	cin.clear();
	cin.sync();
	
	cout << "Enter supplier name:";
	cin >> entries[count].supplierN;

	cin.clear();
	cin.sync();
	
	cout << "Enter Item Price:";
	cin >> entries[count].Price;

	cin.clear();
	cin.sync();
	
	cout << "Enter Item name:";
	cin >> entries[count].IName;
	
	cin.clear();
	cin.sync();

	cout << "Enter Item Quantity:";
	cin >> entries[count].qty;
	
	cin.clear();
	cin.sync();
	
	if(entries[count].Price <= 200){
		entries[count].ROrder = 5;
		
		cin.clear();
		cin.sync();
	}else if(entries[count].Price > 200 and entries[count].Price< 500){
		entries[count].ROrder = 10;
	
		cin.clear();
		cin.sync();
	}else if(entries[count].Price > 500){
		entries[count].ROrder = 15;
		
		cin.clear();
		cin.sync();
	}
	
	cout << "Enter Item Category:";
	cin >> entries[count].category;

	cin.clear();
	cin.sync();
	
	cout << "Enter Item Unit of measure in:";
	cin >> entries[count].UOM;
	
	cin.clear();
	cin.sync();

	a_file << "\n================="<< endl;
	a_file <<"ID:" <<entries[count].ID << "\n";
	a_file << "Enter Item :"<<entries[count].desc << "\n";
	a_file << "supplier name:"<<entries[count].supplierN << "\n";
	a_file << "Item Price:"<<entries[count].Price << "\n";
	a_file << "Item name:"<<entries[count].IName << "\n";
	a_file << "Quantity:"<<entries[count].qty << "\n";
	a_file << "ReOrder Value:"<<entries[count].ROrder  << "\n";
	a_file << "Item Category:"<<entries[count].category << "\n";
	a_file << "Item Unit of measure in:"<<entries[count].UOM << "\n";
	a_file << "=================";

	file <<"\ndate Updated:"<<ct<<endl;
	file << "\n================="<< endl;
	file <<"ID:" <<entries[count].ID << "\n";
	file << "Enter Item :"<<entries[count].desc << "\n";
	file << "supplier name:"<<entries[count].supplierN << "\n";
	file << "Item Price:"<<entries[count].Price << "\n";
	file << "Item name:"<<entries[count].IName << "\n";
	file << "Quantity:"<<entries[count].qty << "\n";
	file << "ReOrder Value:"<<entries[count].ROrder  << "\n";
	file << "Item Category:"<<entries[count].category << "\n";
	file << "Item Unit of measure in:"<<entries[count].UOM << "\n";
	file << "=================";
	
	
	++count;
	a_file.close();
	file.close();
	system("cls");
	
	cout << "Item succesfully added"<<endl;

}
void master::search(){
	 string line;
	 ifstream offile;
	 
	 string getcontent[count1];
	 string Input_Id,qwe;
   	 cout << "Input the ID of the item you want to display:";
   	 cin >>Input_Id;
   	 qwe = "ID:" + Input_Id;
   	 int count1;
   	 
			
			offile.open("master.txt");
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
			  	for(int i = 0; i < 11; i++){
				    cout << getcontent[j+(i-1)] << endl;
				}
				break;
			  }	
		
				
					
				
				
				
			}
	
}

void master::update(){
	 string line;
	 ifstream offile;
	 
	 string getcontent[count1];
	 string Input_Id,qwe,asd;
   	 cout << "Input the ID of the item you want to update:";
   	 cin >>Input_Id;
   	 qwe = "ID:" + Input_Id;
   	 int count1,count2;
   	 count2 = count1;
   	 
			
			offile.open("master.txt");
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
			  	
				
				cout << "Input the quantity update of the item:";
				cin >> asd;
				getcontent[j+5] =  "Quantity:"+asd;
				ofstream a_file ("master.txt");
				for(int j = 0; j < count1-1; j++){
				
				if(j == count1 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "=================";
				cout << "Updated succesfully" << endl;
				a_file.close();
				break;
			  }	
			
		
				
			}
			ofstream file ( "purchase.txt", ios::app );
			
			for(int j = 0; j < count1; j++){
				
			  if(getcontent[j] == qwe){
			  	file <<"date Updated:"<<ct<<endl;
			  	
			  	for(int i = 0; i < 11; i++){
			  		
				    file << getcontent[j+(i-1)]<<endl;
				}
				break;
			  }	
				
			}
			file.close();
	
}

void master::check(){
			string line, text[count1];
			ifstream offile;
			int z = 0;
			int num1 , num2;
			int counter1 = 0,store[z];
			string s;
			offile.open("master.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					text[counter1] = line;
					counter1++;
					
				}
			}
			
			offile.close();
			ofstream a_file ( "OutOfStock.txt");
			for(int j = 0; j < counter1; j++){
				if(j%11==0){
					
					if(stoi(text[j+(6)].substr(9,10)) <= stoi(text[j+(7)].substr(14,16))){
					
					int z = stoi(text[j+(1)].substr(3,4));
					string ds = "ID:"+to_string(z);
					if(text[j+1] == ds){
						for(int x = 0; x < 11; x++){
								a_file << text[j+x]<<endl;
			  		
						   
			  				}
					}
					
					
						 
			  				}
			  					
					  }
					
					
					
					
				 		
							}a_file.close();
						}
					
				
				
		
				
						
			
			
		

	
void master::list(){
		string line, text[count1];
			ifstream offile;
			int counter1 = 0;
			offile.open("master.txt");
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
   
void master::list2(){
	string line, text[1000];
			ifstream offile;
			int counter1 = 0;
			offile.open("purchase.txt");
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

void master::list3(){
		string line, text[count1];
			ifstream offile;
			int counter1 = 0;
			string s;
			offile.open("OutOfStock.txt");
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



master MasterFile;	
int main (){
   int input,input1,ID, qty, ROrder,Price;
   string desc,supplierN,IName,category,UOM,user_name;
	//main
	MasterFile.check();	
	do{
	
	cout << "[1] - Access master list\n" ;
	cout << "[2] - Access Purchase lsit\n" ;
	cout << "[3] - Access Out of Stocks list\n" ;
	cout << "[4] - Exit\n";
	cout << "Enter your choice:";
	cin>> input1;
	system("cls");
	do{
	
	if(input1 == 1){
	//crud for file
	
	cout << "[1] - Purchase\n";
	cout << "[2] - Search by ID\n";
	cout << "[3] - List All \n";
	cout << "[4] - update stock\n";
	cout << "[0] - Exit\n";
	cout << "Enter your choice:";
	cin >> input;
		
	if(input == 1){
		system("cls");
		MasterFile.add();
		cout << "Item succesfully added"<<endl;	
	}else if(input == 2){
		system("cls");
		MasterFile.search();
	}else if(input == 3){
		system("cls");
		MasterFile.list();	
	}else if(input == 4){
		system("cls");
		MasterFile.update();	
	}else if(input == 0){
		system("cls");
		
				}
	
		
	
	
	}else if(input1 == 2){
		
		MasterFile.list2();
		
	}else if(input1 == 3){
		system("cls");
		MasterFile.list3();
		}
		}while(input != 0);
	}while(input1 != 4);
	
	cout << "Thank you for using";

	
  
}
