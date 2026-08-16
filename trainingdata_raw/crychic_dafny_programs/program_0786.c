// Generated C + ACSL

/*@
    requires n > 0;
    requires n <= 26;
    assigns \nothing;
*/
void PrintAlphabeticPattern(int n)
{
  int ch = 65;
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant ch == 65 + i * (i + 1) / 2;
  loop assigns i, ch;
  loop variant n - i;
*/
  while ((i < n))
    {
      int j = 0;
/*@
  loop invariant 0 <= j <= i + 1;
  loop invariant ch == 65 + i * (i + 1) / 2 + j;
  loop invariant \at(i, LoopEntry) == i;
  loop invariant \at(ch, LoopEntry) == 65 + i * (i + 1) / 2;
  loop assigns j, ch;
  loop variant i + 1 - j;
*/
      while ((j <= i))
        {
          int currentChar = (char)ch;
          /* unsupported stmt: print currentChar, " "; */
          ch = (ch + 1);
          j = (j + 1);
        }
      /* unsupported stmt: print "\n"; */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintAlphabeticPattern(5);;
}