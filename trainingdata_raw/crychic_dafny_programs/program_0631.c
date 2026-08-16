// Generated C + ACSL

/*@
    requires N >= 0;
    assigns \nothing;
    ensures \result * \result <= N < (\result + 1) * (\result + 1);
*/
int SquareRoot(int N)
{
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant r * r <= N;
  loop invariant r >= \at(r, LoopEntry);
  loop invariant \forall integer k; \at(r, LoopEntry) <= k <= r ==> k * k <= N;
  loop invariant (r + 1) * (r + 1) > N ==> r * r <= N < (r + 1) * (r + 1);
  loop assigns r;
  loop variant N - r * r;
*/
  while ((((r + 1) * (r + 1)) <= N))
    {
      r = (r + 1);
    }
  return r;  // Dafny implicit return
}
