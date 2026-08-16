// Generated C + ACSL

/*@
  predicate sorted(int *a, integer len) =
    \forall integer j, k; 0 <= j && j < k && k < len ==> a[j] <= a[k];
*/

/*@
    requires \true;
    assigns \nothing;
*/
void m(void)
{
  int a_vals[] = {1, 2, 3, 4};
  int* a = a_vals;
  int a_len = 4;
  /*@ assert sorted(a, a_len); */
}
