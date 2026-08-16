// Generated C + ACSL

/*@
  predicate sorted(int *a, integer len, integer l, integer u) =
    \forall integer i, j; 0 <= l && l <= i && i <= j && j <= u && u < len ==> a[i] <= a[j];
*/

/*@
  predicate partitioned(int *a, integer len, integer i) =
    \forall integer k, k_prime;
      0 <= k && k <= i && i < k_prime && k_prime < len ==> a[k] <= a[k_prime];
*/

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void BubbleSort(int *a, int a_len)
{
  int i = (a_len - 1);
/*@
  loop invariant 0 <= i < a_len;
  loop invariant \forall integer k1, k2; i < k1 < k2 < a_len ==>
                   a[k1] <= a[k2];
  loop invariant \forall integer k; i < k < a_len ==>
                   (\forall integer m; 0 <= m <= i ==> a[m] <= a[k]);
  loop assigns i, a[0..a_len-1];
  loop variant i;
*/
  while ((i > 0))
    {
      int j = 0;
/*@
  loop invariant 0 <= j <= i;
  loop invariant 0 < i < a_len;
  loop invariant \forall integer k; i < k < a_len ==>
                   (\forall integer m; 0 <= m <= i ==> a[m] <= a[k]);
  loop invariant \forall integer k1, k2; i < k1 < k2 < a_len ==>
                   a[k1] <= a[k2];
  loop invariant \forall integer k; 0 <= k < j ==> a[k] <= a[j];
  loop assigns j, a[0..i];
  loop variant i - j;
*/
      while ((j < i))
        {
          if ((a[j] > a[(j + 1)]))
          {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
          }
          j = (j + 1);
        }
      i = (i - 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a[5];
  a[0] = 9; a[1] = 4; a[2] = 6; a[3] = 3; a[4] = 8;
  BubbleSort(a, 5);
  int k = 0;
/*@
  loop invariant 0 <= k <= 5;
  loop assigns k;
  loop variant 5 - k;
*/
  while ((k < 5))
    {
      /* unsupported stmt: print a[k], "\n"; */
      k = (k + 1);
    }
}