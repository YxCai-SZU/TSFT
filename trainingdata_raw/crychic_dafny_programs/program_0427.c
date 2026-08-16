// Generated C + ACSL

/*@ logic integer R(integer n) = 
  @   (n == 0) ? 0 : 
  @   (R(n-1) > n) ? R(n-1) - n : R(n-1) + n;
  @*/

/*@ requires n >= 0;
  @ decreases n;
  @*/
int R(int n)
{
  return ((n == 0)) ? (0) : (((R((n - 1)) > n)) ? ((R((n - 1)) - n)) : ((R((n - 1)) + n)));
}

/*@ requires n >= 0;
  @ requires n <= 46340; // Ensures no overflow: n*(n+1)/2 fits in int
  @ ensures \result == R(n);
  @*/
int calcR(int n)
{
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i && i <= n;
  loop invariant r == R(i);
  loop invariant \at(n, LoopEntry) == n;
  loop invariant -i * (i + 1) / 2 <= r <= i * (i + 1) / 2;
  loop invariant i <= 46340 ==> r <= 2147483647;
  loop invariant i <= 46340 ==> r >= -2147483648;
  loop assigns i, r;
  loop variant n - i;
*/
  while ((i < n))
    {
      /*@ assert (i < n) && (0 <= i) && (i <= n) && (r == R(i)); */
      /*@ assert i + 1 <= n; */
      /*@ assert -i * (i + 1) / 2 <= r <= i * (i + 1) / 2; */
      /*@ assert ((r > (i + 1)) && (0 <= i + 1) && (i + 1 <= n) && (((r - i) - 1) == R((i + 1)))) || ((r <= (i + 1)) && (0 <= i + 1) && (i + 1 <= n) && (((r + i) + 1) == R((i + 1)))); */
      i = (i + 1);
      /*@ assert ((r > i) && (0 <= i) && (i <= n) && ((r - i) == R(i))) || ((r <= i) && (0 <= i) && (i <= n) && ((r + i) == R(i))); */
      /*@ assert -i * (i + 1) / 2 - i <= r - i <= i * (i + 1) / 2 + i; */
      if ((r > i))
      {
        r = (r - i);
        /*@ assert r == R(i); */
      }
      else
      {
        r = (r + i);
        /*@ assert r == R(i); */
      }
      /*@ assert (0 <= i) && (i <= n) && (r == R(i)); */
      /*@ assert -(i * (i + 1)) / 2 <= r <= (i * (i + 1)) / 2; */
    }
  /*@ assert i == n; */
  /*@ assert r == R(n); */
  return r;  // Dafny implicit return
}