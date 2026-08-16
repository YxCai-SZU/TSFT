#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (a + b == c || a + c == b || b + c == a);
*/
bool func(int a, int b, int c)
{
    int sum_a_b;
    int sum_a_c;
    int sum_b_c;
    bool result;

    sum_a_b = a + b;
    sum_a_c = a + c;
    sum_b_c = b + c;

    //@ assert 1 <= sum_a_b <= 200;
    //@ assert 1 <= sum_a_c <= 200;
    //@ assert 1 <= sum_b_c <= 200;

    //@ assert (sum_a_b == c || sum_a_c == b || sum_b_c == a) ==> (a + b == c || a + c == b || b + c == a);

    result = (sum_a_b == c) || (sum_a_c == b) || (sum_b_c == a);
    return result;
}
