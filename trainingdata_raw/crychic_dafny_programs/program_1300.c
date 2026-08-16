// Generated C + ACSL

/*@
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer j; 0 <= j < a_len ==> a[\result] >= a[j];
*/
int FindMax(int* a, int a_len)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int index = 1;
/*@
  loop invariant 0 <= i < a_len;
  loop invariant 1 <= index <= a_len;
  loop invariant \forall integer k; 0 <= k < index ==> a[i] >= a[k];
  loop invariant \valid_read(a + (0..a_len-1));
  loop assigns i, index;
  loop variant a_len - index;
*/
  while ((index < a_len))
    {
      if ((a[index] > a[i]))
      {
        i = index;
      }
      index = (index + 1);
    }
  return i;
}
