#include <iostream>
#include <vector>

#include "..\..\..\include\TADS\Set\Set.hpp"

template <typename T>
Set<T>::Set() {}

template <typename T>
Set<T>::~Set() {}

template <typename T>
bool Set<T>::insert(T element) {
    // Verificar se o elemento já existe no conjunto
    if (contains(element)) {
        return false;
    }

    // Inserir o elemento no vetor
    elements.push_back(element);
    return true;
}

template <typename T>
bool Set<T>::remove(T element) {
    // Procurar o elemento no vetor
    auto it = find(elements.begin(), elements.end(), element);

    // Verificar se o elemento foi encontrado
    if (it != elements.end()) {
        // Remover o elemento do vetor
        elements.erase(it);
        return true;
    }

    return false;
}

template <typename T>
bool Set<T>::contains(T element) const {
    // Procurar o elemento no vetor
    auto it = find(elements.begin(), elements.end(), element);

    // Verificar se o elemento foi encontrado
    return (it != elements.end());
}

template <typename T>
int Set<T>::size() const {
    return elements.size();
}

template <typename T>
bool Set<T>::isEmpty() const {
    return elements.empty();
}

template <typename T>
void Set<T>::print() const {
    for (const T& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}