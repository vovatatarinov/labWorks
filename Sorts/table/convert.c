#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* out;
	FILE* in;
	out = fopen("table_rus.csv", "wb");
	in = fopen("table.csv", "rb");
	fseek(in, 0, SEEK_END);
	int dataSize = ftell(in);
	fseek(in, 0, SEEK_SET);
	char* buffer = (char*)malloc(dataSize);
	fread(buffer, dataSize, 1, in);
	fclose(in);
	for (int i = 0; i < dataSize; ++i)
		if (buffer[i] == '.')
			buffer[i] = ',';
	fwrite(buffer, dataSize, 1, out);
	fclose(out);
}