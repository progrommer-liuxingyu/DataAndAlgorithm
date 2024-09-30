#pragma once

// 先定义链表节点
typedef struct _LIST_NODE_
{
    int nVal = 0;
    _LIST_NODE_* pNext = nullptr;
    _LIST_NODE_(int value) :nVal(value) {}
    _LIST_NODE_() = default;
}ListNode, *PListNode;

typedef struct _TREE_NODE_
{
    int nVal = 0;
    _TREE_NODE_* pLeft = nullptr, * pRight = nullptr;
    _TREE_NODE_(int value) :nVal(value) {}
    _TREE_NODE_() = default;
}TreeNode, *PTreeNode;

