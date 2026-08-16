// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \exists integer i; 0 <= i < a_len && a[i] == e;
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures a[\result] == e;
    ensures \forall integer k; 0 <= k < \result ==> a[k] != e;
*/
int LinearSearch(int* a, int a_len, int e)
{
  int n = 0;
  /*@ assert n >= 0 && n <= 2147483647; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \forall integer i; 0 <= i < n ==> e != a[i];
  loop assigns n;
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      if ((e == a[n]))
      {
        return n;
      }
      n = (n + 1);
    }
  return n;  // Dafny implicit return
}