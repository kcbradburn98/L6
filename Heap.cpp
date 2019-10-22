#include "Heap.h"
#include <iostream>
#include <tuple>


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
    for(int i = 0; i < m_size + 1; i++){
        if(m_arr[i] == -999){
            m_arr[i] = num;
            m_size++;
            upheap(i);
            return true;
        }
    }
    return false;
}

bool Heap::remove(){
    m_arr[0] = -999;
    m_size--;
    swap(0,m_size);
    downheap(0);
    return true;
}

int Heap::PQHighest(){
    int max = 0;
    for(int i = 0; i < m_size; i++){
        if(max < m_arr[i]){
            max = m_arr[i];
        }
    }
    return max;
}

int Heap::PQLowest(){
    return m_arr[0];
}

void Heap::levelOrder(){
    for(int i = 0; i < m_size; i++){
        if(true){
            std::cout << m_arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void Heap::heapify(int index){
    upheap(index);
    downheap(index);
    
    
    
    // bool a,b,c,d;
    // if(){
    //     return;
    // }
    // a = m_arr[index] <= m_arr[p];
    // b = m_arr[index] >= m_arr[l];
    // c = m_arr[index] >= m_arr[m];
    // d = m_arr[index] >= m_arr[r];
    // if(a && b && c && d){
    //     return; 
    // }
    // else{
    //     if(m_arr[index] < m_arr[p] ){
    //         swap(index, p);
    //         heapify(p);
    //     }
    //     else if(m_arr[index] > m_arr[l]){
    //         swap(index, l);
    //         heapify(l);
    //     }
    //     else if(m_arr[index] > m_arr[m]){
    //         swap(index, m);
    //         heapify(m);
    //     }
    //     else if(m_arr[index] > m_arr[r]){
    //         swap(index, r);
    //         heapify(r);
    //     }  
    // }   
}
void Heap::swap(int a, int b){
    int temp = m_arr[a];
    m_arr[a] = m_arr[b];
    m_arr[b] = temp;
}

void Heap::upheap(int index){
    int p = parent(index);
    if(index == p){
        return;
    }
    else if(m_arr[index] < m_arr[p]){
        swap(index, p);
        upheap(p);
    }
}
void Heap::downheap(int index){
    int child[3] = {lchild(index),mchild(index),rchild(index)};
    int minIndex = index;
    if(!(child[0] >= m_size)){
        //left child exists
        if(m_arr[minIndex] > m_arr[child[0]]){
            minIndex = child[0];
        }
    }
    if(!(child[1] >= m_size)){
        //middle child exists
        if(m_arr[minIndex] > m_arr[child[1]]){
            minIndex = child[1];
        }
    }
    if(!(child[2] >= m_size)){
        //right child exists
        if(m_arr[minIndex] > m_arr[child[2]]){
            minIndex = child[2];
        }
    }
    if(!(minIndex == index)){
        swap(index,minIndex);
        downheap(minIndex);
    }
}