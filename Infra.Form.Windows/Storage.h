#include <direct.h>


#include <sys/types.h>

#include <sys/stat.h>


#include <stdio.h>



#include "Local.h"




#include <Infra.Form.Infra/Public.h>






typedef struct __stat64 StorageStat;




typedef struct
{
    Object Name;


    Int Mode;


    FILE* File;


    StorageStat* Status;


} Storage;