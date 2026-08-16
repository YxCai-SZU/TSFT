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
  int max = 0;
  /*@ assert max >= 0 && max <= 2147483647; */
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant 0 <= max < a_len;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= a[max];
  loop assigns i, max;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] > a[max]))
      {
        max = i;
      }
      i = (i + 1);
    }
  return max;
}
