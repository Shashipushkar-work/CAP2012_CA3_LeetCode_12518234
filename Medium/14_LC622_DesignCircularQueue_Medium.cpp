
class MyCircularQueue {
private:
    vector<int> arr;
    int frontIndex;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        arr.resize(k);
        frontIndex = 0;
        count = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        int rearIndex = (frontIndex + count) % capacity;
        arr[rearIndex] = value;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        frontIndex = (frontIndex + 1) % capacity;
        count--;

        return true;
    }

    int Front() {
        if (isEmpty()) return -1;

        return arr[frontIndex];
    }

    int Rear() {
        if (isEmpty()) return -1;

        int rearIndex = (frontIndex + count - 1) % capacity;
        return arr[rearIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
