//
//  main.cpp
//  DataStructures
//
//  Created by Анастасия Мехова on 18.01.2025.
//

#include <iostream>
#include "TVector.h"
#include "TStack.h"

int main(int argc, const char * argv[]) {
    TVector<int> t(4);
    std::cin >> t;
    std::cout << t;
    
    t.Insert(4, 78);
    
    std::cout << t;
    
    t.Remove(2);
    
    std::cout << t;
    
    
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
