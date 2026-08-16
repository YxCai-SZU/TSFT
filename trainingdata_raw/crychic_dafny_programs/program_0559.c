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
  loop invariant k == \at(k, LoopEntry) + (k - \at(k, LoopEntry));
  loop invariant tempB == 0 || tempB == 1;
  loop invariant tempB == 1 ==>
    \exists integer i, j; 0 <= i < r_len && 0 <= j < x_len && r[i] == x[j];
  loop invariant tempB == 0 ==>
    \forall integer i, j; 0 <= i < k && 0 <= j < x_len ==> r[i] != x[j];
  loop invariant \forall integer m; 0 <= m < \at(k, LoopEntry) ==>
    \forall integer n; 0 <= n < x_len ==> r[m] != x[n];
  loop assigns k, l, tangentMissing, tempB;
  loop variant r_len - k;
*/
  while (((k != r_len) && !(tempB)))
    {
      /*@ assert 0 <= k < r_len; */
      /*@ assert tempB == 0; */
      /*@ assert \forall integer j; 0 <= j < k ==> 
          (\forall integer n; 0 <= n < x_len ==> r[j] != x[n]); */
      
      l = 0;
      tangentMissing = 0;
      
      /*@ assert l == 0; */
      /*@ assert tangentMissing == 0; */
      /*@ assert tempB == 0; */
      
/*@
  loop invariant 0 <= l <= x_len;
  loop invariant 0 <= k < r_len;
  loop invariant tempB == 0 || tempB == 1;
  loop invariant tangentMissing == 0 || tangentMissing == 1;
  loop invariant tempB == 1 ==>
    \exists integer i; 0 <= i < l && r[k] == x[i];
  loop invariant tempB == 0 ==>
    \forall integer i; 0 <= i < l ==> r[k] != x[i];
  loop invariant tangentMissing == 1 ==>
    \exists integer i; 0 <= i < l && r[k] < x[i];
  loop invariant tangentMissing == 0 ==>
    \forall integer i; 0 <= i < l ==> r[k] >= x[i];
  loop invariant (tempB == 1 && tangentMissing == 0) ==>
    \exists integer i; 0 <= i < l && r[k] == x[i];
  loop invariant (tempB == 0 && tangentMissing == 1) ==>
    (\forall integer i; 0 <= i < l ==> r[k] != x[i]) &&
    (\exists integer i; 0 <= i < l && r[k] < x[i]);
  loop invariant (tempB == 0 && tangentMissing == 0) ==>
    \forall integer i; 0 <= i < l ==> r[k] >= x[i] && r[k] != x[i];
  loop invariant l == \at(l, LoopEntry) + (\at(l, LoopCurrent) - \at(l, LoopEntry));
  loop assigns l, tempB, tangentMissing;
  loop variant x_len - l;
*/
      while (((l != x_len) && !(tangentMissing)))
        {
          /*@ assert 0 <= l < x_len; */
          /*@ assert tangentMissing == 0; */
          
          if ((r[k] == x[l]))
          {
            tempB = 1;
            /*@ assert r[k] == x[l]; */
            /*@ assert tempB == 1; */
          }
          if ((r[k] < x[l]))
          {
            tangentMissing = 1;
            /*@ assert r[k] < x[l]; */
            /*@ assert tangentMissing == 1; */
          }
          l = (l + 1);
        }
      /*@ assert l == x_len || tangentMissing == 1; */
      /*@ assert tempB == 1 ==> \exists integer j; 0 <= j < x_len && r[k] == x[j]; */
      /*@ assert tempB == 0 ==> \forall integer j; 0 <= j < x_len ==> r[k] != x[j]; */
      
      k = (k + 1);
    }
  /*@ assert tempB == 1 || k == r_len; */
  /*@ assert tempB == 1 ==> \exists integer i, j; 0 <= i < r_len && 0 <= j < x_len && r[i] == x[j]; */
  /*@ assert tempB == 0 ==> \forall integer i, j; 0 <= i < r_len && 0 <= j < x_len ==> r[i] != x[j]; */
  
  int b = tempB;
  /*@ assert b >= 0 && b <= 2147483647; */
  return b;  // Dafny implicit return
}