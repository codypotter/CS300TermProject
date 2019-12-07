//Created by Max VR on 12/01/2019

#include "Database.h"

using namespace std;

//Gathers input from user to pass to database addMember function
void getMember(Database & database) {
    string inputName;
    string inputStreet;
    string inputCity;
    string inputState;
    string inputZip;
    string newID;

    cout << "\nPlease enter the name of the member to add: ";
    getline(cin, inputName);
    cout << "\nPlease enter the street address of the member to add: ";
    getline(cin, inputStreet);
    cout << "\nPlease enter the name of the city in which the member is located: ";
    getline(cin, inputCity);
    cout << "\nPlease enter the state of the member to add: ";
    getline(cin, inputState);
    cout << "\nPlease enter the zip of the member to add: ";
    getline(cin, inputZip);
    newID = database.addMember(inputName, inputStreet, inputCity, inputState, inputZip);
    database.update();
    cout << "\n\nMember added to database and assigned ID: " << newID;
    return;
}

//Same as getMember but for providers
void getProvider(Database & database) {
    string inputName;
    string inputStreet;
    string inputCity;
    string inputState;
    string inputZip;
    string newID;

    cout << "\nPlease enter the name of the provider to add: ";
    getline(cin, inputName);
    cout << "\nPlease enter the street address of the provider to add: ";
    getline(cin, inputStreet);
    cout << "\nPlease enter the name of the city in which the provider is located: ";
    getline(cin, inputCity);
    cout << "\nPlease enter the state of the provider to add: ";
    getline(cin, inputState);
    cout << "\nPlease enter the zip of the provider to add: ";
    getline(cin, inputZip);
    newID = database.addProvider(inputName, inputStreet, inputCity, inputState, inputZip);
    database.update();
    cout << "\n\nProvider added to database and assigned ID: " << newID;
    return;
}

//Prompts user for ID to delete, displays name to confirm with user, 
//prompts for confirmation, deletes if confirmation is provided
void deleteMember(Database &database)
{
    string inputID;
    char input;

    cout << "\nPlease input the ID of the member to delete: ";
    getline(cin, inputID);
    if (database.validateMemID(inputID) == false)
    {
        cout << "\nThat ID is invalid. No member will be deleted.";
        return;
    }
    Member memberToDelete = database.members.at(inputID);
    cout << "\nThat member ID matches the following member: " << memberToDelete.name;
    cout << "\nAre you sure you want to delete? y/n: ";
    cin >> input;

    if (toupper(input) == 'Y')
    {
        cout << "\nMember has been removed";
        database.removeMember(inputID);
        database.update();
    }
    else
    {
        cout << "\nThe member has not been removed.";
    }
    cin.ignore(256, '\n');
    return;
}
//Same as deleteMember, but for providers
void deleteProvider(Database & database) {
    string inputID;
    char input;
    cout << "\nPlease input the ID of the provider to delete: ";
    getline(cin, inputID);
    if (database.validateProvID(inputID) == false)
    {
        cout << "\nThat ID is invalid. No provider will be deleted.";
        return;
    }
    Provider providerToDelete = database.providers.at(inputID);
    cout << "\nThat provider ID matches the following provider: " << providerToDelete.name;
    cout << "\nAre you sure you want to delete? y/n: ";
    cin >> input;
    if(toupper(input) == 'Y'){
        cout << "\nProvider has been removed";
        database.removeProvider(inputID);
        database.update();
    }
    else {
        cout << "\nThe provider has not been removed.";
    }
    cin.ignore(256, '\n');
    return;
}

//prompts user for ID to pass to database editMember function
void changeMember(Database & database) {
    string inputID;
    
    cout << "\nPlease input the ID of the member to edit: ";
    getline(cin, inputID);
    if (database.validateMemID(inputID) == false)
    {
        cout << "\nThat ID is invalid. No member will be edited.";
        return;
    }
    database.editMember(inputID);
    return;
}

//Again, same as member but for provider
void changeProvider(Database & database) {
    string inputID;
    
    cout << "\nPlease input the ID of the provider to edit: ";
    getline(cin, inputID);
    if (database.validateProvID(inputID) == false)
    {
        cout << "\nThat ID is invalid. No provider will be edited.";
        return;
    }
    database.editProvider(inputID);
    return;
}

void printHeader(char target) {
	switch(target)
	{
		case 'c':
			cout <<  " __        __   __" << endl;
			cout << "/  ` |__| /  \\ /  `  /\\  |\\ |" << endl;
			cout << "\\__, |  | \\__/ \\__, /--\\ | \\|" << endl << endl;
			break;
		case 'm':
			cout << "                                            _____                    _             _ "<<endl;
			cout << "  /\\/\\   __ _ _ __   __ _  __ _  ___ _ __  /__   \\___ _ __ _ __ ___ (_)_ __   __ _| |"<<endl;
			cout << " /    \\ / _` | '_ \\ / _` |/ _` |/ _ \\ '__|   / /\\/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` | |"<<endl;
			cout << "/ /\\/\\ \\ (_| | | | | (_| | (_| |  __/ |     / / |  __/ |  | | | | | | | | | | (_| | |"<<endl;
			cout << "\\/    \\/\\__,_|_| |_|\\__,_|\\__, |\\___|_|     \\/   \\___|_|  |_| |_| |_|_|_| |_|\\__,_|_|"<<endl;
			cout << "                          |___/                                                      "<<endl;
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
	string currDate = getCurrentDate();
	for (auto pair : db.providers) {
		Provider helper = pair.second;
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
	ofstream eft;
	for (auto pair : db.providers){
		Provider helper = pair.second;
		int totalFee = 0;
		string filename = "reports/EFTReports/" + helper.name + "-EFT" + "-" + currDate + ".txt";
		for(auto pairS : db.services){
			if(pairS.second.providerID == helper.id){				
				int fee = db.directory.at(pairS.second.serviceCode).fee;
				totalFee += fee;
			}
		}
		eft.open(filename);
		eft << "Name: "<< helper.name<<endl;
		eft << "Id: "<< helper.id<<endl;
		eft <<"Amount to be transferred: "<<"$"<<totalFee<<endl;
		eft.close();
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
//true or false depending on if the ID is valid - there is a matching function for provider IDs
string validateMember(Database db) {
	string memID = "";
	cout << "Please enter member ID number: (9 digits)" << endl;
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
string verifyService(Database db) {
	string servCode = "";
	cout << "Enter a service code: (6 digits)" << endl;
	cin >> servCode;
	if(db.directory.find(servCode) == db.directory.end())
	{
		cout << "Invalid service code" << endl;
		return "null";
	}
	else
		return servCode;
}
