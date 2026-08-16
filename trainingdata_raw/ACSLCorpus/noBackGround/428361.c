#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 9) && (1 <= (g) && (g) <= 9) && (1 <= (b) && (b) <= 9);
    ensures \result == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
    assigns \nothing;
*/
bool func(int r, int g, int b)
{
    int num;
    int temp;
    int remainder;
    bool is_divisible;
    
    //@ assert (1 <= (r) && (r) <= 9);
    //@ assert (1 <= (g) && (g) <= 9);
    //@ assert (1 <= (b) && (b) <= 9);
    
    num = r * 100 + g * 10 + b;
    temp = num;
    
    /*@
        loop invariant 0 <= temp <= num;
        loop invariant temp % 4 == num % 4;
        loop assigns temp;
    */
    while (temp >= 4)
    {
        temp -= 4;
    }
    
    remainder = temp;
    is_divisible = (remainder == 0);
    
    //@ assert is_divisible == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
    
    return is_divisible;
}
