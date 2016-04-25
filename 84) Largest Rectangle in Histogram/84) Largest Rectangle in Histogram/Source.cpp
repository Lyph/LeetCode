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

int largestRectangleArea(vector<int>& heights) {

	if (heights.size() == 0) { return 0; } //empty set
	if (heights.size() == 1) { return heights[0]; } //set of 1
	if (*max_element(heights.begin(), heights.end()) == 0) { return 0; }//multiple zeros
	bool sorted = true;
	int sortedMax = 0;
	int sortedTemp = 0;

	for (int i = 1; i < heights.size(); i++) {
		if (heights[i] < heights[i - 1]) {
			sorted = false;
			break;
		}
	}

	if (sorted)
	{
		for (int i = 0; i < heights.size(); i++) {
			
			sortedTemp = heights[i] * (heights.size() - i);
			if (sortedTemp > sortedMax) { sortedMax = sortedTemp; }
		}
		return sortedMax;
	}

	int counterTemp = 0;
	int counter = 0;
	int tempMaxArea = 0;
	int maxArea = 0;

	int i = heights[0];
	int k = 0;
	bool uni;

	vector<int> unique{heights[0]};
	for (int i = 0; i < heights.size(); i++) {
		for (int j = 0; j < unique.size(); j++) {
			if (heights[i] == unique[j])
			{
				uni = false;
				break;
			}
			else 
			{
				uni = true;
			}
		}
		if (uni == true) { unique.push_back(heights[i]); }
	}

	heights.push_back(0);

	for (int i = 0; i < unique.size(); i++) {
		for (int j = 0; j < heights.size(); j++) {
			if (unique[i] <= heights[j]) {
				counterTemp++;
			}
			else {
				if (counterTemp > counter) {
					counter = counterTemp;
				}
				counterTemp = 0;
			}
		}
		tempMaxArea = unique[i] * counter;
		if (tempMaxArea > maxArea) { maxArea = tempMaxArea; }
		counter = 0;
		counterTemp = 0;

	}
	return maxArea;
}


int main()
{
	vector<int> a{ 0,1,0,9 };

	int max = largestRectangleArea(a);
	cout << max;

	return 0;
}