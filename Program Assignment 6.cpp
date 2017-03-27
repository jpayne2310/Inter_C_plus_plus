/*
James Payne
SE 124.02
Program Assignment 6

Purpose: To create two Charter Passenger Load Reports from user entered data.  The program will output 
one CPLR with the data sorted by Airline name.  The other CPLR will be generated with the same data, 
but sorted using the destination.  Once the two CPLRs have been viewed by the user, the program will 
exit out.

Variable Dictionary:

Variable Name				Type			Represents
airline_name				string			name of airline
airline_flight_number		integer			airline fight number
array_counter				integer			array counter
charter_number				integer			data entry reference
destination					string			destination of flight
duplicate_array				string			reference for sort
enter_to_continue			string			press enter to continue
increment					integer			incrementing variable
index						integer			reference for sort results
input_max					integer			changeable maximum for inputted data
passenger_load				integer			number of passengers on flight
passenger_load_max			integer			maximum number of passengers allowed on flight
passenger_load_min			integer			minimum number of passengers per fight
swapping					character		sort condition
total_passengers			integer			total number of passengers on all flights
*/

#include <iostream>
#include <string>

using namespace std;

char swapping;																//variables declared
int array_counter, charter_number, increment, input_max, passenger_load_max,
passenger_load_min, total_passengers;
string enter_to_continue;

int airline_flight_number[10];												//arrays declared
int passenger_load[10];
string airline_name[10];
string destination[10];
string duplicate_array[10];
int index[10];

void build_inputted_array();												//functions declared
void check_response();
void create_duplicate_airline_name_array();
void create_duplicate_destination_array();
void sort_data();
void heading();
void report_alphabetical_airline_name();
void report_alphabetical_destination();
void settings();

int main()
{
	settings();																//call settings
	build_inputted_array();													//call build inputted array
	report_alphabetical_airline_name();										//call report airline name
	report_alphabetical_destination();										//call report destination
	system("pause");
	return 0;
}

void sort_data()															//sort data to alphabetize
{
	for (increment = 0; increment < array_counter; increment++)
	{
		index[increment] = increment;
	}

	swapping = 'Y';
	while (swapping == 'Y')
	{
		swapping = 'N';
		for (increment = 0; increment < array_counter - 1; increment++)
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

void build_inputted_array()
{
	for (array_counter = 0; array_counter < input_max; array_counter++)				//load array
	{
		heading();															//call heading
		cout << "	Airline Name----------->";
		cin >> airline_name[array_counter];
		cout << "	Airline Flight Number-->";
		cin >> airline_flight_number[array_counter];
		cout << "	Destination------------>";
		cin >> destination[array_counter];
		cout << "	Passenger Load--------->";
		cin >> passenger_load[array_counter];
		check_response();													//validate response
	}
	getline(cin, enter_to_continue);										//trip continue condition

}

void create_duplicate_airline_name_array()									//create a duplicate array
{																			//for sort 
	for (increment = 0; increment < array_counter; increment++)
	{
		duplicate_array[increment] = airline_name[increment];
	}
}

void create_duplicate_destination_array()									//create a duplicate array
{																			//for sort 
	for (increment = 0; increment <= array_counter; increment++)
	{
		duplicate_array[increment] = destination[increment];
	}
}

void check_response()														//requirements for 
{																			//passenger_load variable
	while (passenger_load[array_counter] < passenger_load_min || passenger_load[array_counter] > 
		passenger_load_max)
	{
		cout << "Incorrect response." << endl;
		cout << "Passenger load must be at least " << passenger_load_min << endl
			<< "and no more than " << passenger_load_max << endl;
		cout << "	Passenger Load--------->";
		cin >> passenger_load[array_counter];
	}
}

void heading()																//heading for inputted data
{
	system("cls");
	cout << "	ABC TRAVEL AGENCY" << endl << endl << endl;
	cout << "Charter Number---->" << " " << charter_number;
	cout << endl<< endl << endl;
	charter_number = charter_number++;
}

void report_alphabetical_airline_name()										//passenger load report by
{																			//alphabetical airline name
	system("cls");
	cout << "			ABC TRAVEL AGENCY" << endl;
	cout << "		  CHARTER PASSENGER LOAD REPORT" << endl << endl << endl;
	cout << "AIRLINE		FLIGHT	DESTINATION	PASSENGER" << endl;
	cout << "NAME		NUMBER			LOAD" << endl << endl;
	create_duplicate_airline_name_array();									//call duplicate array creator
	sort_data();															//call sort data
	for (increment = 0; increment < array_counter; increment++)
	{
		cout << airline_name[index[increment]] << "		" << airline_flight_number[index[increment]] 
			<< "	" << destination[index[increment]] << "   	" << passenger_load[index[increment]] 
			<< endl;
	}
	cout << endl << endl << "END OF PASSENGER REPORT";
	cout << endl << endl << "PRESS ENTER OR RETURN KEY" << endl;			//continue condition
	cout << "TO CONTINUE:";
	getline(cin, enter_to_continue);
}

void report_alphabetical_destination()										//passenger load report by
{																			//alphabetical destination
	system("cls");
	cout << "			ABC TRAVEL AGENCY" << endl;
	cout << "		  CHARTER PASSENGER LOAD REPORT" << endl << endl << endl;
	cout << "AIRLINE		FLIGHT	DESTINATION	PASSENGER" << endl;
	cout << "NAME		NUMBER			LOAD" << endl << endl;
	create_duplicate_destination_array();									//call duplicate array creator
	sort_data();															//call sort data
	for (increment = 0; increment < array_counter; increment++)
	{
		cout << airline_name[index[increment]] << "		" << airline_flight_number[index[increment]] 
			<< "	" << destination[index[increment]] << "   	" << passenger_load[index[increment]] 
			<< endl;
		total_passengers = total_passengers + passenger_load[index[increment]];
	}
	cout << endl << endl << "TOTAL PASSENGER: " << total_passengers << endl << endl;
	cout << "END OF PASSENGER REPORT";
	cout << endl << endl << "PRESS ENTER OR RETURN KEY" << endl;
	cout << "TO CONTINUE:";													//continue condition
	getline(cin, enter_to_continue);
}

void settings()
{
	array_counter = 0;														//starting value for
	charter_number = 1;														//counters
	total_passengers = 0;
	
	input_max = 6;															//values set to 
	passenger_load_max = 275;												//changeable variables 
	passenger_load_min = 50;
}