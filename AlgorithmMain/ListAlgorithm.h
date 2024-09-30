#pragma once
#include "PubStruct.h"
#include <vector>
#include <queue>

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

    /*
    合并K个升序链表(leetcode23)：
    1.基本思路就是要获取左右链表中的头结点最小值，然后对最小值的链表取出头结点，再用下一个节点绩效合并
    2.要获取数组中最小值，可以用优先队列（小顶堆），每次取小顶堆的top，进行合并
    3.合并的逻辑跟两个升序两表合并差不多了
    4.在Leetcode中，list有可能是空的，所以在最初插入小顶堆前先做判空处理
    */
    static ListNode* MergeKLists(std::vector<ListNode*>& lists);
    bool operator()(ListNode* l1, ListNode* l2) { return l1->nVal > l2->nVal; }

    /*
    K个一组翻转链表(leetcode25)：
    1.先翻转K个，后面递归下去
    2.先计算长度，如果不够K个，直接返回原来的链表
    */
    static ListNode* ReverseKGroup(ListNode* head, int k);
};

