#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a <= c && c <= b) || (b <= c && c <= a));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int tmp_a = a;
    unsigned int tmp_b = b;
    
    //@ assert (1 <= (tmp_a) <= 100) && (1 <= (tmp_b) <= 100) && (1 <= (c) <= 100);
    
    if (tmp_a > tmp_b)
    {
        unsigned int temp = tmp_a;
        tmp_a = tmp_b;
        tmp_b = temp;
    }
    
    //@ assert tmp_a <= tmp_b;
    
    bool result = (tmp_a <= c) && (c <= tmp_b);
    
    //@ assert result == ((a <= c && c <= b) || (b <= c && c <= a));
    
    return result;
}
