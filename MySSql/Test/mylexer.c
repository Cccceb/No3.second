/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 1 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 05/25/20
* Time: 11:04:49
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
#endif
#ifdef YYNAMESPACE
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2012年4月5日
****************************************************************************/

#include "myparser.h"
#include <stdlib.h>
char * stop;

#line 51 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 29 ".\\mylexer.l"
;
#line 134 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 31 ".\\mylexer.l"

										yylval.nvalue = strtod(yytext, &stop);//将字面量转化为值
										return NUMBER;
									
#line 144 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 36 ".\\mylexer.l"
 return '+'; 
#line 151 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 37 ".\\mylexer.l"
 return '-'; 
#line 158 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 38 ".\\mylexer.l"
 return '*'; 
#line 165 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 39 ".\\mylexer.l"
 return '/'; 
#line 172 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 40 ".\\mylexer.l"
 return '('; 
#line 179 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 41 ".\\mylexer.l"
 return ')'; 
#line 186 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 42 ".\\mylexer.l"
 return 0; 
#line 193 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 61;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 0, 12 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 4, 1 },
		{ 13, 14 },
		{ 15, 13 },
		{ 4, 4 },
		{ 15, 13 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 0, 0 },
		{ 9, 1 },
		{ 0, 1 },
		{ 10, 1 },
		{ 12, 11 },
		{ 0, 0 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 1 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 11, -9, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 9 },
		{ 0, -6, 1 },
		{ 0, 0, 7 },
		{ 0, 0, 8 },
		{ 0, 0, 5 },
		{ 0, 0, 3 },
		{ 0, 0, 4 },
		{ 0, 0, 6 },
		{ 14, -7, 2 },
		{ 14, -67, 0 },
		{ 16, -18, 0 },
		{ 0, -45, 2 },
		{ 16, 0, 0 },
		{ 0, -35, 2 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 45 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section



