package me.study.wwwinterview;

public class LinkedList<E> {

    private Node<E> head;
    private int listSize;
    private Node<E> tail;

    class Node<E> {
        E data;
        Node<E> next;
        Node<E> prev; // 이중 연결 리스트 구현에서 활용 가능

        public Node(E data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.listSize = 0;
    }

    public Node<E> getHead() {
        return this.head;
    }

    public int getSize() {
        return this.listSize;
    }

    /* 반환값은 학습을 위해 임의로 한 번 지정해보았다 */
    public LinkedList<E> addLast(E data) {
        Node<E> newNode = new Node<>(data);
        if (this.head!=null) {
            Node<E> lastNode = this.getLastNode(this.head);
            // last null인지 체크 필요
            lastNode.next = newNode;
        } else {
            head = newNode;
        }
        this.listSize ++;
        return this;
    }

    public Node<E> addFirst(E data) {
        Node<E> temp = this.head;
        this.head = new Node<E>(data);
        head.next = temp;
        this.listSize ++;
        return this.head;
    }

    public boolean removeLast() {
        if (this.head!=null) {
            Node<E> lastNode = this.getLastNode(this.head);
            if (lastNode != null) {
                lastNode.prev.next = null;
                return true;
            }
        }
        return false;
    }

    public E removeFirst() {
        if (this.head!=null) {
            E data = head.data;
            this.head = head.next;
            return data;
        }
        return null;
    }

/*
    public boolean remove(E data) {
        if (head==null) return false;
        if (head.data == data) {
            // removeFirst 의 반환값을 수정했으므로, 해당 메서드도 수정이 필요하다
            return removeFirst();
        }

        for (int i = 1; i < this.listSize; i++) {
            Node<E> node = getNext(head);
            if (node == null) return false;
            if (node.data == data) {
                node.prev.next = node.next;
                return true;
            }
        }
        return false;
    }
*/

    /* 다음 노드를 반환한다. 다음 노드가 없는 경우 null 값을 반환한다. */
    private Node<E> getNext(Node node) {
        if (node.next == null) {
            return null;
        }
        return node.next;
    }

    /* 가장 마지막 노드를 반환한다.*/
    private Node<E> getLastNode(Node node) {
        if (node == null || node.next == null) {
            return node;
        }
        return getLastNode(node.next);
    }
}
