// Generated C + ACSL

/*@
    requires a_len >= 0;
    requires a_len > 0 ==> a != \null;
    requires a_len > 0 ==> \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result >= 0 ==> \result < a_len && a[\result] == x;
    ensures \result < 0 ==> (\forall integer i; 0 <= i < a_len ==> a[i] != x);
*/
int Busca(int* a, int a_len, int x)
{
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant 0 <= r <= a_len;
  loop invariant \forall integer i; 0 <= i < r ==> a[i] != x;
  loop assigns r;
  loop variant a_len - r;
*/
  while ((r < a_len))
    {
      if (a[r] == x)
      {
        return r;
      }
      r = (r + 1);
    }
  r = -1;
  return r;  // Dafny implicit return
}