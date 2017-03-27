/*
James Payne
SE 124.02
Program Assignment Four

Purpose: This program will determine a student's current academic standing using data retrieved from an 
institute of higher learning's student database.  The user will be prompted to enter a student's ID 
number.  The program will then check to see if that student's ID is in the database.  If found, the 
student's current academic standing will be displayed.

Variable Dictionary:

Variable Name				Type			Represents
first_name					string			student's first name
gpa							double			grade point average
last_name					string			student's last name
match						character		student id check result
min_average_gpa				double			minimum grade point average for average student rating
min_dean_gpa				double			minimum grade point average for Dean's List
response_y_n				character		y for yes n for no
row							integer			location reference number
student_id					integer			inputted student id number
stuid						integer			student id number in database
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char match, response_y_n;												//variables declared
double min_average_gpa, min_dean_gpa;
int row, stuid;

int student_id[8] = {456, 438, 321, 322, 832, 443, 473, 432};
string last_name[8] = { "Ames", "Coburn", "Collins", "Eccleston", "Finney", "Hollis", "Janus", "Roberts" };
string first_name[8] = { "Jeremy", "Barbara", "James", "Karen", "Robert", "Janet", "Tony", "Sally" };
double gpa[8] = { 3.45, 2.51, 3.88, 3.91, 1.23, 3.22, 1.37, 3.11 };

void check_response();													//functions declared
void enter_target();
void load_arrays();
void search();
void settings();
void successful();
void unsuccessful();

int main()
{																		//check to run
	cout << "Would you like to check a student's academic standing? Y or N: ";
	cin >> response_y_n;
	response_y_n = toupper(response_y_n);

	check_response();													//validate response

	while (response_y_n == 'Y')											//main while loop
	{
		settings();
		//load_arrays();
		enter_target();
		search();

		cout << endl;													//check to run again
		cout << "Would you like to look up another student? Y or N:";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);

		check_response();												//validate response
	}
	system("pause");
	return 0;
}

void check_response()													//validates response
{
	while (response_y_n != 'Y' && response_y_n != 'N')
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a Y for Yes or a N for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}
}

void enter_target()														//get search target
{
	system("cls");
	cout << "Please enter ID number of student you would like to enquire about." << endl << endl;
	cout << "Student ID number: ";
	cin >> stuid;
}

void load_arrays()														//get interactive data
{ /*
	system("cls");
	cout << "Please enter the following information:" << endl << endl << endl;
	for (int x = 0; x < 8; x++)
	{

		cout << "	Student ID Number: ";
		cin >> student_id[x];
		cout << "	Student's Last Name: ";
		cin >> last_name[x];
		cout << "	Student's First Name: ";
		cin >> first_name[x];
		cout << "	Student's Current GPA: ";
		cin >> gpa[x];

		while (gpa[x] < 0 || gpa[x] > 4)
		{
			cout << "Incorrect response." << endl;
			cout << "GPA must be greater than 0 but not more than 4" << endl;
			cout << "Please re-enter Student's Current GPA: ";
			cin >> gpa[x];
		}
		system("cls");
		cout << "Please enter the following information:" << endl << endl << endl;
	}	*/
}

void search()															//search for student record
{
	match = 'N';

	row = 0;

	while (match == 'N' && row < 8)
	{
		if (stuid == student_id[row])
		{
			match = 'Y';
		}
		else
		{
			row++;
		}
	}

	if (match == 'Y')
	{
		successful();													//results for found record
	}
	else
	{
		unsuccessful();													//result for record not found
	} 
}

void settings()															//set current value to
{																		//changeable variables
	min_average_gpa = 2.0;
	min_dean_gpa = 3.65;
}

void successful()														//process and output
{																		//found record
	system("cls");
	if (gpa[row] >= min_dean_gpa)
	{
		cout << first_name[row] << " " << last_name[row] << " is on the Dean's list"
			<< endl;
	}
	else
	if (gpa[row] >= min_average_gpa)
	{
		cout << first_name[row] << " " << last_name[row] << " is an average student"
			<< endl;
	}
	else
	{
		cout << first_name[row] << " " << last_name[row] << " is on Academic Probation"
			<< endl;
	}
}

void unsuccessful()												//output for record not found
{
	system("cls");
	cout << "The student ID was not located" << endl;
}