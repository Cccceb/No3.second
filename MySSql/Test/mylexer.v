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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 06/15/20
# Time: 12:23:55
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  NOT

    2  EXIT

    3  TABLES

    4  DROP

    5  DELETE

    6  FROM

    7  UPDATE

    8  SET

    9  CREATE

   10  SHOW

   11  USE

   12  DATABASE

   13  TABLE

   14  CHAR

   15  INT

   16  SELECT

   17  WHERE

   18  INSERT

   19  INTO

   20  VALUES

   21  AND

   22  OR

   23  [A-Za-z][A-Za-z0-9_]*

   24  [0-9]+

   25  "="

   26  "!="

   27  "<"

   28  ">"

   29  ">="

   30  "<="

   31  "+"

   32  "-"

   33  "*"

   34  "/"

   35  "'"

   36  ";"

   37  "("

   38  ")"

   39  "."

   40  ","


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x21               goto 3
	0x27               goto 4
	0x28               goto 5
	0x29               goto 6
	0x2a               goto 7
	0x2b               goto 8
	0x2c               goto 9
	0x2d               goto 10
	0x2e               goto 11
	0x2f               goto 12
	0x30 - 0x39 (10)   goto 13
	0x3b               goto 14
	0x3c               goto 15
	0x3d               goto 16
	0x3e               goto 17
	0x41               goto 18
	0x42               goto 19
	0x43               goto 20
	0x44               goto 21
	0x45               goto 22
	0x46               goto 23
	0x47 - 0x48 (2)    goto 19
	0x49               goto 24
	0x4a - 0x4d (4)    goto 19
	0x4e               goto 25
	0x4f               goto 26
	0x50 - 0x52 (3)    goto 19
	0x53               goto 27
	0x54               goto 28
	0x55               goto 29
	0x56               goto 30
	0x57               goto 31
	0x58 - 0x5a (3)    goto 19
	0x61               goto 18
	0x62               goto 19
	0x63               goto 20
	0x64               goto 21
	0x65               goto 22
	0x66               goto 23
	0x67 - 0x68 (2)    goto 19
	0x69               goto 24
	0x6a - 0x6d (4)    goto 19
	0x6e               goto 25
	0x6f               goto 26
	0x70 - 0x72 (3)    goto 19
	0x73               goto 27
	0x74               goto 28
	0x75               goto 29
	0x76               goto 30
	0x77               goto 31
	0x78 - 0x7a (3)    goto 19


state 2
	^INITIAL

	0x21               goto 3
	0x27               goto 4
	0x28               goto 5
	0x29               goto 6
	0x2a               goto 7
	0x2b               goto 8
	0x2c               goto 9
	0x2d               goto 10
	0x2e               goto 11
	0x2f               goto 12
	0x30 - 0x39 (10)   goto 13
	0x3b               goto 14
	0x3c               goto 15
	0x3d               goto 16
	0x3e               goto 17
	0x41               goto 18
	0x42               goto 19
	0x43               goto 20
	0x44               goto 21
	0x45               goto 22
	0x46               goto 23
	0x47 - 0x48 (2)    goto 19
	0x49               goto 24
	0x4a - 0x4d (4)    goto 19
	0x4e               goto 25
	0x4f               goto 26
	0x50 - 0x52 (3)    goto 19
	0x53               goto 27
	0x54               goto 28
	0x55               goto 29
	0x56               goto 30
	0x57               goto 31
	0x58 - 0x5a (3)    goto 19
	0x61               goto 18
	0x62               goto 19
	0x63               goto 20
	0x64               goto 21
	0x65               goto 22
	0x66               goto 23
	0x67 - 0x68 (2)    goto 19
	0x69               goto 24
	0x6a - 0x6d (4)    goto 19
	0x6e               goto 25
	0x6f               goto 26
	0x70 - 0x72 (3)    goto 19
	0x73               goto 27
	0x74               goto 28
	0x75               goto 29
	0x76               goto 30
	0x77               goto 31
	0x78 - 0x7a (3)    goto 19


state 3
	0x3d               goto 32


