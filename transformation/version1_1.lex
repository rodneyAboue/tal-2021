%%
%class lexer
%unicode
%int
%standalone //debug ou standalone
%line
%column

comments = "/"{2}.*
pack= "package"
func = "func"
import = "import"
for = "for"
if = "if"
go = "go"
main = "main"
int = "int"
const = "const"
println = "Println"
string = "string"
var = "var"
sync = "sync"
done = "Done"
range = "range"
len = "len"
else = "else"
struct = "struct"
type = "type"
wait ="Wait"
waitGroup = "WaitGroup"
add = "Add"

number = [0-9]+
variable =[a-z\_][a-zA-Z0-9\_]*

%%
"="			{ System.out.print(yytext()); }
"["			{ System.out.print(yytext()); }
"]"			{ System.out.print(yytext()); }
[\"]		{ System.out.print(yytext()); }
"-"			{ System.out.print(yytext()); }
"+"			{ System.out.print(yytext()); }
"/"			{ System.out.print(yytext()); }
"*"			{ System.out.print(yytext()); }
":"			{ System.out.print(yytext()); }
"<"			{ System.out.print(yytext()); }
">"			{ System.out.print(yytext()); }
"."			{ System.out.print(yytext()); }
","			{ System.out.print(yytext()); }
"("			{ System.out.print(yytext()); }
")"			{ System.out.print(yytext()); }
"{"			{ System.out.print(yytext()); }
"}"			{ System.out.print(yytext()); }
";"			{ System.out.print(yytext()); }
" "			{ System.out.print(" "); }
"&"			{ System.out.print(yytext()); }

{wait}		{ System.out.print(yytext()); }
{waitGroup}	{ System.out.print(yytext()); }
{add}		{ System.out.print(yytext()); }
{else}		{ System.out.print(yytext()); }
{done}		{ System.out.print(yytext()); }
{sync}		{ System.out.print(yytext()); }
{range}		{ System.out.print(yytext()); }
{len}		{ System.out.print(yytext()); }
{struct}	{ System.out.print(yytext()); }
{type}		{ System.out.print(yytext()); }
{var}		{ System.out.print(yytext()); }
{var}		{ System.out.print(yytext()); }
{number}	{ System.out.print(yytext()); }
{comments}	{}
{pack}		{ System.out.print(yytext()); }
{func}		{ System.out.print(yytext()); }
{import}	{ System.out.print(yytext()); }
{for}		{ System.out.print(yytext()); }
{if}		{ System.out.print(yytext()); }
{go}		{ System.out.print(yytext()); }
{main}		{ System.out.print(yytext()); }
{int}		{ System.out.print(yytext()); }
{const}		{ System.out.print(yytext()); }
{println}	{ System.out.print(yytext()); }
{string}	{ System.out.print(yytext()); }
{variable}	{ System.out.print(yytext()); }
[\n]*		{ System.out.println();}
[\t]		{ System.out.print("\t");}
.			{ System.out.print("chaine: "+yytext()); }

