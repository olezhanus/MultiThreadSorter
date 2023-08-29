#pragma once
#include <vector>
class MultiThreadSorter
{
public:

	void operator()(std::vector<int> &vec);
	void make_threads(bool val);

private:
	const size_t _BIG_NUMBER { 500000 };

	bool _make_threads { true };


	//mergesort из 11 модуля, чуть переделанный под std::vector
	void mergesort(std::vector<int> &vec, size_t l, size_t r);

	void merge(std::vector<int> &vec, size_t l, size_t m, size_t r);
};

