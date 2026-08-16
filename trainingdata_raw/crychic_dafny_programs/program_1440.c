// Generated C + ACSL

/*@ axiomatic Exponential {
  @   logic integer exp(integer n, integer e);
  @   
  @   axiom exp_base: \forall integer n; exp(n, 0) == 1;
  @   axiom exp_rec: \forall integer n, e; e > 0 ==> exp(n, e) == n * exp(n, e - 1);
  @   axiom exp_positive: \forall integer n, e; n > 0 && e >= 0 ==> exp(n, e) > 0;
  @ }
  */

/*@
  requires e >= 0;
  decreases e;
  assigns \nothing;
*/
int exp(int n, int e)
{
  return ((e > 0)) ? ((n * exp(n, (e - 1)))) : (1);
}

/*@
  requires e >= 0;
  requires n >= 1;
  requires e <= 30;
  ensures \result == exp(n, e);
*/
int expon(int n, int e)
{
  int b = e;
  int r = 1;
  /*@ assert r == 1; */
  /*@ assert b == e; */
  /*@ assert r == exp(n, 0); */
  /*@ assert exp(n, e - b) == exp(n, 0); */
/*@
  loop invariant 0 <= b <= e;
  loop invariant r == exp(n, e - b);
  loop invariant e - b >= 0;
  loop invariant b >= 0 ==> r >= 1;
  loop assigns r, b;
  loop variant b;
*/
  while ((b > 0))
    {
      /*@ assert b > 0; */
      /*@ assert r == exp(n, e - b); */
      /*@ assert e - b >= 0; */
      /*@ assert e - (b - 1) == (e - b) + 1; */
      r = (r * n);
      /*@ assert r == n * exp(n, e - b); */
      /*@ assert r == exp(n, e - b + 1); */
      b = (b - 1);
      /*@ assert r == exp(n, e - b); */
    }
  /*@ assert b == 0; */
  /*@ assert r == exp(n, e - 0); */
  /*@ assert r == exp(n, e); */
  return r;
}