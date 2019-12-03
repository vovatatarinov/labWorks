#include <stdio.h>
#include <stdlib.h>

int strcmp(char* a, const char* b) {
    for (int i = 0;; ++i) {
      if (a[i] != b[i])
        return 0;
      if (a[i] == '\0')
        break;
    }
    return 1;
}

void allocErr() {
    printf("Memory allocation error! Too big file?\n");
    exit(3);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Command line options: %s [Input file name] [Output file name]\n", argv[0]);
	return 0;
    }
    FILE* in = fopen(argv[1], "rb");
    FILE* out = fopen(argv[2], "wb");
    if (in == NULL) {
        printf("Can't open input file!\n");
	return 1;
    }
    if (out == NULL) {
        printf("Can't open output file!\n");
	return 2;
    }
    fseek(in, 0, SEEK_END);
    long long dataSize = ftell (in);
    fseek(in, 0, SEEK_SET);
    char* buffer = malloc(dataSize + 1);
    if (buffer == NULL)
        allocErr();
    fread(buffer, dataSize, 1, in);
    fclose(in);
    if ( (buffer[4] == ' ') || (buffer[4] == '\n') ) {
        char tmp = buffer[4];
        buffer[4] = '\0';
	if (strcmp(buffer, "file")) 
            sprintf(buffer, "%s", "ELIF");
	buffer[4] = tmp;
    }
    for (long long i = 0; i < dataSize - 5; ++i) {
        if ( ((buffer[i] == ' ') || (buffer[i] == '\n')) &&
            ((buffer[i+5] == ' ')||(buffer[i+5] == '\n'))) {
            char* str = buffer + i + 1;
            char tmp = str[4];
            str[4] = '\0';
	    if (strcmp(str, "file"))
                sprintf(str, "%s", "ELIF");
	    str[4] = tmp;
	}
    }
    if ( (buffer[dataSize - 5] == ' ') || (buffer[dataSize - 5] == '\n') ) {
            char* str = buffer + (dataSize - 4);
            char tmp = str[4];
            str[4] = '\0';
	    if (strcmp(str, "file")) {
                sprintf(str, "%s", "ELIF");
            }
            str[4] = tmp;
    }
    fwrite(buffer, dataSize, 1, out);
    fclose(out);
    return 0;
}
