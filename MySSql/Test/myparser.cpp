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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 06/15/20
* Time: 12:23:55
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2012年4月5日
****************************************************************************/
#include "mylexer.h"
#include<yycpars.h>
#include<bits/stdc++.h>
#include<direct.h> 
#include <ctype.h>
#include <stdlib.h>
#pragma warning(disable:4996)
using namespace std;
struct cons {
	string field;
	char cmp;
	string value;
	int type;
	cons(char* field, char cmp, char * value,int type) :field(field), cmp(cmp), value(value),type(type) {};
};
stringstream ss;string exprs;
map<string,vector<vector<cons>>> myConditions;
enum TYPE {INT1,CHAR1};		//字段可用类型
struct	Createfieldsdef{		/*create语句中的字段定义*/
	char *field;		//字段名称
	enum TYPE	type;		//字段类型
	int			length;		//字段长度
	struct  Createfieldsdef   *next_fdef;	//下一字段
};
struct	Createstruct{			/*create语法树根节点*/
	char	*table;				//基本表名称
	struct Createfieldsdef	*fdef;	//字段定义
};


struct	Conditions{/*条件*/
	struct  Conditions	*left;		//左部条件
	struct  Conditions	*right;		//右部条件
	char	 comp_op;	/* 'a'是and, 'o'是or, '<' , '>' , '=', ‘!='  */
	int	 type;	/* 0是字段，1是字符串，2是整数 */
	char	 *value;/* 根据type存放字段名、字符串或整数 */	
	char	 *table;	/* NULL或表名 */	
};
struct	Selectedfields{/*select语句中选中的字段*/
	char 	*table;			//字段所属表
	char 	*field;			//字段名称
	struct 	Selectedfields	*next_sf;//下一个字段
};
struct	Selectedtables{	/*select语句中选中的表*/
	char	  *table;		//基本表名称
	struct  Selectedtables  *next_st;	//下一个表
};
struct	Selectstruct{		/*select语法树的根节点*/
	struct Selectedfields 	*sf;	//所选字段
	struct Selectedtables	*st;	//所选基本表
	struct Conditions		*cons;	//条件
};
struct Insertfields{
	char *field;
	struct Insertfields *next_if;
};
struct Insertvalues{
	char *val;
	struct Insertvalues *next_iv;
};
struct Insertstruct{
	char *table;
	struct Insertfields *tf;
	struct Insertvalues *tv;
};
struct Updatefields{
	char *field;
	char *vals;
	struct Updatefields *next_uf;
};
struct Updatestruct{
	char *table;
	struct Updatefields *uf;
	struct Conditions *cons;
};
struct Deletestruct{
	char *table;
	struct Conditions *cons;
};
int updatesql(Updatestruct* sql);
int createTable(Createstruct* createsql);
void showDatabase();
int createDatabase(char *database);
int useDatabase(char *basePath);
int selectSql(Selectstruct* sql);
int insertSql(Insertstruct* sql);
int deleteSql(Deletestruct * sql);
int dropTable(char * name);
bool judge(map<string,int>idx,vector<string> data,string table);
std::string base = "";
std::vector<std::string> splitString(const std::string& s);
vector<cons> genCondations(Conditions *condition,bool flag,bool turn);
int dropDatabase(char* name);
int showTables();

#line 141 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 147 ".\\myparser.y"

				int result = showTables();
				if(result == 0){
					cout <<"Please Select A Database!"<<endl;
				}
			
#line 284 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 154 ".\\myparser.y"
	
				exit(0);
			
#line 299 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 158 ".\\myparser.y"

				int result = dropDatabase(yyattribute(3 - 4).yych);
				if(result == 0){cout <<" Optional Failed!"<<endl;}
				else{cout <<" Optional Successfully!"<<endl;}
			
#line 316 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 164 ".\\myparser.y"

				int result = dropTable(yyattribute(3 - 4).yych);
				if(result == -1){cout <<" Optional Failed!";}
				else{cout <<" Optional Successfully!";}
			
#line 333 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 170 ".\\myparser.y"

				int result = deleteSql(yyattribute(1 - 1).ds_var);
				if(result == -1){cout <<" Optional Failed!";}
				else{
					cout <<"Number of rows affected"<<result<<endl;
				}
				
			
#line 353 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 179 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).ds_var = (Deletestruct *)malloc(sizeof(Deletestruct));
				(*(YYSTYPE YYFAR*)yyvalptr).ds_var->table = yyattribute(3 - 6).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).ds_var->cons = yyattribute(5 - 6).cons_var;
			
#line 370 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 185 ".\\myparser.y"

				int result = updatesql(yyattribute(1 - 1).us_var);
				if(result == -1){cout <<" Optional Failed!";}
				else{
					cout <<"Number of rows affected"<<result<<endl;
				}
				
			
#line 390 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 194 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).us_var = (Updatestruct *)malloc(sizeof(Updatestruct));
				(*(YYSTYPE YYFAR*)yyvalptr).us_var->table = yyattribute(2 - 7).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).us_var->uf = yyattribute(4 - 7).uf_var;
				(*(YYSTYPE YYFAR*)yyvalptr).us_var->cons = yyattribute(6 - 7).cons_var;
			
#line 408 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 201 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).uf_var = (Updatefields *)malloc(sizeof(Updatefields));
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->field = yyattribute(1 - 1).uf_var->field;
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->vals = yyattribute(1 - 1).uf_var->vals;
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->next_uf = NULL;
			
#line 426 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 208 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).uf_var = (Updatefields *)malloc(sizeof(Updatefields));
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->field = yyattribute(3 - 3).uf_var->field;
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->vals = yyattribute(3 - 3).uf_var->vals;
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->next_uf = yyattribute(1 - 3).uf_var;
			
#line 444 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 216 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).uf_var = (Updatefields *)malloc(sizeof(Updatefields));
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->field = yyattribute(1 - 5).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->vals = yyattribute(4 - 5).yych;
			
#line 461 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 222 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).uf_var = (Updatefields *)malloc(sizeof(Updatefields));
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->field = yyattribute(1 - 3).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).uf_var->vals = yyattribute(3 - 3).yych;
			
#line 478 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 228 ".\\myparser.y"

	showDatabase();

#line 493 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 232 ".\\myparser.y"

	int result = createDatabase(yyattribute(3 - 4).yych);
	if(result == 1){cout << "Create Successfully!"<<endl;}
	else{cout << "The database already exists"<<endl;}

#line 510 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 238 ".\\myparser.y"

	int result = useDatabase(yyattribute(2 - 3).yych);
	if(result != 1){cout <<"The database doesn't exist" <<endl; }

#line 526 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 244 ".\\myparser.y"
	int result;
	result=createTable(yyattribute(1 - 1).cs_var);
	if(result==1){
		printf("Create Table %s Successful!\n",yyattribute(1 - 1).cs_var->table);
	}else
	{	
		printf("Create Table %s Failed!\n",yyattribute(1 - 1).cs_var->table);
	}

#line 547 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 254 ".\\myparser.y"

	(*(YYSTYPE YYFAR*)yyvalptr).cs_var=(struct Createstruct *)malloc(sizeof(struct Createstruct));
	(*(YYSTYPE YYFAR*)yyvalptr).cs_var->table=yyattribute(3 - 7).yych;
	(*(YYSTYPE YYFAR*)yyvalptr).cs_var->fdef=yyattribute(5 - 7).cfdef_var;

