// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result > 0;
*/
int AnalysisResult(int histograms, int moments);

/*@
    assigns \nothing;
    ensures \result > 0;
*/
int DoThreadedAnalysis(void)
{
  int histograms = 0;
  int moments = 0;
  int result = AnalysisResult(histograms, moments);
  //@ assert result > 0;
  return result;
}

// skipped function RunAnalysis due to unsupported type

// skipped function SequentialAnalysis due to unsupported type

// skipped function ParallelAnalysis due to unsupported type