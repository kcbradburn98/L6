#include "Heap.h"
#include <iostream>


Heap::Heap(){
    for(int i = 0; i < m_arrayLength; i++){
        m_arr[i] = -999;
    }
}
bool Heap::insert(int num){
    if(m_size == 0){
        m_arr[0] = num;
        m_size++;
        std::cout << "triggered 0\n";
        return true;
    }
    else{
        for(int i = 0; i < m_size + 1; i++){
            if(m_arr[i] == -999){
                m_arr[i] = num;
                m_size++;
                std::cout << "triggered 1\n";
                upheap(i);
                return true;
            }
        }
    }
    return false;
}

void Heap::remove(int num){
    int temp = m_arr[m_size];
    for(int i = 0; i < m_size; i++){
        if(m_arr[i] == num){
            m_arr[m_size] = -999;
            m_size--;
            m_arr[i] = temp;
            upheap(i);
        }
    }
}

void Heap::PQHighest(){

}

void Heap::PQLowest(){

}

void Heap::levelOrder(){
    for(int i = 0; i < m_size; i++){
        if(m_arr[i] != -999){
            std::cout << m_arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void Heap::timeLowest(){

}


// Helper functions for Heap class
void Heap::upheap(int index){
    if(index == 0){
        return; 
    }
    else{
        int pIndex = parent(index);
        if(m_arr[index] < m_arr[pIndex] ){
            //child is less than parent, swap and upheap
            int temp = m_arr[pIndex];
            m_arr[pIndex] = m_arr[index];
            m_arr[index] = temp;
            upheap(pIndex);
        }  
    }   
}


