%{
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
%}
%name myparser
%union					/*定义yylval的格式*/
{	

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
}
%term CREATE TABLE ID CHAR 	NUMBER INT SELECT WHERE  FROM SHOW DATABASE USE CMP INSERT INTO VALUES UPDATE SET DELETE FROM DROP EXIT TABLES NOT

%left OR
%left AND
%left '+' '-'
%left '*' '/'
%nonterm<yych> table  field database val
%nonterm<yynm> type
%nonterm<cfdef_var>	fieldsdefinition field_type
%nonterm<cs_var>	createsql 
%nonterm<sf_var>  fields_star  table_fields  table_field
%nonterm<st_var> tables 
%nonterm<ss_var>  selectsql
%nonterm<cons_var> conditions condition
%nonterm<is_var> insertsql
%nonterm<if_var> insert_fields
%nonterm<iv_var> vals
%nonterm showdatabase createdatabase
%nonterm<us_var> updatesql
%nonterm<uf_var> updatefields updatefield
%nonterm<ds_var> deletesql
%%
statements: statements statement | statement;
statement : SHOW TABLES ';'
			{
				int result = showTables();
				if(result == 0){
					cout <<"Please Select A Database!"<<endl;
				}
			};
statement : EXIT
			{	
				exit(0);
			};
statement : DROP DATABASE database ';'
			{
				int result = dropDatabase($3);
				if(result == 0){cout <<" Optional Failed!"<<endl;}
				else{cout <<" Optional Successfully!"<<endl;}
			};
statement : DROP TABLE table ';'
			{
				int result = dropTable($3);
				if(result == -1){cout <<" Optional Failed!";}
				else{cout <<" Optional Successfully!";}
			};
statement : deletesql
			{
				int result = deleteSql($1);
				if(result == -1){cout <<" Optional Failed!";}
				else{
					cout <<"Number of rows affected"<<result<<endl;
				}
				
			};
deletesql : DELETE FROM table WHERE conditions ';'
			{
				$$ = (Deletestruct *)malloc(sizeof(Deletestruct));
				$$->table = $3;
				$$->cons = $5;
			};
statement : updatesql
			{
				int result = updatesql($1);
				if(result == -1){cout <<" Optional Failed!";}
				else{
					cout <<"Number of rows affected"<<result<<endl;
				}
				
			};
updatesql : UPDATE table SET updatefields WHERE conditions ';'
			{
				$$ = (Updatestruct *)malloc(sizeof(Updatestruct));
				$$->table = $2;
				$$->uf = $4;
				$$->cons = $6;
			};
updatefields : updatefield 
			{
				$$ = (Updatefields *)malloc(sizeof(Updatefields));
				$$->field = $1->field;
				$$->vals = $1->vals;
				$$->next_uf = NULL;
			}
			| updatefields ',' updatefield
			{
				$$ = (Updatefields *)malloc(sizeof(Updatefields));
				$$->field = $3->field;
				$$->vals = $3->vals;
				$$->next_uf = $1;
			};
			
updatefield : ID CMP '\''ID'\''
			{
				$$ = (Updatefields *)malloc(sizeof(Updatefields));
				$$->field = $1.yych;
				$$->vals = $4.yych;
			}
			| ID CMP NUMBER
			{
				$$ = (Updatefields *)malloc(sizeof(Updatefields));
				$$->field = $1.yych;
				$$->vals = $3.yych;
			};
statement : showdatabase;
showdatabase : SHOW DATABASE ';'{
	showDatabase();
};
statement : createdatabase;
createdatabase : CREATE DATABASE database';'{
	int result = createDatabase($3);
	if(result == 1){cout << "Create Successfully!"<<endl;}
	else{cout << "The database already exists"<<endl;}
};
statement : usedatabase;
usedatabase : USE database ';'{
	int result = useDatabase($2);
	if(result != 1){cout <<"The database doesn't exist" <<endl; }
};
database : ID;
statement : createsql  
{	int result;
	result=createTable($1);
	if(result==1){
		printf("Create Table %s Successful!\n",$1->table);
	}else
	{	
		printf("Create Table %s Failed!\n",$1->table);
	}
};
createsql: CREATE TABLE table '(' fieldsdefinition ')' ';'
{
	$$=(struct Createstruct *)malloc(sizeof(struct Createstruct));
	$$->table=$3;
	$$->fdef=$5;
};

