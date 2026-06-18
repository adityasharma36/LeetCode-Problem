class MyCircularQueue {
public:
    vector<int>v;
    int rear = 0;
    int front = 0;
    int n ;
    MyCircularQueue(int k) {
        v = vector<int>(k+1);
        n = k + 1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        rear = (rear+1) % n;
        v[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        front = (front+1) %n;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[(front+1) % n];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        if((rear+1) % n == front) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */