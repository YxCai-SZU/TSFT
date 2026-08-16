// Generated C + ACSL

/*@
  predicate isSorted(int *a, integer len) =
    \forall integer i, j; 0 <= i <= j < len ==> a[i] <= a[j];
*/

/*@
    requires a != \null;
    requires \valid_read(a + (0 .. a_len-1));
    requires a_len >= 0 && a_len <= 2147483647;
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
    assigns \nothing;
    ensures \result == 1 <==> (\exists integer i; 0 <= i < a_len && a[i] == K);
    ensures \result == 0 <==> (\forall integer i; 0 <= i < a_len ==> a[i] != K);
*/
int binSearch(int* a, int a_len, int K)
{
  int lo = 0;
  /*@ assert lo >= 0 && lo <= 2147483647; */
  int hi = a_len;
  /*@ assert hi >= 0 && hi <= 2147483647; */
/*@
  loop invariant 0 <= lo <= hi <= a_len;
  loop invariant \forall integer i; 0 <= i < a_len ==> ((i < lo || hi <= i) ==> a[i] != K);
  loop invariant \forall integer i; 0 <= i < lo ==> a[i] < K;
  loop invariant \forall integer i; hi <= i < a_len ==> a[i] > K;
  loop invariant \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
  loop invariant \at(lo, LoopEntry) <= lo;
  loop invariant hi <= \at(hi, LoopEntry);
  loop assigns lo, hi;
  loop variant hi - lo;
*/
  while ((lo < hi))
    {
      /*@ assert lo < hi; */
      /*@ assert 0 <= lo < hi <= a_len; */
      int mid = ((lo + hi) / 2);
      /*@ assert mid >= 0 && mid <= 2147483647; */
      /*@ assert lo <= mid && mid < hi; */
      if ((a[mid] < K))
      {
        /*@ assert (a[lo] <= a[mid]); */
        /*@ assert (a[mid] < K); */
        /*@ assert \forall integer i; lo <= i <= mid ==> a[i] < K; */
        lo = (mid + 1);
        /*@ assert mid < lo && lo <= hi; */
      }
      else
      if ((a[mid] > K))
      {
        /*@ assert (K < a[mid]); */
        /*@ assert \forall integer i; mid <= i < hi ==> a[i] > K; */
        hi = mid;
        /*@ assert lo <= hi && hi == mid; */
      }
      else
      {
        /*@ assert a[mid] == K; */
        return 1;
      }
    }
  /*@ assert lo == hi; */
  /*@ assert \forall integer i; 0 <= i < a_len ==> (i < lo || lo <= i) ==> a[i] != K; */
  return 0;
}