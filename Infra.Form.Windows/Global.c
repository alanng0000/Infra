#include "Global.h"




ClassNew(Global)





Bool Global_Init(Object this)
{
    Global* m = CastPointer(this);



    Object constants;
    
    

    constants = Constants_New();



    Constants_Init(constants);



    m->Constants = constants;



    return true;
}





Bool Global_Final(Object this)
{
    Global* m = CastPointer(this);



    Object constants = m->Constants;



    Constants_Final(constants);



    Constants_Delete(constants);



    return true;
}





Object Global_Constants(Object this)
{
    Global* m = CastPointer(this);


    return m->Constants;
}





Object Infra_Form_Global_Data;




Object Infra_Form_Global()
{
    return Infra_Form_Global_Data;
}




Bool Infra_Form_Init()
{
    Object global;
    
    
    
    global = Global_New();



    Global_Init(global);
    



    Infra_Form_Global_Data = global;



    return true;
}




Bool Infra_Form_Final()
{
    Object global = Infra_Form_Global_Data;



    Global_Final(global);



    Global_Delete(global);



    Infra_Form_Global_Data = null;
    


    return true;
}