// Generated C + ACSL

/*@
    requires a_len >= 1;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer i; 0 <= i < a_len ==> a[i] <= a[\result];
*/
int FindMax(int* a, int a_len)
{
  int m = a[0];
  int r = 0;
  int i = 1;
/*@
  loop invariant 1 <= i <= a_len;
  loop invariant 0 <= r < a_len;
  loop invariant m == a[r];
  loop invariant \forall integer j; 0 <= j < i ==> a[j] <= a[r];
  loop assigns i, r, m;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] > m))
      {
        r = i;
        m = a[i];
      }
      i = (i + 1);
    }
  int max = r;
  /*@ assert max >= 0 && max <= 2147483647; */
  return max;  // Dafny implicit return
}
