#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((((a) * 8) / 100) >= b || (((b) * 10) / 100) >= a);
*/
bool func(int a, int b)
{
    int a_div_100 = 0;
    int temp_a = a * 8;
    int b_div_100 = 0;
    int temp_b = b * 10;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant a_div_100 >= 0;
        loop invariant temp_a >= 0;
        loop invariant temp_a == a * 8 - a_div_100 * 100;
        loop invariant a_div_100 <= a * 8 / 100;
        loop assigns temp_a, a_div_100;
    */
    while (temp_a >= 100)
    {
        temp_a -= 100;
        a_div_100 += 1;
    }
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant b_div_100 >= 0;
        loop invariant temp_b >= 0;
        loop invariant temp_b == b * 10 - b_div_100 * 100;
        loop invariant b_div_100 <= b * 10 / 100;
        loop assigns temp_b, b_div_100;
    */
    while (temp_b >= 100)
    {
        temp_b -= 100;
        b_div_100 += 1;
    }
    
    //@ assert a_div_100 == (a * 8) / 100;
    //@ assert b_div_100 == (b * 10) / 100;
    
    return a_div_100 >= b || b_div_100 >= a;
}
