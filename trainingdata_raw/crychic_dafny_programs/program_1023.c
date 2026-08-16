// Generated C + ACSL

/*@
  predicate IsPositive(integer value) =
    value > 0;
*/

/*@
  predicate IsNegative(integer value) =
    value < 0;
*/

/*@
    requires reviews != \null;
    requires reviews_len >= 0;
    requires \valid(reviews + (0 .. reviews_len-1));
    assigns \nothing;
*/
void CountSentiments(int* reviews, int reviews_len)
{
  int positive = 0;
  /*@ assert positive >= 0 && positive <= 2147483647; */
  int neutral = 0;
  /*@ assert neutral >= 0 && neutral <= 2147483647; */
  int negative = 0;
  /*@ assert negative >= 0 && negative <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= reviews_len;
  loop invariant positive + neutral + negative == i;
  loop invariant positive >= 0;
  loop invariant neutral >= 0;
  loop invariant negative >= 0;
  loop assigns i, positive, neutral, negative;
  loop variant reviews_len - i;
*/
  while ((i < reviews_len))
    {
      int sentiment = reviews[i];
      if (sentiment > 0)
      {
        positive = (positive + 1);
      }
      else
      if (sentiment < 0)
      {
        negative = (negative + 1);
      }
      else
      {
        neutral = (neutral + 1);
      }
      i = (i + 1);
    }
}