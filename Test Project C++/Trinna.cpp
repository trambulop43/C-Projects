#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>   
#include <ctime>
using namespace std;

class Project{
	
	public:
		Project(){
			string counterz, store[1000];
			ifstream offile;
			int counter0 = 0;
			offile.open("MasterFile.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,counterz);
					store[counter0] = counterz;
					counter0++;
					
				}
			}
			 div0 = counter0;
			 div = (counter0)/11;
			offile.close();
		
    	}
    	
    
		void purchase();
    	void find();
    	void list1();
    	void UpdateItem();
    	void sold();
    	void CheckOut();
    	void purchaseS();
    	void OutList();
  		void Slist();

		
		struct EntryStruct				
   		{
      	int id;
		char desc[15];
		char sName[15];
		char Item[15];
		int value;
		int Qty;
		int ROValue;
		char Cat[15];
		char Unit[15];
   		};
   		
   		 EntryStruct entries[100];
  			int div;
  			int div0;
  			time_t current = time(0);
			string ct = ctime(&current);
			
		};
		
		
		
void Project::sold(){
	string diverz;
	 ifstream offile;
	 
	 string getcontent[div0];
	 string Input_id,sss,asd;
   	 cout << "Input the id of the item has been lessen:";
   	 cin >>Input_id;
   	 sss = "id:" + Input_id;
   	 int div0,div2;
   	 div2 = div0;
   	 
			
			offile.open("MasterFile.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,diverz);
					getcontent[div0] = diverz;
					div0++;
					
				}
			}
			offile.close();
			
			for(int j = 0; j < div0; j++){
				
			  if(getcontent[j] == sss){
			  	
				
				cout << "Input the quantity update of the item:";
				cin >> asd;
				getcontent[j+5] =  "Quantity:"+asd;
				ofstream a_file ("sales.txt");
				for(int j = 0; j < div0-1; j++){
				
				if(j == div0 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "--------------------------------";
				cout << "Update succesfully" << endl;
				a_file.close();
				break;
			  }	
			
		
				
			}
			ofstream file ( "sales.txt", ios::app );
			
			for(int j = 0; j < div0; j++){
				
			  if(getcontent[j] == sss){
			  	file <<"\ndate and time Updated:"<<ct<<endl;
			  	
			  	for(int i = 0; i < 11; i++){
			  		
				    file << getcontent[j+(i-1)]<<endl;
				}
				break;
			  }	
				
			}
			file.close();
	
}	


void Project::purchase(){
	
	ofstream a_file ( "MasterFile.txt", ios::app );
	ofstream file ( "purchase.txt", ios::app );
	entries[div].id = div+1;
	
	
	cout << "Enter Item Description:";
	cin >> entries[div].desc;
	
	cin.clear();
	cin.sync();
	
	cout << "Enter supplier name:";
	cin >> entries[div].sName;

	cin.clear();
	cin.sync();
	
	cout << "Enter Item value:";
	cin >> entries[div].value;

	cin.clear();
	cin.sync();
	
	cout << "Enter Item name:";
	cin >> entries[div].Item;
	
	cin.clear();
	cin.sync();

	cout << "Enter Item Quantity:";
	cin >> entries[div].Qty;
	
	cin.clear();
	cin.sync();
	
	if(entries[div].value <= 200){
		entries[div].ROValue = 5;
		
		cin.clear();
		cin.sync();
	}else if(entries[div].value > 200 and entries[div].value< 500){
		entries[div].ROValue = 10;
	
		cin.clear();
		cin.sync();
	}else if(entries[div].value > 500){
		entries[div].ROValue = 15;
		
		cin.clear();
		cin.sync();
	}
	
	cout << "Enter Item Category:";
	cin >> entries[div].Cat;

	cin.clear();
	cin.sync();
	
	cout << "Enter Item Unit of measure in:";
	cin >> entries[div].Unit;
	
	cin.clear();
	cin.sync();

	a_file << "\n--------------------------------"<< endl;
	a_file <<"id:" <<entries[div].id << "\n";
	a_file << "Item Description:"<<entries[div].desc << "\n";
	a_file << "supplier name:"<<entries[div].sName << "\n";
	a_file << "Item value:"<<entries[div].value << "\n";
	a_file << "Item name:"<<entries[div].Item << "\n";
	a_file << "Quantity:"<<entries[div].Qty << "\n";
	a_file << "ReOrder Value:"<<entries[div].ROValue  << "\n";
	a_file << "Item Category:"<<entries[div].Cat << "\n";
	a_file << "Item Unit of measure in:"<<entries[div].Unit << "\n";
	a_file << "--------------------------------";

	file <<"\ndate UpdateItemd:"<<ct<<endl;
	file << "\n--------------------------------"<< endl;
	file <<"id:" <<entries[div].id << "\n";
	file << "Item Description :"<<entries[div].desc << "\n";
	file << "supplier name:"<<entries[div].sName << "\n";
	file << "Item value:"<<entries[div].value << "\n";
	file << "Item name:"<<entries[div].Item << "\n";
	file << "Quantity:"<<entries[div].Qty << "\n";
	file << "ReOrder Value:"<<entries[div].ROValue  << "\n";
	file << "Item Category:"<<entries[div].Cat << "\n";
	file << "Item Unit of measure in:"<<entries[div].Unit << "\n";
	file << "--------------------------------";
	
	
	++div;
	a_file.close();
	file.close();
	system("cls");
	
	cout << "Item succesfully purchased"<<endl;

}
void Project::find(){
	 string diverz;
	 ifstream offile;
	 
	 string getcontent[div0];
	 string Input_id,sss;
   	 cout << "Input the id of the item you want to display:";
   	 cin >>Input_id;
   	 sss = "id:" + Input_id;
   	 int div0;
   	 
			
			offile.open("MasterFile.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,diverz);
					getcontent[div0] = diverz;
					div0++;
					
				}
			}
			offile.close();
			for(int j = 0; j < div0; j++){
				
			  if(getcontent[j] == sss){
			  	for(int i = 0; i < 11; i++){
				    cout << getcontent[j+(i-1)] << endl;
				}
				break;
			  }	
		
				
					
				
				
				
			}
	
}

