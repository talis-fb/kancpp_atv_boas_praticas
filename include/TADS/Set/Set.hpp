#ifndef SET_CLASS
#define SET_CLASS

#include <vector>

using namespace std;

/**
 * @brief The Set class represents a set data structure.
 *
 * It stores a collection of unique elements.
 *
 * @tparam T The type of elements stored in the set.
 */
template <typename T>
class Set
{
private:
    vector<T> elements; /**< The vector storing the elements of the set. */
public:
    /**
     * @brief Constructs an empty Set object.
     */
    Set() {}

    /**
     * @brief Destroys the Set object and frees the memory.
     */
    ~Set() {}

    /**
     * @brief Insert an element into the set.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false if it already exists in the set.
     */
    bool insert(T element)
    {
        // Verificar se o elemento já existe no conjunto
        if (contains(element))
        {
            return false;
        }

        // Inserir o elemento no vetor
        elements.push_back(element);
        return true;
    }

    /**
     * @brief Remove an element from the set.
     *
     * @param element The element to remove.
     * @return True if the element was successfully removed, false if it does not exist in the set.
     */
    bool remove(T element)
    {
        // Procurar o elemento no vetor
        auto it = find(elements.begin(), elements.end(), element);

        // Verificar se o elemento foi encontrado
        if (it != elements.end())
        {
            // Remover o elemento do vetor
            elements.erase(it);
            return true;
        }

        return false;
    }

    /**
     * @brief Check if the set contains the specified element.
     *
     * @param element The element to search for.
     * @return True if the element is found in the set, false otherwise.
     */
    bool contains(T element) const
    {
        // Procurar o elemento no vetor
        auto it = find(elements.begin(), elements.end(), element);

        // Verificar se o elemento foi encontrado
        return (it != elements.end());
    }

    /**
     * @brief Get the size of the set.
     *
     * @return The number of elements in the set.
     */
    int size() const
    {
        return elements.size();
    }

    /**
     * @brief Check if the set is empty.
     *
     * @return True if the set is empty, false otherwise.
     */
    bool isEmpty() const
    {
        return elements.empty();
    }

    /**
     * @brief Print the elements of the set.
     */
    void print() const
    {
        for (const T &element : elements)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

#endif