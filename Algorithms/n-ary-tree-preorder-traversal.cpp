/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (68.78%)
 * Likes:    295
 * Dislikes: 43
 * Total Accepted:    58.4K
 * Total Submissions: 84.9K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Return its preorder traversal as: [1,3,5,6,2,4].
 * 
 * 
 * 
 * Note:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node*> stk;
        if (root)
        {
            stk.push(root);
            while (!stk.empty())
            {
                root = stk.top();
                stk.pop();
                int val = root->val;
                result.push_back(val);
                vector<Node*>& v = root->children;
                for (vector<Node*>::reverse_iterator rend = v.rend(), rit = v.rbegin(); rit != rend; ++rit)
                {
                    stk.push(*rit);
                }
            }
        }
        return result;
    }
};