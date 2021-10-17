/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2021 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


// PPOPSDEF.H -- define operators
//
// PPOPCG -- defines code-generation requirements
// PPOPAN -- defines table for ANALYSE.C
// PPOPCD -- defines an operator code
// PPOPIM -- defines impossible entry for ANALYSE.C
//           -- can be deleted with a table re-arrangement
// PPOPNAME -- defines start of CO_NAME_...
// PPOPNM -- define CO_NAME...
// PPOPOP -- define mangled version of operator name
//
// This file is never directly #included. Use the following:
//
//  * PPOPS.H       -- enumerate CO_...
//  * PPOPSAN.H     -- generate internal table in ANALYSE.C
//  * PPOPSFLG.H    -- generate the flags column
//  * PPOPSCOP.H    -- generate the CGOP column
//  * PPOPSNAM.H    -- generate names for the CGOP column (debug only)
//  * PPOPSLNM.H    -- generate long names for the CGOP column
//  * PPOPFNAM.H    -- generate names for the Internal Names column
//
// 91/06/25 -- J.W.Welch        -- defined
// 91/10/25 -- J.W.Welch        -- added internal names
// 91/12/04 -- J.W.Welch        -- introduced PPOP.. macros
// 92/01/29 -- J.W.Welch        -- introduced OPCNV_... bits
// 92/12/18 -- Greg Bentz       -- added PPOPSLNM.H
// 93/01/18 -- Greg Bentz       -- added PPOPOP
// 93/09/29 -- A.F.Scian        -- added delete [] and new []
// 95/02/16 -- A.F.Scian        -- moved non-null PPOPOP operators up so that
//                                 CppLookupOperatorName doesn't have to sift through
//                                 impossible operator names to lookup valid
//                                 operator names

// define null macros as required

#ifndef PPOPCD
    #define PPOPCD( a )
    #define undefPPOPCD
#endif

#ifndef PPOPOP
    #define PPOPOP( a, sa )
    #define undefPPOPOP
#endif

#ifndef PPOPCG
    #define PPOPCG( a, b, c )
    #define undefPPOPCG
#endif

#ifndef PPOPIM
    #define PPOPIM
    #define undefPPOPIM
#endif

#ifndef PPOPAN
    #define PPOPAN( a, b, c, d, e )
    #define undefPPOPAN
#endif

#ifndef PPOPNMS
    #define PPOPNMS
    #define undefPPOPNMS
#endif

#ifndef PPOPNM
    #define PPOPNM( a )
    #define undefPPOPNM
#endif

#ifndef PPOPEND
    #define PPOPEND
    #define undefPPOPEND
#endif


#ifndef ONLY_INTRINSIC

#define delim

PPOPCD( PLUS )
PPOPOP( "OJ", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_PLUS, O_PLUS, "+" )
PPOPAN( ER__BOTH_PTR, LVALUE_BEXPR, SW_LV_EXPR, BIN_ARITH, ER__ONLY_AP )//o+o

#undef  delim
#define delim ,

PPOPCD( MINUS )
PPOPOP( "OI", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_MINUS, O_MINUS, "-" )
PPOPAN( MINUS_PP, LVALUE_BEXPR, ER__SUB_AP, BIN_ARITH, ER__ONLY_AP )//o-o

PPOPCD( TIMES )
PPOPOP( "OF", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_TWO_AR, O_TIMES, "*" )
PPOPAN( ER__ONLY_AR, ER__ONLY_AR, ER__ONLY_AR, BIN_ARITH, ER__ONLY_AR )//o*o

PPOPCD( DIVIDE )
PPOPOP( "OM", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_TWO_AR, O_DIV, "/" )
PPOPAN( ER__ONLY_AR, ER__ONLY_AR, ER__ONLY_AR, BIN_ARITH, ER__ONLY_AR )//o/o

PPOPCD( PERCENT )
PPOPOP( "ON", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_TWO_INT, O_MOD, "%" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, BIN_ARITH_I, ER__ONLY_IN )//o%o

