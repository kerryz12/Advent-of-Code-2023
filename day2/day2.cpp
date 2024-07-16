#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day2.txt");

int part1();
int part2();
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
    vector<int> balls;
    vector<string> names;
    int sum = 0;
    int flag = 1;

    for (string s : input) {

        vector<string> temp = split(s, " ");

        temp[1].pop_back();
        int id = stoi(temp[1]);
        for(int i = 2; i < temp.size(); i += 2) {
            balls.push_back(stoi(temp[i]));
        }
        for (int i = 3; i < temp.size(); i += 2) {
            names.push_back(temp[i]);
        }
        for (int j = 0; j < names.size(); ++j) {
            if (names[j].back() == ';' || names[j].back() == ',') { names[j].pop_back(); }
        }

        for (int i = 0; i < balls.size(); ++i) {
            if (names[i] == "red" && balls[i] > 12) { flag = 0; break; }
            else if (names[i] == "green" && balls[i] > 13) { flag = 0; break; }
            else if (names[i] == "blue" && balls[i] > 14) { flag = 0; break; } 
        }

        if (flag) sum += id;
        
        flag = 1;
        balls.clear();
        names.clear();
    }

    return sum;
}

int part2() {
    vector<int> balls;
    vector<string> names;
    long long sum = 0;
    int flag = 1;

    int max_red = 0;
    int max_green = 0;
    int max_blue = 0;

    for (string s : input) {

        vector<string> temp = split(s, " ");

        temp[1].pop_back();
        int id = stoi(temp[1]);
        for(int i = 2; i < temp.size(); i += 2) {
            balls.push_back(stoi(temp[i]));
        }
        for (int i = 3; i < temp.size(); i += 2) {
            names.push_back(temp[i]);
        }
        for (int j = 0; j < names.size(); ++j) {
            if (names[j].back() == ';' || names[j].back() == ',') { names[j].pop_back(); }
        }

        for (int i = 0; i < balls.size(); ++i) {
            if (names[i] == "red" && balls[i] > max_red) { max_red = balls[i]; }
            else if (names[i] == "green" && balls[i] > max_green) { max_green = balls[i]; }
            else if (names[i] == "blue" && balls[i] > max_blue) { max_blue = balls[i]; } 
        }

        int power = max_red * max_green * max_blue;
        sum += power;

        max_red = 0; max_green = 0; max_blue = 0;
        flag = 1;
        balls.clear();
        names.clear();
    }

    return sum;
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