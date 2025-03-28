
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
	for (unsigned long i = 0; i < input.size(); i++){
		

	}

    

    return input;
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    sort(input.begin(), input.end()); // Sort in ascending order
    return bdc_helper_dynamic(input);
}   

int main(){
    vector<int> tester = {3, 5, 6, 10, 20};
    vector<int> ans = biggest_divisible_conglomerate(tester);
    cout << vec_to_string(ans) << endl;

}



