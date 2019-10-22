#include "Heap.h"
#include <iostream>
#include <tuple>
#include <fstream>
#include "Timer.h"

MinHeap::MinHeap(){
    for(int i = 0; i < m_arrayLength; i++){
        m_arr[i] = -999;
    }
}
bool MinHeap::insert(int num){
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

bool MinHeap::remove(){
    m_arr[0] = -999;
    m_size--;
    swap(0,m_size);
    downheap(0);
    return true;
}

int MinHeap::PQHighest(){
    return m_arr[0];
}

int MinHeap::PQLowest(){
    int lowest = -1000000;
    for(int i = 0; i < m_size; i++){
        if(lowest < m_arr[i]){
            lowest = m_arr[i];
        }
    }
    return lowest;
}

void MinHeap::levelOrder(){
    int lineEndPoint = 0;
    for(int i = 0; i < m_size; i++){
        std::cout << m_arr[i] << " ";
        if(lineEndPoint == i){
            std::cout << std::endl;
            if(!(rchild(lineEndPoint) > m_size)){
                lineEndPoint = rchild(lineEndPoint);
            }
            else if(!(mchild(lineEndPoint) > m_size)){
                lineEndPoint = mchild(lineEndPoint);
            }
            else if(!(lchild(lineEndPoint) > m_size)){
                lineEndPoint = lchild(lineEndPoint);
            }
        }
    }
}

void MinHeap::swap(int a, int b){
    int temp = m_arr[a];
    m_arr[a] = m_arr[b];
    m_arr[b] = temp;
}

void MinHeap::upheap(int index){
    int p = parent(index);
    if(index == p){
        return;
    }
    else if(m_arr[index] < m_arr[p]){
        swap(index, p);
        upheap(p);
    }
}
void MinHeap::downheap(int index){
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

int MinHeap::timeLowest(){
    Timer myTimer;
    return PQLowest();
}




//MaxHeap overriden functions
MaxHeap::MaxHeap(){
    for(int i = 0; i < m_size; i++){
        m_arr[i] = -999;
    }
}

void MaxHeap::upheap(int index){
    int p = parent(index);
    if(index == p){
        return;
    }
    else if(m_arr[index] > m_arr[p]){
        swap(index, p);
        upheap(p);
    }
}

void MaxHeap::downheap(int index){
    int child[3] = {lchild(index),mchild(index),rchild(index)};
    int minIndex = index;
    if(!(child[0] >= m_size)){
        //left child exists
        if(m_arr[minIndex] < m_arr[child[0]]){
            minIndex = child[0];
        }
    }
    if(!(child[1] >= m_size)){
        //middle child exists
        if(m_arr[minIndex] < m_arr[child[1]]){
            minIndex = child[1];
        }
    }
    if(!(child[2] >= m_size)){
        //right child exists
        if(m_arr[minIndex] < m_arr[child[2]]){
            minIndex = child[2];
        }
    }
    if(!(minIndex == index)){
        swap(index,minIndex);
        downheap(minIndex);
    }
}

int MaxHeap::PQLowest(){
    int lowest = 100000;
    for(int i = 0; i < m_size; i++){
        if(lowest > m_arr[i]){
            lowest = m_arr[i];
        }
    }
    return lowest;
}
