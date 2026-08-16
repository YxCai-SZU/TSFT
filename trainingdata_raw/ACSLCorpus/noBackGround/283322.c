#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == (((b) * 10 + (c)) % 4 < 1 || a % 2 == 1);
*/
bool func(int a, int b, int c)
{
    int sum;
    bool is_sum_even;
    bool is_a_odd;
    bool answer;

    sum = b * 10 + c;
    //@ assert sum == ((b) * 10 + (c));
    
    is_sum_even = (sum % 4) == 0;
    //@ assert is_sum_even == (((b) * 10 + (c)) % 4 == 0);
    
    is_a_odd = (a % 2) == 1;
    //@ assert is_a_odd == (a % 2 == 1);
    
    answer = is_sum_even || is_a_odd;
    //@ assert answer == (((b) * 10 + (c)) % 4 < 1 || a % 2 == 1);
    
    return answer;
}
