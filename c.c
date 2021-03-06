#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

// Laziness redeemed
void printDirInfo(char *dirloc) {
  
  struct dirent *curr;
  DIR *dir = opendir(dirloc);
  char *files[500];
  char *directories[500];
  int f = 0;
  int d = 0;
  int sum = 0;
  while (curr = readdir(dir)){
    struct stat ap;
    if ((*curr).d_type == 4){
      directories[d] = (*curr).d_name;
      d ++;
    }
    else if ((*curr).d_type == 8){
      files[f] = (*curr).d_name;
      f ++;
      sum += ap.st_size;
    }
  }

  closedir(dir);

  printf("\nStatistics for directory: %s\n", dirloc);
  printf("Total Directory Size: %d Bytes\n", sum);
  int i = 0;
  int a = 0;
  printf("Subdirectories:\n");
  while(directories[a]){
    printf("    %s\n",directories[a]);
    a ++;
  }
    printf("Regular Files:\n");
  while (files[i]){
    printf("    %s\n",files[i]);
    i ++;
  }
  
}

int main() {
  printDirInfo(".");
  return 0;
}
