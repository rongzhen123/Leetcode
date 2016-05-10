/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> nodes;
		TreeNode* cur = root;//u��ǰ���ʵĽ��
		TreeNode* lastNode = NULL;//�ϴη��ʵĽ�� 
		while (cur || !s.empty())
		{
			//һֱ������ֱ��Ϊ��Ϊֹ
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			//������������Ϊ�ջ��Ѿ����ʹ������ʵ�ǰ���
			if (cur->right == NULL || cur->right == lastNode)
			{
				nodes.push_back(cur->val);
				lastNode = cur;
				s.pop();
				cur = NULL;
			}
			else
				cur = cur->right;
		}
		return nodes;
	}
};