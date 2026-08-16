#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures \result == (((a) + (b) + 1) / 2 >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int total;
    unsigned int half_result;
    bool final_result;

    //@ assert (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    
    total = a + b + 1;
    //@ assert total == ((a) + (b) + 1);
    
    half_result = total / 2;
    //@ assert half_result == ((a) + (b) + 1) / 2;
    
    final_result = (half_result >= c);
    //@ assert final_result == (((a) + (b) + 1) / 2 >= c);
    
    return final_result;
}
