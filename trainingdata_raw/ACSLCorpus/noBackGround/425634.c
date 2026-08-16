#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == (((a) + (b)) + (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int ab;
    int abc;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    //@ assert 1 <= a + b && a + b <= 200;
    ab = a + b;
    
    //@ assert 1 <= ab && ab <= 200;
    //@ assert 1 <= ab + c && ab + c <= 300;
    abc = ab + c;
    
    return abc;
}
