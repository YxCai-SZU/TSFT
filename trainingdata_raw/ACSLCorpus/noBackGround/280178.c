#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (b) != (c)) ==> \result == c;
    ensures ((b) == (c) && (a) != (b)) ==> \result == a;
    ensures ((a) == (c) && (a) != (b)) ==> \result == b;
*/
int func(int a, int b, int c)
{
    int ans;
    //@ ghost int original_a = a;
    //@ ghost int original_b = b;
    //@ ghost int original_c = c;

    if (a == b)
    {
        ans = c;
    }
    else if (b == c)
    {
        ans = a;
    }
    else
    {
        ans = b;
    }

    //@ assert ((original_a) == (original_b) && (original_b) != (original_c)) ==> ans == original_c;
    //@ assert ((original_b) == (original_c) && (original_a) != (original_b)) ==> ans == original_a;
    //@ assert ((original_a) == (original_c) && (original_a) != (original_b)) ==> ans == original_b;

    return ans;
}
