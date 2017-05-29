#include "algorithms.h" 

int main(void) {

	char thing[] = "William Shakespeare", thing2[] = "I am a weakish speller";
	int status = is_anagram(thing, thing2);
	printf("Status: %d\n", status);
	
	return 0;
}
