/*
Design And Implement LRU Cache



Problem Statement:



The LRU caching scheme removes the least recently used frame, when the cache is full and a new page is referenced which is not there in the cache.



You are given one integer named capacity, denoting the maximum size possible of the LRU cache. Also you are given three integer arrays named query_type, key and value, each having size n.



query_type[i], key[i] and value[i] together denotes one query. So there are total n queries.



query_type contains 0 or 1. query_type[i] = 0 means ith query is GET query and query_type[i] = 1 means ith query is SET query. key and value arrays contain only positive integers.



You have to return an array containing answers for GET queries.



GET query:

For GET query only key[i] matters, do not care what is stored in value[i].



For each GET query append one integer in the array to be returned. Append the value of the key[i], if the key[i] exists in the cache, otherwise append -1.



SET query:

If key[i] is already present in the cache then update its value to value[i], else add key[i] with value value[i] in the cache.



Input/Output Format For The Function:



Input Format:



There are four arguments in the input. First is integer named capacity. Second is integer array named query_type. Third is integer array named key. Fourth is integer array named value.



Output Format:



Return an array res containing answers for GET queries.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer capacity, denoting capacity of LRU cache.

The second line of input should contain an integer n, denoting the number of queries. In next n lines, ith line should contain an integer query_type[i], denoting an entry at index i of query_type array. (i=0,1,...,n-1)

In next line, there should be an integer n. In next n lines, ith line should contain an integer key[i], denoting an entry at index i of key array. (i=0,1,...,n-1)

In next line, there should be an integer n. In next n lines, ith line should contain an integer value[i], denoting an entry at index i of value array. (i=0,1,...,n-1)



If n = 7,

capacity = 2,



index     query_type     key       value

0              1                    5             11

1              1                    10           22

2              0                    5               1

3              1                    15           33

4              0                    10             1

5              1                    5             55

6              0                    5               1



Then input should be:



2

7

1

1

0

1

0

1

0

7

5

10

5

15

10

5

5

7

11

22

1

33

1

55

1



Output Format:



Let’s denote the total no of read queries in input as nr. Then resultant array res returned by solution function will be of size nr.

Hence, there will be nr lines, where ith line contains res[i], denoting entry at index i of res.



For input:

n = 7,

capacity = 2,



index     query_type     key       value

0              1                    5             11

1              1                    10           22

2              0                    5               1

3              1                    15           33

4              0                    10             1

5              1                    5             55

6              0                    5               1



Output will be:



11

-1

55



Constraints:



1 <= n <= 10^5
1 <= capacity <= 10^5
query_type[i] belongs to {0, 1}
1 <= key[i] <= 10^5
1 <= value[i] <= 10^5


Sample Test Case:



Sample Input:



capacity = 2



index     query_type     key       value

0              1                    5            11

1              1                    10          22

2              0                    5              1

3              1                    15          33

4              0                    10            1

5              1                    5            55

6              0                    5              1



(

this is same as:

query_type = [1 1 0 1 0 1 0]

key = [5 10 5 15 10 5 5]

value = [11 22 1 33 1 55 1]

)



Sample Output:



[11 -1 55]



Explanation:



Initially cache is empty.



Step 1:

SET: 5 -> 11

Noe cache contains (5 ->11).



Step 2:

SET: 10 -> 22

Now cache contains (5 -> 11) and (10 -> 22).



Step 3:

GET: 5

Cache contains (5 ->11), so append 11 to answer.



Step 4:

SET: 15 -> 33

Now cache contains (5 -> 11) and (15 -> 33).

Note that here (10 -> 22) is removed because 10 is the least recently used. 5 was used in the previous query!



Step 5:

GET: 10

Cache does not contain key 10 (it was removed in previous step), so append -1 to answer.



Step 6:

SET: 5 -> 55

Now cache contains (5 -> 55) and (15 -> 33). Note that (5 -> 11) is updated to (5 -> 55).



Step 7:

GET: 5

Cache contains (5 -> 55), so append 55 to answer.



Notes:

Suggested time in interview: 20 minutes.

The “Suggested Time” is the time expected to complete this question during a real-life interview, not now in homework i.e. For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, coding it, as well as identifying any gaps that you can discuss during a TA session. Take your time, but limit yourself to 2 one hour sessions for most problems.


class Cache {
	private:
		int capacity;
	public:
		int size;
		struct Node {
			int key;
			int value;
			Node *next, *prev;
			Node(int k, int v) : key(k), value(v), next(NULL), prev(NULL) {}
			Node() {}
		};

		unordered_map<int, Node *> hashMap;
		Node dummy_head, dummy_tail, *head, *tail;

		Cache(int c) {
			capacity = c;
			size = 0;

			head = &dummy_head;
			tail = &dummy_tail;

			head->next = tail;
			head->prev = NULL;
			tail->prev = head;
			tail->next = NULL;
		}

		void set(int key, int value) {
			if (hashMap.find(key) == hashMap.end()) {
				if (size == capacity) {
					evict();
				}
				Node *cur = new Node(key, value);

				hashMap[key] = cur;

				addResult(cur);
				size++;
			// key already present 
		}
		 else {
		 Node *cur = hashMap[key];
		 cur->value = value;
		 updateResult(cur);
			}
		}

		int get(int key) {
			if (hashMap.find(key) == hashMap.end())
				return -1;
			else {
				int value = hashMap[key]->value;
				Node *cur = hashMap[key];

				updateResult(cur);
				return value;
			}
		}

		virtual void evict() = 0;
		virtual void addResult(Node *cur) = 0;
		virtual void updateResult(Node *cur) = 0;
		virtual void deleteResult(Node *cur) = 0;
};

class LRUCache : public Cache {
public:

	LRUCache(int c) : Cache(c) {}
	void evict() {
		if (size == 0)
			return;

		Node *cur = tail->prev;
		hashMap.erase(cur->key);

		deleteResult(cur);
		delete cur;
		size--;
	}

	void addResult(Node *cur) {
		cur->next = head->next;
		head->next->prev = cur;
		head->next = cur;
		cur->prev = head;
	}

	void updateResult(Node *cur) {
		Node *next = cur->next;
		Node *prev = cur->prev;

		if (cur == head->next)
			return;

		cur->next = head->next;
		head->next->prev = cur;
		head->next = cur;
		cur->prev = head;

		next->prev = prev;
		prev->next = next;
	}

	void deleteResult(Node *cur) {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
};

vector <int>
implement_LRU_cache(int capacity, vector<int> query_type, vector<int> key, vector<int> value)
{

	LRUCache lru(capacity);
	vector<int> ret;

	for (int i = 0; i < query_type.size(); i++) {
		if (query_type[i] == 1) {
			lru.set(key[i], value[i]);
		}
		else {
			ret.push_back(lru.get(key[i]));
		}
	}

	return ret;
}


*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector <int> implement_LRU_cache(int capacity, vector <int> query_type, vector <int> key, vector <int> value) {

}

int main()
{
	ostream &fout = cout;

	vector <int> res;
	int capacity;
	cin >> capacity;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int query_type_size = 0;
	cin >> query_type_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<int> query_type;
	for (int i = 0; i < query_type_size; i++) {
		int query_type_item;
		cin >> query_type_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		query_type.push_back(query_type_item);
	}

	int key_size = 0;
	cin >> key_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<int> key;
	for (int i = 0; i < key_size; i++) {
		int key_item;
		cin >> key_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		key.push_back(key_item);
	}

	int value_size = 0;
	cin >> value_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<int> value;
	for (int i = 0; i < value_size; i++) {
		int value_item;
		cin >> value_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		value.push_back(value_item);
	}

	res = implement_LRU_cache(capacity, query_type, key, value);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		fout << res[res_i] << endl;;
	}


	return 0;
}
