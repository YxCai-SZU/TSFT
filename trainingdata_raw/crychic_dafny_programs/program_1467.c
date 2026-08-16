// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer k; 0 <= k < a_len ==> a[k] <= a[\result];
*/
int FindMax(int* a, int a_len)
{
  int i = 0;
  int idx = 0;
  /*@ assert idx >= 0 && idx <= 2147483647; */
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant 0 <= idx <= i;
  loop invariant 0 <= idx < a_len;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= a[idx];
  loop assigns i, idx;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] > a[idx]))
      {
        idx = i;
      }
      i = (i + 1);
    }
  return idx;
}
