%{
#include <ctype.h>
#include <stdio.h>

extern FILE *yyin;
extern FILE *yyout;

%}

%token NUMENTERO, MAS, MENOS, POR, DIV, PAR_I, PAR_D, IF, THEN, MAYOR_Q, MENOR_Q, WITH, USE, ELSE, SALTOLINEA, PROCEDURE, IS, IDENTIFICADOR, END, BEGINN, DOSPUNTOS, INTEGER, FLOAT, STRING, BOOLEAN, IDENTIFICADORSIMB, PIZQ_COM, DOSPUNTOS_IGUAL, PDECH_COM, PUTLINE, ENDIF, NUMREAL, TRUE, FALSE, COMENTARIO, WHILE, LOOP, ENDLOOP, IGUAL
%start programa

%%

programa : cabecera SALTOLINEA cuerpo
;

cuerpo : inicio SALTOLINEA sentencias SALTOLINEA  fin
;

cabecera : with SALTOLINEA use {fprintf(yyout, "Cabecera -> with y use\n");}
;

with: WITH IDENTIFICADORSIMB
;

use: USE IDENTIFICADORSIMB
;

inicio : PROCEDURE IDENTIFICADOR IS {fprintf(yyout, "Inicio -> procedure\n");}
;

fin : END IDENTIFICADOR {fprintf(yyout, "Final -> end\n");}
;

sentencias : declaracion SALTOLINEA comienzo SALTOLINEA sentencia
;

comienzo: BEGINN {fprintf(yyout, "Comienzo -> begin\n");}
;


declaraciones : declaracion SALTOLINEA declaracion
	   | declaracion SALTOLINEA declaraciones

;

declaracion : IDENTIFICADOR DOSPUNTOS tipo

;

tipo: INTEGER {fprintf(yyout, "Declaracion -> int\n");}
      |FLOAT {fprintf(yyout, "Declaracion -> float\n");}
      |STRING {fprintf(yyout, "Declaracion -> string\n");}
      |BOOLEAN {fprintf(yyout, "Declaracion -> boolean\n");}


;

sentencia : expr SALTOLINEA expr 
;

expr: operaciones 
      |sentencia_if {fprintf(yyout, "Sentencia IF\n");}
      |PUTLINE PIZQ_COM IDENTIFICADOR PDECH_COM {fprintf(yyout, "Put_Line\n");}
      |IDENTIFICADOR DOSPUNTOS_IGUAL factor {fprintf(yyout, "Asignacion\n");}
      |COMENTARIO IDENTIFICADOR {fprintf(yyout, "Comentario\n");}
      |bucle_while {fprintf(yyout, "Bucle WHILE\n");}


;

operaciones: IDENTIFICADOR DOSPUNTOS_IGUAL factor MAS factor {fprintf(yyout, "Operación SUMA\n");}  
      |IDENTIFICADOR DOSPUNTOS_IGUAL factor MENOS factor {fprintf(yyout, "Operación MENOS\n");}  
      |IDENTIFICADOR DOSPUNTOS_IGUAL factor POR factor {fprintf(yyout, "Operación MULTIPLICACION\n");}  
      |IDENTIFICADOR DOSPUNTOS_IGUAL factor DIV factor {fprintf(yyout, "Operación DIVISION\n");}  
      |factor {fprintf(yyout, "expr --> term\n");}
;

factor: NUMENTERO {fprintf(yyout, "  factor--> NUMENTERO(%d)\n",$1);}
	| NUMREAL {fprintf(yyout, "  factor--> NUMREAL(%d)\n",$1);}
	|IDENTIFICADOR {fprintf(yyout, "  factor --> variable\n");}
	|TRUE {fprintf(yyout, "  factor --> True\n");}
	|FALSE {fprintf(yyout, "  factor --> False\n");}


;


sentencia_if: IF condicion THEN SALTOLINEA sentencia SALTOLINEA ENDIF
	| IF condicion THEN SALTOLINEA sentencia SALTOLINEA ELSE SALTOLINEA sentencia SALTOLINEA ENDIF 


;

bucle_while: WHILE condicion LOOP SALTOLINEA sentencia SALTOLINEA ENDLOOP
;

condicion: factor MAYOR_Q factor {fprintf(yyout, "Condicion\n");}
	| factor MENOR_Q factor {fprintf(yyout, "Condicion\n");}
	| factor IGUAL factor {fprintf(yyout, "Condicion\n");}

;





%%
int main(int argc, char *argv[]) {

if (argc == 1) {
	yyparse();
}
if (argc == 2) {
	yyout = fopen( "./salidaAda.txt", "wt" );

	yyin = fopen(argv[1], "rt");

	yyparse();
}

return 0;
}


yyerror()
{ 
} 
