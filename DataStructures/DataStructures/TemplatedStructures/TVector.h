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

template<typename T>
class TVector {
private:
    T* data;
    size_t length;
public:
    explicit TVector(size_t size = 1) : length(size), data(new T[size]()) {}
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
        else {
            return *this;
        }
    }
    T& operator[](size_t i){
        if((i < 0) || (i >= length)) {
            throw std::out_of_range("index out of range");
        }
        return data[i];
    }
    void SetLength(size_t new_length){
        T* temp = new T[new_length];
        for(size_t i = 0; i < min(new_length, length); ++i) {
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        length = new_length;
    }
    size_t GetLength(){
        return length;
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
