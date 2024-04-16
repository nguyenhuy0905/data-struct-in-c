#ifndef _DATASTRUCT_IN_C_ERR_HANDLER_H_
#define _DATASTRUCT_IN_C_ERR_HANDLER_H_

#define DIAGNOSTIC_INFO ({printf("Error at line %d\nAt file %s\n", __LINE__, __FILE__);})

#endif // !_DATASTRUCT_IN_C_ERR_HANDLER_H_
