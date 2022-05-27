#include <stdio.h>
#include <stdarg.h>
#include "time.h"
#include <string.h>
#include <stdlib.h>
#include "logger.h"
FILE *file ;
static int SESSION_TRACKER;

char* print_time()
{
    int size = 0;
    time_t time;
    char *buf;
    
    time = time(NULL);
    
    char *timestr = asctime(localtime(&time));
    timestr[strlen(timestr) - 1] = 0;
    
    size = strlen(timestr) + 1 + 2;
    buf = (char*)malloc(size);
    
    memset(buf, 0x0, size);
    snprintf(buf, size, "[%s]", timestr);
   
    return buf;
}

void log_print(char* filename, int line, char *fmt,...)
{
    va_list list;
    char *p, *r;
    int e;

    if(SESSION_TRACKER > 0)
      file = fopen ("log/log.txt", "a+");
    else
      file = fopen ("log/log.txt", "w");
    
    fprintf(file,"%s ",print_time());
    fprintf(file,"[%s][line: %d] ", filename, line);
    va_start(list, fmt);

    for (p = fmt; *p; ++p)
    {
        if (*p != '%')
        {
            fputc(*p, file);
        }
        else
        {
            switch (*++p)
            {
            case 's':
            {
                r = va_arg(list, char *);

                fprintf(file,"%s", r);
                continue;
            }

            case 'd':
            {
                e = va_arg(list, int);
                fprintf(file, "%d", e);
                continue;
            }

            default:
                fputc(*p, file);
            }
        }
    }
    va_end(list);
    fputc('\n', file);
    SESSION_TRACKER++;
    fclose(file);
}
