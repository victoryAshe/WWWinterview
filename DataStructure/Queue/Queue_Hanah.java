package me.study.wwwinterview;

import java.nio.BufferOverflowException;
import java.nio.BufferUnderflowException;

public class Queue {
    int[] queue;
    int front;
    int rear;
    int size;

    public Queue(int size) {
        this.queue = new int[size];
        this.size = size;
        this.front = 0;
        this.rear = 0;
    }

    public void add(int element) {
        if (rear == size) throw new BufferOverflowException();
        this.queue[rear] = element;
        rear++;
    }

    public int popleft() throws Exception {
        if (rear==0) throw new BufferUnderflowException();
        int val = queue[0];
        for (int i= 0; i<this.size-2; i++) {
            queue[i] = queue[i+1];
        }
        rear--;
        return val;
    }
}
