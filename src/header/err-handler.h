#ifndef _DATASTRUCT_IN_C_ERR_HANDLER_H_
#define _DATASTRUCT_IN_C_ERR_HANDLER_H_

#define DIAGNOSTIC_INFO(FUNC) ({printf("Error at line %d\nAt function %s\nAt file %s\n", __LINE__,FUNC, __FILE__);})

#endif // !_DATASTRUCT_IN_C_ERR_HANDLER_H_
