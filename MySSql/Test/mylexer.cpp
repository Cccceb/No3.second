/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 22 of your 30 day trial period.
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
* Date: 06/15/20
* Time: 12:23:55
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

//this code will be added into the header of generated .cpp file
#include <iostream>
#include "myparser.h"
#pragma warning(disable:4996)
using namespace std;

#line 46 "mylexer.cpp"
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

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
}

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
#line 12 ".\\mylexer.l"

//this code will be added into yyaction function
    YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
    //double yylval;

#line 144 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 17 ".\\mylexer.l"
return NOT;
#line 151 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 18 ".\\mylexer.l"
return EXIT;
#line 158 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 19 ".\\mylexer.l"
return TABLES;
#line 165 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 20 ".\\mylexer.l"
return DROP;
#line 172 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 21 ".\\mylexer.l"
return DELETE;
#line 179 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 22 ".\\mylexer.l"
return FROM;
#line 186 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 23 ".\\mylexer.l"
return UPDATE;
#line 193 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 24 ".\\mylexer.l"
return SET;
#line 200 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 25 ".\\mylexer.l"
return CREATE;
#line 207 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 26 ".\\mylexer.l"
return SHOW;
#line 214 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 27 ".\\mylexer.l"
return USE;
#line 221 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 28 ".\\mylexer.l"
return DATABASE;
#line 228 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 29 ".\\mylexer.l"
return TABLE;
#line 235 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 30 ".\\mylexer.l"
return CHAR;
#line 242 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 31 ".\\mylexer.l"
return INT;
#line 249 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 32 ".\\mylexer.l"
return SELECT;
#line 256 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 33 ".\\mylexer.l"
return WHERE;
#line 263 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 34 ".\\mylexer.l"
return INSERT;
#line 270 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 35 ".\\mylexer.l"
return INTO;
#line 277 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 36 ".\\mylexer.l"
return VALUES;
#line 284 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 37 ".\\mylexer.l"
return AND;
#line 291 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 38 ".\\mylexer.l"
return OR;
#line 298 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 40 ".\\mylexer.l"
	
					yylval.yych=(char *)malloc(strlen(yytext)+1); 			
					strcpy(yylval.yych, yytext);
				//	cout << yylval.yych<<endl;
					return ID;
					
#line 310 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 47 ".\\mylexer.l"

		yylval.yych=(char *)malloc(strlen(yytext)+1); 			
		strcpy(yylval.yych, yytext);
		return NUMBER; 
		
#line 321 "mylexer.cpp"
		}
		break;
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
#line 58 ".\\mylexer.l"
		{	
			yylval.yych=(char *)malloc(strlen(yytext)+1); 			
			strcpy(yylval.yych, yytext);
			return CMP; 
		}
