#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <dirent.h>
lll
#define ARRAY_SIZE 4096
#define getch() wgetch(stdscr)

float arr[750];
// float sum_Tmp;
// float sum_Tmp_2;
char array[4096];
char cwd[PATH_MAX];
char tx_1[PATH_MAX];
char tx_2[PATH_MAX];

int my_get_float(FILE * file, float * f_A);
int my_get_arr(FILE * file, float  * p_arr);
int findMinIndex(float * array, int size);
int do_one_file(FILE * file);

int main(int argc, char const *argv[])
{
    //system("/Users/igelya/Desktop/my_C/text.c");

   FILE *file = fopen("/Users/igelya/Desktop/work/C/Fl1_07.27/DASHA04/C1_1.TXT", "r");
   do_one_file(file);
   int i;
    for (i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    getchar();
   return 0;

}
  

int my_get_float(FILE * file, float * f_A)
{
   // считывает данные из файла и сохраняет их в переменную типа float
     char a;
     char b[256];
     int k = 0, j = 0;
     float x;
     while(1) 
     {
     a = fgetc (file);
     if (a == EOF) return -1;
     if (a == ',') 
      {
         a = 0;
         b[k] = a;
         break;
      }
      b[k] = a;
      k++;
     } 
   //   while(a != ',');
   //   b[k-1] = 0;
   //   k = 0;
     //printf("b = %s\n", b);
     *f_A = atof(b);
     //fclose(file);
     return 0;
}
int my_get_arr(FILE * file, float * p_arr)
{
   //считывает данные из файла и сохраняет их в массиве переменных
   int i, i_rez;
   for (i = 0; i < ARRAY_SIZE / 2; i++)
   {
      //
      //printf("i = %d\n", i);
      i_rez = my_get_float(file, &(p_arr[i]));
      //printf("p_arr[i] = %e\n", p_arr[i]);
      if (i_rez == -1) return -1;
   };
   return 0;
}

int findMinIndex(float * array, int size) {
   // 
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;        
        }
    }
    return minIndex;
}
int do_one_file(FILE * file) 
{
    //
    if (file == NULL) printf("file = 0\n");
   printf("START_A\n");
   //wgetch(stdscr);
   //getch();
   //getchar();
   float array[ARRAY_SIZE];
   float array_2[1800];
   int i, j, i_rez, size, minIndex;
   float * p_arr;
   p_arr = array;
   //printf("m_1\n");
   i_rez = my_get_arr(file, p_arr);
   size = 750;
   //printf("m_2\n");
   minIndex = findMinIndex(array, size);
   minIndex = findMinIndex(array + minIndex + 400, size);
   //getchar();
   for (i = 0; i < 1800; i++) 
   {
       array_2[i] = 0;
   }
   j = 0;
   while(1)
   {
      //printf("m_3\n");
      i_rez = my_get_arr(file, p_arr + ARRAY_SIZE / 2);
      if (i_rez == -1) 
      {
         printf("End of file\n");
         break;
      }
      size = 300;

      do {
         for (i = 0; i < 1800; i++) 
         {
            array_2[i] = array_2[i] + *(array + minIndex - 20 + i);
         }
         minIndex = minIndex + 400 + findMinIndex(array + minIndex + 400, size);
         j++;
         
      } while (minIndex <= (ARRAY_SIZE / 2));
      for(i = 0; i < (ARRAY_SIZE / 2); i++)
      {
         array[i] = array[i + ARRAY_SIZE / 2];
      }
      minIndex -= ARRAY_SIZE /2 ;
      //printf("%s\n", minIndex);
      //printf("min index: %d\n", minIndex);
   }
   for (i = 0; i < 1800; i++) 
      {
         array_2[i] = array_2[i] / j; 
      }
      fclose(file);
      //printf("UUU\n");
     FILE *file_2 = fopen("/Users/igelya/Desktop/work/C/Fl1_07.27/DASHA04/C1_1c.TXT", "w");
     if (file_2 == NULL) printf("file_2 = 0\n");
     //printf("END = %f\n", array_2[i]);
     for (i = 0; i < 1800; i++) 
      {
         fprintf(file_2,"%e\n", array_2[i]); 
      }
   
    return 0;
}

