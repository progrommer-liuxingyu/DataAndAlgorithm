#pragma once
#include <vector>
#include "PubStruct.h"

typedef std::vector<int>::iterator VECIT;

class TreeAlgorithm
{
public:
    // ��������+ǰ�򹹽�������
    static TreeNode* BuildTreeByPreAndInOrd(std::vector<int> vecPre, std::vector<int> vecIn);
    static TreeNode* _BuildTreeByPreAndInOrd(VECIT& itCur, VECIT itPreE, VECIT itS, VECIT itEnd);

    // ��������+���򹹽�������
    static TreeNode* BuildTreeByBackAndInOrd(std::vector<int> vecBack, std::vector<int> vecIn);
    static TreeNode* _BuildTreeByBackAndInOrd(std::vector<int>::reverse_iterator& itCur, std::vector<int>::reverse_iterator itBackE, VECIT itS, VECIT itEnd);
};

