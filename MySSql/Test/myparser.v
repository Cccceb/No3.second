#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 22 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 06/15/20
# Time: 12:23:55
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : statements $end

    1  statements : statements statement
    2             | statement

    3  statement : SHOW TABLES ';'
    4            | EXIT
    5            | DROP DATABASE database ';'
    6            | DROP TABLE table ';'
    7            | deletesql

    8  deletesql : DELETE FROM table WHERE conditions ';'

    9  statement : updatesql

   10  updatesql : UPDATE table SET updatefields WHERE conditions ';'

   11  updatefields : updatefield
   12               | updatefields ',' updatefield

   13  updatefield : ID CMP '\'' ID '\''
   14              | ID CMP NUMBER

   15  statement : showdatabase

   16  showdatabase : SHOW DATABASE ';'

   17  statement : createdatabase

   18  createdatabase : CREATE DATABASE database ';'

   19  statement : usedatabase

   20  usedatabase : USE database ';'

   21  database : ID

   22  statement : createsql

   23  createsql : CREATE TABLE table '(' fieldsdefinition ')' ';'

   24  table : ID

   25  fieldsdefinition : field_type
   26                   | fieldsdefinition ',' field_type

   27  field_type : field type

   28  field : ID

   29  type : CHAR '(' NUMBER ')'
   30       | INT

   31  statement : selectsql

   32  selectsql : SELECT fields_star FROM tables ';'
   33            | SELECT fields_star FROM tables WHERE conditions ';'

   34  fields_star : table_fields
   35              | '*'

   36  table_fields : table_field
   37               | table_fields ',' table_field

   38  table_field : field
   39              | table '.' field

   40  tables : tables ',' table
   41         | table

   42  conditions : condition
   43             | conditions AND conditions
   44             | conditions OR conditions
   45             | '(' conditions ')'
   46             | NOT '(' conditions ')'

   47  condition : condition condition condition
   48            | CMP
   49            | table '.' field
   50            | field
   51            | expr
   52            | '\'' NUMBER '\''
   53            | '\'' ID '\''

   54  expr : expr '+' expr
   55       | expr '-' expr
   56       | expr '*' expr
   57       | expr '/' expr
   58       | '(' expr ')'
   59       | '-' expr
   60       | NUMBER

   61  statement : insertsql

   62  insertsql : INSERT INTO table '(' insert_fields ')' VALUES '(' vals ')' ';'
   63            | INSERT INTO table VALUES '(' vals ')' ';'

   64  insert_fields : insert_fields ',' field
   65                | field

   66  vals : val
   67       | vals ',' val

   68  val : '\'' ID '\''
   69      | '\'' NUMBER '\''
   70      | NUMBER


##############################################################################
# States
##############################################################################

state 0
	$accept : . statements $end

	CREATE  shift 1
	SELECT  shift 2
	SHOW  shift 3
	USE  shift 4
	INSERT  shift 5
	UPDATE  shift 6
	DELETE  shift 7
	DROP  shift 8
	EXIT  shift 9

	createsql  goto 10
	updatesql  goto 11
	createdatabase  goto 12
	showdatabase  goto 13
	insertsql  goto 14
	selectsql  goto 15
	statements  goto 16
	statement  goto 17
	usedatabase  goto 18
	deletesql  goto 19


state 1
	createsql : CREATE . TABLE table '(' fieldsdefinition ')' ';'
	createdatabase : CREATE . DATABASE database ';'

	TABLE  shift 20
	DATABASE  shift 21


state 2
	selectsql : SELECT . fields_star FROM tables WHERE conditions ';'
	selectsql : SELECT . fields_star FROM tables ';'

	'*'  shift 22
	ID  shift 23

	table  goto 24
	fields_star  goto 25
	table_fields  goto 26
	field  goto 27
	table_field  goto 28


state 3
	statement : SHOW . TABLES ';'
	showdatabase : SHOW . DATABASE ';'

	DATABASE  shift 29
	TABLES  shift 30


state 4
	usedatabase : USE . database ';'

	ID  shift 31

	database  goto 32


state 5
	insertsql : INSERT . INTO table VALUES '(' vals ')' ';'
	insertsql : INSERT . INTO table '(' insert_fields ')' VALUES '(' vals ')' ';'

	INTO  shift 33