PPOPCD( AND )
PPOPOP( "OK", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_TWO_INT, O_AND, "&" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, BIN_ARITH_I, ER__ONLY_IN )//o&o

PPOPCD( OR )
PPOPOP( "OS", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_TWO_INT, O_OR, "|" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, BIN_ARITH_I, ER__ONLY_IN )//o|o

PPOPCD( XOR )
PPOPOP( "OR", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_TWO_INT, O_XOR, "^" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, BIN_ARITH_I, ER__ONLY_IN )//o^o

PPOPCD( RSHIFT )
PPOPOP( "OA", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_SHIFT, O_RSHIFT, ">>" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, SHIFT_OP, ER__ONLY_IN )//o>>o

PPOPCD( LSHIFT )
PPOPOP( "OB", INVALID )
PPOPCG( PTO_BIN_ARITH | OPCNV_SHIFT, O_LSHIFT, "<<" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, SHIFT_OP, ER__ONLY_IN )//o<<o

PPOPCD( UMINUS )
PPOPOP( "OI", MINUS )
PPOPCG( PTO_UN_ARITH | OPCNV_ONE_AR, O_UMINUS, "-" )
PPOPAN( ER__ONLY_AR, IMPOSSIBLE, IMPOSSIBLE, UN_ARITH, ER__ONLY_IN )//-o

PPOPCD( TILDE )
PPOPOP( "OQ", INVALID )
PPOPCG( PTO_UN_ARITH | OPCNV_ONE_INT, O_COMPLEMENT, "~" )
PPOPAN( ER__ONLY_IN, IMPOSSIBLE, IMPOSSIBLE, UN_ARITH_I, ER__ONLY_IN )//~o

PPOPCD( ADDR_OF )
PPOPOP( "OK", AND )
PPOPCG( PTO_ADDR_OPER, 0, "&" )
PPOPAN( ADDR_OF, IMPOSSIBLE, IMPOSSIBLE, ADDR_OF, ADDR_OF )//&o

PPOPCD( EQUAL )
PPOPOP( "AA", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQUALS | PTO_ASSIGN_SAME, O_GETS, "=" )
PPOPAN( EQUAL_PP, EQUAL_PZ, EQUAL_AP, EQUAL_AA, EQUAL_OTHER )//o=o

PPOPCD( EQ )
PPOPOP( "RA", INVALID )
PPOPCG( PTO_COMPARES | OPCNV_RELEQ, O_EQ, "==" )
PPOPAN( CMP_PP, CMP_PTR_ZERO, CMP_ZERO_PTR, CMP_AA, CMP_MP )//o==o

PPOPCD( NE )
PPOPOP( "RB", INVALID )
PPOPCG( PTO_COMPARES | OPCNV_RELEQ, O_NE, "!=" )
PPOPAN( CMP_PP, CMP_PTR_ZERO, CMP_ZERO_PTR, CMP_AA, CMP_MP )//o!=o

PPOPCD( GT )
PPOPOP( "RE", INVALID )
PPOPCG( PTO_COMPARES | OPCNV_RELN, O_GT, ">" )
PPOPAN( CMP_PP, CMP_PTR_ZERO, CMP_ZERO_PTR, CMP_AA, ER__ONLY_AP )//o>o

PPOPCD( LE )
PPOPOP( "RD", INVALID )
PPOPCG( PTO_COMPARES | OPCNV_RELN, O_LE, "<=" )
PPOPAN( CMP_PP, CMP_PTR_ZERO, CMP_ZERO_PTR, CMP_AA, ER__ONLY_AP )//o<=o

PPOPCD( LT )
PPOPOP( "RC", INVALID )
PPOPCG( PTO_COMPARES | OPCNV_RELN, O_LT, "<" )
PPOPAN( CMP_PP, CMP_PTR_ZERO, CMP_ZERO_PTR, CMP_AA, ER__ONLY_AP )//o<o

