#ifndef _COROUTINE_H_
#define _COROUTINE_H_

enum CoroutineStatus { COROUTINE_DEAD, COROUTINE_READY, COROUTINE_RUNNING, COROUTINE_SUSPEND };

typedef struct schedule schedule;
typedef void(*coroutine_func)(schedule * s, void * ud);

schedule *coroutine_open();
void coroutine_close(schedule *s);
int coroutine_new(schedule *s, coroutine_func , void *ud);
void coroutine_resume(schedule *s, int id);
void coroutine_yield(schedule *s);
int coroutine_status(schedule *s, int id);
int coroutine_running(schedule *s);

#endif // !_COROUTINE_H_
