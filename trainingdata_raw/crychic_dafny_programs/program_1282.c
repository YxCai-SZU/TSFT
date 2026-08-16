// Generated C + ACSL

/*@
    requires a != \null;
    requires 0 <= num < a_len;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void flip(int* a, int a_len, int num)
{
  int tmp;
  int i = 0;
  int j = num;
/*@
  loop invariant num == i + j;
  loop invariant 0 <= i <= num + 1;
  loop invariant -1 <= j <= num;
  loop invariant i - 1 <= j + 1;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[num - k], LoopEntry);
  loop invariant \forall integer k; i <= k && k <= j ==> a[k] == \at(a[k], LoopEntry);
  loop invariant \forall integer k; j < k && k <= num ==> a[k] == \at(a[num - k], LoopEntry);
  loop invariant \forall integer k; num < k && k < a_len ==> a[k] == \at(a[k], LoopEntry);
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