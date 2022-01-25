#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
// #include <fcntl.h>
// #include <io.h>

#define OPTIONS 3
#define HEX 16

const char options_label[OPTIONS][18] = {"Domain Classifier", "Combs Joiner", "Hash Fixer"};

void operations_viewer();
void logo();

void domain_classifier(char *comb, int, int, int, int, int);
void combs_joiner();
void hash_fixer(char *comb, int fdes);

int main(int argc, char const *argv[]) {
    logo();
    
 /***/
    DIR *program_folder;
    struct dirent *entry;
    struct stat filestat;

    program_folder = opendir(".");
    if(program_folder == NULL)  {
        perror("[Error] Unable to read directory.");
        return(1);
    }
    char cwdpath[256];
    getcwd(cwdpath,256);
/***/

    int quit = 0, get_files = 0, option_selected = 0;
    char option_to_operate[3] = "xox";

    operations_viewer();
    fgets( option_to_operate, sizeof(option_to_operate), stdin );

    while (option_selected == 0)  {
    if( option_to_operate[0] == 49 ) {
       printf("[CombNinja] Domain Classifier requires <1> input.txt file");
       option_selected = 1;
      break;
    }else if( option_to_operate[0] == 50 ) {
      option_selected = 1;
      break;
    }else if( option_to_operate[0] == 51 ) {
      printf("[CombNinja] Hash Fixer requires <1> input.txt file");
      option_selected = 1;
      break;
    }else if( option_to_operate[0] == 48 )  {
        option_selected = 1;
        quit = 1;
        break;
    }else {
      fflush(stdin);
      fprintf(stderr, "[Error] Unable to recognize <%c> please try again. \n\n >> ", option_to_operate[0]);
      option_selected = 0;
      fgets( option_to_operate, sizeof(option_to_operate), stdin );
    }
        fflush(stdin);
    }

    if(quit == 1)   {
        get_files = 0;
    }else{
        get_files = 1;
    }

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    /*stuff used for hexa*/
    char of_gmail_file[64], of_yahoo_file[64], of_aol_file[64], of_hotmail_file[64], of_outlook_file[64];
    char output_file_name[64];
    char input_file_name[64];
    FILE *fp;
    long long total_bytes = 0;
    int ch, loop_index = 0, counter = 0;
    char comb[255];

    if(get_files == 1)  {
    printf(", I have detected these files:\n\n Dir  | %s \n", cwdpath);
    while( (entry=readdir(program_folder)) )    {

        stat(entry->d_name,&filestat);
    if( S_ISDIR(filestat.st_mode) ) {
        continue;
    }else
        printf(" File | %s\n",entry->d_name);
        counter+=1;
        total_bytes+=filestat.st_size;
    }
    closedir(program_folder);
    printf("\n %d File(s) for %lld bytes\n",counter,total_bytes);
    
    printf("\n[CombNinja] please enter a file name >> ");
    fgets(input_file_name,sizeof(input_file_name),stdin);
    input_file_name[strcspn(input_file_name, "\n")] = 0;
    }

    int has_opened = 0;
    fp = fopen(input_file_name, "r");
    while(has_opened == 0 && get_files == 1)  {

    if( fp == NULL )    {
        fprintf(stderr,"\n[Error] Unable to open <%s>.\n<!> Make sure to include file name and its extention <example.txt> <!>\n", input_file_name);
        fflush(stdin);
        printf("\n[CombNinja] please enter a file name again >> ");
        fgets(input_file_name,sizeof(input_file_name),stdin);
        input_file_name[strcspn(input_file_name, "\n")] = 0;
        has_opened = 0;
    }else   {
        printf("[CombNinja] File <%s> has opened for %s.\n", input_file_name, options_label[option_to_operate[0] - 1]);
        has_opened = 1;
        break;
    }
    fp = fopen(input_file_name, "r");
    }

    if(option_to_operate[0] == 49)    {

        sprintf(of_gmail_file, "%c%s%s", 91, asctime(tm)," - GMAILPARSED.txt");
        of_gmail_file[strcspn(of_gmail_file, "\n")] = 93;
        of_gmail_file[strcspn(of_gmail_file, ":")] = 45;
        of_gmail_file[strcspn(of_gmail_file, ":")] = 45;
        of_gmail_file[strcspn(of_gmail_file, "\n")] = 0;
        sprintf(of_yahoo_file, "%c%s%s", 91, asctime(tm)," - YAHOOPARSED.txt");
        of_yahoo_file[strcspn(of_yahoo_file, "\n")] = 93;
        of_yahoo_file[strcspn(of_yahoo_file, ":")] = 45;
        of_yahoo_file[strcspn(of_yahoo_file, ":")] = 45;
        of_yahoo_file[strcspn(of_yahoo_file, "\n")] = 0;
        sprintf(of_aol_file, "%c%s%s", 91, asctime(tm)," - AOLPARSED.txt");
        of_aol_file[strcspn(of_aol_file, "\n")] = 93;
        of_aol_file[strcspn(of_aol_file, ":")] = 45;
        of_aol_file[strcspn(of_aol_file, ":")] = 45;
        of_aol_file[strcspn(of_aol_file, "\n")] = 0;
        sprintf(of_hotmail_file, "%c%s%s", 91, asctime(tm)," - HOTMAILPARSED.txt");
        of_hotmail_file[strcspn(of_hotmail_file, "\n")] = 93;
        of_hotmail_file[strcspn(of_hotmail_file, ":")] = 45;
        of_hotmail_file[strcspn(of_hotmail_file, ":")] = 45;
        of_hotmail_file[strcspn(of_hotmail_file, "\n")] = 0;
        sprintf(of_outlook_file, "%c%s%s", 91, asctime(tm)," - OUTLOOKPARSED.txt");
        of_outlook_file[strcspn(of_outlook_file, "\n")] = 93;
        of_outlook_file[strcspn(of_outlook_file, ":")] = 45;
        of_outlook_file[strcspn(of_outlook_file, ":")] = 45;
        of_outlook_file[strcspn(of_outlook_file, "\n")] = 0;
    }else if( option_to_operate[0] == 50 )  {

    }else if( option_to_operate[0] == 51)  {
        sprintf(output_file_name, "%c%s%s", 91, asctime(tm)," - HASHFIXER.txt");
        output_file_name[strcspn(output_file_name, "\n")] = 93;
        output_file_name[strcspn(output_file_name, ":")] = 45;
        output_file_name[strcspn(output_file_name, ":")] = 45;
        output_file_name[strcspn(output_file_name, "\n")] = 0;
    }

    int fdes,of_gmail, of_yahoo, of_aol, of_hotmail, of_outlook;

    if(has_opened == 1 && option_to_operate[0] == 49)   {

        of_gmail = open(of_gmail_file, O_WRONLY|O_CREAT,S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH);
        of_yahoo = open(of_yahoo_file, O_WRONLY|O_CREAT,S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH);
        of_aol = open(of_aol_file, O_WRONLY|O_CREAT,S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH);
        of_hotmail = open(of_hotmail_file, O_WRONLY|O_CREAT,S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH);
        of_outlook = open(of_outlook_file, O_WRONLY|O_CREAT,S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH);

    }
    if(has_opened == 1 && option_to_operate[0] == 51) {
    fdes = open(output_file_name, O_WRONLY|O_CREAT,S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH);
    }

    while( !feof(fp) && has_opened == 1 && (option_to_operate[0] == 49 || option_to_operate[0] == 51))  {
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
        if(option_to_operate[0] == 49 && loop_index > 1)    {
            domain_classifier(comb);
        }
        if(option_to_operate[0] == 51 && loop_index > 1)    {
            hash_fixer(comb, fdes);
        }
        strcpy(comb, "");
        loop_index = 0;
    }
    if(option_to_operate[0] == 49)  {
    fclose(fp);
    close(of_gmail);
    close(of_yahoo);
    close(of_aol);
    close(of_hotmail);
    close(of_outlook);
    }
    if(option_to_operate[0] == 51)  {
    fclose(fp);
    close(fdes);
    }
    char goodbye[4] = "xxx";
    printf("[CombNinja] Work is done.");
    fgets(goodbye, sizeof(goodbye), stdin);
    return (0);
}
void logo() {

 printf("    _____           _   _____ _      _     \n");
 printf("   |     |___ _____| |_|   | |_|___ |_|___ \n");
 printf("   |   --| . |     | . | | | | |   || | .'|\n");
 printf("   |_____|___|_|_|_|___|_|___|_|_|_|| |__,|\n");
 printf("                                  |___|    \n");
 printf("                    By xLinnit");
 printf("\n\n[Info] Check <readme.md> to know how to use the software.\n");
 printf("\n");
 printf(" Menu :\n");
}
void operations_viewer()    {
  int loop_index = 0;
  for (loop_index = 0; loop_index < OPTIONS; ++loop_index) {
    printf(" [%d] | %s\n", loop_index + 1, options_label[loop_index]);
  }
    printf(" [%d] | exit\n\n >> ", 0);
}

