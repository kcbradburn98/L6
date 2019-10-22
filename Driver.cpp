#include "Driver.h"
#include <iostream>
#include <fstream>
#include "Timer.h"


Driver::Driver(){
    minheap = new MinHeap;
    maxheap = new MaxHeap;
    std::ifstream infile;
    infile.open("data.txt");
    int n;
    while(!infile.eof()){
        infile >> n;
        minheap->insert(n);
        maxheap->insert(n);
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
    std::cout << "**********MINHEAP**********\n";
    if(minheap->insert(n)){
        std::cout << "          INSERT SUCCESFUL          \n";
    }
    else{
        std::cout << "          INSERT FAILED          \n";
    }
    std::cout << "**********MAXHEAP**********\n"; 
    if(maxheap->insert(n)){
        std::cout << "          INSERT SUCCESFUL          \n";
    }
    else{
        std::cout << "          INSERT FAILED          \n";
    }  
}

void Driver::remove(){
    std::cout << "**********MINHEAP**********\n";
    if(minheap->remove()){
        std::cout << "          REMOVE SUCCESFUL          \n";
    }
    else{
        std::cout <<  "          REMOVE FAILED          \n";
    }
    std::cout << "**********MAXHEAP**********\n"; 
    if(maxheap->remove()){
        std::cout << "          REMOVE SUCCESFUL          \n";
    }
    else{
        std::cout <<  "          REMOVE FAILED          \n";
    }
}

void Driver::PQLowest(){
    std::cout << "**********MINHEAP**********\n";
    if(minheap->getSize() != 0){
        std::cout << "Lowest -> " << minheap->PQLowest() << std::endl;
    }
    std::cout << "**********MAXHEAP**********\n";
    if(maxheap->getSize() != 0){
        std::cout << "Lowest -> " << maxheap->PQLowest() << std::endl;
    }
}

void Driver::PQHighest(){
    std::cout << "**********MINHEAP**********\n";
    if(minheap->getSize() != 0){
        std::cout << "Highest -> " << minheap->PQHighest() << std::endl;
    }
    std::cout << "**********MAXHEAP**********\n";
    if(minheap->getSize() != 0){
        std::cout << "Highest -> " << maxheap->PQHighest() << std::endl;
    }
}

void Driver::levelOrder(){
    std::cout << "**********MINHEAP**********\n";
    minheap->levelOrder();
    std::cout << "***************************\n";
    std::cout << "**********MAXHEAP**********\n";
    maxheap->levelOrder();
    std::cout << "***************************\n";
}

void Driver::timeLowest(){
    std::cout << "**********MINHEAP**********\n";
    if(minheap->getSize() != 0){
        Timer myTimer;
        std::cout << minheap->PQLowest() << std::endl;
    }
    std::cout << "**********MAXHEAP**********\n";
    if(maxheap->getSize() != 0){
        Timer myTimer2;
        std::cout << maxheap->PQLowest() << std::endl;
    }
}

void Driver::menu(){
    std::cout << "**********************************\n" << "1) insert\n2) remove\n3) PQLowest\n4) PQHighest\n5) Level Order\n6) Time Lowest PQ\n7) Exit\n**********************************\nSelection: ";
}

