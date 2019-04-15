#ifndef ___TEST_HELPER_H__
#define ___TEST_HELPER_H__

int compare(const uint8_t *vec1, size_t size1, const uint8_t *vec2, size_t size2)
{
	size_t len = (size1 < size2)?(size2):(size1);
	size_t i;

	for (i = 0; i < len; ++i) {
		if (i < size1 && i < size2) {
			printf("0x%02x 0x%02x\n", vec1[i], vec2[i]);
			if (vec1[i] != vec2[i]) {
				printf("values are not equal!\n");
				return 1;
			}
		} else if (i < size1) {
			printf("0x%02x\n", vec1[i]);
			if (size2 + 2 <= i) {
				return 1;
			}
		} else {
			printf("     0x%02x\n", vec2[i]);
			if (size2 + 2 <= i) {
				return 1;
			}
		}
	}

	return 0;
}

#endif
