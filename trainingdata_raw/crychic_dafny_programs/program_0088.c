// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer x; 0 <= x < a_len ==> a[\result] <= a[x];
    ensures \forall integer x; 0 <= x < \result ==> a[\result] < a[x];
*/
int Getmini(int* a, int a_len)
{
  int min = a[0];
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer x; 0 <= x < i ==> min <= a[x];
  loop invariant \exists integer j; 0 <= j < a_len && min == a[j];
  loop assigns i, min;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] < min))
      {
        min = a[i];
      }
      i = (i + 1);
    }
  int k = 0;
/*@
  loop invariant 0 <= k <= a_len;
  loop invariant \forall integer x; 0 <= x < k ==> min < a[x];
  loop assigns k;
  loop variant a_len - k;
*/
  while ((k < a_len))
    {
      if (a[k] == min)
      {
        return k;
      }
      k = (k + 1);
    }
  return 0;
}