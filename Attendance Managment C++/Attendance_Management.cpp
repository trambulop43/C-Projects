#include<conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<dos.h>
#include<cctype>
#include<sstream>
#include<string>
#include<ctime>
using namespace std;
bool check_t = true;
bool check_s = true;

struct Node_t
{
	string prof_lname;
	string prof_fname;
	int class_code_t;
	string subject_t;
	string class_time;
	//int num_stud;
	
	Node_t *next;
}*head_t, *last_t;

struct Node_s
{
	string stud_lname;
	string stud_fname;
	string stud_id;
	string course;
	int class_code_s;
	string stud_time;
	int status;
	
	Node_s *next;
}*head_s, *last_s;

int check_time(string a, int b)
{
	Node_t *prev = NULL;
	Node_t *current = NULL;
	
	prev = head_t;
	current = head_t;
	
	while (current -> class_code_t != b)
	{
		prev = current;
		current = current -> next;
	}
	
	string c = current -> class_time;
	
	int TM01 = c[11] - '0';
	int TM02 = c[12] - '0';
	int TM03 = c[14] - '0';
	int TM04 = c[15] - '0';
	
	int TM05 = a[11] - '0';
	int TM06 = a[12] - '0';
	int TM07 = a[14] - '0';
	int TM08 = a[15] - '0';
	
	int TM09 = (TM01 * 10) + TM02;
	int TM10 = (TM03 * 10) + TM04;
	
	int TM11 = (TM05 * 10) + TM06;
	int TM12 = (TM07 * 10) + TM08;
	
	int TM13 = (TM09 * 60) + TM10;
	int TM14 = (TM11 * 60) + TM12;
	
	if(TM14 - TM13 > 15)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

void create_C()
{
	bool check = false;
	int cc;
	
	time_t class_enter = time(0);
	string ct = ctime(&class_enter);
	
	Node_t *x;
	x = new Node_t();
	
	Node_t *prev = NULL;
	Node_t *current = NULL;
	
	cout << "TEACHER/PROFESSOR LAST NAME: ";
	cin >> (x -> prof_lname);
	
	cout << "TEACHER/PROFESSOR FIRST NAME: ";
	cin >> (x -> prof_fname);
	
	do
	{
		prev = head_t;
		current = head_t;
		
		cout << "ENTER CLASS CODE: ";
		cin >> cc;
		
		while(current != NULL)
		{
			if (current -> class_code_t == cc)
			{
				cout << "CLASS CODE ALREADY TAKEN." << endl << "SUBJECT: " << (current -> subject_t) << endl << endl;
				break;
			}
			
			prev = current;
			current = current -> next;
		}
		
		if (current == NULL)
		{
			x -> class_code_t = cc;
			check = true;
			break;
		}
	}while(!check);
	
	cout << "SUBJECT CODE: ";
	cin >> (x -> subject_t);
	
	cout << "TIME: " << ct;
	(x -> class_time) = ct;
	
	x -> next = NULL;
	
	if(check_t)
	{
		head_t = x;
		last_t = x;
		check_t = false;
	}
	
	else
	{
		last_t -> next = x;
		last_t = x;
	}
	
	getch();
}

void del_C()
{
	Node_t *x = NULL;
	
	Node_t *prev = NULL;
	Node_t *current = NULL;
	
	Node_s *prev_s = NULL;
	Node_s *current_s = NULL;
	
	int CODE;
	
	cout << "ENTER CLASS CODE TO DELETE: ";
	cin >> CODE;
	cout << endl;
	
	prev = head_t;
	current = head_t;
	
	prev_s = head_s;
	current_s = head_s;
	
	while (current != NULL)
	{
		if(current -> class_code_t == CODE)
		{
			cout << "CLASS CODE: " << (current -> class_code_t) << endl;
			cout << "SUBJECT CODE: " << (current -> subject_t) << endl;
			cout << "PROFESSOR NAME: " << (current -> prof_lname) << ", " << (current -> prof_fname) << endl;
			cout << "TIME: " << (current -> class_time) << endl;
			
			prev -> next = current -> next;
			current -> next = NULL;
			
			delete current;
			
			cout << endl << "CLASS DELETED SUCCESSFULLY!";
			
			break;
		}
		
		prev = current;
		current = current -> next;
	}
	
	if (current == NULL)
	{
		cout << "CLASS DOES NOT EXIST." << endl;
	}
	
	getch();
}

void show_stud()
{
	bool check = false;
	int num = 0, OT = 0, LT = 0;
	Node_s *current = NULL;
	int subject;
	
	cout << "ENTER SUBJECT CODE TO SHOW: ";
	cin >> subject;
	cout << endl;
	
	current = head_s;
	
	while(current != NULL)
	{
		if(current -> class_code_s == subject)
		{
			check = true;
			break;
		}
		
		current = current -> next;
	}
	
	if(check)
	{
		do
		{
			if (current -> class_code_s == subject)
			{
				cout << "NAME: " << (current -> stud_lname) << ", " << (current -> stud_fname) << endl;
				cout << "STUDENT NUMBER: " << (current -> stud_id) << endl;
				cout << "ENTERED AT: " << (current -> stud_time);
				
				if (current -> status == 1)
				{
					cout << "STATUS: LATE" << endl;
					LT += 1;
				}
				
				else
				{
					cout << "STATUS: ON-TIME" << endl;
					OT += 1;
				}
				
				cout << endl;
				
				num += 1;
				current = current -> next;
			}
			
			else
			{
				current = current -> next;
			}
			
		}while(current != NULL);
		
		cout << "TOTAL NUMBER OF ON-TIME: " << OT << endl;
		cout << "TOTAL NUMBER OF LATE: " << LT << endl;
		cout << "TOTAL NUMBER OF STUDENTS ENTERED: " << num << endl;
		
	}
	
	else
	{
		cout << "CLASS DOES NOT EXIST." << endl;
	}
	
	getch();
}

void enter_C()
{
	bool check_class = false;
	int cc;
	
	time_t TIME = time(0);
	string stud_enter = ctime(&TIME);
	
	Node_s *x;
	x = new Node_s();
	
	Node_t *prev = NULL;
	Node_t *current = NULL;
	
	cout << "ENTER LAST NAME: ";
	cin >> (x -> stud_lname);
	
	cout << "ENTER FIRST NAME: ";
	cin >> (x -> stud_fname);
	
	cout << "ENTER STUDENT NUMBER: ";
	cin >> (x -> stud_id);
	
	do
	{
		prev = head_t;
		current = head_t;
		
		cout << "ENTER CLASS CODE TO ATTEND: ";
		cin >> cc;
		
		while(current != NULL)
		{
			if (current -> class_code_t == cc)
			{
				x -> class_code_s = cc;
				
				cout << "CLASS TO ATTEND IS: " << (current -> subject_t) << endl;
				check_class = true;
				break;
			}
			
			prev = current;
			current = current -> next;
		}
		
		if (current == NULL)
		{
			cout << endl << "CLASS CODE NOT AVAILABLE. PLEASE TRY AGAIN." << endl << endl;
		}
	}while(!check_class);
	
	cout << "TIME-IN: " << stud_enter;
	(x -> stud_time) = stud_enter;
	
	int time_check = check_time(stud_enter, cc);
	
	if(time_check == 1)
	{
		cout << "STATUS: LATE" << endl;
		(x -> status) = time_check;
	}
	
	else
	{
		cout << "STATUS: ON TIME" << endl;
		(x -> status) = time_check;
	}
	
	x -> next = NULL;
	
	if(check_s)
	{
		head_s = x;
		last_s = x;
		check_s = false;
	}
	
	else
	{
		last_s -> next = x;
		last_s = x;
	}
	
	getch();
}

void show_C()
{
	int num = 1;
	Node_t *current = head_t;
	
	cout << "CLASSES:" << endl << endl;
	
	while(current != NULL)
	{
		if (current == NULL)
		{
			break;
		}
		
		else if (current != NULL)
		{
		cout << num << ". " << (current -> class_code_t) << ": " << (current -> subject_t) << endl;
		cout << "   INSTRUCTOR: " << (current -> prof_lname) << ", " << (current -> prof_fname) << endl;
		cout << "   ENTERED AT: " << (current -> class_time) << endl;
		cout << endl;
		
		current = current -> next;
		num += 1;
		}
	}
	
	getch();
}

void teacher()
{
	int op;
	
	cout << "TEACHER MODE" << endl << endl;
	
	getch();
	
	do
	{
		system("cls");
		
		cout << "CHOOSE AN OPTION: " << endl;
		
		cout << "[1] CREATE A CLASS" << endl;
		cout << "[2] DELETE A CLASS" << endl;
		cout << "[3] SHOW NUMBER OF STUDENTS" << endl;
		cout << "[4] SHOW ALL CLASSES" << endl;
		cout << "[0] BACK" << endl;
		
		cout << "OPTION: ";
		cin >> op;
		
		if (op == 1)
		{
			system("cls");
			create_C();
		}
		
		else if  (op == 2)
		{
			system("cls");
			del_C();
		}
		
		else if (op == 3)
		{
			system("cls");
			show_stud();
		}
		
		else if (op == 4)
		{
			system("cls");
			show_C();
		}
	}while(op != 0);
	
	if (op == 0)
	{
		getch();
	}
}

void student()
{
	int op;
	
	cout << "STUDENT MODE";
	
	getch();
	
	do
	{
		system("cls");
		
		cout << "CHOOSE AN OPTION: " << endl;
		
		cout << "[1] ENTER A CLASS" << endl;
		cout << "[2] SHOW ALL CLASSES" << endl;
		cout << "[0] BACK" << endl;
		
		cout << "OPTION: ";
		cin >> op;
		
		if (op == 1)
		{
			system("cls");
			enter_C();
		}
		
		else if (op == 2)
		{
			system("cls");
			show_C();
		}
	}while(op != 0);
	
	if (op == 0)
	{
		getch();
	}
}

int main()
{
	int op;
	
	cout << "ATTENDANCE MANAGEMENT SYSTEM" << endl << endl;
	
	cout << "Press any key to continue..." << endl;
	
	getch();
	
	do
	{
		system("cls");
		
		cout << "CHOOSE AN OPTION: " << endl;
		
		cout << "[1] TEACHER" << endl;
		cout << "[2] STUDENT" << endl;
		cout << "[0] EXIT" << endl;
		
		cout << "OPTION: ";
		cin >> op;
		
		if (op == 1)
		{
			system("cls");
			teacher();
		}
		
		else if (op == 2)
		{
			system("cls");
			student();
		}
	}while(op != 0);
	
	if(op == 0)
	{
		exit(0);
	}
}
