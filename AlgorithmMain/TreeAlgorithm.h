#pragma once
#include <vector>
#include "PubStruct.h"

typedef std::vector<int>::iterator VECIT;

class TreeAlgorithm
{
public:
    // 根据中序+前序构建二叉树
    static TreeNode* BuildTreeByPreAndInOrd(std::vector<int> vecPre, std::vector<int> vecIn);
    static TreeNode* _BuildTreeByPreAndInOrd(VECIT& itCur, VECIT itPreE, VECIT itS, VECIT itEnd);

    // 根据中序+后序构建二叉树
    static TreeNode* BuildTreeByBackAndInOrd(std::vector<int> vecBack, std::vector<int> vecIn);
    static TreeNode* _BuildTreeByBackAndInOrd(std::vector<int>::reverse_iterator& itCur, std::vector<int>::reverse_iterator itBackE, VECIT itS, VECIT itEnd);
};

