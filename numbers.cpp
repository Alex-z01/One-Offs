#include <iostream>
#include <math.h>
#include <sstream>
#include <string> 
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

string input;
string numString;

string names[] = { " ", "Mi", "Bi", "Tri", "Quadri", "Quinti", "Sexti", "Septi", "Octi", "Noni", "Deci"};
string suffix[] = { " ", "Deci", "Vigi", "Triginti",  };
string prefix[] = { " ", "Un", "Duo", "Tre", "Quattuor", "Quint", "Sext", "Sept", "Octo", "Novem" };

int main()
{
	cout << "Input Number" << endl;
	cin >> input;

	ofstream File("numbers.txt");
	File << input;

	File.close();

	string fileText; 
	ifstream ReadFile("numbers.txt");

	ReadFile >> numString;
	
	ReadFile.close();

	string s1;
	s1 = numString.substr(0, 3);
	float m = stoi(s1);
	m = m / 100;

	double fullNum = stod(numString);

	double _exp = round(floor(log10(fullNum)));
	int exponent = static_cast<int>(_exp);

	double V;

	if (exponent < 36 && exponent > 5)
	{
		if (exponent % 3 == 0)
		{
			V = 0;
		}
		if (exponent % 3 == 1)
		{
			V = 1;
		}
		if (exponent % 3 == 2)
		{
			V = 2;
		}

		double U = (exponent - V) / 3 - 1;
		int newU = static_cast<int>(U);

		string suffix = names[newU] + "llion";
		cout << "\n" << m << " " << suffix << endl;
	}

	if (exponent >= 36)
	{
		int remainder = exponent % 30;
		int num1 = exponent - remainder;
		int SuffixNum = num1 / 30;

		if (remainder % 3 == 0 || remainder % 3 == 3)
		{
			V = 0;
		}
		if (remainder % 3 == 1)
		{
			V = 1;
		}
		if (remainder % 3 == 2)
		{
			V = 2;
		}

		int PrefixNum;
		if (remainder % 3 == 0)
		{
			PrefixNum = remainder/3 - 1;
		}
		else 
		{
			PrefixNum = ((remainder - 1) / 3) - 1;
		}
		if (remainder == 0)
		{
			PrefixNum = 9;
		}
		cout << exponent << endl;
		if (V == 1)
		{
			m = m * 10;
		}
		if (V == 2)
		{
			m = m * 100;
		}
		cout << m << " " << prefix[PrefixNum] << suffix[SuffixNum] << "llion" << endl;
	}
	main();
}

