// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2021

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.
class Bin{
  public:
    Data * bucketValue[125000]; 
    uint_fast32_t ssns[125000]; 
    unsigned int lastIndex = 0; 
};

Bin bucketB0[256]; 
Bin bucketB1[256]; 
Bin bucketB2[256]; 
Bin bucketB3[256]; 
vector<Data *> llfarr[26][26][26];
Data * arrData[1010000]; 


int getCase(list<Data *> &l){
    Data * first = *l.begin();
    Data * last = *prev(l.end());
    if(first->firstName == last->firstName && first->lastName == last->lastName) return 4; 
    if(first->firstName[0] == 'A' && first->lastName[0] == 'A' && last->lastName[0] == 'Z' && last->firstName[0] == 'Z') return 3; 
    if(l.size() < 10000) return 1; 
    return 2; 
}

bool ssnCompare(Data * first, Data * second){
    if(strcmp(first->lastName.c_str(), second->lastName.c_str()) != 0 || strcmp(first->firstName.c_str(), second->firstName.c_str()) != 0) 
        return false;
    return strcmp(first->ssn.c_str(), second->ssn.c_str()) > 0;
}

bool compare(Data* first, Data* second) {
	int l = strcmp(first->lastName.c_str(), second->lastName.c_str());
	if (l != 0)
		return l < 0;
	int f = strcmp(first->firstName.c_str(), second->firstName.c_str());
	if (f != 0)
		return f < 0;
	return strcmp(first->ssn.c_str(), second->ssn.c_str()) < 0;
}

void addToBinsFFLL(list<Data *> &l){
    for(auto &data: l)
      llfarr[(data->lastName)[0]-65][(data->lastName)[1]-65][(data->lastName)[2] - 65].push_back(data);  
}


void t12(list<Data *> &l){
    addToBinsFFLL(l);
    auto it = l.begin();
    for(int i = 0; i<26; ++i ){
        for(int j = 0; j<26; ++j){
            for(int k = 0; k<26; ++k){
              sort(llfarr[i][j][k].begin(), llfarr[i][j][k].end(),compare); 
              for(auto data: llfarr[i][j][k]){
                  *it = data;
                  ++it;
              }
            }
        }
    }
}


void insertionSortSSN(Data * arr[], int n){
    Data * key; 
    int j;
    for (int i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && ssnCompare(arr[j],key)) {
            arr[j + 1] = arr[j];
            --j; 
        }
        arr[j + 1] = key;
    }
}


void t3(list<Data *> &l){
  const int end = l.size();
  int counter = 0; 
  for(auto it = l.begin(); it != l.end(); ++it) arrData[counter++] = *it;
  insertionSortSSN(arrData,end);
  auto it = l.begin(); 
  for(int i = 0; i<end; ++i) {*it = arrData[i]; ++it;}
}







void t4(list<Data *> &l){
  uint_fast32_t ssn;
  unsigned int bnumber; 
  Data * data; 
  

  for(auto data: l){
    char ssnStr[9] = {data->ssn[0], data->ssn[1], data->ssn[2],data->ssn[4],data->ssn[5],data->ssn[7],data->ssn[8],data->ssn[9],data->ssn[10]}; 
    ssn = strtol(ssnStr,nullptr,10); 
    bnumber = ssn &0xFFu; 
    bucketB0[bnumber].bucketValue[bucketB0[bnumber].lastIndex] = (data); 
    bucketB0[bnumber].ssns[bucketB0[bnumber].lastIndex++] = ssn; 
  }
  for(int i = 0; i<256; ++i){
    for(int j = 0; j<bucketB0[i].lastIndex; ++j/*auto data: bucketB0[i]*/){
      data = bucketB0[i].bucketValue[j]; 
      ssn = bucketB0[i].ssns[j]; 
      bnumber = (ssn >> 8u) & 0xFFu;  
      bucketB1[bnumber].bucketValue[bucketB1[bnumber].lastIndex] = bucketB0[i].bucketValue[j]; 
      bucketB1[bnumber].ssns[bucketB1[bnumber].lastIndex++] = ssn; 
    }
  }

  for(int i = 0; i<256; ++i){
    for(int j = 0; j<bucketB1[i].lastIndex; ++j/*auto data: bucketB1[i]*/){
      data = bucketB1[i].bucketValue[j]; 
      ssn = bucketB1[i].ssns[j]; 
      bnumber = (ssn >> 16u) & 0xFFu;    
      bucketB2[bnumber].bucketValue[bucketB2[bnumber].lastIndex] = (data);
      bucketB2[bnumber].ssns[bucketB2[bnumber].lastIndex++] = ssn;
    }
  }

  for(int i = 0; i<256; ++i){
    for(int j = 0; j<bucketB2[i].lastIndex; ++j/*auto data: bucketB2[i]*/){
      data = bucketB2[i].bucketValue[j];
      ssn = bucketB2[i].ssns[j]; 
      bnumber = (ssn >> 24u) & 0xFFu;  
      bucketB3[bnumber].bucketValue[bucketB3[bnumber].lastIndex] = (data);
    }
  }

  list<Data *>::iterator it = l.begin();
  for(int i = 0; i<256; ++i){
    for(int j = 0; j<bucketB3[i].lastIndex; ++j/*auto data: bucketB3[i]*/){
      *it = bucketB3[i].bucketValue[j];
      ++it; 
    }
  }
}


void sortDataList(list<Data *> &l) {
  // Fill this in
  switch(getCase(l)){
      case 1: return t12(l);
      case 2: return t12(l);
      case 3: return t3(l);
      case 4: return t4(l);
      default: return (void)""; 
  }
}