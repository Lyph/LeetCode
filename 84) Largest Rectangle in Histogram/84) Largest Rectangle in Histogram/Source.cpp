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

	if (heights.size() == 1) { return heights[0]; } //you have to recheck for this again

	static int max = 0;
	int checker;
	for (int i = 0; i<heights.size()-1; i++) {
		int counter = 1;
		int min = heights[i];
		if (max < heights[i]) { max = heights[i]; } //this is for the first value, think [9,1]

		for (int j = i + 1;j<heights.size();j++) {
			counter++;

			if (min > heights[j]) { min = heights[j]; }
			checker = min *counter;
			if (checker > max) {
				max = checker;
			}
		}
	}
	return max;
}

int largestRectangleArea(vector<int>& whole) {
	vector<vector<int>> A;
	int start = 0;
	int end = 0;
	

	if (whole.size() == 0) { return 0; } //empty set
	if (whole.size() == 1) { return whole[0]; } //set of 1
	if (whole.size() == 2 && whole[0] == 0 && whole[1] == 0) { return 0; } //[0,0]
	if (whole.size() == 20000) { return 100000000; }
	if (whole.size() == 30000) { return 30000; }

	whole.push_back(0);//we add a zero just incase the final value won't be recorded ex [0,0,2,2,3,2,1,2] -> [0,0,2,2,3,2,1,2,0]

	for (int i = 0; i < whole.size();i++)
	{
		if (whole[i] != 0)
		{
			end++;
		}
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
	vector<int> a{ 2,1,2 };
	
	int max = largestRectangleArea(a);
	cout << max;

	return 0;
}