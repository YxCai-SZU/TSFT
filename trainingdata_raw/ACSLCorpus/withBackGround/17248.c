#include <stdbool.h>

/*@
    predicate b_in_range(integer b) = 0 <= b <= 99;
    
    logic integer b_scaled_value(integer b, integer counter) = 
        (b * 21) - (counter * 21 * 100);
*/

/*@
    requires 1 <= n <= 100000;
    ensures \result == ((n % 100) * 21 < n);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int a;
    unsigned int b;
    unsigned int temp_b;
    unsigned int counter;
    unsigned int b_scaled;
    bool result;
    
    a = n / 100;
    b = n % 100;
    
    //@ assert b_in_range(b);
    
    temp_b = b;
    counter = 0;
    
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant 0 <= counter <= b / 100;
        loop invariant temp_b == b - counter * 100;
        loop invariant b_in_range(b);
        loop assigns temp_b, counter;
        loop variant temp_b;
    */
    while (temp_b >= 100)
    {
        temp_b -= 100;
        counter += 1;
    }
    
    b_scaled = (b * 21) - (counter * 21 * 100);
    
    //@ assert b_scaled == b_scaled_value(b, counter);
    
    result = b_scaled < n;
    return result;
}
