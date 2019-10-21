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
        return true;
    }
    else{
        for(int i = 0; i < m_size + 1; i++){
            if(m_arr[i] == -999){
                m_arr[i] = num;
                m_size++;
                heapify(i);
                return true;
            }
        }
    }
    return false;
}

bool Heap::remove(int num){
    int temp = m_arr[m_size];
    for(int i = 0; i < m_size; i++){
        if(m_arr[i] == num){
            m_arr[m_size] = -999;
            m_size--;
            m_arr[i] = temp;
            heapify(i);
            return true;
        }
    }
    return false;
}

int Heap::PQHighest(){
    int max = 0;
    int i = 0;
    while(lchild(i) < m_arrayLength){
        //finds the leftmost leaf and makes i the index of the leftmost child
        i = lchild(i);
    }
    for(int j = i; j < m_arrayLength;j++){
        if(max < m_arr[j]){
            max = m_arr[j];
        }
    }
    return max;
}

int Heap::PQLowest(){
    return m_arr[0];
}

void Heap::levelOrder(){
    for(int i = 0; i < m_size; i++){
        if(m_arr[i] != -999){
            std::cout << m_arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

// Helper functions for Heap class
void Heap::heapify(int index){
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
            heapify(pIndex);
        }  
    }   
}