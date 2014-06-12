#ifndef _SIMPLE_CONVOLVER_H_
#define _SIMPLE_CONVOLVER_H_

#ifdef __cplusplus
extern "C" {
#endif

void * convolver_create(int preset_no);
void convolver_delete(void *);
void convolver_clear(void *);
short convolver_process(void *, short);

#ifdef __cplusplus
}
#endif

#endif
