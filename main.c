#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>


int main(int argc, char* argv[])
{
    DIR* dir;
    struct dirent *de;
    if (argc>1){
        int i;
        for(i=1; i<argc; i++){
            printf("%s :\n", argv[i]);
            dir = opendir(argv[i]);
            if (dir == NULL){
                if (errno == EACCES){
                    printf("You don't have access to directory : %s\n", argv[i] );
                }
                else if (errno == ENOENT) {
                    printf("%s does not exist\n", argv[i]);
                }
                else if (errno == ENOTDIR) {
                    printf("%s is not a directory\n", argv[i]);
                }
                exit(EXIT_FAILURE);
            }

            while((de = readdir(dir)) != 0){
                printf("\t%s\n", de->d_name);
            }
            closedir(dir);
        }
    }
    else{
        dir = opendir(".");
        if (dir == 0){
            if (errno == EACCES){
                printf("You don't have access to the current directory\n", errno );
                exit(EXIT_FAILURE);
            }
        }
        while((de = readdir(dir)) != 0){
            printf("%s\n", de->d_name);
        }
        closedir(dir);
    }
    return 0;
}
