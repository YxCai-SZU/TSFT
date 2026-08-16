// Generated C + ACSL

/*@
    requires v != \null;
    requires v_len > 0;
    requires 0 <= p < v_len;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        (\forall integer k, l;
            (0 <= k <= p && p < l < v_len) ==> v[k] < v[l]);
    ensures \result == 0 <==>
        (\exists integer k, l;
            (0 <= k <= p && p < l < v_len) && v[k] >= v[l]);
*/
int barrier(int* v, int v_len, int p)
{
  int i = 1;
  int max = 0;
/*@
  loop invariant 0 <= i <= p + 1;
  loop invariant 0 <= max < i;
  loop invariant \forall integer k; 0 <= k < i ==> v[max] >= v[k];
  loop assigns i, max;
  loop variant p - i + 1;
*/
  while ((i <= p))
    {
      if ((v[i] > v[max]))
      {
        max = i;
      }
      i = (i + 1);
    }
/*@
  loop invariant 0 <= i <= v_len;
  loop invariant \at(i, LoopEntry) <= i;
  loop invariant \forall integer k; 0 <= k <= p ==> v[k] <= v[max];
  loop invariant \forall integer k; p < k < \at(i, LoopEntry) ==> v[k] > v[max];
  loop invariant \forall integer k; \at(i, LoopEntry) <= k < i ==> v[k] > v[max];
  loop assigns i;
  loop variant v_len - i;
*/
  while (((i < v_len) && (v[i] > v[max])))
    {
      i = (i + 1);
    }
  int b = (i == v_len);
  /*@ assert b >= 0 && b <= 2147483647; */
  return b;  // Dafny implicit return
}
