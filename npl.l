%{
/*** C code ***/
#include <stdio.h>
void showError();
%}

/*** Regular expressions ***/
nums [0-9]+

%%
/* Flex uses the first applicable regex rule*/
{nums}   {
						/* yytest is a string containing the matched text*/
	          printf("Integer: %s\n", yytext); /*return TOKEN-TYPE;*/
				 }
.				 {showError();}

%%

void showError(){
	printf("Other input");
}
