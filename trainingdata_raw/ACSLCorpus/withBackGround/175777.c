#include <limits.h>

/*@ predicate a_less_b(integer a, integer b) = a < b; */
/*@ predicate b_less_c(integer b, integer c) = b < c; */
/*@ predicate a_less_c(integer a, integer c) = a < c; */

/*@ lemma comparison_chain:
      \forall integer a, b, c;
        a_less_b(a, b) && b_less_c(b, c) ==> a_less_c(a, c); */

/*@
  requires a > INT_MIN && b > INT_MIN && c > INT_MIN;
  requires a < INT_MAX && b < INT_MAX && c < INT_MAX;
  ensures \result == (a < b && b < c);
*/
int func(int a, int b, int c)
{
    int result = 0;
    int b_copy = b;
    int c_copy = c;
    int a_geq_b = 0;
    int b_geq_c = 0;
    int a_less_c = 0;

    //@ assert b_copy == b && c_copy == c;

    if (a >= b_copy)
    {
        a_geq_b = 1;
    }

    //@ assert a_geq_b == (a >= b);

    if (b_copy >= c_copy)
    {
        b_geq_c = 1;
    }

    //@ assert b_geq_c == (b >= c);

    if (a < c_copy)
    {
        a_less_c = 1;
    }

    //@ assert a_less_c == (a < c);

    if (a_geq_b)
    {
        result = 0;
    }
    else if (b_geq_c)
    {
        result = 0;
    }
    else if (a_less_c)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //@ assert result == (a < b && b < c);
    return result;
}
