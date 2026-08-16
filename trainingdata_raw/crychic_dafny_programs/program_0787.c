// Generated C + ACSL

/*@
    assigns \nothing;
*/
void PrintString(void)
{
  char* tej = "votary";
  int i = 0;
/*@
  loop invariant 0 <= i <= 5;
  loop assigns i;
  loop variant 5 - i;
*/
  while ((i < 5))
    {
      /* unsupported stmt: print tej[i], "\n"; */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintString();;
}
