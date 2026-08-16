// Generated C + ACSL

/*@
    requires a_len >= 0;
    requires a_len > 0 ==> a != \null;
    requires a_len > 0 ==> \valid_read(a + (0 .. a_len-1));
    requires \forall integer i; 1 <= i < a_len ==> a[i - 1] < a[i];
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] < a[j];
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \forall integer i; 0 <= i < \result ==> a[i] < circle;
    ensures \forall integer i; \result <= i < a_len ==> circle <= a[i];
*/
int BinarySearch(int* a, int a_len, int circle)
{
  int lo = 0;
  int hi = a_len;
/*@
  loop invariant 0 <= lo <= hi <= a_len;
  loop invariant \forall integer i; 0 <= i < lo ==> a[i] < circle;
  loop invariant \forall integer i; hi <= i < a_len ==> a[i] >= circle;
  loop assigns lo, hi;
  loop variant hi - lo;
*/
  while ((lo < hi))
    {
      int mid = ((lo + hi) / 2);
      if ((a[lo] > circle))
      {
        hi = lo;
      }
      else
      if ((a[(hi - 1)] < circle))
      {
        lo = hi;
      }
      else
      if ((a[mid] < circle))
      {
        lo = (mid + 1);
      }
      else
      {
        hi = mid;
      }
    }
  int n = lo;
  /*@ assert n >= 0 && n <= 2147483647; */
  /*@ assert !(0); */
  return n;  // Dafny implicit return
}

/*@
    requires r != \null;
    requires x != \null;
    requires r_len >= 0;
    requires x_len >= 0;
    requires \valid_read(r + (0 .. r_len-1));
    requires \valid_read(x + (0 .. x_len-1));
    requires \forall integer i; 1 <= i < x_len ==> x[i - 1] < x[i];
    requires \forall integer i, j; 0 <= i < j < x_len ==> x[i] < x[j];
    assigns \nothing;
    ensures \result == 0 ==>
        \forall integer i, j; 0 <= i < r_len && 0 <= j < x_len ==> r[i] != x[j];
    ensures \result != 0 ==>
        \exists integer i, j; 0 <= i < r_len && 0 <= j < x_len && r[i] == x[j];
*/
int Tangent(int* r, int r_len, int* x, int x_len)
{
  int found = 0;
  /*@ assert found >= 0 && found <= 2147483647; */
  int n = 0;
  int f = x_len;
/*@
  loop invariant 0 <= n <= r_len;
  loop invariant found == 0 || found == 1;
  loop invariant found == 0 ==>
    \forall integer i, j; 0 <= i < n && 0 <= j < x_len ==> r[i] != x[j];
  loop invariant found == 1 ==>
    0 <= f < x_len && n < r_len && r[n] == x[f];
  loop invariant \at(r_len, LoopEntry) == r_len;
  loop invariant \at(x_len, LoopEntry) == x_len;
  loop assigns n, f, found;
  loop variant (r_len - n) + (found == 0 ? 1 : 0);
*/
  while (((n != r_len) && !(found)))
    {
      f = BinarySearch(x, x_len, r[n]);
      if (((f != x_len) && (r[n] == x[f])))
      {
        found = 1;
      }
      else
      {
        n = (n + 1);
      }
    }
  /*@ assert ((!(found) && (n == r_len)) || ((found && (n != r_len)) && (r[n] == x[f]))); */
  /*@ assert !(0); */
  return found;  // Dafny implicit return
}