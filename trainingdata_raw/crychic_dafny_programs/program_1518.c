// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result < a_len ==> a[\result] == e;
    ensures \forall integer i; 0 <= i < \result ==> a[i] != e;
*/
int foo(int* a, int a_len, int e)
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
      if (e == a[n])
      {
        return n;
      }
      n = (n + 1);
    }
  return n;  // Dafny implicit return
}