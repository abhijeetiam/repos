#pragma once

#include <iostream>
#include <map>
#include <stack>

using namespace std;

class TrieNode;

typedef std::map<char, TrieNode*> TrieChildNodeMap;
typedef std::map<char, TrieNode*>::const_iterator TrieChildNodeMapIter;

class TrieNode
{
public:

	bool endOfWord_;
	TrieChildNodeMap children_;

	TrieNode() : endOfWord_(false) { cout << "TrieNode object created" << endl; }
	~TrieNode() {};
};

class Tries
{
public:
	Tries();
	~Tries();

	void Insert(const string);
	//void IsPartOfTrie(const string);
	//void AllPrefixMatches(const string);
	void PrintAllWords(TrieNode*, std::stack<char>&);
	void PrintWord(TrieNode*, std::stack<char>&);

	enum Operations
	{
		INSERT = 1,
		MEMBER,
		PREFIXMATCH,
		PRINT,
		EXIT = 10
	};

private:
	TrieNode* root_;
};

