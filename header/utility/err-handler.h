#ifndef __DS_IN_C_ERR_HANDLER_H__
#define __DS_IN_C_ERR_HANDLER_H__

typedef struct EHandler EHandler;

enum EXCEPTION_TYPE {
  NULL_POINTER_EXCEP,
  OUT_OF_BOUND_EXCEP,
};

EHandler *e_handler_new();

int got_exception(EHandler *handler);

#define create_error_handler(name)                                             \
  __attribute__((cleanup(free_handler))) name = e_handler_new();

void free_handler(EHandler *handler);

#endif // !__DS_IN_C_ERR_HANDLER_H__
