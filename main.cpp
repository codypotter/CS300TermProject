/**
 * Created by Bela, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson, Max VanRaden
 */

#include <string>
#include <iostream>
#include "Database.h"
#include "Provider.h"
#include "Service.h"

using namespace std;

int main(int argc, char** argv) {
	Database database((char*) "data/sample-db.json");

	cout <<  " __        __   __" << endl;
	cout << "/  ` |__| /  \\ /  `  /\\  |\\ |" << endl;
	cout << "\\__, |  | \\__/ \\__, /~~\\ | \\|" << endl << endl;
	cout << "Welcome to the ChocAn Simulator." << endl;
	cout << "Would you like to simulate the (m)anager terminal or the (p)rovider terminal?" << endl;
	char res = 0;
	while(res != 'm' && res != 'p') {
		cin >> res;
		if(res != 'm' && res != 'p')
			cout << "Invalid input. Type 'm' for the manager terminal or 'p' for the provider terminal." << endl;
	}

	char choice = 0;
	if(res == 'm') {
		do {
			cout << "Welcome to the manager terminal. Please select an option." << endl;
			cout << "TEST" << endl;
			cout << "(a) Add a new provider" << endl;
			cout << "(b) Add a new member" << endl;
			cout << "(c) Edit a provider or member" << endl;
			cout << "(d) Delete a provider or member" << endl;
			cout << "(x) Exit" << endl;
			cin >> choice;
		}
		while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice !='x');

		switch(choice) {
			case 'a':
				break;
			case 'b':
				break;
			case 'c':
				break;
			case 'd':
				break;
			case 'x':
				break;
		}
	}

	if(res == 'p') {
		do {
			cout << "Welcome to the provider terminal. Please select an option." << endl;
			cout << "(a) View the provider directory" << endl;
			cout << "(b) Provide service" << endl;
			cout << "(x) Exit" << endl;
			cin >> choice;
		}
		while(choice != 'a' && choice != 'b' && choice != 'x');

		switch(choice) {
			case 'a':
				cout << "List of services:" << endl;
				for(auto pair : database.directory)
				{
					string ID = pair.first;
					ServiceEntry service = pair.second;

					cout << "Service name: " << service.name << endl;
					cout << "Service code: " << service.id << endl;
					cout << "Service fee: $" << service.fee << endl;
				}
				break;
			case 'b':
				{
					string memID = "";
					cout << "Provide a Service:" << endl;
					cout << "Please enter member ID number: (9 digits)" << endl;
					cin >> memID;
					if(database.members.find(memID) == database.members.end()) {
						cout << "Invalid member ID" << endl;
						break;
					}
					if(database.members.at(memID).isValid != true) {
						cout << "Member status invalid" << endl;
						break;
					}
					else {
						string servCode = "";
						cout << "Enter a service code: (6 digits)" << endl;
						cin >> servCode;

						if(database.directory.find(servCode) == database.directory.end()) {
							cout << "Invalid service code" << endl;
							break;
						}
						else {
							string currDate = "";
							string servDate = "";
							cout << "Enter the current date: (mm/dd/yyyy)" << endl;
							cin >> currDate;
							cout << "Enter the expected service date: (mm/dd/yyyy)" << endl;
							cin >> servDate;
							//create new service object here with collected data
						}
					}
				}
				break;
			case 'x':
				break;
		}
	}

	return 0;
}
