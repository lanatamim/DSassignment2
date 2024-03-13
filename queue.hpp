/*
 
    Include file for queue.hpp
*/
 
#ifndef QUEUE_HPP
#define QUEUE_HPP
 
#include <iostream>
#include <string>
#include <cstring>
 
struct Node {
    int dest;
    char PL[6];
    Node* next;
 
    // Constructor to initialize dest and PL
    Node(int d, const char* p) : dest(d), next(nullptr) {
        // Copy up to 5 characters from p into PL
        strncpy(PL, p, 5);
        // null termination
        PL[5] = '\0';
    }
};
 
 
class Queue {
private:
    Node* ring[6];
    // Pointer to the front (head) of the queue
    Node* head;
    // Pointer to the rear (tail) of the queue
    Node* tail;
    // Number of elements in the queue
    int size;
 
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {
        for (int i = 0; i < 6; ++i) {
            ring[i] = nullptr;
        }
    }
 
    // Other member functions
    bool isFull();
    bool isEmpty();
 
    int enqueue(Node* temp);
    int dequeue();
    void showQueue();
    bool isDestinationValid(int dest);
};
 
#endif
