/*
James Payne
SE 124.02
Programming Assignment Three

Purpose: This program will analyze test scores for students in a class.  The user will be given 
the option to input students' information, including test scores.  This input will be stored in 
a sequential file named 'class_grades_report.txt'.  If the user chooses not to enter the students'
information, than the program will use an existing file.  Information from the file 
'class_grades_report.txt' will be used to process student test scores into letter grades for 
each student.  A summary report will be generated with individual results for each student along
with the number of students processed and the amount of each letter grade issued.

Variable Dictionary:

Variable Names				Type				Represents
class_average				double				average test score of class
first_name					string				first name of student
last_name					string				last name of student
letter_grade				character			letter grade for student's test score
respomse_y_n				character			'Y' for yes or 'N' for no
students_processed			integer				number of students processed
test_score					integer				test score of student
total_As_received			integer				total amount of A's the class received
total_Bs_received			integer				total amount of B's the class received
total_Cs_received			integer				total amount of C's the class received
total_Ds_received			integer				total amount of D's the class received
total_Fs_received			integer				total amount of F's the class received
total_scores				double				total of all class scores
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char response_y_n, letter_grade;						//declared variables

double class_average, total_scores;

int students_processed, test_score, total_As_received, total_Bs_received,
total_Cs_received,total_Ds_received, total_Fs_received;

string first_name, last_name;

ofstream fout;											//referance data file
ifstream fin;

void settings();										//declared functions
void check_response();
void build_disk_file();
void input();
void heading();
void retrieve_disk_file();
void processing();
void output_summary();

int main()
{														//check to run
	cout << "Would you like to process test scores? Y or N:";
	cin >> response_y_n;
	response_y_n = toupper(response_y_n);

	check_response();									//call check_response

	if (response_y_n == 'Y')
	{
		settings();										//call settings

		cout << "Would you like to create a data "		//check if file needs to be created
			<< "file? Y or N: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);

		check_response();								//call check_response

		if (response_y_n == 'Y')
		{
			build_disk_file();							//call build_disk_file
		}

		heading();										//call heading
		retrieve_disk_file();							//call retrieve_disk_file
		output_summary();								//call output_summary
	}

	system("pause");
	return 0;
}

void settings()
{
	students_processed = 0;								//beginning value assigned
	total_As_received = 0;
	total_Bs_received = 0;
	total_Cs_received = 0;
	total_Ds_received = 0;
	total_Fs_received = 0;
	total_scores = 0;

	cout.setf(ios::fixed, ios::floatfield);				//format for output
	cout.setf(ios::showpoint);
	cout.precision(2);
}

void check_response()									//validate response
{
	while (response_y_n != 'Y' && response_y_n != 'N')
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a Y for Yes or a N for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}
}

void build_disk_file()									//
{
	fout.open("e:class_grades_report.txt");
	while (response_y_n == 'Y')
	{
		input();

		fout << first_name << " " << last_name << " " << test_score
			<< endl;

		cout << "Would you like to enter another student? Y or N: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);

		check_response();
	}
	fout.close();
}

void input()
{
	system("cls");

	cout << "Please enter the following information:" << endl << endl;
	cout << "Student's first name: ";
	cin >> first_name;
	cout << "Student's last name: ";
	cin >> last_name;
	cout << "Student's test score: ";
	cin >> test_score;

	while (test_score < 0 || test_score > 100)
	{
		cout << "Incorrect response." << endl;
		cout << "Test score must fall between 0 and 100." << endl;
		cout << "Please re-enter student's test score: ";
		cin >> test_score;
	}
}

void retrieve_disk_file()
{
	fin.open("e:class_grades_report.txt");

	fin >> first_name >> last_name >> test_score;
	while (!fin.eof())
	{
		processing();
		cout << "		   " << first_name << "       		  " << last_name << "   		  "
			<< letter_grade << endl;
		fin >> first_name >> last_name >> test_score;
	}
	fin.close();
}

void processing()
{
	students_processed = students_processed++;
	total_scores = total_scores + test_score;

		if (test_score >= 90)
		{
			letter_grade = 'A';
			total_As_received = total_As_received++;
		}
	else
		if (test_score >= 80)
		{
			letter_grade = 'B';
			total_Bs_received = total_Bs_received++;
		}
	else
		if (test_score >= 70)
		{
			letter_grade = 'C';
			total_Cs_received = total_Cs_received++;
		}
	else
		if (test_score >= 60)
		{
			letter_grade = 'D';
			total_Ds_received = total_Ds_received++;
		}
	else
	{
		letter_grade = 'F';
		total_Fs_received = total_Fs_received++;
	}
}

void heading()
{
	system("cls");
	cout << "				   CLASS GRADE REPORT" << endl << endl;
	cout << "		First name		Last name		Grade" << endl << endl;
}

void output_summary()
{
	cout << endl << endl;
	cout << "Total students processed		" << students_processed << endl;
	cout << "Total students receiving an A		" << total_As_received << endl;
	cout << "Total students receiving an B		" << total_Bs_received << endl;
	cout << "Total students receiving an C		" << total_Cs_received << endl;
	cout << "Total students receiving an D		" << total_Ds_received << endl;
	cout << "Total students receiving an F		" << total_Fs_received << endl;
	class_average = total_scores / students_processed;
	cout << "Average score for the class		" << class_average << endl;
}