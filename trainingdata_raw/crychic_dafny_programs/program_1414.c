// Generated C + ACSL

/*@
  predicate positive(int *s, integer len) =
    \forall integer u; 0 <= u && u < len ==> s[u] >= 0;
*/

/*@
    requires v != \null;
    requires v_len >= 0;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
*/
void mfirstNegative(int* v, int v_len)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int b = 0;
  /*@ assert b >= 0 && b <= 2147483647; */
/*@
  loop invariant 0 <= i <= v_len;
  loop invariant b <==> (\exists integer k; 0 <= k < i && v[k] < 0);
  loop invariant b ==> (i >= 1 && v[i - 1] < 0);
  loop invariant b ==> (\forall integer k; 0 <= k < i - 1 ==> v[k] >= 0);
  loop invariant !b ==> (\forall integer k; 0 <= k < i ==> v[k] >= 0);
  loop assigns i, b;
  loop variant v_len - i;
*/
  while (((i < v_len) && !(b)))
    {
      b = (v[i] < 0);
      i = (i + 1);
    }
  if (b)
  {
    i = (i - 1);
  }
}

/*@
    requires v != \null;
    requires v_len >= 0;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
*/
void mfirstNegative2(int* v, int v_len)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int b = 0;
  /*@ assert b >= 0 && b <= 2147483647; */
/*@
  loop invariant 0 <= i <= v_len;
  loop invariant b ==> (i < v_len && v[i] < 0);
  loop invariant b ==> (\forall integer k; 0 <= k < i ==> v[k] >= 0);
  loop invariant !b ==> (\forall integer k; 0 <= k < i ==> v[k] >= 0);
  loop invariant b ==> (b == 1);
  loop invariant !b ==> (b == 0);
  loop assigns i, b;
  loop variant v_len - i + (b ? 0 : 1);
*/
  while (((i < v_len) && !(b)))
    {
      /*@ assert !b; */
      /*@ assert i < v_len; */
      /*@ assert \forall integer k; 0 <= k < i ==> v[k] >= 0; */
      b = (v[i] < 0);
      /*@ assert b <==> v[i] < 0; */
      if (!(b))
      {
        /*@ assert v[i] >= 0; */
        /*@ assert \forall integer k; 0 <= k <= i ==> v[k] >= 0; */
        i = (i + 1);
      }
      /*@ assert b ==> (i < v_len && v[i] < 0); */
      /*@ assert b ==> (\forall integer k; 0 <= k < i ==> v[k] >= 0); */
      /*@ assert !b ==> (\forall integer k; 0 <= k < i ==> v[k] >= 0); */
    }
}