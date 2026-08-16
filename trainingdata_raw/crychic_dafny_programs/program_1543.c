// Generated C + ACSL

/*@
    requires k > 0;
    assigns \nothing;
    ensures \result / 2 == k - 1;
*/
int kthEven(int k)
{
  int e = 0;
  /*@ assert e >= 0 && e <= 2147483647; */
  int i = 1;
  /*@ assert i == 1 && e == 0; */
  /*@ assert e == 2 * (i - 1); */
/*@
  loop invariant 1 <= i <= k;
  loop invariant e == 2 * (i - 1);
  loop assigns i, e;
  loop variant k - i;
*/
  while ((i < k))
    {
      e = (e + 2);
      i = (i + 1);
      /*@ assert e == 2 * (i - 1); */
    }
  /*@ assert i == k; */
  /*@ assert e == 2 * (k - 1); */
  /*@ assert e / 2 == k - 1; */
  return e;  // Dafny implicit return
}