// Generated C + ACSL

/*@
  predicate Sorted(int *a, integer len, integer low, integer high) =
    \forall integer j, k; 0 <= j && j < k && k < high ==> a[j] <= a[k];
*/

/*@
  predicate SortedExcept(int *a, integer high, integer except) =
    \forall integer j, k; 0 <= j && j < k && k < high && j != except && k != except ==> a[j] <= a[k];
*/

/*@
    requires a != \null;
    requires a_len > 1;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void InsertionSortShuffle(int* a, int a_len)
{
  int up = 1;
  int injectValue = a[up];
  int injectPoint = up;
/*@
  loop invariant 1 <= up <= a_len;
  loop invariant 0 <= injectPoint <= up;
  loop invariant \forall integer i, j;
      0 <= i < j < up ==> a[i] <= a[j];
  loop assigns up, injectPoint, injectValue, a[0 .. a_len - 1];
  loop variant a_len - up;
*/
  while ((up < a_len))
    {
      injectValue = a[up];
      injectPoint = up;
/*@
  loop invariant 0 <= injectPoint <= \at(up, LoopEntry);
  loop invariant \forall integer k;
      injectPoint < k <= \at(up, LoopEntry) ==>
      a[k] == a[\at(k, LoopEntry) - (\at(up, LoopEntry) - \at(injectPoint, LoopEntry))];
  loop invariant \forall integer k;
      injectPoint <= k <= \at(up, LoopEntry) ==>
      \at(injectValue, LoopEntry) <= a[k];
  loop invariant \forall integer i, j;
      0 <= i < j < injectPoint ==> a[i] <= a[j];
  loop invariant \forall integer i, j;
      injectPoint < i < j <= \at(up, LoopEntry) ==> a[i] <= a[j];
  loop invariant \forall integer k;
      0 <= k < injectPoint && injectPoint < \at(up, LoopEntry) ==>
      a[k] <= a[injectPoint + 1];
  loop assigns injectPoint, a[0 .. \at(up, LoopEntry)];
  loop variant injectPoint;
*/
      while (((injectPoint >= 1) && (a[(injectPoint - 1)] > injectValue)))
        {
          a[injectPoint] = a[(injectPoint - 1)];
          injectPoint = (injectPoint - 1);
        }
      a[injectPoint] = injectValue;
      up = (up + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a_vals[] = {6, 2, 0, 6, 3, 5, 0, 4, 1, 6, 0};
  int* a = a_vals;
  int a_len = 11;
  InsertionSortShuffle(a, a_len);
  int b_vals[] = {8, 7};
  int* b = b_vals;
  int b_len = 2;
  InsertionSortShuffle(b, b_len);
}