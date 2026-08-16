// Generated C + ACSL

typedef struct {
    int isBold;
    int isItalic;
} Run;

typedef struct {
    Run* runs;
    int runs_len;
} Paragraph;

/*@
    requires document != \null;
    requires document_len >= 0;
    requires \valid_read(document + (0 .. document_len-1));
    requires \forall integer k; 0 <= k < document_len ==>
      document[k].runs_len >= 0;
    requires \forall integer k; 0 <= k < document_len ==>
      \valid_read(document[k].runs + (0 .. document[k].runs_len-1));
    assigns \nothing;
*/
void ExtractFormattedPhrases(Paragraph* document, int document_len)
{
  int boldPhrases = 0;
  /*@ assert boldPhrases >= 0 && boldPhrases <= 2147483647; */
  int italicPhrases = 0;
  /*@ assert italicPhrases >= 0 && italicPhrases <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= document_len;
  loop invariant boldPhrases >= 0;
  loop invariant italicPhrases >= 0;
  loop assigns i, boldPhrases, italicPhrases;
  loop variant document_len - i;
*/
  while ((i < document_len))
    {
      Paragraph para = document[i];
      int j = 0;
      int boldStart = boldPhrases;
      int italicStart = italicPhrases;
/*@
  loop invariant 0 <= j <= para.runs_len;
  loop invariant boldPhrases >= boldStart;
  loop invariant italicPhrases >= italicStart;
  loop assigns j, boldPhrases, italicPhrases;
  loop variant para.runs_len - j;
*/
      while ((j < para.runs_len))
        {
          Run run = para.runs[j];
          if (run.isItalic)
          {
            italicPhrases = (italicPhrases + 0);
          }
          if (run.isBold)
          {
            boldPhrases = (boldPhrases + 0);
          }
          j = (j + 1);
        }
      i = (i + 1);
    }
}