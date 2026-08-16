// Generated C + ACSL

/*@
    requires input != \null;
    requires input_len >= 0;
    requires \valid_read(input + (0 .. input_len-1));
    assigns \nothing;
    ensures \result >= 0;
*/
int GenerateHash(char* input, int input_len)
{
  int hash = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= input_len;
  loop invariant hash >= 0;
  loop invariant hash < 2147483647;
  loop invariant i == \at(i, LoopEntry) + (\at(i, LoopCurrent) - \at(i, LoopEntry));
  loop assigns i, hash;
  loop variant input_len - i;
*/
  while ((i < input_len))
    {
      hash = (((hash * 31) + (int)hash) % 2147483647);
      i = (i + 1);
    }
  return hash;
}