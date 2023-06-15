#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct EMP
{
    long long int no;//职工号
    char name[20];//姓名
    int depno;//部门号
    double salary;//工资
    char introduction[100];//简介
    struct EMP *next;
}EMP,*EMPList;

//菜单
/**
 * 1.录入职工信息
 * 2.显示职工信息
 * 3.查询职工信息
 * 4.修改职工信息
 * 5.删除职工信息
 * 6.显示排序后的职工信息
 * 7.各个部门职工数量
 * 8.退出
*/
void menu()
{
    printf("**********职工信息管理系统**********\n");
    printf("**********1.录入职工信息************\n");
    printf("**********2.显示职工信息************\n");
    printf("**********3.查询职工信息************\n");
    printf("**********4.修改职工信息************\n");
    printf("**********5.删除职工信息************\n");
    printf("**********6.显示排序后的职工信息****\n");
    printf("**********7.各个部门职工数量********\n");
    printf("**********8.退出*********************\n");
    printf("请输入你的选择：\n");
}

//职工表初始化
void InitList(EMPList &L)
{
    L = (EMP*)malloc(sizeof(EMP));
    L->next = NULL;
}
//添加职工信息
void AddEMP(EMPList &L)
{
    EMP *p = (EMP*)malloc(sizeof(EMP));
    printf("请输入你要添加的职工号：\n");
    scanf("%lld",&p->no);
    printf("请输入你要添加的职工姓名：\n");
    scanf("%s",p->name);
    printf("请输入你要添加的职工部门号：\n");
    scanf("%d",&p->depno);
    printf("请输入你要添加的职工工资：\n");
    scanf("%lf",&p->salary);
    printf("请输入你要添加的职工简介：\n");
    scanf("%s",&p->introduction);
    printf("添加成功！\n");
    EMP *q = L;
    while(q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    p->next = NULL;
}
//显示职工信息
void ShowEMP(EMPList &L)
{
    EMP *p = L->next;
    printf("职工号\t\t姓名\t\t部门号\t\t工资\t\t简介\n");
    while(p != NULL)
    {
        printf("%lld\t%s\t\t%d\t\t%lf\t%s\n",p->no,p->name,p->depno,p->salary,p->introduction);
        p = p->next;
    }
}
//从emp032.txt文件中读取职工信息
void ReadEMP(EMPList &L)
{
    FILE *fp;
    fp = fopen("emp032.txt","r");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    while(!feof(fp))
    {
        EMP *p = (EMP*)malloc(sizeof(EMP));
        fscanf(fp,"%lld%s%d%lf%s",&p->no,p->name,&p->depno,&p->salary,p->introduction);
        EMP *q = L;
        while(q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->next = NULL;
    }
    printf("读取成功！\n");
    fclose(fp);
}
//将职工信息写入emp032.txt文件中
void WriteEMP(EMPList &L)
{
    FILE *fp;
    fp = fopen("emp032.txt","w");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    EMP *p = L->next;
    while(p != NULL)
    {
        fprintf(fp,"%lld\t%s\t%d\t%lf\t%s\n",p->no,p->name,p->depno,p->salary,p->introduction);
        p = p->next;
    }
    printf("写入成功！\n");
    fclose(fp);
}
//根据输入的部门号和姓名查询职工信息
void SearchEMP(EMPList &L)
{
    int depno;
    char name[20];
    printf("请输入你要查询的职工部门号：\n");
    scanf("%d",&depno);
    printf("请输入你要查询的职工姓名：\n");
    scanf("%s",name);
    EMP *p = L->next;
    while(p != NULL)
    {
        if(p->depno == depno && strcmp(p->name,name) == 0)
        {
            printf("职工号\t\t姓名\t\t部门号\t\t工资\t\t简介\n");
            printf("%lld\t%s\t\t%d\t\t%lf\t%s\n",p->no,p->name,p->depno,p->salary,p->introduction);
            break;
        }
        p = p->next;
    }
    if(p == NULL)
    {
        printf("没有找到该职工信息！\n");
    }
}
int main()
{
    EMPList L;
    InitList(L);
    //AddEMP(L);
    ReadEMP(L);
    ShowEMP(L);
    SearchEMP(L);
    SearchEMP(L);
    WriteEMP(L);
    system("pause");
    return 0;
}