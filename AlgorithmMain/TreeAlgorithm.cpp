#include "TreeAlgorithm.h"

TreeNode* TreeAlgorithm::BuildTreeByPreAndInOrd(std::vector<int> vecPre, std::vector<int> vecIn)
{
    VECIT itPreS = vecPre.begin();
    return _BuildTreeByPreAndInOrd(itPreS, vecPre.end(), vecIn.begin(), vecIn.end());
}

TreeNode* TreeAlgorithm::_BuildTreeByPreAndInOrd(VECIT& itCur, VECIT itPreE, VECIT itS, VECIT itEnd)
{
    if (itCur == itPreE || itS == itEnd)
        return nullptr;

    auto it = find(itS, itEnd, *itCur);
    if (itEnd == it)
        return nullptr;

    TreeNode* pRet = new TreeNode(*itCur);
    ++itCur;
    // 顺序不能反
    pRet->pLeft = _BuildTreeByPreAndInOrd(itCur, itPreE, itS, it);
    pRet->pRight = _BuildTreeByPreAndInOrd(itCur, itPreE, it + 1, itEnd);

    return pRet;
}

TreeNode* TreeAlgorithm::BuildTreeByBackAndInOrd(std::vector<int> vecBack, std::vector<int> vecIn)
{
    auto itCur = vecBack.rbegin();
    return _BuildTreeByBackAndInOrd(itCur, vecBack.rend(), vecIn.begin(), vecIn.end());
}

TreeNode* TreeAlgorithm::_BuildTreeByBackAndInOrd(std::vector<int>::reverse_iterator& itCur, std::vector<int>::reverse_iterator itBackE, VECIT itS, VECIT itEnd)
{
    if (itCur == itBackE || itS == itEnd)
        return nullptr;

    auto it = find(itS, itEnd, *itCur);
    if (it == itEnd)
        return nullptr;

    TreeNode* pRet = new TreeNode(*itCur);
    ++itCur;
    // 顺序不能反：因为是后序遍历，所以靠近根节点的是右孩子
    pRet->pRight = _BuildTreeByBackAndInOrd(itCur, itBackE, it + 1, itEnd);
    pRet->pLeft = _BuildTreeByBackAndInOrd(itCur, itBackE, itS, it);

    return pRet;
}
