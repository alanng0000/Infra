#include "ListIter.h"



InfraClassNew(ListIter)




Bool ListIter_Init(Object this)
{
    return true;
}




Bool ListIter_Final(Object this)
{
    return true;
}




Bool ListIter_SetFirstNode(Object this, ListNode* firstNode)
{
    ListIter* m = CastPointer(this);



    m->CurrentNode = null;


    m->FirstNode = firstNode;


    m->First = true;


    return true;
}



Bool ListIter_Next(Object this)
{
    ListIter* m = CastPointer(this);


    if (m->First)
    {
        if (m->FirstNode == null)
        {
            return false;
        }


        m->CurrentNode = m->FirstNode;


        m->First = false;


        return true;
    }


    if (m->CurrentNode->Next == null)
    {
        return false;
    }


    m->CurrentNode = m->CurrentNode->Next;


    return true;
}



Object ListIter_Value(Object this)
{
    ListIter* m = CastPointer(this);



    return m->CurrentNode->Value;
}