#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day6.txt");

int part1();
long long part2();
std::vector<std::string> split(std::string str,std::string sep);

int main(void) {
    while(getline(file, line)) {
        input.push_back(line);
    }

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    vector<string> ts = split(input[0], " ");
    vector<int> times;
    for (int i=1; i<ts.size();++i) times.push_back(stoi(ts[i]));

    ts = split(input[1], " ");
    vector<int> distances;
    for (int i=1; i<ts.size();++i) distances.push_back(stoi(ts[i]));

    int ways = 0;
    int prod = 1;
    for (int race=0; race<times.size(); ++race) {
        for (int t=1; t<times[race]; ++t) {
            if ((times[race]-t)*t>distances[race]) ways++;
        }
        prod*=ways; ways=0;
    }

    return prod;  
}

long long part2() {
    long long time = 52947594;
    long long distance = 426137412791216;
    long long ways = 0;

    int flag = 0;
    for (long long t=9800000; t<time; t+=1) {
        if (ways == 0 && (time-t)*t>distance) flag = 1;
        if (ways > 0 && flag==1 && !((time-t)*t>distance)) break;
        if ((time-t)*t>distance) ways++;
    }
    
    return ways;
}

std::vector<std::string> split(std::string str,std::string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}