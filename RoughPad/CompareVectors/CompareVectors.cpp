// vector comparisons
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1;
	std::vector<int> v2;

	v1.push_back(1);
	v1.push_back(3);
	v2.push_back(5);
	v2.push_back(7);
	
	if (v1 == v2) std::cout << "v1 and v2 are equal\n";
	if (v1 != v2) std::cout << "v1 and v2 are not equal\n";
	if (v1 < v2) std::cout << "v1 is less than v2\n";
	if (v1 > v2) std::cout << "v1 is greater than v2\n";
	if (v1 <= v2) std::cout << "v1 is less than or equal to v2\n";
	if (v1 >= v2) std::cout << "v1 is greater than or equal to v2\n";

	system("pause");
	return 0;
}