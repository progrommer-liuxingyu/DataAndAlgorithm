#pragma once
#include "PubStruct.h"
#include <vector>

class ListAlgorithm
{
public:
    // 尾插法构建链表
    static ListNode* BuildListInsertTail(const std::vector<int>& vecData);

    // 合并两个递增有序链表(常规合并)
    static ListNode* MergeSortedList(ListNode* pListFirst, ListNode* pListSec);
    // 合并两个递增有序链表(递归合并，比较容易理解)
    static ListNode* MergeListByRecursive(ListNode* pListFirst, ListNode* pListSec);

    // 反转链表
    static ListNode* ReverseList(ListNode* pList);
};

