#include <bits/stdc++.h>
using namespace std;
#include "solution.h"

// your code
#include <string>
#include <vector> 
#include <algorithm>

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */


    bool palin(string word){
        for(int i=0,j=word.length()-1;i<=j;i++,j--){
            if(word[i]!=word[j]){
                return false;
            }
        }
        return true;
    }
    int getindex(TrieNode *root){
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                return i;
            }
        }
        return -1;
    }
    bool check(TrieNode* root,string str){
        if(root->childCount==0)
        {
            if(palin(str))
                return true;
        return false;
        }
        int childindex=getindex(root);
        TrieNode* child=root->children[childindex];
        char s=childindex+'a';
        str=str+s;
        return check(child,str);
    }
    bool newsearch(TrieNode* root,string word){
        if(word.size()==0){
            if(root->childCount==0){
                return true;
            }
            else
                return check(root,"");
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else
            return false;
        return newsearch(child,word.substr(1));
    }
    bool search(vector<string> arr){
        for(int i=0;i<arr.size();i++){
            string str=arr[i];
            string reverse="";
            for(int j=str.length()-1;j>=0;j--){
                reverse+=str[j];
            }
            if(newsearch(root,reverse))
                return true;
        }
            return false;
    }
    
    
    
    // upto this
    bool isPalindromePair(vector<string> arr) {
        // Write your code here
        
        for(int i=0;i<arr.size();i++){
            string s=arr[i];
            insertWord(s);
        }
        return search(arr);
    }
};


// main
int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}