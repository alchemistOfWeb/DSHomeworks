#include <iostream>
#include <stdexcept>
#include <initializer_list> 


template <class T, size_t _size>
class MyArray {
private:
    T m_arr[_size];
public:
    MyArray() {}

    MyArray(const std::initializer_list<T>& init_list) {
        if (init_list.size() > _size) {
            throw std::out_of_range("Init list size is out of range");
        }

        int i = 0;
        for (auto &el : init_list) {
            m_arr[i] = el;
            i++;
            /*m_arr[i] = init_list[i];*/
        }
    }

    void fill(T filler) {
        for (int i = 0; i <= _size; i++) {
            m_arr[i] = filler;
        }
    }

    T& operator[](size_t index) {
        if (index < 0)
            throw std::invalid_argument("value must be positive");
        return m_arr[index];
    }

    const T& operator[](size_t index) const {
        if (index < 0)
            throw std::invalid_argument("value must be positive");
        return m_arr[index];
    }

    
    bool operator==(const MyArray<T, _size>& other) const {
        for (int i = 0; i < _size; i++) {
            if (m_arr[i] != other.m_arr[i]) return false;
        }
        return true;
    }

    bool operator!=(const MyArray<T, _size>& other) const {
        for (int i = 0; i < _size; i++) {
            if (m_arr[i] != other.m_arr[i]) return true;
        }
        return false;
    }
    
    bool operator<(const MyArray<T, _size>&other) const {
        for (int i = 0; i < _size; i++) {
            if (m_arr[i] < other.m_arr[i]) return true;
        }
        return false;
    }

    bool operator>(const MyArray<T, _size>&other) const {
        for (int i = 0; i < _size; i++) {
            if (m_arr[i] > other.m_arr[i]) return true;
        }
        return false;
    }

    bool operator>=(const MyArray<T, _size>&other) const {
        for (int i = 0; i < _size; i++) {
            if (m_arr[i] >= other.m_arr[i]) return true;
        }
        return false;
    }

    bool operator<= (const MyArray<T, _size>&other) const {
        for (int i = 0; i < _size; i++) {
            if (m_arr[i] <= other.m_arr[i]) return true;
        }
        return false;
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
        for (int i = 0; i < _size; i++) {
            T tmp = other.m_arr[i];
            other.m_arr[i] = m_arr[i];
            m_arr[i] = tmp;
        }
    }

};

int main() {
    std::cout << "Hello World!\n";
    MyArray<int, 3> a {1, 4, 3};
    MyArray<int, 3> b {1, 2, 3};
    MyArray<int, 3> c {1, 2, 3};
    std::cout << "a == b: " << (a == b) << std::endl;
    a.swap(c);
    std::cout << "a == b: " << (a == b) << std::endl;

    MyArray<int, 3> a1 {1, 2, 3};
    MyArray<int, 3> a2 {1, 2, 3};
    std::cout << "a <= b: " << (a1 <= a2) << std::endl;
}
