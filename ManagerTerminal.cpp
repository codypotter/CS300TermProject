/**
 * Created by Cody Potter on 12/15/19
 */

#include <iostream>
#include "ManagerTerminal.h"

/**
 * Constructor for Manager Terminal class
 * @param db is a reference to a Database object
 */
ManagerTerminal::ManagerTerminal(Database &db) {
    printHeader();
    database = &db;
    std::cout << "Welcome to the manager terminal. Please select an option." << std::endl;

    char userOption = getRootOption();
    callFunction(userOption);
}

/**
 * Prints a pretty header
 */
void ManagerTerminal::printHeader(){
    std::cout << R"(                                            _____                    _             _ )"<< std::endl;
    std::cout << R"(  /\/\   __ _ _ __   __ _  __ _  ___ _ __  /__   \___ _ __ _ __ ___ (_)_ __   __ _| |)"<< std::endl;
    std::cout << R"( /    \ / _` | '_ \ / _` |/ _` |/ _ \ '__|   / /\/ _ \ '__| '_ ` _ \| | '_ \ / _` | |)"<< std::endl;
    std::cout << R"(/ /\/\ \ (_| | | | | (_| | (_| |  __/ |     / / |  __/ |  | | | | | | | | | | (_| | |)"<< std::endl;
    std::cout << R"(\/    \/\__,_|_| |_|\__,_|\__, |\___|_|     \/   \___|_|  |_| |_| |_|_|_| |_|\__,_|_|)"<< std::endl;
    std::cout << R"(                          |___/                                                      )"<< std::endl << std::endl;
}

/**
 * Gathers user input and adds a member to the database
 */
void ManagerTerminal::addMember() {
    std::string inputName;
    std::string inputStreet;
    std::string inputCity;
    std::string inputState;
    std::string inputZip;
    std::string newID;

    std::cout << "\nPlease enter the name of the member to add: ";
    getline(std::cin, inputName);
    std::cout << "\nPlease enter the street address of the member to add: ";
    getline(std::cin, inputStreet);
    std::cout << "\nPlease enter the name of the city in which the member is located: ";
    getline(std::cin, inputCity);
    std::cout << "\nPlease enter the state of the member to add: ";
    getline(std::cin, inputState);
    std::cout << "\nPlease enter the zip of the member to add: ";
    getline(std::cin, inputZip);
    newID = database->addMember(inputName, inputStreet, inputCity, inputState, inputZip);
    database->update();
    std::cout << "\n\nMember added to database with ID: " << newID;
}

/**
 * Gathers input and adds a provider to the database
 */
void ManagerTerminal::addProvider() {
    std::string inputName;
    std::string inputStreet;
    std::string inputCity;
    std::string inputState;
    std::string inputZip;
    std::string newID;

    std::cout << "\nPlease enter the name of the provider to add: ";
    getline(std::cin, inputName);
    std::cout << "\nPlease enter the street address of the provider to add: ";
    getline(std::cin, inputStreet);
    std::cout << "\nPlease enter the name of the city in which the provider is located: ";
    getline(std::cin, inputCity);
    std::cout << "\nPlease enter the state of the provider to add: ";
    getline(std::cin, inputState);
    std::cout << "\nPlease enter the zip of the provider to add: ";
    getline(std::cin, inputZip);
    newID = database->addProvider(inputName, inputStreet, inputCity, inputState, inputZip);
    database->update();
    std::cout << "\n\nProvider added to database with ID: " << newID;
}

/**
 * Gathers user input and edits a member in the database
 */
void ManagerTerminal::editMember() {
    std::string inputID;

    std::cout << "\nPlease input the ID of the member to edit: ";
    getline(std::cin, inputID);

    if (database->validateMemID(inputID)) {
        database->editMember(inputID);
    } else {
        std::cout << "\nThat ID is invalid. No member will be edited.";
    }
}

/**
 * Gathers user input and edits a provider in the database
 */
void ManagerTerminal::editProvider() {
    std::string inputID;

    std::cout << "\nPlease input the ID of the provider to edit: ";
    getline(std::cin, inputID);
    if (database->validateProviderID(inputID)) {
        database->editProvider(inputID);
    } else {
        std::cout << "\nThat ID is invalid. No provider will be edited.";
    }
}

/**
 * Gathers input and deletes a member from the database
 */
