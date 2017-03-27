/*
James Payne
SE 124.02
Program Assignment Two

Purpose: To produce a sequential file that will contain airline flight data.  The program will
prompt the user for data needed to create the file.  The data will be sent to a file named
airline_data.txt.  A summary of the data in the file will be displayed to ensure data integrity.

Variable Dictionary:

Variable Names						Type				Represents
flight_destination					string				destination of flight
flight_number						integer				official flight number
flight_origin						string				origin of flight
number_of_passengers				integer				number of passengers on flight
response_y_n						character			'Y' for yes or 'N' for no
status_code							character			code for airline arrival status
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char response_y_n, status_code;									//variables declared
int flight_number, number_of_passengers;
string flight_destination, flight_origin;

ofstream fout;													//reference data file
ifstream fin;

void check_response();											//functions declared
void build_disk_file();
void output_summary();
void input();

int main()
{																//check to run
	cout << "Would you like to create a Flight Data file? Y or N: ";
	cin >> response_y_n;
	response_y_n = toupper(response_y_n);

	check_response();
	
	while (response_y_n == 'Y')									//main while loop
	{

		build_disk_file();

		output_summary();

	}
	system("pause");
	return 0;
}

void check_response()											//validates response
{
	while (response_y_n != 'Y' && response_y_n != 'N')
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a Y for yes of N for no: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}
}

void build_disk_file()											//create data file
{																//from user input
	fout.open("e:airline_data.txt");
	while (response_y_n == 'Y')
	{
		input();

		fout << flight_number << " " << flight_origin << " " << flight_destination << " "
			<< number_of_passengers << " " << status_code << endl;

		cout << "Would you like to enter another Flight Record? Y or N: ";
		cin >> response_y_n;									//check if more
		response_y_n = toupper(response_y_n);					//input is needed

		check_response();

	}
	fout.close();

	
}

void output_summary()											//creates a summary report with
{																//records retrieve from data file
	system("cls");

	cout << "Flight No	Origin		Destination	Passengers	Code" << endl << endl;

	fin.open("e:airline_data.txt");	

	fin >> flight_number >> flight_origin >> flight_destination >> number_of_passengers
		>> status_code;

	while (!fin.eof())
	{
		cout << "   " << flight_number << "		" << flight_origin << "		" << flight_destination 
			<< "		    " << number_of_passengers << "		 " << status_code << endl;
	
		fin >> flight_number >> flight_origin >> flight_destination >> number_of_passengers
			>> status_code;
	} 
	fin.close();
}

void input()													//receive and assign user input
{
	system("cls");

	cout << "Please enter the follow information:" << endl << endl;

	cout << "Flight number: ";
	cin >> flight_number;

	cout << "Origin of flight: ";
	cin >> flight_origin;

	cout << "Destination of flight: ";
	cin >> flight_destination;

	cout << "Number of passengers: ";
	cin >> number_of_passengers;

	cout << "Flight status code" << endl;
	cout << "	'O' for on time, 'D' for delayed, or 'C' for cancelled: " << endl;
	cout << "Status code: ";
	cin >> status_code;
	status_code = toupper(status_code);

	while (status_code != 'C' && status_code != 'D' && status_code != 'O')
	{															//validate status_code
		cout << "Incorrect coding." << endl;
		cout << "Please enter 'O' for on time, 'D' for delayed, or 'C' for cancelled: ";
		cin >> status_code;
		status_code = toupper(status_code);
	}
}