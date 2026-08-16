#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a < c) && (c < b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int is_a_less_than_c;
    int is_c_less_than_b;
    int result;
    bool final_result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    is_a_less_than_c = (a < c) ? 1 : 0;
    //@ assert 0 <= is_a_less_than_c <= 1;
    
    is_c_less_than_b = (c < b) ? 1 : 0;
    //@ assert 0 <= is_c_less_than_b <= 1;
    
    result = is_a_less_than_c * is_c_less_than_b;
    //@ assert 0 <= result <= 1;
    
    final_result = (result == 1);
    //@ assert ((final_result) == (((a) < (c)) && ((c) < (b))));
    
    return final_result;
}
