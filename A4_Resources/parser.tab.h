/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER_NUMBER = 260,
    BBNUM = 261,
    DOUBLE_NUMBER = 262,
    NAME = 263,
    RETURN = 264,
    INTEGER = 265,
    FLOAT = 266,
    ASSIGN = 267,
    VOID = 268,
    UMINUS = 269,
    WHILE = 270,
    GREATER_THAN = 271,
    NOT_EQUAL = 272,
    LESS_THAN = 273,
    LESS_THAN_EQUAL = 274,
    EQUAL = 275,
    GREATER_THAN_EQUAL = 276,
    IF = 277,
    ELSE = 278,
    DO = 279,
    AND = 280,
    OR = 281,
    NOT = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
#line 24 "parser.y" /* yacc.c:1909  */
union YYSTYPE
{
#line 25 "parser.y" /* yacc.c:1909  */
   int integer_value;
    double double_value;
    std::string * string_value;
    list<Ast *> * ast_list;
    Ast * ast;
    Symbol_Table * symbol_table;
    Symbol_Table_Entry * symbol_entry;
    Basic_Block * basic_block;
    Procedure * procedure;

#line 91 "parser.tab.h" /* yacc.c:1909  */
};
#line 24 "parser.y" /* yacc.c:1909  */
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
