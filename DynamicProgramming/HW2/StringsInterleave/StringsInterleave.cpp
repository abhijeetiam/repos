/*
Strings Interleave





Problem Statement:

You're given three strings a, b and i. Write a function that checks whether i is an interleaving of a and b.



String i is said to be interleaving string a and b, if:
len(i) = len(a) + len(b).
i only contains characters present in a or b.
i contains all characters of a. From a, any character a[index] should be added exactly once in i.
i contains all characters of b. From b, any character b[index] should be added exactly once in i.
Order of all characters in individual strings (a and b) is preserved.


Input Format:



You will be given three strings a, b and i.



Strings can contain

Small alphabets - a-z
Large alphabets - A-Z
Numbers - 0-9


Output Format:



Return a boolean if i is an interleaving of a and b.



Constraints:



0 <= len(a), len(b) <= 1000

0 <= len(i) <= 2000



Sample Test Case:



Sample Input-1:



a = "123"

b = "456"

i = "123456"



Sample Output-1:



True



Sample Input-2:



a = "AAB"

b = "AAC"

i = "AAAABC"



Sample Output-2:



True



Sample Input-3:



a = "AAB"

b = "AAC"

i = "AAABAC"



Sample Output-3:

True


const int AB_MAX_LEN = 1000;
const int I_MAX_LEN = 2000;

void validate_string(string &s, int max_len){
	assert(s.length() <= max_len);

	for (char& ch : s){
		assert(
			('0' <= ch && ch <= '9') ||
			('a' <= ch && ch <= 'z') ||
			('A' <= ch && ch <= 'Z')
		);
	}
}

void validate_test_case(string &a, string &b, string &i){
	validate_string(a, AB_MAX_LEN);
	validate_string(b, AB_MAX_LEN);
	validate_string(i, I_MAX_LEN);
}

bool doStringsInterleave(string a, string b, string i) {
	validate_test_case(a, b, i);

	if (a.length() + b.length() != i.length()){
		return false;
	}

	bool dp[a.length() + 1][b.length() + 1];

	for (int ai = 0; ai <= a.length(); ai++){
		for (int bi = 0; bi <= b.length(); bi++){
			bool dp_ai_min_1_bi = false;
			bool dp_ai_bi_min_1 = false;

			if (ai > 0){
				dp_ai_min_1_bi = dp[ai - 1][bi] &&
								 (a[ai - 1] == i[ai + bi - 1]);
			}
			if (bi > 0){
				dp_ai_bi_min_1 = dp[ai][bi - 1] &&
								 (b[bi - 1] == i[ai + bi - 1]);
			}

			dp[ai][bi] = (ai == 0 && bi == 0) ||
						 dp_ai_min_1_bi ||
						 dp_ai_bi_min_1;
		}
	}

	return dp[a.length()][b.length()];
}

﻿﻿﻿﻿﻿﻿﻿﻿﻿


*/

#include <bits/stdc++.h>

using namespace std;
/*
 * Complete the 'doStringsInterleave' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 *  3. STRING i
 */

bool doStringsInterleave(string a, string b, string i) {

}

int main()
{
	ostream &fout = cout;

	string a;
	getline(cin, a);

	string b;
	getline(cin, b);

	string i;
	getline(cin, i);

	bool result = doStringsInterleave(a, b, i);

	fout << result << "\n";



	return 0;
}
