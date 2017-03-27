/*
James Payne
SE 124.02
Program Assignment Seven

Purpose: To track college enrollment activity in a variety of different courses.  The user will be 
given an option of entering data for the purpose of this program or using an existing data file.  
The user will then have an oppurtunity to select different ways to view the data or to search for 
an individual record.  Once the user has attain the information they were requesting, they can elect
to exit and terminate the program.

Variable Dictionary:

Variable Name				Type			Represents
choice						character		choice selected from menu options
counter						integer			array incermentor
course_name					string			name of course
course_name_file			string			aka variable used for user inputted data
duplicate_array				string			array used for sorting and searching
enrollment					integer			number of students enrolled in the course
enrollment_file				integer			aka variable used for user inputted data
enter_to_continue			string			continue condition
increment					integer			incrementing variable
index						integer			reference for search results
instructor_last_name		string			last name of instructor
instructor_last_name_file	string			aka variable used for user inputted data
match						character		control variable
max_records					integer			maximum number of records that can be entered
max_enrollment				integer			maximium number of students that can enroll
responce_y_n				character		Y for Yes N for No
row							integer			control variable
row_max						integer			control variable
row_min						integer			control variable
search_target				string			target for search
swapping					character		sort condition
total_enrollment			integer			total number of students enrolled database courses
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

char choice, match, response_y_n, swapping;
int counter, enrollment_file, increment, max_records, max_enrollment, row,
row_max, row_min, total_enrollment;
string course_name_file, instructor_last_name_file, search_target, enter_to_continue;

int enrollment[10];
int index[10];
string course_name[10];
string duplicate_array[10];
string instructor_last_name[10];

ofstream fout;
ifstream fin;

void check_response();
void class_by_instructor();
void class_by_name();
void create_data_file();
void load_data();
void menu();
void obtain_ins_name_enrollment();
void search();
void settings();
void sort_data();

int main()
{
	settings();
	cout << "Is enrollment data already available? Y or N: ";
	cin >> response_y_n;
	check_response();
	while (response_y_n == 'N')
	{
		create_data_file();
	}

	menu();

		while (choice != 'X')
		{
			switch (choice)
			{
			case 'L':
				load_data();
				cout << "Locked and loaded!" << endl;
				system("pause");
				break;

			case 'N':
				class_by_name();
				break;

			case 'I':
				class_by_instructor();
				break;

			case 'O':
				obtain_ins_name_enrollment();
				break;

			default:
				cout << "invalid entry" << endl;
				system("pause");
				break;
			}
			menu();
		}
	system("pause");
	return 0;
}

void check_response()
{
	response_y_n = toupper(response_y_n);
	while (response_y_n != 'Y' && response_y_n != 'N')
	{
		cout << "Incorrect Response." << endl;
		cout << "Enter a 'Y' for Yes or a 'N' for No." << endl;
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	while (enrollment_file > max_enrollment)
	{
		cout << "Incorrect Response." << endl;
		cout << "Maximum Enrollment allowed is 25 students." << endl;
		cout << "Re-enter Number of Students Enrolled: ";
		cin >> enrollment_file;
	}
}

void class_by_instructor()
{
	for (increment = 0; increment < max_records; increment++)
	{
		duplicate_array[increment] = instructor_last_name[increment];
	}
	sort_data();
	system("cls");
	cout << "		ALPHABETICAL CLASS LISTING BY INSTRUCTOR NAME" << endl << endl;
	cout << "INSTRUCTOR	CLASS NAME	ENROLLMENT" << endl << endl;
	for (increment = 0; increment < max_records; increment++)
	{
		cout << instructor_last_name[index[increment]] << "   	" << course_name[index[increment]]
			<< "    	    " << enrollment[index[increment]] << endl;
	}
	cout << endl << endl << "Press the Enter or Return Key" << endl;
	cout << "To Return to the Main Menu";
	getline(cin, enter_to_continue);
	getline(cin, enter_to_continue);
}

void class_by_name()
{
	for (increment = 0; increment < max_records; increment++)
	{
		duplicate_array[increment] = course_name[increment];
	}
	sort_data();
	system("cls");
	cout << "		ALPHABETICAL CLASS LISTING BY CLASS NAME" << endl << endl;
	cout << "CLASS NAME	INSTRUCTOR	ENROLLMENT" << endl << endl;
	for (increment = 0; increment < max_records; increment++)
	{
		cout << course_name[index[increment]] << "		" << instructor_last_name[index[increment]]
			<< "    	    " << enrollment[index[increment]] << endl;
		total_enrollment = total_enrollment + enrollment[index[increment]];
	}
	cout << endl << endl << "Total Enrollment: " << total_enrollment << endl << endl;
	cout << "Press the Enter or Return Key" << endl;
	cout << "To Return to the Main Menu";
	getline(cin, enter_to_continue);
	getline(cin, enter_to_continue);
}
void create_data_file()
{
	fout.open("f:school.dat");
	for (increment = 0; increment < max_records; increment++)
	{
		system("cls");
		cout << "Please enter the following information:" << endl << endl;
		cout << "Name of Course.................";
		cin >> course_name_file;
		cout << "Instructor's Last Name.........";
		cin >> instructor_last_name_file;
		cout << "Number of Students Enrolled....";
		cin >> enrollment_file;
		fout << course_name_file << " " << instructor_last_name_file << " "
			<< enrollment_file << endl;
	}
	response_y_n = 'Y';
	fout.close();
}

void load_data()
{
	fin.open("f:school.dat");
	fin >> course_name[0] >> instructor_last_name[0] >> enrollment[0];
	while (!fin.eof())
	{
		fin >> course_name[counter] >> instructor_last_name[counter] >> enrollment[counter];
		counter = counter++;
	}
	fin.close();
}

void menu()
{
	system("cls");
	cout << "		CLASS MENU" << endl << endl;
	cout << "Code			Function" << endl << endl;
		cout << "L.......................'L'oad Data to Process" << endl;
		cout << "N.......................List Class by 'N'ame" << endl;
		cout << "I.......................List Class by 'I'nstructor" << endl;
		cout << "O.......................'O'btain Instructor Name and Enrollment" << endl;
		cout << "X.......................To e'X'it" << endl << endl;
		cout << "Please enter which code you would like to execute: ";
		cin >> choice;
		choice = toupper(choice);
}

void obtain_ins_name_enrollment()
{
	system("cls");
	cout << "		Search for Instructor and Enrollment" << endl << endl;
	cout << "	Please enter Class Name: ";
	cin >> search_target;
	search();
	if (match == 'Y')
	{
		cout << endl << "	The instructor for class " << course_name[index[row]] << " is "
			<< instructor_last_name[index[row]] << " and there are " << endl;
		cout << "	" << enrollment[index[row]] << " students enrolled." << endl << endl;
	}
	else
	{
		cout << endl << "	Course not found." << endl << endl;
	}
	cout << "Press the Enter or Return Key" << endl;
	cout << "To Return to the Main Menu";
	getline(cin, enter_to_continue);
	getline(cin, enter_to_continue);
}

void search()
{
	for (increment = 0; increment < max_records; increment++)
	{
		duplicate_array[increment] = course_name[increment];
	}
	sort_data();
	match = 'N';
	row_min = 0;
	row_max = max_records;
	while (match == 'N' && row_min <= row_max)
	{
		row = int((row_min + row_max) / 2);
		if (search_target < course_name[index[row]])
		{
			row_max = row - 1;
		}
		else
		if (search_target >course_name[index[row]])
		{
			row_min = row + 1;
		}
		else
		{
			match = 'Y';
		}
	}
}

void settings()
{
	enrollment_file = 0;
	choice = 'B';
	counter = 1;
	max_enrollment = 25;
	max_records = 6;
	row_min = 0;
}

void sort_data()
{
	for (increment = 0; increment < max_records; increment++)
	{
		index[increment] = increment;
	}
	swapping = 'Y';
	while (swapping == 'Y')
	{
		swapping = 'N';
		for (increment = 0; increment < max_records - 1; increment++)
		{
			if (duplicate_array[increment] > duplicate_array[increment + 1])
			{
				swap(duplicate_array[increment], duplicate_array[increment + 1]);
				swap(index[increment], index[increment + 1]);

				swapping = 'Y';
			}
		}
	}
}