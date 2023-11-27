#ifndef _MYERROR_H
#define _MYERROR_H

#include <stdlib.h>

#define PRINT_ERROR(MESSAGE)\
    printf("Error in File: %s, in Function: %s, at Line: %d\n\
Errormessage: %s\n", __FILE__, __func__,__LINE__, (MESSAGE));\
    // return EXIT_FAILURE; 
    
#endif