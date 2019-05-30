/*
Top K



Problem Statement:



You are given an array of integers arr, of size n, which is analogous to a continuous stream of integers input. Your task is to find K largest elements from a given stream of numbers.

By definition, we don't know the size of the input stream. Hence, produce K largest elements seen so far, at any given time. For repeated numbers, return them only once.



If there are less than K distinct elements in arr, return all of them.



Note:

Don't rely on size of input array arr.
Feel free to use built-in functions if you need a specific data-structure.


Input/Output Format For The Function:



Input Format:



There is only one argument: Integer array arr.



Output Format:



Return an integer array res, containing K largest elements. If there are less than K unique elements, return all of them.

Order of elements in res does not matter.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting size of input array arr. In next n lines, ith line should contain an integer arr[i], denoting a value at index i of arr.

In the next line, there should be an integer, denoting value of K.



If n = 5, arr = [1, 5, 4, 4, 2] and K = 2, then input should be:



5

1

5

4

4

2

2



Output Format:



Let’s denote size of res as m, where res is the array of integers returned by solution function.

Then, there will be m lines of output, where ith line contains an integer res[i], denoting value at index i of res.



For input n = 5, arr = [1, 5, 4, 4, 2] and K = 2, output will be:



4

5



Constraints:

1 <= n <= 10^5
1 <= K <= 10^5
arr may contains duplicate numbers.
arr may or may not be sorted


Sample Test Case:



Sample Test Case 1:



Sample Input 1:



arr = [1, 5, 4, 4, 2]; K = 2



Sample Output 1:



[4, 5]



Sample Test Case 2:



Sample Input 2:



arr = [1, 5, 1, 5, 1]; K = 3



Sample Output 2:



[5, 1]

//Less Execution time

vector<int> topK(vector<int> arr, int k) {
	set<int> topk;

	for (int v : arr) {
		if (topk.find(v) == topk.end()) {
			topk.insert(v);
		}
		if (topk.size() > k) {
			topk.erase(topk.begin());
		}
	}

	vector<int> result(topk.begin(), topk.end());
	return result;
}


//Less Memory Usage

vector <int> topK(vector <int> arr, int k) {
	vector<int> heap;
	unordered_set<int> seen;
	auto comparator = [](int a, int b) { return a>b; };

	for (auto a: arr) {
		if (!seen.count(a)) {
			heap.push_back(a);
			push_heap(heap.begin(), heap.end(), comparator);
			if (heap.size() > k) {
				pop_heap(heap.begin(), heap.end(), comparator);
				heap.pop_back();
			}
			// for (auto b: heap) {
			//     cout << b << " ";
			// }
			// cout << endl;
			auto p = seen.insert(a);
			assert(p.second);
		}
	}
	return heap;



	// use minHeap
	// for (auto a: arr) {
	//     heap.push_back(a);
	//     push_heap(h.begin(), h.end(), cmp);
	//     if (heap.size() > k) {
	//         pop_heap(heap.begin(), heap.end(), cmp);
	//         heap.pop_back();
	//      }
	// }

}

*/


#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
vector <int> topK(vector <int> arr, int k) {

}


int main()
{
	ostream &fout = cout;

	vector <int> res;
	int arr_size = 0;
	cin >> arr_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<int> arr;
	for (int i = 0; i < arr_size; i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		arr.push_back(arr_item);
	}

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = topK(arr, k);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		fout << res[res_i] << endl;;
	}


	return 0;
}

