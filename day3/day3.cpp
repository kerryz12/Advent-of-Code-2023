#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day14.txt");

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
    string curr_number;
    vector<int> valid_numbers;
    int valid = 0;
    int valid_number = 0;

    for (int i=0; i<input.size();++i) {
        for (int j=0; j<input[i].size(); ++j) {
            if (!isdigit(input[i][j])) {
                if (valid_number) {
                    valid_numbers.push_back(stoi(curr_number));
                }
                curr_number = "";
                valid = 0; valid_number = 0;
                continue;
            }
            
            if (isdigit(input[i][j])) {
                curr_number.push_back(input[i][j]);

                for(int k=-1; k<2; ++k) {
                    for(int l=-1; l<2; ++l) {
                        if (!((k+i >= 0) && (k+i < input.size()) && (l+j >=0) && (l+j < input.size()))) continue;
                        if (input[i+k][j+l] == '.' || isdigit(input[i+k][j+l])) continue;

                        valid_number = 1;
                    }
                }
            }
        }
    }

    int sum=0;
    for(int i : valid_numbers) sum+=i;

    return sum;
}

int part2() {
    string curr_number;
    vector<int> valid_numbers;
    vector<string> gear_locations;
    int valid = 0;
    int valid_number = 0;
    int gear_found = 0;

    for (int i=0; i<input.size();++i) {
        for (int j=0; j<input[i].size(); ++j) {
            if (!isdigit(input[i][j])) {
                if (valid_number) {
                    valid_numbers.push_back(stoi(curr_number));
                }
                curr_number = "";
                valid = 0; valid_number = 0; gear_found = 0;
                continue;
            }

            if (isdigit(input[i][j])) {
                curr_number.push_back(input[i][j]);

                for(int k=-1; k<2; ++k) {
                    for(int l=-1; l<2; ++l) {
                        if (!((k+i >= 0) && (k+i < input.size()) && (l+j >=0) && (l+j < input.size()))) continue;
                        if (input[i+k][j+l] != '*' || gear_found != 0) continue;

                        valid_number = 1; gear_found = 1;
                        char cc = (i+k-'0');
                        char dd = (j+l-'0');
                        gear_locations.push_back(string(1,cc)+','+dd);
                    }
                }
            }
        }
    }

    int sum=0;
    int gear_ratio=0;

    for (int ii=0;ii<valid_numbers.size();++ii) {
        for(int jj=ii+1;jj<valid_numbers.size();++jj) {
            if(gear_locations[ii] == gear_locations[jj]) {
                gear_ratio = valid_numbers[ii]*valid_numbers[jj];
                sum+=gear_ratio;
                break;
            }
        }
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