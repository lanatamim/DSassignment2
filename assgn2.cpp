/*
  Lana Tamim
  Assignment 2
  03/13/2024
  Purpose: Enqueue and dequeue with a circular queue
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "queue.hpp"
 
int main() {
    Queue queue;
    int choice;
    int destination;
    std::string payload;
 
    Node* temp;
    while (true) {
        std::cout << "Choose an operation:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Show the queue\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;
 
        switch (choice) {
            case 1:
                std::cout << "Enter the destination: ";
                while (!(std::cin >> destination) || !queue.isDestinationValid(destination)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid destination (a number between 1 and 99): ";
                }
                std::cout << "Enter the payload: ";
                std::cin >> payload;
                temp = new Node(destination, payload.c_str()); // Create a new Node instance
                queue.enqueue(temp); // Enqueue the new Node
                queue.showQueue();
                break;
            case 2:
                queue.dequeue();
                queue.showQueue();
                break;
            case 3:
                queue.showQueue();
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
    }
}
