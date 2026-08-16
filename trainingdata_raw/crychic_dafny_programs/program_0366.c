// Generated C + ACSL

/*@
    requires blood != \null;
    requires blood_len >= 0;
    requires \valid_read(blood + (0 .. blood_len-1));
    assigns \nothing;
    ensures 0 <= \result ==> \result < blood_len && blood[\result] == key;
    ensures \result < 0 ==> (\forall integer k; 0 <= k < blood_len ==> blood[k] != key);
*/
int Find(int* blood, int blood_len, int key)
{
  int index = 0;
  /*@ assert index >= 0 && index <= 2147483647; */
/*@
  loop invariant 0 <= index <= blood_len;
  loop invariant \forall integer k; 0 <= k < index ==> blood[k] != key;
  loop assigns index;
  loop variant blood_len - index;
*/
  while ((index < blood_len))
    {
      if (blood[index] == key)
      {
        return index;
      }
      index = (index + 1);
    }
  index = -1;
  return index;  // Dafny implicit return
}