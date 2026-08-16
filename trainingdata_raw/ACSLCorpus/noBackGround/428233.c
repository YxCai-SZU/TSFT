#include <limits.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) && 1 <= (k) && (k) <= (a) + (b) + (c));
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int result = 0;
    int remaining_k = k;
    int num_as = 0;
    int num_bs = 0;
    int num_cs = 0;

    // Calculate the number of As
    //@ assert 0 <= remaining_k <= a + b + c;
    if (remaining_k < a)
    {
        num_as = remaining_k;
    }
    else
    {
        num_as = a;
    }
    result += num_as;
    remaining_k -= num_as;

    // Calculate the number of Bs
    //@ assert 0 <= remaining_k <= b + c;
    if (remaining_k < b)
    {
        num_bs = remaining_k;
    }
    else
    {
        num_bs = b;
    }
    remaining_k -= num_bs;

    // Calculate the number of Cs
    //@ assert 0 <= remaining_k <= c;
    if (remaining_k < c)
    {
        num_cs = remaining_k;
    }
    else
    {
        num_cs = c;
    }
    remaining_k -= num_cs;

    // Update the result based on the count of As, Bs, and Cs
    result -= num_cs;

    // Ensure the result is within the bounds
    //@ assert result == (((k) < (a) ? (k) : (a)) - ((k) - ((k) < (a) ? (k) : (a)) - (b) < 0 ? 0 :          ((k) - ((k) < (a) ? (k) : (a)) - (b) < (c) ? (k) - ((k) < (a) ? (k) : (a)) - (b) : (c))));
    //@ assert result <= a;

    return result;
}
