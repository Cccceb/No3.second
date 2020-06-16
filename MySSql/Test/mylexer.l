%{
//this code will be added into the header of generated .cpp file
#include <iostream>
#include "myparser.h"
#pragma warning(disable:4996)
using namespace std;
%}

%name mylexer

%%
%{
//this code will be added into yyaction function
    YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
    //double yylval;
%}
NOT {return NOT;}
EXIT {return EXIT;}
TABLES {return TABLES;}
DROP {return DROP;}
DELETE {return DELETE;}
FROM {return FROM;}
UPDATE {return UPDATE;}
SET {return SET;}
CREATE	{return CREATE;}
SHOW {return SHOW;}
USE {return USE;}
DATABASE {return DATABASE;}
TABLE	{return TABLE;}
CHAR	{return CHAR;}
INT		{return INT;}
SELECT	{return SELECT;}
WHERE	{return WHERE;}
INSERT	{return INSERT;}
INTO	{return INTO;}
VALUES	{return VALUES;}
AND	{return AND;}
OR	{return OR;}
[A-Za-z][A-Za-z0-9_]*   
					{	
					yylval.yych=(char *)malloc(strlen(yytext)+1); 			
					strcpy(yylval.yych, yytext);
				//	cout << yylval.yych<<endl;
					return ID;
					}

[0-9]+ {
		yylval.yych=(char *)malloc(strlen(yytext)+1); 			
		strcpy(yylval.yych, yytext);
		return NUMBER; 
		}	
"="		|
"!="	|
"<"		|
">"		|
">="	|
"<="	|
		{	
			yylval.yych=(char *)malloc(strlen(yytext)+1); 			
			strcpy(yylval.yych, yytext);
			return CMP; 
		}
"+"		|
"-"		|
"*"		|
"/"	|
"'"		|		
";"		|
"("		|
")"		|
"."		|
","		{return yytext[0]; }

%%


