// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires 0 <= num < a_len;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer i; 0 <= i <= num ==> a[i] == \old(a[num - i]);
    ensures \forall integer j; num < j < a_len ==> a[j] == \old(a[j]);
*/
void flip(int* a, int a_len, int num)
{
  int tmp;
  int i = 0;
  int j = num;
/*@
  loop invariant 0 <= i <= j + 1;
  loop invariant i + j == num;
  loop invariant \forall integer k; i <= k <= j ==> a[k] == \at(a[k], LoopEntry);
  loop invariant \forall integer k; num < k < a_len ==> a[k] == \at(a[k], LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[num - k], LoopEntry);
  loop invariant \forall integer k; j < k <= num ==> a[k] == \at(a[num - k], LoopEntry);
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