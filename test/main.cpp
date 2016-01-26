#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode *&head, int x) {
	ListNode *beforeStart = NULL;
	ListNode *beforeEnd = NULL;
	ListNode *afterStart = NULL;
	ListNode *afterEnd = NULL;
	if (head == NULL)
		return NULL;
	ListNode *cur = head->next;
	while (cur)
	{
		ListNode *nextNode = cur->next;
		cur->next = NULL;
		//��������before����
		if (cur->val < x)
		{
			if (beforeStart == NULL)
			{
				beforeStart = cur;
				beforeEnd = beforeStart;
			}
			else
			{
				beforeEnd->next = cur;
				beforeEnd = cur;
			}
		}
		else//��������after����
		{
			if (afterStart == NULL)
			{
				afterStart = cur;
				afterEnd = afterStart;
			}
			else
			{
				afterEnd->next = cur;
				afterEnd = cur;
			}
		}
		cur = nextNode;
	}

	if (beforeStart == NULL)
	{
		return afterStart;
	}

	//����������������
	beforeEnd->next = afterStart;
	return beforeStart;
}

void Create(ListNode *head)
 {
    int n;
	ListNode *p(head), *q;
    cout << "������Ԫ�ظ�������Ӧ����:";
    cin >> n;
	while (n--)
	{
		int value;
		cin >> value;
		q = new ListNode(value);
		q->next = nullptr;
		p->next = q;
		p = q;
	}
 }

void Print(ListNode *head)
 {
	ListNode *p = head->next;
    while (p)
    {
        cout << p->val << ' ';
        p = p->next;
    }
 }

int main()
{
	ListNode *head = new ListNode(0);
	Create(head);
	Print(head); 
	cout << "�ָ��" << endl;
	ListNode *p = partition(head, 4);
	while (p)
	{
		cout << p->val << ' ';
		p = p->next;
	}
}