#include "Tries.h"

int main()
{
	int n;
	Tries* trie = new Tries();

	while (true)
	{
		cout << "============================TREE MENU=============================" << endl;
		cout << "1: INSERT into trie" << endl;
		cout << "2: MEMBERSHIP CHECK (Check if string is part of trie)" << endl;
		cout << "3: PREFIX MATCH (Return all strings that match the given prefix)" << endl;
		cout << "10: EXIT " << endl;
		cout << "==================================================================" << endl;
		cout << "Enter your choice : ";

		cin >> n;

		switch (n)
		{
		case Tries::INSERT:
		{
			cout << "Creating trie..." << endl;

			trie->Insert("CAT");
			trie->Insert("DOG");
			trie->Insert("BUNNY");
			trie->Insert("CAN");
			trie->Insert("CUT");
			trie->Insert("DOLL");
			break;
		}

		case Tries::MEMBER:
		{
			cout << "Printing trie..." << endl;

			//trie->IsPartOfTries();
			break;
		}

		case Tries::PREFIXMATCH:
		{
			cout << "Printing trie..." << endl;

			//trie->AllPrefixMatches();
			break; 
		}

		case Tries::EXIT:
		{
			cout << "Exiting ... !!!!" << endl;
			return 1;
		}

		case Tries::PRINT:
		{
			cout << "Printing trie ... !!!!" << endl;
			std::stack<char> path;
			TrieNode* curr = NULL;
			trie->PrintAllWords(curr, path);
			return 1;
		}

		default:
		{
			cout << "Invalid choice" << endl;
		}
		}

	}
	system("pause");
	return 1;
}