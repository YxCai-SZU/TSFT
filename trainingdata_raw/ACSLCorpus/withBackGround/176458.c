#include <stdbool.h>

/*@
    predicate is_between(integer a, integer b, integer c) = a <= c && c <= b;
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires a <= b;
    ensures \result == (a <= c && c <= b);
*/
bool func(long long a, long long b, long long c)
{
    bool is_between = false;
    //@ assert a <= b;
    if (a <= c && c <= b)
    {
        is_between = true;
    }
    //@ assert is_between == (a <= c && c <= b);
    return is_between;
}

/*@
    lemma seq_empty_len: \forall integer len; len == 0 ==> len == 0;
*/
