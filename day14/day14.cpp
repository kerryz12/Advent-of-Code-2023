#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
vector<string> columns;
vector<string> rows;
string line;
ifstream file("day14.txt");

int part1();
int part2();
string get_row(int row);
string get_column(int column);
std::vector<std::string> split(std::string str,std::string sep);

int main(void) {
    while(getline(file, line)) {
        input.push_back(line);
    }

    for (string s : input) rows.push_back(s);

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    vector<string> columns;
    int sum = 0;
    int next_move=0;

    for (int i=0; i<input[0].size(); ++i) {
        string column = get_column(i);

        for (int j=0; j<column.size();++j) {
            if (column[j] == 'O') {
                column[j] = '.';
                column[next_move] = 'O';
                next_move = next_move+1;
            }
            else if (column[j] == '.') {
                continue;
            }
            else if (column[j] == '#') {
                next_move=j+1;
            }
        }

        columns.push_back(column); next_move = 0;
    }

    int counter=0;

    for(string s : columns) {
        for (int j=s.size();j>0;--j) {
            if (s[counter] == 'O') { sum+=j; }
            counter++;
        }
        counter=0;
    }

    return sum;
}

int part2() {
    int sum = 0;
    int next_move=0;

    for (int cycles=0; cycles<1000;++cycles) {
        columns.clear();

        // north
        for (int i=0; i<input[0].size(); ++i) {
            string column = get_column(i);

            for (int j=0; j<column.size();++j) {
                if (column[j] == 'O') {
                    column[j] = '.';
                    column[next_move] = 'O';
                    next_move = next_move+1;
                }
                else if (column[j] == '.') {
                    continue;
                }
                else if (column[j] == '#') {
                    next_move=j+1;
                }
            }

            columns.push_back(column); next_move = 0; 
        }
        rows.clear(); next_move=0;

        // west
        for (int i=0; i<input.size(); ++i) {
            string row = get_row(i);

            for (int j=0; j<row.size();++j) {
                if (row[j] == 'O') {
                    row[j] = '.';
                    row[next_move] = 'O';
                    next_move = next_move+1;
                }
                else if (row[j] == '.') {
                    continue;
                }
                else if (row[j] == '#') {
                    next_move=j+1;
                }
            }

            rows.push_back(row); next_move = 0; 
        }
        columns.clear(); 

        // south
        for (int i=0; i<input[0].size(); ++i) {
            string column = get_column(i);
            next_move = column.size()-1;

            for (int j=column.size()-1; j>=0;--j) {
                if (column[j] == 'O') {
                    column[j] = '.';
                    column[next_move] = 'O';
                    next_move = next_move-1;
                }
                else if (column[j] == '.') {
                    continue;
                }
                else if (column[j] == '#') {
                    next_move=j-1;
                }
            }

            columns.push_back(column); next_move = column.size()-1;
        }
        rows.clear(); next_move = columns[0].size()-1;

        // east
        for (int i=0; i<input.size(); ++i) {
            string row = get_row(i);
            next_move = row.size()-1;

            for (int j=row.size()-1; j>=0;--j) {
                if (row[j] == 'O') {
                    row[j] = '.';
                    row[next_move] = 'O';
                    next_move = next_move-1;
                }
                else if (row[j] == '.') {
                    continue;
                }
                else if (row[j] == '#') {
                    next_move=j-1;
                }
            }

            rows.push_back(row); next_move = row.size()-1;;
        }
        columns.clear(); next_move = 0;

        int counter=0;

        for (int i=0; i<rows[0].size(); ++i) {
            string column = get_column(i);
            columns.push_back(column);
        }

        for(string s : columns) {
            for (int j=s.size();j>0;--j) {
                if (s[counter] == 'O') { sum+=j; }
                counter++;
            }
            counter=0;
        }

        cout << sum << " ";
        sum = 0;
    }

    return sum;
}

string get_column(int column) {
    string temp;

    for (string s : rows) {
        temp.push_back(s[column]);
    }

    return temp;
}

string get_row(int row) {
    string temp;

    for (string s : columns) {
        temp.push_back(s[row]);
    }

    return temp;
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