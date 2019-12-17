//
// Created by enjoi on 12/16/2019.
//

#ifndef CS300TERMPROJECT_PROVIDERTERMINAL_H
#define CS300TERMPROJECT_PROVIDERTERMINAL_H

#include <iostream>
#include "Database.h"

class ProviderTerminal {
private:
    std::string userID;
    Database* database;

    static void printHeader();
    void generateProviderReports();
    void printDirectory();
    std::string getValidMemberID();
    std::string getValidServiceCode();
    static std::string getCurrentDate();
    bool doUserOperations();

public:
    explicit ProviderTerminal(Database& db);
};


#endif //CS300TERMPROJECT_PROVIDERTERMINAL_H
