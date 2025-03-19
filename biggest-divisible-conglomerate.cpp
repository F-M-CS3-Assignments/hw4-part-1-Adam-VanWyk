
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
		int div_pos = -1;
		vector<int> L;
		L.push_back(input.at(i));

		for (int j = i; j < input.size() - i; j++){
			if (input.at(j) % L.at(0) == 0){
				div_pos = j;
				break;
			}
		}
		if (div_pos == -1){
			return L;
		}
		vector<int> Rin = sub_vec(input, div_pos, input.size());
		
		vector<int> R = bdc_helper(Rin);

		vector<int> cand_v;
		copy(L.begin(), L.end(), back_inserter(cand_v));
		copy(R.begin(), R.end(), back_inserter(cand_v));

		cands.push_back(cand_v);
	}
	cout << vec_to_string(cands.at(0)) << endl;

	return cands.at(0);
}

vector<int> sub_vec(vector<int> vec, int start, int end){
    vector<int> answer(vec.begin() + start, vec.begin() + end);
    return answer;
}
