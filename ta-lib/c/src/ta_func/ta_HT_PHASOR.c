/* TA-LIB Copyright (c) 1999-2006, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  MF       Mario Fortier
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  120802 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #elif defined( _JAVA )
/* Generated */    #include "ta_defs.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */    #include "ta_trace.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::HT_PHASOR_Lookback( void )
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int HT_PHASOR_Lookback(  )
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_HT_PHASOR_Lookback( void )
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ /* No parameters to validate. */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */

   /* See TA_MAMA_Lookback for an explanation of these */
   return 32 + TA_GLOBALS_UNSTABLE_PERIOD(TA_FUNC_UNST_HT_PHASOR);
}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_HT_PHASOR - Hilbert Transform - Phasor Components
 * 
 * Input  = double
 * Output = double, double
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::HT_PHASOR( int    startIdx,
/* Generated */                                              int    endIdx,
/* Generated */                                              cli::array<double>^ inReal,
/* Generated */                                              [Out]int%    outBegIdx,
/* Generated */                                              [Out]int%    outNbElement,
/* Generated */                                              cli::array<double>^  outInPhase,
/* Generated */                                              cli::array<double>^  outQuadrature )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode HT_PHASOR( int    startIdx,
/* Generated */                              int    endIdx,
/* Generated */                              double       inReal[],
/* Generated */                              MInteger     outBegIdx,
/* Generated */                              MInteger     outNbElement,
/* Generated */                              double        outInPhase[],
/* Generated */                              double        outQuadrature[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_HT_PHASOR( int    startIdx,
/* Generated */                          int    endIdx,
/* Generated */                          const double inReal[],
/* Generated */                          int          *outBegIdx,
/* Generated */                          int          *outNbElement,
/* Generated */                          double        outInPhase[],
/* Generated */                          double        outQuadrature[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */

   int outIdx, i;
   int lookbackTotal, today;
   double tempReal, tempReal2;

   double adjustedPrevPeriod, period;

   /* Variable used for the price smoother (a weighted moving average). */
   int trailingWMAIdx;
   double periodWMASum, periodWMASub, trailingWMAValue;
   double smoothedValue;

   /* Variables used for the Hilbert Transormation */
   CONSTANT_DOUBLE(a) = 0.0962;
   CONSTANT_DOUBLE(b) = 0.5769;
   double hilbertTempReal;
   int hilbertIdx;

   HILBERT_VARIABLES( detrender );
   HILBERT_VARIABLES( Q1 );
   HILBERT_VARIABLES( jI );
   HILBERT_VARIABLES( jQ );

   double Q2, I2, prevQ2, prevI2, Re, Im;

   double I1ForOddPrev2,  I1ForOddPrev3;
   double I1ForEvenPrev2, I1ForEvenPrev3;

   double rad2Deg;

   double todayValue;

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA)*/
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !outInPhase )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( !outQuadrature )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Constant */
   rad2Deg = 180.0 / (4.0 * atan(1));

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */
   lookbackTotal = 32 + TA_GLOBALS_UNSTABLE_PERIOD(TA_FUNC_UNST_HT_PHASOR);

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      return NAMESPACE(TA_RetCode)TA_SUCCESS;
   }

   VALUE_HANDLE_DEREF(outBegIdx) = startIdx;

   /* Initialize the price smoother, which is simply a weighted
    * moving average of the price.
    * To understand this algorithm, I strongly suggest to understand
    * first how TA_WMA is done.
    */
   trailingWMAIdx = startIdx - lookbackTotal;
   today = trailingWMAIdx;

   /* Initialization is same as WMA, except loop is unrolled
    * for speed optimization.
    */
   tempReal = inReal[today++];
   periodWMASub = tempReal;
   periodWMASum = tempReal;
   tempReal = inReal[today++];
   periodWMASub += tempReal;
   periodWMASum += tempReal*2.0;
   tempReal = inReal[today++];
   periodWMASub += tempReal;
   periodWMASum += tempReal*3.0;

   trailingWMAValue = 0.0;

   /* Subsequent WMA value are evaluated by using
    * the DO_PRICE_WMA macro.
    */
   #define DO_PRICE_WMA(varNewPrice,varToStoreSmoothedValue) { \
      periodWMASub     += varNewPrice; \
      periodWMASub     -= trailingWMAValue; \
      periodWMASum     += varNewPrice*4.0; \
      trailingWMAValue  = inReal[trailingWMAIdx++]; \
      varToStoreSmoothedValue = periodWMASum*0.1; \
      periodWMASum -= periodWMASub; \
   }

   i = 9;
   do
   {
      tempReal = inReal[today++];
      DO_PRICE_WMA(tempReal,smoothedValue);
   } while( --i != 0);

   /* Initialize the circular buffers used by the hilbert
    * transform logic. 
    * A buffer is used for odd day and another for even days.
    * This minimize the number of memory access and floating point
    * operations needed (note also that by using static circular buffer, 
    * no large dynamic memory allocation is needed for storing
    * intermediate calculation!).
    */
   hilbertIdx = 0;

   INIT_HILBERT_VARIABLES(detrender);
   INIT_HILBERT_VARIABLES(Q1);
   INIT_HILBERT_VARIABLES(jI);
   INIT_HILBERT_VARIABLES(jQ);

   period = 0.0;
   outIdx = 0;

   prevI2 = prevQ2 = 0.0;
   Re     = Im     = 0.0;
   I1ForOddPrev3 = I1ForEvenPrev3 = 0.0;
   I1ForOddPrev2 = I1ForEvenPrev2 = 0.0;

   /* The code is speed optimized and is most likely very
    * hard to follow if you do not already know well the
    * original algorithm.
    * To understadn better, it is strongly suggested to look 
    * first at the Excel implementation in "test_MAMA.xls" included
    * in this package.
    */
   while( today <= endIdx )
   {
      adjustedPrevPeriod = (0.075*period)+0.54;

      todayValue = inReal[today];
      DO_PRICE_WMA(todayValue,smoothedValue);

      if( (today%2) == 0 )
      {
         /* Do the Hilbert Transforms for even price bar */
         DO_HILBERT_EVEN(detrender,smoothedValue);
         DO_HILBERT_EVEN(Q1,detrender);
         if( today >= startIdx )
         {
            outQuadrature[outIdx] = Q1;
            outInPhase[outIdx++] = I1ForEvenPrev3;
         }
         DO_HILBERT_EVEN(jI,I1ForEvenPrev3);
         DO_HILBERT_EVEN(jQ,Q1);
         if( ++hilbertIdx == 3 )
            hilbertIdx = 0;

         Q2 = (0.2*(Q1 + jI)) + (0.8*prevQ2);
         I2 = (0.2*(I1ForEvenPrev3 - jQ)) + (0.8*prevI2);

         /* The variable I1 is the detrender delayed for
          * 3 price bars. 
          *
          * Save the current detrender value for being
          * used by the "odd" logic later.
          */
         I1ForOddPrev3 = I1ForOddPrev2;
         I1ForOddPrev2 = detrender;
      
      }
      else
      {
         /* Do the Hilbert Transforms for odd price bar */
         DO_HILBERT_ODD(detrender,smoothedValue);
         DO_HILBERT_ODD(Q1,detrender);
         if( today >= startIdx )
         {
            outQuadrature[outIdx] = Q1;
            outInPhase[outIdx++] = I1ForOddPrev3;
         }
         DO_HILBERT_ODD(jI,I1ForOddPrev3);
         DO_HILBERT_ODD(jQ,Q1);

         Q2 = (0.2*(Q1 + jI)) + (0.8*prevQ2);
         I2 = (0.2*(I1ForOddPrev3 - jQ)) + (0.8*prevI2);

         /* The varaiable I1 is the detrender delayed for
          * 3 price bars. 
          *
          * Save the current detrender value for being
          * used by the "even" logic later.
          */
         I1ForEvenPrev3 = I1ForEvenPrev2;
         I1ForEvenPrev2 = detrender;
      }

      /* Adjust the period for next price bar */
      Re = (0.2*((I2*prevI2)+(Q2*prevQ2)))+(0.8*Re);
      Im = (0.2*((I2*prevQ2)-(Q2*prevI2)))+(0.8*Im);
      prevQ2 = Q2;
      prevI2 = I2;
      tempReal = period;
      if( (Im != 0.0) && (Re != 0.0) )
         period = 360.0 / (atan(Im/Re)*rad2Deg);
      tempReal2 = 1.5*tempReal;
      if( period > tempReal2)
         period = tempReal2;
      tempReal2 = 0.67*tempReal;
      if( period < tempReal2 )
         period = tempReal2;
      if( period < 6 )
         period = 6;
      else if( period > 50 )
         period = 50;
      period = (0.2*period) + (0.8 * tempReal);

      /* Ooof... let's do the next price bar now! */
      today++;
   }

   /* Default return values */
   VALUE_HANDLE_DEREF(outNbElement) = outIdx;

   return NAMESPACE(TA_RetCode)TA_SUCCESS;
}

