
#include <vector>
#include <string>
#include <iostream>
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
    vector <int> bdc;

    

    return bdc;
}   