void ManagerTerminal::deleteMember() {
    std::string inputID;
    char input;

    std::cout << "\nPlease input the ID of the member to delete: ";
    getline(std::cin, inputID);

    if (database->validateMemID(inputID)) {
        Member memberToDelete = database->members.at(inputID);
        std::cout << "\nThat member ID matches the following member: " << memberToDelete.name;
        std::cout << "\nAre you sure you want to delete? y/n: ";
        std::cin >> input;

        if (toupper(input) == 'Y') {
            std::cout << "\nMember has been removed";
            database->removeMember(inputID);
            database->update();
        } else {
            std::cout << "\nThe member has not been removed.";
        }
        std::cin.ignore(256, '\n');

    } else {
        std::cout << "\nThat ID is invalid. No member will be deleted.";
    }
}

/**
 * Gathers user input and deletes a provider from the database
 */
void ManagerTerminal::deleteProvider() {
    std::string inputID;
    char input;
    std::cout << "\nPlease input the ID of the provider to delete: ";
    getline(std::cin, inputID);

    if (database->validateProviderID(inputID)) {
        Provider providerToDelete = database->providers.at(inputID);
        std::cout << "\nThat provider ID matches the following provider: " << providerToDelete.name;
        std::cout << "\nAre you sure you want to delete? y/n: ";
        std::cin >> input;

        if(toupper(input) == 'Y'){
            std::cout << "\nProvider has been removed";
            database->removeProvider(inputID);
            database->update();
        } else {
            std::cout << "\nThe provider has not been removed.";
        }
        std::cin.ignore(256, '\n');

    } else {
        std::cout << "\nThat ID is invalid. No provider will be deleted.";
    }
}

/**
 * Generates ChocAn member reporting and writes them to text files in the reports directory
 */
void ManagerTerminal::generateMemberReports() {
    std::ofstream report;
    for (const auto& pair : database->members) {
        Member person = pair.second;
        std::string currDate = getCurrentDate();
        std::string filename = "reports/memberReports/" + person.name + "-" + currDate + ".txt";
        report.open (filename);
        report << "Name: " << person.name;
        report << "\nID: " << person.id;
        report << "\nAddress: " << person.street;
        report << "\nCity: " << person.city;
        report << "\nState: " << person.state;
        report << "\nZIP: " << person.zip;
        report << "\nServices:\n";

        for (const std::string& id : person.services) {
            std::string code = database->services.at(id).serviceCode;
            report << "\nService Provided: " << database->directory.at(code).name;
            report << "\nProvider: " << database->services.at(id).providerID;
            report << "\nDate of Service: " << database->services.at(id).serviceDate << "\n";
        }
        report.close();
    }
    std::cout << "Reports generated successfully!" << std::endl;
}

/**
 * User control function
 * @param option the operation that the user wants to execute on the database
 */
void ManagerTerminal::callFunction(char option) {
    switch (option) {
        case 'a':
            addProvider();
            break;
        case 'b':
            addMember();
            break;
        case 'c':
            editProvider();
            break;
        case 'd':
            editMember();
            break;
        case 'e':
            deleteProvider();
            break;
        case 'f':
            deleteMember();
            break;
        case 'g':
            database->printMembers();
            generateMemberReports();
            break;
        case 'x':
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Sorry, that's not a valid option. Exiting..." << std::endl;
            break;
    }
}

/**
 * Gets the user option for database operations
 * @return - the option character
 */
char ManagerTerminal::getRootOption() {
    char choice;

    std::cout << "\n(a) Add a new provider" << std::endl;
    std::cout << "(b) Add a new member" << std::endl;
    std::cout << "(c) Edit a provider" << std::endl;
    std::cout << "(d) Edit a member" << std::endl;
    std::cout << "(e) Delete a provider" << std::endl;
    std::cout << "(f) Delete a member" << std::endl;
    std::cout << "(g) Generate member reports" << std::endl;
    std::cout << "(x) Exit" << std::endl;
    std::cin.get(choice);
    std::cin.ignore(256, '\n');

    return choice;
}

/**
 * Returns the current date in a formatted string
 * @return - the current date in a formatted string
 */
std::string ManagerTerminal::getCurrentDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    std::string year = std::to_string(localTime->tm_year - 100);
    std::string month = std::to_string(localTime->tm_mon + 1);
    std::string day = std::to_string(localTime->tm_mday);
    return (month + "-" + day + "-" + year);
}


