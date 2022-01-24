#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define OPTIONS 3
#define HEX 16

const char options_label[OPTIONS][18] = {"Domain Classifier", "Combs Joiner", "Hash Fixer"};

void operations_viewer();
void logo();

void domain_classifier();
void combs_joiner();
void hash_fixer(char *comb, int fdes);

int main(int argc, char const *argv[]) {

    int quit = 0;
    char option_to_operate[3] = "xxx";
    operations_viewer();

    fgets( option_to_operate, sizeof(option_to_operate), stdin );
    if(strncmp(option_to_operate, 48, 4) == 0)
    {
      quit = 1;
      break;
    }
    while( quit == 0 )  {
    if( option_to_operate[0] == 49 ) {
      
    }else if( option_to_operate[0] == 50 ) {
      
    }else if( option_to_operate[0] == 51 ) {
      
    }else {
      fprintf(stderr, "unable to recognize %c\n", option_to_operate[0]);
    }
  }
    return (0);
}
void logo() {
  printf("");
}
void operations_viewer()    {
  int loop_index = 0;
  for (loop_index = 0; loop_index < OPTIONS; ++loop_index) {
    printf("%d| %s\n", loop_index + 1, options_label[loop_index]);
  }
  printf("%d| to exit", 0);
}


void hash_fixer(char *comb, int fdes)   {
    int r = 0;
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
    printf("[hash_fixer()] The hash of [%s] has been fixed\n", comb);
    strcpy(fixed_comb, "");
    r = 0;
}
