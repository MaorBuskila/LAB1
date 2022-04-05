#include <stdio.h>
#include <string.h>
int hexToNum(char);

int main(int argc, char ** argv){
	FILE* in = stdin;
	FILE* out = stdout;
	char ch;
	int toFile =0;
	int fromFile = 0;
	int  debug = 0;
	int encSub = 0;
	int encSubb =0;
	int encAdd = 0;
	int converted = 0;
	char firstChar = '\0';
	if (argc >1){
		for(int arg = 1; arg < argc; arg ++){
			if(strcmp(argv[arg], "-D") == 0){
				printf("debug enabled\n ");
				debug = 1;
			}else if(strncmp(argv[arg], "-e", 2) == 0){
				printf("decrease enabled\n ");
				encSub =  hexToNum(argv[arg][2]);
				encSubb = encSub;
			}else if(strncmp(argv[arg], "+e", 2) == 0){
				printf("increase enabled\n ");
				encAdd = hexToNum(argv[arg][2]);
			}
			else if(strncmp(argv[arg], "-i", 2) == 0){
				printf("input is read from file\n");
				in = fopen(argv[arg]+2,"r");
				fromFile =1;
			}else if(strncmp(argv[arg], "-o", 2) ==0){
				printf("to file");
				out = fopen(argv[arg]+2, "w");
				toFile =1;
			}
		}
	}
	while((ch=fgetc(in)) != EOF){
		if(encSub ==0){
		if ((encAdd == 0) && (encSubb == 0)){
			if(debug && (ch != 10))
				fprintf(stderr ,"%d ", ch);
			if(ch >='A' && ch< 'Z'){
				if(debug)
					fprintf(stderr, "46\n");
				fprintf(out,".");
				converted++;
			}else{
				if(debug && (ch != 10)){
					fprintf(stderr, "%d", ch);
					fprintf(stderr, "\n");
				}
				fprintf(out ,"%c", ch);
			}
		}else{
			if (firstChar == '\0')
				firstChar = ch;
			if (ch == 10){
				for(int charToAdd =1 ; charToAdd <=encAdd ;charToAdd++){
					fprintf(out ,"%c" ,firstChar);
				}
				firstChar = '\0';
			}
			fprintf(out ,"%c", ch);
		}
		}else{
			encSub--;
		}
	}
	if(debug){
		fprintf(stderr, "number of added letters : %d\n", encAdd);
		fprintf(stderr, "number of removed letters: %d\n" , encSubb);
		fprintf(stderr, "number of converted letters: %d\n", converted);
	}
	if(toFile){
		fclose(out);
	}
	if(fromFile){
		fclose(in);
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