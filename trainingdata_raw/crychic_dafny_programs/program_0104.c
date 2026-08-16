// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \forall integer i; 0 <= i < a_len ==> \result <= a[i];
    ensures \exists integer i; 0 <= i < a_len && \result == a[i];
*/
int minArray(int* a, int a_len)
{
  int r = a[0];
  /*@ assert r == a[0]; */
  int i = 1;
/*@
  loop invariant 0 < i <= a_len;
  loop invariant \forall integer x; 0 <= x < i ==> r <= a[x];
  loop invariant \exists integer x; 0 <= x < i && r == a[x];
  loop assigns i, r;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((r > a[i]))
      {
        r = a[i];
      }
      i = (i + 1);
    }
  /*@ assert i == a_len; */
  /*@ assert \forall integer x; 0 <= x < a_len ==> r <= a[x]; */
  /*@ assert \exists integer x; 0 <= x < a_len && r == a[x]; */
  return r;  // Dafny implicit return
}