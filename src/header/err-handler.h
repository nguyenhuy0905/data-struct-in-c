#ifndef _DATASTRUCT_IN_C_ERR_HANDLER_H_
#define _DATASTRUCT_IN_C_ERR_HANDLER_H_

/* Simply prints out the line number, function and the file from which the error occured */
#define DIAGNOSTIC_INFO(FUNC) ({perror("\033[31mError");\
  printf("\033[31mAt line %d\nAt function %s\nAt file %s\n", __LINE__,FUNC, __FILE__);})

#endif // !_DATASTRUCT_IN_C_ERR_HANDLER_H_
