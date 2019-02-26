#include <sys/types.h>
#include <stdio.h>
int main(){
  pid_t pid;
  pid = fork();
  printf("Proceso %d\n", pid);
  if(pid < 0){
    fprintf(stderr, "Fork failed");
    return 1;
  }else if (pid == 0){
    printf("Hola!, soy proceso hijo\n");
    execlp("/bin/ls", "ls", NULL);
  }else{

    wait(NULL);
    printf("Hola!, soy proceso padre\n");
  }
}
