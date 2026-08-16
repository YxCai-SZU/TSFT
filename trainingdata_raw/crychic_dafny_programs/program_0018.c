// Generated C + ACSL

/*@
    requires N >= 0;
    assigns \nothing;
    ensures \result == N * (N + 1) / 2;
*/
int TriangleNumber(int N)
{
  int t = 0;
  /*@ assert t >= 0 && t <= 2147483647; */
  int n = 0;
/*@
  loop invariant 0 <= n <= N;
  loop invariant t == n * (n + 1) / 2;
  loop invariant n >= \at(n, LoopEntry);
  loop invariant \at(n, LoopEntry) <= N ==> t >= \at(t, LoopEntry);
  loop assigns n, t;
  loop variant N - n;
*/
  while ((n < N))
    {
      n = (n + 1);
      t = (t + n);
    }
  return t;  // Dafny implicit return
}
