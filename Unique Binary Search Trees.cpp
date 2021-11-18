
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode *> constructTrees(int start, int end) {
    vector<TreeNode *> list;
    if (start > end) {
        list.push_back(NULL);
        return list;
    }

    for (int i = start; i <= end; i++) {
        vector<TreeNode *> l = constructTrees(start, i - 1);
        vector<TreeNode *> r = constructTrees(i + 1, end);

        for (int index = 0; index < l.size(); index++) {
            TreeNode *ln = l[index];
            for (int index1 = 0; index1 < r.size(); index1++) {
                TreeNode *rn = r[index1];
                TreeNode *cn = new TreeNode(i);
                cn->left = ln;
                cn->right = rn;
                list.push_back(cn);
            }
        }
    }
    return list;

}

vector<TreeNode *> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return constructTrees(1, A);
}
