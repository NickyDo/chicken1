#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

void main(int argc, char *argv[]) {
	FILE* f1;
	FILE* f2;
	int dem[max], count = 0;
	char a[max], b[max];
	int fi = max;
	int t1, t2;

	if ((f1 = fopen(argv[1], "r")) == NULL)	printf("Can't open this file\n");		
	else if ((f2 = fopen(argv[2], "r")) == NULL)printf("Can't open this file\n");
	else{
	for (int i = 0; i < max; ++i)
		dem[i] = 0;
	printf("Nhung dong ma file %s va %s khac nhau la:\n", argv[1], argv[2]);
	while (!feof(f1) || !feof(f2)) {
		t1 = fscanf(f1, "%[^\n]\n", a);
		t2 = fscanf(f2, "%[^\n]\n", b);
		if (strcmp(a, b) != 0 || t1 != t2)
		{
			dem[count] = 1;
			printf("Dong cua file thu nhat: %s\tDong cua file thu hai: %s\n", t1 == 1?a : "\0", t2 == 1?b: "\0");
		}
		t1 = -1;
		t2 = -1;
		count++;
	}
	for (int i = 0; i <= count; ++i)
		if (dem[i] == 1)
		{
			if (i < fi)
				fi = i;
		}
	printf("Dong dau tien ma file %s va %s khac nhau la dong thu: %d\n", argv[1], argv[2], fi + 1);
	fclose(f1);
	fclose(f2);
	}
}
//Note: write a program to  compare two files given as the command parameters and indicates:
//+The fist line where they differ(line numbers).
//+All lines where they differ.
