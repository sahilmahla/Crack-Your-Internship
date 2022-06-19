// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
Node *reverse(Node *curr1,Node* curr2, Node *end)
    {
        Node *curr = curr1;
        Node *next = end;
        while(curr!=end)
        {
            Node *temp = curr->next;
            curr->next = next;
            next = curr;
            curr = temp;
        }
        return next;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        Node *curr = head;
        Node *prev=NULL,*curr1,*curr2;
        int i=1;
        while(i<=n)
        {
            if(i==m)
            curr1 = curr;
            if(i==m-1)
            prev = curr;
            if(i==n){
            curr2 = curr;
            break;
         }
         curr = curr->next;  
          i++;
        }
       Node* end = curr->next;
       if(prev!=NULL)
        prev->next = reverse(curr1,curr2,end);
        else head = reverse(curr1,curr2,end);
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends