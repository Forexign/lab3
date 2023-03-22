#include <iostream>
using namespace std;
//Node class
class Node {
public:
    int data;
    Node *next;
    Node(int Data) {
        data = Data;
        next = NULL;
    }
};

//Queue class
class Queue {
private:
    Node *front;
    Node *back;
    int size;
public:
    Queue() {
        front = NULL;
        back = NULL;
        size = 0;
    }

    //Add a new element to the queue
    void enqueue(int Data) {
        Node *newNode = new Node(Data);

        if (back == NULL) {
            front = newNode;
            back = newNode;
        }
        else {
            back -> next = newNode;
            back = newNode;
        }

        size++;
    }

    //Remove the first element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        Node *tmp = front;
        front = front -> next;
        if (front == NULL) {
            back = NULL;
        }
        delete tmp;
        size--;
    }

    //Gets the value of the top element.
    int top() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return -1;
        }
        return front -> data;
    }

    //Check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    //Returns the size of the queue
    int Size() {
        return size;
    }

    //Prints the queue -- This function is not in the task, i just created it in order to see if my code works properly.
    void print() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        Node *tempElement = front;
        while (tempElement != NULL) {
            cout << tempElement -> data << " - ";
            tempElement = tempElement -> next;
        }
        cout << endl;
    }

};

int main() {
    Queue queue;

    //Add elements to the queue
    queue.enqueue(9);
    queue.enqueue(2);
    queue.enqueue(6);
    queue.enqueue(28);
    queue.enqueue(11);
    queue.enqueue(4);

    //Print the queue
    cout << "The elements of the queue : ";
    queue.print();

    //Print size of queue
    cout << "Size of the queue is  " << queue.Size() << endl;

    //Print top element of the queue
    cout << "Top element is " << queue.top() << endl;

    cout<<"--------------------------------------------------------" << endl;

    //Remove the first element from the queue
    queue.dequeue();

    //Print the queue
    cout << "The elements of the queue : ";
    queue.print();

    //Print size of queue
    cout << "Size of the queue is " << queue.Size() << endl;

    //Print top element of the queue
    cout << "Top element is " << queue.top() << endl;

    cout<<"--------------------------------------------------------" << endl;
    return 0;
}