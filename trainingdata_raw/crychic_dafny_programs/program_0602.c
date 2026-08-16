// Generated C + ACSL

/*@
    requires a_len >= 0;
    requires a_len > 0 ==> \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \forall integer i; 0 <= i < a_len ==> \result >= a[i];
    ensures a_len == 0 ==> \result == 0;
*/
int maxarr(int *a, int a_len)
{
  int max = 0;
  /*@ assert max >= 0 && max <= 2147483647; */
  if ((a_len == 0))
  {
    return 0;
  }
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer j; 0 <= j < i ==> max >= a[j];
  loop invariant \at(i, LoopEntry) <= i;
  loop assigns i, max;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] > max))
      {
        max = a[i];
      }
      i = (i + 1);
    }
  return max;
}