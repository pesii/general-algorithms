#include "algorithms.h"

#define ASCII_65 65
#define ASCII_90 90
#define ASCII_97 97
#define ASCII_122 122
#define UPPER_TO_LOWER 32

#define ANAGRAM 1
#define NOT_ANAGRAM 0

typedef struct occurence {
	int count[26];
} Occurence;


/*
 * Returns the length of the input string
 */
int strLength(char strFeed[]){
	int length=0;
	for(int i=0; strFeed[i] != '\0'; i++){
		length = i+1;
	}

	return length;
}

/* 
 * puncStrip() removes punctuation from ASCII 32-47, 58-64, 91-96, 123-127
 * Any ASCII in the range 65-90 would be converted to its equivalence in 97-12
 * I absolutely have no idea why I had puncStrip return a string. That was pain in the arse.
 */
void puncStrip(char stringFeed[]){
	int i = 0, j = 0;
	while(stringFeed[i] != '\0') {
		if ((stringFeed[i] >= ASCII_65) && (stringFeed[i] <= ASCII_90)) {
			stringFeed[j] = stringFeed[i] + UPPER_TO_LOWER;
			j++;
		} else if ((stringFeed[i] >= ASCII_ALPHABET_a) && (stringFeed[i] <= ASCII_ALPHABET_z)) {
			stringFeed[j] = stringFeed[i];
			j++;
		}
		i++;
	}
	stringFeed[j] = '\0'; // Recalibrating the end of string after changing its contents
}

/*
 * Returns 0 if NOT an anagram,
 * otherwise returns 1 if stringFeed and stringCompare are anagrams
 */
int is_anagram(char *stringFeed, char *stringCompare) {
	Occurence input, output;	
	puncStrip(stringFeed);
	puncStrip(stringCompare);

	/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
	/* Pitiful way of initializing all the elements in count array
	 */
	for(int initialize = 0; initialize < 26; initialize++){
		input.count[initialize] = 0;
		output.count[initialize] = 0;
	}
	/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

	if (strLength(stringFeed) != strLength(stringCompare)){
		return NOT_ANAGRAM; // not an anagram if parsed string are not same length
	} else {
		int i = 0;
		
		while (i < strLength(stringFeed)){
			input.count[stringFeed[i]-97] += 1;
			output.count[stringCompare[i]-97] += 1;
			i++;
		}
		
		for (i = 0; i<26; i++){
			if(input.count[i] == output.count[i]){
			} else {
				return NOT_ANAGRAM;
			}
		}

	}

	return ANAGRAM;

}
