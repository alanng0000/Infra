#include "Main.h"




int main()
{
    Infra_Form_Init();




    Object test;



    test = Test_New();



    Test_Init(test);



    Test_Execute(test);



    Test_Final(test);



    Delete(test);





    return true;
}