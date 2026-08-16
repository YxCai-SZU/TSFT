#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == (
        (a == b + 1 && b == c + 1) || 
        (a == b && b == c + 1) || 
        (a == b + 1 && b == c) || 
        (a == b && b == c)
    );
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int n = 0;
    
    //@ assert n == 0;
    
    if (a == b + 1 && b == c + 1) {
        n += 1;
    }
    //@ assert n == (((a) == (b) + 1 && (b) == (c) + 1) ? 1 : 0);
    
    if (a == b && b == c + 1) {
        n += 1;
    }
    //@ assert n == (((a) == (b) + 1 && (b) == (c) + 1) ? 1 : 0) + (((a) == (b) && (b) == (c) + 1) ? 1 : 0);
    
    if (a == b + 1 && b == c) {
        n += 1;
    }
    //@ assert n == (((a) == (b) + 1 && (b) == (c) + 1) ? 1 : 0) + (((a) == (b) && (b) == (c) + 1) ? 1 : 0) + (((a) == (b) + 1 && (b) == (c)) ? 1 : 0);
    
    if (a == b && b == c) {
        n += 1;
    }
    //@ assert n == (((((a)) == ((b)) + 1 && ((b)) == ((c)) + 1) ? 1 : 0) + ((((a)) == ((b)) && ((b)) == ((c)) + 1) ? 1 : 0) +          ((((a)) == ((b)) + 1 && ((b)) == ((c))) ? 1 : 0) + ((((a)) == ((b)) && ((b)) == ((c))) ? 1 : 0));
    
    //@ assert n > 0 ==> ((a == b + 1 && b == c + 1) || (a == b && b == c + 1) || (a == b + 1 && b == c) || (a == b && b == c));
    
    return n > 0;
}
