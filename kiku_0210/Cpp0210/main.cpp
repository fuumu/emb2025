#include <iostream>

#include "function.h"
#include "object.h"

using namespace std;

int main() {
    int m = 3, n = 1;
    cout << m << "と" << n << "のうち、最大のものは" << Function::max(m, n) << endl;
    cout << m << "と" << n << "のうち、最大のものは" << Function::min(m, n) << endl;



    Object* o1, * o2, * o3;
    o1 = new Object();
    o2 = new Object();
    o3 = new Object();
    cout << "オブジェクトの数:" << Object::getObjectNum() << endl;
    delete o3;
    cout << "オブジェクトの数:" << Object::getObjectNum() << endl;
    delete o2;
    delete o1;
    return 0;
}