// Generated C + ACSL

/*@
    requires 0 <= j < a_len;
    requires a != \null;
    requires \valid(a + (0 .. a_len-1));
    assigns a[j];
    ensures a[j] == 60;
    ensures \forall integer k; 0 <= k < a_len && k != j ==> a[k] == \old(a[k]);
*/
void TestArrayElements(int* a, int a_len, int j)
{
  a[j] = 60;
}
