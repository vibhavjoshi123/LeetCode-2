117. Populating Next Right Pointers in Each Node II
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode * a = root, * b = NULL, * c = NULL;
        while (a) {
            b = NULL;
            c = NULL;
            while (a) {
                if (a->left) {
                    if (b) {
                        c->next = a->left;
                        c = c->next;
                    }
                    else {
                        b = a->left;
                        c = b;
                    }
                }
                if (a->right) {
                    if (b) {
                        c->next = a->right;
                        c = c->next;
                    }
                    else {
                        b = a->right;
                        c = b;
                    }
                }
                a = a->next;
            }
            a = b;
        }
    }
};