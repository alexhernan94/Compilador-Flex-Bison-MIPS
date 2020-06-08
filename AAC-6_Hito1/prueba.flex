%{
#include "prueba.tab.h"
%}
digito [0-9]
letra [a-zA-Z]
letraysimb [a-zA-Z_\.]


%option noyywrap
%%
[ \t]+ ;

"+" return MAS;
"-" return MENOS;
"*" return POR;
"/" return DIV;
"(" return PAR_I;
")" return PAR_D;
"if"  { return IF;}
"then" { return THEN;}
">" return MAYOR_Q;
"<" return MENOR_Q;
"else" return ELSE;
"procedure" return PROCEDURE;
"is" return IS;
"with" return WITH;
"use" return USE;
"end" return END;
"begin" return BEGINN;
":" return DOSPUNTOS;
"Integer" return INTEGER;
"Float" return FLOAT;
"String" return STRING;
"Boolean" return BOOLEAN;
":=" return DOSPUNTOS_IGUAL;
"(\"" return PIZQ_COM;
"\")" return PDECH_COM;
"Put_Line" return PUTLINE;
"end if" return ENDIF;
"True" return TRUE;
"False" return FALSE;
"--" return COMENTARIO;
"while" return WHILE;
"loop" return LOOP;
"end loop" return ENDLOOP;
"=" return IGUAL;




[ \n]+ return SALTOLINEA;


{letra}({letra}|{digito})* return IDENTIFICADOR; 
{letraysimb}+ return IDENTIFICADORSIMB; 
[-+]?{digito}+ {yylval=atoi(yytext); return NUMENTERO;}
[-+]?{digito}+(.{digito}+)?((E|e)[-+]?{digito}+)? {yylval=atoi(yytext); return NUMREAL;}



. {printf("token erroneo\n");} 
%%
