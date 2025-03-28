
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

int longest_vec(vector<vector<int>> cands){
	unsigned long longest = 0;
	for (unsigned long i = 0; i < cands.size(); i++){
		if (cands.at(i).size() > longest){
			longest = i;
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

    vector<vector<int>> index(input.size());
    for (unsigned long i = 0; i < input.size(); i++){
        index.at(i) = {input.at(i)};
    }

	int curr_element;
	for (unsigned long i = 0; i < input.size(); i++){
		curr_element = input.at(i);
		for (unsigned long j = i + 1; j < input.size(); j++){
			if (input.at(j)%curr_element==0 && index.at(i).size() >= index.at(j).size()){
				index.at(j) = {input.at(j)};
				for (unsigned long k = 0; k < index.at(i).size(); k++){
					index.at(j).push_back(index.at(i).at(k));
				}
			}
		}

	}
	int max_idx = longest_vec(index);
    return index.at(max_idx);
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    sort(input.begin(), input.end()); // Sort in ascending order
    return bdc_helper_dynamic(input);
}   

// int main(){
//     vector<int> tester = {3, 5, 6, 10, 20};
//     vector<int> ans = biggest_divisible_conglomerate(tester);
//     cout << vec_to_string(ans) << endl;

// }



