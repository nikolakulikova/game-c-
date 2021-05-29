//
// Created by kulik on 27. 11. 2020.
//

#ifndef PROJEKT_GUI_H
#define PROJEKT_GUI_H

#include "../map/Map.h"

class Gui{
public:
    Gui(const string &file);
    string get_map();
    void print_all();
private :
    Map map ;
};


#endif //PROJEKT_GUI_H
