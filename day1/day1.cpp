#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> input;
string line;
ifstream file("day1.txt");

int part1();
int part2();

int main(void) {
    while(getline(file, line)) {
        input.push_back(line);
    }

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    vector<int> calibration_values;
    string calibration_value;

    for (string s : input) {
        for (char c : s) {
            if (isdigit(c)) { 
                calibration_value.push_back(c);
                break;
            }
        }
        for (int i = s.length()-1; i >= 0; --i) {
            if (isdigit(s[i])) { 
                calibration_value.push_back(s[i]);
                break;            
            }
        }
        calibration_values.push_back(stoi(calibration_value));
        calibration_value.clear();
    }

    int sum = 0;
    for (int i : calibration_values) sum += i;

    return sum;
}

int part2() {
    vector<int> calibration_values;
    string calibration_value;

    for (string s : input) {
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) { 
                calibration_value.push_back(s[i]);
                break;
            }
            else if (s[i] == 'o') {
                if (s[i+1] == 'n' && s[i+2] == 'e')  { calibration_value.push_back('1'); break; }
            }
            else if (s[i] == 't') {
                if (s[i+1] == 'w' && s[i+2] == 'o') { calibration_value.push_back('2'); break; }
                else if (s[i+1] == 'h' && s[i+2] == 'r' && s[i+3] == 'e' && s[i+4] == 'e') { calibration_value.push_back('3'); break; }
            }
            else if (s[i] == 'f') {
                if (s[i+1] == 'o' && s[i+2] == 'u' && s[i+3] == 'r') { calibration_value.push_back('4'); break; }
                else if (s[i+1] == 'i' && s[i+2] == 'v' && s[i+3] == 'e') { calibration_value.push_back('5'); break; }
            }            
            else if (s[i] == 's') {
                if (s[i+1] == 'i' && s[i+2] == 'x') { calibration_value.push_back('6'); break; }
                else if (s[i+1] == 'e' && s[i+2] == 'v' && s[i+3] == 'e' && s[i+4] == 'n') { calibration_value.push_back('7'); break; }
            }
            else if (s[i] == 'e') {
                if (s[i+1] == 'i' && s[i+2] == 'g' && s[i+3] == 'h' && s[i+4] == 't') { calibration_value.push_back('8'); break; }
            }
            else if (s[i] == 'n') {
                if (s[i+1] == 'i' && s[i+2] == 'n' && s[i+3] == 'e') { calibration_value.push_back('9'); break; }
            }
        }
        for (int i = s.length()-1; i >= 0; --i) {
            if (isdigit(s[i])) { 
                calibration_value.push_back(s[i]);
                break;            
            }
            else if (s[i] == 'e') {
                if (s[i-1] == 'n' && s[i-2] == 'o')  { calibration_value.push_back('1'); break; }
                else if (s[i-1] == 'e' && s[i-2] == 'r' && s[i-3] == 'h' && s[i-4] == 't') { calibration_value.push_back('3'); break; }
                else if (s[i-1] == 'v' && s[i-2] == 'i' && s[i-3] == 'f') { calibration_value.push_back('5'); break; }
                else if (s[i-1] == 'n' && s[i-2] == 'i' && s[i-3] == 'n') { calibration_value.push_back('9'); break; }
            }
            else if (s[i] == 'o') {
                if (s[i-1] == 'w' && s[i-2] == 't') { calibration_value.push_back('2'); break; }
            }
            else if (s[i] == 'r') {
                if (s[i-1] == 'u' && s[i-2] == 'o' && s[i-3] == 'f') { calibration_value.push_back('4'); break; }
            }            
            else if (s[i] == 'x') {
                if (s[i-1] == 'i' && s[i-2] == 's') { calibration_value.push_back('6'); break; }
            }
            else if (s[i] == 'n') {
                if (s[i-1] == 'e' && s[i-2] == 'v' && s[i-3] == 'e' && s[i-4] == 's') { calibration_value.push_back('7'); break; }
            }
            else if (s[i] == 't') {
                if (s[i-1] == 'h' && s[i-2] == 'g' && s[i-3] == 'i' && s[i-4] == 'e') { calibration_value.push_back('8'); break; }
            }
        }

        calibration_values.push_back(stoi(calibration_value));
        calibration_value.clear();
    }

    int sum = 0;
    for (int i : calibration_values) sum += i;

    return sum;
}