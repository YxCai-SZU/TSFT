// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < a_len && \result == a[i];
    ensures \forall integer i; 0 <= i < a_len ==> \result <= a[i];
*/
int Minimum(int* a, int a_len)
{
  int n = 0;
  int m = a[0];
  /*@ assert m == a[0]; */
  /*@ assert 0 < a_len; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \exists integer i; 0 <= i < a_len && m == a[i];
  loop invariant \forall integer i; 0 <= i < n ==> m <= a[i];
  loop invariant n > 0 ==> (\exists integer j; 0 <= j < n && m == a[j]);
  loop invariant n == 0 ==> m == a[0];
  loop assigns n, m;
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      if ((a[n] < m))
      {
        m = a[n];
        /*@ assert m == a[n]; */
        /*@ assert 0 <= n < a_len; */
      }
      /*@ assert \forall integer i; 0 <= i <= n ==> m <= a[i]; */
      n = (n + 1);
      /*@ assert n > 0; */
      /*@ assert \exists integer i; 0 <= i < a_len && m == a[i]; */
    }
  /*@ assert n == a_len; */
  /*@ assert \exists integer i; 0 <= i < a_len && m == a[i]; */
  /*@ assert \forall integer i; 0 <= i < a_len ==> m <= a[i]; */
  return m;  // Dafny implicit return
}