state 6
	updatesql : UPDATE . table SET updatefields WHERE conditions ';'

	ID  shift 34

	table  goto 35


state 7
	deletesql : DELETE . FROM table WHERE conditions ';'

	FROM  shift 36


state 8
	statement : DROP . DATABASE database ';'
	statement : DROP . TABLE table ';'

	TABLE  shift 37
	DATABASE  shift 38


state 9
	statement : EXIT .  (4)

	.  reduce 4


state 10
	statement : createsql .  (22)

	.  reduce 22


state 11
	statement : updatesql .  (9)

	.  reduce 9


state 12
	statement : createdatabase .  (17)

	.  reduce 17


state 13
	statement : showdatabase .  (15)

	.  reduce 15


state 14
	statement : insertsql .  (61)

	.  reduce 61


state 15
	statement : selectsql .  (31)

	.  reduce 31


state 16
	$accept : statements . $end  (0)
	statements : statements . statement

	$end  accept
	CREATE  shift 1
	SELECT  shift 2
	SHOW  shift 3
	USE  shift 4
	INSERT  shift 5
	UPDATE  shift 6
	DELETE  shift 7
	DROP  shift 8
	EXIT  shift 9

	createsql  goto 10
	updatesql  goto 11
	createdatabase  goto 12
	showdatabase  goto 13
	insertsql  goto 14
	selectsql  goto 15
	statement  goto 39
	usedatabase  goto 18
	deletesql  goto 19


state 17
	statements : statement .  (2)

	.  reduce 2


state 18
	statement : usedatabase .  (19)

	.  reduce 19


state 19
	statement : deletesql .  (7)

	.  reduce 7


state 20
	createsql : CREATE TABLE . table '(' fieldsdefinition ')' ';'

	ID  shift 34

	table  goto 40


state 21
	createdatabase : CREATE DATABASE . database ';'

	ID  shift 31

	database  goto 41


state 22
	fields_star : '*' .  (35)

	.  reduce 35


state 23
	field : ID .  (28)
	table : ID .  (24)

	'.'  reduce 24
	.  reduce 28


state 24
	table_field : table . '.' field

	'.'  shift 42


state 25
	selectsql : SELECT fields_star . FROM tables WHERE conditions ';'
	selectsql : SELECT fields_star . FROM tables ';'

	FROM  shift 43


state 26
	fields_star : table_fields .  (34)
	table_fields : table_fields . ',' table_field

	','  shift 44
	.  reduce 34


state 27
	table_field : field .  (38)

	.  reduce 38


state 28
	table_fields : table_field .  (36)

	.  reduce 36


state 29
	showdatabase : SHOW DATABASE . ';'

	';'  shift 45


state 30
	statement : SHOW TABLES . ';'

	';'  shift 46


state 31
	database : ID .  (21)

	.  reduce 21


state 32
	usedatabase : USE database . ';'

	';'  shift 47


state 33
	insertsql : INSERT INTO . table VALUES '(' vals ')' ';'
	insertsql : INSERT INTO . table '(' insert_fields ')' VALUES '(' vals ')' ';'

	ID  shift 34

	table  goto 48


state 34
	table : ID .  (24)

	.  reduce 24


state 35
	updatesql : UPDATE table . SET updatefields WHERE conditions ';'

	SET  shift 49


state 36
	deletesql : DELETE FROM . table WHERE conditions ';'

	ID  shift 34

	table  goto 50


state 37
	statement : DROP TABLE . table ';'

	ID  shift 34

	table  goto 51


state 38
	statement : DROP DATABASE . database ';'

	ID  shift 31

	database  goto 52


state 39
	statements : statements statement .  (1)

	.  reduce 1


state 40
	createsql : CREATE TABLE table . '(' fieldsdefinition ')' ';'

	'('  shift 53


state 41
	createdatabase : CREATE DATABASE database . ';'

	';'  shift 54


state 42
	table_field : table '.' . field

	ID  shift 55

	field  goto 56


state 43
	selectsql : SELECT fields_star FROM . tables WHERE conditions ';'
	selectsql : SELECT fields_star FROM . tables ';'

	ID  shift 34

	table  goto 57
	tables  goto 58


