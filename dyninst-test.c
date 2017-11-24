//
// Created by vaibhav on 11/15/17.
//
#include <stdio.h>
#include <stdarg.h>

int myprintf(const char *fmt, ...){
 int n;
 char *p, *np;
 va_list ap;
 va_start(ap, fmt);
 vprintf(fmt, ap);
 va_end(ap);
}

int testfn() {
    myprintf("Hello World!\n");
		int x = 1;
    int a = 1;
		a = 1 + x;
		if(a < 3) 
      myprintf("less\n");
		else myprintf("greater than or equal to\n");
    return 0;
}

int main() { testfn(); return 0; }
