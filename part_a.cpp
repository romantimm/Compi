#include <stdio.h>
#include "tokens.hpp"
#include <string>
#include <iostream>
extern int yylex();

void showToken(const char * name)
{
        printf("Lex found a %s, the lexeme is %s and its length is %d\n", name, yytext, yyleng);
}

void printExString(const char * text)
{
	std::string strText (text);
	int cnt = 0;
	bool esc_flag = false;
	std::string strTemp = "";
	for (std::string::iterator it=strText.begin()+1;
		 it!=strText.end()-1;
		 ++it){
			//We expect a escape char
			 if (esc_flag){
				strTemp += *it;
				//std::cout << strTemp << '\n';
				if (strTemp.compare("\\n") == 0) {
					std::cout << '\n';
					esc_flag = false;
					strTemp = "";
					continue;
				}
				else if (strTemp.compare("\\r") == 0) {
					std::cout << '\r';
					esc_flag = false;
					strTemp = "";
					continue;
				}
				else if (strTemp.compare("\\t") == 0) {
					std::cout << '\t';
					esc_flag = false;
					strTemp = "";
					continue;
				}
				else if (strTemp.compare("\\\\") == 0) {
					std::cout << '\\';
					esc_flag = false;
					strTemp = "";
					continue;
				}
				else if (strTemp.compare("\"") == 0) {
					std::cout << '\"';
					esc_flag = false;
					strTemp = "";
					continue;
				}
				else if (strTemp.compare("\0") == 0) {
					std::cout << '\0';
					esc_flag = false;
					strTemp = "";
					continue;
				}
			 }
			 //If got a "\" then we expect to see an escape characchter
			 if(*it == '\\') {
				//std::cout << "got an escaped slash" << '\n';
				esc_flag = true;
				strTemp += *it;
				continue;
			 }
			 std::cout << *it;
			 cnt++;
		 }
		 cnt = 0;
}

int main(){
	int token;
	while(token = yylex()) {
		if (token == NUM) {
			showToken("NUM");
		} else if (token == WORD) {
			showToken("WORD");
		} else if (token == EMAIL) {
			showToken("EMAIL");
		} else if (token == VOID) {
			showToken("VOID");
		} else if (token == INT) {
			showToken("INT");
		} else if (token == BYTE) {
			showToken("BYTE");
		} else if (token == B) {
			showToken("B");
		} else if (token == BOOL) {
			showToken("BOOL");
		} else if (token == AND) {
			showToken("AND");
		} else if (token == OR) {
			showToken("OR");
		} else if (token == NOT) {
			showToken("NOT");
		} else if (token == STRING) {
			printExString(yytext);
			showToken("STRING");
		} else if (token == NUM) {
			showToken("NUM");
		} else if (token == ID) {
			showToken("ID");
		} else if (token == TRUE) {
			showToken("TRUE");
		} else if (token == FALSE) {
			showToken("FALSE");
		} else if (token == RETURN) {
			showToken("RETURN");
		} else if (token == IF) {
			showToken("IF");
		} else if (token == ELSE) {
			showToken("ELSE");
		} else if (token == COMMENT) {
			showToken("COMMENT");
		}
	}
	return 0;
}