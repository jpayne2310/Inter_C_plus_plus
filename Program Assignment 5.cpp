/*
James Payne
SE 124.02
Programming Assignment Five

Purpose: This program will search payroll data to determine whether an employee has earned 
overtime.  The user will be allowed to create their own payroll data file or to use an existing
file to perform individual employee payroll searches.  A brief summary will be printed if the
file is or is not found.  Once the user is done looking up individual files, the program will
print an overtime summary if any employees were eligiable.

Variable Dictionary:

Variable Names				Type			Represents
empid						integer			search condition
employee_id					integer			employee identifacation number
employee_counter			interger		Total number of employees in data file
employee_id_file			integer			inputted employee identifacation number
first_name					string			first name of employee
first_name_file				string			inputted first name of employee
hours_worked				integer			number of hour employee worked
hours_worked_file			integer			inputted number of hour employee worked
last_name					string			last name of employee
last_name_file				string			inputted last name of employee
match						character		search condition
ot_compensation				double			overtime calculation
rate_of_pay					double			employee rate of pay
rate_of_pay_file			double			inputted employee rate of pay
response_y_n				character		Y for yes or N for no
row_max						integer			search condition
row_min						integer			search condition
standard_work_week			integer			hours in a standard work week
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char create_file_c_e = 'E', match, response_y_n;						//variables declared
double ot_compensation, ot_pay, rate_of_pay_file, total_ot_pay;
int empid, employee_counter, employee_id_file, hours_worked_file, ot_hours, row, row_max, 
row_min, standard_work_week, employees_ot_eligible;
string first_name_file, last_name_file;

int employee_id[20];
string last_name[20];
string first_name[20];
double rate_of_pay[20];
int hours_worked [20];

ofstream fout;															//referenced data file
ifstream fin;

void check_response();													//functions declared
void create_data_file();
void input();
void retrieve_data();
void settings();
void get_target();
void search();
void successful();
void unsuccessful();
void final_summary();

int main()
{																		//check to run
	cout << "Would you like to run the Payroll Overtime Analyst Program? Y on N: ";
	cin >> response_y_n;
	check_response();													//validate response

	if (response_y_n == 'Y')
	{
		system("cls");
		cout << "Please enter a 'C' if you would like to 'C'reate a Payroll data file." << endl;
		cout << "Or enter an 'E' to use the 'E'xesisting Payroll data file: ";
		cin >> create_file_c_e;
		create_file_c_e = toupper(create_file_c_e);
		check_response();												//validate response
	}
	if (create_file_c_e == 'C')
	{
		create_data_file();												//create data file if necessary
	}
	
		settings();														//call settings
		retrieve_data();												//call retrieve data
	
	while (response_y_n == 'Y')
	{
		get_target();													//call get target
		search();														//call search

		cout << "Would you like to look up another employee? Y or N: "; //check to run again
		cin >> response_y_n;
		check_response();												//validate response
	}
	if (employees_ot_eligible > 0)
	{
		final_summary();												//call final summary
	}																	//if program ran
	system("pause");
	return 0;
}

void check_response()													//validate response
{
	response_y_n = toupper(response_y_n);
	while (response_y_n != 'Y' && response_y_n != 'N')
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a Y for Yes or a N for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}
	while (create_file_c_e != 'C' && create_file_c_e != 'E')
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a 'C' if you would like to 'C'reate a Payroll data file." << endl;
		cout << "Or enter an 'E' to use the 'E'xesisting Payroll data file: ";
		cin >> create_file_c_e;
		create_file_c_e = toupper(create_file_c_e);
	}
}

void create_data_file()													//create a data file
{
	fout.open("f:payroll_file.txt");									//open file to be created
	while (create_file_c_e == 'C')
	{
		input();														//call input

		fout << employee_id_file << " " << last_name_file << " " << first_name_file 
			<< " " << rate_of_pay_file << " " << hours_worked_file << endl;

		cout << "Would you like to create another employee record?" << endl;
		cout << "Enter a C to create or E to exit: ";					//check to create
		cin >> create_file_c_e;											//another record
		create_file_c_e = toupper(create_file_c_e);
		check_response();												//validate response
	}
	fout.close();														//close data file
}

void input()															//get information 
{																		//from user
	system("cls");
	cout << "Please enter the following employee information:" << endl << endl;
	cout << "	ID Number: ";
	cin >> employee_id_file;
	cout << "	Last Name: ";
	cin >> last_name_file;
	cout << "	First Name: ";
	cin >> first_name_file;
	cout << "	Rate of Pay: ";
	cin >> rate_of_pay_file;
	cout << "	Hours Worked: ";
	cin >> hours_worked_file;
}

void settings()
{
	employee_counter = 0;												//set starting value of accumulators
	employees_ot_eligible = 0;
	total_ot_pay = 0;

	standard_work_week = 40;											//set starting value of descriptive variables
	ot_compensation = 1.5;

	cout.setf(ios::fixed, ios::floatfield);								//set format numeric output
	cout.setf(ios::showpoint);
	cout.precision(2);

}

void retrieve_data()													//load data from file into array
{
	fin.open("f:payroll_file.txt");										//open data file
	fin >> employee_id[0] >> last_name[0] >> first_name[0] >> rate_of_pay[0] >> hours_worked[0];
	row = 1;
	while (!fin.eof())													//set to run till end of file
	{
		fin >> employee_id[row] >> last_name[row] >> first_name[row] 
			>> rate_of_pay[row] >> hours_worked[row];
		row = row++;
		employee_counter = employee_counter++;
	}
	fin.close();														//close data file
}

void get_target()														//get information to search for
{
	system("cls");
	cout << "Please enter the ID number of the employee you would like to enquire about."
		<< endl << endl;
	cout << "Employee ID number: ";
	cin >> empid;
}

void search()															//preform search
{
	match = 'N';														//search conditions set
	row_min = 0;
	row_max = employee_counter;
	while (match == 'N' && row_min <= row_max)
	{
		row = int((row_min + row_max) / 2);
		if (empid < employee_id[row])
		{
			row_max = row - 1;
		}
		else

			if (empid > employee_id[row])
			{
			row_min = row + 1;
			}
			else
			{
				match = 'Y';
			}
		
	}
	if (match == 'Y')
	{
		successful();													//call successful
	}
	else
	{
		unsuccessful();													//call unsuccessful
	}
}

void successful()														//output results of
{																		//found information
	if (hours_worked[row] > standard_work_week)
	{
		ot_hours = hours_worked[row] - standard_work_week;				//calculate overtime hours
		ot_pay = ot_hours * ot_compensation * rate_of_pay[row];			//calculate overtime pay
		total_ot_pay = total_ot_pay + ot_pay;							//increment total overtime pay
		employees_ot_eligible++;										//increment eligible employees 

		cout << first_name[row] << " " << last_name[row] << " has worked " << ot_hours
			<< " hours of overtime " << endl << "and is eligible for $" << ot_pay
			<< " overtime pay." << endl << endl;
	}
	else
	{																	//output not eligible statement
		cout << first_name[row] << " " << last_name[row]
			<< " is not eligible for overtime pay." << endl;
	}
}

void unsuccessful()														//search information not found
{
	cout << "Employee not found." << endl;
}

void final_summary()													//output final summary
{
	system("cls");
	cout << "The total number of employees eligible for overtime pay is: " 
		<< employees_ot_eligible << endl;
	cout << "The total amount of money paid in overtime to those employee is $" 
		<< total_ot_pay << endl;
}