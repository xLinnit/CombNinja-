#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define OPTIONS 3
#define HEX 16

const char options_label[OPTIONS][18] = {"Domain Classifier", "Combs Joiner", "Hash Fixer"};

void operations_viewer();
void logo();

void domain_classifier(char *comb);
void combs_joiner();
void hash_fixer(char *comb, int fdes);

int main(int argc, char const *argv[]) {

/***/
    DIR *program_folder;
    struct dirent *entry;
    struct stat filestat;

    program_folder = opendir(".");
    if(program_folder == NULL)  {
        perror("Unable to read directory");
        return(1);
    }
/***/
    int quit = 0, get_files = 0;
    char option_to_operate[3] = "xox";
    operations_viewer();

    fgets( option_to_operate, sizeof(option_to_operate), stdin );

    if( option_to_operate[0] == 49 ) {
      
    }else if( option_to_operate[0] == 50 ) {
      
    }else if( option_to_operate[0] == 51 ) {
      
    }else if( option_to_operate[0] == 48 )  {
        quit = 1;
    }else {
      fprintf(stderr, "unable to recognize %c\n", option_to_operate[0]);
      return (1);
    }

    if(quit != 1)   {
        get_files = 0;
    }else{
        get_files = 1;
    }

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    char output_file_name[64];
    char input_file_name[64];

    FILE *fp;
    int ch, loop_index = 0;
    char comb[255];
    printf("files detected ->");
    while( (entry=readdir(program_folder)) )    {

        stat(entry->d_name,&filestat);
    if( S_ISDIR(filestat.st_mode) ) {
        continue;
    }else
        printf("[%s], ",entry->d_name);
    }
    closedir(program_folder);
    /***************************************************/

    printf("\nenter input_file name: ");
    fgets(input_file_name,sizeof(input_file_name),stdin);
    input_file_name[strcspn(input_file_name, "\n")] = 0;
    printf("\n");

    fp = fopen(input_file_name, "r");
    if( fp == NULL )    {
        fprintf(stderr,"unable to open %s\n", input_file_name);
        return (1);
    }else   {
        printf("file %s has opened\n", input_file_name);
    }

    if( option_to_operate[0] == 49 )    {

    }else if( option_to_operate[0] == 50 )  {

    }else if( option_to_operate[0] == 51 )  {
        sprintf(output_file_name, "%c%s%s", 91,asctime(tm)," -o- hash_fixer.txt");
        output_file_name[strcspn(output_file_name, "\n")] = 93;
        output_file_name[strcspn(output_file_name, ":")] = 45;
        output_file_name[strcspn(output_file_name, ":")] = 45;
        output_file_name[strcspn(output_file_name, "\n")] = 0;
    }

    int fdes,of_gmail, of_yahoo, of_aol, of_hotmail, of_outlook;
    fdes = open(output_file_name, O_WRONLY|O_CREAT,S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH);

    while( !feof(fp) )  {
        int flag = 0;

        while( flag != 1 )  {
            ch = fgetc(fp);

            if( ch == '\n' || ch == -1 )    {
                flag = 1;
                ch = (char) 0;
            }
            comb[loop_index] = ch;
            loop_index++;
        }
        if(option_to_operate[0] == 51 && loop_index > 1)    {
            hash_fixer(comb, fdes);
        }
        strcpy(comb, "");
        loop_index = 0;
    }
    fclose(fp);
    close(fdes);

    return (0);
}
void logo() {
  printf("[Info]: Read howtouse.txt to know how to use the software");
  printf("By xLinnit");
}
void operations_viewer()    {
  int loop_index = 0;
  for (loop_index = 0; loop_index < OPTIONS; ++loop_index) {
    printf("  %d| %s\n", loop_index + 1, options_label[loop_index]);
  }
  printf("  %d| to exit\n\n >", 0);
}
void hash_fixer(char *comb, int fdes)   {
    int r, runs = 0;
    char fixed_comb[256];

    char digits[2];
    digits[0] = 47;
    digits[1] = 47;

    int loop_index_i = 0, loop_index_j = 0;

    for (loop_index_i = 0; loop_index_i < HEX; ++loop_index_i)  {
        if(loop_index_i < 10)   {
            digits[0]++;
        }else if(loop_index_i == 10)    {
            digits[0] = 48;
            digits[0] = digits[0] + 49;
        }else if(loop_index_i > 10) {
            digits[0]++;
        }
        for(loop_index_j = 0; loop_index_j < HEX; ++loop_index_j)   {
            if(loop_index_j < 10)   {
                digits[1]++;
            }else if(loop_index_j == 10)    {
                digits[1] = 48;
                digits[1] = digits[1] + 49;
            }else if(loop_index_j > 10) {
                digits[1]++;
            }
            sprintf(fixed_comb, "%s%c%c%c", comb, digits[0], digits[1], '\n');
            r = write(fdes, fixed_comb, strlen(fixed_comb));
        }
        digits[1] = 47;
    }
    printf("worked with %s now going to the other file to hex\n", comb);
    runs++;
    strcpy(fixed_comb, "");
    r = 0;
}