//
// Created by 김혁진 on 2019/10/28.
//

#ifndef SMART_PTR_HUMAN_H
#define SMART_PTR_HUMAN_H

#include <iostream>

class human {
protected:
   const char* name;
public:
    human();
    explicit human(const char* name);
    const char * get_name();
    virtual int get_id();
};


#endif //SMART_PTR_HUMAN_H
