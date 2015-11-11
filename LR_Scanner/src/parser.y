/* parser.y */
%{
#include <stdio.h>
#include "State.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yyleng;
extern State* root;

void yyerror(const char *s);

%}


%union {
	State *s;
	char *str;
}


%token <str> ID STRING SCRIPT

%type <s> list item bnf_item bnf_list symbol_list symbol name

%start list

%%

/* 总的混合bnf和脚本的列表 */
list : item { $$ = new State();  $$->AddChildrenState($1); root = $$; }
	 | list item { $1->AddChildrenState($2); $$ = $1; }
	 ;

/* 可以是bnf或脚本 */
item : bnf_item { $$ = $1; }
	 | SCRIPT { $$ = new State(); $$->state_type = script; $$->script = $1; }
	 ;

/* 一行bnf的定义 */
bnf_item : symbol '=' bnf_list ';' { $1->AddChildrenState($3); $$ = $1; $$->isList = false; }
		 ;

/* bnf后面的部分 */
bnf_list : symbol_list { $$ = $1; }
		 | bnf_list '|' symbol_list { $1->AddBrotherState($3); $$ = $1; }
		 ;

/* 一条bnf项的列表 */
symbol_list : symbol { $$ = new State(); $$->state_type = temporality; $$->AddChildrenState($1); }
			| symbol_list symbol { $1->AddChildrenState($2); $$ = $1; }
			;

/* 可用的bnf符号 */
symbol : '<' name '>' { $$ = $2; $$->state_type = statement; }
	   | '[' name ']' { $$ = $2; $$->state_type = terminal; }
	   | 'e' { $$ = new State(); $$->state_type = epsilon; }
	   | STRING { $$ = new State(); $$->state_type = constant; $$->state_const = $1; }
	   | SCRIPT { $$ = new State(); $$->state_type = script; $$->script = $1; }
	   ;

/* 名字，并且可以定义实例名 */
name : ID  { $$ = new State(); 
			 $$->state_class = $1; }
	 | ID ':' ID  { $$ = new State(); 
	 				$$->state_class = $1;
	 				$$->state_var = $3; }
	 ;
%%

void yyerror(const char* s){
	fprintf(stderr, "%s \n", s);    
	fprintf(stderr, "line %d: ", yylineno);
	fprintf(stderr, "error %s \n", yytext);
}
