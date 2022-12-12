#include <stdlib.h>



#include "Exit.h"



Bool Exit(Int code)
{
    int t = (int)code;
    
    exit(t);


    return true;
}