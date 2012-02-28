/** 
* @file 3.c
* @brief 用结构体数组实现5个学生的成绩统计。功能包括
* 1）输入学生的学号，姓名，成绩；
* 2）按成绩由高到低进行排序并打印结果，并且60及60分以上的学生打印出标志“pass”，
* 60分以下的学员打印出标志“fail”；
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

#define N 3

typedef struct student
{
        int id;
        char name[10];
        int score;
}stu_t;

int main(int argc, const char *argv[])
{
        stu_t stu[N], tmp;
        int i, j, pos;

        for(i = 0; i < N; i++)
                scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
        
        for(i = 0; i < N-1; i++)
        {
                pos = i;
                for(j = i+1; j < N; j++)
                {
                        if(stu[pos].score < stu[j].score)
                                pos = j;
                }
                if(pos != i)
                {
                        tmp = stu[pos];
                        stu[pos] = stu[i];
                        stu[i] = tmp;
                }
        }

        printf("id\t%-10s\tscore\tgrade\n", "name");
        for(i = 0; i < N; i++)
        {
                printf("%d\t%-10s\t%d\t%s\n", stu[i].id, stu[i].name, stu[i].score, stu[i].score >= 60 ? "pass" : "fail");
        }

        return 0;
}
