// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    requires 0 <= num < a_len;
    assigns a[0 .. a_len-1];
*/
void flip(int *a, int a_len, int num)
{
  int tmp;
  int i = 0;
  int j = num;
/*@
  loop invariant i + j == num;
  loop invariant 0 <= i <= num / 2 + 1;
  loop invariant num / 2 - 1 <= j <= num;
  loop invariant \forall integer n; 0 <= n < i ==> a[n] == \at(a[num - n], LoopEntry);
  loop invariant \forall integer n; num < n < a_len ==> a[n] == \at(a[n], LoopEntry);
  loop invariant \forall integer n; 0 <= n < i ==> a[num - n] == \at(a[n], LoopEntry);
  loop invariant \forall integer n; i <= n <= j ==> a[n] == \at(a[n], LoopEntry);
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