
#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);


	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	values = {};
	ans = biggest_divisible_conglomerate(values);
	assert(ans.empty());

	values = {42};
	ans = biggest_divisible_conglomerate(values);
	assert(ans == values);

	values = {3, 5, 7, 11, 13};
	ans = biggest_divisible_conglomerate(values);
	assert(ans.size() == 1);

	values = {9, 3, 6, 18, 2, 4};
	ans = biggest_divisible_conglomerate(values);
	set<int> soln1 = {18, 9, 3};
	set<int> soln2 = {6, 3, 18};
	set<int> soln3 = {4, 2};
	set<int> answerSeta(ans.begin(), ans.end());
	assert(answerSeta == soln1 || answerSet == soln2 || answerSet == soln3);

	values = {1, 2, 4, 8, 16, 32};
	ans = biggest_divisible_conglomerate(values);
	set<int> expected = {32, 16, 8, 4, 2, 1};
	set<int> answerSetb(ans.begin(), ans.end());
	assert(answerSetb == expected);

	values = {50, 25, 100, 10, 5, 20, 4, 2, 1};
	ans = biggest_divisible_conglomerate(values);
	cout << vec_to_string(ans) << "ANS " << endl;
	set<int> expectedq = {100, 50, 25, 5, 1};
	set<int> answerSetc(ans.begin(), ans.end());
	assert(answerSetc == expectedq);
	
	values = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
	ans = biggest_divisible_conglomerate(values);
	assert(ans.size() == values.size());

	values = {17, 23, 31, 47, 53, 89};
	ans = biggest_divisible_conglomerate(values);
	assert(ans.size() == 1);

	
	vector<int> vint = {100, 2, 3, 4, 5, 7, 14, 21, 25, 30, 49, 70, 77};
	//cout << vec_to_string(vint) << endl;

	vector<int> cand = biggest_divisible_conglomerate(vint);
	cout << vec_to_string(cand) << endl;

	return 0;
}
