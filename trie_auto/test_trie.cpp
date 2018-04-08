#include <bits/stdc++.h>
using namespace std;

struct trienode
{
	trienode* children[26];
	bool is_end_of_word;
};

vector <char> vec;

trienode* getnode()
{
	trienode* new_node = new trienode;

	for(int i=0;i<26;i+=1)
	{
		new_node->children[i] = NULL;
	}

	new_node->is_end_of_word = false;

	return new_node;
}

void insert(trienode* root, string key)
{
	trienode* temp = root;

	for(int i=0;key[i];i+=1)
	{
		if(temp->children[key[i]-'a']==NULL)
			temp->children[key[i]-'a'] = getnode();
		temp = temp->children[key[i]-'a'];
	}

	temp->is_end_of_word=true;
}

trienode* f_root;

int search_for_prefix(trienode* root, string key)
{
	f_root = root;

	for(int i=0;key[i];i+=1)
	{
		if(f_root->children[key[i]-'a']==NULL)
			return 0;
		f_root=f_root->children[key[i]-'a'];
	}

	return 1;
}

int islast(trienode* root)
{
	for(int i=0;i<26;i+=1)
	{
		if(root->children[i])
			return 0;
	}
	return 1;
}


void autocomplete(trienode* root, string key)
{
	vector<trienode*> node_vec;
	vector<int> indx_vec;
	vector<char> char_vec;
}


int main(int argc, char** argv)
{

	string s;

	trienode *root = getnode();

	string line;
	ifstream myfile ("/home/mohit123/Desktop/autocomp/trie_auto/words.txt");
	if (myfile.is_open())
	{
	    while (getline(myfile,line))
	    {
	      // cout << line << '\n';
	      insert(root, line);
	    }
	    myfile.close();
	}

	{
		s = argv[1];
		vec.clear();
		int present = search_for_prefix(root, s);
		if(present==0)
		{
			cout<<"NO such prefix"<<endl;
		}
		else
		{
			autocomplete(f_root, s);
		}

	}

	return 0;
}