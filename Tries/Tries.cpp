#include "Tries.h"

Tries::Tries()
{
}

Tries::~Tries()
{
}

void Tries::Insert(const string word)
{
	TrieNode* curr = root_;
	TrieChildNodeMapIter iter;
		
	for (int i = 0; i < word.length(); i++)
	{
		char ch = word[i];
		iter = curr->children_.find(ch);
		if (iter == curr->children_.end())
		{
			TrieNode* node = new TrieNode();
			curr->children_[ch] = node;
		}
		else
			curr = curr->children_[ch];
	}
	curr->endOfWord_ = true;
}

void Tries::PrintAllWords(TrieNode* curr, std::stack<char>& path)
{
	curr = root_;
	
	if (curr == NULL)
		return;

	if (curr->endOfWord_ == true)
		Tries::PrintWord(curr, path);
	
	for (auto& x : curr->children_)
	{
		if (x.second)
		{
			path.push(x.first);
			Tries::PrintAllWords(x.second, path);
		}
			
	}
}

void Tries::PrintWord(TrieNode* node, std::stack<char>& path)
{
	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();
	}
}