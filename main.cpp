#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// function to read data from a file
vector<string> readdata( const string&  fn) {
    vector<string> data;
    ifstream fin(fn);
    string line;

    while ( getline(fin,line) ) {
        data.push_back(line);
    }

    return data;
}

// Read part
int mReadV(vector<string>& v, const vector<string>& data) {
    auto start = high_resolution_clock::now();
    v = data;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

int mReadL(list<string>& l, const vector<string>& data) {
    auto start = high_resolution_clock::now();
    l.assign(data.begin(), data.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

int mReadS(set<string>& s, const vector<string>& data) {
    auto start = high_resolution_clock::now();
    s.insert(data.begin(), data.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

// Sort part
int mSortV(vector<string>& v) {
    auto start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

int mSortL(list<string>& l) {
    auto start = high_resolution_clock::now();
    l.sort();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

int mSortS(set<string>& s) {
    return -1 ;
}

// Insert part

int mInsertV(vector<string>& v, const string& value) {
    auto start = high_resolution_clock::now();
    v.insert(v.begin()+ v.size()/2, value);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

int mInsertL(list<string>& l, const string& value) {
    auto start = high_resolution_clock::now();
    auto it = next(l.begin(), l.size() / 2);
    l.insert(it, value);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

int mInsertS(set<string>& s, const string& value) {
    auto start = high_resolution_clock::now();
    s.insert(value);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

// Delete part

int mDeleteV(vector<string>& v) {
    auto start = high_resolution_clock::now();
    v.erase(v.begin() + v.size() / 2);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

int mDeleteL(list<string>& l) {
    auto start = high_resolution_clock::now();
    auto it = next(l.begin(), l.size() / 2);
    l.erase(it);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

int mDeleteS(set<string>& s, const string& value) {
    auto start = high_resolution_clock::now();
    s.erase(value);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}





int main() {
    string fn = "codes.txt";
    // read data 
    vector<string> data = readdata(fn); 
    int sim = 15;

    // 2D vector of vectors
    vector<vector<vector<int>>> result(sim, vector<vector<int>>(4, vector<int>(3, 0)));

    for (int i = 0; i < sim; i++) {
        vector<string> v;
        list<string> l;
        set<string> s;
        // 
    
        result[i][0][0] = mReadV(v, data);
        result[i][0][1] = mReadL(l, data);
        result[i][0][2] = mReadS(s, data);
        
        result[i][1][0] = mSortV(v);
        result[i][1][1] = mSortL(l);
        result[i][1][2] = mSortS(s);
        
        string test = "HelloWorld";
        result[i][2][0] = mInsertV(v,test);
        result[i][2][1] = mInsertL(l,test);
        result[i][2][2] = mInsertS(s,test);
        
        result[i][3][0] = mDeleteV(v);
        result[i][3][1] = mDeleteL(l);
        result[i][3][2] = mDeleteS(s, test);
    }

    vector<vector<int>> aresult(4, vector<int>(3, 0));
    for (int a = 0; a < sim; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 3; c++) {
                aresult[b][c] += result[a][b][c];
            }
        }
    }
    
    // Output
    cout << " Number of simulations: " << sim << endl ; 
    cout << " Operation  Vector  List    Set " << endl ;
    cout << " Read       " << aresult[0][0]/15 << "       " << aresult[0][1]/15 << "       " << aresult[0][2]/15 << endl;
    cout << " Sort       " << aresult[1][0]/15 << "       " << aresult[1][1]/15 << "       " << aresult[1][2]/15 << endl;
    cout << " Insert     " << aresult[2][0]/15 << "       " << aresult[2][1]/15 << "       " << aresult[2][2]/15 << endl;
    cout << " Delete     " << aresult[3][0]/15 << "       " << aresult[3][1]/15 << "       " << aresult[3][2]/15 << endl;
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/