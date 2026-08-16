// Generated C + ACSL

/*@
  predicate Sorted(int *a, integer len) =
    \forall integer j, k; 0 <= j && j < k && k < len ==> a[j] < a[k];
*/

/*@
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0];
*/
void DoSomething(int* a, int a_len)
{
  a[0] = 1;
}
