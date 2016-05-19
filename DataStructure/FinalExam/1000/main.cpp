const int SIZE = 200;

template <class QueueEntry>
class MyQueue {
public:
  MyQueue();
  // 入队操作
  void append(const QueueEntry &item);
  // 出队操作，如果队列为空，则什么都不做
  void serve();
  // 获取队头元素，如果队列为空，则什么都不做
  void retrieve(QueueEntry &item) const;
private:
  // 队列成员变量可以自定义
  int arr[SIZE], front, tail, size;
};

template <typename T>
MyQueue<T>::MyQueue() {
  front = tail = -1;
  size = 0;
}

template <typename T>
void MyQueue<T>::append(const T& item) {
  ++size;
  if (-1 == front) {
    front = tail = 0;
    arr[tail] = item;
  } else {
    tail = (tail + 1) % SIZE;
    arr[tail] = item;
  }
}

template <typename T>
void MyQueue<T>::serve() {
  if (size > 0) {
    front = (front + 1) % SIZE;
    --size;
  }
}

template <typename T>
void MyQueue<T>::retrieve(T &item) const {
  if (size > 0) {
    item = arr[front];
  }
}

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  MyQueue<int> q;
  q.append(12);
  q.append(5);
  int k;
  q.retrieve(k);
  cout << k << endl;
  return 0;
}
