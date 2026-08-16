// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \exists integer i; 0 <= i < a_len && a[i] == P;
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures a[\result] == P;
    ensures \forall integer k; 0 <= k < \result ==> a[k] != P;
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
  return n;
}