state 4
	match 35


state 5
	match 37


state 6
	match 38


state 7
	match 33


state 8
	match 31


state 9
	match 40


state 10
	match 32


state 11
	match 39


state 12
	match 34


state 13
	0x30 - 0x39 (10)   goto 13

	match 24


state 14
	match 36


state 15
	0x3d               goto 33

	match 27


state 16
	match 25


state 17
	0x3d               goto 34

	match 28


state 18
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4d (13)   goto 19
	0x4e               goto 35
	0x4f - 0x5a (12)   goto 19
	0x5f               goto 19
	0x61 - 0x6d (13)   goto 19
	0x6e               goto 35
	0x6f - 0x7a (12)   goto 19

	match 23


state 19
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 23


state 20
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x47 (7)    goto 19
	0x48               goto 36
	0x49 - 0x51 (9)    goto 19
	0x52               goto 37
	0x53 - 0x5a (8)    goto 19
	0x5f               goto 19
	0x61 - 0x67 (7)    goto 19
	0x68               goto 36
	0x69 - 0x71 (9)    goto 19
	0x72               goto 37
	0x73 - 0x7a (8)    goto 19

	match 23


state 21
	0x30 - 0x39 (10)   goto 19
	0x41               goto 38
	0x42 - 0x44 (3)    goto 19
	0x45               goto 39
	0x46 - 0x51 (12)   goto 19
	0x52               goto 40
	0x53 - 0x5a (8)    goto 19
	0x5f               goto 19
	0x61               goto 38
	0x62 - 0x64 (3)    goto 19
	0x65               goto 39
	0x66 - 0x71 (12)   goto 19
	0x72               goto 40
	0x73 - 0x7a (8)    goto 19

	match 23


state 22
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x57 (23)   goto 19
	0x58               goto 41
	0x59 - 0x5a (2)    goto 19
	0x5f               goto 19
	0x61 - 0x77 (23)   goto 19
	0x78               goto 41
	0x79 - 0x7a (2)    goto 19

	match 23


state 23
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x51 (17)   goto 19
	0x52               goto 42
	0x53 - 0x5a (8)    goto 19
	0x5f               goto 19
	0x61 - 0x71 (17)   goto 19
	0x72               goto 42
	0x73 - 0x7a (8)    goto 19

	match 23


state 24
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4d (13)   goto 19
	0x4e               goto 43
	0x4f - 0x5a (12)   goto 19
	0x5f               goto 19
	0x61 - 0x6d (13)   goto 19
	0x6e               goto 43
	0x6f - 0x7a (12)   goto 19

	match 23


state 25
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4e (14)   goto 19
	0x4f               goto 44
	0x50 - 0x5a (11)   goto 19
	0x5f               goto 19
	0x61 - 0x6e (14)   goto 19
	0x6f               goto 44
	0x70 - 0x7a (11)   goto 19

	match 23


state 26
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x51 (17)   goto 19
	0x52               goto 45
	0x53 - 0x5a (8)    goto 19
	0x5f               goto 19
	0x61 - 0x71 (17)   goto 19
	0x72               goto 45
	0x73 - 0x7a (8)    goto 19

	match 23


state 27
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 46
	0x46 - 0x47 (2)    goto 19
	0x48               goto 47
	0x49 - 0x5a (18)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 46
	0x66 - 0x67 (2)    goto 19
	0x68               goto 47
	0x69 - 0x7a (18)   goto 19

	match 23


state 28
	0x30 - 0x39 (10)   goto 19
	0x41               goto 48
	0x42 - 0x5a (25)   goto 19
	0x5f               goto 19
	0x61               goto 48
	0x62 - 0x7a (25)   goto 19

	match 23


state 29
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4f (15)   goto 19
	0x50               goto 49
	0x51 - 0x52 (2)    goto 19
	0x53               goto 50
	0x54 - 0x5a (7)    goto 19
	0x5f               goto 19
	0x61 - 0x6f (15)   goto 19
	0x70               goto 49
	0x71 - 0x72 (2)    goto 19
	0x73               goto 50
	0x74 - 0x7a (7)    goto 19

	match 23


