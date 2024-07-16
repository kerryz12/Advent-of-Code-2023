#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day5.txt");

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
    vector<long long> seeds; vector<vector<long long>> soil; vector<vector<long long>> fertilizer;
    vector<vector<long long>> water; vector<vector<long long>> light; vector<vector<long long>> temperature;
    vector<vector<long long>> humidity; vector<vector<long long>> location;

    vector<string> temp = split(input[0], " ");
    for (int i=1; i<temp.size();++i) {
        seeds.push_back(stoll(temp[i]));
    }

    vector<long long> temp_val;
    for (int i=3;i<26;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        soil.push_back(temp_val); temp_val.clear();
    }

    for (int i=28;i<68;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        fertilizer.push_back(temp_val); temp_val.clear();
    }

    for (int i=70;i<84;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        water.push_back(temp_val); temp_val.clear();
    }

    for (int i=86;i<132;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        light.push_back(temp_val); temp_val.clear();
    }

    for (int i=134;i<169;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        temperature.push_back(temp_val); temp_val.clear();
    }

    for (int i=171;i<199;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        humidity.push_back(temp_val); temp_val.clear();
    }

    for (int i=201;i<243;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        location.push_back(temp_val); temp_val.clear();
    }

    for (int se=0; se<seeds.size(); ++se) {
        for (vector<long long> s : soil) {
            if (seeds[se] <= s[1]+s[2] && seeds[se] >= s[1]) {
                seeds[se] = s[0] + (seeds[se] - s[1]); break;
            }
        }
        for (vector<long long> s : fertilizer) {
            if (seeds[se] <= s[1]+s[2] && seeds[se] >= s[1]) {
                seeds[se] = s[0] + (seeds[se] - s[1]); break;
            }
        }
        for (vector<long long> s : water) {
            if (seeds[se] <= s[1]+s[2] && seeds[se] >= s[1]) {
                seeds[se] = s[0] + (seeds[se] - s[1]); break;
            }
        }
        for (vector<long long> s : light) {
            if (seeds[se] <= s[1]+s[2] && seeds[se] >= s[1]) {
                seeds[se] = s[0] + (seeds[se] - s[1]); break;
            }
        }
        for (vector<long long> s : temperature) {
            if (seeds[se] <= s[1]+s[2] && seeds[se] >= s[1]) {
                seeds[se] = s[0] + (seeds[se] - s[1]); break;
            }
        }
        for (vector<long long> s : humidity) {
            if (seeds[se] <= s[1]+s[2] && seeds[se] >= s[1]) {
                seeds[se] = s[0] + (seeds[se] - s[1]); break;
            }
        }
        for (vector<long long> s : location) {
            if (seeds[se] <= s[1]+s[2] && seeds[se] >= s[1]) {
                seeds[se] = s[0] + (seeds[se] - s[1]); break;
            }
        }
    }

    int min_value = *min_element(seeds.begin(), seeds.end());

    return min_value;
}

int part2() {
    vector<long long> seeds; vector<vector<long long>> soil; vector<vector<long long>> fertilizer;
    vector<vector<long long>> water; vector<vector<long long>> light; vector<vector<long long>> temperature;
    vector<vector<long long>> humidity; vector<vector<long long>> location; vector<long long> seeds_locations;

    vector<string> temp = split(input[0], " ");
    for (int i=1; i<temp.size();++i) {
        seeds.push_back(stoll(temp[i]));
    }

    vector<long long> temp_val;
    for (int i=3;i<26;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        soil.push_back(temp_val); temp_val.clear();
    }

    for (int i=28;i<68;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        fertilizer.push_back(temp_val); temp_val.clear();
    }

    for (int i=70;i<84;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        water.push_back(temp_val); temp_val.clear();
    }

    for (int i=86;i<132;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        light.push_back(temp_val); temp_val.clear();
    }

    for (int i=134;i<169;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        temperature.push_back(temp_val); temp_val.clear();
    }

    for (int i=171;i<199;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        humidity.push_back(temp_val); temp_val.clear();
    }

    for (int i=201;i<243;++i) {
        temp = split(input[i], " ");

        for (string s : temp) {
            temp_val.push_back(stoll(s));
        }

        location.push_back(temp_val); temp_val.clear();
    }

    int loop = 7873000;
    long long curr_loc = 0;
    while (true) {
        curr_loc = loop;
        for (vector<long long> s : location) {
            if (curr_loc <= s[0]+s[2] && curr_loc >= s[0]) {
                curr_loc = s[1] + (curr_loc - s[0]); break;
            }
        }

        for (vector<long long> s : humidity) {
            if (curr_loc <= s[0]+s[2] && curr_loc >= s[0]) {
                curr_loc = s[1] + (curr_loc - s[0]); break;
            }
        }

        for (vector<long long> s : temperature) {
            if (curr_loc <= s[0]+s[2] && curr_loc >= s[0]) {
                curr_loc = s[1] + (curr_loc - s[0]); break;
            }
        }

        for (vector<long long> s : light) {
            if (curr_loc <= s[0]+s[2] && curr_loc >= s[0]) {
                curr_loc = s[1] + (curr_loc - s[0]); break;
            }
        }

        for (vector<long long> s : water) {
            if (curr_loc <= s[0]+s[2] && curr_loc >= s[0]) {
                curr_loc = s[1] + (curr_loc - s[0]); break;
            }
        }

        for (vector<long long> s : fertilizer) {
            if (curr_loc <= s[0]+s[2] && curr_loc >= s[0]) {
                curr_loc = s[1] + (curr_loc - s[0]); break;
            }
        }

        for (vector<long long> s : soil) {
            if (curr_loc <= s[0]+s[2] && curr_loc >= s[0]) {
                curr_loc = s[1] + (curr_loc - s[0]); break;
            }
        }

        for (int se = 0; se < seeds.size(); se += 2) {
            if ((curr_loc <= (seeds[se] + seeds[se+1])) && (curr_loc >= seeds[se])) {
                return loop;
            }
        }

        loop++;
    }

    return -1;
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