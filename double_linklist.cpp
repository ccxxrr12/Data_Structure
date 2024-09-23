/*
*******************************************
*
* 项目：双向链表/ Double Linked List
* 结构体--Node（拥有prev，next两个指针）
* 全局变量：
* head：指向头部
* tail：指向尾部
*
*******************************************
*
* CreateNode()：创建一个首位地址=0的节点
* InsertHead()：头部插入节点
* InsertTail()：尾部插入节点
*
*******************************************
*
* Delete()：删除节点（传入要删除的data）
* -ChangePtr()：将目标节点（要删的那个）的前后节点建立联结
*
*******************************************
*
* Print()：打印链表（正向）
* ReversePrint()：打印链表（反向）
*
*******************************************
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

Node *CreateNode(int n)
{
    Node *tmp = new Node();
    tmp->data = n;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

void InsertHead(int x)
{
    Node *temp = CreateNode(x);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertTail(int y)
{
    Node *temp = CreateNode(y);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void ChangePtr(Node *ptr)
{
    if (ptr->prev != NULL)
    {
        ptr->prev->next = ptr->next;
    }
    else
    {
        head = ptr->next;
    }

    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    else
    {
        tail = ptr->prev;
    }
}

void Delete(int x)
{
    Node *tmp = head;
    Node *tmp1 = tail;

    while (tmp != NULL && tmp1 != NULL)
    {
        if (tmp->data == x)
        {
            ChangePtr(tmp);
            delete (tmp); // 记得new用delete！！
            return;
        }
        else if (tmp1->data == x)
        {
            ChangePtr(tmp1);
            delete (tmp1);
            return;
        }
        tmp = tmp->next;
        tmp1 = tmp1->prev;
    }
}

void Print()
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

void ReversePrint()
{
    Node *q = tail;
    while (q != NULL)
    {
        cout << q->data;
        q = q->prev;
    }
    cout << endl;
}

int main()
{
    InsertHead(2);
    InsertTail(4);
    InsertHead(6);
    InsertTail(8);
    InsertTail(3);
    Print();
    ReversePrint();
    Delete(8);
    Print();
    ReversePrint();
}
