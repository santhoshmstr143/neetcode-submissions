class MyCircularQueue {
public:
    vector<int> a;
    int front,rear,size,k;
    MyCircularQueue(int k) {
        this->k = k;
        a.resize(k);
        front = -1;
        rear = -1;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear+1)%k;
        }
        a[rear]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front+1)%k;
        }
        size--;
        return true;
        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return a[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return a[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==k;
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