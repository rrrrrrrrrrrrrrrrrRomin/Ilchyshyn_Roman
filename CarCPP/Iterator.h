#pragma once
#include <vector>
template <typename T>
class Iterator {
private:
	typename std::vector<T>::iterator current;
public:
	Iterator() = default;
	Iterator(typename std::vector<T>::iterator iter) : current(iter) {}

	T& operator*() {
		return *current;
	}

	Iterator<T>& operator++() {
		++current;
		return *this;
	}

	bool operator!=(const Iterator<T>& other) const {
		return current != other.current;
	}
};

