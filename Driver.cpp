#include "Driver.h"
#include <iostream>
#include <fstream>
#include "Timer.h"


Driver::Driver(){
    m_heap = new Heap;
    std::ifstream infile;
    infile.open("data.txt");
    int n;
    while(!infile.eof()){
        infile >> n;
        if(m_heap->insert(n)){
        std::cout << "INSERT SUCCESFUL\nCURRENTHEAP-> ";
        m_heap->levelOrder();
        }
        else{
            std::cout << "***ERROR*** INSERT FAILED\n";
        } 
    }
    infile.close();

}


void Driver::run(){
    bool run = true;
    int choice;
    while(run){
        menu();
        std::cin >> choice;
        switch (choice) {
        case 1: insert();
            break;
        case 2: remove();
            break;
        case 3: PQLowest();
            break;
        case 4: PQHighest();
            break;
        case 5: levelOrder();
            break;
        case 6: timeLowest();
            break;
        case 7: run = false;
            break;
        }
    }
}

void Driver::insert(){
    std::cout << "Please enter an integer to insert: ";
    int n;
    std::cin >> n;
    if(m_heap->insert(n)){
        std::cout << "INSERT SUCCESFUL\nCURRENTHEAP-> ";
        m_heap->levelOrder();
    }
    else{
        std::cout << "***ERROR*** INSERT FAILED\n";
    }   
}

void Driver::remove(){
    if(m_heap->remove()){
        std::cout << "REMOVE SUCCESFUL::CURRENTHEAP-> ";
        m_heap->levelOrder();
    }
    else{
        std::cout << "***ERROR*** REMOVE FAILED\n";
    } 
}

void Driver::PQLowest(){
    if(m_heap->getSize() != 0){
        std::cout << "Lowest -> " << m_heap->PQLowest() << std::endl;
        return;
    }
    std::cout << "Heap is empty\n";
}

void Driver::PQHighest(){
    if(m_heap->getSize() != 0){
        std::cout << "Highest -> " << m_heap->PQHighest() << std::endl;
        return;
    }
    std::cout << "Heap is empty\n";
}

void Driver::levelOrder(){
    m_heap->levelOrder();
}

void Driver::timeLowest(){
    Timer myTimer;
    PQLowest();
}

void Driver::menu(){
    std::cout << "**********************************\n" << "1) insert\n2) remove\n3) PQLowest\n4) PQHighest\n5) Level Order\n6) Time Lowest PQ\n7) Exit\n**********************************\nSelection: ";
}

