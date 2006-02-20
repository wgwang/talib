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
 *  112400 MF   Template creation.
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
/* Generated */ int Core::MOM_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int MOM_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_MOM_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 10;
/* Generated */    else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */       return -1;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */

   return optInTimePeriod;

}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_MOM - Momentum
 * 
 * Input  = double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod:(From 1 to 100000)
 *    Number of period
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::MOM( int    startIdx,
/* Generated */                                        int    endIdx,
/* Generated */                                        cli::array<double>^ inReal,
/* Generated */                                        int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                                        [Out]int%    outBegIdx,
/* Generated */                                        [Out]int%    outNbElement,
/* Generated */                                        cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode MOM( int    startIdx,
/* Generated */                        int    endIdx,
/* Generated */                        double       inReal[],
/* Generated */                        int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                        MInteger     outBegIdx,
/* Generated */                        MInteger     outNbElement,
/* Generated */                        double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_MOM( int    startIdx,
/* Generated */                    int    endIdx,
/* Generated */                    const double inReal[],
/* Generated */                    int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                    int          *outBegIdx,
/* Generated */                    int          *outNbElement,
/* Generated */                    double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */

   int inIdx, outIdx, trailingIdx;

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
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 10;
/* Generated */    else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !outReal )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* The interpretation of the rate of change varies widely depending
    * which software and/or books you are refering to.
    *
    * The following is the table of Rate-Of-Change implemented in TA-LIB:
    *       MOM     = (price - prevPrice)         [Momentum]
    *       ROC     = ((price/prevPrice)-1)*100   [Rate of change]
    *       ROCP    = (price-prevPrice)/prevPrice [Rate of change Percentage]
    *       ROCR    = (price/prevPrice)           [Rate of change ratio]
    *       ROCR100 = (price/prevPrice)*100       [Rate of change ratio 100 Scale]
    *
    * Here are the equivalent function in other software:
    *       TA-Lib  |   Tradestation   |    Metastock         
    *       =================================================
    *       MOM     |   Momentum       |    ROC (Point)
    *       ROC     |   ROC            |    ROC (Percent)
    *       ROCP    |   PercentChange  |    -     
    *       ROCR    |   -              |    -
    *       ROCR100 |   -              |    MO
    *
    * The MOM function is the only one who is not normalized, and thus
    * should be avoided for comparing different time serie of prices.
    * 
    * ROC and ROCP are centered at zero and can have positive and negative
    * value. Here are some equivalence:
    *    ROC = ROCP/100 
    *        = ((price-prevPrice)/prevPrice)/100
    *        = ((price/prevPrice)-1)*100
    *
    * ROCR and ROCR100 are ratio respectively centered at 1 and 100 and are
    * always positive values.
    */

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < optInTimePeriod )
      startIdx = optInTimePeriod;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      return NAMESPACE(TA_RetCode)TA_SUCCESS;
   }

   /* Calculate Momentum:
    *    Just substract the value from 'period' ago from
    *    current value.
    */
   outIdx      = 0;
   inIdx       = startIdx;
   trailingIdx = startIdx - optInTimePeriod;

   while( inIdx <= endIdx )
      outReal[outIdx++] = inReal[inIdx++] - inReal[trailingIdx++];

   /* Set output limits. */
   VALUE_HANDLE_DEREF(outNbElement) = outIdx;
   VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;

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
/* Generated */ enum class Core::TA_RetCode Core::MOM( int    startIdx,
/* Generated */                                        int    endIdx,
/* Generated */                                        cli::array<float>^ inReal,
/* Generated */                                        int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                                        [Out]int%    outBegIdx,
/* Generated */                                        [Out]int%    outNbElement,
/* Generated */                                        cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode MOM( int    startIdx,
/* Generated */                        int    endIdx,
/* Generated */                        float        inReal[],
/* Generated */                        int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                        MInteger     outBegIdx,
/* Generated */                        MInteger     outNbElement,
/* Generated */                        double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_MOM( int    startIdx,
/* Generated */                      int    endIdx,
/* Generated */                      const float  inReal[],
/* Generated */                      int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                      int          *outBegIdx,
/* Generated */                      int          *outNbElement,
/* Generated */                      double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    int inIdx, outIdx, trailingIdx;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInTimePeriod = 10;
/* Generated */     else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !outReal )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    if( startIdx < optInTimePeriod )
/* Generated */       startIdx = optInTimePeriod;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */    }
/* Generated */    outIdx      = 0;
/* Generated */    inIdx       = startIdx;
/* Generated */    trailingIdx = startIdx - optInTimePeriod;
/* Generated */    while( inIdx <= endIdx )
/* Generated */       outReal[outIdx++] = inReal[inIdx++] - inReal[trailingIdx++];
/* Generated */    VALUE_HANDLE_DEREF(outNbElement) = outIdx;
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;
/* Generated */    return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