PPOPCD( GE )
PPOPOP( "RF", INVALID )
PPOPCG( PTO_COMPARES | OPCNV_RELN, O_GE, ">=" )
PPOPAN( CMP_PP, CMP_PTR_ZERO, CMP_ZERO_PTR, CMP_AA, ER__ONLY_AP )//o>=o

PPOPCD( AND_AND )
PPOPOP( "OT", INVALID )
PPOPCG( PTO_FLOW_BINARY | OPCNV_LOG2, O_FLOW_AND, "&&" )
PPOPAN( BIN_LOG_PP, BIN_LOG_PA, BIN_LOG_AP, BIN_LOG_AA, BIN_LOG_MP )//o&&o

PPOPCD( OR_OR )
PPOPOP( "OU", INVALID )
PPOPCG( PTO_FLOW_BINARY | OPCNV_LOG2, O_FLOW_OR, "||" )
PPOPAN( BIN_LOG_PP, BIN_LOG_PA, BIN_LOG_AP, BIN_LOG_AA, BIN_LOG_MP )//o&&o

PPOPCD( EXCLAMATION )
PPOPOP( "OC", INVALID )
PPOPCG( PTO_FLOW_UNARY | OPCNV_LOG1, O_FLOW_NOT, "!" )
PPOPAN( UN_LOG_P, UN_LOG_P, UN_LOG, UN_LOG, UN_LOG_MP )//!o

PPOPCD( ARROW )
PPOPOP( "OE", INVALID )
PPOPCG( PTO_POINTS_TO | OPCNV_ARROW, O_PLUS, "->" )
PPOPIM

PPOPCD( INDEX )
PPOPOP( "OD", INVALID )
PPOPCG( PTO_INDEX | OPCNV_SUBSCR, 0, "[]" )
PPOPAN( ER__PP_INDEX, INDEX_PA, INDEX_AP, ER__INDEX, ER__INDEX )//o[o]

PPOPCD( PLUS_EQUAL )
PPOPOP( "AC", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQAP | PTO_ASSIGN_SAME, O_PLUS, "+=" )
PPOPAN( ER__BOTH_PTR, OPEQ_PTR, ER__AP_ASSN, OPEQ_ARITH, ER__ONLY_AP )//o+=o

PPOPCD( MINUS_EQUAL )
PPOPOP( "AD", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQAP | PTO_ASSIGN_SAME, O_MINUS, "-=" )
PPOPAN( ER__BOTH_PTR, OPEQ_PTR, ER__AP_ASSN, OPEQ_ARITH, ER__ONLY_AP )//o-=o

PPOPCD( TIMES_EQUAL )
PPOPOP( "AB", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQAR, O_TIMES, "*=" )
PPOPAN( ER__ONLY_AR, ER__ONLY_AR, ER__ONLY_AR, OPEQ_ARITH, ER__ONLY_AR )//o*=o

PPOPCD( DIVIDE_EQUAL )
PPOPOP( "AE", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQAR, O_DIV, "/=" )
PPOPAN( ER__ONLY_AR, ER__ONLY_AR, ER__ONLY_AR, OPEQ_ARITH, ER__ONLY_AR )//o/=o

PPOPCD( PERCENT_EQUAL )
PPOPOP( "AF", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQINT, O_MOD, "%=" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, OPEQ_INT, ER__ONLY_IN )//o%=o

PPOPCD( AND_EQUAL )
PPOPOP( "AI", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQINT | PTO_ASSIGN_SAME, O_AND, "&=" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, OPEQ_INT, ER__ONLY_IN )//o&=o

PPOPCD( OR_EQUAL )
PPOPOP( "AJ", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQINT | PTO_ASSIGN_SAME, O_OR, "|=" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, OPEQ_INT, ER__ONLY_IN )//o|=o

PPOPCD( XOR_EQUAL )
PPOPOP( "AK", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQINT | PTO_ASSIGN_SAME, O_XOR, "^=" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, OPEQ_INT, ER__ONLY_IN )//o^=o

PPOPCD( RSHIFT_EQUAL )
PPOPOP( "AG", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQINT, O_RSHIFT, ">>=" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, OPEQ_SHIFT, ER__ONLY_IN )//o>>=o

