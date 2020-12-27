#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>

#include <iostream>

#include <string.h>

void ClearString(char string[255]) {

	int i;

	for (i = 0; i < 255; i++) { string[i] = '\0'; }
}

int main(int argc, char* argv[]) {

	char str[255], s[255] = "", t[255] = "", c; bool r;

	int i = 0, j = 0;

	printf("Enter text>"); gets_s(s);

	strcpy(str, "");

	do {
		r = false;

		do {
			c = s[i]; i++;

			if (c > '9') { r = true; }

			if (c == ' ' || c == '.' || c == '\0') {

				if (t[0] > '9') {
					if (r) {

						strcat(str, t); strcat(str, " ");
					}

				} t[j] = '\0';

				j = 0; ClearString(t); break;
			}

			else { t[j] = c; j++; }

		} while (1);

	} while (c != '.' && c != '\0');

	printf("Right identifiers:\n");

	puts(str);

	system("PAUSE");

	return EXIT_SUCCESS;
}