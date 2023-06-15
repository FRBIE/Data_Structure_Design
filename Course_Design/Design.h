#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct EMP
{
    int no;//职工号
    char name[20];//姓名
    int depno;//部门号
    double salary;//工资
    struct emp *next;
}EMP,*EMPLINK;

