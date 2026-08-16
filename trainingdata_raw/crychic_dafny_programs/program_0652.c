// Generated C + ACSL

/*@
    requires n > 0;
    assigns \nothing;
    ensures \result == 1 <==> (n == 2 || (\forall integer x; 2 <= x < n ==> n % x != 0));
    ensures \result == 0 || \result == 1;
*/
int isPrime(int n)
{
  int b;
  if ((n < 2))
  {
    b = 1;
    /*@ assert b >= 0 && b <= 2147483647; */
  }
  else
  {
    b = 1;
    int factor = 2;
    /*@ assert factor >= 0 && factor <= 2147483647; */
/*@
  loop invariant 2 <= factor <= n;
  loop invariant b == 0 || b == 1;
  loop invariant b == 1 <==> (\forall integer x; 2 <= x < factor ==> n % x != 0);
  loop invariant b == 0 ==> (\exists integer x; 2 <= x < factor && n % x == 0);
  loop invariant factor == \at(factor, LoopEntry) + (\at(factor, LoopEntry) - \at(factor, LoopEntry)) || factor > \at(factor, LoopEntry);
  loop assigns factor, b;
  loop variant n - factor;
*/
    while ((b && (factor < n)))
      {
        if (((n % factor) == 0))
        {
          b = 0;
        }
        factor = (factor + 1);
      }
  }
  return b;
}