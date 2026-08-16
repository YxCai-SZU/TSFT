#include <stdbool.h>

/*@ predicate is_valid_input(integer a, integer b, integer c) =
      a >= 1 && a <= 100 &&
      b >= 1 && b <= 100 &&
      c >= 1 && c <= 100;
*/

/*@ predicate is_valid_result(integer res) =
      res >= 1 && res <= 3;
*/

/*@ lemma result_cases:
      \forall integer a, b, c;
      is_valid_input(a, b, c) ==>
      (a == b && b == c) ==> \true &&
      (a != b && b != c && c != a) ==> \true &&
      (!(a == b && b == c) && !(a != b && b != c && c != a)) ==> \true;
*/

/*@
    requires is_valid_input(a, b, c);
    ensures  is_valid_result(\result);
    assigns  \nothing;
*/
int func(int a, int b, int c)
{
    int res = -1;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;

    if (a == b && b == c)
    {
        res = 1;
        //@ assert res == 1;
    }
    else if (a != b && b != c && c != a)
    {
        res = 3;
        //@ assert res == 3;
    }
    else
    {
        res = 2;
        //@ assert res == 2;
    }

    //@ assert res >= 1 && res <= 3;

    return res;
}
