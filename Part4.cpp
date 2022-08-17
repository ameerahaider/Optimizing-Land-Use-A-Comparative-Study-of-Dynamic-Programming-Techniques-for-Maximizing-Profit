/*
	Ameera Haider 
	20I-0799
	Algo F
	Project
	Question# 2
	Part 4 Bottom Up Approach
*/

#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b;}

int cutLand (int sizes[], int table[], int rates[], int n) {
	
	int i, j;
	
	for (i = 1; i <= n; i++) {
		
		int max_rate = -1;
		
		for (j = 1; j < i; j++){
		
			max_rate = max(max_rate, rates[j] + table[i-j-1]);
			sizes[i] = j;
		}
		
		table[i] = max_rate;
	}
	
	return table[n];
}


int main() {
	
	//int rates[] = { 15, 75, 120, 135, 150, 255, 255};
	//int size = (20*25) /100;

	int w, l;
	cout << "Enter Width: ";
	cin >> w;
	cout << "Enter Length: ";
	cin >> l;
	
	int size = (w*l)/100;
	
	int rates[size];
	for (int i = 0; i < size; i++){
		
		cout << "Enter Price for Land Size " << i*100 << ": ";
		cin >> rates[i];
	}
	
	int table[size+1];	
	table[0] = 0;
	int sizes[size+1];
	for (int i = 0; i < size+1; i++ )	sizes[i] = 0;
	
cout << endl << "Maximum Obtainable Profit is " << cutLand(sizes, table, rates, size) << "k" << endl;
cout << endl << "Land can slpit into sizes: ";

while (size > 1 ) {
	
	cout << sizes[size]*100 << " ";
	size -= sizes[size];
}
cout << 100;
return 0;
}

