#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Node {
        unordered_map<char, int> next;
        int bestIndex;
        Node() {
            bestIndex = -1;
        }
    };

    vector<Node> trie;

    // Update shortest word index
    void updateBest(int node,int idx,vector<string>& wordsContainer)
    {
        if(trie[node].bestIndex == -1 ||
           wordsContainer[idx].length() <
           wordsContainer[trie[node].bestIndex].length())
        {
            trie[node].bestIndex = idx;
        }
    }

    // Insert reversed word into Trie
    void insert(string word,int idx,vector<string>& wordsContainer)
    {
        reverse(word.begin(), word.end());
        int node = 0;
        updateBest(node, idx, wordsContainer);
        for(char ch : word)
        {
            if(trie[node].next.find(ch) ==
               trie[node].next.end())
            {
                trie[node].next[ch] = trie.size();
                trie.push_back(Node());
            }
            node = trie[node].next[ch];
            updateBest(node, idx, wordsContainer);
        }
    }

    // Search longest common suffix
    int search(string query)
    {
        reverse(query.begin(), query.end());
        int node = 0;
        for(char ch : query)
        {
            if(trie[node].next.find(ch) ==trie[node].next.end())
            {
                break;
            }
            node = trie[node].next[ch];
        }
        return trie[node].bestIndex;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,  vector<string>& wordsQuery)
    {
        // root node
        trie.push_back(Node());
        // Build Trie
        for(int i = 0; i < wordsContainer.size(); i++)
        {
            insert(wordsContainer[i], i, wordsContainer);
        }
        vector<int> ans;
        // Process queries
        for(string q : wordsQuery)
        {
            ans.push_back(search(q));
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<string> wordsContainer = {
        "abcdefgh",
        "poiuygh",
        "ghghgh"
    };

    vector<string> wordsQuery = {
        "gh",
        "acbfgh",
        "acbfegh"
    };

    vector<int> ans =obj.stringIndices(wordsContainer,  wordsQuery);
    cout << "Output: ";
    for(int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}