void Project::UpdateItem(){
	 string diverz;
	 ifstream offile;
	 
	 string getcontent[div0];
	 string Input_id,sss,asd;
   	 cout << "Input the id of the item you want to update:";
   	 cin >>Input_id;
   	 
   	 sss = "id:" + Input_id;
   	 int div0,div2;
   	 div2 = div0;
   	 
			
			offile.open("MasterFile.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,diverz);
					getcontent[div0] = diverz;
					div0++;
					
				}
			}
			offile.close();
			
			for(int j = 0; j < div0; j++){
				
			  if(getcontent[j] == sss){
			  	
				
				cout << "Input the quantity update of the item:";
				cin >> asd;
				getcontent[j+5] =  "Quantity:"+asd;
				ofstream a_file ("MasterFile.txt");
				for(int j = 0; j < div0-1; j++){
				
				if(j == div0 ){
					a_file << getcontent[j];
					
				}else{
					a_file << getcontent[j]<<endl;
					
				}
					
				}
				a_file << "--------------------------------";
				cout << "Update succesfully" << endl;
				a_file.close();
				break;
			  }	
			
		
				
			}
			ofstream file ( "purchase.txt", ios::app );
			
			for(int j = 0; j < div0; j++){
				
			  if(getcontent[j] == sss){
			  	file <<"\ndate and time Updated:"<<ct<<endl;
			  	
			  	for(int i = 0; i < 11; i++){
			  		
				    file << getcontent[j+(i-1)]<<endl;
				}
				break;
			  }	
				
			}
			file.close();
	
}

