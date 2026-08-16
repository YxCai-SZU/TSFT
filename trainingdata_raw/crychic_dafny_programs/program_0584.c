// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void BubbleSort(int* a, int a_len)
{
  int down = a_len;
/*@
  loop invariant 0 <= down <= a_len;
  loop invariant \forall integer i, j;
    0 <= i < down && down <= j < a_len ==> a[i] <= a[j];
  loop invariant \forall integer i, j;
    down <= i < j < a_len ==> a[i] <= a[j];
  loop assigns down, a[0..a_len-1];
  loop variant down;
*/
  while ((down > 0))
    {
      int up = 0;
/*@
  loop invariant 0 <= up <= down - 1;
  loop invariant \forall integer k; 0 <= k < up ==> a[k] <= a[up];
  loop invariant \forall integer i, j;
    0 <= i < down && down <= j < a_len ==> a[i] <= a[j];
  loop invariant \forall integer i, j;
    down <= i < j < a_len ==> a[i] <= a[j];
  loop assigns up, a[0..down-1];
  loop variant down - 1 - up;
*/
      while ((up < (down - 1)))
        {
          if ((a[up] > a[(up + 1)]))
          {
            int temp = a[up];
            a[up] = a[up + 1];
            a[up + 1] = temp;
          }
          up = (up + 1);
        }
      down = (down - 1);
    }
}

/*@
  predicate Sorted(int *a, integer len, integer l, integer r) =
    \forall integer i, j; l <= i && i < j && j < r ==> a[i] <= a[j];
*/