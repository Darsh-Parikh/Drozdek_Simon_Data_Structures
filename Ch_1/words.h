#ifndef WORDS_H
#define WORDS_H

#include<stdio.h>
#include<string.h>

typedef char dbkeytype[21];
typedef int dbdatatype;

#define comparedbkey(s1, s2)   ((int)strcmp(s1, s2))
#define copydbkey(s1, s2)      (strcopy(s1, s2))
#define copydbdata(d1, d2)     (d2 = d1)

#endif