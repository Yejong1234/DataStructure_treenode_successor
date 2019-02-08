#include <stdio.h>

typedef struct TreeNode {//Ʈ�� ��带 ���� ����ü ����
	int data;
	struct TreeNode *left, *right, *parent;//Ʈ�� ������ ���� ������ ������
} TreeNode;
// G
// C F
// A B D E
TreeNode n1 = { 'A', NULL, NULL, NULL };//Ʈ�� ����ü�� ������ �ֱ�
TreeNode n2 = { 'B', NULL, NULL, NULL };
TreeNode n3 = { 'C', &n1, &n2, NULL };
TreeNode n4 = { 'D', NULL, NULL, NULL };
TreeNode n5 = { 'E', NULL, NULL, NULL };
TreeNode n6 = { 'F', &n4, &n5, NULL };
TreeNode n7 = { 'G', &n3, &n6, NULL };
TreeNode *exp = &n7;
TreeNode *tree_successor(TreeNode *p) {
	TreeNode *h;
	h = p->right;//p�� right �ּҸ� ��´�.

	if (h != NULL) {//h's right is not NULL
		while (h->left != NULL)//return the leftmost node of right subtree
			h = h->left;
		return h;
	}
	TreeNode *y = p->parent;//parent �ּҸ� ��´�.
	while (y != NULL && p == y->right) {//parent�� null�� �ƴϰ� p�� parent�� right child �� ���
		p = y;
		y = y->parent;//��� ���� parent�� ã�´�.
	}
	return y;

}
void main()
{
	TreeNode *q = exp;
	n1.parent = &n3;
	n2.parent = &n3;
	n3.parent = &n7;
	n4.parent = &n6;
	n5.parent = &n6;
	n6.parent = &n7;
	n7.parent = NULL;
	while (q->left) q = q->left; // Go to the leftmost node. ���� ���ʿ� �ִ� �� ���� �����ؼ� successor
	do
	{
		printf("%c\n", q->data); // Output data
		// Call the successor
		q = tree_successor(q);
	} while (q); // If not null
}
