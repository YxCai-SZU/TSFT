// Generated C + ACSL

/*@
  predicate Clean(int *a, integer len, integer key) =
    \forall integer k; 0 <= k && k < len ==> a[k] != key;
*/

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer j; 0 <= j < a_len ==> a[j] != key);
    ensures \result == 0 <==> (\exists integer j; 0 <= j < a_len && a[j] == key);
*/
int IsClean(int* a, int a_len, int key)
{
  int clean = 1;
  /*@ assert clean >= 0 && clean <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant clean == 1 ==> (\forall integer j; 0 <= j < i ==> a[j] != key);
  loop invariant clean == 0 ==> (\exists integer j; 0 <= j < i && a[j] == key);
  loop invariant clean == 0 || clean == 1;
  loop invariant (clean == 1 && i == a_len) ==> (\forall integer j; 0 <= j < a_len ==> a[j] != key);
  loop assigns i, clean;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if (a[i] == key)
      {
        clean = 0;
        /*@ assert a[i] == key; */
        /*@ assert \exists integer j; 0 <= j <= i && a[j] == key; */
        break;;
      }
      /*@ assert a[i] != key; */
      i = (i + 1);
    }
  /*@ assert i <= a_len; */
  /*@ assert clean == 1 ==> i == a_len; */
  /*@ assert clean == 1 ==> (\forall integer j; 0 <= j < a_len ==> a[j] != key); */
  /*@ assert clean == 0 ==> (\exists integer j; 0 <= j < a_len && a[j] == key); */
  return clean;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void Test(void)
{
  int a_vals[] = {1, 2, 2, 2, 3};
  int* a = a_vals;
  int a_len = 5;
  /*@ assert (a[0] == 1); */
  /*@ assert (a[1] == 2); */
  /*@ assert (a[2] == 2); */
  /*@ assert (a[3] == 2); */
  /*@ assert (a[4] == 3); */
  int b = IsClean(a, a_len, 5);
  /*@ assert (b == 1); */
  b = IsClean(a, a_len, 2);
  /*@ assert !(b); */
  b = IsClean(a, a_len, 3);
  /*@ assert !(b); */
  b = IsClean(a, a_len, 4);
  /*@ assert b; */
  int c_vals[] = {1};
  int* c = c_vals;
  int c_len = 1;
  /*@ assert (c[0] == 1); */
  b = IsClean(c, c_len, 1);
  /*@ assert !(b); */
  b = IsClean(c, c_len, 2);
  /*@ assert b; */
  int d_vals[1] = {0};
  int* d = d_vals;
  /*@ assert d[0] == 0; */
  b = IsClean(d, 1, 0);
  /*@ assert d[0] == 0; */
  /*@ assert !b; */
}