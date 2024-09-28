#ifndef CTINT_HPP
#define CTINT_HPP

#include <iostream>

class ctint { //comparisons-tracking int
	private:
		static size_t comparisons;
		int value;

	public:
		ctint();
		ctint(int value);
		ctint(ctint &copy);
		ctint(const ctint &copy);
		ctint(const long long &copy);
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

#endif