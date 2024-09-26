template <typename PairContainer>
PairContainer PmergeMe::jacobsthalOrderGen(size_t upper) {
	PairContainer order;
	size_t i = 0;
	size_t j;
	size_t next = 1;
	while (true) {
		j = jacobsthal(i) * 2;
		next += j;
		for (size_t k = 0; k < j; k++) {
			if (next <= upper)
				order.push_back(std::make_pair(next, j));
			next--;
		}
		if (next >= upper)
			break;
		next += j;
		i++;
	}
	std::cout << std::endl;
	return order;
}

template <typename Container, typename Element>
void PmergeMe::binaryInsertion(Container& cont, const Element& el) {
	typename Container::iterator low = cont.begin();
	typename Container::iterator high = cont.end();

	while (low < high) {
		typename Container::iterator mid = low + (high - low) / 2;

		if (*mid < el)
			low = mid + 1;
		else
			high = mid;
	}

	cont.insert(low, el);
}


#include "PmergeMe.hpp"