void domain_classifier(char *comb, int of_gmail, int of_yahoo, int of_aol, int of_hotmail, int of_outlook) {

    int r, runs = 0;
    char parsed_comb[256];

    char *ret_gmail, *ret_yahoo, *ret_aol, *ret_hotmail, *ret_outlook;

    ret_gmail = strstr(comb, "@gmail");
    ret_yahoo = strstr(comb, "@yahoo");
    ret_aol = strstr(comb, "@aol");
    ret_hotmail = strstr(comb, "@hotmail");
    ret_outlook = strstr(comb, "@outlook");

    if(ret_gmail)   {
        sprintf(parsed_comb, "%s%c", comb, '\n');
        r = write(ret_gmail, parsed_comb, strlen(parsed_comb));
    }else if(ret_yahoo) {
        sprintf(parsed_comb, "%s%c", comb, '\n');
        r = write(ret_yahoo, parsed_comb, strlen(parsed_comb));
    }else if(ret_aol)   {
        sprintf(parsed_comb, "%s%c", comb, '\n');
        r = write(ret_aol, parsed_comb, strlen(parsed_comb));
    }else if(ret_hotmail)   {
        sprintf(parsed_comb, "%s%c", comb, '\n');
        r = write(ret_hotmail, parsed_comb, strlen(parsed_comb));
    }else if(ret_outlook)   {
        sprintf(parsed_comb, "%s%c", comb, '\n');
        r = write(ret_outlook, parsed_comb, strlen(parsed_comb));
    }
    strcpy(parsed_comb, "");
    r = 0;
    runs++;
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