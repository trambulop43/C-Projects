#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <stdbool.h>

using namespace std;
//function used to check for the summary of the day
 void summary(int ST,int PT,int FC , int TR,int WRC,int SP, int RG, int WG,int PG,int RW,int WW,int PW, int SD, int SC,int SBF,int SI,int RV,int ICE ){
 		cout << "Total number of sales on this day"<<endl;
 		
		 
 		if(ST != 0){
 			cout << ST <<" Steak with mash potato"<< endl;
		 }
			if(PT!= 0){
				cout << PT <<" Pork tonkatsu with rice"<< endl;
			}
			if(FC != 0){
				cout << FC <<" Fried chicken with rice"<< endl;
			}
			if(TR != 0){
			cout << TR <<" Tempura with rice"<< endl;	
			}
			if(WRC != 0){
				cout << WRC <<" Whole roasted chicken with 5 rice"<< endl;
			}if(SP != 0){
				cout << SP <<" Seafood Platter with 5 rice"<< endl;
			}
			if(RG != 0){
					cout << RG <<" 1 glass of red wine"<< endl;
			}
			if(WG != 0){
					cout << WG <<" 1 glass of white wine"<< endl;
			}
			if(PG != 0){
				cout << PG <<" 1 glass of pink wine"<< endl;
			}
			if(RW != 0){
				cout << RW <<" Red wine"<< endl;
			}
			if(WW != 0){
				cout << WW <<" White wine"<< endl;
			}
			if(PW != 0){
				cout << PW <<" Pink wine"<< endl;
			}
			if(SD != 0){
				cout << SD <<" SoftDrinks"<< endl;
			}
			if(SC != 0){
				cout << SC <<" 1 Slice Chocolate mousse cake"<< endl;
			}
			if(SBF != 0){
				cout << SBF <<" 1 slice black forest cake"<< endl;
			}
			if(SI != 0){
				cout << SI <<" 1 slice ice cream cake"<< endl;
			}
			if(RV != 0){
				cout << RV <<" 1 slice red velvet cake"<< endl;
			}
			if(ICE != 0){
				cout << ICE <<" 1 Glass ice cream [any flavor]"<< endl;
			}
			
			
				
			cout << "\n\n";
 		}
 		
 		//function to print out the total cash of the day
 		void Total(double Cash[],int z){
 			int TotalSaale;
 			for(int x = 0; x< z;x++){
			TotalSaale += Cash[x]; 
		}
			cout << "The total Sale of today is:"<<TotalSaale;
			cout << "\n\n";
		 }
		 
		 
		 //function to count the customer
		void sold(int customer){
				cout <<  "There are a Total of " << customer << " Customer today" << endl;
				cout << "\n\n";
		}
