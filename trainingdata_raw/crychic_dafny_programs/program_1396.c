// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void BubbleSort(int* a, int a_len)
{
  int i = (a_len - 1);
/*@
  loop invariant -1 <= i < a_len;
  loop invariant \forall integer par1, par2;
    (0 <= par1 <= i && i < par2 < a_len) ==> a[par1] <= a[par2];
  loop invariant \forall integer elem1, elem2;
    (i < elem1 < elem2 < a_len) ==> a[elem1] <= a[elem2];
  loop assigns i, a[0..a_len-1];
  loop variant i;
*/
  while ((i > 0))
    {
      int j = 0;
/*@
  loop invariant 0 <= j <= i;
  loop invariant 1 <= i < a_len;
  loop invariant \forall integer k1, k2;
    0 <= k1 <= i && i < k2 < a_len ==> a[k1] <= a[k2];
  loop invariant \forall integer k;
    0 <= k < j ==> a[k] <= a[j];
  loop invariant \forall integer k1, k2;
    i < k1 < k2 < a_len ==> a[k1] <= a[k2];
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