// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    requires 0 <= num < a_len;
    assigns a[0 .. num];
    ensures \forall integer n; 0 <= n <= num ==> a[n] == \old(a[num - n]);
    ensures \forall integer n; num < n && n < a_len ==> a[n] == \old(a[n]);
*/
void flip(int* a, int a_len, int num)
{
  int tmp;
  int i = 0;
  int j = num;
/*@
  loop invariant 0 <= i <= num / 2 + 1;
  loop invariant num / 2 <= j <= num;
  loop invariant i + j == num;
  loop invariant \forall integer k3; 0 <= k3 < i ==>
    a[k3] == \at(a[num - k3], LoopEntry) && a[num - k3] == \at(a[k3], LoopEntry);
  loop invariant \forall integer k5; i <= k5 <= j ==>
    a[k5] == \at(a[k5], LoopEntry);
  loop invariant \forall integer k6; num < k6 && k6 < a_len ==>
    a[k6] == \at(a[k6], LoopEntry);
  loop assigns i, j, tmp, a[0..num];
  loop variant j - i;
*/
  while ((i < j))
    {
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i = (i + 1);
      j = (j - 1);
    }
}