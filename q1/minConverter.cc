#include "minConverter.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// use to get the arithmetic time list for the specific hour
vector<int> get_list(int hour){
    if (hour == 12) {
        return {34}; // only 12:34
    }
    if (hour == 11) {
        return {11}; // only 11:11
    }
    if (hour == 10) { // no available
        return {};
    }
    vector<int> res = {};
    int tmp = 0;
    for (int i = -1 * hour; i < 5; ++i) {
        int fir = hour + i;
        int sec = hour + 2 * i;
        if ((fir > 5) || (sec > 9)) break;
        if ((fir <= 0) || (sec < 0)) continue;
        tmp = fir * 10 + sec;
        res.emplace_back(tmp);
    }
    return res;
}

min_converter::min_converter(int input) {
    int hours = input / 60 % 12;
    int min = input % 60;
    int round = input / 60 / 12;
    int time[] = {12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int total = 0;
    // deal with half days
    if (round >= 1){
        for(int i = 0; i <= 11; ++i) {
            total += get_list(time[i]).size();
        }
        total *= round;
    }
    // for time less than half days
    for(int i = 0; i < hours; ++i) {
        total += get_list(time[i]).size();
    }

    vector<int> on = get_list(time[hours]);
    for (auto p: on) {
        if (p <= min) ++total;
    }
    min_converter::total = total;
}

int min_converter::get_total() {
    return total;
}


min_converter::~min_converter() {

};