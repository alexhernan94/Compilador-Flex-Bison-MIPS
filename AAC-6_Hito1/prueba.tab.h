/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMENTERO = 258,
     MAS = 259,
     MENOS = 260,
     POR = 261,
     DIV = 262,
     PAR_I = 263,
     PAR_D = 264,
     IF = 265,
     THEN = 266,
     MAYOR_Q = 267,
     MENOR_Q = 268,
     WITH = 269,
     USE = 270,
     ELSE = 271,
     SALTOLINEA = 272,
     PROCEDURE = 273,
     IS = 274,
     IDENTIFICADOR = 275,
     END = 276,
     BEGINN = 277,
     DOSPUNTOS = 278,
     INTEGER = 279,
     FLOAT = 280,
     STRING = 281,
     BOOLEAN = 282,
     IDENTIFICADORSIMB = 283,
     PIZQ_COM = 284,
     DOSPUNTOS_IGUAL = 285,
     PDECH_COM = 286,
     PUTLINE = 287,
     ENDIF = 288,
     NUMREAL = 289,
     TRUE = 290,
     FALSE = 291,
     COMENTARIO = 292,
     WHILE = 293,
     LOOP = 294,
     ENDLOOP = 295,
     IGUAL = 296
   };
#endif
/* Tokens.  */
#define NUMENTERO 258
#define MAS 259
#define MENOS 260
#define POR 261
#define DIV 262
#define PAR_I 263
#define PAR_D 264
#define IF 265
#define THEN 266
#define MAYOR_Q 267
#define MENOR_Q 268
#define WITH 269
#define USE 270
#define ELSE 271
#define SALTOLINEA 272
#define PROCEDURE 273
#define IS 274
#define IDENTIFICADOR 275
#define END 276
#define BEGINN 277
#define DOSPUNTOS 278
#define INTEGER 279
#define FLOAT 280
#define STRING 281
#define BOOLEAN 282
#define IDENTIFICADORSIMB 283
#define PIZQ_COM 284
#define DOSPUNTOS_IGUAL 285
#define PDECH_COM 286
#define PUTLINE 287
#define ENDIF 288
#define NUMREAL 289
#define TRUE 290
#define FALSE 291
#define COMENTARIO 292
#define WHILE 293
#define LOOP 294
#define ENDLOOP 295
#define IGUAL 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

