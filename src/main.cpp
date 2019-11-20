#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using clase = std::set<int>;

int main(int argc, char *argv[])
{
	// Las letras fueron reemplazadas por su número de orden por -1
	// c -> -3

	std::vector<std::set<int>> A=
	{
		{1,2,11,17,3,4,8,5,12,6,7,15,-1},
		{2,27,4,5,6,25,11,7,23,13,9,26,-2},
		{2,6,23,5,19,8,4,17,11,13,-3},
		{1,15,3,2,5,9,4,6,11,24,7,28,-1},
		{30,23,31,2,37,5,9,38,17,-3},
		{14,2,25,13,7,9,16,17,26,27,4,-5},
		{2,28,16,5,30,25,1,33,15,4,29,-4},
		{25,7,8,22,26,28,23,5,24,10,-6},
		{12,16,17,11,15,13,40,37,14,18,-1},
		{8,42,41,16,17,11,15,14,21,3,-7}
	};

	for(size_t ii = 0; ii < A.size(); ++ii)
	{
		for(size_t jj = ii; jj < A.size(); ++jj)
		{
			if(ii == jj)
			{
				continue;
			}
			std::vector<int> inter;
			// Esta cosas pone la intersección en inter.
			std::set_intersection(
					A[ii].begin(),
					A[ii].end(),
					A[jj].begin(),
					A[jj].end(),
					std::back_inserter(inter));

			if(inter.size() == 0)
			{
				std::cout << 'A' << ii+1 << " no colisiona con A" << jj+1 << '\n';
			}
		}
	}

	return 0;
}
