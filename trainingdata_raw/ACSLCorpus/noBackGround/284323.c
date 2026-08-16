#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == true <==> 
        (((a) % 3) == 0 || ((b) % 3) == 0 || ((a + b) % 3) == 0);
*/
bool func(unsigned int a, unsigned int b)
{
    bool will_turn_on = false;
    unsigned int a_mod = a;
    unsigned int b_mod = b;
    unsigned int sum_mod = a + b;
    
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant a_mod <= a;
        loop invariant a_mod >= 0;
        loop invariant ((a_mod) % 3) == ((a) % 3);
        loop assigns a_mod;
    */
    while (a_mod >= 3)
    {
        a_mod -= 3;
    }
    
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant b_mod <= b;
        loop invariant b_mod >= 0;
        loop invariant ((b_mod) % 3) == ((b) % 3);
        loop assigns b_mod;
    */
    while (b_mod >= 3)
    {
        b_mod -= 3;
    }
    
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant sum_mod <= a + b;
        loop invariant sum_mod >= 0;
        loop invariant ((sum_mod) % 3) == ((a + b) % 3);
        loop assigns sum_mod;
    */
    while (sum_mod >= 3)
    {
        sum_mod -= 3;
    }
    
    //@ assert a_mod == ((a) % 3);
    //@ assert b_mod == ((b) % 3);
    //@ assert sum_mod == ((a + b) % 3);
    
    if (a_mod == 0 || b_mod == 0 || sum_mod == 0) {
        will_turn_on = true;
    }
    
    return will_turn_on;
}

int main() {
    return 0;
}
