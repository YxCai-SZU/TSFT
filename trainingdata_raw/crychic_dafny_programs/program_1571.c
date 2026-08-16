// Generated C + ACSL

/*@
    requires v != \null;
    requires v_len >= 0;
    requires \valid_read(v + (0 .. v_len-1));
    assigns \nothing;
    ensures 0 <= \result <= v_len;
    ensures \forall integer j; 0 <= j < \result ==> v[j] != 0;
    ensures \result != v_len ==> v[\result] == 0;
*/
int mfirstCero(int* v, int v_len)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= i <= v_len;
  loop invariant \forall integer j; 0 <= j < i ==> v[j] != 0;
  loop assigns i;
  loop variant v_len - i;
*/
  while (((i < v_len) && (v[i] != 0)))
    {
      i = (i + 1);
    }
  return i;  // Dafny implicit return
}
