#pragma once

// �ȶ�������ڵ�
typedef struct _LIST_NODE_
{
    int nVal = 0;
    _LIST_NODE_* pNext = nullptr;
    _LIST_NODE_(int value) :nVal(value) {}
    _LIST_NODE_() = default;
}ListNode, *PListNode;

