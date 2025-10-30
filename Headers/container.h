
#include <vector>
#include <algorithm>

#include <iterator>




template <typename T>
class CustomIterator {
public:
    explicit CustomIterator(T* ptr = nullptr) : m_ptr(ptr) {}

    T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

    CustomIterator& operator++() {
        ++m_ptr;
        return *this;
    }

    CustomIterator operator++(int) {
        CustomIterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const CustomIterator& other) const {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const CustomIterator& other) const {
        return !(*this == other);
    }

private:
    T* m_ptr;
};

template <typename T>
class CustomContainer {
public:
    using iterator = CustomIterator<T>;
    using const_iterator = CustomIterator<const T>;


    void add(const T& value) {
        data.push_back(value);
    }


    void remove(int value) {
        data.erase(data.begin() + value);
    }

    T& operator[](std::size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    iterator begin() {
        return iterator(data.data());
    }

    iterator end() {
        return iterator(data.data() + data.size());
    }

    const_iterator begin() const {
        return const_iterator(data.data());
    }

    const_iterator end() const {
        return const_iterator(data.data() + data.size());
    }

    void sort() {
        std::sort(begin(), end());
    }

    void clear() {
        data.clear();
    }

    std::size_t size() const {
        return data.size();
    }

private:
    std::vector<T> data;
};
