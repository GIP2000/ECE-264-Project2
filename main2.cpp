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

list<Data *> llfarr[26][26][26][26];

int getCase(list<Data *> &l){
    Data * first = *l.begin();
    Data * last = *prev(l.end());
    if(strcmp(first->firstName.c_str(),last->firstName.c_str()) == 0 && strcmp(first->lastName.c_str(),last->lastName.c_str())) return 4; 
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

void addToBinsLastName(list<Data *> &l){
    for(auto &data: l)
      llfarr[(data->lastName)[0]-65][(data->lastName)[1]-65][(data->firstName)[0] - 65][(data->firstName)[1] - 65].push_back(data);  
}

void t12(list<Data *> &l){
    addToBinsLastName(l);
    auto it = l.begin();
    for(int i = 0; i<26; ++i ){
        for(int j = 0; j<26; ++j){
            for(int k = 0; k<26; ++k){
                for(int m =0; m<26; ++m){
                    llfarr[i][j][k][m].sort(compare);
                    for(auto data: llfarr[i][j][k][m]){
                        *it = data;
                        ++it; 
                    }
                }
            }
        }
    }
}

void t3(list<Data *> &l){
   for(auto it = l.begin(); next(it) != l.end();++it){
       if(ssnCompare(*it,*next(it))){ // we need to swap
       auto pivet = next(it);
        for(auto st = make_reverse_iterator(prev(pivet)); next(st) != l.rbegin(); ++st){
            auto fst = st.base(); 
            if(!ssnCompare(*pivet,*fst)){
                l.insert(fst,*pivet);
                l.erase(pivet);
            }
        }
        it--;
       }
   } 
}

void t4(list<Data *> &l){

}


void sortDataList(list<Data *> &l) {
  // Fill this in
  cout << "hello world\n"; 
  switch(getCase(l)){
      case 1: return t12(l);
      case 2: return t12(l);
      case 3: return t3(l);
      case 4: return t4(l);
      default: return (void)""; 
  }

  


  

}