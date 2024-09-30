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

    /*
    �ϲ�K����������(leetcode23)��
    1.����˼·����Ҫ��ȡ���������е�ͷ�����Сֵ��Ȼ�����Сֵ������ȡ��ͷ��㣬������һ���ڵ㼨Ч�ϲ�
    2.Ҫ��ȡ��������Сֵ�����������ȶ��У�С���ѣ���ÿ��ȡС���ѵ�top�����кϲ�
    3.�ϲ����߼���������������ϲ������
    4.��Leetcode�У�list�п����ǿյģ��������������С����ǰ�����пմ���
    */
    static ListNode* MergeKLists(std::vector<ListNode*>& lists);
    bool operator()(ListNode* l1, ListNode* l2) { return l1->nVal > l2->nVal; }

    /*
    K��һ�鷭ת����(leetcode25)��
    1.�ȷ�תK��������ݹ���ȥ
    2.�ȼ��㳤�ȣ��������K����ֱ�ӷ���ԭ��������
    */
    static ListNode* ReverseKGroup(ListNode* head, int k);
};

