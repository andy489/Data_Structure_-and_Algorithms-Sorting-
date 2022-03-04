// https://www.hackerrank.com/challenges/reverse-a-linked-list/problem

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* next;
    
    while(curr) {
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
    }

    return prev;
}
