// Generated C + ACSL

/*@
  predicate exist2(int *a, integer len, integer x) =
    \exists integer m; 0 <= m < len &&
      (\exists integer n; 0 <= n < len && m != n && a[m] == x && a[n] == x);
*/

/*@
  predicate exist1(int *a, integer len, integer x) =
    \exists integer m; 0 <= m < len && a[m] == x && !exist2(a, len, x);
*/

/*@
  predicate tail(int *a, integer len) =
    \forall integer m; 0 <= m < len - 1 ==> (a[m] == 0 ==> a[m + 1] == 0);
*/

/*@
    assigns \nothing;
*/
void testExist1(void)
{
  int a_vals[] = {3, 3, 1, 0, 0, 0};
  int* a = a_vals;
  int a_len = 6;
  /*@ assert ((((((a[0] == 3) && (a[1] == 3)) && (a[2] == 1)) && (a[3] == 0)) && (a[4] == 0)) && (a[5] == 0)); */
  int x = 1;
  /*@ assert exist1(a, a_len, x); */
  x = 0;
  /*@ assert !(exist1(a, a_len, x)); */
  x = 3;
  /*@ assert !(exist1(a, a_len, x)); */
  x = 42;
  /*@ assert !(exist1(a, a_len, x)); */
}

/*@
    assigns \nothing;
*/
void testExist2(void)
{
  int a_vals[] = {3, 3, 1, 0, 0, 0};
  int* a = a_vals;
  int a_len = 6;
  /*@ assert ((((((a[0] == 3) && (a[1] == 3)) && (a[2] == 1)) && (a[3] == 0)) && (a[4] == 0)) && (a[5] == 0)); */
  int x = 1;
  /*@ assert !(exist2(a, a_len, x)); */
  x = 0;
  /*@ assert exist2(a, a_len, x); */
  x = 3;
  /*@ assert exist2(a, a_len, x); */
  x = 42;
  /*@ assert !(exist2(a, a_len, x)); */
}

/*@
    assigns \nothing;
*/
void testTail(void)
{
  int a_vals[] = {3, 3, 1, 0, 0, 0};
  int* a = a_vals;
  int a_len = 6;
  /*@ assert ((((((a[0] == 3) && (a[1] == 3)) && (a[2] == 1)) && (a[3] == 0)) && (a[4] == 0)) && (a[5] == 0)); */
  /*@ assert tail(a, a_len); */
  int b_vals[] = {0, 0};
  int* b = b_vals;
  int b_len = 2;
  /*@ assert ((b[0] == 0) && (b[1] == 0)); */
  /*@ assert tail(b, b_len); */
  int* c; /* unsupported init: Microsoft.Dafny.AllocateArray() */
  int c_len = 0;
  /*@ assert tail(c, c_len); */
  int d_vals[] = {9, 1, 3, 8, 5};
  int* d = d_vals;
  int d_len = 5;
  /*@ assert (((((d[0] == 9) && (d[1] == 1)) && (d[2] == 3)) && (d[3] == 8)) && (d[4] == 5)); */
  /*@ assert tail(d, d_len); */
  int e_vals[] = {1, 0, 2};
  int* e = e_vals;
  int e_len = 3;
  /*@ assert (((e[0] == 1) && (e[1] == 0)) && (e[2] == 2)); */
  /*@ assert !(tail(e, e_len)); */
  int f_vals[] = {0, 1};
  int* f = f_vals;
  int f_len = 2;
  /*@ assert ((f[0] == 0) && (f[1] == 1)); */
  /*@ assert !(tail(f, f_len)); */
}