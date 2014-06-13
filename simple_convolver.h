#ifndef _SIMPLE_CONVOLVER_H_
#define _SIMPLE_CONVOLVER_H_

#ifdef __cplusplus
extern "C" {
#endif

void * convolver_create(int preset_no);
void convolver_delete(void *);
void convolver_clear(void *);
int convolver_get_free_count(void *);
void convolver_write(void *, short);
int convolver_ready(void *);
short convolver_read(void *);

#ifdef __cplusplus
}
#endif

#endif
