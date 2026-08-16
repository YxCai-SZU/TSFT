// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
*/
int LinearSearch0(int* a, int a_len, int P)
{
  int n = 0;
  /*@ assert n >= 0 && n <= 2147483647; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \forall integer k; 0 <= k < n ==> a[k] != P;
  loop invariant n == \at(n, LoopEntry) + (\at(n, LoopEntry) <= n ? n - \at(n, LoopEntry) : 0);
  loop assigns n;
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      if (a[n] == P)
      {
        return n;
      }
      n = (n + 1);
    }
  return n;
}

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result == a_len || P == a[\result];
    ensures \forall integer i; 0 <= i < \result ==> P != a[i];
*/
int LinearSearch1(int* a, int a_len, int P)
{
  int n = 0;
  /*@ assert n >= 0 && n <= 2147483647; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \forall integer i; 0 <= i < n ==> a[i] != P;
  loop assigns n;
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      if (a[n] == P)
      {
        return n;
      }
      n = (n + 1);
    }
  return n;
}

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \exists integer i; 0 <= i < a_len && a[i] == P;
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures a[\result] == P;
*/
int LinearSearch3(int* a, int a_len, int P)
{
  int n = 0;
  /*@ assert n >= 0 && n <= 2147483647; */
/*@
  loop invariant 0 <= n < a_len;
  loop invariant \exists integer i; n <= i < a_len && a[i] == P;
  loop invariant \forall integer j; \at(n, LoopEntry) <= j < n ==> a[j] != P;
  loop assigns n;
  loop variant a_len - n;
*/
  while (1)
    {
      if (a[n] == P)
      {
        return n;
      }
      n = (n + 1);
    }
  return n;
}

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < a_len && \result == a[i];
    ensures \forall integer i; 0 <= i < a_len ==> \result <= a[i];
*/
int min(int* a, int a_len)
{
  int n = 0;
  int m = a[0];
  /*@ assert m == a[0]; */
  /*@ assert n == 0; */
  /*@ assert 0 < a_len; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \forall integer i; 0 <= i < n ==> m <= a[i];
  loop invariant \exists integer i; 0 <= i < a_len && m == a[i];
  loop invariant n == 0 ==> m == a[0];
  loop invariant m == \at(m, LoopEntry) || (\exists integer j; \at(n, LoopEntry) <= j < n && m == a[j]);
  loop assigns n, m;
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      if ((a[n] < m))
      {
        m = a[n];
      }
      n = (n + 1);
    }
  return m;
}