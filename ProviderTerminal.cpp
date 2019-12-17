//
// Created by Cody Potter on 12/16/2019.
//
#include <ctime>
#include <fstream>
#include "ProviderTerminal.h"

/**
 * Constructor that takes a database reference
 * @param db - a reference to the Database object
 */
ProviderTerminal::ProviderTerminal(Database &db) {
    database = &db;
    printHeader();

    bool userContinue = true;
    while (userContinue) {
        userContinue = doUserOperations();
    }
}

/**
 * Member function contains the basic user operations of the Provider Terminal
 * @return - false when user is done
 */
bool ProviderTerminal::doUserOperations() {
    bool validUserIDEntered = false;
    while (!validUserIDEntered) {
        std::cout << "Please enter a valid provider number: (9 digits)" << std::endl;
        std::cin >> userID;
        std::cin.ignore(256, '\n');
        if (database->providers.find(userID) != database->providers.end()) {
            validUserIDEntered = true;
        } else {
            std::cout << "Invalid provider ID." << std::endl;
            continue;
        }
    }

    char userChoice = ' ';
    while (userChoice != 'a' && userChoice != 'b' && userChoice != 'c' && userChoice != 'x') {

        std::cout << "(a) View the provider directory" << std::endl;
        std::cout << "(b) Provide service" << std::endl;
        std::cout << "(c) Generate provider reports" << std::endl;
        std::cout << "(x) Exit" << std::endl;
        std::cin >> userChoice;
        std::cin.ignore(256, '\n');
    }

    switch (userChoice) {
        case 'a': {
            printDirectory();
            return true;
        }

        case 'b': {
            std::string memID = getValidMemberID();
            if (memID == "null")
                return true;

            std::string servCode = getValidServiceCode();
            if (servCode == "null") {
                return true;
            }

            time_t now = time(0);
            tm *localTime = localtime(&now);

            std::string currDate = getCurrentDate();

            std::string servDate;
            std::cout << "Enter the expected service date (mm/dd/yyyy): ";
            std::cin >> servDate;
            std::cin.ignore(256, '\n');

            //print summary
            std::cout << "Service Summary:" << std::endl;
            std::cout << "Date of Service: " << servDate << std::endl;
            std::cout << "Date of Submission: " << currDate << std::endl;
            std::cout << "Member ID: " << memID << std::endl;
            std::cout << "Provider ID: " << userID << std::endl;
            std::cout << "Service ID: " << servCode << std::endl;
            std::cout << "Fee: " << database->directory.at(servCode).fee << std::endl;

            std::string servID = database->addService(servDate, currDate, memID, userID, servCode, database->directory.at(servCode).fee);
            database->members.at(memID).services.push_back(servID);
            database->providers.at(userID).services.push_back(servID);
            database->update();

            return true;
        }

        case 'c': {
            generateProviderReports();
            return true;
        }

        case 'x': {
            return false;
        }

        default: {
            return false;
        }
    }
}

/**
 * Prints a pretty header
 */
void ProviderTerminal::printHeader() {
    std::cout << R"( ___             _    _           _____              _           _ )" << std::endl;
    std::cout << R"(| _ \_ _ _____ _(_)__| |___ _ _  |_   _|__ _ _ _ __ (_)_ _  __ _| |)" << std::endl;
    std::cout << R"(|  _/ '_/ _ \ V / / _` / -_) '_|   | |/ -_) '_| '  \| | ' \/ _` | |)" << std::endl;
    std::cout << R"(|_| |_| \___/\_/|_\__,_\___|_|     |_|\___|_| |_|_|_|_|_||_\__,_|_|)" << std::endl << std::endl;
    std::cout << "Welcome to the provider terminal!" << std::endl << std::endl;
}

/**
 * Generates the provider reports to the reports directory
 */
