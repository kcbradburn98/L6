#pragma once




class Heap{
    public:
        virtual void insert(int num);
        virtual void remove(int num);
        virtual void PQLowest();
        virtual void PQHighest();
        virtual void levelOrder();
        virtual void timeLowest();
        
        
    private:
        int * m_arr;
        int m_size = 0;
};