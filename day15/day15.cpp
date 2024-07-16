#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day15.txt");

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
    int curr_val = 0; int sum=0;
    vector<string> in = split(input[0], ",");

    for(string s : in) {
        for(char c : s) {
            curr_val+=int(c);
            curr_val*=17;
            curr_val=curr_val%256;
        }
        sum+=curr_val; curr_val=0;
    }

    return sum;
}

int part2() {
    int curr_val = 0; int sum=0;
    vector<string> in = split(input[0], ",");\
    vector<vector<string>> boxes; vector<vector<int>> lens;

    for(int i=0;i<256;++i) {
        vector<string> temp;
        vector<int> t_lens;
        boxes.push_back(temp);
        lens.push_back(t_lens);
    }

    for(string s : in) {
        for(char c : s) {
            if(!isalpha(c)) break;
            curr_val+=int(c);
            curr_val*=17;
            curr_val=curr_val%256;
        }
        if (s.back() == '-') {
            string s_temp = s;
            s_temp.pop_back();
            if (find(boxes[curr_val].begin(), boxes[curr_val].end(), s_temp) != boxes[curr_val].end()) {
                auto erase_index = lens[curr_val].begin() + (find(boxes[curr_val].begin(), boxes[curr_val].end(), s_temp) - boxes[curr_val].begin());
                boxes[curr_val].erase(find(boxes[curr_val].begin(), boxes[curr_val].end(), s_temp));
                lens[curr_val].erase(erase_index);
            }
        }
        else {
            string s_temp = s; int lens_val = s.back() - '0';
            s_temp.pop_back(); s_temp.pop_back();
            if (find(boxes[curr_val].begin(), boxes[curr_val].end(), s_temp) != boxes[curr_val].end()) {
                lens[curr_val][find(boxes[curr_val].begin(), boxes[curr_val].end(), s_temp) - boxes[curr_val].begin()] = lens_val;
            }            
            else {
                boxes[curr_val].push_back(s_temp); lens[curr_val].push_back(lens_val);
            }
        }

        curr_val = 0;
    }

    for (int i=0;i<256;++i) {
        for(int j=0;j<lens[i].size();++j) {
            sum+=(i+1)*(j+1)*lens[i][j];
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