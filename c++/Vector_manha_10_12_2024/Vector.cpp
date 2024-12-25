#include <iostream>
#include <string>
#include "Vector.hpp"

Vector::Vector(const Vector& vec) {
    m_capacity = vec.m_capacity;
    m_size = vec.m_size;
    m_array = new int[m_capacity];
    for(int i = 0; i < m_size; ++i) {
        m_array[i] = vec.m_array[i];
    }
}

Vector::Vector() {
    m_capacity = 1;
    m_size = 0;
    m_array = new int[m_capacity];
}

Vector::~Vector() {
    delete[] m_array;
}

void Vector::reserve(int n) {
    if(n > m_capacity) {
        m_capacity = n;
        int* aux = new int[m_capacity];
        for(int i = 0; i < m_size; i++) {
            aux[i] = m_array[i];
        }
        delete[] m_array;
        m_array = aux;
    }
}

void Vector::push_back(const int & value) {
    if(m_size == m_capacity) { // se estiver cheio
        reserve(m_capacity * 2); // dobra a capacidade da lista
    }
    m_array[m_size] = value;
    m_size++;
}

int& Vector::at(int k) {
    if(k >= 0 && k < m_size) {
        return m_array[k];
    }
    else {
        std::string mensagem = "indice " + std::to_string(k) + " fora do intervalo";
        throw std::out_of_range(mensagem);
    }
}

const int& Vector::at(int k) const {
    if(k >= 0 && k < m_size) {
        return m_array[k];
    }
    else {
        std::string mensagem = "indice " + std::to_string(k) + " fora do intervalo";
        throw std::out_of_range(mensagem);
    }
}

int Vector::size() const {
    return m_size;
}

bool Vector::empty() const {
    return m_size == 0;
}

int Vector::capacity() const {
    return m_capacity;
}

int& Vector::operator[] (int k) {
    if(k >= 0 && k < m_size) {
        return m_array[k];
    }
    else {
        std::string mensagem = "indice " + std::to_string(k) + " fora do intervalo";
        throw std::out_of_range(mensagem);
    }
}   

const int& Vector::operator[] (int k) const {
    if(k >= 0 && k < m_size) {
        return m_array[k];
    }
    else {
        std::string mensagem = "indice " + std::to_string(k) + " fora do intervalo";
        throw std::out_of_range(mensagem);
    }
}

void Vector::pop_back() {
    if(m_size > 0) {
        m_size--;
    }
}