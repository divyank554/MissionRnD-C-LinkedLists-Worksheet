/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K)
{
	if (head == NULL || head->num == K || K <= 0)
		return NULL;

	int i;
	int n = K;

	struct node *temp = head;
	int length = 0;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}

	while (K <= length)
	{
		struct node *current = head;
		struct node *prev;
		for (i = 1; i < K - 1; i++)
		{
			current = current->next;

			if (current->next == NULL)
				return head;
		}

		prev = current;

		current = current->next->next;

		prev->next = current;

		K = K + (n - 1);
	}

	return head;
}
	 
