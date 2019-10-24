#pragma once
#include "Heap.h"




class Driver{
    public:
        Driver();
        ~Driver();
        void run();
        void insert();
        void remove();
        void PQLowest();
        void PQHighest();
        void levelOrder();
        void timeLowest();
        void menu();
        void print();
    private:
        MinHeap * minheap;
        MaxHeap * maxheap;

};