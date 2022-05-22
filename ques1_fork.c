#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#define _GNU_SOURCE
#include <string.h>

void sectionB()
{
    int file_open = open("student_record.csv", O_RDONLY);
    char buffer_size[1024];

    if(file_open == -1)
    {
        printf("File cannot be opened");
        exit(0);
    }


    int bytes = read(file_open, &buffer_size, sizeof (buffer_size));

    //printf("%s\n",buffer_size);

    int counter = 0;
    int flag = 0;
    float total_stu = 0;
    float ass1 = 0, ass2 = 0, ass3 = 0, ass4 = 0, ass5 = 0, ass6 = 0;
    char* val = strtok(buffer_size, ",");

    char* sec;

    while(val)
    {
        counter++;

        sec = val;
        if(strcmp(sec,"B")==0)
        {
            flag = 1;
            total_stu++;
        }
        else
        {
            flag = 0;
        }

        if(flag == 1)
        {
            val = strtok(NULL,",");
            ass1 += atoi(val);

            val = strtok(NULL,",");
            ass2 += atoi(val);

            val = strtok(NULL,",");
            ass3 += atoi(val);

            val = strtok(NULL,",");
            ass4 += atoi(val);

            val = strtok(NULL,",");
            ass5 += atoi(val);

            val = strtok(NULL,",");
            ass6 += atoi(val);

        }
        val = strtok(NULL,",");
    }

    //total_stu--;

    printf("Section B average marks for each assignment:");
    printf("\n");
    printf("Total students : %.1f\n",total_stu);

    float x1 = (ass1)/total_stu;
    float x2 = (ass2)/total_stu;
    float x3 = (ass3)/total_stu;
    float x4 = (ass4)/total_stu;
    float x5 = (ass5)/total_stu;
    float x6 = (ass6)/total_stu;

    printf("Ass1 : %f\n", x1);
    printf("Ass2 : %f\n", x2);
    printf("Ass3 : %f\n", x3);
    printf("Ass4 : %f\n", x4);
    printf("Ass5 : %f\n", x5);
    printf("Ass6 : %f\n", x6);

}

void sectionA()
{
    int file_open = open("student_record.csv", O_RDONLY);
    char buffer_size[1024];

    if(file_open == -1)
    {
        printf("File cannot be opened");
        exit(0);
    }


    int bytes = read(file_open, &buffer_size, sizeof (buffer_size));

    //printf("%s\n",buffer_size);

    int flag = 0;
    float total_stu = 0;
    float ass1 = 0;
    float ass2 = 0, ass3 = 0, ass4 = 0, ass5 = 0, ass6 = 0;
    char* val = strtok(buffer_size, ",");


    char* sec;

    while(val)
    {
        sec = val;
        if(strcmp(sec,"A")==0)
        {
            flag = 1;
            total_stu++;
        }
        else
        {
            flag = 0;
        }

        if(flag == 1)
        {
            val = strtok(NULL,",");
            ass1 += atoi(val);

            val = strtok(NULL,",");
            ass2 += atoi(val);

            val = strtok(NULL,",");
            ass3 += atoi(val);

            val = strtok(NULL,",");
            ass4 += atoi(val);

            val = strtok(NULL,",");
            ass5 += atoi(val);

            val = strtok(NULL,",");
            ass6 += atoi(val);

        }
        val = strtok(NULL,",");
    }

    //total_stu--;

    printf("Section A average marks for each assignment:");
    printf("\n");
    printf("Total students : %.1f\n",total_stu);

    float x1 = ass1/total_stu;
    float x2 = ass2/total_stu;
    float x3 = ass3/total_stu;
    float x4 = ass4/total_stu;
    float x5 = ass5/total_stu;
    float x6 = ass6/total_stu;

    printf("Ass1 : %f\n", x1);
    printf("Ass2 : %f\n", x2);
    printf("Ass3 : %f\n", x3);
    printf("Ass4 : %f\n", x4);
    printf("Ass5 : %f\n", x5);
    printf("Ass6 : %f\n", x6);

}

int main()
{
    //int sect = fork();
    
    int sect = fork();
    if (sect == 0)
    {
        //printf("Child process in action :\n");
        sectionA();
        exit(0);
    }

    if(sect<0)
    {
        printf("Child process not created\n");
    }

    else
    {
        //printf("Parent process in action :\n");
        int j=0;
        pid_t sectb = waitpid(sect,&j,0);
        sectionB();
        printf("Child process has terminated :\n");
        exit(0);
    }

    return 0;
}
