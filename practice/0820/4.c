/** 
* @file 4.c
* @brief 定义结构体学生，成员包括学号，姓名，四门功课的成绩，和平均分。
* 编写函数实现平均成绩的计算并存入到结构体相应的域中。
* 编写函数实现结构体的打印，要求传入一个结构体，把各项打印出来。
* 在主函数中调用以上两个函数实现各个成员的平均成绩的计算及最终结果的打印。
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

typedef struct stu{
	int ID;
	char name[20];
	int score[4];
	float aver;
}student_t;

/** 
* @brief Print the detail of a student
* 
* @param s student_t
*/
void print_stu(student_t s)
{
	printf("%d\t%10s\t%d\t%d\t%d\t%d\t%f\n", s.ID, s.name, s.score[0], s.score[1], s.score[2], s.score[3], s.aver);
}

/** 
* @brief  Calc the average
* 
* @param s array of student_t
* @param size size of the array
*/
void calc_aver(student_t *s, int size)
{
	int i;

	for (i = 0; i < size; i++) 
	{
		s[i].aver = (float)(s[i].score[0] + s[i].score[1] + s[i].score[2] + s[i].score[3]) / 4;
	}
}

int main(int argc, const char *argv[])
{
	student_t s[5];
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d %s %d %d %d %d", &s[i].ID, s[i].name, &s[i].score[0], &s[i].score[1], &s[i].score[2], &s[i].score[3]);

	calc_aver(s, 5);
	for (i = 0; i < 5; i++) 
	{
		print_stu(s[i]);
	}

	return 0;
}
