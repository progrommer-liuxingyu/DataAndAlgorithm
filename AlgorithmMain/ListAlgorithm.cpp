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

/*
合并K个升序链表的思路：
1.可以用优先队列，采用小顶堆，每次取小顶堆的top，进行合并
2.合并的逻辑跟两个升序两表合并差不多了
3.在Leetcode中，list有可能是空的，所以在最初插入小顶堆前先做判空处理
*/
ListNode* ListAlgorithm::MergeKLists(std::vector<ListNode*>&lists)
{
    ListNode* pHead = new ListNode, ** pTail = &pHead->pNext;
    std::priority_queue<ListNode*, std::vector<ListNode*>, ListAlgorithm>pqTemp;
    for (auto list : lists)
    {
        if (list)
            pqTemp.push(list);
    }
    while (pqTemp.size() > 1)
    {
        ListNode* pTop = pqTemp.top();
        pqTemp.pop();
        (*pTail) = pTop;
        pTail = &(*pTail)->pNext;
		pTop = pTop->pNext;
        if (pTop)
            pqTemp.push(pTop);
    }
    if (pqTemp.size() == 1)
        *pTail = pqTemp.top();
    return pHead->pNext;
}