table : ID;
fieldsdefinition : field_type{
					$$ = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
					$$->field = $1->field;
					
					$$->type = $1->type;
					$$->length = $1->length;
					$$->next_fdef = NULL;
					}
				 | fieldsdefinition ',' field_type{
					$$ = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
					$$->field = $3->field;
					$$->type = $3->type;
					$$->length = $3->length;
					$$->next_fdef = $1;
				 };
field_type : field type{
			$$ = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
			$$->field = $1;
		//	cout <<$2[0] <<" "<<$2[1]<<endl;
			if($2[0]==1){
				$$->type = CHAR1;
			}else{
				$$->type= INT1;
			}
			$$->length = $2[1];
			};
field: ID;
type: CHAR '(' NUMBER ')' {
	int * s = (int *)malloc(2*sizeof(int));
	s[0] = 1;
	s[1] = atof($3.yych);
//	cout <<"0"<<$3.yych<<endl;
	$$ = s;
	}
	| INT{
		int * s = (int *)malloc(2*sizeof(int));
		s[0] = 0;
		s[1] = 4;
//		cout <<"1"<<"4"<<endl;
		$$ = s;
	};
statement : selectsql{
			int result = selectSql($1);
			if(result ==0){cout << "Please Select A Database!"<<endl;}
			else if(result == -1){cout <<"There are no selection fields"<<endl;}
			else if(result == -2){cout <<"There are no selection tables"<<endl;}
};
selectsql: SELECT fields_star FROM tables	';'
			{
				$$ = (Selectstruct *)malloc(sizeof(Selectstruct));
				$$->sf = $2;
				$$->st = $4;
				$$->cons = NULL;
			
				
			}
		   | SELECT fields_star FROM tables WHERE conditions ';'
		   {
				$$ = (Selectstruct *)malloc(sizeof(Selectstruct));
				$$->sf = $2;
				$$->st = $4;
				$$->cons = $6;
		   };
fields_star: table_fields
			{
				$$ = (Selectedfields *)malloc(sizeof(Selectedfields));
				$$->table = $1->table;
				$$->field = $1->field;
				$$->next_sf = $1->next_sf;
			}
			| '*'{
				$$ = (Selectedfields *)malloc(sizeof(Selectedfields));
				$$->table = (char *)"all";
				$$->field = (char *)"all";
				$$->next_sf = NULL;
				
			};
table_fields: table_field
			{
				$$ = (Selectedfields *)malloc(sizeof(Selectedfields));
				$$->table = $1->table;
				$$->field = $1->field;
				$$->next_sf = NULL;
			}
			 | table_fields ',' table_field
			 {
				$$ = (Selectedfields *)malloc(sizeof(Selectedfields));
				$$->table = $3->table;
				$$->field = $3->field;
				$$->next_sf = $1;
			 };
table_field: field 
			{
				$$ = (Selectedfields *)malloc(sizeof(Selectedfields));
				$$->table = (char *)"all";
				$$->field = $1;
			}
			| table '.' field
			{
				$$ = (Selectedfields *)malloc(sizeof(Selectedfields));
				$$->table = $1;
				$$->field = $3;		
			};
tables: tables ',' table
		{
			$$ = (Selectedtables *)malloc(sizeof(Selectedtables));
			$$->table = $3;
			$$->next_st = $1;
		} 
		| table
		{
			$$ = (Selectedtables *)malloc(sizeof(Selectedtables));
			$$->table = $1;
			$$->next_st = NULL;
		};
conditions: condition
			{	
				$$ = $1;
			}
		
		   | conditions  AND conditions
		   {
				$$ = (Conditions *)malloc(sizeof(Conditions));	
				$$->left = $1;
				$$->right = $3;
				$$->comp_op = 'a';
				$$->table = (char *)"all";
				$$->value = NULL;
		   }
		   | conditions OR conditions
		   {
				$$ = (Conditions *)malloc(sizeof(Conditions));	
				$$->left = $1;
				$$->right = $3;
				$$->comp_op = 'o';
				$$->table = (char *)"all";
				//$$->value = (char *)"YES";
				$$->value = NULL;
		   }
		   | '(' conditions ')'
		   {
				$$ = $2;
		   }
		   |NOT '(' conditions ')'
		   {
				$$ = $3;
				$$->value =(char *)"NOT";
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
		   }
		   ;
