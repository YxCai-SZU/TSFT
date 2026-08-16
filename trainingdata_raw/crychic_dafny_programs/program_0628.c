// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result != -1 ==> 0 <= \result < a_len;
    ensures \result != -1 ==> a[\result] == x;
    ensures \result != -1 ==> \result % 2 == 0;
    ensures \result == -1 ==>
        (\forall integer k; 0 <= k < a_len && k % 2 == 0 ==> a[k] != x);
*/
int findInEven(int* a, int a_len, int x)
{
  int r = -1;
  /*@ assert r == -1; */
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len + 1;
  loop invariant i % 2 == 0;
  loop invariant r == -1 || (0 <= r < a_len && r % 2 == 0);
  loop invariant r != -1 ==> 0 <= r < i;
  loop invariant r != -1 ==> a[r] == x;
  loop invariant r == -1 ==>
    (\forall integer y; 0 <= y < i && y % 2 == 0 ==> a[y] != x);
  loop assigns i, r;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((x == a[i]))
      {
        r = i;
        /*@ assert r == i; */
        /*@ assert a[r] == x; */
        /*@ assert r % 2 == 0; */
      }
      /*@ assert x == a[i] ==> r == i; */
      /*@ assert x != a[i] ==> r == \at(r, LoopCurrent); */
      i = (i + 2);
    }
  /*@ assert i >= a_len; */
  /*@ assert r != -1 ==> (0 <= r < a_len && a[r] == x && r % 2 == 0); */
  /*@ assert r == -1 ==> (\forall integer k; 0 <= k < a_len && k % 2 == 0 ==> a[k] != x); */
  return r;  // Dafny implicit return
}