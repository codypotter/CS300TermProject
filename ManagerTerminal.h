//
// Created by enjoi on 12/16/2019.
//

#ifndef CS300TERMPROJECT_MANAGERTERMINAL_H
#define CS300TERMPROJECT_MANAGERTERMINAL_H

#include <iostream>
#include "Database.h"

class ManagerTerminal {
private:
    Database* database;

    static void printHeader();
    static char getRootOption();
    void callFunction(char option);
    void addProvider();
    void addMember();
    void editProvider();
    void editMember();
    void deleteProvider();
    void deleteMember();
    void generateMemberReports();
    static std::string getCurrentDate();

public:
    explicit ManagerTerminal(Database &database);
};


#endif //CS300TERMPROJECT_MANAGERTERMINAL_H
