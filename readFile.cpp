#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	//open file
	ifstream input("contact.txt", ifstream::in);

	string line;
	vector<PersonInfo> persons;

	while(getline(input, line)) {
		PersonInfo person;
		istringstream record(line);
		record >> person.name;
		string phoneNum;
		while(record >> phoneNum) {
			person.phones.push_back(phoneNum);
		}
		persons.push_back(person);
	}

	//close file
	if (input.is_open()) {
		input.close();
	}

	cout << "The file contains " << persons.size() << " persons" << endl;

	for(auto itr = persons.cbegin(); itr != persons.cend(); ++itr) {
		cout << itr->name << "\t";
		for (auto ptr = (itr->phones).cbegin(); ptr != (itr->phones).cend(); ++ptr) {
			cout << *ptr << " ";
		}
		cout << endl;
	}	
	return 0;
}
