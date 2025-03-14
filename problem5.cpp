// File name: A3_SheetPb5_20220325.cpp
// Purpose: Task Manager.
// Author(s): Marawan Shrief Abdelatef Soliman
// ID(s): 20220325
// Section: S5
// Date: 10/12/2023


#include <bits/stdc++.h>

using namespace std;
bool check;
void get_data(const string& a) {
    // Use system to execute the tasklist command and redirect the output to a file
    string s =  "tasklist > " + a;

    //error as string(s) doesn't represent as (Cstyle_string) we need to make string s represent
    //as (Cstyle_string) so we used function c_str() to make string s represent as (Cstyle_string)
    //int res = system(s);

    //correct as string(s) represent as (Cstyle_string) by using c_str() function
    int result = system(s.c_str());

    if (result == -1) {
        cerr << "Error executing tasklist command.\n";
    }
}

bool comp_name(pair<string, pair<int, pair<string, pair<int, string>>>> a,
               pair<string, pair<int, pair<string, pair<int, string>>>> b) {
    return a.first < b.first;
}

bool comp_id(pair<string, pair<int, pair<string, pair<int, string>>>> a,
             pair<string, pair<int, pair<string, pair<int, string>>>> b) {
    return a.second.first < b.second.first;
}

bool comp_mem(pair<string, pair<int, pair<string, pair<int, string>>>> a,
              pair<string, pair<int, pair<string, pair<int, string>>>> b) {
    if (a.second.second.second.second.size() != b.second.second.second.second.size()){
        return a.second.second.second.second.size() < b.second.second.second.second.size();
    }
    return a.second.second.second.second < b.second.second.second.second;
}

class RepresentData {
protected:
    vector<pair<string, pair<int, pair<string, pair<int, string>>>>> v1;
    vector<string> v2;
public:
    RepresentData() {}

    RepresentData(string file) {
        represent_data(file);
    }

    void represent_data(string file) {
        ifstream ifile;
        ifile.open(file);
        if (!ifile.is_open()){
            cout << "There is No file with this name\n";
            check = true;
            return;
        }
        string strs;
        for (int i = 0; i < 4 && getline(ifile, strs); ++i) {
            v2.push_back(strs);
        }
        while (getline(ifile, strs)) {
            istringstream ist(strs);
            int PID, SessionNum;
            string ImageName, SessionName, MemUsage;
            ist >> ImageName >> PID >> SessionName >> SessionNum >> MemUsage;
            v1.push_back({ImageName, {PID, {SessionName, {SessionNum, MemUsage}}}});
        }
    }
};

class RuninngProcessData : public RepresentData {
    vector<string >mem;
public:
    RuninngProcessData(string file) {
        represent_data(file);
    }

    void sort_by_name() {
        sort(v1.begin(), v1.end(), comp_name);
        print_data_after_sorted();
    }

    void sort_by_id() {
        sort(v1.begin(), v1.end(), comp_id);
        print_data_after_sorted();
    }

    void sort_by_mem() {
        sort(v1.begin(), v1.end(), comp_mem);
        print_data_after_sorted();
    }

    void print_data_after_sorted() {
        for (auto &x: v2) {
            cout << x << '\n';
        }
        for (auto &x: v1) {
            cout << x.first;
            string a = to_string(x.second.first);
            for (int i = 0; i < 34 - (x.first.size() + a.size()); ++i) {
                cout << ' ';
            }
            cout << x.second.first << ' ' << x.second.second.first;
            for (int i = 0; i < 28 - (x.second.second.first.size() + 1); ++i) {
                cout << ' ';
            }
            cout << x.second.second.second.first;
            for (int i = 0; i < 11 - (x.second.second.second.second.size()); ++i) {
                cout << ' ';
            }
            cout << x.second.second.second.second << " k\n";
        }
    }

};

int main() {
    string file, num;
    cout << "Enter file name that you want to store OS programs on it:\n";
    cin >> file;
    get_data(file);
    if (check) return 0;
    cout << "Enter process that you want:\n"
            "1)Print the current data\n"
            "2)Print the data sorted by name\n"
            "3)Print the data sorted by id\n"
            "4)Print the data sorted by Memory usage\n";
    RuninngProcessData ob(file);
    cin >> num;
    if (num == "1") {
        ob.print_data_after_sorted();
    } else if (num == "2") {
        ob.sort_by_name();
    } else if (num == "3") {
        ob.sort_by_id();
    } else if (num == "4") {
        ob.sort_by_mem();
    } else {
        cout << "Wrong input please try again :)";
    }
    return 0;
}