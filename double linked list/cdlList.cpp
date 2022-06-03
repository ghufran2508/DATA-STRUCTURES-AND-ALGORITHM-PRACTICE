#include <iostream>
#include "node_H.h"
#include "cdlList.h"
using namespace std;

    cdlList::cdlList(){
        first = last = NULL;
    }
    void cdlList::append(int x){
        node *t;
        t= new node(x);
        if (first==NULL)
        {
            first = last = t;
            first->prev = t;
            last->next = t;
        }
        else
        {
            t->next = first;
            t->prev = last;
            last->next = t;
            last = t;
            first->prev = last;
        }
    }
    void cdlList::show()
    {
        node *t;

        if (first!=NULL)
        {
            if (first==last)
                cout<<first->getData();
            else
            {
                t=first;
                do
                {
                    cout << t->getData()<<" - ";
                    t=t->next;
                }while(t!=first);
                cout<<endl;
            }
        }
    }
    node *cdlList::searchNode(int x)
    {
        bool sFlag=false;
        node *t;
        t=first;
        do
        {
            if (t->getData()==x)
                sFlag=true;
            else
                t=t->next;
        }while(!sFlag && t!=first);
        if (sFlag)
            return t;
        else
            return NULL;
    }
    bool cdlList::insertBefore(int d, int x)
    {
        node *sn,*t;
        t=new node(x);

        sn = searchNode(d);
        if (sn!=NULL)
        {
            if (sn==first)
            {
                t->next = first;
                t->prev = last;
                first->prev = t;
                last->next=t;
                first=t;
            }
            else
            {
                t->next = sn;
                t->prev = sn->prev;
                sn->prev->next = t;
                sn->prev = t;
            }
        }
    }
