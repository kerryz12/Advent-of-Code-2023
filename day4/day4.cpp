#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day4.txt");

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
    vector<vector<string>> lines;
    vector<int> winning; vector<int> mine;
    int line_sum = 0; int sum = 0;

    for (string s : input) {
        lines.push_back(split(s," "));
    }

    for (int line = 0; line < lines.size(); ++line) {
        for (int i = 2; i < 12; ++i) {
            winning.push_back(stoi(lines[line][i]));
        }
        for (int j = 13; j < 38; ++j) {
            mine.push_back(stoi(lines[line][j]));
        }

        for (int i = 0; i < winning.size(); ++i) {
            for (int j = 0; j < mine.size(); ++j) {
                if (winning[i] == mine[j]) {
                    if (line_sum == 0) line_sum = 1;
                    else line_sum *= 2;
                }
            }
        }

        sum += line_sum;
        line_sum = 0; winning.clear(); mine.clear();
    }

    return sum;
}

int part2() {
    vector<vector<string>> lines;
    vector<int> winning; vector<int> mine;
    int num_cards = 0; int sum = 0;

    for (string s : input) {
        lines.push_back(split(s," "));
    }

    vector<int> card_counts;
    for (int i = 1; i < 210; ++i) {
        card_counts.push_back(1);
    }

    for (int line = 0; line < lines.size(); ++line) {
        string cc = lines[line][1]; cc.pop_back();
        int card = stoi(cc);

        for (int i = 2; i < 12; ++i) {
            winning.push_back(stoi(lines[line][i]));
        }
        for (int j = 13; j < 38; ++j) {
            mine.push_back(stoi(lines[line][j]));
        }

        for (int i = 0; i < winning.size(); ++i) {
            for (int j = 0; j < mine.size(); ++j) {
                if (winning[i] == mine[j]) {
                    num_cards++;
                }
            }
        }

        if (num_cards > 0) {
            for(int i = card; i < (card+num_cards); ++i) {
                if (i < 209) card_counts[i] += card_counts[card - 1];
            }
        }

        num_cards = 0; winning.clear(); mine.clear();
    }

    for (int c : card_counts) sum += c;

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