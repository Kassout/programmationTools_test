//
// Created by maxim on 23/04/2021.
//

#ifndef LLIST_H
#define LLIST_H

#define DL_APPEND(head,add)                                                                    \
    DL_APPEND2(head,add,prev,next)

#define DL_APPEND2(head,add,prev,next)                                                         \
do {                                                                                           \
  if (head) {                                                                                  \
      (add)->prev = (head)->prev;                                                              \
      (head)->prev->next = (add);                                                              \
      (head)->prev = (add);                                                                    \
      (add)->next = NULL;                                                                      \
  } else {                                                                                     \
      (head)=(add);                                                                            \
      (head)->prev = (head);                                                                   \
      (head)->next = NULL;                                                                     \
  }                                                                                            \
} while (0)

#define DL_DELETE(head,del)                                                                    \
    DL_DELETE2(head,del,prev,next)

#define DL_DELETE2(head,del,prev,next)                                                         \
do {                                                                                           \
  assert((head) != NULL);                                                                      \
  assert((del)->prev != NULL);                                                                 \
  if ((del)->prev == (del)) {                                                                  \
      (head)=NULL;                                                                             \
  } else if ((del)==(head)) {                                                                  \
      (del)->next->prev = (del)->prev;                                                         \
      (head) = (del)->next;                                                                    \
  } else {                                                                                     \
      (del)->prev->next = (del)->next;                                                         \
      if ((del)->next) {                                                                       \
          (del)->next->prev = (del)->prev;                                                     \
      } else {                                                                                 \
          (head)->prev = (del)->prev;                                                          \
      }                                                                                        \
  }                                                                                            \
} while (0)

template<typename T>
class DoubleLinkedList {
private:
    struct Node {
        T _data;
        Node* _prev;
        Node* _next;
        Node(T data, Node* prev, Node* next) : _data(data), _prev(prev), _next(next) {}
    };
    Node* _head;
    Node* _tail;
public:
    DoubleLinkedList() : _head(NULL), _tail(NULL) {}

    template<int N>
    explicit DoubleLinkedList(T (&arr) [N]);
    ~DoubleLinkedList();

    bool empty() const;
    explicit operator bool() const;
    void push_back(T);
    void push_front(T);
    T pop_back();
    T pop_front();
};

#endif /* LLIST_H */
