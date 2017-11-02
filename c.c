#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

void printDirInfo(char *dirloc) {
  printf("\nStatistics for diretory: %s\n", dirloc);
  struct stat ap;
  stat(dirloc, &ap);
  DIR *dir = opendir(dirloc);
  printf("Dir size: %lu", ap.st_size);
  struct dirent *curr;
  while (curr = readdir(dir)){
    printf("   %s\n", (*curr).d_name);
  }
  closedir(dir);
}

int main() {
  printDirInfo(".");
  return 0;
}