state 30
	0x30 - 0x39 (10)   goto 19
	0x41               goto 51
	0x42 - 0x5a (25)   goto 19
	0x5f               goto 19
	0x61               goto 51
	0x62 - 0x7a (25)   goto 19

	match 23


state 31
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x47 (7)    goto 19
	0x48               goto 52
	0x49 - 0x5a (18)   goto 19
	0x5f               goto 19
	0x61 - 0x67 (7)    goto 19
	0x68               goto 52
	0x69 - 0x7a (18)   goto 19

	match 23


state 32
	match 26


state 33
	match 30


state 34
	match 29


state 35
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x43 (3)    goto 19
	0x44               goto 53
	0x45 - 0x5a (22)   goto 19
	0x5f               goto 19
	0x61 - 0x63 (3)    goto 19
	0x64               goto 53
	0x65 - 0x7a (22)   goto 19

	match 23


state 36
	0x30 - 0x39 (10)   goto 19
	0x41               goto 54
	0x42 - 0x5a (25)   goto 19
	0x5f               goto 19
	0x61               goto 54
	0x62 - 0x7a (25)   goto 19

	match 23


state 37
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 55
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 55
	0x66 - 0x7a (21)   goto 19

	match 23


state 38
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x53 (19)   goto 19
	0x54               goto 56
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 56
	0x75 - 0x7a (6)    goto 19

	match 23


state 39
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4b (11)   goto 19
	0x4c               goto 57
	0x4d - 0x5a (14)   goto 19
	0x5f               goto 19
	0x61 - 0x6b (11)   goto 19
	0x6c               goto 57
	0x6d - 0x7a (14)   goto 19

	match 23


state 40
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4e (14)   goto 19
	0x4f               goto 58
	0x50 - 0x5a (11)   goto 19
	0x5f               goto 19
	0x61 - 0x6e (14)   goto 19
	0x6f               goto 58
	0x70 - 0x7a (11)   goto 19

	match 23


state 41
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x48 (8)    goto 19
	0x49               goto 59
	0x4a - 0x5a (17)   goto 19
	0x5f               goto 19
	0x61 - 0x68 (8)    goto 19
	0x69               goto 59
	0x6a - 0x7a (17)   goto 19

	match 23


state 42
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4e (14)   goto 19
	0x4f               goto 60
	0x50 - 0x5a (11)   goto 19
	0x5f               goto 19
	0x61 - 0x6e (14)   goto 19
	0x6f               goto 60
	0x70 - 0x7a (11)   goto 19

	match 23


state 43
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x52 (18)   goto 19
	0x53               goto 61
	0x54               goto 62
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x72 (18)   goto 19
	0x73               goto 61
	0x74               goto 62
	0x75 - 0x7a (6)    goto 19

	match 23


state 44
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x53 (19)   goto 19
	0x54               goto 63
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 63
	0x75 - 0x7a (6)    goto 19

	match 23


state 45
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 22


state 46
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4b (11)   goto 19
	0x4c               goto 64
	0x4d - 0x53 (7)    goto 19
	0x54               goto 65
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x6b (11)   goto 19
	0x6c               goto 64
	0x6d - 0x73 (7)    goto 19
	0x74               goto 65
	0x75 - 0x7a (6)    goto 19

	match 23


state 47
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4e (14)   goto 19
	0x4f               goto 66
	0x50 - 0x5a (11)   goto 19
	0x5f               goto 19
	0x61 - 0x6e (14)   goto 19
	0x6f               goto 66
	0x70 - 0x7a (11)   goto 19

	match 23


state 48
	0x30 - 0x39 (10)   goto 19
	0x41               goto 19
	0x42               goto 67
	0x43 - 0x5a (24)   goto 19
	0x5f               goto 19
	0x61               goto 19
	0x62               goto 67
	0x63 - 0x7a (24)   goto 19

	match 23


