#include "ctint.hpp"

size_t ctint::comparisons = 0;

ctint::ctint(int value) : value(value) {}

ctint::ctint(const ctint &copy) {
	*this = copy;
}

ctint &ctint::operator=(const ctint &copy) {
	if (this != &copy) {
		this->value = copy.value;
	}
	return *this;
}

ctint::~ctint() {}

bool ctint::operator<(const ctint &rhs) const {
	comparisons++;
	std::cerr << this->value << "\t vs \t" << rhs.value << std::endl;
	return this->value < rhs.value;
}

bool ctint::operator>(const ctint &rhs) const {
	comparisons++;
	std::cerr << this->value << "\t vs \t" << rhs.value << std::endl;
	return this->value > rhs.value;
}

bool ctint::operator<=(const ctint &rhs) const {
	comparisons++;
	std::cerr << this->value << "\t vs \t" << rhs.value << std::endl;
	return this->value <= rhs.value;
}

bool ctint::operator>=(const ctint &rhs) const {
	comparisons++;
	std::cerr << this->value << "\t vs \t" << rhs.value << std::endl;
	return this->value >= rhs.value;
}

bool ctint::operator==(const ctint &rhs) const {
	comparisons++;
	std::cerr << this->value << "\t vs \t" << rhs.value << std::endl;
	return this->value == rhs.value;
}

bool ctint::operator!=(const ctint &rhs) const {
	comparisons++;
	std::cerr << this->value << "\t vs \t" << rhs.value << std::endl;
	return this->value != rhs.value;
}

size_t ctint::getComparisons() {
	return comparisons;
}

void ctint::resetComparisons() {
	comparisons = 0;
}

int ctint::val() const {
	return this->value;
}

std::ostream &operator<<(std::ostream &os, const ctint &rhs) {
	os << rhs.val();
	return os;
}

bool operator<(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs) {
	return lhs.first < rhs.first;
}

bool operator>(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs) {
	return lhs.first > rhs.first;
}

bool operator<=(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs) {
	return lhs.first <= rhs.first;
}

bool operator>=(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs) {
	return lhs.first >= rhs.first;
}

bool operator==(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs) {
	return lhs.first == rhs.first;
}

bool operator!=(const std::pair<ctint, size_t>& lhs, const std::pair<ctint, size_t>& rhs) {
	return lhs.first != rhs.first;
}
