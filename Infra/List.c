#include "List.h"




ClassNew(List)





Bool List_Init(Object this)
{
    List* m = CastPointer(this);




    Object o = ListRefer_New();



    m->Refer = o;



    return true;
}





Bool List_Final(Object this)
{
    List* m = CastPointer(this);



    List_DeleteNodes(m);




    Object refer = m->Refer;



    ListRefer_Delete(refer);




    return true;
}







Int List_GetCount(Object this)
{
    List* list = CastPointer(this);



    return list->Count;
}




Object List_Add(Object this, Object item)
{
    List* list = CastPointer(this);




    Object o = ListNode_New();




    ListNode* node = CastPointer(o);




    node->Refer = list->Refer;




    node->Value = item;





    if (!(list->Last == null))
    {

        node->Previous = list->Last;




        list->Last->Next = node;
    }




    if (list->First == null)
    {
        list->First = node;
    }




    
    list->Last = node;





    list->Count++;





    Object ret = (Object)node;



    return ret;
}





Object List_Insert(Object this, Object key, Object item)
{
    List* list = CastPointer(this);




    ListNode* t = List_Node(list, key);



    if (t == null)
    {
        return null;
    }





    Object o = ListNode_New();



    ListNode* node = CastPointer(o);




    node->Refer = list->Refer;



    node->Value = item;





    if (list->First == t)
    {
        list->First = node;
    }





    if (t->Previous != null)
    {
        t->Previous->Next = node;



        node->Previous = t->Previous;
    }





    node->Next = t;



    t->Previous = node;





    list->Count++;




    Object ret = (Object)node;



    return ret;
}





Bool List_Remove(Object this, Object key)
{
    List* list = CastPointer(this);




    ListNode* node = List_Node(list, key);




    if (node == null)
    {
        return false;
    }




    if (list->First == node)
    {
        list->First = node->Next;
    }





    if (list->Last == node)
    {
        list->Last = node->Previous;
    }






    if (node->Next != null)
    {
        node->Next->Previous = node->Previous;
    }





    if (node->Previous != null)
    {
        node->Previous->Next = node->Next;
    }





    node->Refer = null;





    Object u = CastInt(node);




    ListNode_Delete(u);





    list->Count --;




    return true;
}




Bool List_Contain(Object this, Object key)
{
    List* m = CastPointer(this);




    ListNode* node = List_Node(m, key);




    if (node == null)
    {
        return false;
    }




    return true;
}





Bool List_Clear(Object this)
{
    List* list = CastPointer(this);




    List_DeleteNodes(list);





    list->First = null;




    list->Last = null;




    list->Count = 0;




    Object t = list->Refer;




    Object o = ListRefer_New();



    Object refer = o;




    ListRefer_Delete(t);



    list->Refer = refer;




    return true;
}





Object List_Get(Object this, Object key)
{
    List* list = CastPointer(this);



    ListNode* node = List_Node(list, key);



    if (node == null)
    {
        return null;
    }



    Object t = node->Value;



    Object ret = t;


    return ret;
}




Bool List_Set(Object this, Object key, Object value)
{
    List* m = CastPointer(this);


    ListNode* node = List_Node(m, key);


    if (node == null)
    {
        return false;
    }


    node->Value = value;


    return true;
}





Bool List_Iter(Object this, Object iter)
{
    List* m = CastPointer(this);



    ListIter_SetFirstNode(iter, m->First);



    return true;
}




ListNode* List_Node(List* this, Object key)
{
    ListNode* node = CastPointer(key);




    if (!(node->Refer == this->Refer))
    {
        return null;
    }




    ListNode* ret = node;


    return ret;
}




Bool List_DeleteNodes(List* this)
{
    ListNode* current = this->First;



    ListNode* next = null;



    Object u = null;



    while (current != null)
    {
        next = current->Next;



        u = CastInt(current);



        ListNode_Delete(u);



        current = next;
    }



    return true;
}





ClassNew(ListNode)




ClassNew(ListRefer)
