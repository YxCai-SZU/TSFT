// Generated C + ACSL

/*@
    requires s_len >= 0;
    requires s_len > 0 ==> s != \null;
    requires s_len > 0 ==> \valid_read(s + (0 .. s_len-1));
    requires \forall integer p, q; 0 <= p < q < s_len ==> s[p] <= s[q];
    assigns \nothing;
    ensures 0 <= \result <= s_len;
    ensures \forall integer i; 0 <= i < \result ==> s[i] <= x;
    ensures \forall integer i; \result <= i < s_len ==> s[i] >= x;
*/
int Search(int* s, int s_len, int x)
{
  int p = 0;
  int q = s_len;
  if ((p == q))
  {
    return p;
  }
/*@
  loop invariant 0 <= p <= q;
  loop invariant q <= s_len;
  loop invariant \forall integer r; 0 <= r < p ==> s[r] <= x;
  loop invariant \forall integer r; q <= r < s_len ==> s[r] >= x;
  loop assigns p, q;
  loop variant q - p;
*/
  while ((p != q))
    {
      int m = (p + ((q - p) / 2));
      if ((s[m] == x))
      {
        return m;
      }
      if ((s[m] < x))
      {
        p = (m + 1);
      }
      else
      {
        q = m;
      }
    }
  return p;
}

// skipped function Sort due to unsupported type