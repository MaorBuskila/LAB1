#include <stdio.h>
#include <string.h>
int hexToNum(char);
int main(int argc, char ** argv){
	FILE *in = stdin;
	FILE *err = stderr;
	FILE* out = stdout;
	int debug = 0;
	int encSub =0;
	int encAdd = 0;
	int converted = 0;
	char firstChar = '\0';
	int subKey =0;
	int addKey =0;
	int arg;
	if (argc >1){
		for(arg = 1; arg < argc; arg ++){
			if(strcmp(argv[arg], "-D") == 0){
				fprintf(err,"%s\n","debug enabled");
				debug = 1;
			}
			else if(strncmp(argv[arg], "-e", 2) == 0){
					fprintf(err,"%s\n","decrease enabled");
				subKey =  hexToNum(argv[arg][2]);
				encSub = subKey;
			}else if(strncmp(argv[arg], "+e", 2) == 0){
				fprintf(err,"%s\n","increase enabled");
				addKey = hexToNum(argv[arg][2]);
				encAdd = addKey;
			}
		}
	}
char ch;
	while ((ch = fgetc(in)) != EOF){
		if (subKey){
			if (ch == 10){
				if (firstChar == '\0')
					fprintf(out, "-NONE-\n");

				else{
					firstChar = '\0';
					fprintf(out, "\n");
				}
				encSub = subKey;
			}
			else if (encSub > 0)
				encSub --;
			else if (encSub == 0){
				if (firstChar == '\0')
					firstChar = ch;
				fprintf(out, "%c", ch);
			}
		}
        if (addKey){
            if (firstChar == '\0')
                firstChar = ch;
            if (ch == 10){
                for (int i = 0; i < encAdd; i++)
                    fprintf(out, "%c", firstChar);
                firstChar = '\0';
            }
            fprintf(out,"%c", ch);
        }
        if(ch >= 'A' && ch <= 'Z'){
            if (debug) {
                fprintf(err, "%d %d\n", ch, '.');
            }
        } else if (ch != 10) {
            if (debug) {
                fprintf(err, "%d %d\n", ch, ch);
            }
		if (subKey == 0 && addKey == 0){
                fprintf(stdout,"%c" , '.');
                converted++;
            }
        }
	}
    fprintf(stdout,"%c", '\n');
	if(debug){
		fprintf(stderr, "number of added letters : %d\n", encAdd);
		fprintf(stderr, "number of removed letters: %d\n" , encSub);
		fprintf(stderr, "number of converted letters: %d\n", converted);
	}
	return 0;
}

int hexToNum(char ch){
	int num = 0;
	if (ch >= '1' && ch <= '9')
		num = ch - 0x30;
	if (ch >= 'A' && ch <= 'F')
		num = ch - 0x37;
	return num;
}
