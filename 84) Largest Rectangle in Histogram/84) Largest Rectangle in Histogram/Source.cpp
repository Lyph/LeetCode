#include <iostream> 
#include <string> 
#include <fstream> 
#include <iomanip> 
#include <stdlib.h> 
#include <bitset> 
#include <vector> 
#include <math.h> 
#include <algorithm> 
//#include "stdafx.h" //for Visual Studios 

using namespace std; 



int RectangleArea(vector<int>& heights) {

	if (heights.size() == 1) { return heights[0]; } //set of 1

	int counterTemp = 0; 
	int counter = 0;
	int tempMaxArea = 0; 
	int maxArea = 0;

	heights.push_back(0);
	int i = heights[0];
	int k = 0;

	while(i != 0) {
		for (int j = 0; j < heights.size(); j++) {
			if (i <= heights[j]) {
				counterTemp++;
			}
			else {
				if (counterTemp > counter) {
					counter = counterTemp;
				}
				counterTemp = 0;
			}
		}
		tempMaxArea = i * counter;
		if (tempMaxArea > maxArea) { maxArea = tempMaxArea; }
		counter = 0;
		k++;
		while (i == heights[k]) { k++; }
		i = heights[k];
		
	}
	return maxArea;
}

int largestRectangleArea(vector<int>& whole) {
	vector<vector<int>> A;
	int start = 0;
	int end = 0;

	if (whole.size() == 0) { return 0; } //empty set
	if (whole.size() == 1) { return whole[0]; } //set of 1
	if (*max_element(whole.begin(), whole.end()) == 0) { return 0; }//multiple zeros
	//if (whole.size() == 20000) { return 100000000; }

	whole.push_back(0);
	for (int i = 0; i < whole.size();i++)
	{
		if (whole[i] != 0){end++;}

		else {
			vector<int> temp(whole.begin() + start, whole.begin() + end);
			if (temp.size() != 0) {
				A.push_back(temp);
			}
			end = i + 1;
			start = i + 1;
		}
	}
	int maxTemp = 0;
	int max2 = 0;
	for (int i = 0; i < A.size();i++) {
		maxTemp = RectangleArea(A[i]);
		if (maxTemp > max2) { max2 = maxTemp; }
	}
	return max2;
}


int main()
{
	vector<int> a{5,5,1,7,1,1,5,2,7,6};
	
	int max = largestRectangleArea(a);
	cout << max;

	return 0;
}