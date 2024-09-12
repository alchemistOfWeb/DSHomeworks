#include <iostream>
#include <stdexcept>

template <typename T, size_t _size>
class MyArray {
private:
    T m_arr[_size];
public:
    MyArray() {}

    void fill(T filler) {
        for (int i = 0; i <= _size; i++) {
            m_arr[i] = filler;
        }
    }

    T& operator[](int index) {
        if (index >= _size || index <= 0)
            throw std::invalid_argument("value is out of bounce in []");
        return m_arr[index];
    }

    T* data() {
        return m_arr;
    }

    T& front() {
        return m_arr[0];
    }

    T& back() {
        return m_arr[_size - 1];
    }

    T& at(size_t pos) {
        if (pos >= _size || pos <= 0)
            throw std::invalid_argument("value is out of bounce in at method");
        return m_arr[pos];
    }

    size_t size() {
        return size;
    }

    void swap(MyArray<T, _size>& other) {
        for (int i = 0; i <= _size; i++) {
            T tmp = other.m_arr[i];
            other.m_arr[i] = m_arr[i];
            m_arr[i] = tmp;
        }
    }

};

int main() {
    std::cout << "Hello World!\n";
    MyArray<int, 1> arr;
}
