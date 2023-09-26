#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
ggg
#include <string.h>
#if defined(_MSC_VER)
#define getcwd _getcwd
#elif defined(__GNUC__)
#include <unistd.h>
#endif
char tx_1[PATH_MAX];
char tx_2[PATH_MAX];
char cwd[PATH_MAX];
void my_FUN(const char *p);

int main(int argc, char *argv[]) 
{
    strcpy(tx_1, argv[0]);
    printf("%s\n", tx_1);
    int i_1, i;
    i_1 = strlen(tx_1);
    for (i = i_1; i > 0; i--)
    {
        if (tx_1[i] == '/') 
        {
            tx_1[i+1] = 0;
        break;
        }
    };
    printf("%s\n", tx_1);
    //return 0;
    // Узнаем содержимое папки
    char* buffer;

    if( (buffer=getcwd(NULL, 0)) == NULL) {
        perror("failed to get current directory\n");
    } else {
        printf("%s \nLength: %zu\n", buffer, strlen(buffer));
        free(buffer);
    }

    char path_2[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   strcpy(tx_2, tx_1);
   strcat(tx_2, "/NEW");
   int result = mkdir(tx_2, 0777);
   printf("RESULT = %d\n", result);

   sprintf(path_2,"%s/%s", cwd, "NEW_2");
   printf("\n%s\n",path_2);
   mkdir(path_2, 0777);
   const char * homeDir;
     homeDir = getenv("HOME");
    
    printf("Home directory is %s\n", homeDir);
    DIR *d;
  struct dirent *dir;
  char d_name_1[256];
  char d_name_2[256];
  int k = 0;
  char ch;
  d = opendir(tx_1);
  if (d) {
     while ((dir = readdir(d)) != NULL) {
    //printf("*");
      my_FUN(dir->d_name);
     }
    }
    else
    {
        printf("ERR_1 %s", tx_1);
     }
     const char *programPath = "./vb_3";
    const char *arguments = tx_1;
    
    char command[1024];
    // 
    sprintf(command, "%s %s", programPath, arguments);
    int result_2 = system(command);
   
    if (result == -1)
    {
        printf("Error\n");
    }
    closedir(d);
  }
  
void my_FUN(const char * p) {
    //printf("%s\n", p);

    char ch_0, ch[256], ch_1[256], ch_2[256];
    strcpy(ch, p);
    int i = 0;
    while(1)
    {
        if (ch[i] == '.')
        {
            ch[i] = 0;
            break;
        }
        if (ch[i] == 0 )
        {
            break;
        }
        i++;
    };
    i++;
    if ((ch[i] != 'T')&&(ch[i] != 't')) return;
    sprintf(ch_1, "%s%s%s", tx_1, ch, ".TXT");
    sprintf(ch_2, "%s%s%s%s", tx_1, "NEW/", ch, "_.TXT");
    //
     FILE *file = fopen(ch_1, "r");
     FILE *file_2 = fopen(ch_2, "w");
     if (file_2 == NULL) 
     {
        printf("error = %p\n", (void *)file_2);
     }

     char a;
     char b[256];
     int k = 0, j = 0;
     float x;
     N:
     do {
     a = fgetc (file);
     if (a == EOF) goto M;

     b[k] = a;
     k++;
     } while(a != ',');
     b[k-1] = 0;
     k = 0;
    //  x = atof(b);
    //  printf("%.3e\n", x);
    // printf("%s\n", b);
    fprintf(file_2,"%s\n", b);
     j++;
     if (1) // j <= 100) 
     goto N;
    M: 
     fclose(file);
     fclose(file_2);
        return;
}

