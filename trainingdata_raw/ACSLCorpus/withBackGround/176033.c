#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;

    predicate bounds_valid(integer a, integer b, integer c, integer d, integer e, integer k) =
        a < 0x80000000 && b < 0x80000000 && c < 0x80000000 &&
        d < 0x80000000 && e < 0x80000000 && k < 0x80000000;

    lemma ordering_implies_distinct:
        \forall integer a, b, c, d, e;
        is_ordered(a,b,c,d,e) ==> a != b && a != c && a != d && a != e &&
                                   b != c && b != d && b != e &&
                                   c != d && c != e && d != e;
*/

/*@
    requires bounds_valid(a, b, c, d, e, k);
    requires is_ordered(a, b, c, d, e);
    ensures \result == true || \result == false;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int v[5];
    unsigned int n;
    unsigned int i;
    unsigned int j;
    unsigned int diff;

    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;
    n = 5;
    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant n == 5;
        loop invariant bounds_valid(a, b, c, d, e, k);
        loop invariant is_ordered(a, b, c, d, e);
        loop invariant v[0] == a && v[1] == b && v[2] == c &&
                       v[3] == d && v[4] == e;
        loop assigns i, j, diff;
        loop variant n - i;
    */
    while (i < n)
    {
        j = i + 1;

        /*@
            loop invariant i < j <= n;
            loop invariant n == 5;
            loop invariant bounds_valid(a, b, c, d, e, k);
            loop invariant is_ordered(a, b, c, d, e);
            loop invariant v[0] == a && v[1] == b && v[2] == c &&
                           v[3] == d && v[4] == e;
            loop assigns j, diff;
            loop variant n - j;
        */
        while (j < n)
        {
            //@ assert v[i] < 0x80000000 && v[j] < 0x80000000;
            
            if (v[i] > v[j]) {
                diff = v[i] - v[j];
            } else {
                diff = v[j] - v[i];
            }

            //@ assert diff == (v[i] > v[j] ? v[i] - v[j] : v[j] - v[i]);

            if (diff > k) {
                //@ assert diff > k;
            }

            j += 1;
        }

        i += 1;
    }

    //@ assert i == n;
    return true;
}
