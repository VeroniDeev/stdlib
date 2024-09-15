/// wries the textual version of `val` into ptr
/// returns the start of the written text it will write from backwards
int itoa(int val, char ptr[10]) {
	int i = 9;
	for (; i != 0; i--) {
		int ch = val % 10;
		val /= 10;
		ptr[i] = ch + '0';

		if (val == 0) {
			break;
		}
	}

	return i;
}
