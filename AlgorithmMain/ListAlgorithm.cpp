#include "ListAlgorithm.h"

ListNode* ListAlgorithm::BuildListInsertTail(const std::vector<int>& vecData)
{
    ListNode* pRet = new ListNode, ** pTail = &pRet->pNext;
    for (int nVal : vecData)
    {
        *pTail = new ListNode(nVal);
        pTail = &(*pTail)->pNext;
    }
    return pRet->pNext;
}

ListNode* ListAlgorithm::MergeSortedList(ListNode* pListFirst, ListNode* pListSec)
{
    ListNode* pRet = new ListNode, ** pTail = &pRet->pNext;
    while (pListFirst && pListSec)
    {
        if (pListFirst->nVal < pListSec->nVal)
        {
            *pTail = pListFirst;
            pListFirst = pListFirst->pNext;
        }
        else
        {
            *pTail = pListSec;
            pListSec = pListSec->pNext;
        }
        pTail = &(*pTail)->pNext;
    }

    if (pListFirst)
        *pTail = pListFirst;
    else if (pListSec)
        *pTail = pListSec;
    
    return pRet->pNext;
}

ListNode* ListAlgorithm::MergeListByRecursive(ListNode* pListFirst, ListNode* pListSec)
{
    if (!pListSec)
        return pListFirst;
    if (!pListFirst)
        return pListSec;

    if (pListFirst->nVal <= pListSec->nVal) 
    {
        pListFirst->pNext = MergeListByRecursive(pListFirst->pNext, pListSec);
        return pListFirst;
    }

    pListSec->pNext = MergeListByRecursive(pListFirst, pListSec->pNext);
    return pListSec;
}

ListNode* ListAlgorithm::ReverseList(ListNode* pList)
{
    ListNode* pRet = nullptr, * pCur = pList, * pNext = nullptr;
    while (pCur)
    {
        pNext = pCur->pNext;
        pCur->pNext = pRet;
        pRet = pCur;
        pCur = pNext;
    }
    return pRet;
}

