#include <iostream>
#include <json/json.h>
#include "utils.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s <parameters>\n", argv[0]);
        return -1;
    }

    //example of reading a json file
    Record sample = read_json("data/sample-db.json");

    Record& members = sample["members"];
    for(int i = 0; i < members.size(); ++i) {
        printf("Name: %s\n", members[i]["name"].asString().c_str());
    }

    //modifying a json value
    members[1]["name"] = "test";
    //example of writing to a json file
    write_json("data/test.json", sample);

    return 0;
}
