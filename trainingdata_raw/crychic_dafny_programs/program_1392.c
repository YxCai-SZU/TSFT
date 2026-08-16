// Generated C + ACSL

/*@
  predicate just1(int *a, integer len, integer key) =
    (\exists integer k; 0 <= k && k < len && a[k] == key) &&
    !(\exists integer k, j; 0 <= k && k < j && j < len && a[k] == key && a[j] == key);
*/

/*@
    requires a != \null;
    requires a_len >= 1;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==>
        (\exists integer i; 0 <= i < a_len && a[i] == key &&
         (\forall integer j; 0 <= j < a_len && j != i ==> a[j] != key));
    ensures \result == 0 <==>
        ((\forall integer i; 0 <= i < a_len ==> a[i] != key) ||
         (\exists integer i, j; 0 <= i < j < a_len && a[i] == key && a[j] == key));
*/
int Just1(int *a, int a_len, int key)
{
  int i = 0;
  /*@ assert (i == 0); */
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] != key;
  loop assigns i;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] == key))
      {
        int n = (i + 1);
        /*@ assert ((n == (i + 1)) && (n > i)); */
        /*@ assert ((!((a[i] == key))) || (\exists integer k; 0 <= k <= i && a[k] == key)); */
        if ((n == a_len))
        {
          /*@ assert ((a[(a_len - 1)] == key) && (\forall integer k; 0 <= k < a_len - 1 ==> a[k] != key)); */
          return 1;
        }
/*@
  loop invariant a[i] == key;
  loop invariant i + 1 <= n <= a_len;
  loop invariant \forall integer k; i + 1 <= k < n ==> a[k] != key;
  loop invariant \at(i, LoopEntry) < n;
  loop assigns n;
  loop variant a_len - n;
*/
        while ((n < a_len))
          {
            if ((a[n] == key))
            {
              /*@ assert (\forall integer k; 0 <= k < i ==> a[k] != key) && a[i] == key && !(\forall integer j; 0 <= i < j && j < a_len && a[i] == key ==> a[j] != key); */
              /*@ assert \exists integer k, y; 0 <= k < y && y < a_len && a[k] == key && a[y] == key; */
              return 0;
            }
            n = (n + 1);
          }
        /*@ assert \forall integer k; i + 1 <= k < a_len ==> a[k] != key; */
        /*@ assert ((a[i] == key) && (\forall integer m; 0 <= m < i ==> a[m] != key)); */
        return 1;
      }
      i = (i + 1);
    }
  /*@ assert (i == a_len); */
  /*@ assert \forall integer k; 0 <= k < a_len ==> a[k] != key; */
  /*@ assert !(\exists integer k; 0 <= k < a_len && a[k] == key); */
  return 0;
}

/*@
    assigns \nothing;
*/
void test(void)
{
  int a1_vals[] = {1, 3, 3, 2, 0, 2, 3, 3, 4};
  int* a1 = a1_vals;
  int a1_len = 9;
  /*@ assert (((((((((a1[0] == 1) && (a1[1] == 3)) && (a1[2] == 3)) && (a1[3] == 2)) && (a1[4] == 0)) && (a1[5] == 2)) && (a1[6] == 3)) && (a1[7] == 3)) && (a1[8] == 4)); */
  /*@ assert just1(a1, a1_len, 1); */
  /*@ assert just1(a1, a1_len, 0); */
  /*@ assert just1(a1, a1_len, 4); */
  /*@ assert !(just1(a1, a1_len, 2)); */
  /*@ assert !(just1(a1, a1_len, 3)); */
  /*@ assert !(just1(a1, a1_len, 5)); */
}