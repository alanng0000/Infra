#include "Local.h"





typedef struct
{
    Object Constants;


} Global;






Object Global_New();



Bool Global_Delete(Object o);




Bool Global_Init(Object this);



Bool Global_Final(Object this);