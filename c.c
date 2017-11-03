#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

// Takes a slow and inefficient approach because I was too lazy to fix it
// May be better in the future
void printDirInfo(char *dirloc) {
  printf("\nStatistics for diretory: %s\n", dirloc);
  DIR *dir = opendir(dirloc);

  //Print size
  int sum = 0;
  struct dirent *curr;
  while (curr = readdir(dir)){ // Yes it does the same loop thrice
    struct stat ap;
    stat((*curr).d_name, &ap);
    if ((*curr).d_type == 8)
      sum += ap.st_size;
  }

  //Print dirs
  printf("Total Directory Size: %d Bytes\n", sum);
  printf("Directories:\n");
  closedir(dir);
  dir = opendir(dirloc);
  while (curr = readdir(dir))
    if ((*curr).d_type == 4)
      printf("   %s\n", (*curr).d_name);

  //Print files
  printf("Regular Files:\n", sum);
  closedir(dir);
  dir = opendir(dirloc);
  while (curr = readdir(dir))
    if ((*curr).d_type == 8)
      printf("   %s\n", (*curr).d_name);

  closedir(dir);
}

int main() {
  printDirInfo(".");
  return 0;
}
