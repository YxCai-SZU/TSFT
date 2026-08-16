// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 1;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer k; 0 <= k < a_len ==> a[k] <= a[\result];
*/
int FindMax(int* a, int a_len)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int j = 1;
/*@
  loop invariant 0 <= i < j <= a_len;
  loop invariant \forall integer k; 0 <= k < j ==> a[k] <= a[i];
  loop invariant \valid_read(a + (0..a_len-1));
  loop invariant i < a_len;
  loop assigns i, j;
  loop variant a_len - j;
*/
  while ((j < a_len))
    {
      if ((a[j] > a[i]))
      {
        i = j;
      }
      j = (j + 1);
    }
  return i;  // Dafny implicit return
}
