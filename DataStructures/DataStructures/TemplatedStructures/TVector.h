//
//  TVector.h
//  DataStructures
//
//  Created by Анастасия Мехова on 18.01.2025.
//

#ifndef TVector_h
#define TVector_h

#include <stdexcept>
#include <iostream>
#include <algorithm>

template<typename T>
class TVector {
private:
    T* data;
    size_t length; //текущий размер вектора
//    size_t capacity; //общее кол-во элементов в векторе
public:
    explicit TVector(size_t size = 1) : length(size), data(new T[size]()) {
        if(!size) {
            throw std::invalid_argument("size must be greater than 0");
        }
    }
    TVector(const TVector& other) : length(other.length), data(new T[other.length]()) {
        for(size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }
    ~TVector() {
        delete [] data;
    }
    TVector& operator=(const TVector& other){
        if(this != &other) {
            delete [] data;
            length = other.length;
            data = new T[length];
            for(size_t i = 0; i < length; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    T& operator[](size_t i){
        if(i >= length) {
            throw std::out_of_range("index out of range");
        }
        return data[i];
    }
    void SetLength(size_t new_length){
        if(!new_length) {
            throw std::invalid_argument("length must be greater than 0");
        }
        T* temp = new T[new_length];
        for(size_t i = 0; i < std::min(new_length, length); ++i) {
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        length = new_length;
    }
    size_t GetLength(){
        return length;
    }
    
    void Insert(size_t index, T const & value) {
        if(index > length) {
            throw std::out_of_range("index must be less or equal length");
        }
        
        SetLength(length + 1);
        for(size_t i = length - 1; i > index; --i) {
            data[i] = data[i-1];
        }
        data[index] = value;
    }
    void Remove(size_t index) {
        if(index > length) {
            throw std::out_of_range("index must be less or equal length");
        }
        for(size_t i = index; i < length - 1; ++i) {
            data[i] = data[i+1];
        }
        SetLength(length - 1);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const TVector& vector){
        for(size_t i = 0; i < vector.length; ++i) {
            os << vector.data[i] << " ";
        }
        os << std::endl;
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, const TVector& vector){
        for(size_t i = 0; i < vector.length; ++i) {
            is >> vector.data[i];
        }
        return is;
    }
};


//int main() {
//    TVector<int> t(2);
//    
//    TVector<int> t2 = 2;  // без explicit 2 преобразовывапется в аргумент конструктора
//    
//    
//    TVector<int> t3 = static_cast<TVector<int>>(2); // это уже явное преобразование (ошибки компиляции не будет)
//    
//    return 0;
//}


#endif /* TVector_h */
