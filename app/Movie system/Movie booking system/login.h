#ifndef LOGIN_H
#define LOGIN_H

#include <string>
using namespace std;

class Login {
public:
    bool adminLogin();
    bool compare(const string& a, const string& b);
};

#endif