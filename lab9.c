#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 100;

// RecordType
struct RecordType
{
	int		id;
	char	name;
	int		order; 
};
struct Node{
	struct RecordType data;
	struct Node *next;
};
// Fill out this structure
struct HashType
{
	struct Node *head;
};

// Compute the hash function
int hash(int x)
{
	return x % HASHSIZE;
}
//new record into hash table
void insert(struct HashType hashTable[], struct RecordType record){
	int index = hash(record.id);

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = record;
	newNode->next = NULL;

	if(hashTable[index].head == NULL){
		hashTable[index].head = newNode;
	}
	else{
		struct Node *cur = hashTable[index].head;
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = newNode;
	}

}
//displey records
void displayRecordsinHash(struct HashType hashTable[], int hashSize){
	for( int i = 0 ; i < hashSize; ++i){
		printf("Index %d ->", i);
		struct Node *cur = hashTable[i].head;
		while (cur != NULL){
			printf("%d %c %d -> ", cur -> data.id, cur ->data.name, cur ->data.order);
			cur = cur -> next;
		}
		printf("\n");
	}
}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (struct RecordType*) malloc(sizeof(struct RecordType) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

// display records in the hash structure
// skip the indices which are free
// the output will be in the format:
// index x -> id, name, order -> id, name, order ....
void displayRecordsInHash(struct HashType *pHashArray, int hashSz)
{
	int i;

	for (i=0;i<hashSz;++i)
	{
		// if index is occupied with any records, print all
	}
}

int main(void)
{
	struct RecordType *pRecords;
	int recordSz = 0;

	recordSz = parseData("input.txt", &pRecords);
	printRecords(pRecords, recordSz);
	// Your hash implementation
}