// Generated C + ACSL

/*@
    requires r != \null;
    requires x != \null;
    requires r_len >= 0;
    requires x_len >= 0;
    requires \valid_read(r + (0 .. r_len-1));
    requires \valid_read(x + (0 .. x_len-1));
    requires \forall integer i, j; 0 <= i <= j < x_len ==> x[i] <= x[j];
    requires \forall integer i, j; 0 <= i < r_len && 0 <= j < x_len ==> r[i] >= 0 && x[j] >= 0;
    assigns \nothing;
    ensures \result == 0 ==>
        \forall integer i, j; 0 <= i < r_len && 0 <= j < x_len ==> r[i] != x[j];
    ensures \result != 0 ==>
        \exists integer i, j; 0 <= i < r_len && 0 <= j < x_len && r[i] == x[j];
*/
int Tangent(int* r, int r_len, int* x, int x_len)
{
  int tempB = 0;
  int tangentMissing = 0;
  int k = 0;
  int l = 0;
/*@
  loop invariant 0 <= k <= r_len;
  loop invariant tempB == 0 || tempB == 1;
  loop invariant tangentMissing == 0 || tangentMissing == 1;
  loop invariant tempB ==>
    (\exists integer i, j; 0 <= i < r_len && 0 <= j < x_len && r[i] == x[j]);
  loop invariant !tempB ==>
    (\forall integer i, j; 0 <= i < k && 0 <= j < x_len ==> r[i] != x[j]);
  loop invariant tempB == \at(tempB, LoopEntry) ||
    (\exists integer i; \at(tempB, LoopEntry) <= i < k &&
     (\exists integer j; 0 <= j < x_len && r[i] == x[j]));
  loop assigns k, l, tempB, tangentMissing;
  loop variant r_len - k;
*/
  while (((k != r_len) && !(tempB)))
    {
      l = 0;
      tangentMissing = 0;
/*@
  loop invariant 0 <= l <= x_len;
  loop invariant tempB == 0 || tempB == 1;
  loop invariant tangentMissing == 0 || tangentMissing == 1;
  loop invariant tempB ==>
    (\exists integer i; 0 <= i < l ==> r[k] == x[i]);
  loop invariant !tempB ==>
    (\forall integer i; 0 <= i < l ==> r[k] != x[i]);
  loop invariant tangentMissing ==>
    (\forall integer i; l <= i < x_len ==> r[k] < x[i]);
  loop invariant tempB == \at(tempB, LoopEntry) ||
    (\exists integer i; 0 <= i < l && r[k] == x[i]);
  loop invariant tangentMissing == \at(tangentMissing, LoopEntry) ||
    (\exists integer i; 0 <= i < l && r[k] < x[i]);
  loop assigns l, tempB, tangentMissing;
  loop variant x_len - l;
*/
      while (((l != x_len) && !(tangentMissing)))
        {
          if ((r[k] == x[l]))
          {
            tempB = 1;
          }
          if ((r[k] < x[l]))
          {
            tangentMissing = 1;
          }
          l = (l + 1);
        }
      k = (k + 1);
    }
  int b = tempB;
  /*@ assert tempB == 0 || tempB == 1; */
  /*@ assert b == tempB; */
  /*@ assert b == 0 || b == 1; */
  /*@ assert b >= 0 && b <= 2147483647; */
  return b;  // Dafny implicit return
}