// Generated C + ACSL

/*@
    requires a_len >= 0;
    requires a_len == 0 || (a != \null && \valid(a + (0 .. a_len-1)));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result == a_len || P == a[\result];
*/
int LinearSearch0(int* a, int a_len, int P)
{
  int n = 0;
  /*@ assert n >= 0 && n <= 2147483647; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \forall integer k; 0 <= k < n ==> a[k] != P;
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
  return n;  // Dafny implicit return
}

/*@
    requires a_len >= 0;
    requires a_len == 0 || (a != \null && \valid(a + (0 .. a_len-1)));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result == a_len || a[\result] == P;
    ensures \forall integer i; 0 <= i < \result ==> a[i] != P;
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
  return n;  // Dafny implicit return
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
  loop invariant \forall integer k; 0 <= k < n ==> a[k] != P;
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
  return n;  // Dafny implicit return
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
  /*@ assert \exists integer i; 0 <= i < a_len && m == a[i]; */
  /*@ assert m == a[0]; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \exists integer i; 0 <= i < a_len && m == a[i];
  loop invariant \forall integer i; 0 <= i < n ==> m <= a[i];
  loop assigns n, m;
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      /*@ assert 0 <= n < a_len; */
      if ((a[n] < m))
      {
        m = a[n];
        /*@ assert \exists integer i; 0 <= i < a_len && m == a[i]; */
      }
      /*@ assert \forall integer i; 0 <= i <= n ==> m <= a[i]; */
      n = (n + 1);
    }
  /*@ assert n == a_len; */
  /*@ assert \forall integer i; 0 <= i < a_len ==> m <= a[i]; */
  return m;  // Dafny implicit return
}