#include <stdbool.h>
#include <stdint.h>

/*@
    predicate within_range(int *s, integer len, integer min, integer max) =
        \forall integer i; 0 <= i < len ==> (min <= s[i] <= max);

    predicate all_even(int *s, integer len) =
        \forall integer i; 0 <= i < len ==> s[i] % 2 == 0;

    predicate all_greater_than(int *s, integer len, integer min) =
        \forall integer i; 0 <= i < len ==> s[i] > min;
*/

/*@
    requires 2 <= n <= 100;
    requires 2 <= m <= 100;
    ensures \result == (n - 1) * (m - 1);
*/
int func(int n, int m)
{
    //@ assert 1 <= n - 1 <= 99;
    //@ assert 1 <= m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    return (n - 1) * (m - 1);
}

/*@
    requires \valid(v + (0 .. 3));
    ensures within_range(v, 4, 2, 8);
    ensures all_even(v, 4);
    ensures all_greater_than(v, 4, 1);
*/
void main2(int *v)
{
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;
    v[3] = 8;
    
    //@ assert within_range(v, 4, 2, 8);
    //@ assert all_even(v, 4);
    //@ assert all_greater_than(v, 4, 1);
}