state 49
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x43 (3)    goto 19
	0x44               goto 68
	0x45 - 0x5a (22)   goto 19
	0x5f               goto 19
	0x61 - 0x63 (3)    goto 19
	0x64               goto 68
	0x65 - 0x7a (22)   goto 19

	match 23


state 50
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 69
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 69
	0x66 - 0x7a (21)   goto 19

	match 23


state 51
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4b (11)   goto 19
	0x4c               goto 70
	0x4d - 0x5a (14)   goto 19
	0x5f               goto 19
	0x61 - 0x6b (11)   goto 19
	0x6c               goto 70
	0x6d - 0x7a (14)   goto 19

	match 23


state 52
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 71
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 71
	0x66 - 0x7a (21)   goto 19

	match 23


state 53
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 21


state 54
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x51 (17)   goto 19
	0x52               goto 72
	0x53 - 0x5a (8)    goto 19
	0x5f               goto 19
	0x61 - 0x71 (17)   goto 19
	0x72               goto 72
	0x73 - 0x7a (8)    goto 19

	match 23


state 55
	0x30 - 0x39 (10)   goto 19
	0x41               goto 73
	0x42 - 0x5a (25)   goto 19
	0x5f               goto 19
	0x61               goto 73
	0x62 - 0x7a (25)   goto 19

	match 23


state 56
	0x30 - 0x39 (10)   goto 19
	0x41               goto 74
	0x42 - 0x5a (25)   goto 19
	0x5f               goto 19
	0x61               goto 74
	0x62 - 0x7a (25)   goto 19

	match 23


state 57
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 75
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 75
	0x66 - 0x7a (21)   goto 19

	match 23


state 58
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4f (15)   goto 19
	0x50               goto 76
	0x51 - 0x5a (10)   goto 19
	0x5f               goto 19
	0x61 - 0x6f (15)   goto 19
	0x70               goto 76
	0x71 - 0x7a (10)   goto 19

	match 23


state 59
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x53 (19)   goto 19
	0x54               goto 77
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 77
	0x75 - 0x7a (6)    goto 19

	match 23


state 60
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4c (12)   goto 19
	0x4d               goto 78
	0x4e - 0x5a (13)   goto 19
	0x5f               goto 19
	0x61 - 0x6c (12)   goto 19
	0x6d               goto 78
	0x6e - 0x7a (13)   goto 19

	match 23


state 61
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 79
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 79
	0x66 - 0x7a (21)   goto 19

	match 23


state 62
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4e (14)   goto 19
	0x4f               goto 80
	0x50 - 0x5a (11)   goto 19
	0x5f               goto 19
	0x61 - 0x6e (14)   goto 19
	0x6f               goto 80
	0x70 - 0x7a (11)   goto 19

	match 15


state 63
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 1


state 64
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 81
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 81
	0x66 - 0x7a (21)   goto 19

	match 23


state 65
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 8


state 66
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x56 (22)   goto 19
	0x57               goto 82
	0x58 - 0x5a (3)    goto 19
	0x5f               goto 19
	0x61 - 0x76 (22)   goto 19
	0x77               goto 82
	0x78 - 0x7a (3)    goto 19

	match 23


state 67
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x4b (11)   goto 19
	0x4c               goto 83
	0x4d - 0x5a (14)   goto 19
	0x5f               goto 19
	0x61 - 0x6b (11)   goto 19
	0x6c               goto 83
	0x6d - 0x7a (14)   goto 19

	match 23


state 68
	0x30 - 0x39 (10)   goto 19
	0x41               goto 84
	0x42 - 0x5a (25)   goto 19
	0x5f               goto 19
	0x61               goto 84
	0x62 - 0x7a (25)   goto 19

	match 23


state 69
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 11


state 70
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x54 (20)   goto 19
	0x55               goto 85
	0x56 - 0x5a (5)    goto 19
	0x5f               goto 19
	0x61 - 0x74 (20)   goto 19
	0x75               goto 85
	0x76 - 0x7a (5)    goto 19

	match 23


state 71
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x51 (17)   goto 19
	0x52               goto 86
	0x53 - 0x5a (8)    goto 19
	0x5f               goto 19
	0x61 - 0x71 (17)   goto 19
	0x72               goto 86
	0x73 - 0x7a (8)    goto 19

	match 23


