// Generated C + ACSL

/*@
    requires 0 <= n <= a_len;
    requires a != \null;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result <==> (\forall integer i, j; (0 <= j <= i < n) ==> a[i] >= a[j]);
*/
int sorted(int* a, int a_len, int n)
{
  /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall integer k, l; (0 <= l <= k < i) ==> a[k] >= a[l];
    loop assigns i;
    loop variant n - i;
  */
  for (int i = 0; i < n; i++) {
    /*@
      loop invariant 0 <= j <= i + 1;
      loop invariant \forall integer l; (0 <= l < j) ==> a[i] >= a[l];
      loop assigns j;
      loop variant i + 1 - j;
    */
    for (int j = 0; j <= i; j++) {
      if (a[i] < a[j]) {
        /*@ assert a[i] < a[j]; */
        /*@ assert 0 <= j <= i < n; */
        /*@ assert \exists integer k, l; (0 <= l <= k < n) && a[k] < a[l]; */
        return 0;
      }
      /*@ assert a[i] >= a[j]; */
    }
    /*@ assert \forall integer l; (0 <= l <= i) ==> a[i] >= a[l]; */
  }
  /*@ assert \forall integer k, l; (0 <= l <= k < n) ==> a[k] >= a[l]; */
  return 1;
}

/*@
    requires 0 <= n < a_len;
    requires a != \null;
    requires \valid_read(a + (0 .. a_len-1));
    requires \forall integer i, j; 0 <= i < j < n ==> a[i] <= a[j];
    assigns \nothing;
    ensures \forall integer i, j; 0 <= i < j < n ==> a[i] <= a[j];
    ensures -(n + 1) <= \result <= n;
    ensures \result >= 0 ==> a[\result] == e;
    ensures \result >= 0 ==> \forall integer i; 0 <= i < \result ==> a[i] <= e;
    ensures \result >= 0 ==> \forall integer i; \result <= i < n ==> a[i] >= e;
    ensures \result < 0 ==> \forall integer i; 0 <= i < -\result - 1 ==> a[i] < e;
    ensures \result < 0 ==> \forall integer i; -\result - 1 <= i < n ==> a[i] > e;
*/
int binaryIndex(int* a, int a_len, int n, int e)
{
  int l = 0;
  int r = (n - 1);
/*@
  loop invariant 0 <= l <= n;
  loop invariant -1 <= r < n;
  loop invariant \forall integer i; 0 <= i < l ==> a[i] < e;
  loop invariant \forall integer i; r < i < n ==> a[i] > e;
  loop assigns l, r;
  loop variant r - l;
*/
  while ((l <= r))
    {
      int m = (l + ((r - l) / 2));
      /*@ assert l <= m <= r; */
      if ((a[m] < e))
      {
        l = (m + 1);
      }
      else
      if ((a[m] > e))
      {
        r = (m - 1);
      }
      else
      {
        return m;
      }
    }
  /*@ assert (l >= 0); */
  return -(l + 1);
}