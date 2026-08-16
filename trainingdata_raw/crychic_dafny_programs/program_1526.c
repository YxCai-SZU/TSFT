// Generated C + ACSL

/*@
    requires b != \null;
    requires b_len >= 0;
    requires \valid_read(b + (0 .. b_len-1));
    assigns \nothing;
    ensures 0 <= \result <= b_len;
    ensures \result < b_len ==> b[\result] == f;
    ensures \result == b_len ==> (\forall integer i; 0 <= i < b_len ==> b[i] != f);
    ensures \forall integer i; 0 <= i < \result ==> b[i] != f;
*/
int ZXCV(int* b, int b_len, int f)
{
  int q = 0;
  /*@ assert q >= 0 && q <= 2147483647; */
/*@
  loop invariant 0 <= q <= b_len;
  loop invariant \forall integer i; 0 <= i < q ==> f != b[i];
  loop invariant q == \at(q, LoopEntry) + (\at(q, LoopEntry) - \at(q, LoopEntry)) || q > \at(q, LoopEntry);
  loop assigns q;
  loop variant b_len - q;
*/
  while ((q != b_len))
    {
      if (f == b[q])
      {
        return q;
      }
      q = (q + 1);
    }
  return q;  // Dafny implicit return
}