#include <fstream>
#include <iostream>
#include "map.h"
using namespace std;

void PrintMap(Map<string, int> mp);

void CountMap(ifstream & instr) {
	Map<string, int> myMap;
	string nxtword;

	while (true) {
		instr >> nxtword;
		if (instr.fail()) break;
		else {
			if (myMap.containsKey(nxtword)) {
				int count = myMap.get(nxtword);
				myMap[nxtword] = count + 1;
			} else
				myMap[nxtword] = 1;
		}
	}
	PrintMap(myMap);
}

void PrintMap(Map<string, int> mp) {
	for (Map<string, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
		string mkey = *itr;
		cout << mkey << "->" << mp[mkey] << endl;
	}
}

int main() {
	ifstream instr;
	string fn = "test.txt";
	instr.open(fn.c_str());
	if (instr.fail())
		cout << "Open fail" << endl;
	CountMap(instr);
	return 0;
}