// Generated C + ACSL

/*@
    requires numelems > 0;
    requires a != \null;
    requires a_len >= numelems;
    requires \valid(a + (0 .. numelems-1));
    assigns \nothing;
    ensures (\result == -1 &&
             (\forall integer j; 0 <= j < numelems ==> a[j] != v)) ||
            (0 <= \result < numelems && a[\result] == v);
*/
int find(int v, int* a, int a_len, int numelems)
{
  int i = 0;
  int r = -1;
/*@
  loop invariant 0 <= i <= numelems;
  loop invariant (r == -1 && \forall integer j; 0 <= j < i ==> a[j] != v) ||
                 (0 <= r < i && a[r] == v);
  loop invariant r >= -1 && r < numelems;
  loop invariant r >= 0 ==> a[r] == v;
  loop invariant r >= 0 ==> r < i;
  loop assigns i, r;
  loop variant numelems - i;
*/
  while ((i < numelems))
    {
      if ((a[i] == v))
      {
        r = i;
        /*@ assert a[r] == v; */
        /*@ assert 0 <= r < numelems; */
        break;;
      }
      /*@ assert a[i] != v; */
      i = (i + 1);
    }
  /*@ assert i <= numelems; */
  /*@ assert r == -1 ==> i == numelems; */
  /*@ assert r == -1 ==> \forall integer j; 0 <= j < numelems ==> a[j] != v; */
  /*@ assert r >= 0 ==> (0 <= r < numelems && a[r] == v); */
  return r;  // Dafny implicit return
}