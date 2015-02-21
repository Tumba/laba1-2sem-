#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>

typedef struct
  {
    char name[25];
    unsigned long int money;
    char city[25];
    char coach[25];

  }Clubs;
Clubs* NewData(Clubs *club,int *num,int *newnum)
  {
    *newnum = -1;
    Clubs *newclub = NULL;
    for(int i = 0;i <=*num;i++)
      {
        if((club+i)->money > 1000000)
          {
             *newnum = *newnum +1;
             newclub = (Clubs*)realloc(newclub,(*newnum+1)*sizeof(Clubs));
             *(newclub+*newnum) = *(club+i);
          }
      }
    return newclub;
  }
Clubs* InputData(int *num)
  {
    char c;
    *num = 0;
    Clubs *club = (Clubs*)malloc(sizeof(Clubs));
    do
      {
        do
          {
            printf("Введите название клуба (не более 25 символов)\n");
            fflush(stdin);
            fgets((club+*num)->name,25,stdin);
            *((club+*num)->name+strlen((club+*num)->name)-1) = '\0';
            if(*((club+*num)->name) == '\n')
              printf("Название клуба не может быть пустым\n");
          }
        while(*((club+*num)->name) == '\n');
        do
          {
            printf("Введите город клуба(не более 25 символов)\n");
            fgets((club+*num)->city,25,stdin);
            *((club+*num)->city+strlen((club+*num)->city)-1) = '\0';
            if(*((club+*num)->city) == '\n')
              printf("Название города не может быть пустым\n");
          }
        while(*((club+*num)->city) == '\n');
        do
          {
            printf("Введите имя тренера клуба(не более 25 символов)\n");
            fgets((club+*num)->coach,25,stdin);
            *((club+*num)->coach+strlen((club+*num)->coach)-1) = '\0';
            if(*((club+*num)->coach) == '\n')
              printf("Имя тренера не может быть пустым\n");
          }
        while(*((club+*num)->coach) == '\n');
        printf("Введите количество денег в клубе\n");
        scanf("%ld",&(club+*num)->money);
        printf("Если вы хотите продолжить ввод, нажмите ENTER\n");
        fflush(stdin);
        c = getch();
        if(c == '\r')
          {
            *num = *num +1;
            club = (Clubs*)realloc(club,(*num+1)*sizeof(Clubs));
          }
      }
    while(c == '\r');
    return club;
  }


void OutPutData(Clubs *club,int num)
  {
    printf("Клуб\t\tГород\t\tТренер\t\tБюджет\n");
    for(int i = 0;i <= num;i++)
        printf("%s\t\t%s\t\t%s\t\t%ld\n",(club+i)->name,(club+i)->city,(club+i)->coach,(club+i)->money);
  }
int main()
  {
    setlocale(LC_ALL,"Russian");
    int z;
    bool f = false,ff = false;
    int num,newnum;
    Clubs *club,*newclub;
    do
      {
        printf("1 - Ввод структур\n");
        printf("2 - Вывод структур\n");
        printf("3 - Формирование последовательности структур\n");
        printf("4 - Вывод новых структур\n");
        printf("5 - Завершить работу программы\n");
        scanf("%d",&z);
        switch(z)
          {
            case 1:
               if(f)
                 free(club);
               else
                 f = true;
               if(ff)
                 {
                   ff = false;
                   free(newclub);
                 }
               club = InputData(&num);
               break;
            case 2:
               if(f)
                 OutPutData(club,num);
               else
                 printf("Данные не были введены(пункт 1)\n");
               break;
            case 3:
               if(ff)
                 free(newclub);
               else
                 ff = true;
               newclub = NewData(club,&num,&newnum);
               printf("Новая последовательность сформирована\n");
               break;
            case 4:
               if(f)
                 {
                   if(ff)
                     {
                       if(newnum >= 0)
                         OutPutData(newclub,newnum);
                       else
                         printf("Нет полей удовлетворяющих условию\n");
                     }
                   else
                     printf("Новая последовательность не была сформирована(пункт меню 3)\n");
                 }
               else
                 printf("Исходная последовательность не была введена(пункт меню 1)\n");
               break;
            case 5:
               printf("Спасибо, что воспользовались нашей программой.До встречи!\n");
               if(f == true)
                 free(club);
               if(ff && newnum >= 0)
                 free(newclub);
               break;
            default:
               printf("Ошибка в выборе пункта меню!\n");
               break;
          }
      }
      while(z != 5);
      return 0;
  }
