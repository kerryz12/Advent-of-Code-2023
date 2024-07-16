#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;

vector<string> hands;
vector<string> bids;
vector<pair<string, int>> thands;

string line;
ifstream file("day7.txt");

int part1();
int part2();
int hand_value(pair<vector<char>, vector<int>>, string hand);
bool comp_hands(string hand1, string hand2);
bool comp(pair<string, int> hand1, pair<string, int> hand2);
std::vector<std::string> split(std::string str,std::string sep);

map<char, int> card_vals{{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};

map<char, int> card_vals2{{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 1}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};

int main(void) {
    while(getline(file, line)) {
        input.push_back(line);
    }

    for (string s : input) {
        vector<string> temp = split(s, " ");

        hands.push_back(temp[0]); bids.push_back(temp[1]);
        thands.push_back(make_pair(temp[0], stoi(temp[1])));
    }

    //cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    sort(thands.begin(), thands.end(), comp);

    int rank = 1; int total_winnings = 0;
    for(pair<string, int> h : thands) {
        total_winnings += rank * h.second;
        rank++;
    }

    return total_winnings;
}

int part2() {
    sort(thands.begin(), thands.end(), comp);

    int rank = 1; int total_winnings = 0;
    for(pair<string, int> h : thands) {
        total_winnings += rank * h.second;
        rank++;
    }

    return total_winnings;
}

bool comp_hands(string hand1, string hand2) {
    pair<vector<char>, vector<int>> h1;
    pair<vector<char>, vector<int>> h2;

    for (char c : hand1) {
        if (find(h1.first.begin(), h1.first.end(), c) == h1.first.end()) {
            h1.first.push_back(c);
            h1.second.push_back(1);
        }
        else {
            h1.second[find(h1.first.begin(), h1.first.end(), c) - h1.first.begin()] += 1;
        }        
    }

    for (char c : hand2) {
        if (find(h2.first.begin(), h2.first.end(), c) == h2.first.end()) {
            h2.first.push_back(c);
            h2.second.push_back(1);
        }
        else {
            h2.second[find(h2.first.begin(), h2.first.end(), c) - h2.first.begin()] += 1;
        }        
    }

    int value1 = hand_value(h1, hand1); int value2 = hand_value(h2, hand2);

    if (value1 == value2) {
        for (int j=0; j<5; ++j) {
            if (card_vals2[hand1[j]] == card_vals2[hand2[j]]) continue;
            return (card_vals2[hand1[j]] < card_vals2[hand2[j]]);
        }
    }
    else {
        return (value1 < value2);
    }

    return 0;
}

int count_jacks(string hand) {
    int count = 0;
    for (char c : hand) {
        if (c == 'J') count++;
    }

    return count;
}

int hand_value(pair<vector<char>, vector<int>> h, string hand) {
    // calculate hand value
    int value = 0;

    if (find(h.second.begin(), h.second.end(), 5) != h.second.end()) {
        value = 7;
    }
    else if (find(h.second.begin(), h.second.end(), 4) != h.second.end()) {
        value = 6;

        if (count_jacks(hand) == 1 || count_jacks(hand) == 4) value++;
    }
    else if (find(h.second.begin(), h.second.end(), 3) != h.second.end()
            && find(h.second.begin(), h.second.end(), 2) != h.second.end()) {
        value = 5;

        if (count_jacks(hand) == 2 || count_jacks(hand) == 3) value += 2;
    }
    else if (find(h.second.begin(), h.second.end(), 3) != h.second.end()) {
        value = 4;

        if (count_jacks(hand) == 3) value += 2;
        else if (count_jacks(hand) == 1) value += 2;
    }
    else if (find(h.second.begin(), h.second.end(), 2) != h.second.end()) {
        int count = 0;
        for(int i : h.second) {
            if (i==2) count++;
        }
        if(count==2) {
            value = 3;

            if (count_jacks(hand) == 2) value += 3;
            if (count_jacks(hand) == 1) value += 2;
        }
        else if (count==1) { 
            value = 2;

            if (count_jacks(hand) == 2) value += 2;
            if (count_jacks(hand) == 1) value += 2;
        }
    }
    else {
        if (count_jacks(hand) == 1) value = 2;
        else value = 1;
    }

    return value;
}

bool comp(pair<string, int> hand1, pair<string, int> hand2) {
    return comp_hands(hand1.first, hand2.first);
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