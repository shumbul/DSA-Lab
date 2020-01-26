#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int n; 
	puts("Enter the number of characters");
	scanf("%d", &n);
	unsigned int s = (int)(pow(2, n));
	char a[n];
	puts("Enter the characters");
	for(int i = 0; i < n; i++)
		scanf(" %c", &a[i]);

	char c[s][n+1];

	/*
Each alphabhet can either be present or not. 
So, 1 or 0.
"i" represents that in a binary form. 
"j" is taken as a counter to ensure that the condition for the sequence is satisfied
        */
	for(int i = 1; i <= s; i++)
	 {
		int k = 0;
		for(int j = 0; j < n; j++)
		 {
			if(i & (1<<j))
			 {
				c[i-1][k] = a[j];
				k++;
				c[i-1][k] = '\0';
		       	}
		}
	}
	for(int i = 0; i < s-2; i++) {
		for(int j = i+1; j < s-1; j++) {
			if(strcmp(c[i], c[j]) >= 0) {
				char t[26]={0};
				strcpy(t, c[j]);
				strcpy(c[j], c[i]);
				strcpy(c[i], t);
			}
		}
	}
	puts("Enter the string whose index is to be found");
	char user[n];
	scanf("%s", user);
	for(int i = 0; i < s-1; i++) {
		if(strcmp(user, c[i]) == 0) {
			printf("The string has position %d\n", 1+i);
			break;
		}
	}
}
