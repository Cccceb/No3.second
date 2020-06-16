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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 06/15/20
* Time: 12:23:55
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#ifndef YYSTYPE
union tagYYSTYPE {
#line 105 ".\\myparser.y"
	

	char *yych;				//字面量
	int *yynm;			//数组
	struct Createfieldsdef	*cfdef_var;	//字段定义
	struct Createstruct	*cs_var;	//整个create语句锞?
	/*属于select语法树的类型*/
	struct Selectedfields	*sf_var;	//所选字段
	struct Selectedtables *st_var;	//所选表格
	struct Conditions	*cons_var;	//条件语句
	struct Selectstruct	*ss_var;	//整个select语句
	struct Insertstruct *is_var;
	struct Insertfields *if_var;
	struct Insertvalues *iv_var;
	struct Updatefields *uf_var;
	struct Updatestruct *us_var;
	struct Deletestruct *ds_var;

#line 92 "myparser.h"
};

#define YYSTYPE union tagYYSTYPE
#endif

#define CREATE 257
#define TABLE 258
#define ID 259
#define CHAR 260
#define NUMBER 261
#define INT 262
#define SELECT 263
#define WHERE 264
#define FROM 265
#define SHOW 266
#define DATABASE 267
#define USE 268
#define CMP 269
#define INSERT 270
#define INTO 271
#define VALUES 272
#define UPDATE 273
#define SET 274
#define DELETE 275
#define DROP 276
#define EXIT 277
#define TABLES 278
#define NOT 279
#define OR 280
#define AND 281
#endif
