#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <stdexcept>

using namespace std;

// 1. PAIR
template <typename K, typename V>
struct Pair {
    K first;
    V second;

    Pair() {}
    Pair(K k, V v) : first(k), second(v) {}

    bool operator==(const Pair& other) const {
        return first == other.first;
    }
};

// 2. VECTOR
template <typename T>
class MyVector {
public:
    typedef T* iterator;
    typedef const T* const_iterator;

private:
    T* data;
    size_t m_capacity;
    size_t m_size;

    void resize_capacity(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < m_size; i++) {
            newData[i] = data[i];
        }
        if (data) delete[] data;
        data = newData;
        m_capacity = newCapacity;
    }

public:
    MyVector() {
        m_capacity = 10;
        m_size = 0;
        data = new T[m_capacity];
    }

    MyVector(const MyVector& other) {
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        data = new T[m_capacity];
        for (size_t i = 0; i < m_size; i++) {
            data[i] = other.data[i];
        }
    }

    ~MyVector() {
        if (data) delete[] data;
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            if (data) delete[] data;
            m_capacity = other.m_capacity;
            m_size = other.m_size;
            data = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            resize_capacity(m_capacity == 0 ? 10 : m_capacity * 2);
        }
        data[m_size++] = value;
    }

    T& operator[](size_t index) {
        if (index >= m_size) throw out_of_range("Index out of bounds");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= m_size) throw out_of_range("Index out of bounds");
        return data[index];
    }

    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    void clear() { m_size = 0; }

    iterator begin() { return data; }
    iterator end() { return data + m_size; }
    const_iterator begin() const { return data; }
    const_iterator end() const { return data + m_size; }

    // Hàm xóa tại vị trí iterator
    iterator erase(iterator pos) {
        if (pos < begin() || pos >= end()) return end();

        for (iterator it = pos; it < end() - 1; ++it) {
            *it = *(it + 1);
        }
        m_size--;
        return pos;
    }

    // Hàm xóa một khoảng (iterator first -> last)
    iterator erase(iterator first, iterator last) {
        if (first >= last) return end();

        size_t countToRemove = last - first;
        size_t itemsAfter = end() - last;

        for (size_t i = 0; i < itemsAfter; ++i) {
            *(first + i) = *(last + i);
        }

        m_size -= countToRemove;
        return first + itemsAfter;
    }
};

// 3. MAP
template <typename K, typename V>
class MyMap {
private:
    MyVector<Pair<K, V>> items;

public:
    void insert(const Pair<K, V>& p) {
        (*this)[p.first] = p.second;
    }

    void erase(const K& key) {
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].first == key) {
                items.erase(items.begin() + i);
                return;
            }
        }
    }

    V& operator[](const K& key) {
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].first == key) {
                return items[i].second;
            }
        }
        items.push_back(Pair<K, V>(key, V()));
        return items[items.size() - 1].second;
    }

    size_t count(const K& key) const {
        for(size_t i=0; i < items.size(); i++) {
            if(items[i].first == key) return 1;
        }
        return 0;
    }

    size_t size() const { return items.size(); }
    bool empty() const { return items.empty(); }
    void clear() { items.clear(); }

    typename MyVector<Pair<K, V>>::iterator begin() { return items.begin(); }
    typename MyVector<Pair<K, V>>::iterator end() { return items.end(); }
    typename MyVector<Pair<K, V>>::const_iterator begin() const { return items.begin(); }
    typename MyVector<Pair<K, V>>::const_iterator end() const { return items.end(); }
};

// 4. AlGORITHM
class Algorithms {
public:
    // partition
    template <typename T, typename Compare>
    static int partition(MyVector<T>& arr, int low, int high, Compare comp) {
        T pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (comp(arr[j], pivot)) {
                i++;
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        T temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }

    // main quicksort
    template <typename T, typename Compare>
    static void quickSort(MyVector<T>& arr, int low, int high, Compare comp) {
        if (low < high) {
            int pi = partition(arr, low, high, comp);

            quickSort(arr, low, pi - 1, comp);
            quickSort(arr, pi + 1, high, comp);
        }
    }

    // wrapper func
    template <typename T, typename Compare>
    static void sort(MyVector<T>& arr, Compare comp) {
        if (!arr.empty()) {
            quickSort(arr, 0, (int)arr.size() - 1, comp);
        }
    }

    // binary search
    template <typename T, typename K>
    static int binarySearch(const MyVector<T>& arr, K key, int (*getKey)(const T&)) {
        int left = 0;
        int right = (int)arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            K midKey = getKey(arr[mid]);

            if (midKey == key) {
                return mid;
            }
            if (midKey < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    // linear search
    template <typename T>
    static MyVector<T> linearSearch(const MyVector<T>& arr, const string& keyword, string (*getName)(const T&)) {
        MyVector<T> result;
        string keyLower = keyword;
        for(char &c : keyLower) if(c >= 'A' && c <= 'Z') c += 32;

        for (int i = 0; i < (int)arr.size(); i++) {
            string name = getName(arr[i]);
            string nameLower = name;
            for(char &c : nameLower) if(c >= 'A' && c <= 'Z') c += 32;

            if (nameLower.find(keyLower) != string::npos) {
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};

#endif
