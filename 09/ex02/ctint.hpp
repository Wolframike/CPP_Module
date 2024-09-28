#ifndef CTINT_HPP
#define CTINT_HPP

#include <iostream>

class ctint { //comparisons-tracking int
	private:
		static size_t comparisons;
		int value;

	public:
		ctint(int value);
		ctint(const ctint &copy);
		ctint &operator=(const ctint &copy);
		~ctint();

		bool operator<(const ctint &rhs) const;
		bool operator>(const ctint &rhs) const;
		bool operator<=(const ctint &rhs) const;
		bool operator>=(const ctint &rhs) const;
		bool operator==(const ctint &rhs) const;
		bool operator!=(const ctint &rhs) const;

		static void addComparison();
		static size_t getComparisons();
		static void resetComparisons();

		int val() const;
};

std::ostream &operator<<(std::ostream &os, const ctint &rhs);
bool operator<(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs);
bool operator>(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs);
bool operator<=(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs);
bool operator>=(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs);
bool operator==(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs);
bool operator!=(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs);

// bool operator<(const ctint &lhs, const int &rhs);
// bool operator>(const ctint &lhs, const int &rhs);
// bool operator<=(const ctint &lhs, const int &rhs);
// bool operator>=(const ctint &lhs, const int &rhs);
// bool operator==(const ctint &lhs, const int &rhs);
// bool operator!=(const ctint &lhs, const int &rhs);

// //opposite
bool operator<(const int &lhs, const ctint &rhs);
// bool operator>(const int &lhs, const ctint &rhs);
// bool operator<=(const int &lhs, const ctint &rhs);
// bool operator>=(const int &lhs, const ctint &rhs);
// bool operator==(const int &lhs, const ctint &rhs);
// bool operator!=(const int &lhs, const ctint &rhs);

#endif