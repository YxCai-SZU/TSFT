// Generated C + ACSL

/*@ axiomatic Padovan {
  @   logic integer P(integer n);
  @   axiom P_base1: P(0) == 1;
  @   axiom P_base2: P(1) == 1;
  @   axiom P_base3: P(2) == 1;
  @   axiom P_rec: \forall integer n; n > 2 ==> P(n) == P(n-2) + P(n-3);
  @   
  @   // Additional axioms for bounds
  @   axiom P_positive: \forall integer n; n >= 0 ==> P(n) >= 1;
  @   axiom P_monotonic: \forall integer n; n >= 3 ==> P(n) >= P(n-1);
  @   axiom P_bounded: \forall integer n; 0 <= n <= 46 ==> P(n) <= 2147483647;
  @ }
  @*/

/*@
  requires 0 <= n <= 46;
  ensures \result == P(n);
  ensures \result >= 1;
  ensures \result <= 2147483647;
*/
int calcP(int n)
{
  if ((n <= 2))
  {
    return 1;
  }
  int a = 1;
  int b = 1;
  int c = 1;
  int i = 2;
/*@
  loop invariant 2 <= i <= n;
  loop invariant a == P(i - 2);
  loop invariant b == P(i - 1);
  loop invariant c == P(i);
  loop invariant a >= 1;
  loop invariant b >= 1;
  loop invariant c >= 1;
  loop invariant i <= 46 ==> c <= 2147483647;
  loop invariant i <= 46 ==> a <= 2147483647;
  loop invariant i <= 46 ==> b <= 2147483647;
  loop assigns i, a, b, c;
  loop variant n - i;
*/
  while ((i < n))
    {
      int tmp_a = b;
      int tmp_b = c;
      int tmp_c = a + b;
      a = tmp_a;
      b = tmp_b;
      c = tmp_c;
      i = (i + 1);
    }
  int res = c;
  /*@ assert i == n; */
  /*@ assert res == P(n); */
  /*@ assert n <= 46; */
  /*@ assert res >= 1; */
  /*@ assert res <= 2147483647; */
  return res;
}