/**
 * Created by Bela, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson, Max VanRaden
 */

#include <iostream>
#include "Database.h"
using namespace std;

int main(int argc, char** argv) {
    Database database("data/sample-db.json");

    cout << "Welcome to the ChocAn Simulator." << endl;
    cout << "Would you like to simulate the (m)anager terminal or the (p)rovider terminal?" << endl;
    char res = 0;
    while(res != 'm' && res != 'p') {
        cin >> res;
        if(res != 'm' && res != 'p')
            cout << "Invalid input. Type 'm' for the manager terminal or 'p' for the provider terminal." << endl;
    }

    if(res == 'm') {
        cout << "Welcome to the manager terminal" << endl;
        //Someone does this
    }
    if(res == 'p') {
        cout << "Welcome to the provider terminal" << endl;
        //Someone does this
    }

    return 0;
}
