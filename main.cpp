/**
 * Created by Bela Kurzenhauser, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson and Max Van Raden.
 */

#include <iostream>
#include "Database.h"
#include "ManagerTerminal.h"
#include "ProviderTerminal.h"

void printHeader() {
    std::cout << R"( __        __   __           )" << std::endl;
    std::cout << R"(/  ` |__| /  \ /  `  /\  |\ |)" << std::endl;
    std::cout << R"(\__, |  | \__/ \__, /--\ | \|)" << std::endl << std::endl;
    std::cout << "Welcome to the ChocAn Simulator." << std::endl << std::endl;
}

void beginSimulation() {
    Database database((char *)"data/database.json");

    std::cout << "Would you like to simulate the (m)anager terminal or the (p)rovider terminal?: " ;
    char res = 0;
    while (res != 'm' && res != 'p') {
        std::cin.get(res);
        std::cin.ignore(256, '\n');
        if (res != 'm' && res != 'p')
            std::cout << "Invalid input. Type 'm' for the manager terminal or 'p' for the provider terminal." << std::endl;
    }

    char choice = 0;
    if (res == 'm') {
        ManagerTerminal managerTerminal(database);
    } else if (res == 'p') {
        ProviderTerminal providerTerminal(database);
    }
}

int main(int argc, char **argv) {
    printHeader();
	beginSimulation();
	return 0;
}
