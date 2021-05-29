//
// Created by kulik on 27. 11. 2020.
//

#include "Gui.h"
#include "../objects/Player.h"

Gui::Gui(const string &file) {
    map.read(file);
}

string Gui::get_map() {
    string res = "";
    for(int i = 0; i < map.mapSizeY; i++) {
        for (int j = 0; j < map.mapSizeX; j++) {
            try{
                res += map.privateMap[i][j]->repr();
            }
            catch (...){
                res += " ";
            }
        }
        res += "\n";
    }
    return res;
}

void Gui::print_all() {
    while(true) {
        string map = get_map();
        cout << map;
        string what = "";
        cout << "What do you wanna do? Move / Save" << endl;
        cin >> what;
        if (what == "Move") {
            string where;
            cout << "Where? UP/ DOWN / LEFT / RIGHT" << endl;
            cin >> where;
            this->map.move(where);
        }

        if (what == "Save") {
            while(true){
                string file = "";
                cout << "File name";
                cin >> file;
                if(file != "" || file != " "){
                    this->map.save(file + ".txt");
                    return;
                }
            }

        }
    }
}
