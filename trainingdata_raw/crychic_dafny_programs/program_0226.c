// Generated C + ACSL

/*@
    requires a_len >= 8;
    requires a != \null;
    requires \valid(a + (0 .. a_len-1));
    assigns a[4], a[7];
    ensures a[4] == \old(a[4]) + 3;
    ensures a[7] == 516;
    ensures \forall integer i; 0 <= i < a_len && i != 4 && i != 7 ==> a[i] == \old(a[i]);
*/
void UpdateElements(int* a, int a_len)
{
  a[4] = (a[4] + 3);
  a[7] = 516;
}
