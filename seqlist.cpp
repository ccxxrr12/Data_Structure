#pragma once // 仅编译一次
#include <bits/stdc++.h>
using namespace std;
#define initsize 5
#define extsize 3

struct seqlist
{
    int *data;
    size_t maxsize;
    size_t length;
};



void clearlist(seqlist &l)
{
    l.length = 0;
    memset(l.data, 0, sizeof(int) * l.maxsize);
}

void initlist(seqlist &l)
{
    l.data = new int[initsize];
    l.length = 0;
    l.maxsize = initsize;
    clearlist(l);
}

void destroylist(seqlist &l)
{
    l.length = 0;
    l.maxsize = 0;
    delete[] l.data;
    l.data = nullptr;
}

bool extlist(seqlist &l)
{
    int *newdata = new int[l.maxsize + extsize];
    if (newdata == nullptr)
        return false;

    memmove(newdata, l.data, sizeof(int) * l.maxsize);

    delete[] l.data;
    l.data = newdata;
    l.maxsize += extsize;

    return true;
}

bool insertlist(seqlist &l, size_t pos, const int &ee)
{
    if (l.length == l.maxsize)
    {
        cout << "exting" << endl;
        if (extlist(l) == false)
        {
            return false;
        }
    }

    if ((pos < 1) || (pos > l.length + 1))
    {
        cout << "ill" << endl;
        return false;
    }

    memmove(l.data + pos, l.data + pos - 1, sizeof(int) * (l.length - pos + 1));

    l.data[pos - 1] = ee;
    l.length++;
    return true;
}

int length(seqlist &l)
{
    return l.length;
}

bool getelem(seqlist &l, size_t pos, int &ee)
{
    if ((pos < 1) || (pos > l.length + 1))
    {
        cout << "ill" << endl;
        return false;
    }

    ee = l.data[pos - 1];
    return true;
}

size_t findelem(seqlist &l, const int &ee)
{
    for (int i = 0; i < l.length; i++)
    {
        if (ee == l.data[i])
            return i + 1;
    }
    return false;
}

bool deleteelem(seqlist &l, size_t pos)
{
    if (l.length == 0)
        return false;
    if ((pos < 1) || (pos > l.length))
    {
        cout << "ill" << endl;
        return false;
    }

    memmove(l.data + pos - 1, l.data + pos, sizeof(int) * (l.length - pos));
    l.length--;
    return true;

}

