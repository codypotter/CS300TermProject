/**
 * Created by Bela, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson, Max VanRaden
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include "Database.h"

void getMember(Database & database);
void getProvider(Database & database);
void deleteMember(Database & database);
void deleteProvider(Database & database);
void changeMember(Database & database);
void changeProvider(Database & database);

using namespace std;

void printHeader(char target) {
	switch(target)
	{
		case 'c':
			cout <<  " __        __   __" << endl;
			cout << "/  ` |__| /  \\ /  `  /\\  |\\ |" << endl;
			cout << "\\__, |  | \\__/ \\__, /~~\\ | \\|" << endl << endl;
			break;
		case 'm':
			cout << "   __  ___                              ______              _           __" << endl;
			cout << "  /  |/  /__  ___  ___  ___  ___ ____  /_  __/__ ______ _  (_)__  ___ _/ /" << endl;
			cout << " / /|_/ / _ `/ _ \\/ _ `/ _ `/ -_) __/   / / / -_) __/  ' \\/ / _ \\/ _ `/ /" << endl;
			cout << "/_/  /_/\\_,_/_//_/\\_,_/\\_, /\\__/_/     /_/  \\__/_/ /_/_/_/_/_//_/\\_,_/_/" << endl;
			break;
		case 'p':
			cout << " ___             _    _           _____              _           _ " << endl;
			cout << "| _ \\_ _ _____ _(_)__| |___ _ _  |_   _|__ _ _ _ __ (_)_ _  __ _| |" << endl;
			cout << "|  _/ '_/ _ \\ V / / _` / -_) '_|   | |/ -_) '_| '  \\| | ' \\/ _` | |" << endl;
			cout << "|_| |_| \\___/\\_/|_\\__,_\\___|_|     |_|\\___|_| |_|_|_|_|_||_\\__,_|_|" << endl;
			break;
	}
}

string getCurrentDate() {
	time_t now = time(0);
	tm* localTime = localtime(&now);
	string year = to_string(localTime->tm_year - 100);
	string month = to_string(localTime->tm_mon + 1);
	string day = to_string(localTime->tm_mday);
	return (month + "-" + day + "-" + year);
}

void generateMemberReports(Database db) {
	ofstream report;
	for (auto pair : db.members) {
		Member person = pair.second;
		string currDate = getCurrentDate();
		string filename = "reports/memberReports/" + person.name + "-" + currDate + ".txt";
		report.open (filename);
		report << "Name: " << person.name;
		report << "\nID: " << person.id;
		report << "\nAddress: " << person.street;
		report << "\nCity: " << person.city;
		report << "\nState: " << person.state;
		report << "\nZIP: " << person.zip;
		report << "\nServices:\n";
		for (string i : person.services) {	
			string code = db.services.at(i).serviceCode;
			report << "\nService Provided: " << db.directory.at(code).name;
			report << "\nProvider: " << db.services.at(i).providerID;
			report << "\nDate of Service: " << db.services.at(i).serviceDate << "\n";
		}
		report.close();
	}
	cout << "Reports generated successfully!" << endl;
}

void generateProviderReports(Database db) {
	ofstream report;
	for (auto pair : db.providers) {
		Provider helper = pair.second;
		string currDate = getCurrentDate();
		int totalFee = 0;
		int totalVisits = 0;
		string filename = "reports/providerReports/" + helper.name + "-" + currDate + ".txt";
		report.open (filename);
		report << "Name: " << helper.name;
		report << "\nID: " << helper.id;
		report << "\nAddress: " << helper.street;
		report << "\nCity: " << helper.city;
		report << "\nState: " << helper.state;
		report << "\nZIP: " << helper.zip;
		report << "\nServices Provided: \n";
		for (string i : helper.services) {
			string memberID = db.services.at(i).memberID;
			string code = db.services.at(i).serviceCode;
			int fee = db.directory.at(code).fee;
			report << "\nDate of service: " << db.services.at(i).serviceDate;
			report << "\nDate of submission: " << db.services.at(i).submissionDate;
			report << "\nMember Name: " << db.members.at(memberID).name;
			report << "\nMember ID: " << memberID;
			report << "\nService Code: " << code;
			report << "\nService Type: " << db.directory.at(code).name;
		       	report << "\nFee for Service: $" << fee << "\n";
			totalFee+=fee;
			totalVisits++;
		}
		report << "\nTotal number of services provided: " << totalVisits;
		report << "\nTotal fee: $" << totalFee;
		report.close();
	}
	cout << "Reports generated successfully!" << endl;
  }
  
void printDirectory(Database db) {
	cout << "List of services:" << endl;
	for(auto pair : db.directory)
	{
		cout << "Service Code: " << pair.first << endl;
		cout << "Name: " << pair.second.name << endl;
		cout << "Fee: " << pair.second.fee << endl << endl;
	}
}

//There is a database verion of this called validateMemID that takes an ID as a string and returns
//true or false depending on if the ID is valid
string validateMember(Database db) {
	string memID = "";
	cout << "Please enter member ID number: (9 digits)" << endl;
	cin.ignore(256, '\n');
	cin >> memID;
	if(db.members.find(memID) == db.members.end())
	{
		cout << "Invalid member ID, please try again";
		return "null";
	}
	if(db.members.at(memID).isValid != true)
	{
		cout << "Member status invalid, cannot recieve services" << endl;
		return "null";
	}
	else
		return memID;
}
//There is a database verion of this called validateProvID that takes an ID as a string and returns
//true or false depending on if the ID is valid
string validateProvider(Database db) {
	string providerID = "";
	cout << "Please enter provider ID number: (9 digits)" << endl;
	cin.ignore(256, '\n');
	cin >> providerID;
	if(db.providers.find(providerID) == db.providers.end())
	{
		cout << "Invalid provider ID, please try again";
		return "null";
	}
	if(db.providers.at(providerID).isValid != true)
	{
		cout << "Provider status invalid, cannot recieve services" << endl;
		return "null";
	}
	else
		return providerID;
}

string verifyService(Database db) {
	string servCode = "";
	cout << "Enter a service code: (6 digits)" << endl;
	cin.ignore(256, '\n');
	cin >> servCode;
	if(db.directory.find(servCode) == db.directory.end())
	{
		cout << "Invalid service code" << endl;
		return "null";
	}
	else
		return servCode;
}

int main(int argc, char** argv) {
	printHeader('c');
	Database database((char*) "data/sample-db.json");

	cout << "Welcome to the ChocAn Simulator." << endl;
	cout << "Would you like to simulate the (m)anager terminal or the (p)rovider terminal?" << endl;
	char res = 0;
	while(res != 'm' && res != 'p') {
		cin.ignore(256, '\n');
		cin >> res;
		if(res != 'm' && res != 'p')
			cout << "Invalid input. Type 'm' for the manager terminal or 'p' for the provider terminal." << endl;
	}

	char choice = 0;
	if(res == 'm') {
		printHeader(res);
		string inputName;
		string inputStreet;
		string inputCity;
		string inputState;
		string inputZip;
		string inputID;
		do {
			cout << "Welcome to the manager terminal. Please select an option." << endl;
			cout << "(a) Add a new provider" << endl;
			cout << "(b) Add a new member" << endl;
			cout << "(c) Edit a provider" << endl;
			cout << "(d) Edit a member" << endl;
			cout << "(e) Delete a provider" << endl;
			cout << "(f) Delete a member" << endl;
			cout << "(g) Generate member reports" << endl;
			cout << "(x) Exit" << endl;
			cin.ignore(256, '\n');
			cin >> choice;
		}
		while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && choice != 'f' && choice != 'g' && choice !='x');

		switch(choice) {
			case 'a':     
				getProvider(database);
				break;
			case 'b':
				getMember(database);
				break;
			case 'c':
				changeProvider(database);
				break;
			case 'd':	
				changeMember(database);
				break;
			case 'e':
				deleteProvider(database);
				break;
			case 'f':
				deleteMember(database);
				break;
			case 'g':
				database.printMembers();
				generateMemberReports(database);
				break;
			case 'x':
				break;
		}
	}

	if(res == 'p') {
		string provID = "";
		cout << "Please enter provider number: (9 digits)" << endl;
		cin.ignore(256, '\n');
		cin >> provID;
		if(database.providers.find(provID) == database.providers.end())
		{
			cout << "Invalid provider ID" << endl;
			return 0;
		}
		printHeader(res);
		do {
			cout << "Welcome to the provider terminal" << endl;
			cout << "(a) View the provider directory" << endl;
			cout << "(b) Provide service" << endl;
			cout << "(c) Generate provider reports" << endl;
			cout << "(x) Exit" << endl;
			cin.ignore(256, '\n');
			cin >> choice;
		}
		while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'x');

		switch(choice) {
			case 'a':
				printDirectory(database);
				break;
			case 'b':
				{
					string memID = validateMember(database);
					if(memID == "null")
						break;
					string servCode = verifyService(database);
					if(servCode == "null")
						break;
					else
					{
						time_t now = time(0);
						tm* localTime = localtime(&now);
						//enter relevant dates
						string currDate = "";
						string servDate = "";
						string year = to_string(localTime->tm_year - 100);
						string month = to_string(localTime->tm_mon + 1);
						string day = to_string(localTime->tm_mday);
						string hour = to_string(localTime->tm_hour);
						string minute = to_string(localTime->tm_min);
						string second = to_string(localTime->tm_sec);
						currDate = month + "/" + day + "/" + year + " " + hour + ":" + minute + ":" + second;
						cout << "Enter the expected service date: (mm/dd/yyyy)" << endl;
						cin.ignore(256, '\n');
						cin >> servDate;

						//print summary
						cout << "Service Summary:" << endl;
						cout << "Date of Service: " << servDate << endl;
						cout << "Date of Submission: " << currDate << endl;
						cout << "Member ID: " << memID << endl;
						cout << "Provider ID: " << provID << endl;
						cout << "Service ID: " << servCode << endl;
						cout << "Fee: " << database.directory.at(servCode).fee << endl;
            
						string servID = database.addService(servDate, currDate, memID, provID, servCode, database.directory.at(servCode).fee);
						database.members.at(memID).services.push_back(servID);
						database.providers.at(memID).services.push_back(servID);
						database.update();
					}
				}
				break;
			case 'c':
				generateProviderReports(database);
				break;
			case 'x':
				break;
		}
	}

	return 0;
}
