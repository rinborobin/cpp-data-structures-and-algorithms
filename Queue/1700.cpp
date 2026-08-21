#include <queue>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
    queue<int> q;

public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int swIndex = 0;
        for (int student : students)
        {
            q.push(student);
        }

        int r = 0;

        while (r <= students.size() && q.size() > 0)
        {

            if (sandwiches[swIndex] == q.front())
            {
                q.pop();
                r = 0;
                swIndex++;
            }
            else
            {
                int student = q.front();
                q.pop();
                q.push(student);
                r++;
            }
        }

        return q.size();
    }
};

int main()
{
    Solution s;

    vector<int> st{1, 1, 1, 0, 0, 1};
    vector<int> sw{1, 0, 0, 0, 1, 1};

    int result = s.countStudents(st, sw);

    cout << result << endl;

    return 0;
}