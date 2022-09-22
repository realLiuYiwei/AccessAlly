#include "minConverter.h"
#include <iostream>
using namespace std;
int main() {
    int min = 0;
    if(cin >> min){
        min_converter convert = min_converter(min);
        int out = convert.get_total();
        cout << out << endl;
    } else {
        return 0;
    }
}
