// Generated C + ACSL

/*@
  predicate predMaxEx(integer a, integer b) =
    a >= b && b > 100;
*/

/*@
  predicate maxSpec(integer a, integer b, integer c) =
    c >= a && c >= b;
*/

/*@
  logic integer max(integer a, integer b) =
    (a > b) ? a : b;
*/

/*@
  requires \true;
  ensures maxSpec(a, b, \result);
  ensures \result == max(a, b) + 100;
*/
int computeMax(int a, int b) {
  int c;
  if (a > b) {
    c = a + 100;
  } else {
    c = b + 100;
  }
  return c;
}