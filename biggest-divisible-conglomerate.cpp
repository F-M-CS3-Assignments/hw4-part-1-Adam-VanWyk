
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#include "bdc.h"

using namespace std;

string vec_to_string(vector<int> vec){
	string str = "[";
	for (unsigned long i = 0; i < vec.size(); i++){
		//cout << vec[i] << endl;
		str.append(to_string(vec[i])); 
		str.append(", ");
	}
	if (!vec.empty()){
		str.erase(str.size() - 2, 2);
	}
	str.append("]");
	return str; 
}

int find_next_div_pos(vector<int> input, int idx, int mod){
	for (size_t i = idx; i < input.size(); i++){
		if (input[i] % mod == 0){
			return i; // return position of next divisor
		}
	}
	return -1; // no divisor found
}

vector<int> sub_vec(vector<int> vec, int start){
	if (start >= vec.size()){
		return {}; // invalid index
	}
    return vector<int> (vec.begin() + start, vec.end());

}

vector<int> longest_vec(vector<vector<int>> cands){
	vector<int> longest;
	for (const auto& vec : cands){
		if (vec.size() > longest.size()){
			longest = vec;
		}
	}
	return longest;
}

vector<int> bdc_helper_dynamic(vector<int> input){
    if (input.size() == 0 || input.size() == 1){
        return input;
    } 
    cout << vec_to_string(input) << endl;
    //cout << input.size() << endl;

    int** index = new int*[input.size()];
    for (unsigned long i = 0; i < input.size(); i++){
        index[i] = new int[input.size()];
    }

    

    return input;
}

// vector<int> bdc_helper(vector<int> input){
// 	if (input.size() <= 1){
// 		return input;
// 	}

// 	vector<vector<int>> cands;

// 	for (size_t i = 0; i < input.size(); i++){
// 		vector<int> L = {input[i]};
// 		set<int> L_set;

// 		int j = find_next_div_pos(input, i + 1, L.back());
// 		while (j != -1){
// 			vector<int> Rin = sub_vec(input, j);
// 			vector<int> R = bdc_helper(Rin); // recursion
// 			if (!R.empty() && (R.front() % L.back() == 0)){
// 				L.insert(L.end(), R.begin(), R.end()); // combine
// 			}
// 			j = find_next_div_pos(input, j + 1, L.back());
// 		}
// 		L_set.insert(L.begin(), L.end());
// 		L.clear();
// 		L.assign(L_set.begin(), L_set.end());
// 		cands.push_back(L); // Add candidate 

// 	}
// 	return longest_vec(cands);
// }

vector<int> biggest_divisible_conglomerate(vector<int> input){
    sort(input.begin(), input.end()); // Sort in ascending order
    return bdc_helper_dynamic(input);
}   

int main(){
    vector<int> tester = {3, 5, 6, 10, 20};
    vector<int> ans = biggest_divisible_conglomerate(tester);
    cout << vec_to_string(ans) << endl;

}



