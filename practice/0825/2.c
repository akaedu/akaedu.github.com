/** 
* @file 2.c
* @brief 从命令行读取数据，
* 要求用户输入的日期形式为：8/25/2011，并且假设日期中没有空
* 格，执行后显示的数据格式为：August 25，2011，如果没有按照指定格式录入日期，
* 那么程序显示出错次信息；（提示：可以使用sscanf函数从命令行截取出年，月，日）
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
        char *mon[13] = {NULL,"January","Febrary","March","April","May","June","July",
                "August","September","October","November","December"};

        int year, month, day, ret;
        
        if(argc != 2)
        {
                printf("Please Usage : ./XX 8/25/2011\n");
                return 0;
        }
        ret = sscanf(argv[1], "%d/%d/%d", &month, &day, &year);
        if(ret != 3)
        {
                printf("Error!\n");
                return 0;
        }
        printf("%s %d, %d\n", mon[month], day, year);

        return 0;
}
