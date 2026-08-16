#include <limits.h>

/*@ predicate is_one_of(integer val, integer a, integer b, integer c, integer d) =
      val == a || val == b || val == c || val == d;
*/

/*@ predicate is_maximum(integer val, integer a, integer b, integer c, integer d) =
      val >= a && val >= b && val >= c && val >= d;
*/

/*@ lemma max_property:
      \forall integer a, b, c, d, max_ab, max_bc, max_cd, max_ac, max_bd,
             max_1, max_2, max_3, max_4;
      (max_ab == (a > b ? a : b)) &&
      (max_bc == (b > c ? b : c)) &&
      (max_cd == (c > d ? c : d)) &&
      (max_ac == (a > c ? a : c)) &&
      (max_bd == (b > d ? b : d)) &&
      (max_1 == (max_ab > max_bc ? max_ab : max_bc)) &&
      (max_2 == (max_cd > max_ac ? max_cd : max_ac)) &&
      (max_3 == (max_1 > max_2 ? max_1 : max_2)) &&
      (max_4 == (max_3 > max_bd ? max_3 : max_bd))
      ==>
      (is_one_of(max_4, a, b, c, d) && is_maximum(max_4, a, b, c, d));
*/

/*@
  requires -100 <= a <= 100;
  requires -100 <= b <= 100;
  requires -100 <= c <= 100;
  requires -100 <= d <= 100;
  ensures \result == a || \result == b || \result == c || \result == d;
  ensures \result >= a && \result >= b && \result >= c && \result >= d;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_ac;
    int max_bd;
    int max_1;
    int max_2;
    int max_3;
    int max_4;

    max_ab = (a > b) ? a : b;
    //@ assert max_ab == a || max_ab == b;
    //@ assert max_ab >= a && max_ab >= b;

    max_bc = (b > c) ? b : c;
    //@ assert max_bc == b || max_bc == c;
    //@ assert max_bc >= b && max_bc >= c;

    max_cd = (c > d) ? c : d;
    //@ assert max_cd == c || max_cd == d;
    //@ assert max_cd >= c && max_cd >= d;

    max_ac = (a > c) ? a : c;
    //@ assert max_ac == a || max_ac == c;
    //@ assert max_ac >= a && max_ac >= c;

    max_bd = (b > d) ? b : d;
    //@ assert max_bd == b || max_bd == d;
    //@ assert max_bd >= b && max_bd >= d;

    max_1 = (max_ab > max_bc) ? max_ab : max_bc;
    //@ assert max_1 == max_ab || max_1 == max_bc;
    //@ assert max_1 >= max_ab && max_1 >= max_bc;

    max_2 = (max_cd > max_ac) ? max_cd : max_ac;
    //@ assert max_2 == max_cd || max_2 == max_ac;
    //@ assert max_2 >= max_cd && max_2 >= max_ac;

    max_3 = (max_1 > max_2) ? max_1 : max_2;
    //@ assert max_3 == max_1 || max_3 == max_2;
    //@ assert max_3 >= max_1 && max_3 >= max_2;

    max_4 = (max_3 > max_bd) ? max_3 : max_bd;
    //@ assert max_4 == max_3 || max_4 == max_bd;
    //@ assert max_4 >= max_3 && max_4 >= max_bd;

    //@ assert is_one_of(max_4, a, b, c, d);
    //@ assert is_maximum(max_4, a, b, c, d);

    return max_4;
}
