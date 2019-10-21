#pragma once
#include <cmath>




class Heap{
    public:
        Heap();
        virtual bool insert(int num);
        virtual void remove(int num);
        virtual void PQLowest();
        virtual void PQHighest();
        virtual void levelOrder();
        virtual void timeLowest();

        virtual int lchild(int index){return 3*index;}
        virtual int mchild(int index){return (3*index + 1);}
        virtual int rchild(int index){return (3*index + 2);}
        virtual int parent(int child){return floor(child/3);}
        virtual void upheap(int index);
        
        
    private:
        int * m_arr = new int[10];
        int m_size = 0;
        int m_arrayLength = 10;
};