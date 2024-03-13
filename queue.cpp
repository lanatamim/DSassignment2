/*

    Implement the following methods for the Queue class:
*/

#include "queue.hpp"
#include <iostream>
#include <cstring>


bool Queue::isFull() {
    return (tail + 1) % 6 == head;
}

bool Queue::isEmpty() {
    return head == tail;
}

void Queue::enqueue(int destination, const std::string& payload) {
    if (isFull()) {
        std::cout << "Queue is full. Unable to enqueue.\n";
        return;
    }

    ring[tail].destination = destination;
    std::strncpy(ring[tail].payload, payload.c_str(), 6);
    ring[tail].payload[5] = '\0'; // Ensure null-termination
    tail = (tail + 1) % 6;
}


void Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Unable to dequeue.\n";
        return;
    }

    head = (head + 1) % 6;
}

void Queue::showQueue() {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    int i = head;
    while (i != tail) {
        std::cout << "Destination: " << ring[i].destination << " Payload: " << ring[i].payload << std::endl;
        i = (i + 1) % 6;
    }
}