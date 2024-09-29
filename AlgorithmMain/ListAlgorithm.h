#pragma once
#include "PubStruct.h"
#include <vector>
#include <queue>

class ListAlgorithm
{
public:
    // β�巨��������
    static ListNode* BuildListInsertTail(const std::vector<int>& vecData);

    // �ϲ�����������������(����ϲ�)
    static ListNode* MergeSortedList(ListNode* pListFirst, ListNode* pListSec);
    // �ϲ�����������������(�ݹ�ϲ����Ƚ��������)
    static ListNode* MergeListByRecursive(ListNode* pListFirst, ListNode* pListSec);

    // ��ת����
    static ListNode* ReverseList(ListNode* pList);

    // �ϲ�K����������leetcode23
    static ListNode* MergeKLists(std::vector<ListNode*>& lists);
    bool operator()(ListNode* l1, ListNode* l2) { return l1->nVal > l2->nVal; }
};