PPOPCD( LSHIFT_EQUAL )
PPOPOP( "AH", INVALID )
PPOPCG( PTO_BIN_ASSIGN | OPCNV_EQINT, O_LSHIFT, "<<=" )
PPOPAN( ER__ONLY_IN, ER__ONLY_IN, ER__ONLY_IN, OPEQ_SHIFT, ER__ONLY_IN )//o<<=o

PPOPCD( UPLUS )
PPOPOP( "OJ", PLUS )
PPOPCG( PTO_UN_ARITH | OPCNV_ONE_AR, 0, "+" )
PPOPAN( UN_PLUS_PTR, IMPOSSIBLE, IMPOSSIBLE, UN_ARITH, ER__ONLY_AR )//+o

// these four operators must be in the same order as their BPRE/BPOST equivalents

PPOPCD( PRE_PLUS_PLUS )
PPOPOP( "OG", INVALID )
PPOPCG( PTO_UN_ASSIGN | OPCNV_ONE_RAP, 0, "++" )
PPOPAN( LINCDEC_PTR, IMPOSSIBLE, IMPOSSIBLE, LINCDEC_ARITH, ER__ONLY_AP )//++o

PPOPCD( PRE_MINUS_MINUS )
PPOPOP( "OH", INVALID )
PPOPCG( PTO_UN_ASSIGN | OPCNV_ONE_RAP, 0, "--" )
PPOPAN( LINCDEC_PTR, IMPOSSIBLE, IMPOSSIBLE, LINCDEC_ARITH, ER__ONLY_AP )//--o

PPOPCD( POST_PLUS_PLUS )
PPOPOP( "OG", PRE_PLUS_PLUS )
PPOPCG( PTO_UN_ASSIGN | OPCNV_POST_OP, 0, "++" )
PPOPAN( INCDEC_PTR, IMPOSSIBLE, IMPOSSIBLE, INCDEC_ARITH, ER__ONLY_AP )//o++

PPOPCD( POST_MINUS_MINUS )
PPOPOP( "OH", PRE_MINUS_MINUS )
PPOPCG( PTO_UN_ASSIGN | OPCNV_POST_OP, 0, "--" )
PPOPAN( INCDEC_PTR, IMPOSSIBLE, IMPOSSIBLE, INCDEC_ARITH, ER__ONLY_AP )//o--

PPOPCD( INDIRECT )
PPOPOP( "OF", TIMES )
PPOPCG( PTO_ADDR_OPER | OPCNV_PTR, O_POINTS, "*" )
PPOPAN( INDIRECT, IMPOSSIBLE, IMPOSSIBLE, ER__NO_PTR, ER__NO_PTR )//*o

PPOPCD( COMMA )
PPOPOP( "OO", INVALID )
PPOPCG( PTO_BINARY_OVLD, O_COMMA, "," )
PPOPAN( COMMA, COMMA, COMMA, COMMA, COMMA )//o, o

PPOPCD( ARROW_STAR )
PPOPOP( "OL", INVALID )
PPOPCG( PTO_BINARY_OVLD | OPCNV_ARROW_STAR, 0, "->*" )
PPOPAN( ARROW_STAR, ARROW_STAR, ARROW_STAR, ARROW_STAR, ARROW_STAR )//o->*o

PPOPCD( CALL )
PPOPOP( "OP", INVALID )
PPOPCG( PTO_FUNCALL | OPCNV_FUNCTION, 0, "()" )
PPOPAN( CALL, CALL, ER__NOT_FUN, ER__NOT_FUN, CALL )//o(o)

PPOPCD( CONVERT )
PPOPOP( "CV", INVALID )
PPOPCG( PTO_BINARY_NO_OVLD, O_CONVERT, "CONV" )
PPOPAN( CAST, CAST, CAST, CAST, CAST )//convert

PPOPCD( NEW )
PPOPOP( "NW", INVALID )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "new" )
PPOPAN( NEW, NEW, NEW, NEW, NEW )//new

