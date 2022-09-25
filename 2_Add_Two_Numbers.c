/****************** 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

 

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.

*************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void insertAfter(struct ListNode **head, int value);

void insertAfter(struct ListNode **head, int value){
    struct ListNode *newNode = (struct ListNode*) malloc (sizeof(struct ListNode));
    if (newNode == NULL)
        return;
    
    newNode->val = value;
    newNode->next = NULL;
    
    if (*head == NULL){
        *head = newNode;
        return;
    }
    
    struct ListNode *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    return;
}
    
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *sum, *temp1 = l1, *temp2 = l2;
    int sumValue = 0;
    
    
    while (temp1 != NULL || temp2 != NULL){
        if (temp1 == NULL){
            sumValue += temp2->val;
            temp2 = temp2->next;
        }
        else if (temp2 == NULL){
            sumValue += temp1->val;
            temp1 = temp1->next;
        }
        else{
            sumValue += temp1->val + temp2->val;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        
        insertAfter(&sum, sumValue%10);        
        sumValue = sumValue/10;
    }
    
    return sum;
}

//print(reverse)
//main
