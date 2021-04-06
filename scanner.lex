%{
#include <unistd.h>
#include "tokens.hpp"
%}

%{ 
/* Declarations section */ 
#include "tokens.hpp" 
%} 

%option yylineno 
%option noyywrap 
digit ([0-9]) 
letter ([a-zA-Z])
whitespace ([\t\n ])

%% 
\"(([^\"]|\\\")*[^\\])?\" return STRING;
"void" return VOID;
"int" return INT;
"byte" return BYTE;
"bool" return BOOL;
"and"|"&&" return AND;
"or"|"||" return OR;
"not"|"!" return NOT;
"true" return TRUE;
"false" return FALSE;
"return" return RETURN;
"if" return IF;
"else" return ELSE;
"while" return WHILE;
"break" return BREAK;
"continue" return CONTINUE;
"switch" return SWITCH;
"case" return CASE;
"default" return DEFAULT;
":" return COLON;
";" return SC;
"," return COMMA;
"(" return LPAREN;
")" return RPAREN;
"{" return LBRACE;
"}" return RBRACE;
"=" return ASSIGN;
"=="|"!="|"<"|">"|"<="|">=" return RELOP;
\+|\-|\*|\/ return BINOP;
\/\/[^\n]*$ return COMMENT;


{digit}+b return B;  
[1-9]+{digit}*|0 return NUM;
{letter}+({digit}*|{letter}*)* return ID;
{letter}+@{letter}+\.com return EMAIL;

{whitespace} ; 
. printf("Lex doesn't know what that is!\n"); 

%% 
/* Code section is empty. All code in parts*/ 
