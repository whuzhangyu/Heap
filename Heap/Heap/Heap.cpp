// Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void SiftDown(vector<int>& data, int istart, int iend);
void SiftUp(vector<int>& heap, int index);
void Heapify(vector<int>& data);
void PopMin(vector<int>& heap);
void Insert(vector<int>& heap, int key);

// this is OSU branch

int main()
{
    vector<int>   data(10);
    data = { 1,10,4,7,2,6,8,3,9,5 };

    Heapify(data);
    PopMin(data);
    Insert(data, 1);


    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }

    return 0;
}

// Build a min-heap from an input integer array
void Heapify(vector<int>& data)
{
    int count = data.size();
    // last index in the array, zero-based index
    int iend = count - 1;
    // istart is the index of the last parent node
    int istart = (iend - 1) / 2;

    while (istart >= 0)
    {
        // sift down the istart-th node to the proper place
        // to make the istart-th node rooted tree in heap order
        SiftDown(data, istart, iend);
        // go to the next parent node
        istart--;
    }
}

// repair the heap rooted sift-down
void SiftDown(vector<int>& data, int istart, int iend)
{
    int iroot = istart;
    // loop while the root has at least one child
    while ((2 * iroot + 1) <= iend)
    {
        // 2*iroot+1 points to the left child
        int ichild = 2 * iroot + 1;
        // choose the smaller child
        if (ichild + 1 <= iend && data[ichild] > data[ichild + 1])
        {
            // if right child is bigger, then point to it instead
            ichild = ichild + 1;
        }
        // swap the child with root if child is smaller
        if (data[iroot] > data[ichild])
        {
            int tmp;
            tmp = data[iroot];
            data[iroot] = data[ichild];
            data[ichild] = tmp;

            // return the swapped root to test again
            iroot = ichild;
        }
        else
            return;
    }
}


// repair the heap rooted sift-up
void SiftUp(vector<int>& heap, int index)
{
    if (index == 0) return;
    int iparent = (index - 1) / 2;
    if (heap[iparent] > heap[index])
    {
        int tmp = heap[index];
        heap[index] = heap[iparent];
        heap[iparent] = tmp;
        SiftUp(heap, iparent);
    }
}


// Pop the minimum element of a min-heap and then reheapify
void PopMin(vector<int>& heap)
{
    int count = heap.size();
    if (count == 0) return;
    // For a min-heap, the minimum element is in the first node
    // copy the last node to the root, then delete the last node
    heap[0] = heap[count - 1];
    heap.erase(heap.end() - 1);

    count--;
    SiftDown(heap, 0, count - 1);
}


// Insert an element into the min-heap
void Insert(vector<int>& heap, int key)
{
    // Add the element to the last position of the heap
    heap.insert(heap.end(), key);
    int count = heap.size();
    // sift up to rebuild the heap
    SiftUp(heap, count - 1);
}

