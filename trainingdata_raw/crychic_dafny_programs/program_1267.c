// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 1;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \forall integer k; 0 <= k < a_len ==> a[k] <= \result;
*/
int FindMax(int* a, int a_len)
{
  int max = a[0];
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= max;
  loop invariant i == 0 ==> max == a[0];
  loop invariant i > 0 ==> (\exists integer j; 0 <= j < i && max == a[j]);
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
  /*@ assert i == a_len; */
  /*@ assert \forall integer k; 0 <= k < a_len ==> a[k] <= max; */
  return max;
}