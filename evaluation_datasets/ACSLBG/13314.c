#include <stdbool.h>

/*@
    predicate diff_correct(integer a, integer e, integer diff) =
        diff == e - a;
*/


bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int diff;

    diff = e - a;

    //@ assert diff_correct(a, e, diff);

    return k >= diff;
}