state 44
	table_fields : table_fields ',' . table_field

	ID  shift 23

	table  goto 24
	field  goto 27
	table_field  goto 59


state 45
	showdatabase : SHOW DATABASE ';' .  (16)

	.  reduce 16


state 46
	statement : SHOW TABLES ';' .  (3)

	.  reduce 3


state 47
	usedatabase : USE database ';' .  (20)

	.  reduce 20


state 48
	insertsql : INSERT INTO table . VALUES '(' vals ')' ';'
	insertsql : INSERT INTO table . '(' insert_fields ')' VALUES '(' vals ')' ';'

	'('  shift 60
	VALUES  shift 61


state 49
	updatesql : UPDATE table SET . updatefields WHERE conditions ';'

	ID  shift 62

	updatefield  goto 63
	updatefields  goto 64


state 50
	deletesql : DELETE FROM table . WHERE conditions ';'

	WHERE  shift 65


state 51
	statement : DROP TABLE table . ';'

	';'  shift 66


state 52
	statement : DROP DATABASE database . ';'

	';'  shift 67


state 53
	createsql : CREATE TABLE table '(' . fieldsdefinition ')' ';'

	ID  shift 55

	field_type  goto 68
	field  goto 69
	fieldsdefinition  goto 70


state 54
	createdatabase : CREATE DATABASE database ';' .  (18)

	.  reduce 18


state 55
	field : ID .  (28)

	.  reduce 28


state 56
	table_field : table '.' field .  (39)

	.  reduce 39


state 57
	tables : table .  (41)

	.  reduce 41


state 58
	selectsql : SELECT fields_star FROM tables . WHERE conditions ';'
	selectsql : SELECT fields_star FROM tables . ';'
	tables : tables . ',' table

	','  shift 71
	';'  shift 72
	WHERE  shift 73


state 59
	table_fields : table_fields ',' table_field .  (37)

	.  reduce 37


state 60
	insertsql : INSERT INTO table '(' . insert_fields ')' VALUES '(' vals ')' ';'

	ID  shift 55

	field  goto 74
	insert_fields  goto 75


state 61
	insertsql : INSERT INTO table VALUES . '(' vals ')' ';'

	'('  shift 76


state 62
	updatefield : ID . CMP '\'' ID '\''
	updatefield : ID . CMP NUMBER

	CMP  shift 77


state 63
	updatefields : updatefield .  (11)

	.  reduce 11


state 64
	updatesql : UPDATE table SET updatefields . WHERE conditions ';'
	updatefields : updatefields . ',' updatefield

	','  shift 78
	WHERE  shift 79


state 65
	deletesql : DELETE FROM table WHERE . conditions ';'

	'\''  shift 80
	'('  shift 81
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	NOT  shift 85

	table  goto 86
	field  goto 87
	conditions  goto 88
	condition  goto 89
	expr  goto 90


state 66
	statement : DROP TABLE table ';' .  (6)

	.  reduce 6


state 67
	statement : DROP DATABASE database ';' .  (5)

	.  reduce 5


state 68
	fieldsdefinition : field_type .  (25)

	.  reduce 25


state 69
	field_type : field . type

	CHAR  shift 91
	INT  shift 92

	type  goto 93


state 70
	fieldsdefinition : fieldsdefinition . ',' field_type
	createsql : CREATE TABLE table '(' fieldsdefinition . ')' ';'

	')'  shift 94
	','  shift 95


state 71
	tables : tables ',' . table

	ID  shift 34

	table  goto 96


state 72
	selectsql : SELECT fields_star FROM tables ';' .  (32)

	.  reduce 32


state 73
	selectsql : SELECT fields_star FROM tables WHERE . conditions ';'

	'\''  shift 80
	'('  shift 81
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	NOT  shift 85

	table  goto 86
	field  goto 87
	conditions  goto 97
	condition  goto 89
	expr  goto 90


state 74
	insert_fields : field .  (65)

	.  reduce 65


state 75
	insertsql : INSERT INTO table '(' insert_fields . ')' VALUES '(' vals ')' ';'
	insert_fields : insert_fields . ',' field

	')'  shift 98
	','  shift 99


state 76
	insertsql : INSERT INTO table VALUES '(' . vals ')' ';'

	'\''  shift 100
	NUMBER  shift 101

	val  goto 102
	vals  goto 103


