#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * 800 - ((a) / 15 * 200));
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int result;
    int count;
    int temp_a;
    
    //@ assert (1 <= (a) && (a) <= 100);
    
    //@ assert a * 800 <= 100 * 800;
    result = a * 800;
    count = 0;
    temp_a = a;
    
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 0 <= count;
        loop invariant 0 <= temp_a;
        loop invariant result == a * 800;
        loop invariant a == temp_a + 15 * count;
        loop invariant count <= 6;
        loop assigns count, temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 15)
    {
        //@ assert count <= 6;
        count = count + 1;
        temp_a = temp_a - 15;
    }
    
    //@ assert count <= 6;
    result = result - count * 200;
    
    //@ assert result == ((a) * 800 - ((a) / 15 * 200));
    return result;
}
