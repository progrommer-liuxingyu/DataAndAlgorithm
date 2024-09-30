#include <iostream>
#include <vector>
#include <algorithm>
#include "ListAlgorithm.h"
#include "TreeAlgorithm.h"
using namespace std;

int main()
{
    vector<int> vecBack = { 11, 12, 7, 4, 2, 8, 5, 9, 10, 6, 3, 1 };
	vector<int> vecIn = { 4, 11, 7, 12, 2, 1, 5, 8, 3, 9, 6, 10 };

    auto ret = TreeAlgorithm::BuildTreeByBackAndInOrd(vecBack, vecIn);

    return 0;
}

