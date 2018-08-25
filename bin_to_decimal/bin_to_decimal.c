int bin_to_decimal(char *bin)
{
	int x = 0;

	while (*bin != '\0') {
		x <<= 1;
		if (*bin == '1')
			x++;
		bin++;
	}
	return x;
}
