#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool search(TrieNode *root,string word) {
        // Write your code here
      if(word.size()==0)
        {
            return root->isTerminal;
      }
        TrieNode* child;
        int index = word[0] - 'a';
        
        if(root->children[index]!= NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        
        return search(child , word.substr(1));
       
    }
    bool search(string word)
    {  return search(root,word);}

    void removeWord(TrieNode *root , string word){
        // base case
        if(word.size()==0){
            root->isTerminal =false;
            return;
        }

        // small calculation
        int index = word[0]-'a';
        TrieNode * child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }
        // recursive call
        removeWord(child , word.substr(1));

        // delete(unallocate)
        if(child->isTerminal ==false){
            for (int i = 0; i < 26; i++)
            {
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

};

// main
int main()
{
    int choice;
    cin >> choice;
    Trie t;

    while (choice != -1)
    {
        string word;
        bool ans;
        switch (choice)
        {
        case 1: // insert
            cin >> word;
            t.insertWord(word);
            break;
        case 2: // search
            cin >> word;
            cout << (t.search(word) ? "true\n" : "false\n");
            break;
        default:
            return 0;
        }
        cin >> choice;
    }

    return 0;
}