state 77
	updatefield : ID CMP . '\'' ID '\''
	updatefield : ID CMP . NUMBER

	'\''  shift 104
	NUMBER  shift 105


state 78
	updatefields : updatefields ',' . updatefield

	ID  shift 62

	updatefield  goto 106


state 79
	updatesql : UPDATE table SET updatefields WHERE . conditions ';'

	'\''  shift 80
	'('  shift 81
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	NOT  shift 85

	table  goto 86
	field  goto 87
	conditions  goto 107
	condition  goto 89
	expr  goto 90


state 80
	condition : '\'' . ID '\''
	condition : '\'' . NUMBER '\''

	ID  shift 108
	NUMBER  shift 109


state 81
	conditions : '(' . conditions ')'
	expr : '(' . expr ')'

	'\''  shift 80
	'('  shift 81
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	NOT  shift 85

	table  goto 86
	field  goto 87
	conditions  goto 110
	condition  goto 89
	expr  goto 111


state 82
	expr : '-' . expr

	'('  shift 112
	'-'  shift 82
	NUMBER  shift 83

	expr  goto 113


state 83
	expr : NUMBER .  (60)

	.  reduce 60


state 84
	condition : CMP .  (48)

	.  reduce 48


state 85
	conditions : NOT . '(' conditions ')'

	'('  shift 114


state 86
	condition : table . '.' field

	'.'  shift 115


state 87
	condition : field .  (50)

	.  reduce 50


state 88
	deletesql : DELETE FROM table WHERE conditions . ';'
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions

	';'  shift 116
	OR  shift 117
	AND  shift 118


state 89
	condition : condition . condition condition
	conditions : condition .  (42)

	'\''  shift 80
	'('  shift 112
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	.  reduce 42

	table  goto 86
	field  goto 87
	condition  goto 119
	expr  goto 90


90: shift-reduce conflict (shift 122, reduce 51) on '-'
state 90
	expr : expr . '+' expr
	expr : expr . '/' expr
	expr : expr . '-' expr
	expr : expr . '*' expr
	condition : expr .  (51)

	'*'  shift 120
	'+'  shift 121
	'-'  shift 122
	'/'  shift 123
	.  reduce 51


state 91
	type : CHAR . '(' NUMBER ')'

	'('  shift 124


state 92
	type : INT .  (30)

	.  reduce 30


state 93
	field_type : field type .  (27)

	.  reduce 27


state 94
	createsql : CREATE TABLE table '(' fieldsdefinition ')' . ';'

	';'  shift 125


state 95
	fieldsdefinition : fieldsdefinition ',' . field_type

	ID  shift 55

	field_type  goto 126
	field  goto 69


state 96
	tables : tables ',' table .  (40)

	.  reduce 40


state 97
	selectsql : SELECT fields_star FROM tables WHERE conditions . ';'
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions

	';'  shift 127
	OR  shift 117
	AND  shift 118


state 98
	insertsql : INSERT INTO table '(' insert_fields ')' . VALUES '(' vals ')' ';'

	VALUES  shift 128


state 99
	insert_fields : insert_fields ',' . field

	ID  shift 55

	field  goto 129


state 100
	val : '\'' . ID '\''
	val : '\'' . NUMBER '\''

	ID  shift 130
	NUMBER  shift 131


state 101
	val : NUMBER .  (70)

	.  reduce 70


state 102
	vals : val .  (66)

	.  reduce 66


state 103
	insertsql : INSERT INTO table VALUES '(' vals . ')' ';'
	vals : vals . ',' val

	')'  shift 132
	','  shift 133


state 104
	updatefield : ID CMP '\'' . ID '\''

	ID  shift 134


state 105
	updatefield : ID CMP NUMBER .  (14)

	.  reduce 14


state 106
	updatefields : updatefields ',' updatefield .  (12)

	.  reduce 12


state 107
	updatesql : UPDATE table SET updatefields WHERE conditions . ';'
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions

	';'  shift 135
	OR  shift 117
	AND  shift 118


state 108
	condition : '\'' ID . '\''

	'\''  shift 136


state 109
	condition : '\'' NUMBER . '\''

	'\''  shift 137


state 110
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions
	conditions : '(' conditions . ')'

	')'  shift 138
	OR  shift 117
	AND  shift 118


