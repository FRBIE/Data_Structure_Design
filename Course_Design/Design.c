#include"Design.h"

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
    printf("**********3.删除职工信息************\n");
    printf("**********4.修改职工信息************\n");
    printf("**********5.查找职工信息************\n");
    printf("**********6.显示排序后的职工信息****\n");
    printf("**********7.各个部门职工数量********\n");
    printf("**********8.退出*********************\n");
    printf("请输入你的选择：(1-8)\n");
}

//职工表初始化
void InitEMPList(EMPList &L)
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
    if(p == NULL)
    {
        printf("没有职工信息！\n");
        return;
    }
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
        return;
    }
    EMP *p = L;
    while(!feof(fp))
    {
        EMP *q = (EMP*)malloc(sizeof(EMP));
        fscanf(fp,"%lld%s%d%lf%s",&q->no,q->name,&q->depno,&q->salary,q->introduction);
        q->next = NULL;
        p->next = q;
        p = q;
    }
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
        return;
    }
    EMP *p = L->next;
    while(p != NULL)
    {
        fprintf(fp,"%lld\t%s\t%d\t%lf\t%s\n",p->no,p->name,p->depno,p->salary,p->introduction);
        p = p->next;
    }
    fclose(fp);
}

//根据输入的部门号和姓名查询职工信息并修改
void ModifyEMP(EMPList &L)
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
        return;//没有找到就结束该函数，不执行下面的修改操作
    }
    int choice;
    int loop=1;
    do{
         printf("请输入你要修改的信息：\n");
        printf("1.职工号\n");
        printf("2.姓名\n");
        printf("3.部门号\n");
        printf("4.工资\n");
        printf("5.简介\n");
        printf("6.退出\n");
        printf("请输入(1-6)\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("请输入你要修改的职工号：\n");
                scanf("%lld",&p->no);
                printf("修改成功！\n");
                break;
            case 2:
                printf("请输入你要修改的职工姓名：\n");
                scanf("%s",p->name);
                printf("修改成功！\n");
                break;
            case 3:
                printf("请输入你要修改的职工部门号：\n");
                scanf("%d",&p->depno);
                printf("修改成功！\n");
                break;
            case 4:
                printf("请输入你要修改的职工工资：\n");
                scanf("%lf",&p->salary);
                printf("修改成功！\n");
                break;
            case 5:
                printf("请输入你要修改的职工简介：\n");
                scanf("%s",p->introduction);
                printf("修改成功！\n");
                break;
            case 6:
                loop = 0;//不再修改
                break;
            default:
                printf("输入错误！\n");
                break;
        }        
    }while(loop);
}
//根据输入的部门号和姓名删除职工信息
void DeleteEMP(EMPList &L)
{
    int depno;
    char name[20];
    printf("请输入你要删除的职工部门号：\n");
    scanf("%d",&depno);
    printf("请输入你要删除的职工姓名：\n");
    scanf("%s",name);
    EMP *p = L;
    while(p->next != NULL)
    {
        if(p->next->depno == depno && strcmp(p->next->name,name) == 0)
        {
            EMP *q = p->next;
            p->next = q->next;
            free(q);
            printf("删除成功！\n");
            return;
        }
        p = p->next;
    }
    printf("没有找到该职工信息！\n");
}
//根据职工号查找职工信息
void SearchEMPno(EMPList &L)
{
    long long no;
    printf("请输入你要查询的职工号：\n");
    scanf("%lld",&no);
    EMP *p = L->next;
    while(p != NULL)
    {
        if(p->no == no)
        {
            printf("职工号\t\t姓名\t\t部门号\t\t工资\t\t简介\n");
            printf("%lld\t%s\t\t%d\t\t%lf\t%s\n",p->no,p->name,p->depno,p->salary,p->introduction);
        }
        p = p->next;
    }
    if(p == NULL)
    {
        printf("没有找到该职工信息！\n");
    }
}
//根据姓名查找职工信息
void SearchEMPname(EMPList &L)
{
    char name[20];
    printf("请输入你要查询的职工姓名：\n");
    scanf("%s",name);
    EMP *p = L->next;
    while(p != NULL)
    {
        if(strcmp(p->name,name) == 0)
        {
            printf("职工号\t\t姓名\t\t部门号\t\t工资\t\t简介\n");
            printf("%lld\t%s\t\t%d\t\t%lf\t%s\n",p->no,p->name,p->depno,p->salary,p->introduction);
        }
        p = p->next;
    }
    if(p == NULL)
    {
        printf("没有找到该职工信息！\n");
    }
}
//根据部门号查找职工信息
void SearchEMPdepno(EMPList &L)
{
    int depno;
    printf("请输入你要查询的职工部门号：\n");
    scanf("%d",&depno);
    EMP *p = L->next;
    while(p != NULL)
    {
        if(p->depno == depno)
        {
            printf("职工号\t\t姓名\t\t部门号\t\t工资\t\t简介\n");
            printf("%lld\t%s\t\t%d\t\t%lf\t%s\n",p->no,p->name,p->depno,p->salary,p->introduction);
        }
        p = p->next;
    }
    if(p == NULL)
    {
        printf("没有找到该职工信息！\n");
    }
}
//根据多种关键字查找职工信息
void SearchEMP(EMPList &L)
{
    int choice;
    int loop=1;
    do{
        printf("请输入你要查询的方式：\n");
        printf("1.职工号\n");
        printf("2.姓名\n");
        printf("3.部门号\n");
        printf("4.退出\n");
        printf("请输入(1-4)\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                SearchEMPno(L);
                break;
            case 2:
                SearchEMPname(L);
                break;
            case 3:
                SearchEMPdepno(L);
                break;
            case 4:
                loop = 0;//不再查询
                break;
            default:
                printf("输入错误！\n");
                break;
        }        
    }while(loop);
}
//输出按照部门号排序，部门号相同时则按照职工号排序的职工信息
void SortEMPdepno(EMPList &L)
{
    EMP *p = L->next;
    EMP *q = p->next;
    EMP *r;
    while(q != NULL)
    {
        if(p->depno > q->depno)
        {
            r = q->next;
            q->next = p;
            p->next = r;
            L->next = q;
            q = r;
        }
        else if(p->depno == q->depno)
        {
            if(p->no > q->no)
            {
                r = q->next;
                q->next = p;
                p->next = r;
                L->next = q;
                q = r;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    ShowEMP(L);
}


//输出按照职工号排序的职工信息
void SortEMPno(EMPList &L)
{
    EMP *p = L->next;
    EMP *q = p->next;
    EMP *r;
    while(q != NULL)
    {
        if(p->no > q->no)
        {
            r = q->next;
            q->next = p;
            p->next = r;
            L->next = q;
            q = r;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    ShowEMP(L);
}
//输出所有职工按照工资排序的职工信息
void SortEMPsalary(EMPList &L)
{
    EMP *p = L->next;
    EMP *q = p->next;
    EMP *r;
    while(q != NULL)
    {
        if(p->salary > q->salary)
        {
            r = q->next;
            q->next = p;
            p->next = r;
            L->next = q;
            q = r;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    ShowEMP(L);
}

//职工信息排序
void SortEMP(EMPList &L)
{
    int choice;
    int loop=1;
    do{
        printf("请输入你要排序的方式：\n");
        printf("1.职工号\n");
        printf("2.部门号\n");
        printf("3.工资\n");
        printf("4.退出\n");
        printf("请输入(1-4)\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                SortEMPno(L);
                break;
            case 2:
                SortEMPdepno(L);
                break;
            case 3:
                SortEMPsalary(L);
                break;
            case 4:
                loop = 0;//不再排序
                break;
            default:
                printf("输入错误！\n");
                break;
        }        
    }while(loop);
}

//统计每个部门职工的数量并显示结果,不断询问是否继续查询
void CountEMP(EMPList &L)
{
    int depno;
    int count = 0;
    int loop = 1;
    do{
        count = 0;
        printf("请输入你要查询的部门号：\n");
        scanf("%d",&depno);
        EMP *p = L->next;
        while(p != NULL)
        {
            if(p->depno == depno)
            {
                count++;
            }
            p = p->next;
        }
        printf("部门%d的职工数量为%d\n",depno,count);
        printf("是否继续查询？\n");
        printf("1.是\n");
        printf("2.否\n");
        scanf("%d",&loop);
    }while(loop == 1);
}
//主函数
int main()
{

    int choice;
    int loop = 1;
    EMPList L;
    InitEMPList(L);
    
    do{
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                AddEMP(L);
                break;
            case 2:
                ShowEMP(L);
                break;
            case 3:
                DeleteEMP(L);
                break;
            case 4:
                ModifyEMP(L);
                break;
            case 5:
                SearchEMP(L);
                break;
            case 6:
                SortEMP(L);
                break;
            case 7:
                CountEMP(L);
                break;
            case 8:
                loop = 0;//退出
                break;
            default:
                printf("输入错误！\n");
                break;
        }
    }while(loop);
    return 0;
}