/**** START GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::HT_PHASOR( int    startIdx,
/* Generated */                                              int    endIdx,
/* Generated */                                              cli::array<float>^ inReal,
/* Generated */                                              [Out]int%    outBegIdx,
/* Generated */                                              [Out]int%    outNbElement,
/* Generated */                                              cli::array<double>^  outInPhase,
/* Generated */                                              cli::array<double>^  outQuadrature )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode HT_PHASOR( int    startIdx,
/* Generated */                              int    endIdx,
/* Generated */                              float        inReal[],
/* Generated */                              MInteger     outBegIdx,
/* Generated */                              MInteger     outNbElement,
/* Generated */                              double        outInPhase[],
/* Generated */                              double        outQuadrature[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_HT_PHASOR( int    startIdx,
/* Generated */                            int    endIdx,
/* Generated */                            const float  inReal[],
/* Generated */                            int          *outBegIdx,
/* Generated */                            int          *outNbElement,
/* Generated */                            double        outInPhase[],
/* Generated */                            double        outQuadrature[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    int outIdx, i;
/* Generated */    int lookbackTotal, today;
/* Generated */    double tempReal, tempReal2;
/* Generated */    double adjustedPrevPeriod, period;
/* Generated */    int trailingWMAIdx;
/* Generated */    double periodWMASum, periodWMASub, trailingWMAValue;
/* Generated */    double smoothedValue;
/* Generated */    CONSTANT_DOUBLE(a) = 0.0962;
/* Generated */    CONSTANT_DOUBLE(b) = 0.5769;
/* Generated */    double hilbertTempReal;
/* Generated */    int hilbertIdx;
/* Generated */    HILBERT_VARIABLES( detrender );
/* Generated */    HILBERT_VARIABLES( Q1 );
/* Generated */    HILBERT_VARIABLES( jI );
/* Generated */    HILBERT_VARIABLES( jQ );
/* Generated */    double Q2, I2, prevQ2, prevI2, Re, Im;
/* Generated */    double I1ForOddPrev2,  I1ForOddPrev3;
/* Generated */    double I1ForEvenPrev2, I1ForEvenPrev3;
/* Generated */    double rad2Deg;
/* Generated */    double todayValue;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !outInPhase )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     if( !outQuadrature )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    rad2Deg = 180.0 / (4.0 * atan(1));
/* Generated */    lookbackTotal = 32 + TA_GLOBALS_UNSTABLE_PERIOD(TA_FUNC_UNST_HT_PHASOR);
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */    }
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx) = startIdx;
/* Generated */    trailingWMAIdx = startIdx - lookbackTotal;
/* Generated */    today = trailingWMAIdx;
/* Generated */    tempReal = inReal[today++];
/* Generated */    periodWMASub = tempReal;
/* Generated */    periodWMASum = tempReal;
/* Generated */    tempReal = inReal[today++];
/* Generated */    periodWMASub += tempReal;
/* Generated */    periodWMASum += tempReal*2.0;
/* Generated */    tempReal = inReal[today++];
/* Generated */    periodWMASub += tempReal;
/* Generated */    periodWMASum += tempReal*3.0;
/* Generated */    trailingWMAValue = 0.0;
/* Generated */    #define DO_PRICE_WMA(varNewPrice,varToStoreSmoothedValue) { \
/* Generated */       periodWMASub     += varNewPrice; \
/* Generated */       periodWMASub     -= trailingWMAValue; \
/* Generated */       periodWMASum     += varNewPrice*4.0; \
/* Generated */       trailingWMAValue  = inReal[trailingWMAIdx++]; \
/* Generated */       varToStoreSmoothedValue = periodWMASum*0.1; \
/* Generated */       periodWMASum -= periodWMASub; \
/* Generated */    }
/* Generated */    i = 9;
/* Generated */    do
/* Generated */    {
/* Generated */       tempReal = inReal[today++];
/* Generated */       DO_PRICE_WMA(tempReal,smoothedValue);
/* Generated */    } while( --i != 0);
/* Generated */    hilbertIdx = 0;
/* Generated */    INIT_HILBERT_VARIABLES(detrender);
/* Generated */    INIT_HILBERT_VARIABLES(Q1);
/* Generated */    INIT_HILBERT_VARIABLES(jI);
/* Generated */    INIT_HILBERT_VARIABLES(jQ);
/* Generated */    period = 0.0;
/* Generated */    outIdx = 0;
/* Generated */    prevI2 = prevQ2 = 0.0;
/* Generated */    Re     = Im     = 0.0;
/* Generated */    I1ForOddPrev3 = I1ForEvenPrev3 = 0.0;
/* Generated */    I1ForOddPrev2 = I1ForEvenPrev2 = 0.0;
/* Generated */    while( today <= endIdx )
/* Generated */    {
/* Generated */       adjustedPrevPeriod = (0.075*period)+0.54;
/* Generated */       todayValue = inReal[today];
/* Generated */       DO_PRICE_WMA(todayValue,smoothedValue);
/* Generated */       if( (today%2) == 0 )
/* Generated */       {
/* Generated */          DO_HILBERT_EVEN(detrender,smoothedValue);
/* Generated */          DO_HILBERT_EVEN(Q1,detrender);
/* Generated */          if( today >= startIdx )
/* Generated */          {
/* Generated */             outQuadrature[outIdx] = Q1;
/* Generated */             outInPhase[outIdx++] = I1ForEvenPrev3;
/* Generated */          }
/* Generated */          DO_HILBERT_EVEN(jI,I1ForEvenPrev3);
/* Generated */          DO_HILBERT_EVEN(jQ,Q1);
/* Generated */          if( ++hilbertIdx == 3 )
/* Generated */             hilbertIdx = 0;
/* Generated */          Q2 = (0.2*(Q1 + jI)) + (0.8*prevQ2);
/* Generated */          I2 = (0.2*(I1ForEvenPrev3 - jQ)) + (0.8*prevI2);
/* Generated */          I1ForOddPrev3 = I1ForOddPrev2;
/* Generated */          I1ForOddPrev2 = detrender;
/* Generated */       }
/* Generated */       else
/* Generated */       {
/* Generated */          DO_HILBERT_ODD(detrender,smoothedValue);
/* Generated */          DO_HILBERT_ODD(Q1,detrender);
/* Generated */          if( today >= startIdx )
/* Generated */          {
/* Generated */             outQuadrature[outIdx] = Q1;
/* Generated */             outInPhase[outIdx++] = I1ForOddPrev3;
/* Generated */          }
/* Generated */          DO_HILBERT_ODD(jI,I1ForOddPrev3);
/* Generated */          DO_HILBERT_ODD(jQ,Q1);
/* Generated */          Q2 = (0.2*(Q1 + jI)) + (0.8*prevQ2);
/* Generated */          I2 = (0.2*(I1ForOddPrev3 - jQ)) + (0.8*prevI2);
/* Generated */          I1ForEvenPrev3 = I1ForEvenPrev2;
/* Generated */          I1ForEvenPrev2 = detrender;
/* Generated */       }
/* Generated */       Re = (0.2*((I2*prevI2)+(Q2*prevQ2)))+(0.8*Re);
/* Generated */       Im = (0.2*((I2*prevQ2)-(Q2*prevI2)))+(0.8*Im);
/* Generated */       prevQ2 = Q2;
/* Generated */       prevI2 = I2;
/* Generated */       tempReal = period;
/* Generated */       if( (Im != 0.0) && (Re != 0.0) )
/* Generated */          period = 360.0 / (atan(Im/Re)*rad2Deg);
/* Generated */       tempReal2 = 1.5*tempReal;
/* Generated */       if( period > tempReal2)
/* Generated */          period = tempReal2;
/* Generated */       tempReal2 = 0.67*tempReal;
/* Generated */       if( period < tempReal2 )
/* Generated */          period = tempReal2;
/* Generated */       if( period < 6 )
/* Generated */          period = 6;
/* Generated */       else if( period > 50 )
/* Generated */          period = 50;
/* Generated */       period = (0.2*period) + (0.8 * tempReal);
/* Generated */       today++;
/* Generated */    }
/* Generated */    VALUE_HANDLE_DEREF(outNbElement) = outIdx;
/* Generated */    return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

