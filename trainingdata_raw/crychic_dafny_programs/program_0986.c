// Generated C + ACSL

/*@
    requires word != \null;
    requires word_len >= 0;
    requires \valid_read(word + (0 .. word_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==>
        (word_len == 3 && word[0] == 't' && word[1] == 'h' && word[2] == 'e') ||
        (word_len == 1 && word[0] == 'a') ||
        (word_len == 2 && word[0] == 'a' && word[1] == 'n') ||
        (word_len == 3 && word[0] == 'a' && word[1] == 'n' && word[2] == 'd') ||
        (word_len == 2 && word[0] == 'o' && word[1] == 'r') ||
        (word_len == 3 && word[0] == 'b' && word[1] == 'u' && word[2] == 't') ||
        (word_len == 2 && word[0] == 'i' && word[1] == 'n') ||
        (word_len == 2 && word[0] == 'o' && word[1] == 'n') ||
        (word_len == 2 && word[0] == 'a' && word[1] == 't');
*/
int isStopword(char* word, int word_len)
{
  if (word_len == 3 && word[0] == 't' && word[1] == 'h' && word[2] == 'e') return 1;
  if (word_len == 1 && word[0] == 'a') return 1;
  if (word_len == 2 && word[0] == 'a' && word[1] == 'n') return 1;
  if (word_len == 3 && word[0] == 'a' && word[1] == 'n' && word[2] == 'd') return 1;
  if (word_len == 2 && word[0] == 'o' && word[1] == 'r') return 1;
  if (word_len == 3 && word[0] == 'b' && word[1] == 'u' && word[2] == 't') return 1;
  if (word_len == 2 && word[0] == 'i' && word[1] == 'n') return 1;
  if (word_len == 2 && word[0] == 'o' && word[1] == 'n') return 1;
  if (word_len == 2 && word[0] == 'a' && word[1] == 't') return 1;
  return 0;
}

// skipped function calculateWordFrequencies due to unsupported type