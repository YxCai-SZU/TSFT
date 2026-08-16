// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result == a_len || P == a[\result];
    ensures \forall integer i; 0 <= i < \result ==> P != a[i];
*/
int LinearSearch(int* a, int a_len, int P)
{
  int n = 0;
  /*@ assert n >= 0 && n <= 2147483647; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \forall integer i; 0 <= i < n ==> P != a[i];
  loop assigns n;
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      if (P == a[n])
      {
        return n;
      }
      n = (n + 1);
    }
  return n;
}