#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= (b) && (b) <= 10 && 1 <= (c) && (c) <= 100);
    ensures \result == c * a || \result == c * b || \result == -1;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int min_a_c;
    int min_b_c;
    int min_value;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert 1 <= c && c <= 100;
    
    //@ assert c * a <= 1000;
    //@ assert c * b <= 1000;

    if (a > 10 || b > 10 || c > 100)
    {
        result = -1;
        return result;
    }

    min_a_c = c * a;
    min_b_c = c * b;

    if (min_a_c < min_b_c)
    {
        min_value = min_a_c;
    }
    else
    {
        min_value = min_b_c;
    }

    if (min_value < 1000)
    {
        result = min_value;
    }
    else
    {
        result = -1;
    }

    return result;
}
