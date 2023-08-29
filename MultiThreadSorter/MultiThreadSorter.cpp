// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "MultiThreadSorter.h"
#include <future>


void MultiThreadSorter::operator()(std::vector<int> &vec)
{
	mergesort(vec, 0, (vec.size() - 1));
}

void MultiThreadSorter::make_threads(bool val)
{
	_make_threads = val;
}

void MultiThreadSorter::mergesort(std::vector<int> &vec, size_t l, size_t r)
{
	if (l >= r)
	{
		return;
	}

	auto m = (l + r - 1) / 2;

	if (_make_threads && (r - l > _BIG_NUMBER))
	{
		auto f = std::async(std::launch::async, [&]()
			{
				mergesort(vec, l, m);
			});

		mergesort(vec, m + 1, r);
	}
	else
	{
		mergesort(vec, l, m);
		mergesort(vec, m + 1, r);
	}
	merge(vec, l, m, r);
}

void MultiThreadSorter::merge(std::vector<int> &vec, size_t l, size_t m, size_t r)
{
	size_t nl = m - l + 1;
	size_t nr = r - m;

	std::vector<int> left((vec.begin() + l), (vec.begin() + m + 1));
	std::vector<int> right((vec.begin() + m + 1), (vec.begin() + r + 1));

	int i = 0, j = 0;
	int k = l;

	while (i < nl && j < nr)
	{
		if (left[i] <= right[j])
		{
			vec[k] = left[i];
			i++;
		}
		else
		{
			vec[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < nl)
	{
		vec[k] = left[i];
		i++;
		k++;
	}

	while (j < nr)
	{
		vec[k] = right[j];
		j++;
		k++;
	}
}
