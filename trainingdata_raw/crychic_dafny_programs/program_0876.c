// Generated C + ACSL

/*@
    requires start <= end;
    assigns \nothing;
*/
void PrintRange(int start, int end)
{
  int n = start;
/*@
  loop invariant start <= n <= end + 1;
  loop assigns n;
  loop variant end - n + 1;
*/
  while ((n <= end))
    {
      /* unsupported stmt: print n, "\n"; */
      n = (n + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintRange(1, 5);;
}
