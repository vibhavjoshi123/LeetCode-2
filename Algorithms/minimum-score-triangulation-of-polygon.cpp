1039. Minimum Score Triangulation of Polygon
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.

Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the product of the labels of the vertices, and the total score of the triangulation is the sum of these values over all N-2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

 

Example 1:

Input: [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
Example 2:



Input: [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.
Example 3:

Input: [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
 

Note:

3 <= A.length <= 50
1 <= A[i] <= 100

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int sz = A.size();
        vector<vector<int>> B(sz, vector<int>(sz, INT_MAX));
        for (int i = 0; i < sz; ++i)
        {
            int j = i + 1;
            j %= sz;
            B[i][j] = 0;
        }
        for (int d = 2; d < sz; ++d)
        {
            for (int i = 0; i + d < sz; ++i)
            {
                int j = i + d;
                for (int k = i + 1; k < j; ++k)
                {
                    int val = B[i][k] + B[k][j] + A[i] * A[k] * A[j];
                    B[i][j] = min(B[i][j], val);
                }
            }
        }
        return B[0][sz - 1];
    }
};