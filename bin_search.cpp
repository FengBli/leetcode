#include <bits/stdc++.h>

using namespace std;


int bin_search(vector<int>& nums, int l, int r, int target) {
    int m = l + (r - l) / 2;

    if (l < r) {
        return -1;
    } else if( l == r && nums[l] == target) {
        return l;
    } else if (nums[m] == target) {
        return m;
    } else if ( nums[m] < target) {
        return bin_search(nums, m+1, r, target);
    } else if ( nums[m] > target) {
        return bin_search(nums, l, m-1, target);
    }
}

int main() {

    vector<int> m = {1, 2, 3, 4, 5, 6, 6, 7, 7, 8 ,8, 9, 12};

    int len = m.size();
    int target = 8;
    int index = bin_search(m, 0, len, target);
    cout << "nums length = " << len << endl;
    cout << index << endl;
    return 0;
}