// Generated C + ACSL

/*@
    requires X != \null;
    requires X_len >= 1;
    requires n == X_len;
    requires \valid(X + (0 .. X_len-1));
    assigns X[0 .. X_len-1];
*/
void QuicksortPartition(int* X, int X_len, int n, int p)
{
  int a = 0;
  /*@ assert a >= 0 && a <= 2147483647; */
/*@
  loop invariant 0 <= a <= n;
  loop invariant \forall integer x; 0 <= x < a ==> X[x] <= p;
  loop assigns a;
  loop variant n - a;
*/
  while (((a < n) && (X[a] <= p)))
    {
      a = (a + 1);
    }
  int b = (a + 1);
  /*@ assert b >= 0 && b <= 2147483647; */
/*@
  loop invariant 0 <= a < b <= n + 1;
  loop invariant b == n + 1 ==> a == n;
  loop invariant \forall integer x; 0 <= x <= a - 1 ==> X[x] <= p;
  loop invariant a == n || (\forall integer x; a <= x < b ==> X[x] > p);
  loop invariant \at(a, LoopEntry) <= a <= n;
  loop invariant \at(b, LoopEntry) <= b <= n + 1;
  loop assigns a, b, X[0..n-1];
  loop variant n - b;
*/
  while ((b < n))
    {
      if ((X[b] <= p))
      {
        int t = X[b];
        X[b] = X[a];
        X[a] = t;
        a = (a + 1);
      }
      b = (b + 1);
    }
}
