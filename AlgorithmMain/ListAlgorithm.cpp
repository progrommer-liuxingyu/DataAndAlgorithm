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
�ϲ�K�����������˼·��
1.���������ȶ��У�����С���ѣ�ÿ��ȡС���ѵ�top�����кϲ�
2.�ϲ����߼���������������ϲ������
3.��Leetcode�У�list�п����ǿյģ��������������С����ǰ�����пմ���
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

