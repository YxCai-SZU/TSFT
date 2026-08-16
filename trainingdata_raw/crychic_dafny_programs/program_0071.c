// Generated C + ACSL

/*@
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer k; 0 <= k < a_len ==> a[k] <= a[\result];
*/
int FindMax(int* a, int a_len)
{
  int j = 0;
  int max = a[0];
  int i = 1;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 1 <= i <= a_len;
  loop invariant \forall integer k; 0 <= k < i ==> max >= a[k];
  loop invariant 0 <= j < a_len;
  loop invariant a[j] == max;
  loop invariant \forall integer k; 0 <= k < i ==> a[j] >= a[k];
  loop assigns i, j, max;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((max < a[i]))
      {
        max = a[i];
        j = i;
      }
      i = (i + 1);
    }
  i = j;
  return i;  // Dafny implicit return
}
