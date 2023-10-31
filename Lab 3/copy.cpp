#include<iostream>
using namespace std;
class NODE {
public:
	int data;
	NODE* next;
	NODE() {

	}
	NODE(int a)
	{
		data = a;
		next = NULL;
	}
	NODE (int a,NODE* temp)
	{
		data = a;
		next = temp;
	}

};
class LL {
public:
	NODE* head;
	NODE *tail;
	LL()
	{
		head = NULL;
		tail = NULL;
	}

	void insertAtHEad(int a)
	{
		if (head == NULL)
		{
			head = tail = new NODE(a);
		}
		else {
			NODE* temp = head;
			head = new NODE(a);
			head->next = temp;
		}
	}
	void insertAtTail(int a)
	{
		if (tail == NULL)
		{
			head=tail = new NODE(a);
		}
		else {
			NODE* temp = tail;
			tail = new NODE(a);
			temp->next = tail;

		}

	}
	void insertAtMiddle(int pos, int a)
	{
		NODE* temp = head;
		int count = 1;
		if (head == NULL)
		{
			insertAtHEad(a);
			return;

		}
		while (count < pos - 1)
		{
			temp = temp->next;
			count++;
		}
		if (temp->next == NULL)
		{
			insertAtTail(a);
			return;
		}
		else
		{
			NODE* n = new NODE(a);
			n->next = temp->next;
			temp->next = n;
		}


	}

	void print()
	{
		cout << endl;
		NODE* temp = head;
		while (temp != NULL)
		{
			if (temp->next != NULL)
			{
				cout << temp->data << "  ---->  ";
				temp = temp->next;

			}
			else {
				cout << temp->data;
				temp = temp->next;
			}
		}
	}
	void update(int a, int pos)
	{
		NODE *temp = head;
		int count = 1;
		while (count != pos )
		{
			temp = temp->next;
			count++;
		}
		temp->data = a;
	}

    void deleted(int pos){
        if(head==NULL)
        {
            cout<<"LINK LIST IS ALREADY EMPTY"<<endl;
        }
        else if(pos==1)
        {
            NODE* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        else {
            NODE* curr=head;
            NODE* prev=NULL;
            int count=1;
            while(count<pos)
            {
                prev=curr;
                curr=curr->next;
                count++;
            }
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
        }

            
    }
    
    // void oddeven()
    // {
    // 	NODE* evenHead=NULL;
    // 	NODE* evenTail=NULL;
    // 	NODE* oddHead=NULL;
    // 	NODE* oddTail=NULL;
    // 	NODE* temp=head;
    // 	while(temp!=NULL)
    // 	{
    // 		if(temp->data%2==0)
    // 			{ 	
	// 				if(evenHead==NULL)
    // 					{
    // 						evenHead=evenTail=new NODE(temp->data);
	// 					}	
					
	// 				else{
    // 						evenTail->next=new NODE(temp->data);
    // 						evenTail=evenTail->next;
    						
	// 					}
	// 			}
	// 		else if(temp->data%2!=0)
	// 		{
	// 			if(oddHead==NULL)
    // 					{
    // 						oddHead=oddTail=new NODE(temp->data);
	// 					}	
					
	// 				else{
    // 						oddTail->next=new NODE(temp->data);
    // 						oddTail=oddTail->next;
    						
	// 					}
	// 		}

	// 		temp=temp->next;
    // 	}
    // 	evenTail->next=oddHead;
    // 	if(evenHead)
    // 	{
	// 	head=evenHead;
	// 	}
	// 	else
	// 	head=oddHead;
	// 	if(oddTail)
	// 	tail=oddTail;
	// 	else
	// 	tail=evenTail;
	// }
	
	void palindrome()
{
    bool flag = true;
    int count = 0;
    NODE* aHead = NULL;
    NODE* aTail = NULL;
    NODE* bHead = NULL;
    NODE* bTail = NULL;
    NODE* temp1 = head;
    LL list2;

    // Calculate the total count of nodes
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        count++;
    }

    if (count == 0) {
        cout << "The linked list is empty." << endl;
        return;
    }

    int a, b;
    a = count / 2;
    b = count / 2;
    // Reset temp1 to the head of the list
    temp1 = head;

    // Populate aHead and bHead
    while (a > 0)
    {
        if (aHead == NULL)
            list2.insertAtHEad(temp1->data);
        else {
            aTail->next = new NODE(temp1->data);
            aTail = aTail->next;
        }
        a--;
        temp1 = temp1->next;
    }

    // Skip the middle node for odd counts
    if (count % 2 != 0)
    {
        temp1 = temp1->next;
    }

    while (b > 0)
    {
        if (bHead == NULL)
            bHead = bTail = new NODE(temp1->data);
        else {
            bTail->next = new NODE(temp1->data);
            bTail = bTail->next;
        }
        b--;
        temp1 = temp1->next;
    }

    // Compare aHead and bHead
    while (aHead)
    {
        if (aHead->data != bHead->data)
        {
            flag = false;
            break;
        }
        aHead = aHead->next;
        bHead = bHead->next;
    }

    if (flag) {
        cout << "palindrome" << endl;
    }
    else
        cout << "not a palindrome" << endl;
}

	
};
int main() {
	LL obj1;
	obj1.insertAtTail(1);
	obj1.insertAtTail(2);
	obj1.insertAtTail(3);
	obj1.insertAtTail(2);
	obj1.insertAtTail(1);
		obj1.palindrome();
}