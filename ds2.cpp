#include <iostream>
#include <string>
#include <cstring>

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

    void enqueue(int destination, const std::string& payload) {
        if (isFull()) {
            std::cout << "Queue is full. Unable to enqueue.\n";
            return;
        }

        if (destination < 1 || destination > 99) {
        std::cout << "Invalid destination. Destination must be between 1 and 99.\n";
        return;
      }

        std::string truncatedPayload = payload.substr(0, 6);

        ring[tail].destination = destination;
        payload.copy(ring[tail].payload, 6);
        tail = (tail + 1) % 6;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Unable to dequeue.\n";
            return;
        }

        head = (head + 1) % 6;
    }

    void showQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::cout << "Queue:\n";
        int current = head;
        while (current != tail) {
            std::cout << "Destination: " << ring[current].destination << ", Payload: " << ring[current].payload << std::endl;
            current = (current + 1) % 6;
        }
    }

private:
    bool isFull() {
        return (tail + 1) % 6 == head;
    }

    bool isEmpty() {
        return head == tail;
    }
};
 
int main() {
    Queue queue;
    int choice;
    int destination;
    std::string payload;

    while (true) {
        std::cout << "Choose an operation:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Show the queue\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the destination: ";
                std::cin >> destination;
                std::cout << "Enter the payload: ";
                std::cin.ignore(); // Clear the newline character left in the input buffer
                std::getline(std::cin, payload);
                queue.enqueue(destination, payload);
                queue.showQueue();
                break;
            case 2:
                queue.dequeue();
                queue.showQueue();
                break;
            case 3:
                queue.showQueue();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
