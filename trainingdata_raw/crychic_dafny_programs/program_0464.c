// Generated C + ACSL

/*@
    requires a_len >= 0;
    requires a_len == 0 || (a != \null && \valid(a + (0 .. a_len-1)));
    assigns \nothing;
    ensures \result == 1 ==>
        (\forall integer x; 0 <= x < a_len ==> a[x] == a[a_len - x - 1]);
    ensures \result == 0 ==>
        (\exists integer x; 0 <= x < a_len && a[x] != a[a_len - x - 1]);
*/
int Symmetric(int* a, int a_len)
{
  if ((a_len == 0))
  {
    return 1;
  }
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer x; 0 <= x < i ==> a[x] == a[a_len - x - 1];
  loop assigns i;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] != a[((a_len - i) - 1)]))
      {
        return 0;
      }
      i = (i + 1);
    }
  return 1;
}
