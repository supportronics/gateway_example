#ifndef _VERSION_H_
#define _VERSION_H_

#define SW_VERSION_NAME     BUILD_VERSION_STRING(SW_VERSION_MAJOR,SW_VERSION_MINOR,SW_VERSION_REVISION)  
#define SW_VERSION_MAJOR    0                       
#define SW_VERSION_MINOR    0                       
#define SW_VERSION_REVISION 2                       


#define     QUOTE(x) #x
#define     BUILD_VERSION_STRING(x,y,z) "V" QUOTE(x) "." QUOTE(y) "." QUOTE(z)
#endif

