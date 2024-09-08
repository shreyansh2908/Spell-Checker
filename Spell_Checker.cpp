#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode{
         vector<TrieNode*> child;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {
        child = vector<TrieNode*>(26, nullptr); 
    }
};

class Trie {
    public:

    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }

    void insert(const string &word){
        TrieNode* node=root;
        for(char c :word){
            int index= c -'a';
            if(!node->child[index]){
                node->child[index]=new TrieNode;
            }

           node= node->child[index];
        }
            node->isEndOfWord=true;
    }

    bool SpellChecker(const string &word){
        TrieNode* node= root;
        for(char c : word){
            int index= c -'a';
            node=node->child[index];
            if(!node){
                return false;
            }
        }
        return node->isEndOfWord;
    }

    void dfs(TrieNode* node,const string &prefix,vector<string> &word){
        if(node->isEndOfWord){
            word.push_back(prefix);
        }

        for(int i=0;i<26;i++){
            char c='a'+i;
            if(node->child[i]){
                dfs(node->child[i],prefix+c,word);
            }
        }
    }

    vector<string> AutoComplete(const string &prefix){
         TrieNode* node = root;
        for(char c : prefix) {
            node = node->child[c - 'a'];
            if(!node) {
                return {};
            }
        }
        vector<string> words;
        dfs(node, prefix, words);
        return words;
    }

    vector<string> autoCorrect(const string &word) {
    vector<string> candidates;
    dfs(root, "", candidates);  // Collect all words using dfs
    
    vector<string> corrections;
    for(const string &candidate : candidates) {
        if(levenshteinDistance(word, candidate) <= 3) {
            corrections.push_back(candidate);
        }
    }
     return corrections;
    }

    int levenshteinDistance(const string &s1, const string &s2) {
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for(int i = 0; i <= s1.size(); i++) {
        for(int j = 0; j <= s2.size(); j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
           dp[i][j] = 1 + min(min(dp[i-1][j],      // Insert
                       dp[i][j-1]),     // Remove
                   dp[i-1][j-1]);       // Replace
                    
             }
         }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    Trie trie;
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    for(int i = 0; i < q; i++) {
        int type;
        string queryWord;
        cin >> type >> queryWord;

        if(type == 1) {
            cout << trie.SpellChecker(queryWord) << "\n";
        } else if(type == 2) {
            vector<string> words = trie.AutoComplete(queryWord);
            cout << words.size() << "\n";
            for(const string &word : words) {
                cout << word << "\n";
            }
        }
        else if(type == 3) {
            vector<string> corrections = trie.autoCorrect(queryWord);
            cout << corrections.size() << "\n";
            for(const string &word : corrections) {
            cout << word << "\n";
    }
}

    }

    return 0;
}
