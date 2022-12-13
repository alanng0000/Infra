#pragma once



#include "Public.h"






struct ListRefer;


typedef struct ListRefer ListRefer;




struct ListNode;


typedef struct ListNode ListNode;




struct ListNode
{
    ListNode* Previous;


    ListNode* Next;



    Object Refer;



    Object Value;
};




Bool ListIter_SetFirstNode(Object this, ListNode* firstNode);