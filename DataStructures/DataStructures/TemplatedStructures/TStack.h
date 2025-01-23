//
//  TStack.h
//  DataStructures
//
//  Created by Анастасия Мехова on 21.01.2025.
//

#ifndef TStack_h
#define TStack_h



template<typename T>
class TStack {
public:
    TStack() {}
    TStack(TStack&& src) : head(src.head) {
        src.head = nullptr;
    }
    TStack(TStack& src) {        
        if(src.head) {
            Node* temp = src.head;
//            while (!src.IsEmpty()) {
            while (temp) {
                Push(temp->value);
                temp = src.head->next;
            }
        }
        
    }
    void Push(T const _value) {
        Node* new_node = new Node{_value, head};
        head = new_node;
    }
    void Pop() {
        if(!IsEmpty()) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }
    T& Top() {
        if(IsEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return head->value;
    }
    bool IsEmpty() const {
        return head == nullptr;
    }
    void Clear() {
        while (!IsEmpty()) {
            Pop();
        }
    }
    ~TStack() {
        Clear();
    }
    
private:
    struct Node{
        T value;
        Node* next;
    };
    Node* head = nullptr;
};


#endif /* TStack_h */