void Project::CheckOut(){
			string diverz, store[div0];
			ifstream offile;
			int q = 0;
			int num1 , num2;
			int diver0 = 0,store1[q];
			string s;
			offile.open("MasterFile.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,diverz);
					store[diver0] = diverz;
					diver0++;
					
				}
			}
			
			offile.close();
			ofstream a_file ( "OutOfStock.txt");
			for(int j = 0; j < diver0; j++){
				if(j%11==0){
					
					if(stoi(store[j+(6)].substr(9,10)) <= stoi(store[j+(7)].substr(14,16))){
					
					int z = stoi(store[j+(1)].substr(3,4));
					string ds = "id:"+to_string(z);
					if(store[j+1] == ds){
						for(int x = 0; x < 11; x++){
								a_file << store[j+x]<<endl;
			  		
						   
			  				}
					}
					
					
						 
			  				}
			  					
					  }
					
					
					
					
				 		
							}a_file.close();
						}
					
				
				
		
				
						
			
			
		

	
void Project::list1(){
		string diverz, store[div0];
			ifstream offile;
			int diver0 = 0;
			offile.open("MasterFile.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,diverz);
					store[diver0] = diverz;
					diver0++;
					
				}
			}
			offile.close();
			for(int j = 0; j < diver0; j++){
				cout << store[j] << endl;
				
			}
	
   }
   
void Project::purchaseS(){
	string diverz, store[1000];
			ifstream offile;
			int diver0 = 0;
			offile.open("purchase.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,diverz);
					store[diver0] = diverz;
					diver0++;
					
				}
			}
			offile.close();
			for(int j = 0; j < diver0; j++){
				cout << store[j] << endl;
				
			}
}

void Project::OutList(){
		string diverz, store[1000];
			ifstream offile;
			int diver0 = 0;
			string s;
			offile.open("OutOfStock.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,diverz);
					store[diver0] = diverz;
					diver0++;
					
				}
			}
			offile.close();
			for(int j = 0; j < diver0; j++){
				
				cout << store[j] << endl;
				
				
			}
}
void Project::Slist(){
	string diverz, store[1000];
			ifstream offile;
			int diver0 = 0;
			offile.open("sales.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,diverz);
					store[diver0] = diverz;
					diver0++;
					
				}
			}
			offile.close();
			for(int j = 0; j < diver0; j++){
				cout << store[j] << endl;
				
			}
}



Project ProjectFile;	
int main (){
   int input,input1,id, Qty, ROValue,value;
   string Desc,sName,Item,Cat,Unit,user_name;
	//main
	ProjectFile.CheckOut();	
	do{
	cout <<".___________________________."<<endl;
	cout <<"|                           |"<<endl;
	cout <<"|        ABC stock          |"<<endl;
	cout <<"|     management system     |"<<endl;
	cout <<".___________________________."<<endl;
	cout << "[1]Access Master list\n" ;
	cout << "[2]Access List of items bought\n" ;
	cout << "[3]Access Out of Stocks list\n" ;
	cout << "[4]Access Sales list\n" ;
	cout << "[5]Exit\n";
	cout << "Enter your choice:";
	cin>> input1;
	system("cls");
	do{
	
	if(input1 == 1){
	//crud for file
	cout <<".___________________________."<<endl;
	cout <<"|                           |"<<endl;
	cout <<"|        Welcome to         |"<<endl;
	cout <<"|    master list commands   |"<<endl;
	cout <<".___________________________."<<endl;
	cout << "[1]Purchase\n";
	cout << "[2]update sales item\n";
	cout << "[3]find by id\n";
	cout << "[4]List All Master file\n";
	cout << "[5]update stocks\n";
	cout << "[0]Exit\n";
	cout << "Enter your choice:";
	cin >> input;
		
	if(input == 1){
		system("cls");
		ProjectFile.purchase();
		
	}else if(input == 2){
		system("cls");
		ProjectFile.sold();
	}
	else if(input == 3){
		system("cls");
		ProjectFile.find();
	}else if(input == 4){
		system("cls");
		ProjectFile.list1();	
	}else if(input == 5){
		system("cls");
		ProjectFile.UpdateItem();
		ProjectFile.CheckOut();	
	}else if(input == 0){
		system("cls");
		
				}
	
		
	
	
	}else if(input1 == 2){
		
		ProjectFile.purchaseS();
		
	}else if(input1 == 3){
		system("cls");
		ProjectFile.OutList();
		}
		else if(input1 == 4){
			ProjectFile.Slist();
		}
		}while(input != 0);
	}while(input1 != 5);
	
	cout << "Thank you for using";

	
  
}
