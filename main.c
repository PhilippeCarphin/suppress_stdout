#include "my_functions.h"
#include <unistd.h>
#include <stdio.h>

int saved_stdout = -1;
int suppress_stdout(){
    if(saved_stdout != -1){
        return -1;
    }
    saved_stdout = dup(STDOUT_FILENO);
    freopen("/dev/null", "w", stdout);
    fclose(stdout);
    return 0;
}
int restore_stdout(){
    if(saved_stdout == -1){
        return -1;
    }
    stdout = fdopen(saved_stdout, "w");
    saved_stdout = -1;
    return 0;
}
int main(void){

    suppress_stdout();
    my_function();
    restore_stdout();

    my_function();

    return 0;
}
