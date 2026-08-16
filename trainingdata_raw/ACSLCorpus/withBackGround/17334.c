#include <stdbool.h>
#include <limits.h>

/*@
    predicate max_digit_invariant(integer temp, integer n, integer max) =
        temp <= n &&
        max < 10 &&
        max >= 0 &&
        n <= 5000000;
*/

/*@
    logic integer max_digit_decreases(integer temp) = temp;
*/

/*@
    requires n <= 5000000;
    ensures \result < 10;
    ensures \result >= 0;
*/
unsigned int max_digit(unsigned int n)
{
    unsigned int max = 0;
    unsigned int temp = n;
    
    /*@
        loop invariant max_digit_invariant(temp, n, max);
        loop assigns max, temp;
        loop variant max_digit_decreases(temp);
    */
    while (temp > 0)
    {
        unsigned int current_digit = temp % 10;
        
        //@ assert current_digit < 10;
        
        if (current_digit > max)
        {
            max = current_digit;
        }
        
        temp /= 10;
    }
    
    //@ assert max < 10;
    //@ assert max >= 0;
    
    return max;
}

int main()
{
    return 0;
}
