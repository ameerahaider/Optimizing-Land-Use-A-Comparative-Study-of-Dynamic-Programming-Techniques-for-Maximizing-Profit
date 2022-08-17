/*
	Ameera Haider 
	20I-0799
	Algo F
	Project
	Question# 2
	Part 3 Bottom Up Approach
*/

#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b;}

int cutLand (int rates[], int n) {

	int table[n+1];
	table[0] = 0;
	int i, j;
	
	for (i = 1; i <= n; i++) {
		
		int max_rate = -1;
		
		for (j = 0; j < i; j++)
			max_rate = max(max_rate, rates[j] + table[i-j-1]);
		
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

cout << endl << "Maximum Obtainable Profit is " << cutLand(rates, size) << "k" << endl;
return 0;
}

