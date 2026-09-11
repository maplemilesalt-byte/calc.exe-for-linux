#ifndef CALC_LINUX_PLATFORM_H
#define CALC_LINUX_PLATFORM_H

/* Small compatibility layer for the experimental Linux port. */

#include <stddef.h>
#include <stdint.h>

typedef int BOOL;
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef uint32_t COLORREF;

#endif /* CALC_LINUX_PLATFORM_H */
