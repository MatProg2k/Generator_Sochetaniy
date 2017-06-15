#include "stdafx.h"                       
#include <iostream>
#include <ctime>
#include <locale>
#include <fstream>
#include <vector>

__int64 Factorial(int number)
{
	if ((number == 1) | (number == 0))
	{
		return 1;
	}
	return Factorial(number - 1) * number;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	
	int sizeSet;
	int sizeCombinations;
	int sizeSubset;
	int m;
	const int maskaForBit = 0x1;
	std::vector<int> set;
	std::vector<std::vector<int>> combinations;
	
	//Данные
	sizeSet = 4;
	m = 3;
	sizeSubset = (int)pow(2, sizeSet);
	sizeCombinations = Factorial(sizeSet) / (Factorial(sizeSet - m) * Factorial(m));
	for (int i = 0; i < sizeSet; i++)
	{
		set.push_back(i);
	}

	//Генератор
	for (int i = 0; i < sizeSubset; i++)
	{
		int tempMask = i;
		std::vector<int> temp;
		for (int j = 0; j < sizeSet; j++)
		{
			if (tempMask & maskaForBit)
			{
				temp.push_back(j);
			}
			tempMask >>= 1;
		}

		if (temp.size() != m)
		{
			continue;
		}
		else
		{
			combinations.push_back(temp);
		}
	}

	//Вывод
	std::cout << "Сочетания:" << std::endl;
	for (int i = 0; i < sizeCombinations; i++)
	{
		std::cout << "{ ";
		for (int j = 0; j < combinations[i].size(); j++)
		{
			std::cout << char(97 + combinations[i][j]) << " ";
		}
		std::cout << "}" << std::endl;
	}

	system("pause");
	return 0;
}

