// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer i; 0 <= i < a_len ==> a[i] <= a[\result];
*/
int max(int* a, int a_len)
{
  int x = 0;
  /*@ assert x >= 0 && x <= 2147483647; */
  int y = (a_len - 1);
  int m = y;
/*@
  loop invariant 0 <= x <= y < a_len;
  loop invariant m == x || m == y;
  loop invariant \forall integer i; 0 <= i < x ==> a[i] <= a[m];
  loop invariant \forall integer i; y < i < a_len ==> a[i] <= a[m];
  loop assigns x, y, m;
  loop variant y - x;
*/
  while ((x != y))
    {
      if ((a[x] <= a[y]))
      {
        x = (x + 1);
        m = y;
      }
      else
      {
        y = (y - 1);
        m = x;
      }
    }
  return x;
}