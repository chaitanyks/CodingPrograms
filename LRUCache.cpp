#include<bits/stdc++.h>
using namespace std;
class node {
    public:
        int key;
        int value;
        node * next;
        node * prev;
        node(int key,int value)
        {
            this->key = key;
            this->value = value;
            this->next=NULL;
            this->prev=NULL;
        }
};

unordered_map<int,node *> cache;
node* head = new node(-1,-1);
node* trail = new node(-1,-1);
int capacity,cnt=0;

int addnodeathead(node *value)
{
    value->next = head->next;
    value->prev = head;
    head->next->prev=value;
    head->next=value;
}

void removenode(node * value)
{
    value->prev->next=value->next;
    value->next->prev=value->prev;
}
int movetohead(node *value)
{
    removenode(value);
    addnodeathead(value);
}
void deletefromtrail()
{
    removenode(trail->prev);
}

int get(int key)
{
    if(cache.count(key) == 0 )
    {
        cout<<"Invalid key"<<endl;
        return -1;
    }
    else {
        node *temp = cache[key];
        movetohead(temp);
        return temp->value;
    }
}


int put(int key,int val)
{
    if(cache.count(key) == 0)
    {
        node * temp = new node(key,val);
        cache[key]=temp;
        addnodeathead(temp);
        cnt++;
        if(cnt>capacity)
        {
            cnt--;
            deletefromtrail();
        }
    }
    else
    {
        node * value = cache[key];
        value->value = val;
        movetohead(value);
    }
    return key;
}




int main()
{
    head->next=trail;
    trail->prev=head;
    cout<<"Enter the capacity : "<<endl;
    cin>>capacity;
    int q;
    cin>>q;
    while(q--)
    {
        char type;
        int key,value;
        cin>>type;
        if(type=='p')
        {
            cin>>key>>value;
            cout<<"Inserted Successfully "<<put(key,value)<<endl;
        }
        else
        {
            cin>>key;
            cout<<"value for key is "<<get(key)<<endl;
        }
        node * temp = head->next;
        while(temp!=trail)
        {
            cout<<temp->key<<" "<<temp->value<<" ";
            temp=temp->next;
        }
    }
}