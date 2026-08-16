// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer k, l; 0 <= k < l < a_len ==> a[k] <= a[l];
*/
void BubbleSort(int* a, int a_len)
{
  int i = (a_len - 1);
/*@
  loop invariant -1 <= i <= a_len - 1;
  loop invariant a_len == 0 <==> i == -1;
  loop invariant \forall integer k, l; i < k < l < a_len ==> a[k] <= a[l];
  loop invariant \forall integer k, l; 0 <= k <= i && i + 1 <= l < a_len ==> a[k] <= a[l];
  loop assigns i, a[0..a_len-1];
  loop variant i;
*/
  while ((i > 0))
    {
      int j = 0;
/*@
  loop invariant 1 <= i <= a_len - 1 && 0 <= j <= i;
  loop invariant \forall integer k, l; i < k < l < a_len ==> a[k] <= a[l];
  loop invariant \forall integer k, l; 0 <= k <= i && i + 1 <= l < a_len ==> a[k] <= a[l];
  loop invariant \forall integer k; 0 <= k < j ==> a[k] <= a[j];
  loop assigns j, a[0..i];
  loop variant i - j;
*/
      while ((j < i))
        {
          if ((a[j] > a[(j + 1)]))
          {
            int t = a[j];
            a[j] = a[(j + 1)];
            a[(j + 1)] = t;
          }
          j = (j + 1);
        }
      i = (i - 1);
    }
}