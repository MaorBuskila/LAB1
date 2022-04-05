#include <stdio.h>
#include <string.h>

int hexToNum(char);

int main(int argc, char **argv){
	FILE *in = stdin;
	FILE *err = stderr;
	FILE *out = stdout;
	int debug = 0;
	int addKey = 0;
	int subKey = 0;
	int encNum = 0;
	int convertCount = 0;
	int firstChar = '\0';
	int inputFile = 0;
	int outputFile = 0;
	for (int i = 1; i < argc; i++){
		if (!strcmp(argv[i], "-D")){
		debug = 1;
fprintf(stdout, "%s\n" , "debug activeted");
		}
		
		else if (!strncmp(argv[i], "+e", 2)){
			addKey = 1;
			encNum = hexToNum(argv[i][2]);
			fprintf(stdout, "%s\n" , "increase activeted");
		}
		else if (!strncmp(argv[i], "-e", 2)){
            encNum = hexToNum(argv[i][2]);
			subKey = encNum;
			fprintf(stdout, "%s\n" , "decrease activeted");
                }
		else if (!strncmp(argv[i], "-i", 2)){
			inputFile = 1;
			in = fopen(argv[i] + 2, "r");
			fprintf(stdout, "%s\n" , "input is from file");
		}
		else if (!strncmp(argv[i], "-o", 2)){
			outputFile = 1;
				fprintf(stdout, "%s\n" , "to output");
			out = fopen(argv[i] + 2, "w");
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
				encNum = subKey;
			}
			else if (encNum > 0)
				encNum --;
			else if (encNum == 0){
				if (firstChar == '\0')
					firstChar = ch;
				fprintf(out, "%c", ch);
			}
		}
		else if (addKey){
			if (firstChar == '\0')
				firstChar = ch;
			if (ch == 10){
				for (int i = 0; i < encNum; i++)
					fprintf(out, "%c", firstChar);
				firstChar = '\0';
			}
			fprintf(out,"%c", ch);
		}
		else if (ch >= 65 && ch <= 90){
			if (debug){
				fprintf(err, "%d ", ch);
				fprintf(err, "%d\n", '.');
			}
			fprintf(out, ".");
			convertCount++;
		}
		else if (ch != 10) {
			if (debug){
				fprintf(err,"%d %d\n", ch, ch);
			}
			fprintf(out, "%c", ch);
		}
		else{
			fprintf(out, "%c", '\n');
               }

	}
				if (debug){
                		fprintf(err, "the number of letters: %d\n", convertCount);
				if (in != stdin)
                                	fprintf(err, "The name of input file: %c", in);
                        	if (out != stdout)
                                	fprintf(err, "The name of output file: %c",out);
			}
	if (out != stdout)
        	fclose(out);
        if (in != stdin)
                fclose(in);
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
