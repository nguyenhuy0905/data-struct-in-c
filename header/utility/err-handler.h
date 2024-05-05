#ifndef __DS_IN_C_ERR_HANDLER_H__
#define __DS_IN_C_ERR_HANDLER_H__

typedef struct _e_handler e_handler;

enum EXCEPTION_TYPE {
  NULL_POINTER_EXCEP,
  OUT_OF_BOUND_EXCEP,
};

e_handler *e_handler_new();

int got_exception(e_handler *handler);

#define create_error_handler(name)                                             \
  __attribute__((cleanup(free_handler))) name = e_handler_new();

void free_handler(e_handler *handler);

#endif // !__DS_IN_C_ERR_HANDLER_H__
