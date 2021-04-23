//
// Created by Bailin Feng on 2020/11/28.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int wordSize = word.size();
        int res = 0;
        for(int i = 0; i < sequence.size(); ++i) {
            if(sequence.substr(i, wordSize) == word) {
                int k = 0;
                for(int j = i; j < wordSize; j += wordSize) {
                    cout << "j = " << j << endl;
                    if(sequence.substr(j, wordSize) == word) k++;
                    else break;
                }
                res = max(res, k);
            }
        }
        return res;
    }
};