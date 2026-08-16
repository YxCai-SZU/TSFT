#include <stdbool.h>

/*@
    requires (2 <= (a) && (a) <= 3);
    requires (4 <= (b) && (b) <= 5);
    ensures \result == true;
*/
bool func(int a, int b) {
    //@ assert (2 <= (a) && (a) <= 3);
    //@ assert (4 <= (b) && (b) <= 5);
    //@ assert ((a) <= (b));
    return true;
}

int main() {
    return 0;
}
