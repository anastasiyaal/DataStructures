//
//  TTList.h
//  DataStructures
//
//  Created by Анастасия Мехова on 20.01.2025.
//

#ifndef TList_h
#define TList_h


#include <stdio.h>
#include <stdexcept>


template<typename T>
class TListData {
public:
    TListData(T* _data) : data(_data) {}
    T*& GetData() {
        return data;
    }
private:
    void SetNext(TListData<T>* _next) {
        next = _next;
    }

    TListData<T>* GetNext() const {
        return next;
    }
    TListData<T>* next;
    T* data;
    template<typename U>
    friend class TList;
};



template<typename T>
class TList {
public:
    TList() : head(nullptr), tail(nullptr), current_size(0) {}
    TList(TList&& src) : head(src.head), tail(src.tail), current_size(src.current_size) {
        src.head = nullptr;
        src.tail = nullptr;
        src.current_size = 0;
    }
    void Add(T* data) {
        if(!current_size) {
            head = new TListData<T>(data);
            tail = head;
            ++current_size;
        }
        else {
            TListData<T>* temp = tail;
            tail = new TListData<T>(data);
            temp->SetNext(tail);
            ++current_size;
        }
    }
    void Remove(size_t index) {
        if(index >= current_size) {
            throw std::out_of_range("index must be less or equal than size");
        }
        TListData<T>* current = head;
        TListData<T>* prev = nullptr;
        for (size_t i = 0; i < index; ++i) {
            prev = current;
            current = current->GetNext();
        }
        if(!index) {
            head = current->GetNext();
            delete current;
        }
        else {
            if(index == current_size - 1) {
                tail = prev;
            }
            prev->SetNext(current->GetNext());
            delete current;
        }
        --current_size;
    }
    
    TListData<T>& operator[](size_t index) {
        TListData<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->GetNext();
        }
        return *current;
    }
    
    void Insert(size_t index, T* value) {
        if(index > current_size) {
            throw std::out_of_range("index must be less or equal than size");
        }
        if(index == current_size) {
            Add(value);
        }
        else {
            TListData<T>* current = head;
            TListData<T>* prev = nullptr;
            
            for (size_t i = 0; i < index; ++i) {
                prev = current;
                current = current->GetNext();
            }
            TListData<T>* new_current = new TListData<T>(value);
            if(!index) {
                new_current->SetNext(head);
                head = new_current;
            }
            else {
                new_current->SetNext(current);
                prev->SetNext(new_current);
            }
            ++current_size;
        }
    }
    
    void Clear() {
        TListData<T>* current = head;
        for (size_t i = 0; i < current_size; ++i) {
            TListData<T>* temp = current->GetNext();
            delete current;
            current = temp;
        }
//        delete tail;
    }
    
    size_t GetSize() const {
        return current_size;
    }
private:
    TListData<T>* head;
    TListData<T>* tail;
    size_t current_size;
};





#endif /* TTList_h */
