#pragma once



#include "Local.h"





struct ListRefer
{
    Bool Dummy;
};




typedef struct
{
    ListNode* First;


    ListNode* Last;



    Int Count;



    Object Refer;


} List;





ListNode* List_Node(List* this, Object key);





Bool List_DeleteNodes(List* this);








Object ListNode_New();



Bool ListNode_Delete(Object o);







Object ListRefer_New();



Bool ListRefer_Delete(Object o);