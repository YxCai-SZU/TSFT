// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer k; 0 <= k < a_len ==> a[k] >= 0;
*/
void AbsArray(int* a, int a_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] >= 0;
  loop assigns i, a[0..a_len-1];
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] < 0))
      {
        a[i] = -a[i];
      }
      i = (i + 1);
    }
}
