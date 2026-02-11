#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node* next; 
}*head,*tail,*temp,*newnode;

void create(int inp){
    newnode=new(node);
    newnode->data=inp;
    newnode->next=NULL;
}

void insertbeg(int inp){
    create(inp);
    if(head==NULL){
        cout<<"Added element: "<<inp<<endl;
        head=newnode;
        tail=newnode;
        tail->next=head;
    }else{
        cout<<"Added element: "<<inp<<endl;
        newnode->next=head;
        head=newnode;
        tail->next=head;
    }
}

void insertend(int inp){
    create(inp);
    if(head==NULL){
        cout<<"Added element: "<<inp<<endl;
        head=newnode;
        tail=newnode;
        tail->next=head;
    }else{
        cout<<"Added element: "<<inp<<endl;
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
}

void delend(){
    if(head==NULL){
        cout<<"Queue is empty! "<<endl;
    }else if(head==tail){
        cout<<"Deleted element: "<<head->data<<endl;
        delete head;
        head=tail=NULL;
    }else{
        cout<<"Deleted element: "<<tail->data<<endl;
        for(temp=head;temp->next!=tail;temp=temp->next){
        }delete tail;
        tail=temp;
        tail->next=head;
    }
}

void delbeg(){
    if(head==NULL){
        cout<<"Queue is empty! "<<endl;
    }else if(head==tail){
        cout<<"Deleted element: "<<head->data<<endl;
        delete head;
        head=tail=NULL;
    }else{
        temp=head;
        cout<<"Deleted element: "<<head->data<<endl;
        head=head->next;
        delete temp;
        tail->next=head;
    }
}

void display(){
    if(head==NULL){
        cout<<"Queue is empty: "<<endl;
    }else{
        for(temp=head;temp->next!=head;temp=temp->next){
            cout<<"Element: "<<temp->data<<endl;
        }cout<<"Element: "<<temp->data<<endl;
    }
}

int main(){
    insertend(23);
    display();
    insertbeg(45);
    display();
    insertbeg(467);
    display();
    insertend(26);
    display();
    insertbeg(766);
    display();
    delend();
    display();
    delbeg();
    display();
    delbeg();
    display();
    delend();
    display();
    insertend(877);
    display();
    delbeg();
    display();
    delend();
    display();
}