#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Adress
{
private:
	string nameCity{};
	string nameStreet{};
	int numberHouse{};
	int numberPalace{};
public:
	Adress(const string& nameCity, const string& nameStreet, int numberHouse, int numberPalace) :
		nameCity(nameCity), nameStreet(nameStreet), numberHouse(numberHouse), numberPalace(numberPalace) { }
	string getOutputAdress() const
	{
		return nameCity + ", " + nameStreet + ", " + to_string(numberHouse) + ", " + to_string(numberPalace);
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	ifstream inputFile("in.txt");
	if (!inputFile.is_open()) cerr << "Error opening in.txt";

	int n;
	inputFile >> n;
	inputFile.ignore();

	Adress** adresses = new Adress*[n];
	for (int i{}; i < n; ++i)
	{
		string city, street, houseStr, palaceStr;

		getline(inputFile, city);
		getline(inputFile, street);
		getline(inputFile, houseStr);
		getline(inputFile, palaceStr);

		int houseNumber = stoi(houseStr);
		int palaceNumber = stoi(palaceStr);

		houseNumber = stoi(houseStr);
		palaceNumber = stoi(palaceStr);

		adresses[i] = new Adress(city, street, houseNumber, palaceNumber);
	}

	inputFile.close();

	ofstream outputFile("out.txt");
	if (!outputFile.is_open())
	{
		cerr << "Error opening out.txt";
	}
	outputFile << n << endl;
	for (int i{n - 1}; i >= 0; --i)
	{
		outputFile << adresses[i]->getOutputAdress() << endl;
	}
	outputFile.close();
	for (int i{}; i < n; i++)
	{
		delete adresses[i];
	}
	delete[] adresses;
	return EXIT_SUCCESS;
}