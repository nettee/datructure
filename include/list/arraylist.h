#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include <iostream>
#include <cassert>

static const int defaultSize = 1024;

template <typename E>
class ArrayList {
public:
    ArrayList() {
        theMaxSize = defaultSize;
        elements = new E[theMaxSize];
        theSize = 0;
    }

    ArrayList(ArrayList& anothor) {
        theMaxSize = defaultSize;
        elements = new E[theMaxSize];
        theSize = anothor.size();
        for (int i = 0; i < theSize; i++) {
            elements[i] = anothor.elements[i];
        }
    }

    ~ArrayList() { 
        delete[] elements;
    }

    void clear() {
        theSize = 0;
    }

    bool isEmpty() {
        return theSize == 0;
    }

    int size() {
        return theSize;
    }

    E get(int index) {
        assert(index >= 0 && index < theSize);
        return elements[index];
    }

    E set(int index, E e) {
        assert(index >= 0 && index < theSize);
        E prev_element = elements[index];
        elements[index] = e;
        return prev_element;
    }

    bool contains(E x) {
        for (int i = 0; i < theSize; i++) {
            if (elements[i] == x) {
                return true;
            }
        }
        return false;
    }

    int indexOf(E x) {
        for (int i = 0; i < theSize; i++) {
            if (elements[i] == x) {
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(E x) {
        int lastIndex = -1;
        for (int i = 0; i < theSize; i++) {
            if (elements[i] == x) {
                lastIndex = i;
            }
        }
        return lastIndex;
    }

    bool add(E e) {
        assert(theSize < theMaxSize);
        elements[theSize++] = e;
    }

    void add(int index, E e) {
        assert(index >= 0 && index < theSize);
        for (int j = theSize; j > index; j--) {
            elements[j] = elements[j-1];
        }
        ++theSize;
        elements[index] = e;
    }

    /* different from Java API
     * because of the pitfall of C++ language
     */
    E removeByIndex(int index) {
        assert(index >= 0 && index < theSize);
        E val = elements[index];
        for (int j = index; j < theSize - 1; j++) {
            elements[j] = elements[j+1];
        }
        --theSize;
        return val;
    }

    bool remove(E x) {
        for (int i = 0; i < theSize; i++) {
            if (elements[i] == x) {
                for (int j = i; j < theSize - 1; j++) {
                    elements[j] = elements[j+1];
                }
                --theSize;
                return true;
            }
        }
        return false;
    }

    void removeRange(int fromIndex, int toIndex) {
        assert(fromIndex >= 0 && fromIndex < theSize);
        assert(toIndex >= 0 && toIndex < theSize);
        int rangeWidth = toIndex - fromIndex;
        for (int j = 0; j < rangeWidth; j++) {
            elements[fromIndex + j] = elements[toIndex + j];
        }
        theSize -= rangeWidth;
    }

    // :IMPROVEABLE: efficiency
    void fromArray(E *source, int length) {
        clear();
        for (int i = 0; i < length; i++) {
            add(source[i]);
        }
    }

    // :IMPROVEABLE: efficiency
    void toArray(E *destination) {
        for (int i = 0; i < size(); i++) {
            destination[i] = get(i);
        }
    }

    // :NOTE: subList method not implemented
    // it is hard to implement it nice in C++
    ArrayList subList(int fromIndex, int toIndex) {
        assert(0);
    }

    void output();

private:
    E *elements;
    int theMaxSize;
    int theSize;
};

template <typename E>
void ArrayList<E>::output()
{
    for (int i = 0; i < theSize; i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

#endif 
