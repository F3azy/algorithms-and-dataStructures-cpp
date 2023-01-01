#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <class  T>
class DynamicArray {
    private:
        T* array;
        unsigned int arraySize;
        unsigned int arrayOccupied;

        void increaseArraySize();
    public:
        DynamicArray();
        DynamicArray(int);
        ~DynamicArray();
        T* getArray();
        int getSize();
        int getOccupied();
        void push(T);
        void pop();
        bool empty();
        void clear();
        int indexOf(T);
        int* allIndexOf(int);
        int allIndexOfCount(int);
        void sort(std::string = "ASC");
        T& operator[](int);
        template<typename U>
        friend std::ostream& operator<<(std::ostream&, const DynamicArray<U>&);
};

#endif