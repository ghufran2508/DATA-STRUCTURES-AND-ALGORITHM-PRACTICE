#include<iostream>
#include<string>

using namespace std;

class node
{
    int x;
public:
    node *next;
    node(){next=NULL;}
    node(int z){x=z;next=NULL;}
    int getx(){return x;}
};
class SLList
{
    node *first;

public:
    SLList(){first=NULL;}
    void append(int z){
        if (first == NULL)
            first=new node(z);
        else
        {
            node *temp;
            temp=first;
            while (temp->next!=NULL)
                temp=temp->next;

            temp->next = new node(z);
        }
    }
    void insert_Desc(int val)  //sorted insertion when data is sorted in descending order
    {
        node *temp=new node(val);
        if (first==NULL){
            first=temp;
        }
        else{
            node *curr, *prev;
            curr=prev=first;
            if (val > first->getx()){
                temp->next=first;
                first=temp;
            }
            else{
                while(curr!=NULL && curr->getx()>=val){
                    prev=curr;
                    curr=curr->next;
                }
                temp->next=curr;
                prev->next=temp;

            }
        }
    }
    void deleteFirst(int val)  // delete first occurrence of search value
    {
        node *temp=first;
        if (first->getx() == val){
            first=first->next;
            delete temp;
        }
        else{
            node *prev, *curr;
            prev=NULL;
            curr=first;

            while (curr!=NULL && curr->getx()!=val){
                prev=curr;
                curr=curr->next;
            }
            if (curr==NULL) //not found
                cout<<"Not found";
            else{
                prev->next = curr->next;
                delete curr;
            }
        }

    }
    void deleteLast(int val)  // delete last occurrence of search value
    {
        node *curr, *prev, *fdPrev, *fd;

        prev = NULL;
        curr = first;

        bool flag=false;
        while(curr!=NULL){
            if (curr->getx() == val){
                flag = true;
                fdPrev = prev;
                fd = curr;
            }
            prev = curr;
            curr=curr->next;
        }

        if (!flag)
            cout<<"Not found\n";
        else{
            fdPrev->next = fd->next;
            delete fd;
        }
    }

    void deleteAll(int val){ // delete all occurrences of val
        node *prev, *curr;
        prev=NULL;
        curr=first;

        while (first->getx() == val){
            first=first->next;
            delete curr;
            curr=first;
        }

        node *temp;
        while (curr!=NULL){
            if (curr->getx() == val){
                temp=curr;
                prev->next=curr->next;
                curr=curr->next;
                delete temp;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }

    }
    void traverse()
    {
        node *temp;
        temp=first;
        while (temp!=NULL){
            cout << temp->getx()<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    SLList l1;

    l1.append(500);
    l1.append(200);
    l1.append(70);
    l1.traverse();
    cout<<"==============="<<endl;
//BLOCK A Start

    cout<<"==============="<<endl;
    l1.insert_Desc(250);  //in-between
    l1.traverse();
    cout<<"==============="<<endl;
    l1.insert_Desc(550);  // start
    l1.traverse();
    cout<<"==============="<<endl;
    l1.insert_Desc(30);   // end
    l1.insert_Desc(140);   // in-between
    l1.insert_Desc(70);   // in-between
    l1.traverse();
    cout<<"==============="<<endl;

    //BLOCK A END


//BLOCK B Start

/*
    l1.append(200);
    l1.append(30);
    l1.append(200);
    l1.append(400);
    l1.append(600);
    l1.append(200);
    l1.traverse();
    cout<<"==============="<<endl;

    l1.deleteLast(200);
    l1.traverse();
    cout<<"==============="<<endl;

    l1.append(340);
    l1.traverse();
    cout<<"==============="<<endl;
*/

/*//Block C start
    //l1.traverse();

    l1.append(200);
    l1.append(89);
    l1.append(76);
    l1.append(89);
    l1.append(200);
    l1.append(89);

    l1.traverse();
    cout<<"==============="<<endl;

    l1.deleteAll(200);
    l1.traverse();
    cout<<"==============="<<endl;

    l1.deleteAll(89);
    l1.traverse();
    cout<<"==============="<<endl;
//Block C End*/
}
