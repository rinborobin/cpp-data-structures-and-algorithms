#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        for (string word : strs)
        {
            sort(word.begin(), word.end());
            cout << word << endl;
        }

                return {};
    }
};

void printResult(const vector<vector<string>> &groups)
{
    cout << "[" << endl;

    for (const auto &group : groups)
    {
        cout << "  [ ";

        for (const auto &word : group)
        {
            cout << "\"" << word << "\" ";
        }

        cout << "]" << endl;
    }

    cout << "]" << endl;
}

int main()
{

    Solution solution;

    vector<string> strs = {
        "eat",
        "tea",
        "tan",
        "ate",
        "nat",
        "bat"};

    vector<vector<string>> result = solution.groupAnagrams(strs);

    printResult(result);

    return 0;
}