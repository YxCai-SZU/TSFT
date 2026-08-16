// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0], a[a_len-1];
    ensures a[0] == \old(a[a_len-1]);
    ensures a[a_len-1] == \old(a[0]);
    ensures \forall integer k; 1 <= k < a_len-1 ==> a[k] == \old(a[k]);
*/
void SwapFirstAndLast(int* a, int a_len)
{
  int temp = a[0];
  a[0] = a[(a_len - 1)];
  a[(a_len - 1)] = temp;
}
