//
//  Node.h
//  Heap
//
//  Created by Melissa on 17/10/20.
//  Copyright © 2020 Melissa Martínez Mendoza. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

template<class T>
struct Node{
    T data;
    Node<T> *next;
    Node<T> *prev;
    
    Node(T);
    Node(T, Node<T>*, Node<T>*);
};

template<class T>
Node<T> :: Node(T data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template<class T>
Node<T> :: Node(T data, Node<T> *next, Node<T> *prev){
    this->data = data;
    this->next = next;
    this->prev = prev;
}
