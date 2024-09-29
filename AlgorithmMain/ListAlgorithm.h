#pragma once
#include "PubStruct.h"
#include <vector>

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
};

