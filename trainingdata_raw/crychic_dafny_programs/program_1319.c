// Generated C + ACSL

/*@
    requires n >= 0;
    decreases n;
    assigns \nothing;
*/
int R(int n)
{
  return ((n == 0)) ? (0) : (((R((n - 1)) > n)) ? ((R((n - 1)) - n)) : ((R((n - 1)) + n)));
}

/*@ 
    axiomatic RLogic {
      logic integer R_logic(integer n);
      
      axiom R_base: R_logic(0) == 0;
      
      axiom R_rec: \forall integer n; n > 0 ==>
        R_logic(n) == (R_logic(n-1) > n ? R_logic(n-1) - n : R_logic(n-1) + n);
      
      axiom R_bound: \forall integer n; n >= 0 ==>
        -n * (n+1) / 2 <= R_logic(n) <= n * (n+1) / 2;
    }
*/

/*@
    requires n >= 0;
    requires n <= 1000;
    assigns \nothing;
    ensures \result == R_logic(n);
    ensures -n * (n+1) / 2 <= \result <= n * (n+1) / 2;
*/
int calcR(int n)
{
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
  /*@ assert r == R_logic(0); */
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant r == R_logic(i);
  loop invariant -i * (i+1) / 2 <= r <= i * (i+1) / 2;
  loop invariant \at(n, LoopEntry) == n;
  loop assigns i, r;
  loop variant n - i;
*/
  while ((i < n))
    {
      /*@ assert (((i < n) && 0 <= i <= n) && (r == R_logic(i))); */
      /*@ assert -i * (i+1) / 2 <= r <= i * (i+1) / 2; */
      i = (i + 1);
      /*@ assert r == R_logic(i-1); */
      /*@ assert 0 < i <= n; */
      /*@ assert ((r > i) ==> (r - i == R_logic(i))); */
      /*@ assert ((r <= i) ==> (r + i == R_logic(i))); */
      if ((r > i))
      {
        r = (r - i);
      }
      else
      {
        r = (r + i);
      }
      /*@ assert (0 <= i <= n && (r == R_logic(i))); */
      /*@ assert -i * (i+1) / 2 <= r <= i * (i+1) / 2; */
    }
  /*@ assert i == n; */
  /*@ assert r == R_logic(n); */
  return r;  // Dafny implicit return
}