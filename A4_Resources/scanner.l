%{
    #include "stdio.h"
    #include <string>
    #include "parser.tab.h"
    #include "storetokens.hh"
%}

digit        [0-9]
operator    [-+*/]
metachar        [;,(){}?:]
name        [a-zA-Z_][a-zA-Z0-9_]*

%%
"//".* ;
[ \t]* ;
[\n]    {}
int            {
//    printf("INTEGER\n");
    store_token_name("INTEGER", yytext, yylineno);
    return INTEGER;
}
float            {
//    printf("FLOAT\n");
    store_token_name("FLOAT", yytext, yylineno);
    return FLOAT;
}
void        {
//    printf("VOID\n");
    store_token_name("VOID", yytext, yylineno);
    return VOID;
}
return        {
//    printf("RETURN\n");
    store_token_name("RETURN", yytext, yylineno);
    return RETURN;
}
while       {
    store_token_name("WHILE", yytext, yylineno);
    return WHILE;
}
do       {
    store_token_name("DO", yytext, yylineno);
    return DO;
}
if       {
    store_token_name("IF", yytext, yylineno);
    return IF;
}
else       {
    store_token_name("ELSE", yytext, yylineno);
    return ELSE;
}
"&&"       {
    store_token_name("AND", yytext, yylineno);
    return AND;
}
"||"       {
    store_token_name("OR", yytext, yylineno);
    return OR;
}
"!"       {
    store_token_name("NOT", yytext, yylineno);
    return NOT;
}
[>]       {
    store_token_name("GREATER_THAN", yytext, yylineno);
    return GREATER_THAN;
}
"!="       {
    store_token_name("NOT_EQUAL", yytext, yylineno);
    return NOT_EQUAL;
}
[<]       {
    store_token_name("LESS_THAN", yytext, yylineno);
    return LESS_THAN;
}
"<="       {
    store_token_name("LESS_THAN_EQUAL", yytext, yylineno);
    return LESS_THAN_EQUAL;
}
"=="      {
    store_token_name("EQUAL", yytext, yylineno);
    return EQUAL;
}
">="       {
    store_token_name("GREATER_THAN_EQUAL", yytext, yylineno);
    return GREATER_THAN_EQUAL;
}
{operator}    {
//    printf("ARITHOP    %c\n", yytext[0]);
    store_token_name("ARITHOP", yytext, yylineno);
    return yytext[0];
}
{digit}*"."{digit}*    {
//    printf("DOUBLE_NUMBER    %s\n", yytext);
    store_token_name("FNUM", yytext, yylineno);
    yylval.double_value = atof(yytext);
    return DOUBLE_NUMBER;
}
{digit}+    {
//    printf("INTEGER_NUMBER    %s\n", yytext);
    store_token_name("NUM", yytext, yylineno);
    yylval.integer_value = atoi(yytext);
    return INTEGER_NUMBER;
}
{metachar}        {
//    printf("META CHAR        %s\n", yytext);
    store_token_name("META CHAR", yytext, yylineno);
    return yytext[0];
}
{name}        {
//    printf("NAME        %s\n", yytext);
    store_token_name("NAME", yytext, yylineno);
    yylval.string_value = new std::string(yytext);
    return NAME;
}
"=" {
//    printf("ASSIGN\n");
    store_token_name("ASSIGN_OP", yytext, yylineno);
    return ASSIGN;
}
.   {
    printf("cs316: Error recognizing the character\n");
}
%%
