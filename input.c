#include <stdio.h>

int main()
{
	char username[9];
	int score;
	
	FILE *ifp, *ofp;
	ifp = fopen("test.txt", "r");
	ofp = fopen("output.txt","w");

	while (fscanf(ifp, "%s %d", username, &score) != EOF) {
		fprintf(ofp, "%s %d\n", username, score+10);
	}
	return 0;
}