#line 336 "mylexer.cpp"
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 38:
	case 39:
	case 40:
		{
#line 72 ".\\mylexer.l"
return yytext[0]; 
#line 350 "mylexer.cpp"
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

	yytransitionmax = 281;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 34, 17 },
		{ 32, 3 },
		{ 33, 15 },
		{ 0, 0 },
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 64, 46 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 0, 0 },
		{ 36, 20 },
		{ 18, 1 },
		{ 65, 46 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 45, 26 },
		{ 46, 27 },
		{ 24, 1 },
		{ 37, 20 },
		{ 47, 27 },
		{ 35, 18 },
		{ 49, 29 },
		{ 25, 1 },
		{ 26, 1 },
		{ 50, 29 },
		{ 61, 43 },
		{ 62, 43 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 64, 46 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 1 },
		{ 36, 20 },
		{ 18, 1 },
		{ 65, 46 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 45, 26 },
		{ 46, 27 },
		{ 24, 1 },
		{ 37, 20 },
		{ 47, 27 },
		{ 35, 18 },
		{ 49, 29 },
		{ 25, 1 },
		{ 26, 1 },
		{ 50, 29 },
		{ 61, 43 },
		{ 62, 43 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 0, 0 },
		{ 48, 28 },
		{ 41, 22 },
		{ 51, 30 },
		{ 52, 31 },
		{ 0, 0 },
		{ 53, 35 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 48, 28 },
		{ 41, 22 },
		{ 51, 30 },
		{ 52, 31 },
		{ 19, 105 },
		{ 53, 35 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 19, 105 },
		{ 38, 21 },
		{ 54, 36 },
		{ 55, 37 },
		{ 56, 38 },
		{ 39, 21 },
		{ 57, 39 },
		{ 58, 40 },
		{ 59, 41 },
		{ 60, 42 },
		{ 42, 23 },
		{ 63, 44 },
		{ 43, 24 },
		{ 66, 47 },
		{ 67, 48 },
		{ 68, 49 },
		{ 69, 50 },
		{ 70, 51 },
		{ 40, 21 },
		{ 71, 52 },
		{ 72, 54 },
		{ 73, 55 },
		{ 74, 56 },
		{ 75, 57 },
		{ 76, 58 },
		{ 77, 59 },
		{ 78, 60 },
		{ 79, 61 },
		{ 80, 62 },
		{ 81, 64 },
		{ 82, 66 },
		{ 83, 67 },
		{ 84, 68 },
		{ 38, 21 },
		{ 54, 36 },
		{ 55, 37 },
		{ 56, 38 },
		{ 39, 21 },
		{ 57, 39 },
		{ 58, 40 },
		{ 59, 41 },
		{ 60, 42 },
		{ 42, 23 },
		{ 63, 44 },
		{ 43, 24 },
		{ 66, 47 },
		{ 67, 48 },
		{ 68, 49 },
		{ 69, 50 },
		{ 70, 51 },
		{ 40, 21 },
		{ 71, 52 },
		{ 72, 54 },
		{ 73, 55 },
		{ 74, 56 },
		{ 75, 57 },
		{ 76, 58 },
		{ 77, 59 },
		{ 78, 60 },
		{ 79, 61 },
		{ 80, 62 },
		{ 81, 64 },
		{ 82, 66 },
		{ 83, 67 },
		{ 84, 68 },
		{ 85, 70 },
		{ 86, 71 },
		{ 87, 73 },
		{ 88, 74 },
		{ 89, 75 },
		{ 90, 79 },
		{ 91, 81 },
		{ 92, 83 },
		{ 93, 84 },
		{ 94, 85 },
		{ 95, 86 },
		{ 96, 87 },
		{ 97, 88 },
		{ 98, 89 },
		{ 99, 90 },
		{ 100, 91 },
		{ 101, 92 },
		{ 102, 93 },
		{ 103, 94 },
		{ 104, 97 },
		{ 105, 104 },
		{ 44, 25 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 85, 70 },
		{ 86, 71 },
		{ 87, 73 },
		{ 88, 74 },
		{ 89, 75 },
		{ 90, 79 },
		{ 91, 81 },
		{ 92, 83 },
		{ 93, 84 },
		{ 94, 85 },
		{ 95, 86 },
		{ 96, 87 },
		{ 97, 88 },
		{ 98, 89 },
		{ 99, 90 },
		{ 100, 91 },
		{ 101, 92 },
		{ 102, 93 },
		{ 103, 94 },
		{ 104, 97 },
		{ 105, 104 },
		{ 44, 25 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 105, -32, 0 },
		{ 1, 0, 0 },
		{ 0, -58, 0 },
		{ 0, 0, 35 },
		{ 0, 0, 37 },
		{ 0, 0, 38 },
		{ 0, 0, 33 },
		{ 0, 0, 31 },
		{ 0, 0, 40 },
		{ 0, 0, 32 },
		{ 0, 0, 39 },
		{ 0, 0, 34 },
		{ 0, 201, 24 },
		{ 0, 0, 36 },
		{ 0, -57, 27 },
		{ 0, 0, 25 },
		{ 0, -59, 28 },
		{ 105, -34, 23 },
		{ 105, 0, 23 },
		{ 105, -40, 23 },
		{ 105, 98, 23 },
		{ 105, 12, 23 },
		{ 105, 90, 23 },
		{ 105, 96, 23 },
		{ 105, 169, 23 },
		{ 105, -43, 23 },
		{ 105, -29, 23 },
		{ 105, 34, 23 },
		{ 105, -35, 23 },
		{ 105, 36, 23 },
		{ 105, 30, 23 },
		{ 0, 0, 26 },
		{ 0, 0, 30 },
		{ 0, 0, 29 },
		{ 105, 36, 23 },
		{ 105, 99, 23 },
		{ 105, 96, 23 },
		{ 105, 82, 23 },
		{ 105, 92, 23 },
		{ 105, 90, 23 },
		{ 105, 97, 23 },
		{ 105, 92, 23 },
		{ 105, -34, 23 },
		{ 105, 89, 23 },
		{ 105, 0, 22 },
		{ 105, -50, 23 },
		{ 105, 96, 23 },
		{ 105, 110, 23 },
		{ 105, 109, 23 },
		{ 105, 109, 23 },
		{ 105, 103, 23 },
		{ 105, 112, 23 },
		{ 105, 0, 21 },
		{ 105, 100, 23 },
		{ 105, 118, 23 },
		{ 105, 119, 23 },
		{ 105, 116, 23 },
		{ 105, 106, 23 },
		{ 105, 103, 23 },
		{ 105, 111, 23 },
		{ 105, 120, 23 },
		{ 105, 111, 15 },
		{ 105, 0, 1 },
		{ 105, 122, 23 },
		{ 105, 0, 8 },
		{ 105, 105, 23 },
		{ 105, 117, 23 },
		{ 105, 129, 23 },
		{ 105, 0, 11 },
		{ 105, 142, 23 },
		{ 105, 146, 23 },
		{ 105, 0, 14 },
		{ 105, 145, 23 },
		{ 105, 164, 23 },
		{ 105, 147, 23 },
		{ 105, 0, 4 },
		{ 105, 0, 2 },
		{ 105, 0, 6 },
		{ 105, 150, 23 },
		{ 105, 0, 19 },
		{ 105, 166, 23 },
		{ 105, 0, 10 },
		{ 105, 165, 23 },
		{ 105, 151, 23 },
		{ 105, 167, 23 },
		{ 105, 168, 23 },
		{ 105, 169, 23 },
		{ 105, 174, 23 },
		{ 105, 171, 23 },
		{ 105, 157, 23 },
		{ 105, 158, 23 },
		{ 105, 160, 13 },
		{ 105, 175, 23 },
		{ 105, 162, 23 },
		{ 105, 0, 17 },
		{ 105, 0, 9 },
		{ 105, 163, 23 },
		{ 105, 0, 5 },
		{ 105, 0, 18 },
		{ 105, 0, 16 },
		{ 105, 0, 3 },
		{ 105, 0, 7 },
		{ 105, 0, 20 },
		{ 105, 178, 23 },
		{ 0, 40, 12 }
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
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
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
#line 74 ".\\mylexer.l"




