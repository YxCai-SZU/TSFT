// Generated C + ACSL

/*@
  predicate EOSorted(int *a, integer len) =
    len >= 2 ==>
      (\forall integer j; 2 <= j && j < len && j % 2 == 0 ==> a[j] >= a[j - 2]) &&
      (\forall integer k; 3 <= k && k < len && k % 2 == 1 ==> a[k] >= a[k - 2]);
*/

/*@
  predicate Sorted(int *a, integer len) =
    \forall integer j, k; 0 <= j && j < k && k < len ==> a[j] <= a[k];
*/

/*@
    assigns \nothing;
*/
void Test(void)
{
  int* a; /* unsupported init: Microsoft.Dafny.AllocateArray() */
  int b_vals[] = {2, 1, 4, 2, 6, 3};
  int* b = b_vals;
  int b_len = 6;
  /*@ assert EOSorted(b, b_len); */
  int c_vals[] = {1, 2, 3, 1};
  int* c = c_vals;
  int c_len = 4;
  /*@ assert (c[0] == 1); */
  /*@ assert (c[1] == 2); */
  /*@ assert (c[2] == 3); */
  /*@ assert (c[3] == 1); */
  /*@ assert !(EOSorted(c, c_len)); */
  int d_vals[] = {1, 2, 1, 2, 1};
  int* d = d_vals;
  int d_len = 5;
  /*@ assert EOSorted(d, d_len); */
  int e_vals[] = {1, 1, 1, 1, 1};
  int* e = e_vals;
  int e_len = 5;
  /*@ assert EOSorted(e, e_len); */
  int f_vals[] = {1, 100, 1, 100, 1, 200};
  int* f = f_vals;
  int f_len = 6;
  /*@ assert EOSorted(f, f_len); */
  int g_vals[] = {1, 2, 4, 2, 2, 1, 1};
  int* g = g_vals;
  int g_len = 7;
  /*@ assert (g[0] == 1); */
  /*@ assert (g[1] == 2); */
  /*@ assert (g[2] == 4); */
  /*@ assert (g[3] == 2); */
  /*@ assert (g[4] == 2); */
  /*@ assert (g[5] == 1); */
  /*@ assert (g[6] == 1); */
  /*@ assert !(EOSorted(g, g_len)); */
  int h_vals[] = {1, 2, 3, 4, 1};
  int* h = h_vals;
  int h_len = 5;
}