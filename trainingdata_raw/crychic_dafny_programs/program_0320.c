// Generated C + ACSL

/*@
    requires n >= 0;
    requires a != \null;
    requires a_len >= n;
    requires \valid(a + (0 .. n-1));
    assigns \nothing;
    ensures \result == 1 ==>
        (\forall integer j; 0 <= j < n ==> a[j] == v);
    ensures \result == 0 ==>
        (\exists integer j; 0 <= j < n && a[j] != v);
*/
int filled(int* a, int a_len, int v, int n)
{
  int i = 0;
  int s = 1;
  /*@ assert s >= 0 && s <= 2147483647; */
/*@
  loop invariant 0 <= i <= n;
  loop invariant s == 1 ==> \forall integer j; 0 <= j < i ==> a[j] == v;
  loop invariant s == 0 ==> \exists integer j; 0 <= j < i && a[j] != v;
  loop invariant s == 0 || s == 1;
  loop assigns i, s;
  loop variant n - i;
*/
  while ((i < n))
    {
      if ((a[i] != v))
      {
        s = 0;
        break;;
      }
      i = (i + 1);
    }
  return s;  // Dafny implicit return
}
