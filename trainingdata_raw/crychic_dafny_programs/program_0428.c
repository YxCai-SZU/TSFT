// Generated C + ACSL

/*@
    assigns \nothing;
*/
void ZYXW(void)
{
  int ABCD = 0;
  int EFGH = 191;
/*@
  loop invariant 0 <= EFGH <= 191;
  loop invariant 0 <= ABCD <= 27;
  loop invariant 7 * ABCD + EFGH == 191;
  loop invariant EFGH < 7 ==> 7 * ABCD + EFGH == 191;
  loop invariant \at(ABCD, LoopEntry) <= ABCD;
  loop invariant \at(EFGH, LoopEntry) >= EFGH;
  loop assigns ABCD, EFGH;
  loop variant EFGH;
*/
  while ((7 <= EFGH))
    {
      ABCD = (ABCD + 1);
      /*@ assert ABCD >= 0 && ABCD <= 2147483647; */
      EFGH = (191 - (7 * ABCD));
      /*@ assert EFGH >= 0 && EFGH <= 2147483647; */
    }
}