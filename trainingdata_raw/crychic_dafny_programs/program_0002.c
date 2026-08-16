// Generated C + ACSL

/*@
    requires v != \null;
    requires v_len >= 0;
    requires \valid(v + (0 .. v_len-1));
    assigns v[0 .. v_len-1];
*/
void replace(int* v, int v_len, int x, int y)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= v_len;
  loop invariant \forall integer k; 0 <= k < i && \at(v[k], LoopEntry) == x ==> v[k] == y;
  loop invariant \forall integer k; i <= k < v_len ==> v[k] == \at(v[k], LoopEntry);
  loop invariant \forall integer k; 0 <= k < i && \at(v[k], LoopEntry) != x ==> v[k] == \at(v[k], LoopEntry);
  loop assigns i, v[0..v_len-1];
  loop variant v_len - i;
*/
  while ((i < v_len))
    {
      if ((v[i] == x))
      {
        v[i] = y;
      }
      i = (i + 1);
    }
}