PPOPCD( NEW_ARRAY )
PPOPOP( "NA", INVALID )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "new[]" )
PPOPAN( NEW, NEW, NEW, NEW, NEW )//new

PPOPCD( DELETE )
PPOPOP( "DL", INVALID )
PPOPCG( PTO_UNARY_NO_OVLD, 0, "delete" )
PPOPAN( DLT, DLT, DLT, DLT, DLT )//delete

PPOPCD( DELETE_ARRAY )
PPOPOP( "DA", INVALID )
PPOPCG( PTO_UNARY_NO_OVLD, 0, "delete[]" )
PPOPAN( DLT, DLT, DLT, DLT, DLT )//delete_array

PPOPCD( DTOR )
PPOPOP( "DT", INVALID )
PPOPCG( PTO_BINARY_CPP, 0, "DTOR" )
PPOPIM

PPOPCD( CTOR )
PPOPOP( "CT", INVALID )
PPOPCG( PTO_BINARY_CPP, 0, "CTOR" )
PPOPAN( CTOR, CTOR, CTOR, CTOR, CTOR )//ctor

//---
PPOPCD( DOT )
PPOPCG( PTO_DOT, O_PLUS, "." )
PPOPIM

PPOPCD( QUESTION )
PPOPCG( PTO_BINARY_NO_OVLD | OPCNV_QUESTION, 0, "" )
PPOPAN( QUESTMRK, QUESTMRK, QUESTMRK, QUESTMRK, QUESTMRK )//o?o

PPOPCD( COLON )
//PPOPCG( PTO_BINARY_NO_OVLD | OPCNV_COLON, 0, "" )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "" )
PPOPAN( COLON_PP, COLON_PA, COLON_AP, COLON_AA, COLON_OTHER )//o:o

PPOPCD( LIST )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "" )
PPOPAN( PARAMETER_P, PARAMETER, PARAMETER_P, PARAMETER, PARAMETER_P )//list

PPOPCD( DOT_STAR )
PPOPCG( PTO_DOT, 0, ".*" )
PPOPAN( DOT_STAR, DOT_STAR, DOT_STAR, DOT_STAR, DOT_STAR )//o.*o

PPOPCD( CONVERT_INT )
PPOPCG( PTO_UNARY_CPP | OPCNV_ONE_INT, O_NOP, "" )
PPOPAN( ER__ONLY_IN, IMPOSSIBLE, IMPOSSIBLE, CONVERT_INT, CONVERT_INT )

PPOPCD( SIZEOF_TYPE )
PPOPCG( PTO_UNARY_NO_OVLD, 0, "" )
PPOPAN( OP_SIZEOF, IMPOSSIBLE, IMPOSSIBLE, OP_SIZEOF, OP_SIZEOF )//sizeof-type

PPOPCD( SIZEOF_EXPR )
PPOPCG( PTO_UNARY_NO_OVLD, 0, "" )
PPOPAN( OP_SIZEOF, IMPOSSIBLE, IMPOSSIBLE, OP_SIZEOF, OP_SIZEOF )//sizeof-expr

PPOPCD( OFFSETOF )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "" )
PPOPAN( IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, DO_NOTHING )

PPOPCD( STORAGE )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "storage" )
PPOPAN( IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, DO_NOTHING )

PPOPCD( TEMPLATE )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "" )
PPOPAN( IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, DO_NOTHING )

PPOPCD( OPERATOR )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "operator" )
PPOPAN( IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, DO_NOTHING )

PPOPCD( COLON_COLON )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "::" )
PPOPIM

PPOPCD( SEG_OP )
PPOPCG( PTO_BINARY_NO_OVLD, O_CONVERT, ":>" )
PPOPAN( ER__SEGOP, ER__SEGOP, SEGOP, ER__SEGOP, ER__SEGOP ) // o:>o

PPOPCD( DYNAMIC_CAST )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPAN( DYN_CAST, DYN_CAST, DYN_CAST, DYN_CAST, DYN_CAST )  //dynamic_cast<t>(e)

