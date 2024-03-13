[2:43 AM] Jonathan Erb
/*
 
    Include file for queue.hpp
*/
 
#ifndef QUEUE_HPP
#define QUEUE_HPP
 
 
#include <iostream>
#include <string>
 
struct Node {
    int destination;
    char payload[6];
};
 
class Queue {
private:
    Node ring[6];
    int head;
    int tail;
 
public:
    Queue() {
        head = 0;
        tail = 0;
    }
 
    // case 1: enqueue
    void enqueue(int destination, const std::string& payload);
    // case 2: dequeue
    void dequeue();
    // case 3: show queue
    void showQueue();
    // input validator for destination
    bool isDestinationValid(int destination) {
 
        return destination >= 1 && destination <= 99 && std::to_string(destination).find_first_not_of("0123456789") == std::string::npos;
    }
 
private:
    bool isFull();
    bool isEmpty();
};
 
#endif