#line 564 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 261 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->field = yyattribute(1 - 1).cfdef_var->field;
					
					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->type = yyattribute(1 - 1).cfdef_var->type;
					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->length = yyattribute(1 - 1).cfdef_var->length;
					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->next_fdef = NULL;
					
#line 584 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 269 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->field = yyattribute(3 - 3).cfdef_var->field;
					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->type = yyattribute(3 - 3).cfdef_var->type;
					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->length = yyattribute(3 - 3).cfdef_var->length;
					(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->next_fdef = yyattribute(1 - 3).cfdef_var;
				 
#line 603 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 276 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
			(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->field = yyattribute(1 - 2).yych;
		//	cout <<$2[0] <<" "<<$2[1]<<endl;
			if(yyattribute(2 - 2).yynm[0]==1){
				(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->type = CHAR1;
			}else{
				(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->type= INT1;
			}
			(*(YYSTYPE YYFAR*)yyvalptr).cfdef_var->length = yyattribute(2 - 2).yynm[1];
			
#line 626 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 288 ".\\myparser.y"

	int * s = (int *)malloc(2*sizeof(int));
	s[0] = 1;
	s[1] = atof(yyattribute(3 - 4).yych);
//	cout <<"0"<<$3.yych<<endl;
	(*(YYSTYPE YYFAR*)yyvalptr).yynm = s;
	
#line 645 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 295 ".\\myparser.y"

		int * s = (int *)malloc(2*sizeof(int));
		s[0] = 0;
		s[1] = 4;
//		cout <<"1"<<"4"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).yynm = s;
	
#line 664 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 302 ".\\myparser.y"

			int result = selectSql(yyattribute(1 - 1).ss_var);
			if(result ==0){cout << "Please Select A Database!"<<endl;}
			else if(result == -1){cout <<"There are no selection fields"<<endl;}
			else if(result == -2){cout <<"There are no selection tables"<<endl;}

#line 682 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 309 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).ss_var = (Selectstruct *)malloc(sizeof(Selectstruct));
				(*(YYSTYPE YYFAR*)yyvalptr).ss_var->sf = yyattribute(2 - 5).sf_var;
				(*(YYSTYPE YYFAR*)yyvalptr).ss_var->st = yyattribute(4 - 5).st_var;
				(*(YYSTYPE YYFAR*)yyvalptr).ss_var->cons = NULL;
			
				
			
#line 702 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 318 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).ss_var = (Selectstruct *)malloc(sizeof(Selectstruct));
				(*(YYSTYPE YYFAR*)yyvalptr).ss_var->sf = yyattribute(2 - 7).sf_var;
				(*(YYSTYPE YYFAR*)yyvalptr).ss_var->st = yyattribute(4 - 7).st_var;
				(*(YYSTYPE YYFAR*)yyvalptr).ss_var->cons = yyattribute(6 - 7).cons_var;
		   
#line 720 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 325 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).sf_var = (Selectedfields *)malloc(sizeof(Selectedfields));
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->table = yyattribute(1 - 1).sf_var->table;
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->field = yyattribute(1 - 1).sf_var->field;
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->next_sf = yyattribute(1 - 1).sf_var->next_sf;
			
#line 738 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 331 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).sf_var = (Selectedfields *)malloc(sizeof(Selectedfields));
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->table = (char *)"all";
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->field = (char *)"all";
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->next_sf = NULL;
				
			
#line 757 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 339 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).sf_var = (Selectedfields *)malloc(sizeof(Selectedfields));
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->table = yyattribute(1 - 1).sf_var->table;
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->field = yyattribute(1 - 1).sf_var->field;
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->next_sf = NULL;
			
#line 775 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 346 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).sf_var = (Selectedfields *)malloc(sizeof(Selectedfields));
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->table = yyattribute(3 - 3).sf_var->table;
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->field = yyattribute(3 - 3).sf_var->field;
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->next_sf = yyattribute(1 - 3).sf_var;
			 
#line 793 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 353 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).sf_var = (Selectedfields *)malloc(sizeof(Selectedfields));
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->table = (char *)"all";
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->field = yyattribute(1 - 1).yych;
			
#line 810 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 359 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).sf_var = (Selectedfields *)malloc(sizeof(Selectedfields));
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->table = yyattribute(1 - 3).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).sf_var->field = yyattribute(3 - 3).yych;		
			
#line 827 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 365 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).st_var = (Selectedtables *)malloc(sizeof(Selectedtables));
			(*(YYSTYPE YYFAR*)yyvalptr).st_var->table = yyattribute(3 - 3).yych;
			(*(YYSTYPE YYFAR*)yyvalptr).st_var->next_st = yyattribute(1 - 3).st_var;
		
#line 844 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 371 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).st_var = (Selectedtables *)malloc(sizeof(Selectedtables));
			(*(YYSTYPE YYFAR*)yyvalptr).st_var->table = yyattribute(1 - 1).yych;
			(*(YYSTYPE YYFAR*)yyvalptr).st_var->next_st = NULL;
		
#line 861 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 377 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = yyattribute(1 - 1).cons_var;
			
#line 876 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 382 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = yyattribute(1 - 3).cons_var;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = yyattribute(3 - 3).cons_var;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = 'a';
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = (char *)"all";
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = NULL;
		   
#line 896 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 391 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = yyattribute(1 - 3).cons_var;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = yyattribute(3 - 3).cons_var;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = 'o';
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = (char *)"all";
				//$$->value = (char *)"YES";
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = NULL;
		   
#line 917 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 401 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = yyattribute(2 - 3).cons_var;
		   
#line 932 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 405 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = yyattribute(3 - 4).cons_var;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value =(char *)"NOT";
				/*	
				Conditions* head = $$->right;
				while(head){
					if(head->value!=NULL && strcmp("YES",head->value)==0){
						head->value = NULL;
					}
					head = head->right;
				}
				head = $$->left;
				while(head){
					if(head->value!=NULL && strcmp("YES",head->value)==0){
						head->value = NULL;
					}
					head = head->left;
				}*/
		   
#line 963 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 426 ".\\myparser.y"

			
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = yyattribute(2 - 3).cons_var->comp_op;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = yyattribute(1 - 3).cons_var;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = yyattribute(3 - 3).cons_var;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = (char *)"all";
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = yyattribute(2 - 3).cons_var->value;
			
#line 984 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 437 ".\\myparser.y"

		
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->type = -1;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = (*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = NULL;	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = yyattribute(1 - 1).yych[0];
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = (char *)"all";
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = NULL;
			
#line 1005 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 447 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->type = 0;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = yyattribute(3 - 3).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = (*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = NULL;	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = '-';
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = yyattribute(1 - 3).yych;
			
#line 1025 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 456 ".\\myparser.y"

		
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->type = 0;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = yyattribute(1 - 1).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = (*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = NULL;	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = '-';
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = (char *)"all";
			
#line 1046 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 466 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->type = 2;	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = yyattribute(1 - 1).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = (*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = NULL;		
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = '-';	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = (char *)"all";
			//	cout << $1.yych << endl;
			
#line 1067 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 476 ".\\myparser.y"

			
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->type = 2;	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = yyattribute(2 - 3).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = (*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = NULL;		
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = '-';	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = (char *)"all";
			
#line 1088 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 486 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).cons_var = (Conditions *)malloc(sizeof(Conditions));
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->type = 1;	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->value = yyattribute(2 - 3).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->left = (*(YYSTYPE YYFAR*)yyvalptr).cons_var->right = NULL;	
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->comp_op = '-';
				(*(YYSTYPE YYFAR*)yyvalptr).cons_var->table = (char *)"all";
			
#line 1108 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 494 ".\\myparser.y"
 ss.clear();ss << atoi(yyattribute(1 - 3).yych) + atoi(yyattribute(3 - 3).yych) ;ss>>exprs; (*(YYSTYPE YYFAR*)yyvalptr).yych = (char *)exprs.c_str();  
#line 1121 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 495 ".\\myparser.y"
 ss.clear();ss << atoi(yyattribute(1 - 3).yych) - atoi(yyattribute(3 - 3).yych) ;ss>>exprs; (*(YYSTYPE YYFAR*)yyvalptr).yych = (char *)exprs.c_str();  
#line 1134 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 496 ".\\myparser.y"
 ss.clear();ss << atoi(yyattribute(1 - 3).yych) * atoi(yyattribute(3 - 3).yych) ;ss>>exprs; (*(YYSTYPE YYFAR*)yyvalptr).yych = (char *)exprs.c_str();  
#line 1147 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 497 ".\\myparser.y"
 ss.clear();ss << atoi(yyattribute(1 - 3).yych) / atoi(yyattribute(3 - 3).yych) ;ss>>exprs; (*(YYSTYPE YYFAR*)yyvalptr).yych = (char *)exprs.c_str();  
#line 1160 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 498 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3); 
#line 1173 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 499 ".\\myparser.y"
ss.clear(); { ss << -1 * atoi(yyattribute(2 - 2).yych);ss>>exprs; (*(YYSTYPE YYFAR*)yyvalptr).yych = (char *)exprs.c_str();  }
#line 1186 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 500 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1199 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 503 ".\\myparser.y"

			int result = insertSql(yyattribute(1 - 1).is_var);
			if(result == 0){cout <<"Operation Failed"<<endl;}
			else{cout <<"Operation Successful"<<endl;}

		
#line 1217 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[12];
			yyinitdebug((void YYFAR**)yya, 12);
#endif
			{
#line 510 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).is_var = (Insertstruct *)malloc(sizeof(Insertstruct));
				(*(YYSTYPE YYFAR*)yyvalptr).is_var->table = yyattribute(3 - 11).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).is_var->tf = yyattribute(5 - 11).if_var;
				(*(YYSTYPE YYFAR*)yyvalptr).is_var->tv = yyattribute(9 - 11).iv_var;
			
#line 1235 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 517 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr).is_var = (Insertstruct *)malloc(sizeof(Insertstruct));
				(*(YYSTYPE YYFAR*)yyvalptr).is_var->table = yyattribute(3 - 8).yych;
				(*(YYSTYPE YYFAR*)yyvalptr).is_var->tf = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr).is_var->tv = yyattribute(6 - 8).iv_var;
			
#line 1253 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 524 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr).if_var =  (Insertfields *)malloc(sizeof(Insertfields));
					(*(YYSTYPE YYFAR*)yyvalptr).if_var->field = yyattribute(3 - 3).yych;
					(*(YYSTYPE YYFAR*)yyvalptr).if_var->next_if = yyattribute(1 - 3).if_var;
				
#line 1270 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 529 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr).if_var =  (Insertfields *)malloc(sizeof(Insertfields));
					(*(YYSTYPE YYFAR*)yyvalptr).if_var->field = yyattribute(1 - 1).yych;
					(*(YYSTYPE YYFAR*)yyvalptr).if_var->next_if = NULL;
				
#line 1287 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 535 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).iv_var = (Insertvalues *)malloc(sizeof(Insertvalues));
		(*(YYSTYPE YYFAR*)yyvalptr).iv_var->val = yyattribute(1 - 1).yych;
		(*(YYSTYPE YYFAR*)yyvalptr).iv_var->next_iv = NULL;
	
#line 1304 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 541 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).iv_var = (Insertvalues *)malloc(sizeof(Insertvalues));
		(*(YYSTYPE YYFAR*)yyvalptr).iv_var->val = yyattribute(3 - 3).yych;
		(*(YYSTYPE YYFAR*)yyvalptr).iv_var->next_iv = yyattribute(1 - 3).iv_var;
	 
#line 1321 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 547 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).yych = yyattribute(2 - 3).yych;
	
#line 1336 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 551 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).yych = yyattribute(2 - 3).yych;
	
#line 1351 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "\'\\\'\'", 39 },
		{ "\'(\'", 40 },
		{ "\')\'", 41 },
		{ "\'*\'", 42 },
		{ "\'+\'", 43 },
		{ "\',\'", 44 },
		{ "\'-\'", 45 },
		{ "\'.\'", 46 },
		{ "\'/\'", 47 },
		{ "\';\'", 59 },
		{ "error", 256 },
		{ "CREATE", 257 },
		{ "TABLE", 258 },
		{ "ID", 259 },
		{ "CHAR", 260 },
		{ "NUMBER", 261 },
		{ "INT", 262 },
		{ "SELECT", 263 },
		{ "WHERE", 264 },
		{ "FROM", 265 },
		{ "SHOW", 266 },
		{ "DATABASE", 267 },
		{ "USE", 268 },
		{ "CMP", 269 },
		{ "INSERT", 270 },
		{ "INTO", 271 },
		{ "VALUES", 272 },
		{ "UPDATE", 273 },
		{ "SET", 274 },
		{ "DELETE", 275 },
		{ "DROP", 276 },
		{ "EXIT", 277 },
		{ "TABLES", 278 },
		{ "NOT", 279 },
		{ "OR", 280 },
		{ "AND", 281 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: statements",
		"statements: statements statement",
		"statements: statement",
		"statement: SHOW TABLES \';\'",
		"statement: EXIT",
		"statement: DROP DATABASE database \';\'",
		"statement: DROP TABLE table \';\'",
		"statement: deletesql",
		"deletesql: DELETE FROM table WHERE conditions \';\'",
		"statement: updatesql",
		"updatesql: UPDATE table SET updatefields WHERE conditions \';\'",
		"updatefields: updatefield",
		"updatefields: updatefields \',\' updatefield",
		"updatefield: ID CMP \'\\\'\' ID \'\\\'\'",
		"updatefield: ID CMP NUMBER",
		"statement: showdatabase",
		"showdatabase: SHOW DATABASE \';\'",
		"statement: createdatabase",
		"createdatabase: CREATE DATABASE database \';\'",
		"statement: usedatabase",
		"usedatabase: USE database \';\'",
		"database: ID",
		"statement: createsql",
		"createsql: CREATE TABLE table \'(\' fieldsdefinition \')\' \';\'",
		"table: ID",
		"fieldsdefinition: field_type",
		"fieldsdefinition: fieldsdefinition \',\' field_type",
		"field_type: field type",
		"field: ID",
		"type: CHAR \'(\' NUMBER \')\'",
		"type: INT",
		"statement: selectsql",
		"selectsql: SELECT fields_star FROM tables \';\'",
		"selectsql: SELECT fields_star FROM tables WHERE conditions \';\'",
		"fields_star: table_fields",
		"fields_star: \'*\'",
		"table_fields: table_field",
		"table_fields: table_fields \',\' table_field",
		"table_field: field",
		"table_field: table \'.\' field",
		"tables: tables \',\' table",
		"tables: table",
		"conditions: condition",
		"conditions: conditions AND conditions",
		"conditions: conditions OR conditions",
		"conditions: \'(\' conditions \')\'",
		"conditions: NOT \'(\' conditions \')\'",
		"condition: condition condition condition",
		"condition: CMP",
		"condition: table \'.\' field",
		"condition: field",
		"condition: expr",
		"condition: \'\\\'\' NUMBER \'\\\'\'",
		"condition: \'\\\'\' ID \'\\\'\'",
		"expr: expr \'+\' expr",
		"expr: expr \'-\' expr",
		"expr: expr \'*\' expr",
		"expr: expr \'/\' expr",
		"expr: \'(\' expr \')\'",
		"expr: \'-\' expr",
		"expr: NUMBER",
		"statement: insertsql",
		"insertsql: INSERT INTO table \'(\' insert_fields \')\' VALUES \'(\' vals \')\' \';\'",
		"insertsql: INSERT INTO table VALUES \'(\' vals \')\' \';\'",
		"insert_fields: insert_fields \',\' field",
		"insert_fields: field",
		"vals: val",
		"vals: vals \',\' val",
		"val: \'\\\'\' ID \'\\\'\'",
		"val: \'\\\'\' NUMBER \'\\\'\'",
		"val: NUMBER"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 2, -1 },
		{ 1, 1, -1 },
		{ 2, 3, 0 },
		{ 2, 1, 1 },
		{ 2, 4, 2 },
		{ 2, 4, 3 },
		{ 2, 1, 4 },
		{ 3, 6, 5 },
		{ 2, 1, 6 },
		{ 4, 7, 7 },
		{ 5, 1, 8 },
		{ 5, 3, 9 },
		{ 6, 5, 10 },
		{ 6, 3, 11 },
		{ 2, 1, -1 },
		{ 7, 3, 12 },
		{ 2, 1, -1 },
		{ 8, 4, 13 },
		{ 2, 1, -1 },
		{ 9, 3, 14 },
		{ 10, 1, -1 },
		{ 2, 1, 15 },
		{ 11, 7, 16 },
		{ 12, 1, -1 },
		{ 13, 1, 17 },
		{ 13, 3, 18 },
		{ 14, 2, 19 },
		{ 15, 1, -1 },
		{ 16, 4, 20 },
		{ 16, 1, 21 },
		{ 2, 1, 22 },
		{ 17, 5, 23 },
		{ 17, 7, 24 },
		{ 18, 1, 25 },
		{ 18, 1, 26 },
		{ 19, 1, 27 },
		{ 19, 3, 28 },
		{ 20, 1, 29 },
		{ 20, 3, 30 },
		{ 21, 3, 31 },
		{ 21, 1, 32 },
		{ 22, 1, 33 },
		{ 22, 3, 34 },
		{ 22, 3, 35 },
		{ 22, 3, 36 },
		{ 22, 4, 37 },
		{ 23, 3, 38 },
		{ 23, 1, 39 },
		{ 23, 3, 40 },
		{ 23, 1, 41 },
		{ 23, 1, 42 },
		{ 23, 3, 43 },
		{ 23, 3, 44 },
		{ 24, 3, 45 },
		{ 24, 3, 46 },
		{ 24, 3, 47 },
		{ 24, 3, 48 },
		{ 24, 3, 49 },
		{ 24, 2, 50 },
		{ 24, 1, 51 },
		{ 2, 1, 52 },
		{ 25, 11, 53 },
		{ 25, 8, 54 },
		{ 26, 3, 55 },
		{ 26, 1, 56 },
		{ 27, 1, 57 },
		{ 27, 3, 58 },
		{ 28, 3, 59 },
		{ 28, 3, 60 },
		{ 28, 1, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 278;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 16, YYAT_ACCEPT, 0 },
		{ 145, YYAT_SHIFT, 80 },
		{ 145, YYAT_SHIFT, 112 },
		{ 141, YYAT_SHIFT, 157 },
		{ 89, YYAT_SHIFT, 80 },
		{ 89, YYAT_SHIFT, 112 },
		{ 118, YYAT_SHIFT, 81 },
		{ 145, YYAT_SHIFT, 82 },
		{ 119, YYAT_SHIFT, 80 },
		{ 48, YYAT_SHIFT, 60 },
		{ 89, YYAT_SHIFT, 82 },
		{ 123, YYAT_SHIFT, 112 },
		{ 107, YYAT_ERROR, 0 },
		{ 58, YYAT_SHIFT, 71 },
		{ 151, YYAT_SHIFT, 100 },
		{ 77, YYAT_SHIFT, 104 },
		{ 123, YYAT_SHIFT, 82 },
		{ 160, YYAT_SHIFT, 161 },
		{ 3, YYAT_SHIFT, 29 },
		{ 64, YYAT_SHIFT, 78 },
		{ 140, YYAT_SHIFT, 139 },
		{ 140, YYAT_SHIFT, 120 },
		{ 140, YYAT_SHIFT, 121 },
		{ 150, YYAT_SHIFT, 158 },
		{ 140, YYAT_SHIFT, 122 },
		{ 8, YYAT_SHIFT, 37 },
		{ 140, YYAT_SHIFT, 123 },
		{ 1, YYAT_SHIFT, 20 },
		{ 58, YYAT_SHIFT, 72 },
		{ 3, YYAT_SHIFT, 30 },
		{ 107, YYAT_SHIFT, 135 },
		{ 111, YYAT_SHIFT, 139 },
		{ 111, YYAT_SHIFT, 120 },
		{ 111, YYAT_SHIFT, 121 },
		{ 8, YYAT_SHIFT, 38 },
		{ 111, YYAT_SHIFT, 122 },
		{ 1, YYAT_SHIFT, 21 },
		{ 111, YYAT_SHIFT, 123 },
		{ 90, YYAT_SHIFT, 120 },
		{ 90, YYAT_SHIFT, 121 },
		{ 148, YYAT_SHIFT, 120 },
		{ 90, YYAT_SHIFT, 122 },
		{ 147, YYAT_SHIFT, 120 },
		{ 90, YYAT_SHIFT, 123 },
		{ 113, YYAT_SHIFT, 120 },
		{ 148, YYAT_SHIFT, 123 },
		{ 143, YYAT_SHIFT, 118 },
		{ 147, YYAT_SHIFT, 123 },
		{ 159, YYAT_SHIFT, 160 },
		{ 113, YYAT_SHIFT, 123 },
		{ 75, YYAT_SHIFT, 98 },
		{ 159, YYAT_SHIFT, 133 },
		{ 70, YYAT_SHIFT, 94 },
		{ 75, YYAT_SHIFT, 99 },
		{ 100, YYAT_SHIFT, 130 },
		{ 70, YYAT_SHIFT, 95 },
		{ 100, YYAT_SHIFT, 131 },
		{ 80, YYAT_SHIFT, 108 },
		{ 69, YYAT_SHIFT, 91 },
		{ 80, YYAT_SHIFT, 109 },
		{ 69, YYAT_SHIFT, 92 },
		{ 134, YYAT_SHIFT, 156 },
		{ 132, YYAT_SHIFT, 154 },
		{ 131, YYAT_SHIFT, 153 },
		{ 130, YYAT_SHIFT, 152 },
		{ 128, YYAT_SHIFT, 151 },
		{ 124, YYAT_SHIFT, 150 },
		{ 115, YYAT_SHIFT, 55 },
		{ 110, YYAT_SHIFT, 138 },
		{ 109, YYAT_SHIFT, 137 },
		{ 108, YYAT_SHIFT, 136 },
		{ 104, YYAT_SHIFT, 134 },
		{ 103, YYAT_SHIFT, 132 },
		{ 98, YYAT_SHIFT, 128 },
		{ 97, YYAT_SHIFT, 127 },
		{ 94, YYAT_SHIFT, 125 },
		{ 91, YYAT_SHIFT, 124 },
		{ 88, YYAT_SHIFT, 116 },
		{ 86, YYAT_SHIFT, 115 },
		{ 85, YYAT_SHIFT, 114 },
		{ 78, YYAT_SHIFT, 62 },
		{ 71, YYAT_SHIFT, 34 },
		{ 62, YYAT_SHIFT, 77 },
		{ 61, YYAT_SHIFT, 76 },
		{ 52, YYAT_SHIFT, 67 },
		{ 51, YYAT_SHIFT, 66 },
		{ 50, YYAT_SHIFT, 65 },
		{ 44, YYAT_SHIFT, 23 },
		{ 41, YYAT_SHIFT, 54 },
		{ 40, YYAT_SHIFT, 53 },
		{ 38, YYAT_SHIFT, 31 },
		{ 35, YYAT_SHIFT, 49 },
		{ 32, YYAT_SHIFT, 47 },
		{ 30, YYAT_SHIFT, 46 },
		{ 29, YYAT_SHIFT, 45 },
		{ 26, YYAT_SHIFT, 44 },
		{ 25, YYAT_SHIFT, 43 },
		{ 24, YYAT_SHIFT, 42 },
		{ 23, YYAT_REDUCE, 24 },
		{ 7, YYAT_SHIFT, 36 },
		{ 5, YYAT_SHIFT, 33 },
		{ 2, YYAT_SHIFT, 22 },
		{ 0, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 145, YYAT_SHIFT, 23 },
		{ -1, YYAT_ERROR, 0 },
		{ 145, YYAT_SHIFT, 83 },
		{ 89, YYAT_SHIFT, 23 },
		{ -1, YYAT_ERROR, 0 },
		{ 89, YYAT_SHIFT, 83 },
		{ -1, YYAT_ERROR, 0 },
		{ 119, YYAT_SHIFT, 23 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 145, YYAT_SHIFT, 84 },
		{ 123, YYAT_SHIFT, 83 },
		{ 58, YYAT_SHIFT, 73 },
		{ 89, YYAT_SHIFT, 84 },
		{ -1, YYAT_ERROR, 0 },
		{ 151, YYAT_SHIFT, 101 },
		{ 77, YYAT_SHIFT, 105 },
		{ 119, YYAT_SHIFT, 84 },
		{ 64, YYAT_SHIFT, 79 },
		{ -1, YYAT_ERROR, 0 },
		{ 48, YYAT_SHIFT, 61 },
		{ 141, YYAT_SHIFT, 117 },
		{ 141, YYAT_SHIFT, 118 },
		{ -1, YYAT_ERROR, 0 },
		{ 118, YYAT_SHIFT, 85 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 16, YYAT_SHIFT, 1 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 16, YYAT_SHIFT, 2 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 16, YYAT_SHIFT, 3 },
		{ -1, YYAT_ERROR, 0 },
		{ 16, YYAT_SHIFT, 4 },
		{ -1, YYAT_ERROR, 0 },
		{ 16, YYAT_SHIFT, 5 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 16, YYAT_SHIFT, 6 },
		{ -1, YYAT_ERROR, 0 },
		{ 16, YYAT_SHIFT, 7 },
		{ 16, YYAT_SHIFT, 8 },
		{ 16, YYAT_SHIFT, 9 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 102, 1, YYAT_DEFAULT, 16 },
		{ -231, 1, YYAT_ERROR, 0 },
		{ 59, 1, YYAT_DEFAULT, 44 },
		{ -249, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 38 },
		{ -171, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 71 },
		{ -166, 1, YYAT_ERROR, 0 },
		{ -233, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_DEFAULT, 71 },
		{ 0, 0, YYAT_DEFAULT, 38 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 52, 1, YYAT_REDUCE, 28 },
		{ 51, 1, YYAT_ERROR, 0 },
		{ -169, 1, YYAT_ERROR, 0 },
		{ 51, 1, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 35, 1, YYAT_ERROR, 0 },
		{ 34, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 33, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 71 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ -183, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 71 },
		{ 0, 0, YYAT_DEFAULT, 71 },
		{ -169, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 49, 1, YYAT_ERROR, 0 },
		{ 29, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 115 },
		{ 0, 0, YYAT_DEFAULT, 71 },
		{ -172, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ -31, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 78 },
		{ -178, 1, YYAT_ERROR, 0 },
		{ 26, 1, YYAT_ERROR, 0 },
		{ 25, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 115 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 41 },
		{ -31, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_DEFAULT, 115 },
		{ 43, 1, YYAT_ERROR, 0 },
		{ -187, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -25, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ -202, 1, YYAT_ERROR, 0 },
		{ 11, 1, YYAT_ERROR, 0 },
		{ -178, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 9, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 151 },
		{ -24, 1, YYAT_ERROR, 0 },
		{ -179, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ -202, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 123 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 39, 1, YYAT_ERROR, 0 },
		{ 32, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 18, 1, YYAT_DEFAULT, 107 },
		{ -35, 1, YYAT_REDUCE, 42 },
		{ -4, 1, YYAT_REDUCE, 51 },
		{ 36, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 16, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 115 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 15, 1, YYAT_DEFAULT, 107 },
		{ -199, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 115 },
		{ -205, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 31, 1, YYAT_DEFAULT, 159 },
		{ -188, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ -29, 1, YYAT_DEFAULT, 141 },
		{ 31, 1, YYAT_ERROR, 0 },
		{ 30, 1, YYAT_ERROR, 0 },
		{ 27, 1, YYAT_DEFAULT, 141 },
		{ -10, 1, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_DEFAULT, 123 },
		{ 2, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ -192, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ -34, 1, YYAT_DEFAULT, 119 },
		{ -31, 1, YYAT_DEFAULT, 123 },
		{ 0, 0, YYAT_DEFAULT, 123 },
		{ 0, 0, YYAT_DEFAULT, 123 },
		{ 0, 0, YYAT_DEFAULT, 123 },
		{ -29, 1, YYAT_ERROR, 0 },
		{ -195, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 25, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 25, 1, YYAT_ERROR, 0 },
		{ 24, 1, YYAT_ERROR, 0 },
		{ 3, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 151 },
		{ 22, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ -21, 1, YYAT_ERROR, 0 },
		{ -38, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ -235, 1, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ -38, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 1, YYAT_REDUCE, 54 },
		{ -2, 1, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ -18, 1, YYAT_ERROR, 0 },
		{ -25, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 7, 1, YYAT_ERROR, 0 },
		{ -42, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 62 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 65;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 16, 39 },
		{ 16, 19 },
		{ 16, 11 },
		{ 60, 74 },
		{ 133, 155 },
		{ 16, 13 },
		{ 16, 12 },
		{ 16, 18 },
		{ 145, 86 },
		{ 16, 10 },
		{ 44, 24 },
		{ 145, 87 },
		{ 43, 57 },
		{ 44, 27 },
		{ 60, 75 },
		{ 16, 15 },
		{ 151, 159 },
		{ 151, 102 },
		{ 44, 59 },
		{ 145, 145 },
		{ 145, 90 },
		{ 43, 58 },
		{ 123, 149 },
		{ 16, 14 },
		{ 2, 25 },
		{ 2, 26 },
		{ 2, 28 },
		{ 81, 110 },
		{ 122, 148 },
		{ 81, 111 },
		{ 118, 144 },
		{ 118, 89 },
		{ 95, 126 },
		{ 95, 69 },
		{ 53, 70 },
		{ 53, 68 },
		{ 49, 64 },
		{ 49, 63 },
		{ 0, 16 },
		{ 0, 17 },
		{ 121, 147 },
		{ 120, 146 },
		{ 117, 143 },
		{ 115, 142 },
		{ 114, 141 },
		{ 112, 140 },
		{ 99, 129 },
		{ 89, 119 },
		{ 82, 113 },
		{ 79, 107 },
		{ 78, 106 },
		{ 76, 103 },
		{ 73, 97 },
		{ 71, 96 },
		{ 69, 93 },
		{ 65, 88 },
		{ 42, 56 },
		{ 38, 52 },
		{ 37, 51 },
		{ 36, 50 },
		{ 33, 48 },
		{ 21, 41 },
		{ 20, 40 },
		{ 6, 35 },
		{ 4, 32 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 37, 16 },
		{ 0, -1 },
		{ 6, 44 },
		{ 0, -1 },
		{ 54, -1 },
		{ 0, -1 },
		{ 51, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, -1 },
		{ 51, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 48, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 47, -1 },
		{ 46, -1 },
		{ 47, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 41, -1 },
		{ 0, -1 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 31, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 21, 95 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -12, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, -1 },
		{ 0, -1 },
		{ 41, -1 },
		{ 0, -1 },
		{ 30, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 151 },
		{ 0, -1 },
		{ 44, -1 },
		{ 27, 118 },
		{ 0, -1 },
		{ 5, 118 },
		{ 24, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 145 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 18, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 31, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 21, -1 },
		{ 0, -1 },
		{ 22, 118 },
		{ 28, -1 },
		{ 0, -1 },
		{ 20, 118 },
		{ 8, 145 },
		{ 0, 145 },
		{ 17, -1 },
		{ 16, -1 },
		{ 4, -1 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -24, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -11, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 555 ".\\myparser.y"

int useDatabase(char *database){
	ifstream fin("sys.dat");
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	bool flag = false;
	while (fin.getline(str, LINE_LENGTH))
	{
			if (!strcmp(database, str)) {
			flag = true;
			break;
		}
	}
	if(!flag){return 0;}
	base = database;
	return 1;
}
void showDatabase(){
	ifstream fin("sys.dat");
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	while (fin.getline(str, LINE_LENGTH))
	{
		cout << str << endl;
	}
}
int createDatabase(char *database){
	ifstream fin("sys.dat");
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	while (fin.getline(str, LINE_LENGTH))
	{
		if (!strcmp(database, str)) {
			return 0;
		}
	}
	freopen("sys.dat", "at", stdout);
	cout << database << endl;
	freopen("CON", "w", stdout);
	_mkdir(database);
	return 1;
}
int createTable(Createstruct* createsql) {
	if(base=="") return 0;
	string name = createsql->table;
	Createfieldsdef* field = createsql->fdef;
	ifstream fin(("./" + base + "/sys.dat").c_str());
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	while (fin.getline(str, LINE_LENGTH))
	{
		if (!strcmp(name.c_str(), str)) {
			return 0;
		}
	}
	freopen(("./"+base+"/sys.dat").c_str(), "at", stdout);
	
	cout << name << endl;
	while (field)
	{
		cout << field->field << " " << field->type << " " << field->length << " " << endl;;
		field = field->next_fdef;
	}
	cout << "********************" << endl;
	fopen(("./" + base + "/"+name+".txt").c_str(), "w");
	freopen("CON","w",stdout);
	return 1;
}
vector<string> splitString(const string& s)
{
	vector<string> ans;
	int len = s.length();
	if (len == 0) return ans;
	for (int i = 0; i < len;) {
		int pos = s.find(' ', i);
		if (pos != string::npos) {
			if (pos == i) {//跳过多个连续的空格
				i = pos + 1;
				continue;
			}
			else {
				string strTemp = s.substr(i, pos - i);
				ans.push_back(strTemp);
				i = pos + 1;
			}
		}
		else {
			string strTemp = s.substr(i, len - i);
			ans.push_back(strTemp);
			break;
		}
	}
	return ans;
}
int insertSql(Insertstruct* sql) {
	if (base == "") { return 0; }
	const char* splitc = "********************";
	if (base == "") { return 0; }
	ifstream fin(("./" + base + "/sys.dat").c_str());
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	int type[100][2];
	char* name = sql->table;
	map<string, int> construct;
	Insertfields* tf = sql->tf;
	bool flag = false;

	if (tf == NULL) {
		tf = new Insertfields;
		flag = true;
	}
	Insertfields* tp = tf;
	int cnt = 0;
	fin.getline(str, LINE_LENGTH);
	while (strlen(str) && strcmp(name, str) != 0)
	{
		while (strlen(str) && strcmp(str, splitc) != 0)
		{
			fin.getline(str, LINE_LENGTH);
		}
		fin.getline(str, LINE_LENGTH);
	}
	if (strcmp(name, str) != 0) { return 0; }
	fin.getline(str, LINE_LENGTH);
	Insertfields* tt = NULL;
	while (strcmp(str, splitc) != 0)
	{
		vector<string> field = splitString(str);
		construct[field[0]] = cnt;
		type[cnt][0] = atoi(field[1].c_str());
		type[cnt++][1] = atoi(field[2].c_str());
		if (flag) {
			tt = new Insertfields;
			char* s = (char*)malloc(sizeof(field[0]));
			memcpy(s, field[0].c_str(), sizeof(field[0]));
			tt->field = s;
			tt->next_if = NULL;
			tp->next_if = tt;
			tp = tt;
		}
		fin.getline(str, LINE_LENGTH);
	}
	Insertvalues* tv = sql->tv;
	if (flag) { tf = tf->next_if; }
	string data[100];
	for (int i = 0;i < 100;i++) { data[i] = "NULL"; }
	while (tf && tv)
	{
		if (!construct.count(tf->field)) {
		//	cout << 2 << endl;
			return 0;
		}
		int idx = construct[tf->field];
		string s = tv->val;
		if (type[idx][0] == 0) {
			for (int i = 0;i < s.length();i++) {
				if (!isdigit(s[i])) {
				//	cout << 3 << endl;
					return 0;
				}
			}
		}
		else if(type[idx][0]==1)
		{
			if (s.length() > type[idx][1]) {
				//cout << s.length() << " " << type[idx][1] << endl;
				//cout << 4 << endl;
				return 0;
			}
		}
		data[idx] = s;
		tf = tf->next_if;
		tv = tv->next_iv;
	}
	if (tf == NULL && tv == NULL) {
		freopen(("./" + base + "/" + name + ".txt").c_str(), "at", stdout);
		for (int i = 0;i < construct.size();i++) {
			cout << data[i] << " ";
		}
		cout << endl;
		freopen("CON", "w", stdout);
		return 1;
	}
	else {
		//cout << 5 << endl;
		return 0;
	}
	return 1;
}
void inorder(Conditions* condition) {
	if (condition->comp_op!='-') {
		inorder(condition->left);
		cout << condition->comp_op<<" ";
		if (condition->value)
			cout << condition->value<<" ";
		inorder(condition->right);
	}
	else
	{
		cout << condition->table << " ";
		cout << condition->value << " ";
	}
}
int selectSql(Selectstruct* sql) {
	const char* splitc = "********************";
	Selectedfields* sf = sql->sf;
	if (base == "") { return 0; }
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];

	Selectedtables* st = sql->st;
	char* name;
	map<string, map<string, int>> construct;
	while (st)
	{
		ifstream fin(("./" + base + "/sys.dat").c_str());
		name = st->table;
		map<string, int>tmp;
		int cnt = 0;
		fin.getline(str, LINE_LENGTH);
		while (strlen(str) && strcmp(name, str) != 0)
		{
			while (strcmp(str, splitc) != 0)
			{
				fin.getline(str, LINE_LENGTH);
			}
			fin.getline(str, LINE_LENGTH);
		}
		if (strcmp(name, str)!=0) { return -2; }
		fin.getline(str, LINE_LENGTH);
		while (strcmp(str, splitc) != 0)
		{
			vector<string> field = splitString(str);
			tmp[field[0]] = cnt++;
			fin.getline(str, LINE_LENGTH);
		}
		construct[name] = tmp;
		st = st->next_st;
	}
	Conditions* conditions = sql->cons;
	if (conditions) {
		myConditions.clear();
		genCondations(conditions, false,false);
		// inorder(conditions);cout << endl;
		/*for (auto it : myConditions) {
			cout <<"table: "<< it.first << endl;
			vector<vector<cons>> tmp = myConditions[it.first];
			for (int i = 0;i < tmp.size();i++) {
				for (int j = 0;j < tmp[i].size();j++) {
					cout << tmp[i][j].field << tmp[i][j].cmp << tmp[i][j].value << " ";
				
				}
				cout <<endl;
			}
			
		}*/
	}



	map<string, set<string>> search;
	if (strcmp(sf->table, "all") == 0) {
		st = sql->st;
		while (st)
		{

			sf = sql->sf;
			while (sf)
			{
				//cout << sf->field << endl;
				if (strcmp(sf->field, "all") == 0) {
					map<string, int> idx = construct[st->table];
					for (auto ii : idx) {
						search[st->table].insert(ii.first);
					}	
				}
				else {
					search[st->table].insert(sf->field);
				}
				sf = sf->next_sf;
			}
			st = st->next_st;
		}
	}
	else {
		while (sf)
		{
			search[sf->table].insert(sf->field);
			
			sf = sf->next_sf;
		}
	}
	for (auto it : search) {
		map<string, int> idx = construct[it.first];
		cout << endl<<"\t"<<it.first << endl;
		for (auto ii : it.second) {
			cout << ii << "\t";
		}
		cout << endl;
		ifstream fin(("./" + base + "/" + it.first + ".txt").c_str());
		while (fin.getline(str, LINE_LENGTH)) {
			vector<string>data = splitString(str);
			if (data.size() == 0) { break; }
			if (conditions && !judge(idx, data,it.first)) { continue; }
			for (auto k : it.second) {
				if (!idx.count(k)) { return 0; }
				cout << data[idx[k]] << "\t";
			}
			cout << endl;
		}
	}
	return 1;
}

bool judge(map<string,int>idx,vector<string> data,string table) {
	if (!myConditions.count(table)) {
		if (!myConditions.count("all")){
				return true;
		}
		else
		{
			table = "all";
		}
	}
	for (int i = 0;i < myConditions[table].size();i++) {
		bool flag = true;
		for (cons j : myConditions[table][i]) {
			int ix = idx[j.field];
			switch (j.cmp)
			{
			case '!':if (data[ix] == j.value) { flag = false;break; }break;
				
			case '=':if (data[ix] != j.value) { flag = false;break; }break;
			case '>':if (j.type == 1) { flag = false;break; }
						else if (atof(data[ix].c_str()) <= atof(j.value.c_str())) {flag = false;break; }break;
			case '<':if (j.type == 1) { flag = false;break; }
						else if (atof(data[ix].c_str()) >= atof(j.value.c_str())) { flag = false;break; }break;
			default:
				break;
			}
		}
		if (flag) {
			return true;
		}
	}
	return false;
}
vector<cons> genCondations(Conditions* condition, bool flag, bool turn) {
	char cmp = condition->comp_op;
	// cout << condition->left->comp_op << " " << cmp << " " << condition->right->comp_op << endl;
	//if (condition->value != NULL && strcmp(condition->value, "YES") == 0) { turn = false; }
	//else 
	if (turn || (condition->value != NULL && strcmp(condition->value, "NOT") == 0)) {
		condition->value = NULL;
		switch (cmp)
		{
		case '>':cmp = '<';break;
		case '<':cmp = '>';break;
		case '=':cmp = '!';break;
		case '!':cmp = '=';break;
		case 'a':cmp = 'o';turn = true;break;
		case 'o':cmp = 'a';turn = true;break;
		default:
			break;
		}
	}
	condition->comp_op = cmp;
	vector<cons>tmp1;
	vector<cons>tmp2;
	vector<cons>res;
	condition->table = condition->left->table;
	if (cmp == 'a') {
		// cout << "AND" << endl;
		if (condition->left) {
			tmp1 = genCondations(condition->left, true, turn);
			tmp2 = genCondations(condition->right, true, turn);
			if (strcmp(condition->left->table, condition->right->table) != 0) {
				myConditions[condition->left->table].push_back(tmp1);
				myConditions[condition->right->table].push_back(tmp2);
			}
			else
			{	
				int idx = 0;
				vector<cons> child[4];
				vector<cons> tmp;
				for (int i = 0;i < tmp1.size();i++) {
					if (tmp1[i].cmp == '#') {
						child[idx++] = tmp;
						tmp.clear();
						continue;
					}
					tmp.push_back(tmp1[i]);
				}
				child[idx++] = tmp;
				tmp.clear();
				for (int i = 0;i < tmp2.size();i++) {
					if (tmp2[i].cmp == '#') {
						child[idx++] = tmp;
						tmp.clear();
						continue;
					}
					tmp.push_back(tmp2[i]);
				}
				child[idx++] = tmp;

				for (int i = 0;i < idx;i++) {
					for (int j = i+1;j < idx;j++) {
						res.clear();
						for (int k = 0;k < child[i].size();k++) {
							res.push_back(child[i][k]);
						}
						for (int k = 0;k < child[j].size();k++) {
							res.push_back(child[j][k]);
						}
						myConditions[condition->table].push_back(res);
					}
				}
			}
			return res;
		}
	}
	else if (cmp == 'o')
	{
		// cout << "OR" << endl;
		if (condition->left) {
			tmp1 = genCondations(condition->left, flag, turn);

			tmp2 = genCondations(condition->right, flag, turn);

			for (int i = 0;i < tmp1.size();i++) {
				res.push_back(tmp1[i]);
			}
			res.push_back(cons((char*)"",'#', (char*)"",-1));
			for (int i = 0;i < tmp2.size();i++) {
				res.push_back(tmp2[i]);
			}
			return res;
		}
	}
	else {
		// cout << cmp << endl;
		res.push_back(cons(condition->left->value, cmp, condition->right->value, condition->right->type));
	}
	if (!res.empty() && !flag)
		myConditions[condition->table].push_back(res);
	return res;
}
int updatesql(Updatestruct* sql) {
	if (base == "") { return -1; }
	const char* splitc = "********************";
	ifstream fin(("./" + base + "/sys.dat").c_str());
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	int type[100][2];
	char* name = sql->table;
	map<string, int> construct;
	Updatefields* uf = sql->uf;
	int cnt = 0;
	string up[100][2];
	int cnt2 = 0;
	while (uf)//转换赋值
	{
		up[cnt2][0] = uf->field;
		up[cnt2++][1] = uf->vals;
		uf = uf->next_uf;
	}


	fin.getline(str, LINE_LENGTH);//找到该表的结构
	while (str != NULL && strcmp(name, str) != 0)
	{
		while (strcmp(str, splitc) != 0)
		{
			fin.getline(str, LINE_LENGTH);
		}
		fin.getline(str, LINE_LENGTH);
	}
	fin.getline(str, LINE_LENGTH);
	while (strcmp(str, splitc) != 0)//构造表结构
	{
		vector<string> field = splitString(str);
		construct[field[0]] = cnt;
		type[cnt][0] = atoi(field[1].c_str());
		type[cnt++][1] = atoi(field[2].c_str());
		fin.getline(str, LINE_LENGTH);
	}
	Conditions* cons = sql->cons;
	if (cons) {
		//inorder(cons);
		myConditions.clear();
		genCondations(cons,false,false);
	}
	ifstream fin2(("./" + base + "/" + name + ".txt").c_str());
	vector<vector<string>> res;
	int flu = 0;
	while (fin2.getline(str, LINE_LENGTH)) {
		vector<string> data = splitString(str);
		if (cons && !judge(construct, data,name)) { res.push_back(data); continue; }
		//确实要修改
		for (int i = 0;i < cnt2;i++) {//判断新值是否合法
			int idx = construct[up[i][0]];
			string s = up[i][1];
			if (type[idx][0] == 0) {
				for (int i = 0;i < s.length();i++) {
					if (!isdigit(s[i])) {
						cout << "num!" << s[i] << endl;
						return -1;
					}
				}
			}
			else if (type[idx][0] == 1)
			{
				if (s.length() > type[idx][1]) {
					cout << s.length() << type[idx][1] << "length" << endl;
					return -1;
				}
			}
			data[idx] = s;
			flu++;
		}
		res.push_back(data);
	}
	fin2.close();
	freopen(("./" + base + "/" + name + ".txt").c_str(), "w", stdout);
	for (int i = 0;i < res.size();i++) {
		for (int j = 0;j < res[i].size();j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	freopen("CON", "w", stdout);
	return flu;
}
int deleteSql(Deletestruct * sql) {
	if (base == "") { return -1; }
	const char* splitc = "********************";
	ifstream fin(("./" + base + "/sys.dat").c_str());
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	int type[100][2];
	char* name = sql->table;
	map<string, int> construct;
	int cnt = 0;
	
	fin.getline(str, LINE_LENGTH);//找到该表的结构
	while (str != NULL && strcmp(name, str) != 0)
	{
		while (strcmp(str, splitc) != 0)
		{
			fin.getline(str, LINE_LENGTH);
		}
		fin.getline(str, LINE_LENGTH);
	}
	fin.getline(str, LINE_LENGTH);
	while (strcmp(str, splitc) != 0)//构造表结构
	{
		vector<string> field = splitString(str);
		construct[field[0]] = cnt;
		type[cnt][0] = field[1][0] - '0';
		type[cnt++][1] = field[2][0] - '0';
		fin.getline(str, LINE_LENGTH);
	}
	Conditions* cons = sql->cons;
	if (cons) {
		//inorder(cons);
		myConditions.clear();
		genCondations(cons, false,false);
	}
	ifstream fin2(("./" + base + "/" + name + ".txt").c_str());
	vector<vector<string>> res;
	int flu = 0;
	while (fin2.getline(str, LINE_LENGTH)) {
		vector<string> data = splitString(str);
		if (cons && judge(construct, data,name)) { flu++; continue; }
		res.push_back(data);
	}
	fin2.close();
	freopen(("./" + base + "/" + name + ".txt").c_str(), "w", stdout);
	for (int i = 0;i < res.size();i++) {
		for (int j = 0;j < res[i].size();j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	freopen("CON", "w", stdout);
	return flu;
}
int dropTable(char * name) {
	if (base == "") { return -1; }
	const char* splitc = "********************";
	ifstream fin(("./" + base + "/sys.dat").c_str());
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	vector<string> res;
	fin.getline(str, LINE_LENGTH);//找到该表的结构
	while (strlen(str) && strcmp(name, str) != 0)
	{
		while (strlen(str) && strcmp(str, splitc) != 0)
		{
			res.push_back(str);
			fin.getline(str, LINE_LENGTH);
		}
		res.push_back(str);
		fin.getline(str, LINE_LENGTH);
	}
	if (strcmp(name, str) != 0) { return -1; }
	fin.getline(str, LINE_LENGTH);
	while (strcmp(str, splitc) != 0)//跳过被删表结构
	{
		fin.getline(str, LINE_LENGTH);
	}
	while (fin.getline(str, LINE_LENGTH)) {
		res.push_back(str);
	}
	freopen(("./" + base + "/sys.dat").c_str(), "w", stdout);
	for (string s : res) {
		cout << s << endl;
	}
	remove(("./" + base + "/" + name + ".txt").c_str());
	freopen("CON", "w", stdout);
	return 1;
}
int dropDatabase(char* name) {
	ifstream fin("./sys.dat");
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	vector<string> res;
	bool flag = false;
	fin.getline(str, LINE_LENGTH);
	while (strlen(str))
	{
		if (strcmp(name, str) == 0) { 
			flag = true;
			fin.getline(str, LINE_LENGTH); 
			continue; 
		}
		res.push_back(str);
		fin.getline(str, LINE_LENGTH);
	}
	if (!flag) { return 0; }
	freopen("./sys.dat", "w", stdout);
	for (string s : res) {
		cout << s << endl;	
	}
	freopen("CON", "w", stdout);
	rmdir(name);
	return 1;
}
int showTables() {
	if (base == "") { return 0; }
	const char* splitc = "********************";
	ifstream fin(("./" + base + "/sys.dat").c_str());
	const   int  LINE_LENGTH = 100;
	char  str[LINE_LENGTH];
	fin.getline(str, LINE_LENGTH);
	while (strlen(str))
	{
		cout << str << endl;
		while (strcmp(str, splitc) != 0)
		{
			fin.getline(str, LINE_LENGTH);
		}
		fin.getline(str, LINE_LENGTH);
	}
	return 1;
}
int main(int argc, char *argv[])
{
//	freopen("C:\\Users\\86139\\Desktop\\TEST2.txt", "r", stdin);
    printf("Ok\n");
	int n = 1;
	while (true)
	{
		mylexer lexer;
		myparser parser;
		if (parser.yycreate(&lexer)) {
			if (lexer.yycreate(&parser)) {
				//lexer.yyin = new ifstream(argv[1]);
				//lexer.yyout = new ofstream(argv[2]);
				n = parser.yyparse();
				//parse_tree.get_label();
				//parse_tree.gen_code(*lexer.yyout);
			}
		}
	}
	
	
	getchar();
	return n;
}
void yyerror(const char *s)
{
	printf("Error: %s\n", s);
}

