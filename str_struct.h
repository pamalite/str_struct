#ifndef STR_STRUCT_H_
#define STR_STRUCT_H_

#include <stdbool.h>

typedef struct STR_S {
	char *str;
	int length;

    void (*set) (struct STR_S *, const char *);
    void (*setWithFormat) (struct STR_S *, const char *, ...);
    void (*toUpper) (struct STR_S *);
    void (*toLower) (struct STR_S *);
    bool (*isEquals) (struct STR_S *, struct STR_S *);
    bool (*isEqualsIgnoreCase) (struct STR_S *, struct STR_S *);
    void (*leftTrim) (struct STR_S *);
    void (*rightTrim) (struct STR_S *);
    void (*trim) (struct STR_S *);
    struct STR_S * (*sub) (struct STR_S *, int, int);
    void (*append) (struct STR_S *, struct STR_S *);
    bool (*has) (struct STR_S *, const char *);
    int (*find) (struct STR_S *, const char *, int **);
    void (*replace) (struct STR_S *, const char *, const char *);
} Str;

Str *Str_new();
Str *Str_newWith(const char *);
Str *Str_newWithFormat(const char *, ...);
void Str_dispose(Str *);


#endif /* STR_STRUCT_H_ */