void ProviderTerminal::generateProviderReports() {
    std::ofstream report;
    std::string currDate = getCurrentDate();
    for (const auto& pair : database->providers) {
        Provider helper = pair.second;
        int totalFee = 0;
        int totalVisits = 0;
        std::string filename = "reports/providerReports/" + helper.name + "-" + currDate + ".txt";
        report.open (filename);
        report << "Name: " << helper.name;
        report << "\nID: " << helper.id;
        report << "\nAddress: " << helper.street;
        report << "\nCity: " << helper.city;
        report << "\nState: " << helper.state;
        report << "\nZIP: " << helper.zip;
        report << "\nServices Provided: \n";
        for (const std::string& serviceID : helper.services) {
            std::string memberID = database->services.at(serviceID).memberID;
            std::string code = database->services.at(serviceID).serviceCode;
            int fee = database->directory.at(code).fee;
            report << "\nDate of service: " << database->services.at(serviceID).serviceDate;
            report << "\nDate of submission: " << database->services.at(serviceID).submissionDate;
            report << "\nMember Name: " << database->members.at(memberID).name;
            report << "\nMember ID: " << memberID;
            report << "\nService Code: " << code;
            report << "\nService Type: " << database->directory.at(code).name;
            report << "\nFee for Service: $" << fee << "\n";
            totalFee+=fee;
            totalVisits++;
        }
        report << "\nTotal number of services provided: " << totalVisits;
        report << "\nTotal fee: $" << totalFee;
        report.close();
    }
    std::ofstream eft;
    for (const auto& pair : database->providers){
        Provider helper = pair.second;
        int totalFee = 0;
        std::string filename = "reports/EFTReports/" + helper.name + "-EFT" + "-" + currDate + ".txt";
        for(const auto& pairS : database->services){
            if(pairS.second.providerID == helper.id){
                int fee = database->directory.at(pairS.second.serviceCode).fee;
                totalFee += fee;
            }
        }
        eft.open(filename);
        eft << "Name: "<< helper.name<< std::endl;
        eft << "Id: "<< helper.id<< std::endl;
        eft <<"Amount to be transferred: " << "$" << totalFee << std::endl;
        eft.close();
    }
    std::cout << "Reports generated successfully!" << std::endl;
}

/**
 * Prints the directory to the command line
 */
void ProviderTerminal::printDirectory() {
    std::cout << "List of services:" << std::endl;
    for(const auto& pair : database->directory) {
        std::cout << "Service Code: " << pair.first << std::endl;
        std::cout << "Name: " << pair.second.name << std::endl;
        std::cout << "Fee: " << pair.second.fee << std::endl << std::endl;
    }
}

/**
 * Gets a valid member id from the user
 * @return - the valid member id
 */
std::string ProviderTerminal::getValidMemberID() {
    std::string memID;
    std::cout << "Please enter member ID number: (9 digits)" << std::endl;
    std::cin >> memID;
    if(database->members.find(memID) == database->members.end()) {
        std::cout << "Invalid member ID, please try again";
        return "null";
    }
    if(!database->members.at(memID).isValid) {
        std::cout << "Member exists, but has been exempted from services. Refer to billing department." << std::endl;
        return "null";
    }
    return memID;
}

/**
 * Gets a valid service code from the user
 * @return - the valid service code
 */
std::string ProviderTerminal::getValidServiceCode() {
    std::string servCode;
    std::cout << "Enter a service code: (6 digits)" << std::endl;
    std::cin >> servCode;
    if(database->directory.find(servCode) == database->directory.end()) {
        std::cout << "Invalid service code" << std::endl;
        return "null";
    }
    return servCode;
}

/**
 * Gets the current date in a formatted string
 * @return - the current date in a formatted string
 */
std::string ProviderTerminal::getCurrentDate() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);

    std::string year = std::to_string(localTime->tm_year - 100);
    std::string month = std::to_string(localTime->tm_mon + 1);
    std::string day = std::to_string(localTime->tm_mday);
    std::string hour = std::to_string(localTime->tm_hour);
    std::string minute = std::to_string(localTime->tm_min);
    std::string second = std::to_string(localTime->tm_sec);
    return month + "/" + day + "/" + year + " " + hour + ":" + minute + ":" + second;
}