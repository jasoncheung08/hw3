#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // Empty list
  if (head == NULL) {
    smaller = NULL;
    larger = NULL;
    return;
  }

  Node* curr = head;
  head = head->next;
  curr->next = NULL;

  // Recursion
  Node* smallTail = NULL;
  Node* largeTail = NULL;
  llpivot(head, smallTail, largeTail, pivot);

  // Insert curr node into list
  if (curr->val <= pivot) {
    curr->next = smallTail;
    smaller = curr;
    larger = largeTail;
  }
  else {
    curr->next = largeTail;
    larger = curr;
    smaller = smallTail;
  }
}