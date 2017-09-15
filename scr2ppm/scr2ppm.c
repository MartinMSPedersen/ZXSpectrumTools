#include <stdlib.h>
#include <stdio.h>

void ppm_header() {
    printf("P6\n");
    printf("256 192\n");
}

int main(int argc, char* argv[]) {
    const char *input_filename = argv[1];
    FILE *f;
    int data_len;
    unsigned char *data_points;
    unsigned char *data_attrs;
    int attr_pos;
    int points_pos;

    if (argc < 2) {
	fprintf(stderr, "Missing scr-file argument\n");
	return EXIT_FAILURE;
    }

    f=fopen(input_filename,"r");
    if (f == NULL) {
	fprintf(stderr, "Error opening file: %s\n", input_filename);
	return EXIT_FAILURE;
    }
    fseek(f, 0, SEEK_END);
    data_len = ftell(f);
    fseek(f, 0 , SEEK_SET);
    if (data_len != 6912) {
	fprintf(stderr, "Wrong size of scr-file.\n");
	return EXIT_FAILURE;
    }
    data_points = (char *)malloc(256*192);
    data_attrs  = (char *)malloc(32*24);

    fread(data_points, 1, 256*192, f);
    fread(data_attrs, 1, 32*24, f);

    int value;
    for (int i = 0; i <= 4096; i+=2048) {
	for (int j = 0; j < 64; j++) {
	    for (int k = 0; k < 256; k++) {
		points_pos = i + (int)k/8 + 256*(int)j/8;
		value = data_points[points_pos];
		printf("%d %d\n", points_pos, value);
	    }
	}
    }

    ppm_header();

    return EXIT_SUCCESS;
}
