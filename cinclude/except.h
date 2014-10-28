#ifndef EXCPET_INCLUDED
#define EXCPET_INCLUDED

#include <setjmp.h>

typedef struct {
    const char *reason;
} except_t;

typedef struct except_frame_ {
    except_frame_ *prev;
    jmp_buf env;
    const char *file;
    int line;
    const except_t *exception;
} except_frame;

extern except_frame *except_stack;



void except_raise(const except_t *e, const char *file, int line);

#define RAISE(e) except_raise(&(e), __FILE__, __LINE__)
#define RERAISE except_raise(except_frame.exception, \
        except_frame.file, except_frame.line)

#endif
