//
//  main.cpp
//  DataStructures
//
//  Created by Анастасия Мехова on 18.01.2025.
//

#include <iostream>
#include "TVector.h"
#include "TList.h"
#include "TStack.h"

int main(int argc, const char * argv[]) {
//    TVector<int> t(4);
//    std::cin >> t;
//    std::cout << t;
//    
//    t.Insert(4, 78);
//    
//    std::cout << t;
//    
//    t.Remove(2);
//    
//    std::cout << t;
    
//    TList<int> l;
//    int t1 = 4;
//    int* t2 = new int(3);
//    int* t3 = new int(6);
//    l.Add(&t1);
//    l.Add(t2);
//    l.Add(t3);
//    
//    for(size_t i = 0; i < l.GetSize(); ++i) {
//        std::cout << *(l[i].GetData()) << " ";
//    }
//    std::cout << std::endl;
//    
//    l.Remove(2);
//    
//    int t4 = 5;
//    l.Add(&t4);
//    
//    for(size_t i = 0; i < l.GetSize(); ++i) {
//        std::cout << *(l[i].GetData()) << " ";
//    }
//    std::cout << std::endl;
//    
//    int t5 = 99;
//    l.Insert(3, &t5);
//    
//    for(size_t i = 0; i < l.GetSize(); ++i) {
//        std::cout << *(l[i].GetData()) << " ";
//    }
//    std::cout << std::endl;
//    
//    TList<int> f(std::move(l));
//    
//    for(size_t i = 0; i < f.GetSize(); ++i) {
//        std::cout << *(f[i].GetData()) << " ";
//    }
//    std::cout << std::endl;
//    
//    
//    f.Clear();
    
    TList<int> l;
    l.Add(4);
    l.Add(3);
    l.Add(5);
    for(size_t i = 0; i < l.GetSize(); ++i) {
        std::cout << (l[i].GetData()) << " ";
    }
    std::cout << std::endl;

    l.Remove(2);

    l.Add(5);

    for(size_t i = 0; i < l.GetSize(); ++i) {
        std::cout << (l[i].GetData()) << " ";
    }
    std::cout << std::endl;

    l.Insert(3, 99);

    for(size_t i = 0; i < l.GetSize(); ++i) {
        std::cout << (l[i].GetData()) << " ";
    }
    std::cout << std::endl;

    TList<int> f(std::move(l));

    for(size_t i = 0; i < f.GetSize(); ++i) {
        std::cout << (f[i].GetData()) << " ";
    }
    std::cout << std::endl;


    f.Clear();

    
//    TStack<int> t;
//    t.Push(3);
//    t.Push(5);
//    std::cout << t.Top() << std::endl;
//    t.Top() = 9;
//    std::cout << t.Top() << std::endl;
//    
//    t.Pop();
//    std::cout << t.Top() << std::endl;
//    //t.Clear();
//    
//    
//    TStack<int> f(t);
//    std::cout << f.Top() << std::endl;
//    
    
    return 0;
}
