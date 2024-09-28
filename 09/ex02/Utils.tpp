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
void PmergeMe::binaryInsertion(Container& cont, const Element& el, size_t bound) {
	size_t start = 0;
	size_t end = bound;
	size_t mid;

	while (start < end) {
		mid = (start + end) / 2;
		if (cont[mid] < el)
			start = mid + 1;
		else
			end = mid;
	}
	cont.insert(cont.begin() + start, el);
}


#include "PmergeMe.hpp"
