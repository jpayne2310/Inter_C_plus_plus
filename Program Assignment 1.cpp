/*
James Payne
SE 124.02
Programming Assignment One

Purpose: This program will determine the amount of dues owed by club members.  The dues will 
be based on type and length of membership.

Variable Dictionary:

Variable Name						Type				Represents
family_membership					character			membership type
family_non_vested_rate				double				family non-vestred membership rate
family_vested_rate					double				family vested membership rate
first_name							string				first name of account holder
first_run							character			program Initiator
individual_membership				character			membership type
individual_non_vested_rate			double				individual non-vestred membership rate
individual_vested_rate				double				individual vestred membership rate
last_name							string				last name of account holder
membership_dues						double				amount owed by membership account
membership_type						character			type of membership
response_y_n						character			'Y' for yes or 'N' for no
total_family_membership_dues		double				total of all family memberships
total_individual_membership_dues	double				total of all individual memberships
total_members_processed				integer				total number of memberships processed
vested_membership					integer				vested membership years requirment
years_of_membership					integer				amount for years of mmbership

*/

#include <iostream>
#include <string>
using namespace std;
																		//variables declared
char family_membership, first_run = 'Y', individual_membership, membership_type, response_y_n;
double family_non_vested_rate, family_vested_rate, individual_non_vested_rate, 
individual_vested_rate, membership_dues, total_family_membership_dues, 
total_individual_membership_dues;
int total_members_processed, vested_membership, years_of_membership;
string first_name, last_name;

void setup();															//functions declared
void input();
void process_record();
void output_record();
void output_final_totals();
void check_response();

int main() 
{																		//check to run
	cout << "Would you like to process membership dues? Y or N: ";
	cin >> response_y_n;
	response_y_n = toupper(response_y_n);
	check_response();													//call check_response function


	while (response_y_n == 'Y')
	{
		if (first_run == 'Y')											//initiate main while loop
		{
			setup();													//call setup function
			first_run = 'N';
		}

		input();														//call input function
		process_record();												//call process_record function
		output_record();												//call output_record function

		cout << "Would you like to enter another membership record? Y or N: ";
		cin >> response_y_n;											//check to see if to run again
		response_y_n = toupper(response_y_n);
		check_response();												//call check_response function

		
	}

	if (first_run == 'N')
	{
		output_final_totals();											//call output_totals
	}

	system("pause");
	return 0;															//end program
}

void setup()
{
	family_non_vested_rate = 1600.00;									//variable beginning values set
	family_vested_rate = 1200.00;										//changing variables values set
	individual_non_vested_rate = 1100.00;
	individual_vested_rate = 800.00;
	family_membership = 'F';
	individual_membership = 'I';
	total_family_membership_dues = 0;
	total_individual_membership_dues = 0;
	total_members_processed = 0;
	vested_membership = 7;

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);

}

void input()
{																		//get and assign user input
	system("cls");
	cout << "Please enter the following information for the membership record." << endl << endl;
	cout << "	First Name: ";
	cin >> first_name;
	cout << "	Last Name: ";
	cin >> last_name;
	cout << "	Type of membership: F for family or I for individual: ";
	cin >> membership_type;
	membership_type = toupper(membership_type);
	while (membership_type != 'F'  && membership_type != 'I')			//validate membership_type
	{
		cout << "Incorrect response." << endl;
		cout << "Enter F for family or I for individual: ";
		cin >> membership_type;
		membership_type = toupper(membership_type);
	}
	cout << "	Enter number for years of membership: ";
	cin >> years_of_membership;

}

void process_record()
{
	total_members_processed = total_members_processed++;				//increment total_members_processed
	if (membership_type == family_membership)							//process family_membership
	{
		if (years_of_membership < vested_membership)
		{
			membership_dues = family_non_vested_rate;
		}
		else
		{
			membership_dues = family_vested_rate;
		}																//increment total_family_
		total_family_membership_dues =									//membership_dues
			total_family_membership_dues + membership_dues;
	}
	if (membership_type == individual_membership)						//process individual_membership
	{
		if (years_of_membership < vested_membership)
		{
			membership_dues = individual_non_vested_rate;
		}
		else
		{
			membership_dues = individual_vested_rate;
		}																//increment total_individual_
		total_individual_membership_dues =								//membership_dues
			total_individual_membership_dues + membership_dues;
	}
}

void output_record()
{
	system("cls");														//output record summary
	cout << first_name << " " << last_name << " is a ";
	if (membership_type == 'F')
	{
		cout << "family ";
	}
	else
	{
		cout << "individual ";
	}
	cout << "member and annual dues are " << membership_dues << endl;
}

void output_final_totals()
{																		//output final results
	system("cls");
	cout << "Total members processed			" << total_members_processed << endl;
	cout << "Total family membership dues		" << total_family_membership_dues << endl;
	cout << "Total individual membership dues	" << total_individual_membership_dues << endl;
}

void check_response()
{
	while (response_y_n != 'Y' && response_y_n != 'N')					//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a Y for Yes or a N for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}
}