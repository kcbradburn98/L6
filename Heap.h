#pragma once
#include <cmath>




class MinHeap{
    public:
        MinHeap();
        virtual ~MinHeap(){}
        bool insert(int num);
        bool remove();
        virtual int PQLowest();
        int PQHighest();
        void levelOrder();
        int timeLowest();

        
        int getSize(){return m_size;}
        
        
    protected:
        int * m_arr = new int[15000];
        int m_size = 0;
        int m_arrayLength = 15000;

        //moved from public to private
        virtual int lchild(int index){return 3*index + 1;}
        virtual int mchild(int index){return (3*index + 2);}
        virtual int rchild(int index){return (3*index + 3);}
        virtual int parent(int child){return floor((child - 1)/3);}
        virtual void swap(int a, int b);
        virtual void upheap(int index);
        virtual void downheap(int index);
        //end move
};

class MaxHeap : public MinHeap {

    public:
        MaxHeap();
        ~MaxHeap(){}
        virtual void upheap(int index)override;
        virtual void downheap(int index)override;
        virtual int PQLowest()override;

};