#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    DIR* dir;
    struct dirent *de;
    if (argc>1){
        int i;
        for(i=1; i<argc; i++){
            printf("%s :\n", argv[i]);
            dir = opendir(argv[i]);
            while((de = readdir(dir)) != 0){
                printf("\t%s\n", de->d_name);
            }
            closedir(dir);
        }
    }
    else{
        dir = opendir(".");
        while((de = readdir(dir)) != 0){
            printf("%s\n", de->d_name);
        }
        closedir(dir);
    }
    return 0;
}
