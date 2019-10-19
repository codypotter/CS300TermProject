#include <iostream>
#include <json/json.h>
#include "utils.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s <parameters>\n", argv[0]);

    } else {

        Record sample = read_json("data/sample-db.json");

        Record& members = sample["members"];
        for(int i = 0; i < members.size(); ++i) {
            printf("Name: %s\n", members[i]["name"].asString().c_str());
        }

        return 0;
    }
    return -1;
}
