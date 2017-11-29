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

int testfn(int x) {
    myprintf("Hello World!\n");
    int a = 1;
		a = x;
		x = x < 3 ? 3 : x;
		if( (a + x) < 3)
      myprintf("ITE effect was lost OR x >= 3\n");
		else myprintf("ITE effect present\n");
    return 0;
}

int main(int argc, char *argv[]) { 
	if(argc < 2) {
		printf("usage: dyninst-test <integer>\n");
		return 1;
	}
	testfn(atoi(argv[1])); 
	return 0; 
}
