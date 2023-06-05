#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

// Install if not installed
// sudo apt install libreadline-dev


/* Todo:
	- Check if inputs are correct
		- Check if file exists
	- Tab autocompletion
	- Limit the user input to only one character for encrypt message
*/

char* getinput();

int32_t main(void){
	/*
	char input_file[256];
	printf("Enter your input file: ");
	scanf("%255s", input_file);
	while (getchar() != '\n'); //Clear buffer

	char encrypt_or_decrypt;
	printf("Enter 'e' to encrypt or 'd' to decrypt: ");
	scanf("%c", &encrypt_or_decrypt);
	while (getchar() != '\n'); //Clear buffer

	char *password;
	password = getpass("Enter password: ");
	*/

	rl_bind_key('\t', rl_complete);
	//printf("Enter your input file: ");
	//char *input_file = getinput();
	char *input_file = readline("Enter your input file: ");
	rl_unbind_key('\t');

	printf("Enter 'e' to encrypt or 'd' to decrypt: ");
	char *encrypt_or_decrypt = getinput(); 
	while( encrypt_or_decrypt[0] != 'e' && encrypt_or_decrypt[0] != 'd' ){
		printf("Enter 'e' to encrypt or 'd' to decrypt: ");
		encrypt_or_decrypt = getinput(); 
	}

	char *password;
	password = getpass("Enter password: ");

	return 0;
}

char* getinput(){
	// Need to free once done
	char *input_line = NULL; //char[]
	size_t size = 0;
	size_t return_value = getline(&input_line, &size, stdin);
	if( return_value == -1){
		return NULL; // Error getting line so return null
	}
	// Remove the last new line
	char *last_char = &(input_line)[return_value - 1];
	if( *last_char == '\n' ){
		*last_char = '\0';
	}

	return input_line;
}

void get_file_from_input(){

}
