#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void search_lName();
void search_id_num();
void sort_lName();
void sort_id_num();
void load_array();
char ans;
int array_total = 0, number, increment, temp2;
string name1, name2, temp;

string fName[20];
string lName[20];
int id_num[20];
string dob[20];
int index[20];

void main()
{
	ifstream fin;
	fin.open("F:\\Bubble_Sort_with_Search\\search.txt");

	while(fin >> fName[array_total] >> lName[array_total] >> id_num[array_total] >> dob[array_total])
	{
		array_total++;
	}
	for(int x = 0; x < array_total; x++)
	{
		cout << lName[x] << id_num[x] << endl;
	}
	cout << "Would you like to searray_totalh by last name or ID_num?" << endl;
	cin >> ans;

	if(ans == 'l')
	{
		sort_lName();
		search_lName();
	}
	else
	{
		sort_id_num();
		search_id_num();
	}	
	system("pause");
}
void sort_lName()															//sort data to alphabetize
{
	//sort by last name
	
		for (int i = 0; i < array_total - 1; i++)
		{
			for( int r = 0; r < array_total - 1; r++)
			{
				if (lName[r] > lName[r + 1])
			{
				temp = lName[r];
				lName[r] = lName[r + 1];
				lName[r + 1] = temp; 

				temp = fName[r];
				fName[r] = fName[r + 1];
				fName[r + 1] = temp; 

				temp2 = id_num[r];
				id_num[r] = id_num[r + 1];
				id_num[r + 1] = temp2; 

				temp = dob[r];
				dob[r] = dob[r + 1];
				dob[r + 1] = temp; 
			}
		}
	}
}


void sort_id_num()															//sort data to alphabetize
{
	//sort by ID
	
		for (int i = 0; i < array_total - 1; i++)
		{
			for( int r = 0; r < array_total - 1; r++)
			{
				if (id_num[r] > id_num[r + 1])
			{
				temp2 = id_num[r];
				id_num[r] = id_num[r + 1];
				id_num[r + 1] = temp2; 

				temp = fName[r];
				fName[r] = fName[r + 1];
				fName[r + 1] = temp; 

				temp = lName[r];
				lName[r] = lName[r + 1];
				lName[r + 1] = temp; 

				temp = dob[r];
				dob[r] = dob[r + 1];
				dob[r + 1] = temp; 
			}
		}
	}
}

void search_id_num()
{
	int search_target;
	cout << "Please enter Last Name to search for: ";
	cin >> search_target;
	char match = 'N';
	int row;
	int row_min = 0;
	int row_max = array_total;
	row = (row_min + row_max) / 2;
	while (row_min < row_max && search_target !=id_num[row])
	{
		
		if (search_target < id_num[row])
		{
			row_max = row - 1;
		}
		if (search_target > id_num[row])
		{
			row_min = row + 1;
		}

		row = (row_min + row_max) / 2;
	}

	if(search_target == id_num[row])
	{
		cout << "Name: " << fName[row] << " " 
			<< lName[row] << endl;
		cout << "ID Number: " << id_num[row] 
		<< endl;
		cout << "Date of Birth: " << dob[row]
		<< endl;
	}
	else
	{	
		cout << "Record not found" << endl;
	}

}

void search_lName()
{
	string search_target;
	cout << "Please enter Last Name to search for: ";
	cin >> search_target;
	char match = 'N';
	int row;
	int row_min = 0;
	int row_max = array_total;
	row = (row_min + row_max) / 2;
	while (row_min < row_max && search_target !=lName[row])
	{
		
		if (search_target < lName[row])
		{
			row_max = row - 1;
		}
		if (search_target > lName[row])
		{
			row_min = row + 1;
		}

		row = (row_min + row_max) / 2;
	}

	if(search_target == lName[row])
	{
		cout << "Name: " << fName[row] << " " 
			<< lName[row] << endl;
		cout << "ID Number: " << id_num[row] 
		<< endl;
		cout << "Date of Birth: " << dob[row]
		<< endl;
	}
	else
	{	
		cout << "Record not found" << endl;
	}

}
