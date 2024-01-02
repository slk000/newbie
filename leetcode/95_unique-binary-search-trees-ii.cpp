// AC
// https://leetcode.cn/problems/unique-binary-search-trees-ii
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // start <= root <= end
    int cnt = 0;
    vector<TreeNode *> dfs(int start, int end)
    {
        vector<TreeNode *> trees;
        if (start == end)
        {
            trees.push_back(new TreeNode(start));
            return trees;
        }
        // if(start > end) { // this situation is included below
        //     return vector<TreeNode*>();
        // }

        for (int root = start; root <= end; root++)
        {
            vector<TreeNode *> left = dfs(start, root - 1); // generate left tree
            vector<TreeNode *> right = dfs(root + 1, end);  // generate right tree
            if (left.size() != 0 && right.size() != 0)
            {
                for (TreeNode *l : left)
                {
                    for (TreeNode *r : right)
                    {
                        TreeNode *rt = new TreeNode(root);
                        rt->left = l;
                        rt->right = r;
                        trees.push_back(rt);
                    }
                }
            }
            else if (left.size() == 0 && right.size() != 0)
            {
                for (TreeNode *r : right)
                {
                    TreeNode *rt = new TreeNode(root);
                    rt->right = r;
                    trees.push_back(rt);
                }
            }
            else if (left.size() != 0 && right.size() == 0)
            {
                for (TreeNode *l : left)
                {
                    TreeNode *rt = new TreeNode(root);
                    rt->left = l;
                    trees.push_back(rt);
                }
            }
        }
        return trees;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return dfs(1, n);
    }
};

int main()
{
    int n;
    while (cin >> n)
    {
        Solution().generateTrees(n);
    }
    return 0;
}