class MyCircularQueue
{
public:
    vector<int> arr;
    int start = 0;
    int tail = 0;
    int cot = 0;
    int size;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        size = k;
        arr.resize(k);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        arr[tail] = value;
        tail = (tail + 1) % size;
        cot++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (isEmpty())
            return false;
        cot--;
        start = (start + 1) % size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[start];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (isEmpty())
            return -1;
        return arr[(tail + size - 1) % size];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        if (cot == 0)
            return true;
        return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        if (cot == size)
            return true;
        return false;
    }
};