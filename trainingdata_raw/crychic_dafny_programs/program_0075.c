// Generated C + ACSL

/*@
    requires v_len > 0;
    requires v != \null;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
    ensures 0 <= \result < v_len;
    ensures \forall integer k; 0 <= k < v_len ==> v[\result] >= v[k];
*/
int mmaximum1(int* v, int v_len)
{
  int j = 1;
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= j <= v_len;
  loop invariant 0 <= i < j;
  loop invariant \forall integer k; 0 <= k < j ==> v[i] >= v[k];
  loop assigns i, j;
  loop variant v_len - j;
*/
  while ((j < v_len))
    {
      if ((v[j] > v[i]))
      {
        i = j;
      }
      j = (j + 1);
    }
  return i;  // Dafny implicit return
}

/*@
    requires v_len > 0;
    requires v != \null;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
    ensures 0 <= \result < v_len;
    ensures \forall integer k; 0 <= k < v_len ==> v[\result] >= v[k];
*/
int mmaximum2(int* v, int v_len)
{
  int j = (v_len - 2);
  int i = (v_len - 1);
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= i < v_len;
  loop invariant -1 <= j < v_len - 1;
  loop invariant \at(j, LoopEntry) >= j;
  loop invariant \forall integer k; j < k < v_len ==> v[k] <= v[i];
  loop assigns i, j;
  loop variant j + 1;
*/
  while ((j >= 0))
    {
      if ((v[j] > v[i]))
      {
        i = j;
      }
      j = (j - 1);
    }
  return i;  // Dafny implicit return
}

/*@
    requires v_len > 0;
    requires v != \null;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
    ensures 0 <= \result < v_len;
    ensures \forall integer k; 0 <= k < v_len ==> v[\result] >= v[k];
    ensures \forall integer l; 0 <= l < \result ==> v[\result] > v[l];
*/
int mfirstMaximum(int* v, int v_len)
{
  int j = 1;
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= j <= v_len;
  loop invariant 0 <= i < j;
  loop invariant \forall integer k; 0 <= k < j ==> v[i] >= v[k];
  loop invariant \forall integer k; 0 <= k < i ==> v[i] > v[k];
  loop assigns i, j;
  loop variant v_len - j;
*/
  while ((j < v_len))
    {
      if ((v[j] > v[i]))
      {
        i = j;
      }
      j = (j + 1);
    }
  return i;  // Dafny implicit return
}

/*@
    requires v_len > 0;
    requires v != \null;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
    ensures 0 <= \result < v_len;
    ensures \forall integer k; 0 <= k < v_len ==> v[\result] >= v[k];
    ensures \forall integer l; \result < l < v_len ==> v[\result] > v[l];
*/
int mlastMaximum(int* v, int v_len)
{
  int j = (v_len - 2);
  int i = (v_len - 1);
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant -1 <= j < \at(v_len, LoopEntry) - 1;
  loop invariant 0 <= i < \at(v_len, LoopEntry);
  loop invariant \forall integer k; j < k < \at(v_len, LoopEntry) ==> v[k] <= v[i];
  loop invariant \forall integer k; i < k < \at(v_len, LoopEntry) ==> v[k] < v[i];
  loop assigns i, j;
  loop variant j + 1;
*/
  while ((j >= 0))
    {
      if ((v[j] > v[i]))
      {
        i = j;
      }
      j = (j - 1);
    }
  return i;  // Dafny implicit return
}

/*@
    requires v != \null;
    requires v_len > 0;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < v_len && \result == v[i];
    ensures \forall integer k; 0 <= k < v_len ==> \result >= v[k];
*/
int mmaxvalue1(int* v, int v_len)
{
  int i = mmaximum1(v, v_len);
  /*@ assert 0 <= i < v_len; */
  /*@ assert \forall integer k; 0 <= k < v_len ==> v[i] >= v[k]; */
  int m = v[i];
  /*@ assert \exists integer j; 0 <= j < v_len && m == v[j]; */
  /*@ assert \forall integer k; 0 <= k < v_len ==> m >= v[k]; */
  return m;  // Dafny implicit return
}

/*@
    requires v != \null;
    requires v_len > 0;
    requires \valid(v + (0 .. v_len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < v_len && \result == v[i];
    ensures \forall integer k; 0 <= k < v_len ==> \result >= v[k];
*/
int mmaxvalue2(int* v, int v_len)
{
  int i = mmaximum2(v, v_len);
  /*@ assert 0 <= i < v_len; */
  /*@ assert \forall integer k; 0 <= k < v_len ==> v[i] >= v[k]; */
  int m = v[i];
  /*@ assert \exists integer j; 0 <= j < v_len && m == v[j]; */
  /*@ assert \forall integer k; 0 <= k < v_len ==> m >= v[k]; */
  return m;  // Dafny implicit return
}