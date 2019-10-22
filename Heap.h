#pragma once
#include <cmath>




class Heap{
    public:
        Heap();
        virtual bool insert(int num);
        virtual bool remove();
        virtual int PQLowest();
        virtual int PQHighest();
        virtual void levelOrder();

        
        virtual int getSize(){return m_size;}
        
        
    private:
        int * m_arr = new int[10];
        int m_size = 0;
        int m_arrayLength = 10;

        //moved from public to private
        virtual int lchild(int index){return 3*index + 1;}
        virtual int mchild(int index){return (3*index + 2);}
        virtual int rchild(int index){return (3*index + 3);}
        virtual int parent(int child){return floor((child - 1)/3);}
        virtual void heapify(int index);
        virtual void swap(int a, int b);
        virtual void upheap(int index);
        virtual void downheap(int index);
        //end move
};