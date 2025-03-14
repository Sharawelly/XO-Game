// File name: A3_SheetPb2_20220325.cpp
// Purpose: Document similarity measurement.
// Author(s): Marawan Shrief Abdelatef Soliman
// ID(s): 20220325
// Section: S5
// Date: 10/12/2023

#include <bits/stdc++.h>

using namespace std;
bool checker = false;

class StringSet {
private:
    vector<string> v;
public:
    StringSet() {}

    StringSet(string file) {
        ifstream ifile;
        ifile.open(file);
        string x;
        while (ifile >> x) {
            v.push_back(x);
        }
        for (int i = 0; i < v.size(); ++i) {
            string &ignore = v[i];
            for (int j = 0; j < ignore.size(); ++j) {
                if (!isalpha(ignore[j])) {
                    ignore.erase(j, 1);
                    j--;
                } else ignore[j] = ::tolower(ignore[j]);
            }
        }
    }

    StringSet(string str, char s) {
        istringstream ist(str);
        string str2;
        while (ist >> str2) {
            v.push_back(str2);
        }
        for (int i = 0; i < v.size(); ++i) {
            string &ignore = v[i];
            for (int j = 0; j < ignore.size(); ++j) {
                if (!isalpha(ignore[j])) {
                    ignore.erase(j, 1);
                    j--;
                } else ignore[j] = ::tolower(ignore[j]);
            }
        }
        vector<string> v2;
        map<string, int> mp;
        for (auto x: v) {
            if (mp[x] == 0){
                v2.push_back(x);
                mp[x]++;
            }
        }
        v.clear();
        for (auto x: v2) {
            v.push_back(x);
        }
    }

    void add_string(string x) {
        v.push_back(x);
    }

    void remove_string(string x) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == x) {
                v.erase(v.begin() + i);
                break;
            }
        }
    }

    void clear_string() {
        v.clear();
    }

    void num_of_string() {
        cout << v.size() << '\n';
    }

    void print_strings() {
        if (!v.empty())
            for (auto &x: v) {
                cout << x << ' ';
            }
        else cout << "Empty!";
        cout << '\n';
    }

    StringSet operator+(StringSet ob) {
        StringSet ob3;
        map<string, int> mp;
        for (int i = 0; i < v.size(); ++i) {
            ob3.v.push_back(v[i]);
            mp[v[i]]++;
        }
        for (int i = 0; i < ob.v.size(); ++i) {
            if (mp[ob.v[i]] == 0)
                ob3.v.push_back(ob.v[i]);
        }
        return ob3;
    }

    StringSet operator*(StringSet ob) {
        StringSet ob3;
        for (int i = 0; i < ob.v.size(); ++i) {
            if (find(v.begin(), v.end(), ob.v[i]) != v.end()) {
                ob3.v.push_back(ob.v[i]);
            }
        }
        return ob3;
    }

    double sim(StringSet ob) {
        StringSet ob3 = *this * ob;
        if (v.size() && ob.v.size())
            return ob3.v.size() / (sqrt(v.size()) * sqrt(ob.v.size()));
        else {
            return -1;
        }
    }

    void print_sim(StringSet ob) {
        double x = sim(ob);
        if (x!=-1)
            cout << x << '\n';
        else cout << "Error divide by zero";
    }


};

int main() {

    StringSet ob1("test_file.txt");
    StringSet ob2("Chocolate ice cream, chocolate milk, and chocolate bars are delicious.", '2');
    ob2.print_strings();
    StringSet ob3 = ob1 + ob2;
    ob1.print_strings();
    ob3.print_strings();
    ob3.print_sim(ob1);
    ob1.add_string("is");
    ob1.print_strings();
    ob1.num_of_string();
    ob1.remove_string("lol");
    ob1.print_strings();
    ob1.num_of_string();
    ob1.clear_string();
    ob1.print_strings();
    ob1.num_of_string();
//    StringSet ob3 = ob1 + ob2;
//    ob3.print_strings();
    //StringSet ob3 = ob1 + ob2;
    //ob3.print_strings();
    //ob1.print_sim(ob2);

}