PPOPCD( STATIC_CAST )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPAN( STAT_CAST, STAT_CAST, STAT_CAST, STAT_CAST, STAT_CAST )//static_cast<t>(e)

PPOPCD( REINTERPRET_CAST )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPAN( REINT_CAST, REINT_CAST, REINT_CAST, REINT_CAST, REINT_CAST ) //reinterpret_cast<t>(e)

PPOPCD( CONST_CAST )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPAN( CONST_CAST, CONST_CAST, CONST_CAST, CONST_CAST, CONST_CAST ) //const_cast

PPOPCD( TYPEID_EXPR )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPAN( TID_EXPR, TID_EXPR, TID_EXPR, TID_EXPR, TID_EXPR )//typeid(expr)

PPOPCD( TYPEID_TYPE )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPAN( TID_TYPE, TID_TYPE, TID_TYPE, TID_TYPE, TID_TYPE )//typeid(type)

PPOPCD( DELETE_G )
PPOPCG( PTO_UNARY_NO_OVLD, 0, "::delete" )
PPOPAN( DLT, DLT, DLT, DLT, DLT )//delete_g

PPOPCD( DELETE_G_ARRAY )
PPOPCG( PTO_UNARY_NO_OVLD, 0, "::delete[]" )
PPOPAN( DLT, DLT, DLT, DLT, DLT )//delete_g_array

PPOPCD( NEW_G )
PPOPCG( PTO_BINARY_NO_OVLD, 0, "new" )
PPOPAN( NEW, NEW, NEW, NEW, NEW )//new

PPOPCD( NEW_PARMS1 )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPAN( DO_NOTHING, DO_NOTHING, DO_NOTHING, DO_NOTHING, DO_NOTHING )//new_parms_1

PPOPCD( NEW_PARMS2 )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPAN( DO_NOTHING, DO_NOTHING, DO_NOTHING, DO_NOTHING, DO_NOTHING )//new_parms_2

PPOPCD( SEGNAME )                // __segname( string )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPAN( SEGNAME, IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE )

PPOPCD( RETURN )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPAN( RETURN__P, RETURN_PA, RETURN__P, RETURN_AA, RETURN__P )

PPOPCD( CALL_NOOVLD )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPAN( CALL, CALL, ER__NOT_FUN, ER__NOT_FUN, CALL )//o(o) no overload

PPOPCD( THROW )
PPOPCG( PTO_UNARY_NO_OVLD, 0, "" )
PPOPAN( THROW, THROW, THROW, THROW, THROW )

PPOPCD( INIT )
PPOPCG( PTO_BINARY_CPP, O_GETS, "" )
PPOPAN( INIT_PP, INIT_PZ, INIT_AP, INIT_AA, INIT_OTHER )//o=o

#endif

PPOPCD( LOG )
PPOPCG( PTO_UN_ARITH, O_LOG, "log" )
PPOPIM

PPOPCD( COS )
PPOPCG( PTO_UN_ARITH, O_COS, "cos" )
PPOPIM

PPOPCD( SIN )
PPOPCG( PTO_UN_ARITH, O_SIN, "sin" )
PPOPIM

PPOPCD( TAN )
PPOPCG( PTO_UN_ARITH, O_TAN, "tan" )
PPOPIM

PPOPCD( SQRT )
PPOPCG( PTO_UN_ARITH, O_SQRT, "sqrt" )
PPOPIM

PPOPCD( FABS )
PPOPCG( PTO_UN_ARITH, O_FABS, "fabs" )
PPOPIM

PPOPCD( ACOS )
PPOPCG( PTO_UN_ARITH, O_ACOS, "acos" )
PPOPIM

PPOPCD( ASIN )
PPOPCG( PTO_UN_ARITH, O_ASIN, "asin" )
PPOPIM

PPOPCD( ATAN )
PPOPCG( PTO_UN_ARITH, O_ATAN, "atan" )
PPOPIM

PPOPCD( COSH )
PPOPCG( PTO_UN_ARITH, O_COSH, "cosh" )
PPOPIM

