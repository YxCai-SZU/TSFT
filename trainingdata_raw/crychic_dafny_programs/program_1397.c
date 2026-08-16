// Generated C + ACSL

/*@ axiomatic Power {
  logic integer power(integer x, integer y);

  axiom power_base: \forall integer x; power(x, 0) == 1;
  axiom power_step: \forall integer x, y; y > 0 ==> power(x, y) == x * power(x, y - 1);
  }
*/

/*@
  requires y >= 0;
  decreases y;
  ensures y == 0 ==> \result == 1;
  ensures y > 0 ==> \result == x * power(x, y - 1);
  assigns \nothing;
*/
int power(int x, int y)
{
  return ((y == 0)) ? (1) : ((x * power(x, (y - 1))));
}

/*@
  requires y >= 0;
  ensures \result == power(x, y);
  assigns \nothing;
*/
int exponent(int x, int y)
{
  /*@ assert (1 == power(x, (y - y))); */
  int z = 1;
  /*@ assert z >= 0 && z <= 2147483647; */
  /*@ assert (z == power(x, (y - y))); */
  int c = y;
  /*@ assert (z == power(x, (y - c))); */
  /*@ assert c >= 0; */
/*@
  loop invariant 0 <= c <= y;
  loop invariant z == power(x, y - c);
  loop assigns z, c;
  loop variant c;
*/
  while ((c != 0))
    {
      /*@ assert c > 0; */
      /*@ assert ((z * x) == power(x, (y - (c - 1)))); */
      z = (z * x);
      /*@ assert (z == power(x, (y - (c - 1)))); */
      c = (c - 1);
      /*@ assert c >= 0; */
      /*@ assert (z == power(x, (y - c))); */
    }
  /*@ assert c == 0; */
  /*@ assert (z == power(x, y)); */
  return z;
}