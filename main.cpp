#include<iostream>
#include "weighted_random_sampling.cpp"

using namespace std;

void read_input(char*, int &, vector<double> &);

int main() {
	char* inputname = "WRS.inp";	
	vector<double> w;
	int n = 0;
	WRS wrs;	
	
	read_input(inputname, n, w);
	wrs.weight = w;
	wrs.init();
	for (int i = 0; i < n; i++) {
		wrs.weighted_generate();
	}	
	system("PAUSE");
	return 0;
}

void read_input(char* inputname, int &n, vector<double> &w) {
	const int MAX_CHARS = 1000;
	char line[MAX_CHARS];
	FILE *fin = fopen(inputname, "r");
	if (fin == NULL) {
		cout << "file not found" << endl;
	}
	else {
		fgets(line, MAX_CHARS, fin);
		n = atoi(line);
		fgets(line, MAX_CHARS, fin);
		char *pch;
		pch = strtok(line, ",");
		while (pch != NULL) {
			w.push_back(atof(pch));
			pch = strtok(NULL, ",");			
		}
	}	
}