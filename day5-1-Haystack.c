#include <stdio.h>

int stripos ( char* haystack, char* needle, int offset );

int main(int argc, const char * argv[]) {
	char *topic =
		"tra treetreaaee treaeeeees treeetre colortre treetreee";
	
	char *tree_needle = "tree";
	char *tre_needle = "tre";
	char *color_needle = "color";
	char *clor_needle = "clor";
	char *s_needle = "s";
	
	int position = 0;
	
	position = stripos(topic, tre_needle, 0);
	position>0?printf("Found at index : %d\n\n",position)\
						:printf("Needle cannot be found!\n\n");
	
	position = stripos(topic, tre_needle, 11);
	position>0?printf("Found at index : %d\n\n",position)\
						:printf("Needle cannot be found!\n\n");
	
	position = stripos(topic, tree_needle, 30);
	position>0?printf("Found at index: %d\n\n",position)\
						:printf("Needle cannot be found!\n\n");
	
	position = stripos(topic, color_needle, 10);
	position>0?printf("Found at index: %d\n\n",position)\
						:printf("Needle cannot be found!\n\n");

	position = stripos(topic, clor_needle, 10);
	position>0?printf("Found at index: %d\n\n",position)\
						:printf("Needle cannot be found!\n\n");
	
	position = stripos(topic, s_needle, 40);
	position>0?printf("Found at index: %d\n\n",position)\
						:printf("Needle cannot be found!\n\n");

	
    return 0;
}

int stripos ( char* haystack, char* needle, int offset ){
	char *needle_location_backup = needle;
	int matching_postion = -1;
	int decimal_index_of_haystack = 0;
	int length_of_needle = 0;
	
	if (offset>0)
		haystack = (haystack+offset);
	
	printf("Sequence of characters in haystack :%s\n",(haystack));
	printf("Sequence of characters in needle :%s\n",(needle));
	
	while (*needle != '\0'){
		needle++;
		length_of_needle++;
	}
	needle=needle_location_backup; 
	while(*haystack != '\0'){
		if (*needle == '\0'){
			matching_postion = (decimal_index_of_haystack-length_of_needle)+offset;
			return matching_postion;
		}
		
		if (*needle == *haystack){

			needle++;
		}
		else{
			needle = needle_location_backup;
		}
		haystack++;
		decimal_index_of_haystack++;
	}

	return matching_postion;	
}
