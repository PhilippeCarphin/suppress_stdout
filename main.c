#include "my_functions.h"
#include "suppressor.h"
int main(void){

    suppress_stdout();
    my_function();
    restore_stdout();

    my_function();

    return 0;
}