111: shift-reduce conflict (shift 139, reduce 51) on ')'
111: shift-reduce conflict (shift 122, reduce 51) on '-'
state 111
	expr : expr . '+' expr
	expr : expr . '/' expr
	expr : expr . '-' expr
	expr : expr . '*' expr
	expr : '(' expr . ')'
	condition : expr .  (51)

	')'  shift 139
	'*'  shift 120
	'+'  shift 121
	'-'  shift 122
	'/'  shift 123
	.  reduce 51


state 112
	expr : '(' . expr ')'

	'('  shift 112
	'-'  shift 82
	NUMBER  shift 83

	expr  goto 140


state 113
	expr : expr . '+' expr
	expr : expr . '/' expr
	expr : expr . '-' expr
	expr : '-' expr .  (59)
	expr : expr . '*' expr

	'*'  shift 120
	'/'  shift 123
	.  reduce 59


state 114
	conditions : NOT '(' . conditions ')'

	'\''  shift 80
	'('  shift 81
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	NOT  shift 85

	table  goto 86
	field  goto 87
	conditions  goto 141
	condition  goto 89
	expr  goto 90


state 115
	condition : table '.' . field

	ID  shift 55

	field  goto 142


state 116
	deletesql : DELETE FROM table WHERE conditions ';' .  (8)

	.  reduce 8


state 117
	conditions : conditions OR . conditions

	'\''  shift 80
	'('  shift 81
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	NOT  shift 85

	table  goto 86
	field  goto 87
	conditions  goto 143
	condition  goto 89
	expr  goto 90


state 118
	conditions : conditions AND . conditions

	'\''  shift 80
	'('  shift 81
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	NOT  shift 85

	table  goto 86
	field  goto 87
	conditions  goto 144
	condition  goto 89
	expr  goto 90


state 119
	condition : condition . condition condition
	condition : condition condition . condition

	'\''  shift 80
	'('  shift 112
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84

	table  goto 86
	field  goto 87
	condition  goto 145
	expr  goto 90


state 120
	expr : expr '*' . expr

	'('  shift 112
	'-'  shift 82
	NUMBER  shift 83

	expr  goto 146


state 121
	expr : expr '+' . expr

	'('  shift 112
	'-'  shift 82
	NUMBER  shift 83

	expr  goto 147


state 122
	expr : expr '-' . expr

	'('  shift 112
	'-'  shift 82
	NUMBER  shift 83

	expr  goto 148


state 123
	expr : expr '/' . expr

	'('  shift 112
	'-'  shift 82
	NUMBER  shift 83

	expr  goto 149


state 124
	type : CHAR '(' . NUMBER ')'

	NUMBER  shift 150


state 125
	createsql : CREATE TABLE table '(' fieldsdefinition ')' ';' .  (23)

	.  reduce 23


state 126
	fieldsdefinition : fieldsdefinition ',' field_type .  (26)

	.  reduce 26


state 127
	selectsql : SELECT fields_star FROM tables WHERE conditions ';' .  (33)

	.  reduce 33


state 128
	insertsql : INSERT INTO table '(' insert_fields ')' VALUES . '(' vals ')' ';'

	'('  shift 151


state 129
	insert_fields : insert_fields ',' field .  (64)

	.  reduce 64


state 130
	val : '\'' ID . '\''

	'\''  shift 152


state 131
	val : '\'' NUMBER . '\''

	'\''  shift 153


state 132
	insertsql : INSERT INTO table VALUES '(' vals ')' . ';'

	';'  shift 154


state 133
	vals : vals ',' . val

	'\''  shift 100
	NUMBER  shift 101

	val  goto 155


state 134
	updatefield : ID CMP '\'' ID . '\''

	'\''  shift 156


state 135
	updatesql : UPDATE table SET updatefields WHERE conditions ';' .  (10)

	.  reduce 10


state 136
	condition : '\'' ID '\'' .  (53)

	.  reduce 53


state 137
	condition : '\'' NUMBER '\'' .  (52)

	.  reduce 52


state 138
	conditions : '(' conditions ')' .  (45)

	.  reduce 45


state 139
	expr : '(' expr ')' .  (58)

	.  reduce 58


