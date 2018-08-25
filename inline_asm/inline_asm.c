int main()
{
	int res;

	__asm__ ("call system" 	/* asm instruction */
		: "=a" (res)   /* output */
		: "D" ("sh")); /* input : 'D' -> %edi register -> first parameter*/
	return res;
}
