#include <stdbool.h>

/*@
  requires i % 2 == 0;
  ensures \result == true;
*/
bool f(int i) {
    //@ assert i % 2 == 0;
    return true;
}

int main() {
    int i;
    bool result;
    
    i = 4;
    //@ assert i % 2 == 0;
    result = f(i);
    //@ assert result == true;
    
    return 0;
}
