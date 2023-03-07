// Copyright 2022 Leo Jang
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Customer {
	string LNAME;
	int ZONE;
	bool ACTIVE;
	Customer(const string& _LNAME, const int& _ZONE, const bool& _ACTIVE) {
		LNAME = _LNAME;
		ZONE = _ZONE;
		ACTIVE = _ACTIVE;
	}
};
int main(int argc, char** argv) {
	string Query_Type = argv[1];
	if (Query_Type == "q1")
	{
		string Customer_File_Name, ZoneCost_File_Name;
		Customer_File_Name = argv[2];
		ZoneCost_File_Name = argv[3];
		ifstream Customer_File_Input(Customer_File_Name);
		ifstream ZoneCost_File_Input(ZoneCost_File_Name);
		string Line_Input;
		vector<Customer> Customer_Array;
		for (int i = 0; getline(Customer_File_Input, Line_Input); i++)
		{
			if (i < 2)
				continue;
			string _LNAME;
			int _ZONE;
			bool _ACTIVE;
			stringstream Temp_Line(Line_Input);
			string Word;
			for (int j = 0; getline(Temp_Line, Word, ' '); )
			{
				if (j == 2)
					_LNAME = Word;
				if (Word != "")
				{
					_ACTIVE = Word[0] - '0';
					j++;
				}
			}
			_ZONE = Line_Input[135] - '0';
			Customer_Array.push_back(Customer(_LNAME, _ZONE, _ACTIVE));
		}
		vector<int> ID_Array;
		for (int i = 0; getline(ZoneCost_File_Input, Line_Input); i++)
		{
			if (i < 2)
				continue;
			stringstream Temp_Line(Line_Input);
			vector<string> Temp_Array;
			string Word;
			while(getline(Temp_Line, Word, ' '))
			{
				if (Word != "")
					Temp_Array.push_back(Word);
			}
			if (Temp_Array[1] == "Toronto")
				ID_Array.push_back(stoi(Temp_Array[0]));
		}
		for (int i = 0; i < Customer_Array.size(); i++)
		{
			bool check = False;
			for (int j = 0; j < ID_Array.size(); j++)
			{
				if (Customer_Array[i].ZONE == ID_Array[j])
					check = True;
			}
			if (check)
				cout << Customer_Array[i].LNAME << endl;
		}
	}
	return 0;
}
