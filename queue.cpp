#include "queue.hpp"
#include <iostream>
#include <cstring>
 
bool Queue::isFull() {
    // Queue is full if the number of elements is equal to the size of the ring
    return size == 6;
}
 
bool Queue::isEmpty() {
    // Queue is empty if there are 0 elements
    return size == 0;
}
 
int Queue::enqueue(Node* temp) {
    if (isFull()) {
        std::cout << "Queue is full. Unable to enqueue.\n";
        return -1;
    }
 
    if (isEmpty()) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    tail->next = head; // Circular link
    size++;
 
    return 0;
}
 
int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Unable to dequeue.\n";
        return -1;
    }
 
    Node* temp = head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        tail->next = head; // Update tail's next to maintain circular link
    }
    delete temp;
    size--;
 
    return 0;
}
 
void Queue::showQueue() {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }
 
    Node* temp = head;
    do {
        std::cout << "Destination: " << temp->dest << " Payload: " << temp->PL << std::endl;
        temp = temp->next;
    } while (temp != head); // Loop until the head is reached
}
 
bool Queue::isDestinationValid(int dest)
{
    return dest >= 1 && dest <= 99 && std::to_string(dest).find_first_not_of("0123456789") == std::string::npos;
}