int main(){
	//stream file to be inputed on the program
	ifstream offile;
	//stream input to file RECORDS
	ofstream file;
	
	double cash[1000],cashCustomer,cashTotal=0,cashArr[1000],TotalSale = 0,payment = 0,change = 0;
	double discount = 0;
	string store[1000],text[1000],line;
	int I,senior;
	int choice,au,mChoice,Dchoice,Lchoice,Sale = 0,zChoice;
	//date and time
	
	time_t current = time(0);
	string ct = ctime(&current);
	//main dish counter
	int St = 0,Pt = 0,Fc = 0,Tr = 0,Wrc = 0,Sp = 0;
	//drink counter
	int Rg = 0,Wg = 0,Pg = 0,Rw = 0,Ww = 0,Pw = 0,Sd = 0;
	//dessert counter
	int Sc = 0,Sbf = 0,Si = 0,Rv = 0,ice = 0;	
	// temporary main dish counter
	int tSt = 0,tPt = 0,tFc = 0,tTr = 0,tWrc = 0,tSp = 0;
	//temporary drink counter
	int tRg = 0,tWg = 0,tPg = 0,tRw = 0,tWw = 0,tPw = 0,tSd = 0;
	//temporary dessert counter
	int tSc = 0,tSbf = 0,tSi = 0,tRv = 0,tice = 0;
	
	//show the front page of the program the admin user and exit
	do{
	
	cout << "[1] Admin \n[2] User \n[0] exit \nChoose:";
	cin >> au;
	system("cls");
	if(au != 1 && au != 2 && au != 0){
		system("cls");
		cout << "Invalid Input\n" << endl;
	}
	
	int choice1;
	if(au == 1){
		//This will show the command that the admin have
		do{
		
		
		cout << "\nChoice" << endl;
		cout << "[1] Summary of orders of the day"<< endl;
		cout << "[2] Total sales of the day"<< endl;
		cout << "[3] No of customer for the day"<< endl;
		cout << "[4] Print all the record of orders"<< endl;
		cout << "[0] Exit"<< endl;
		cout << "Enter your choice:";
		cin >> choice1;
		
			system("cls");
		cout << "\n\n";
		if(choice1 == 1){
			//command 1 of the admin summary the orders
			summary(St,Pt,Fc,Tr,Wrc,Sp,Rg ,Wg,Pg,Rw,Ww,Pw,Sd,Sc,Sbf,Si,Rv,ice);
		}
		else if(choice1 == 2){
			//command 2 of the admin show the total sales of the day in cash/integer form
			Total(cashArr,Sale);	
		}
		else if (choice1 == 3){
			//command 3 shows all the customer of the day that have bought from the shop
			sold(Sale);		
		}else if(choice1 == 4){
			//command 4 print all the order that was stored in the notepad
			int counter = 0;
			offile.open("RECORDS.txt");
			if (offile.is_open()){
				while(!offile.eof()){
					getline(offile,line);
					text[counter] = line;
					counter++;
					
				}
			}
			offile.close();
			for(int j = 0; j < counter; j++){
				cout << text[j] << endl;
				
			}
			
			
		}else if(choice1 == 0){
			
		
		}else{
			//if the command is invalid this will output that you have entered an invalid input
			system("cls");
			cout << "\nInput Invalid\n " << endl;
		}
		//loop the command
	}while(choice1 != 0);
	}
	
	
	
	
	if(au == 2){
	//this part of the program is the user part of the program where the user will input thier orders
	
	//this file open command will directly append the data that has been gathered to be inputed in the notepad
	file.open("RECORDS.txt",ios::app);
	//this will count the sale of the day
	Sale += 1;
	//clear out the array and counter
	I = 0;
	cashTotal = 0;
	payment = 0;
	change = 0;
	for(int i = 0; i < 100; i++)
	{
		cash[i] = 0;
		store[i] = "\0";
		
	}
	do{
	do{
	cout << "------------------------------------"<<endl;
	cout << "|  Welcome to PC Family restaurant |" << endl;
	cout << "------------------------------------"<<endl;
	
	
	
	
	cout << "Choice:\n";
	cout << "[1] Main\n";
	cout << "[2] Drinks\n";
	cout << "[3] Dessert\n";
	cout << "[4] VOID ORDER\n";
	cout << "[0] Check out\n";
	cout << endl;
	
	cout << "Enter your choice:";
	cin >> choice;
	system("cls");
	
	if(choice == 1){
		//main dishes command
		do{
		
		cout << "\nSolo Menu/main dish"<<endl;
		cout << "[1] Steak with mash potato -- 350"<<endl;
		cout << "[2] Pork tonkatsu with rice -- 200"<<endl;
		cout << "[3] Fried chicken with rice -- 150"<< endl;
		cout << "[4] Tempura  with rice -- 170"<< endl;
		cout << endl;
		cout << "Group order"<< endl;
		cout << "[5] Whole roasted chicken with 5 rice 600"<<endl;
		cout << "[6] Seafood platter with 5 rice -- 700"<<endl;
		cout << "Enter your choice:";
		cin >> mChoice;
		cout <<" \n\n";
		if(mChoice == 1){
			cash[I] = 350;
			store[I] = "Steak with mash potato -- 350";
			I += 1;
			tSt+=1;
		}
		else if(mChoice == 2){
			cash[I] = 200;
			store[I] = "pork tonkatsu with rice -- 200";
			I += 1;
			tPt += 1;
		}	else if(mChoice == 3){
			cash[I] = 150;
			store[I] = "Fried chicken with rice -- 150";
			I += 1;
			tFc += 1; 
		}
			else if(mChoice == 4){
			cash[I] = 170;
			store[I] = "Tempura with rice -- 170";
			I += 1;
			tTr += 1;
		}	else if(mChoice == 5){
			cash[I] = 600;
			store[I] = "Whole roasted chicken with 5 rice -- 600";
			I += 1;
		    tWrc += 1;
		}else if(mChoice == 6){
			cash[I] = 700;
			store[I] = "Seafood platter with 5 rice -- 700";
			I += 1;
			tSp += 1;
		}else{
			//if input is invalid
			system("cls");
			cout << "\nInvalid Input\n" << endl;
		}
		
		
		//this while loop will loop the choice of main dish if the input given is not correct
	}while(mChoice != 1 && mChoice != 2 && mChoice != 3 && mChoice != 4 && mChoice != 5 && mChoice != 6); 
		do{
		
		cout << "Order more[1] or checkout[0]"<<endl;
		cin >> zChoice;
		if(zChoice != 1 && zChoice != 0){
			//if input is invalid
			system("cls");
			cout << "\nInvalid Input\n"<<endl;
		}
		//this while loop will loop the command if the input given is not correct
	}while(zChoice != 1 && zChoice != 0);
		system("cls");
	}
	
	else if (choice == 2){
		//Drinks choices
		do{
		
		cout << "Drinks"<< endl;
		
		cout <<"solo drink" <<endl;
		cout <<"[1]  glass of red wine--110" << endl;
		cout <<"[2]  glass of white wine--85" <<endl;
		cout <<"[3]  glass of pink wine--75" << endl;

		cout<<"whole"<<endl;
		cout <<"[4] bottle of red wine--700"<<endl;
		cout<<"[5] bottle of white wine--500"<<endl;
		cout <<"[6] bottle of pink wine--450"<<endl;
		cout <<"[7] bottle of softdrinks--120"<< endl;
		
		cout << "Enter your Choice:";
		cin >> Dchoice;
		
		if(Dchoice == 1){
			cash[I] = 110;
			store[I] = " glass of red  wine -- 110";
			I += 1;
		
			tRg += 1;
		}
		else if(Dchoice ==2){
			cash[I] = 85;
			store[I] = " glass of white wine -- 85";
			I += 1;
			tWg += 1;
		}else if(Dchoice == 3){
			cash[I] = 75;
			store[I] = "  glass of pink wine -- 75";
			I += 1;
			tPg +=1;
		}
		else if(Dchoice == 4){
			cash[I] = 700;
			store[I] = " bottle of red wine -- 700";
			I += 1;
			tRw += 1;
		}else if(Dchoice == 5){
			cash[I] = 500;
			store[I] = " bottle of white wine -- 500";
			I += 1;
			tWw += 1;
		}else if(Dchoice == 6){
			cash[I] = 450;
			store[I] = " bottle of pink wine -- 450";
			I += 1;
			tPw += 1;
		}else if(Dchoice == 7){
			cash[I] = 120;
			store[I] = " bottle of Soda -- 120" ;
			I += 1;
			tSd += 1;
		}else{
			//if input is invalid
			system("cls");
			cout << "\nInvalid Input\n" << endl;
		}
		
		}//this do while loop will loop the command of drinks if the input given is not correct
		while(Dchoice != 1 && Dchoice != 2 && Dchoice != 3 && Dchoice != 4 && Dchoice != 5 && Dchoice != 6 && Dchoice != 7);
		cout << "\n \n";
		do{
		
		cout << "Order more[1] or checkout[0]"<<endl;
		cin >> zChoice;
		if(zChoice != 0 && zChoice != 1){
			//if input is invalid
			system("cls");
			cout << "\nInvalid Input\n" << endl;
		}
		}//this do while loop will loop the command if the input given is not correct
		while(zChoice != 0 && zChoice != 1);
		system("cls");
	}
	
	else if(choice ==3){
		//dessert command
		do{
		
		cout <<"dessert"<<endl;
		cout <<"[1] 1 slice chocolate mousse -- 150"<<endl;
		cout <<"[2] 1 slice black forest cake -- 150"<<endl;
		cout<<"[3] 1 slice ice cream cake -- 200"<<endl;
		cout <<"[4] 1 slice red velvet cake -- 200"<<endl;
		cout <<"[5] 1 Glass ice cream [any flavor] -- 100"<<endl;
		cout << "\n \n";
		cout << "Enter your Choice:";
		cin >> Lchoice;
	
		
		if(Lchoice == 1){
			cash[I] = 150;
			store[I] = "1 Slice Chocolate mouse cake -- 150";
			I += 1;
			tSc +=1;
		}else if(Lchoice == 2){
			cash[I] = 150;
			store[I] = "1 Slice Black Forest cake -- 150";
			I += 1;
			tSbf+=1;
		}else if(Lchoice == 3){
			cash[I] = 200;
			store[I] = "1 Slice Ice Cream cake -- 200";
			I += 1;
			tSi += 1;
		}else if(Lchoice == 4){
			cash[I] = 200;
			store[I] = "1 Slice Red velvet cake -- 200";
			I += 1;
			tRv += 1;
		}else if(Lchoice == 5){
			cash[I] = 100;
			store[I] = "1 Glass of Ice Cream[any flavor] -- 100";
			I += 1;
			tice += 1;
		}else{
			//invalid input
			system("cls");
			cout << "\nInvalid Input\n"<< endl;
			
		}
			}//this do while loop will loop the command of dessert if the input given is not correct
			while(Lchoice != 1 && Lchoice != 2 && Lchoice != 3 && Lchoice != 4 && Lchoice != 5);
		do{
		
		cout << "Order more[1] or checkout[0]"<<endl;
		cin >> zChoice;
		if(zChoice != 1 && zChoice  != 0){
			system("cls");
			cout << "\nInvalid Input\n"<< endl;
		}
		}//this do while loop will loop the command if the input given is not correct
		while(zChoice != 0 && zChoice != 1);
		system("cls");
		
		
	}else if(choice == 4){
		for(int x = 0; x< I;x++){
		cashTotal += cash[x];
		}
		
		if(cashTotal != 0){
		
		
		for(int x = 0; x< I;x++){
		//output the oreder of the user
		
		cout << store[x]<< endl;
			
			
		}
		
		cout << "____________________________"<<endl;
		cout << "Total:" << cashTotal << endl;
		//this command will void all the orders of the user
		for(int i = 0; i < 100; i++)
	{
		
		cash[i] = 0;
		store[i] = "\0";
		
	}if(tSt != 0){
		tSt = 0;
	}if(tPt != 0){
		tPt = 0;
	}if(tFc != 0){
		tFc = 0;
	}if(tTr != 0){
		tTr = 0;
	}if(tWrc != 0){
		tWrc = 0;
	}if(tSp !=0){
		tSp = 0;
	}if(tRg != 0){
		tRg = 0;
	}if(tWg != 0){
		tWg = 0;
	}if(tPg != 0){
		tPg = 0;
	}if(tRw != 0){
		tRw = 0;
	}if(tWw != 0){
		tWw = 0;
	}if(tPw != 0){
		tPw = 0;
	}if(tSd != 0){
		tSd = 0;
	}if(tSc != 0){
		tSc = 0;
	}if(tSbf != 0){
		tSbf = 0;
	}if(tSi != 0){
		tSi = 0;
	}if(tRv != 0){
		tRv = 0;
	}if(tice != 0){
		tice = 0;
	}
		cashTotal =0;
		cout << "Order void" << endl;
	}else{
		cout << "You cant void anything you didn't order anything"<<endl;
	}
	}else if(choice == 0){
		//this command is to end the user interface
		zChoice = 0;
	}
	else{
		//if the input is invalid it will show this command
		system("cls");
		cout << "\nInvalid input\n"<< endl;
	
	}    	
	

	}//this do while loop will loop the choices of maindish,drinks,dessert command if the input given is not correct
	while(  choice != 0 &&choice != 1 && choice != 2 && choice != 3);
	//this do while loop will loop the command if the input given is not correct
	}while(zChoice !=0 ) ;

	
	system("cls");
			for(int x = 0; x< I;x++){
			//this will total all the value of the order
			cashTotal += cash[x];
			cout << store[x]<< endl;
		}
		cout << "______________________"<<endl;
		cout << "Total:" << cashTotal << endl;
		
	if(cashTotal != 0){
		do{
		
		cout << "Do you have a Senior discount [1] for yes [0] for No:";
		cin >> senior;
		if(senior != 1 && senior != 0){
			//show invalid input
			cout << "\nInvalid Input\n" << endl;
		}
		}
		//this do while will loop the senior question if the input is invalid
		while(senior != 1 && senior != 0);
		if(senior == 1){
			//this command will calculate the discount
		discount = cashTotal *.20;
		cashTotal -= discount;
		}
		int asd;
		do{
		cout << "Total:"<<cashTotal<<endl;
		cout << "Enter your payment:";
		cin >> payment;
		
			
			if(payment >= cashTotal){
				change = payment - cashTotal;
				asd = 1;
			}else{
				cout << "Payment is insufficient"<<endl;
				asd = 0;
			}
		}while(asd!= 1);
	cout << "-----------------------------------"<<endl;
	cout << "|   Thank you for ordering        |" << endl;
	cout << "-----------------------------------"<<endl;
	//show the order number
	cout << "\n \nOrder No:"<<Sale<<endl;
	//show the date and time of the order
	cout <<"date:"<<ct<<endl;
	
		if(tSt != 0){
 			cout << tSt <<" Steak with mash potato -- 350"<< endl;
 			
			}
			if(tPt!= 0){
				cout << tPt <<" Pork tonkatsu with rice -- 200"<< endl;
			
			}
			if(tFc != 0){
				cout << tFc <<" Fried chicken with rice -- 150"<< endl;
				
			}
			if(tTr != 0){
				cout << tTr <<" Tempura with rice -- 170"<< endl;	
				
			}
			if(tWrc != 0){
				cout << tWrc <<" Whole roasted chicken with 5 rice -- 600"<< endl;
				
			}if(tSp != 0){
				cout << tSp <<" Seafood Platter with 5 rice -- 700"<< endl;
				
			}
			if(tRg != 0){
				cout << tRg <<" Glass of red wine -- 110"<< endl;
					
			}
			if(tWg != 0){
					cout << tWg <<" Glass of white wine -- 85"<< endl;
					
			}
			if(tPg != 0){
				cout << tPg <<" Glass of pink wine -- 75"<< endl;
				
			}
			if(tRw != 0){
				cout << tRw <<" Bottle of Red wine -- 700"<< endl;
				
			}
			if(tWw != 0){
				cout << tWw <<" Botlle of White wine -- 500"<< endl;
				
			}
			if(tPw != 0){
				cout << tPw <<" Bottle of Pink wine -- 450"<< endl;
				
			}
			if(tSd != 0){
				cout << tSd <<" Bottle of SoftDrinks -- 120"<< endl;
				
			}
			if(tSc != 0){
				cout << tSc <<" Slice of Chocolate mousse cake  -- 150"<< endl;
				
			}
			if(tSbf != 0){
				cout << tSbf <<" Slice of black forest cake -- 150"<< endl;
				
			}
			if(tSi != 0){
				cout << tSi <<" Slice of ice cream cake -- 200"<< endl;
			
			}
			if(tRv != 0){
				cout << tRv <<" Slice of red velvet cake  -- 200"<< endl;
				
			}
			if(tice != 0){
				cout << tice <<" Glass of ice cream [any flavor] -- 100"<< endl;
				
			}
			
			
				
			cout << "\n\n";
	//same as the first one but all the cout was changed into file then in will input all of the data in the file
	file << "-----------------------------------"<<endl;
	file << "|   Thank you for ordering        |" << endl;
	file << "-----------------------------------"<<endl;
	file << "\n \nOrder No:"<<Sale<<endl;
	file <<"date:"<<ct<<endl;
			if(tSt != 0){
 			
 			file << tSt <<" Steak with mash potato -- 350"<< endl;
			}
			if(tPt!= 0){
				
				file << tPt <<" Pork tonkatsu with rice -- 200"<< endl;
			}
			if(tFc != 0){
				
				file << tFc <<" Fried chicken with rice -- 150"<< endl;
			}
			if(tTr != 0){
					
				file << tTr <<" Tempura with rice -- 170"<< endl;
			}
			if(tWrc != 0){
			
				file << tWrc <<" Whole roasted chicken with 5 rice -- 600"<< endl;
			}if(tSp != 0){
				
				file << tSp <<" Seafood Platter with 5 rice -- 700"<< endl;
			}
			if(tRg != 0){
					
					file << tRg <<"  glass of red wine -- 110"<< endl;
			}
			if(tWg != 0){
				
					file << tWg <<"  glass of white wine -- 85"<< endl;
			}
			if(tPg != 0){
				
				file << tPg <<" glass of pink wine -- 75"<< endl;
			}
			if(tRw != 0){
			
				file << tRw <<" Bottle of Red wine -- 700"<< endl;
			}
			if(tWw != 0){
			
				file << tWw <<" Botlle of White wine -- 500"<< endl;
			}
			if(tPw != 0){
				
				file << tPw <<" Bottle of Pink wine -- 450"<< endl;
			}
			if(tSd != 0){
				
				file << tSd <<" Bottle of SoftDrinks -- 120"<< endl;
			}
			if(tSc != 0){
				
				file << tSc <<"  Slice of Chocolate mousse cake  -- 150"<< endl;
			}
			if(tSbf != 0){
				
				file << tSbf <<"  Slice of black forest cake -- 150"<< endl;
			}
			if(tSi != 0){
			
				file << tSi <<"  Slice of ice cream cake -- 200"<< endl;
			}
			if(tRv != 0){
				
				file << tRv <<"  Slice of red velvet cake  -- 200"<< endl;
			}
			if(tice != 0){
				
				file << tice <<"  Glass of ice cream [any flavor] -- 100"<< endl;
			}
			
			
				
			cout << "\n\n";
 		
		
		for(int x = 0; x< I;x++){
			//same as the first one but this will save the input to the notepad
			file << store[x]<< endl;
			
		}
		cout << "________________________________"<<endl;
		file << "________________________________"<<endl;
		cout << "Total:" << cashTotal << endl;
		cout<<"\n\n";
		cout << "Discount:" <<  discount << endl;
		file << "Total:" << cashTotal << endl;
		file<<"\n\n";
		file << "Discount:" <<  discount << endl;
		cout << "Cash:"<< payment<<endl;
		file << "Cash:"<< payment<<endl;
		cout << "Change:"<< change << endl;
		file << "Change:"<< change << endl;
		cout << "\n \n";
		file << "\n \n";
		
		//close the fill input
		file.close();
		int cashT= payment-change;
		for(int x = 0; x< Sale;x++){
			//this will store the data of the cashTotal to an array for when you are gonna use the summary of sales command
			cashArr[x] = cashT;
			
		
		}
	}else{
		//if the user exit without ordering this will output you You didn't order anything
	cout << "You didn't order anything"<<endl;
	cout << "\n \n";
	//close the fill input
	file.close();
	//if the user checkuot without ordering anything this will less that user from the summary of total customer
	Sale -= 1;
	
			}

		}
		
	if(tSt != 0){   //this whole block of command will check if the user had inputed an order or is it a no order to add to the summary of the day command it gets the data t
		St += tSt;	//hat was temporarily hold by the the command from above which adds when you order somthing
	}if(tPt != 0){
		Pt += tPt;
		tPt = 0;
	}if(tFc != 0){
		Fc += tFc;  
		tFc = 0;
	}if(tTr != 0){
		Tr += tTr;
		tTr = 0;
	}if(tWrc != 0){
		Wrc += tWrc;
		tWrc = 0;
	}if(tSp !=0){
		Sp += tSp;
		tSp = 0;
	}if(tRg != 0){
		Rg += tRg;
		tRg = 0;
	}if(tWg != 0){
		Wg += tWg;
		tWg = 0;
	}if(tPg != 0){
		Pg += tPg;
		tPg = 0;
	}if(tRw != 0){
		Rw += tRw;
		tRw = 0;
	}if(tWw != 0){
		Ww += tWw;
		tWw = 0;
	}if(tPw != 0){
		Pw += tPw;
		tPw = 0;
	}if(tSd != 0){
		Sd += tSd;
		tSd = 0;
	}if(tSc != 0){
		Sc += tSc;
		tSc = 0;
	}if(tSbf != 0){
		Sbf += tSbf;
		tSbf = 0;
	}if(tSi != 0){
		Si += tSi;
		tSi = 0;
	}
	if(tRv != 0){
		Rv += tRv;
		tRv = 0;
	}if(tice != 0){
		ice += tice;
		tice = 0;
	}
	}//loop the main interface
	while(au != 0);
	std::ofstream ofs;
	ofs.open("RECORDS.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	cout << "Thank you for using my program!!" << endl;
	}
