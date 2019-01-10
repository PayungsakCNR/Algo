#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hasMajority(int a[],int size);
void sort(int vote[],int size);
int main(int argc, char const *argv[]){
	clock_t start = clock();
	int vote[] = {1,2,3,1,2,3,1,2,3,1};
	int size = (int)sizeof(vote)/(int)sizeof(vote[0]);
	int out = hasMajority(vote,size);
	printf("Size of a is %d\n", size);
	if(out == 1){
		printf("Majority!!\n");
	}
	else
		printf("No!!\n");
	clock_t stop = clock();
	double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed in ms: %f\n", elapsed);
	return 0;
}
int hasMajority(int vote[],int size){
	int i,j,count;
	sort(vote,size);
	printf("New Array: ");
	for(i=0; i<size; i++){
		printf("%d ", vote[i]);
	}
	printf("\n");
	for(i=0; i<size; i++){
		count = 0;
		for(j=0; j<size; j++){
			if(vote[i] == vote[j]){
				count++;
			}
		}
		if(count > size/2)
			return 1;
	}
	return 0;
}
void sort(int vote[],int size){
	int i,j,temp;
	for(i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
			if(vote[i] > vote[j]){
				temp = vote[i];
				vote[i] = vote[j];
				vote[j] = temp;
			}
		}
	}
}
