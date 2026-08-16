#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int c = 1;
    
    /*@
        loop invariant 1 <= c <= 10;
        loop assigns c;
    */
    while (c < 10) {
        c = c + 1;
    }
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    
    return a * b;
}

int main() {
    return 0;
}