state 72
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 14


state 73
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x53 (19)   goto 19
	0x54               goto 87
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 87
	0x75 - 0x7a (6)    goto 19

	match 23


state 74
	0x30 - 0x39 (10)   goto 19
	0x41               goto 19
	0x42               goto 88
	0x43 - 0x5a (24)   goto 19
	0x5f               goto 19
	0x61               goto 19
	0x62               goto 88
	0x63 - 0x7a (24)   goto 19

	match 23


state 75
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x53 (19)   goto 19
	0x54               goto 89
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 89
	0x75 - 0x7a (6)    goto 19

	match 23


state 76
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 4


state 77
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 2


state 78
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 6


state 79
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x51 (17)   goto 19
	0x52               goto 90
	0x53 - 0x5a (8)    goto 19
	0x5f               goto 19
	0x61 - 0x71 (17)   goto 19
	0x72               goto 90
	0x73 - 0x7a (8)    goto 19

	match 23


state 80
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 19


state 81
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x42 (2)    goto 19
	0x43               goto 91
	0x44 - 0x5a (23)   goto 19
	0x5f               goto 19
	0x61 - 0x62 (2)    goto 19
	0x63               goto 91
	0x64 - 0x7a (23)   goto 19

	match 23


state 82
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 10


state 83
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 92
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 92
	0x66 - 0x7a (21)   goto 19

	match 23


state 84
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x53 (19)   goto 19
	0x54               goto 93
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 93
	0x75 - 0x7a (6)    goto 19

	match 23


state 85
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 94
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 94
	0x66 - 0x7a (21)   goto 19

	match 23


state 86
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 95
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 95
	0x66 - 0x7a (21)   goto 19

	match 23


state 87
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 96
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 96
	0x66 - 0x7a (21)   goto 19

	match 23


state 88
	0x30 - 0x39 (10)   goto 19
	0x41               goto 97
	0x42 - 0x5a (25)   goto 19
	0x5f               goto 19
	0x61               goto 97
	0x62 - 0x7a (25)   goto 19

	match 23


state 89
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 98
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 98
	0x66 - 0x7a (21)   goto 19

	match 23


state 90
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x53 (19)   goto 19
	0x54               goto 99
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 99
	0x75 - 0x7a (6)    goto 19

	match 23


state 91
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x53 (19)   goto 19
	0x54               goto 100
	0x55 - 0x5a (6)    goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 100
	0x75 - 0x7a (6)    goto 19

	match 23


state 92
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x52 (18)   goto 19
	0x53               goto 101
	0x54 - 0x5a (7)    goto 19
	0x5f               goto 19
	0x61 - 0x72 (18)   goto 19
	0x73               goto 101
	0x74 - 0x7a (7)    goto 19

	match 13


state 93
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 102
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 102
	0x66 - 0x7a (21)   goto 19

	match 23


state 94
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x52 (18)   goto 19
	0x53               goto 103
	0x54 - 0x5a (7)    goto 19
	0x5f               goto 19
	0x61 - 0x72 (18)   goto 19
	0x73               goto 103
	0x74 - 0x7a (7)    goto 19

	match 23


state 95
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 17


state 96
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 9


state 97
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x52 (18)   goto 19
	0x53               goto 104
	0x54 - 0x5a (7)    goto 19
	0x5f               goto 19
	0x61 - 0x72 (18)   goto 19
	0x73               goto 104
	0x74 - 0x7a (7)    goto 19

	match 23


state 98
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 5


state 99
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 18


state 100
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 16


state 101
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 3


state 102
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 7


state 103
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 20


state 104
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x44 (4)    goto 19
	0x45               goto 105
	0x46 - 0x5a (21)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 105
	0x66 - 0x7a (21)   goto 19

	match 23


state 105
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 12


#############################################################################
# Summary
#############################################################################

1 start state(s)
40 expression(s), 105 state(s)


#############################################################################
# End of File
#############################################################################
