#include<bits/stdc++.h>
 
using namespace std;
 
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// Function to find the mid of linked-list
ListNode* find_middle(ListNode* head,int n)
        {
            ListNode *slow=head,*fast=head;
            while(fast!=NULL && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            } 
            if(n&1)
                return slow->next;
            else
                return slow;
        }
// Function to Reverse the List using three pointers
ListNode* reverse_link(ListNode* head)
        {
            ListNode *prev=NULL;
            ListNode *curr=head;
            ListNode *next=NULL;
            while(curr!=NULL)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
// Return if the Linked List is palindrome  
bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode *temp=head;
        // Iterate to count odd/even
        int n=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        temp=head;
        // Find the mid elemeny
        ListNode *head_mid=find_middle(temp,n);
        // Reverse the second half linked-list
        ListNode *head_rev=reverse_link(head_mid);
        // Verify first half and second half of linked-list are equivalent
        while(head_rev!=NULL)
        { 
 
            if(head->val!=head_rev->val)
                return false;
            
            head_rev=head_rev->next;
            head=head->next;
        }
        return true;
    }
 
// Driver Function
int main(){
    // Create nodes
    ListNode one = ListNode(31);
    ListNode two = ListNode(32);
    ListNode three = ListNode(33);
    ListNode four = ListNode(32);
    ListNode five = ListNode(31);
 
    ListNode *one_ptr = &one; 
    ListNode *two_ptr = &two; 
    ListNode *three_ptr = &three; 
    ListNode *four_ptr = &four; 
    ListNode *five_ptr = &five; 
 
    // Connect all the nodes
    five_ptr->next = NULL;
    one_ptr->next = &two;
    two_ptr->next = &three;
    three_ptr->next = &four;
    four_ptr->next = &five;
    ListNode* temp = &one;
 
    
    // Call function to return bool if the list is palindrome or not
    int result = isPalindrome(&one);
 
    if(result == 1)
            cout<<"The value is Palindrome\n";
    else
        cout<<"The value is NOT Palindrome\n";
 
return 0;
}
 