state 140
	expr : expr . '+' expr
	expr : expr . '/' expr
	expr : expr . '-' expr
	expr : expr . '*' expr
	expr : '(' expr . ')'

	')'  shift 139
	'*'  shift 120
	'+'  shift 121
	'-'  shift 122
	'/'  shift 123


state 141
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions
	conditions : NOT '(' conditions . ')'

	')'  shift 157
	OR  shift 117
	AND  shift 118


state 142
	condition : table '.' field .  (49)

	.  reduce 49


state 143
	conditions : conditions . AND conditions
	conditions : conditions OR conditions .  (44)
	conditions : conditions . OR conditions

	AND  shift 118
	.  reduce 44


state 144
	conditions : conditions AND conditions .  (43)
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions

	.  reduce 43


145: shift-reduce conflict (shift 80, reduce 47) on '\''
145: shift-reduce conflict (shift 112, reduce 47) on '('
145: shift-reduce conflict (shift 82, reduce 47) on '-'
145: shift-reduce conflict (shift 23, reduce 47) on ID
145: shift-reduce conflict (shift 83, reduce 47) on NUMBER
145: shift-reduce conflict (shift 84, reduce 47) on CMP
state 145
	condition : condition condition condition .  (47)
	condition : condition . condition condition
	condition : condition condition . condition

	'\''  shift 80
	'('  shift 112
	'-'  shift 82
	ID  shift 23
	NUMBER  shift 83
	CMP  shift 84
	.  reduce 47

	table  goto 86
	field  goto 87
	condition  goto 145
	expr  goto 90


state 146
	expr : expr . '+' expr
	expr : expr . '/' expr
	expr : expr . '-' expr
	expr : expr '*' expr .  (56)
	expr : expr . '*' expr

	.  reduce 56


state 147
	expr : expr '+' expr .  (54)
	expr : expr . '+' expr
	expr : expr . '/' expr
	expr : expr . '-' expr
	expr : expr . '*' expr

	'*'  shift 120
	'/'  shift 123
	.  reduce 54


state 148
	expr : expr . '+' expr
	expr : expr . '/' expr
	expr : expr '-' expr .  (55)
	expr : expr . '-' expr
	expr : expr . '*' expr

	'*'  shift 120
	'/'  shift 123
	.  reduce 55


state 149
	expr : expr . '+' expr
	expr : expr '/' expr .  (57)
	expr : expr . '/' expr
	expr : expr . '-' expr
	expr : expr . '*' expr

	.  reduce 57


state 150
	type : CHAR '(' NUMBER . ')'

	')'  shift 158


state 151
	insertsql : INSERT INTO table '(' insert_fields ')' VALUES '(' . vals ')' ';'

	'\''  shift 100
	NUMBER  shift 101

	val  goto 102
	vals  goto 159


state 152
	val : '\'' ID '\'' .  (68)

	.  reduce 68


state 153
	val : '\'' NUMBER '\'' .  (69)

	.  reduce 69


state 154
	insertsql : INSERT INTO table VALUES '(' vals ')' ';' .  (63)

	.  reduce 63


state 155
	vals : vals ',' val .  (67)

	.  reduce 67


state 156
	updatefield : ID CMP '\'' ID '\'' .  (13)

	.  reduce 13


state 157
	conditions : NOT '(' conditions ')' .  (46)

	.  reduce 46


state 158
	type : CHAR '(' NUMBER ')' .  (29)

	.  reduce 29


state 159
	insertsql : INSERT INTO table '(' insert_fields ')' VALUES '(' vals . ')' ';'
	vals : vals . ',' val

	')'  shift 160
	','  shift 133


state 160
	insertsql : INSERT INTO table '(' insert_fields ')' VALUES '(' vals ')' . ';'

	';'  shift 161


state 161
	insertsql : INSERT INTO table '(' insert_fields ')' VALUES '(' vals ')' ';' .  (62)

	.  reduce 62


##############################################################################
# Summary
##############################################################################

State 90 contains 1 shift-reduce conflict(s)
State 111 contains 2 shift-reduce conflict(s)
State 145 contains 6 shift-reduce conflict(s)


37 token(s), 29 nonterminal(s)
71 grammar rule(s), 162 state(s)


##############################################################################
# End of File
##############################################################################
