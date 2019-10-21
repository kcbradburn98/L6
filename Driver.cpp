#include "Driver.h"
#include <iostream>

Driver::Driver(){
    m_heap = new Heap;
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
        std::cout << "INSERT SUCCESFUL\nCURRENTHEAP->[";
        m_heap->levelOrder();
        std::cout << "]\n";
    }   
}

void Driver::remove(){

}

void Driver::PQLowest(){

}

void Driver::PQHighest(){

}

void Driver::levelOrder(){
    m_heap->levelOrder();
}

void Driver::timeLowest(){

}

void Driver::menu(){
    std::cout << "**********************************\n" << "1) insert\n2) remove\n3) PQLowest\n4) PQHighest\n5) Level Order\n6) Time Lowest PQ\n7) Exit\n**********************************\nSelection: ";
}

