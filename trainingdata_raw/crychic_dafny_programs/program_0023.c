// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures -1 <= \result < a_len;
    ensures 0 <= \result < a_len ==>
        a[\result] == 'e' &&
        (\forall integer x; 0 <= x < \result ==> a[x] != 'e');
    ensures \result == -1 ==>
        (\forall integer x; 0 <= x < a_len ==> a[x] != 'e');
*/
int firste(int* a, int a_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer x; 0 <= x < i ==> a[x] != 'e';
  loop assigns i;
  loop variant a_len - i;
*/
  while (i < a_len)
    {
      if (a[i] == 'e')
      {
        return i;
      }
      i = (i + 1);
    }
  return -1;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a[] = {'c', 'h', 'e', 'e', 's', 'e'};
  int p = firste(a, 6);
  /* unsupported stmt: print p; */
}