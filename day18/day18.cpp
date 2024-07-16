#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day18.txt");

int part1();
long long part2();
long long shoelace(vector<vector<long long>> points);
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
    int x=0, y=0;
    vector<vector<long long>> trenches;

    vector<string> directions;
    vector<int> distance;

    for (string s : input) {
        vector<string> temp = split(s, " ");

        directions.push_back(temp[0]); distance.push_back(stoi(temp[1]));
    }

    trenches.push_back({0,0});
    for (int i=0; i<directions.size();++i) {
        for (int j=0; j<distance[i]; ++j) {
            vector<long long> next_pos;
            if (directions[i] == "L") {
                x--;
                next_pos = {x, y};
            }
            if (directions[i] == "U") {
                y++;
                next_pos = {x, y};                
            }
            if (directions[i] == "R") {
                x++;
                next_pos = {x, y};               
            }
            if (directions[i] == "D") {
                y--;
                next_pos = {x, y};          
            }

            if (find(trenches.begin(), trenches.end(), next_pos) == trenches.end()) {
                trenches.push_back(next_pos);
            }

            next_pos.clear();
        }
    }

    int sum=0;
    for(vector<long long> trench : trenches) sum++;

    int area=shoelace(trenches);

    sum=sum+(area - sum/2 + 1);

    return sum;
}

map<int, string> m{{0, "R"}, {1, "D"}, {2, "L"}, {3, "U"}};

long long part2() {
    int x=0, y=0;
    vector<vector<long long>> trenches;

    vector<string> directions;
    vector<int> distance;

    long long sum=0;

    for (string s : input) {
        vector<string> temp = split(s, " ");

        directions.push_back(m[stoi(temp[3])]); distance.push_back(stoi(temp[2], nullptr, 16));
    }

    trenches.push_back({0,0});
    for (int i=0; i<directions.size();++i) {
        if (directions[i] == "L") {
            x-=distance[i];
        }
        if (directions[i] == "U") {
            y+=distance[i];               
        }
        if (directions[i] == "R") {
            x+=distance[i];             
        }
        if (directions[i] == "D") {
            y-=distance[i];        
        }

        vector<long long> next_pos = {x,y};
        trenches.push_back(next_pos); sum += distance[i];
    }

    long long area = shoelace(trenches);

    sum = sum + (area - sum / 2 + 1);

    return sum;
}

long long shoelace(vector<vector<long long>> points) {
	long long leftSum = 0;
	long long rightSum = 0;

	for (long long i = 0; i < points.size(); ++i) {
		long long j = (i + 1) % points.size();
		leftSum  += points[i][0] * points[j][1];
		rightSum += points[j][0] * points[i][1];
	}

	return abs(leftSum - rightSum) / 2;
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