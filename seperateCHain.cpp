#include <iostream>
#define MAX 10
using namespace std;

class Node{
    public:
    	Node * prev ;
    	int data;
    	Node * next;
    	
    	Node(int v){
    	    data = v;
    	    prev = next = NULL;
    	}
};

class Hashing
{
    Node* ht[MAX];
    Node* top[MAX];
    
    public:
        Hashing(){
            *ht = new Node(MAX);
            *top = new Node(MAX);
            for(int i = 0 ; i < MAX ; i++)
            {
                ht[i] = NULL ;
                top[i] = NULL;
            }
        }
        int hashkey(int val){
            return val%MAX;
        }
        void insert(){
            int data;
            cout<<"enter a value : "<<endl;
            cin>>data;
            int i = hashkey(data);
            Node *t = new Node(data);
            if(ht[i]==NULL)
            {
                ht[i]=t;
                top[i]=t;
            }
            else
            {
                t->prev = top[i];
                top[i]->next = t;
                top[i] = t;
            }
        }
        
        void display(){
            Node * temp;
            for(int i =0 ; i<MAX ; i++)
            {
                if(i<10)
                    cout<<"\t ht[0"<<i<<"] : ";
                temp = ht[i];
                if(temp!=NULL)
                {
                    while(temp!=NULL)
                    {
                        cout<<temp->data;
                        temp = temp->next;
                        if(temp!=NULL)
                            cout<<"->";
                    }
                }
                else
                    cout<<"-";
                cout<<"\n";
            }
        }
        
        void search()
        {
            int data;
            int flag = 0 ;
            cout<<"enter a value : ";
            cin>>data;
            int i = hashkey(data);
            Node * temp = ht[i];
            if(temp!=NULL)
            {
                while(temp!=NULL){
                    if(temp->data==data)
                        flag++;
                    temp = temp->next;
                }
                if(flag>0)
                    cout<<"\t *** the search Element is found "<<flag<<"times";
            }
            if(flag==0)
                cout<<" the search Element is not found ";
        }
        
        
        void delete()
        {
            int data; 
            cout<<"Enter a value : ";
            cin>>data;
            int flag = 0 ;
            int i = hashkey(data);
            Node *pr = ht[i];
            if(pr!= NULL)
            {
                while(pr!=NULL)
                {
                    if(pr->data==data)
				    {
				    	if(pr->prev==null)
					    {
    						Node *temp=pr->next;
    						temp->prev=null;
    						ht[i]=temp;
    						pr=temp;
					    }
					    else if(pr->next==null)
					    {
    						top[i]=pr->prev;
    						top[i]->next=null;
    						pr=top[i];
				        }
					    else
				    	{
    						Node *tempprev=pr->prev;
    						Node *tempnext=pr->next;
    						tempprev->next=tempnext;
    						tempnext->prev =tempprev;
    						pr=tempnext;
				    	}
					    flag++;
				    }
				    else
			        	pr=pr->next;
			    }
			    if(flag>0)
				    System.out.println("\n\n\t *** "+flag+" elements deleted.");
			}
			if(flag==0)
				System.out.println("\n\n\t *** The Element is not found.");
        }
        
};	
	
int main(){
    int ch ;
    Hashing h ;
    while(true){
		cout<<"********** Implementation of Hashing **********\n";
		cout<<"1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n";
		cout<<"Enter your Choice : ";
		cin>>ch;
        switch (ch)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.delete();
            break;
        case 3:
            h.display();
            break;
        case 4:
            h.search();
            break;
        case 5 :
            return 0;
        default:
            exit(0);
        }
    }	
	return 0;
}




