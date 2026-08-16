#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) < (b) && (b) < (c) && (c) <= 100);
    ensures \result == (((a) * (a)) + ((b) * (b)) == ((c) * (c)));
    assigns \nothing;
*/
bool is_pythagorean_triplet(int a, int b, int c)
{
    // Variable declarations at top of scope
    int a_square;
    int b_square;
    int c_square;
    bool result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    //@ assert a * a <= 10000;
    //@ assert b * b <= 10000;
    //@ assert c * c <= 10000;
    
    //@ assert a * a + b * b <= 20000;

    a_square = a * a;
    b_square = b * b;
    c_square = c * c;
    
    result = (a_square + b_square) == c_square;
    
    return result;
}