PPOPCD( EXP )
PPOPCG( PTO_UN_ARITH, O_EXP, "exp" )
PPOPIM

PPOPCD( SINH )
PPOPCG( PTO_UN_ARITH, O_SINH, "sinh" )
PPOPIM

PPOPCD( TANH )
PPOPCG( PTO_UN_ARITH, O_TANH, "tanh" )
PPOPIM

PPOPCD( LOG10 )
PPOPCG( PTO_UN_ARITH, O_LOG10, "log10" )
PPOPIM

PPOPCD( POW )
PPOPCG( PTO_BIN_ARITH, O_POW, "pow" )
PPOPIM

PPOPCD( ATAN2 )
PPOPCG( PTO_BIN_ARITH, O_ATAN2, "atan2" )
PPOPIM

PPOPCD( FMOD )
PPOPCG( PTO_BIN_ARITH, O_FMOD, "fmod" )
PPOPIM

// INTRINSIC FUNCTIONS FOR ALPHA

#if _CPU == _AXP

PPOPCD( VASTART )
PPOPCG( PTO_BINARY_CPP, 0, "__builtin_va_start" )
PPOPIM

PPOPCD( ALLOCA )
PPOPCG( PTO_UNARY_CPP, 0, "__builtin_alloca" )
PPOPIM

#endif

#ifndef ONLY_INTRINSIC

PPOPCD( ROUND )
PPOPCG( PTO_UN_ARITH, O_ROUND, "" )
PPOPIM

PPOPCD( INVALID )
PPOPCG( 0, 0, "" )
PPOPIM

PPOPCD( FETCH )
PPOPCG( PTO_FETCH, O_POINTS, "" )
PPOPIM

PPOPCD( TRASH_EXPR )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( EXPR_DONE )
PPOPCG( PTO_UN_ARITH, 0, "" )
PPOPIM

PPOPCD( CALL_EXEC )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPIM

PPOPCD( CALL_SETUP )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( CALL_EXEC_IND )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPIM

PPOPCD( CALL_SETUP_IND )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( COPY_OBJECT )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPIM

PPOPCD( BITFLD_CONVERT )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( PTR_DELTA )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPIM

PPOPCD( RTFUN_INIT )
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPIM

PPOPCD( RTFUN_EXEC )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( BPRE_PLUS_PLUS )
PPOPCG( PTO_BIN_ASSIGN, O_PLUS, "" )
PPOPIM

PPOPCD( BPRE_MINUS_MINUS )
PPOPCG( PTO_BIN_ASSIGN, O_MINUS, "" )
PPOPIM

PPOPCD( BPOST_PLUS_PLUS )
PPOPCG( PTO_BIN_ASSIGN, O_PLUS, "" )
PPOPIM

PPOPCD( BPOST_MINUS_MINUS )
PPOPCG( PTO_BIN_ASSIGN, O_MINUS, "" )
PPOPIM

PPOPCD( BPRE_BOOL_PLUS_PLUS )
PPOPCG( PTO_BIN_ASSIGN, O_OR, "" )
PPOPIM

PPOPCD( BPOST_BOOL_PLUS_PLUS )
PPOPCG( PTO_BIN_ASSIGN, O_OR, "" )
PPOPIM

PPOPCD( MEMPTR_CONST )           // constant member ptr
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( DTOR_STATIC )            // DTOR static member
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPIM

PPOPCD( RARG_FETCH )             // fetch reference argument
PPOPCG( PTO_FETCH, 0, "" )
PPOPIM

PPOPCD( RARG_FETCH_OFF )         // fetch offsetted reference argument
PPOPCG( PTO_UNARY_CPP, O_POINTS, "" )
PPOPIM

PPOPCD( FAR16_TO_POINTER )       // unary convert far16 ptr to near ptr
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( POINTER_TO_FAR16 )       // unary convert near ptr to far16 ptr
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

// "under top" version of these operators must be right after "top" version

PPOPCD( VOLATILE_TOP )           // l-value must be fetched assuming volatility
PPOPCG( PTO_UNARY_CPP, 0, "" )      // (top of expression stack)
PPOPIM

