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

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_ARRAY = 258,
    TOKEN_BOOLEAN = 259,
    TOKEN_CHAR = 260,
    TOKEN_ELSE = 261,
    TOKEN_FALSE = 262,
    TOKEN_FOR = 263,
    TOKEN_FUNCTION = 264,
    TOKEN_IF = 265,
    TOKEN_INTEGER = 266,
    TOKEN_PRINT = 267,
    TOKEN_RETURN = 268,
    TOKEN_STRING = 269,
    TOKEN_TRUE = 270,
    TOKEN_VOID = 271,
    TOKEN_WHILE = 272,
    TOKEN_LITERAL_INT = 273,
    TOKEN_LITERAL_CHAR = 274,
    TOKEN_LITERAL_STRING = 275,
    TOKEN_IDENT = 276,
    TOKEN_POSTFIX_ADD = 277,
    TOKEN_POSTFIX_MINUS = 278,
    TOKEN_GREATER_EQUAL = 279,
    TOKEN_LESS_EQUAL = 280,
    TOKEN_EQUAL = 281,
    TOKEN_NOT_EQUAL = 282,
    TOKEN_NOT = 283,
    TOKEN_LOGICAL_AND = 284,
    TOKEN_LOGICAL_OR = 285,
    TOKEN_LPAREN = 286,
    TOKEN_RPAREN = 287,
    TOKEN_LBRACKET = 288,
    TOKEN_RBRACKET = 289,
    TOKEN_LBRACE = 290,
    TOKEN_RBRACE = 291,
    TOKEN_EXPONENTIATION = 292,
    TOKEN_MUL = 293,
    TOKEN_DIV = 294,
    TOKEN_MOD = 295,
    TOKEN_PLUS = 296,
    TOKEN_MINUS = 297,
    TOKEN_COMMA = 298,
    TOKEN_GREATER = 299,
    TOKEN_LESS = 300,
    TOKEN_ASSIGN = 301,
    TOKEN_COLON = 302,
    TOKEN_SEMI = 303,
    TOKEN_ERROR = 304,
    NO_ELSE = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "b-minor-parser.y" /* yacc.c:1909  */

  struct decl *decl;
  struct stmt *stmt;
  struct expr *expr;
  struct type *type;
  struct param_list *param_list;
  char *name;
  int value;

#line 115 "tokens.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
