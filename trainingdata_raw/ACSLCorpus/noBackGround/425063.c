#include <limits.h>

/*@
  requires -100 <= a <= 100;
  requires -100 <= b <= 100;
  requires -100 <= c <= 100;
  requires -100 <= d <= 100;
  ensures \result == a || \result == b || \result == c || \result == d;
  ensures \result >= a || \result >= b || \result >= c || \result >= d;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_ac;
    int max_bd;
    int max_abc;
    int max_acd;
    int result;

    max_ab = (a > b) ? a : b;
    //@ assert max_ab == a || max_ab == b;

    max_bc = (b > c) ? b : c;
    //@ assert max_bc == b || max_bc == c;

    max_cd = (c > d) ? c : d;
    //@ assert max_cd == c || max_cd == d;

    max_ac = (a > c) ? a : c;
    //@ assert max_ac == a || max_ac == c;

    max_bd = (b > d) ? b : d;
    //@ assert max_bd == b || max_bd == d;

    max_abc = (max_ab > max_bc) ? max_ab : max_bc;
    max_abc = (max_abc > max_cd) ? max_abc : max_cd;
    //@ assert max_abc == a || max_abc == b || max_abc == c || max_abc == d;

    max_acd = (max_ac > max_bd) ? max_ac : max_bd;
    //@ assert max_acd == a || max_acd == b || max_acd == c || max_acd == d;

    result = (max_abc > max_acd) ? max_abc : max_acd;
    //@ assert ((result) == (a) || (result) == (b) || (result) == (c) || (result) == (d));
    //@ assert result >= a || result >= b || result >= c || result >= d;

    return result;
}
