// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include "MultiThreadSorter.h"
#include "Timer.h"

using std::cin, std::cout, std::endl;

int main()
{
	setlocale(LC_ALL, "");
	size_t size = 0;
	cout << "Введите размер массива: ";
	cin >> size;
	srand(time(0));
	std::vector<int> v1;
	for (size_t i = 0; i < size; ++i)
	{
		v1.push_back(rand());
	}
	std::vector<int> v2(v1);

	Timer timer;

	MultiThreadSorter Sort;

	Sort.make_threads(true);
	timer.start();
	Sort(v1);
	timer.stop();
	cout << "Многопоточная сортировка заняла " << timer.duration().count() << "мс" << endl;

	Sort.make_threads(false);
	timer.start();
	Sort(v2);
	timer.stop();
	cout << "Однопоточная сортировка заняла " << timer.duration().count() << "мс" << endl;


	return 0;
}

