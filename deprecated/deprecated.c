#include<stdio.h>
#include<unistd.h>
#include<string.h>
void foo()__attribute__((deprecated));void foo(){write(1,"foo\n",strlen("foo\n"));}typedef int T __attribute__((deprecated));int g_var __attribute__((deprecated))=3231&312321;int main(){foo();T x __attribute__((unused));printf("%d\n",g_var);return 0;}
