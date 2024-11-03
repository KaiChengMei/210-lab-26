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
    vector<string> v;
    list<string> l;
    set<string> s;
    // Output
    cout << " Operation  Vector  List    Set " << endl ;

    int readVectorTime = mReadV(v, data);
    int readListTime = mReadL(l, data);
    int readSetTime = mReadS(s, data);
    cout << " Read       " << readVectorTime << "       " << readListTime << "       " << readSetTime << endl;
    
    int sortVectorTime = mSortV(v);
    int sortListTime = mSortL(l);
    int sortSetTime = mSortS(s);
    cout << " Sort       " << sortVectorTime << "       " << sortListTime << "       " << sortSetTime << endl;
    
    string test = "HelloWorld";
    int insertVectorTime = mInsertV(v,test);
    int insertListTime = mInsertL(l,test);
    int insertSetTime = mInsertS(s,test);
    cout << " Insert     " << insertVectorTime << "       " << insertListTime << "       " << insertSetTime << endl;
    
    int deleteVectorTime = mDeleteV(v);
    int deleteListTime = mDeleteL(l);
    int deleteSetTime = mDeleteS(s, test);
    cout << " Delete     " << deleteVectorTime << "       " << deleteListTime << "       " << deleteSetTime << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/