#include <stdbool.h>

/*@
    predicate is_consecutive(integer a, integer b, integer c) =
        (a == b + 1 && b == c + 1) ||
        (a == b - 1 && b == c - 1) ||
        (a == b + 1 && b == c - 1) ||
        (a == b - 1 && b == c + 1);
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> is_consecutive(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool seq1;
    bool seq2;
    bool seq3;
    bool seq4;
    bool result;

    seq1 = a == b + 1 && b == c + 1;
    seq2 = a == b - 1 && b == c - 1;
    seq3 = a == b + 1 && b == c - 1;
    seq4 = a == b - 1 && b == c + 1;

    //@ assert seq1 == (a == b + 1 && b == c + 1);
    //@ assert seq2 == (a == b - 1 && b == c - 1);
    //@ assert seq3 == (a == b + 1 && b == c - 1);
    //@ assert seq4 == (a == b - 1 && b == c + 1);

    result = seq1 || seq2 || seq3 || seq4;
    return result;
}
