// Generated C + ACSL

/*@
    requires a != \null;
    requires 0 <= i <= j <= a_len;
    requires \valid_read(a + (0 .. a_len-1));
    decreases j - i;
    assigns \nothing;
    ensures (i <= \result < j) || (\result == -1);
    ensures \result != -1 ==> a[\result] == x;
    ensures \result != -1 ==> (\forall integer r; \result < r < j ==> a[r] != x);
    ensures \result == -1 ==> (\forall integer r; i <= r < j ==> a[r] != x);
*/
int SearchRecursive(int* a, int a_len, int i, int j, int x)
{
  if (j == i)
  {
    int k = -1;
    return k;
  }
  if (a[(j - 1)] == x)
  {
    int k = (j - 1);
    return k;
  }
  else
  {
    int k = SearchRecursive(a, a_len, i, (j - 1), x);
    /*@ assert k == -1 ==> (\forall integer r; i <= r < j-1 ==> a[r] != x); */
    /*@ assert k != -1 ==> (i <= k < j-1 && a[k] == x); */
    /*@ assert k != -1 ==> (\forall integer r; k < r < j-1 ==> a[r] != x); */
    /*@ assert a[j-1] != x; */
    return k;
  }
}

/*@
    requires a != \null;
    requires 0 <= i <= j <= a_len;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures (i <= \result < j) || (\result == -1);
    ensures \result != -1 ==> a[\result] == x;
    ensures \result != -1 ==>
        (\forall integer r; \result < r < j ==> a[r] != x);
    ensures \result == -1 ==>
        (\forall integer r; i <= r < j ==> a[r] != x);
*/
int SearchLoop(int* a, int a_len, int i, int j, int x)
{
  if (i == j)
  {
    return -1;
  }
  int t = j;
/*@
  loop invariant i <= t <= j;
  loop invariant \forall integer p; t <= p < j ==> a[p] != x;
  loop invariant \at(i, LoopEntry) == i;
  loop invariant \at(j, LoopEntry) == j;
  loop invariant \at(x, LoopEntry) == x;
  loop assigns t;
  loop variant t - i;
*/
  while (t > i)
    {
      /*@ assert i < t <= j; */
      /*@ assert \forall integer p; t <= p < j ==> a[p] != x; */
      if (a[(t - 1)] == x)
      {
        int k = (t - 1);
        /*@ assert i <= k < j; */
        /*@ assert a[k] == x; */
        /*@ assert \forall integer r; k < r < j ==> a[r] != x; */
        return k;
      }
      else
      {
        /*@ assert a[t-1] != x; */
        t = (t - 1);
        /*@ assert \forall integer p; t <= p < j ==> a[p] != x; */
      }
    }
  /*@ assert t == i; */
  /*@ assert \forall integer p; i <= p < j ==> a[p] != x; */
  int k = -1;
  return k;  // Dafny implicit return
}