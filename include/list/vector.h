#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>
#include <cassert>

template <typename E>
class Vector {
public:
    Vector() {
        elementDataLength = 10;
        elementData = new E[elementDataLength];
        capacityIncrement = 0;
        elementCount = 0;
    }
    Vector(int initialCapacity) {
        elementDataLength = initialCapacity;
        elementData = new E[elementDataLength];
        capacityIncrement = 0;
        elementCount = 0;
    }
    Vector(int initialCapacity, int increment) {
        elementDataLength = initialCapacity;
        elementData = new E[elementDataLength];
        capacityIncrement = increment;
        elementCount = 0;
    }
    Vector(Vector &vec) {
        assert(!"Not implemented");
    }
    
    ~Vector() {
        delete[] elementData;
    }

    void clear() {
        removeAllElements();
    }

    bool isEmpty() {
        return elementCount == 0;
    }

    int size() {
        return elementCount;
    }

    int capacity() {
        return elementDataLength;
    }

    bool contains(E x) {
        for (int i = 0; i < elementCount; i++) {
            if (elementData[i] == x) {
                return true;
            }
        }
        return false;
    }

    int indexOf(E x) {
        for (int i = 0; i < elementCount; i++) {
            if (elementData[i] == x) {
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(E x) {
        int lastIndex = -1;
        for (int i = 0; i < elementCount; i++) {
            if (elementData[i] == x) {
                lastIndex = i;
            }
        }
        return lastIndex;
    }

    int lastIndexOf(E x, int index) {
        for (int j = index; j >= 0; j--) {
            if (elementData[j] == x) {
                return j;
            }
        }
        return -1;
    }

    E get(int index) {
        return elementAt(index);
    }

    E elementAt(int index) {
        assert(index >= 0 && index < size());
        return elementData[index];
    }

    E firstElement() {
        assert(!isEmpty());
        return elementData[0];
    }

    E lastElement() {
        assert(!isEmpty());
        return elementData[elementCount - 1];
    }

    E set(int index, E element) {
        // :CATION: reverse param order
        return setElementAt(element, index);
    }

    E setElementAt(E obj, int index) {
        assert(index >= 0 && index < size());
        E previousValue = elementData[index];
        elementData[index] = element;
        return previousValue;
    }

    void addElement(E obj) {
        assert(elementCount < elementDataLength);
        elementData[elementCount++] = obj;
    }

    void insertElementAt(E obj, int index) {
        assert(index >= 0 && index < size());
        for (int j = elementCount; j > index; j--) {
            elementData[j] = elementData[j-1];
        }
        elementCount[index] = obj;
        ++elementCount;
    }

    void removeElementAt(int index) {
        assert(index >= 0 && index < size());
        for (int j = index; j < elementCount - 1; j++) {
            elementData[j] = elementData[j+1];
        }
        --elementCount;
    }

    bool removeElement(E obj) {
        for (int i = 0; i < elementCount; i++) {
            if (elementData[i] == obj) {
                for (int j = i;  < elementCount - 1; j++) {
                    elementData[j] = elementData[j+1];
                }
                --elementCount;
                return true;
            }
        }
        return false;
    }

    bool removeAllElements() {
        elementCount = 0;
    }

private:
    E *elementData;
    int elementCount;
    int elementDataLength;
    int capacityIncrement;
};

#endif 
