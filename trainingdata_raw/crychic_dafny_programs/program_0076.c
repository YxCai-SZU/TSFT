// Generated C + ACSL

/*@ logic integer fusc(integer n); */

/*@
  axiomatic fusc_properties {
    axiom rule1_statement: fusc(0) == 0;
    axiom rule2_statement: fusc(1) == 1;
    axiom rule3_statement:
      \forall integer n; n >= 0 ==> fusc(2 * n) == fusc(n);
    axiom rule4_statement:
      \forall integer n; n >= 0 ==>
        fusc(2 * n + 1) == fusc(n) + fusc(n + 1);
  }
*/

/*@
    requires N >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int ComputeFusc(int N)
{
  int b = 0;
  /*@ assert b >= 0 && b <= 2147483647; */
  int n = N;
  int a = 1;
  /*@ assert 0 <= n <= N; */
  /*@ assert (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))); */
/*@
  loop invariant 0 <= n <= N;
  loop invariant fusc(N) == a * fusc(n) + b * fusc(n + 1);
  loop invariant a >= \at(a, LoopEntry);
  loop invariant b >= \at(b, LoopEntry);
  loop assigns n, a, b;
  loop variant n;
*/
  while ((n != 0))
    {
      int d = n;
      /*@ assert (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))); */
      /*@ assert (n != 0); */
      /*@ assert ((((n % 2) != 0) && ((n % 2) == 0)) || (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1)))))); */
      /*@ assert ((!((((n % 2) != 0) || ((n % 2) == 0)))) || ((fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))))); */
      /*@ assert (((n % 2) != 0) || (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1)))))); */
      /*@ assert (((n % 2) == 0) || (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1)))))); */
      /*@ assert ((!(((n % 2) == 0))) || ((fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))))); */
      /*@ assert ((!(((n % 2) != 0))) || ((fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))))); */
      if (((n % 2) == 0))
      {
        /*@ assert (fusc(((n / 2) + 1)) == (fusc((n + 1)) - fusc((n / 2)))); */
        /*@ assert (fusc((n / 2)) == fusc(n)); */
        /*@ assert (fusc(N) == (((a + b) * fusc((n / 2))) + (b * fusc(((n / 2) + 1))))); */
        a = (a + b);
        /*@ assert (fusc(N) == ((a * fusc((n / 2))) + (b * fusc(((n / 2) + 1))))); */
        n = (n / 2);
        /*@ assert (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))); */
      }
      else
      {
        /*@ assert ((fusc(n) - fusc(((n - 1) / 2))) == fusc((((n - 1) / 2) + 1))); */
        /*@ assert (fusc(((n - 1) / 2)) == fusc((n - 1))); */
        /*@ assert (fusc((((n - 1) / 2) + 1)) == fusc(((n + 1) / 2))); */
        /*@ assert (fusc(((n + 1) / 2)) == fusc((n + 1))); */
        /*@ assert (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))); */
        /*@ assert (fusc(N) == ((b * fusc((((n - 1) / 2) + 1))) + (a * fusc(n)))); */
        /*@ assert (fusc(N) == ((((b * fusc(n)) - (b * fusc(n))) + (b * fusc((((n - 1) / 2) + 1)))) + (a * fusc(n)))); */
        /*@ assert (fusc(N) == (((b * fusc(n)) - (b * (fusc(n) - fusc((((n - 1) / 2) + 1))))) + (a * fusc(n)))); */
        /*@ assert (fusc(N) == (((b * fusc(n)) - (b * fusc(((n - 1) / 2)))) + (a * fusc(n)))); */
        /*@ assert (fusc(N) == (((b * fusc(n)) - (b * fusc((n - 1)))) + (a * fusc(n)))); */
        /*@ assert (fusc(N) == (((b * fusc(n)) - (b * fusc((n - 1)))) + (a * fusc(n)))); */
        /*@ assert (fusc(N) == (((((a * fusc((n - 1))) + (b * fusc(n))) - (b * fusc((n - 1)))) + (a * fusc(n))) - (a * fusc((n - 1))))); */
        /*@ assert (fusc(N) == ((a * fusc((n - 1))) + ((b + a) * (fusc(n) - fusc((n - 1)))))); */
        /*@ assert (fusc(N) == ((a * fusc((n - 1))) + ((b + a) * (fusc(n) - fusc(((n - 1) / 2)))))); */
        /*@ assert (fusc(N) == ((a * fusc(((n - 1) / 2))) + ((b + a) * fusc((((n - 1) / 2) + 1))))); */
        b = (b + a);
        /*@ assert (fusc(N) == ((a * fusc(((n - 1) / 2))) + (b * fusc((((n - 1) / 2) + 1))))); */
        n = ((n - 1) / 2);
        /*@ assert (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))); */
      }
      /*@ assert (n < d); */
      /*@ assert (fusc(N) == ((a * fusc(n)) + (b * fusc((n + 1))))); */
    }
  /*@ assert (n == 0); */
  /*@ assert (fusc(0) == 0); */
  /*@ assert (fusc(1) == 1); */
  /*@ assert (fusc(N) == ((a * fusc(0)) + (b * fusc((0 + 1))))); */
  /*@ assert (fusc(N) == ((a * 0) + (b * 1))); */
  /*@ assert (b == fusc(N)); */
  return b;
}