PPOPCD( VOLATILE_UNDER_TOP )     // l-value must be fetched assuming volatility
PPOPCG( PTO_UNARY_CPP, 0, "" )      // (just under top of expression stack)
PPOPIM

PPOPCD( CONST_TOP )           // l-value must be fetched assuming constness
PPOPCG( PTO_UNARY_CPP, 0, "" )      // (top of expression stack)
PPOPIM

PPOPCD( CONST_UNDER_TOP )     // l-value must be fetched assuming constness
PPOPCG( PTO_UNARY_CPP, 0, "" )      // (just under top of expression stack)
PPOPIM

PPOPCD( UNALIGNED_TOP )         // l-value must be fetched assuming unaligned
PPOPCG( PTO_UNARY_CPP, 0, "" )  // (top of expression stack)
PPOPIM

PPOPCD( UNALIGNED_UNDER_TOP )   // l-value must be fetched assuming unaligned
PPOPCG( PTO_UNARY_CPP, 0, "" )  // (just under top of expression stack)
PPOPIM

PPOPCD( TYPE_SIG )               // TYPE SIGNATURE
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( SEGOP_SEG )              // SEG_OP -- segment #
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( VIRT_FUNC )              // virtual function
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPIM

PPOPCD( RESET_THIS )             // reset this, if not inlined
PPOPCG( PTO_BINARY_CPP, 0, "" )
PPOPIM

PPOPCD( VBASE_FETCH )            // fetch virtual-base from argument
PPOPCG( PTO_VFETCH, 0, "" )
PPOPIM

PPOPCD( CALL_SETUP_VFUN )        // set up virtual call with ic_vf... opcodes
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( VFUN_PTR )               // set up "this" for virtual funct. call
PPOPCG( PTO_VFETCH, 0, "" )
PPOPIM

PPOPCD( EQUAL_REF )              // assign a reference
PPOPCG( PTO_BINARY_CPP, O_GETS, "=" )
PPOPIM

PPOPCD( INIT_REF )
PPOPCG( PTO_BINARY_CPP, O_GETS, "" )
PPOPIM

// insert new opcodes here

PPOPCD( FILLER00 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER01 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER02 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER03 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER04 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER05 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER06 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER07 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER08 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

PPOPCD( FILLER09 )
PPOPCG( PTO_UNARY_CPP, 0, "" )
PPOPIM

// define opcodes for PT_SYMBOL
PPOPNMS
PPOPNM( NAME_DEFARG )
PPOPNM( NAME_NORMAL )
PPOPNM( NAME_DOT )
PPOPNM( NAME_THIS )
PPOPNM( NAME_DTOR )
PPOPNM( NAME_OPERATOR )
PPOPNM( NAME_CONVERT )
PPOPNM( NAME_CDTOR_EXTRA )
PPOPNM( NAME_DTOR_SYM )
PPOPNM( NAME_PARM_REF )
PPOPNM( NOP )
PPOPNM( USER_CAST )
PPOPNM( IGNORE )               // general ignore

// define end of stuff
PPOPEND

#undef delim

#endif

// undefine any null macros defined

#ifdef undefPPOPCD
    #undef PPOPCD
    #undef undefPPOPCD
#endif

#ifdef undefPPOPOP
    #undef PPOPOP
    #undef undefPPOPOP
#endif

#ifdef undefPPOPCG
    #undef PPOPCG
    #undef undefPPOPCG
#endif

#ifdef undefPPOPIM
    #undef PPOPIM
    #undef undefPPOPIM
#endif

#ifdef undefPPOPAN
    #undef PPOPAN
    #undef undefPPOPAN
#endif

#ifdef undefPPOPNMS
    #undef PPOPNMS
    #undef undefPPOPNMS
#endif

#ifdef undefPPOPNM
    #undef PPOPNM
    #undef undefPPOPNM
#endif

#ifdef undefPPOPEND
    #undef PPOPEND
    #undef undefPPOPEND
#endif
