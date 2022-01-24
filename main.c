#include "stdio.h"
#include <string.h>

#define OPTIONS 3

const char options_label[][18] = {"Domain Classifier", "Combs Joiner", "Hash Fixer"};
void operations_viewer();
void logo();

int main(int argc, char const *argv[]) {
    int quit = 0;
    char option_to_operate[3] = "xxx";
    operations_viewer();

    fgets( option_to_operate, sizeof(option_to_operate), stdin );
    if(strncmp(guess, 48, 4) == 0)
    {
      quit = 1;
      break;
    }
    while( quit == 0 )  {
    if( option_to_operate[0] == 49 ) {
      // domain_classifier();
    }else if( option_to_operate[0] == 50 ) {
      // combs_joiner();
    }else if( option_to_operate[0] == 51 ) {
      // hash_fixer();
    }else {
      fprintf(stderr, "unable to recognize %c\n", option_to_operate[0]);
    }
  }
    return (0);
}
void logo() {
  printf("");
}
void operations_viewer()  {
  int loop_index = 0;
  for (loop_index = 0; loop_index < OPTIONS; ++loop_index) {
    printf("%d| %s\n", loop_index + 1, options_label[loop_index]);
  }
}
