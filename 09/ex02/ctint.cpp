#include "ctint.hpp"

size_t ctint::comparisons = 0;

ctint::ctint() {}

ctint::ctint(int value) : value(value) {}

ctint::ctint(const ctint &copy) {
	*this = copy;
}

ctint::ctint(const long long &value) {
	if (value > INT_MAX || value < INT_MIN)
		throw std::out_of_range("Value is out of range for int");
	this->value = static_cast<int>(value);
}

ctint &ctint::operator=(const ctint &copy) {
	if (this != &copy)
		this->value = copy.value;
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

void ctint::addComparison() {
	comparisons++;
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
