1035. Uncrossed Lines
https://leetcode.com/problems/uncrossed-lines/

We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw a straight line connecting two numbers A[i] and B[j] as long as A[i] == B[j], and the line we draw does not intersect any other connecting (non-horizontal) line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:


Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
 

Note:

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int sz1 = A.size(), sz2 = B.size();
        vector<vector<int>> C(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
                if (A[i - 1] == B[j - 1])
                {
                    C[i][j] = 1 + C[i - 1][j - 1];
                }
                else
                {
                    C[i][j] = max(C[i - 1][j], C[i][j - 1]);
                }
            }
        }
        return C[sz1][sz2];
    }
};