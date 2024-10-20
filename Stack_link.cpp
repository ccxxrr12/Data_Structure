#include <bits/stdc++.h>
using namespace std;

// 定义链表节点
class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

// 定义链栈
class LinkedStack
{
private:
    Node *top; // 指向栈顶元素的指针

public:
    LinkedStack() : top(nullptr) {}

    // 入栈操作
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // 出栈操作
    int pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        Node *temp = top;
        top = top->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    // 查看栈顶元素
    int peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }

    // 判断栈是否为空
    bool isEmpty() const
    {
        return top == nullptr;
    }

    // 析构函数，释放所有节点
    ~LinkedStack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedStack stack;

    // 入栈
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // 出栈并打印栈顶元素
    cout << "Stack top: " << stack.peek() << endl;

    // 出栈
    cout << "Pop: " << stack.pop() << endl;
    cout << "Stack top: " << stack.peek() << endl;

    return 0;
}