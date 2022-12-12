#include "Test.h"




ClassNew(Test)




Bool Test_Init(Object this)
{
    return true;
}



Bool Test_Final(Object this)
{
    return true;
}




Bool Test_Execute(Object this)
{
    Object testStorage;


    testStorage = TestStorage_New();



    TestStorage_Init(testStorage);



    TestStorage_Execute(testStorage);



    TestStorage_Final(testStorage);



    Delete(testStorage);


    return true;
}