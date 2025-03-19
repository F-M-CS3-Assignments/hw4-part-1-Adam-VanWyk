
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "bdc.h"

using namespace std;

string vec_to_string(vector<int> vec){
	string str = "[";
	for (unsigned long i = 0; i < vec.size(); i++){
		//cout << vec[i] << endl;
		str.append(to_string(vec[i])); 
		str.append(", ");
	}
	str.erase(str.size() - 2, 2);
	str.append("]");
	return str; 
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    sort(input.begin(), input.end());
    return bdc_helper(input);
}   

vector<int> bdc_helper(vector<int> input){
	if (input.size() == 0 || input.size() == 1){
		return input;
	}
	vector<vector<int>> cands;
	for (int i = 0; i < input.size() - 1; i ++){
		vector<int> L;
		L.push_back(input.at(i));
	}


}