condition : condition condition condition
			{
			
				$$ = (Conditions *)malloc(sizeof(Conditions));	
				$$->comp_op = $2->comp_op;
				$$->left = $1;
				$$->right = $3;
				$$->table = (char *)"all";
				$$->value = $2->value;
			}

			| CMP
			{
		
				$$ = (Conditions *)malloc(sizeof(Conditions));	
				$$->type = -1;
				$$->left = $$->right = NULL;	
				$$->comp_op = $1.yych[0];
				$$->table = (char *)"all";
				$$->value = NULL;
			}
			| table '.' field
			{
				$$ = (Conditions *)malloc(sizeof(Conditions));	
				$$->type = 0;
				$$->value = $3;
				$$->left = $$->right = NULL;	
				$$->comp_op = '-';
				$$->table = $1;
			}
			| field
			{
		
				$$ = (Conditions *)malloc(sizeof(Conditions));	
				$$->type = 0;
				$$->value = $1;
				$$->left = $$->right = NULL;	
				$$->comp_op = '-';
				$$->table = (char *)"all";
			}
			| expr
			{
				$$ = (Conditions *)malloc(sizeof(Conditions));
				$$->type = 2;	
				$$->value = $1.yych;
				$$->left = $$->right = NULL;		
				$$->comp_op = '-';	
				$$->table = (char *)"all";
			//	cout << $1.yych << endl;
			}
			|'\'' NUMBER '\''
			{
			
				$$ = (Conditions *)malloc(sizeof(Conditions));
				$$->type = 2;	
				$$->value = $2.yych;
				$$->left = $$->right = NULL;		
				$$->comp_op = '-';	
				$$->table = (char *)"all";
			}
			|'\'' ID '\''
			{
				$$ = (Conditions *)malloc(sizeof(Conditions));
				$$->type = 1;	
				$$->value = $2.yych;
				$$->left = $$->right = NULL;	
				$$->comp_op = '-';
				$$->table = (char *)"all";
			};
expr:	    expr '+' expr	    { ss.clear();ss << atoi($1.yych) + atoi($3.yych) ;ss>>exprs; $$.yych = (char *)exprs.c_str();  }
		|	expr '-' expr		{ ss.clear();ss << atoi($1.yych) - atoi($3.yych) ;ss>>exprs; $$.yych = (char *)exprs.c_str();  }
		|	expr '*' expr		{ ss.clear();ss << atoi($1.yych) * atoi($3.yych) ;ss>>exprs; $$.yych = (char *)exprs.c_str();  }
		|	expr '/' expr		{ ss.clear();ss << atoi($1.yych) / atoi($3.yych) ;ss>>exprs; $$.yych = (char *)exprs.c_str();  }
		|	'(' expr ')'	{ $$ = $2; }
		|	'-' expr %prec '-'	{ss.clear(); { ss << -1 * atoi($2.yych);ss>>exprs; $$.yych = (char *)exprs.c_str();  }}
		|	NUMBER {$$=$1;}
		;
statement: insertsql
		{
			int result = insertSql($1);
			if(result == 0){cout <<"Operation Failed"<<endl;}
			else{cout <<"Operation Successful"<<endl;}

		};
insertsql : INSERT INTO table '(' insert_fields ')' VALUES '(' vals ')' ';'
			{
				$$ = (Insertstruct *)malloc(sizeof(Insertstruct));
				$$->table = $3;
				$$->tf = $5;
				$$->tv = $9;
			}
			|INSERT INTO table VALUES '(' vals ')' ';'
			{
				$$ = (Insertstruct *)malloc(sizeof(Insertstruct));
				$$->table = $3;
				$$->tf = NULL;
				$$->tv = $6;
			};
insert_fields : insert_fields ',' field
				{
					$$ =  (Insertfields *)malloc(sizeof(Insertfields));
					$$->field = $3;
					$$->next_if = $1;
				}
				|field{
					$$ =  (Insertfields *)malloc(sizeof(Insertfields));
					$$->field = $1;
					$$->next_if = NULL;
				};
vals : val
	{
		$$ = (Insertvalues *)malloc(sizeof(Insertvalues));
		$$->val = $1;
		$$->next_iv = NULL;
	}
	 |vals ',' val
	 {
		$$ = (Insertvalues *)malloc(sizeof(Insertvalues));
		$$->val = $3;
		$$->next_iv = $1;
	 };
val : '\'' ID '\''
	{
		$$ = $2.yych;
	}
	|'\'' NUMBER '\''
	{
		$$ = $2.yych;
	}
	| NUMBER;
%%
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
