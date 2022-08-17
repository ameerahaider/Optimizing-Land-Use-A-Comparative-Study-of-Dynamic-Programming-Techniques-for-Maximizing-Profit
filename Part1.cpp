/*
	Ameera Haider 
	20I-0799
	Algo F
	Project
	Question# 2
	Part 1 Simple Top Down Approach
*/

#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b;}

int cutLand (int rates[], int n) {
	
	if (n <= 0)
		return 0;
	
	int max_rates = -1;
	
	for (int i = 0; i < n; i++){
	
		int cost = rates[i] + cutLand(rates, n-i-1);
		max_rates = max (max_rates, cost);
	}
	
	return max_rates;
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

