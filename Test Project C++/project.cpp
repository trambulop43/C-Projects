#include <iostream>
#include <fstream>
#include <sstream>
#include <string>                    

using namespace std;
	//stream file to be inputed on the program
	ifstream offile;
	//stream input to file RECORDS
	ofstream file;
void add(int ID,string desc,string supplierN,int Price,string IName,int qty,int ROrder,string category,string UOM){
	file.open("Master.txt",ios::app);
 
	cout << "Enter ID:";
	cin >> ID;
	
	cout << "Enter Item Desc:";
	cin >> desc;
	
	cout << "Enter supplier name:";
	cin >> supplierN;

	cout << "Enter Item Price:";
	cin >> Price;
	
	cout << "Enter Item name:";
	cin >> IName;

	cout << "Enter Item Quantity:";
	cin >> qty;
	
	if(Price <= 200){
		ROrder = 5;
	}else if(Price > 200 and Price< 500){
		ROrder = 10;
	}else if(Price > 500){
		ROrder = 15;
	}
	
	cout << "Enter Item Category:";
	cin >> category;
	
	cout << "Enter Item Unit of measure in:";
	cin >> UOM;
	//File writer
		file <<"================="<< endl;
		file << ID<<endl;
		file << desc<<endl;
		file << desc<<endl;
		file << Price<<endl;
		file << IName<<endl;
		file << qty<<endl;
		file << ROrder<<endl;
		file << category<<endl;
		file << UOM<<endl << endl;
		file <<"================="<< endl;
		
	file.close();
	system("cls");
	cout << "Item succesfully added"<<endl;
}

void search(string user_input){
		cin>>user_input;
				 
                 ifstream data("Master.txt");
                 
	  while( !data.eof() ) {
						
                        getline(data,record);
						
			if (record.find(user_input) != string::npos) {
				cout<<record<<"\n";
			} 
 
                 }
	
            
}




int main (){
   int input,ID, qty, ROrder,Price;
   string desc,supplierN,IName,category,UOM,user_name;
	cout << "[1] - Add\n";
	cout << "[2] - Search\n";
	cout << "[3] - List All \n";
	cout << "[4] - Edit\n";
	cout << "[5] - Delete\n";
	cout << "[0] - Exit\n";
	cout << "Enter your choice:";
	cin >> input;
	
	if(input == 1){
		system("cls");
		add(ID,desc,supplierN,Price,IName,qty,ROrder,category,UOM);
	}else if(input == 2){
		system("cls");
		search(user_name);
	}
	
   return 0;
}
