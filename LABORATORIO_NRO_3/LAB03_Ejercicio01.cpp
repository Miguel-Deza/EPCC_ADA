#include <cassert>
#include <iostream>
#include <vector>


 /* Tiempo de Complejidad BIG O: O(1)*/

template <typename T>
void print_element(const std::vector<T> &items, typename std::vector<T>::size_type index)
{
    assert(index < items.size() && "index out of bounds");
    std::cout << items[index]; 
}

template <typename T>
void print_element_pair(const std::vector<T> &items, typename std::vector<T>::size_type index1, typename std::vector<T>::size_type index2)
{
    assert((index1 < 0 || index1 < items.size()) && "index1 out of bounds");
    assert((index2 < 0 || index2 < items.size()) && "index2 out of bounds");

    print_element(items, index1); 
    std::cout << " , ";
    print_element(items, index2); 
    std::cout << std::endl;
}

/*
 * Tiempo de Complejidad BIG O: O(n)
 */
template <typename T>
void print_elements(const std::vector<T> &items)
{
    
    for (typename std::vector<T>::size_type i = 0; i < items.size(); ++i)
    {
        print_element(items, i);
        std::cout << ", ";
    }
    std::cout << std::endl;
}

/*
 * Tiempo de Complejidad BIG O: O(n^2)
 */
template <typename T>
void print_possible_pairs(const std::vector<T> &items)
{
    
    for (typename std::vector<T>::size_type i = 0; i < items.size(); ++i)
    {
        for (typename std::vector<T>::size_type j = 0; j < items.size(); ++j)
        {
            print_element_pair(items, i, j);
        }
    }
}

/*
 * Tiempo de Complejidad BIG O: O(n^n)
 */
int fibonacci(const int number)
{
    if (number <= 1)
        return number;
    return fibonacci(number - 2) + fibonacci(number - 1);
}

int main(int argc, char *argv[])
{

    const int num_elements = 3;
    std::vector<int> vector;
    vector.reserve(num_elements);
    for (int i = 0; i < num_elements; ++i)
    {
        vector.push_back(i);
    }


    print_element(vector, 0);
    std::cout << std::endl;

    print_element(vector, num_elements / 2);
    std::cout << std::endl;

    print_element(vector, num_elements - 1);
    std::cout << std::endl;

    print_element_pair(vector, 0, num_elements - 1);
    std::cout << std::endl
              << std::endl;
    print_elements(vector);
    std::cout << std::endl
              << std::endl;

    print_possible_pairs(vector);
    std::cout << std::endl
              << std::endl;


    // Tiempo Complejidad O(n^n)
    std::cout << fibonacci(10) << std::endl;
}