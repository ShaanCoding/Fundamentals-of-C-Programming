/**************************************************************
 * FileName: huffman.h
 * Description: This is huffman header file which define function
    prototype to create a HuffmanTree
 * @Author: Zhicheng Lin
 * Change Logs: 
    |Date           |Description                               |
    |2022-10-04     | Create the huffman.h
 **************************************************************/

/*******************************************************************************
 * List header files 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __MENU_H__
#define __MENU_H__
#include "menu.h"
#endif


/*******************************************************************************
 * List External variables
*******************************************************************************/
extern int __debug;
extern int __detail;

/*******************************************************************************
 * List structs
*******************************************************************************/
struct huffNode {
    char ch;
    unsigned freq;
    char hCodes[256];
    struct huffNode *left,*right;
};
typedef struct huffNode hfNode_t;

struct minHeap{
    unsigned size;
    hfNode_t **nodes;
};
typedef struct minHeap minHeap_t;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
hfNode_t* newNode(char ch, unsigned freq);
minHeap_t* newMinHeap(unsigned capcity);
void swapTwoNode(hfNode_t **node1, hfNode_t **node2);
void push(minHeap_t* heap, hfNode_t* newNode);
void bubbleDown(minHeap_t *heap, int idx);
hfNode_t * pop(minHeap_t *heap);
int countFileContent(const char fileName[],char arr[],int freq[]);
void printfStatistic(const char ch_arr[], const int ch_freq[],int size);
void printfHuffmanCode(const hfNode_t nodes[], int size);
void createStatisTable(char ch_arr[], const char arr[],int ch_freq[], const int freq[]);
hfNode_t* createAndBuildMinHeap(const char ch[],const int freq[],int size);
void mappingCode(hfNode_t *root, char arr[], int top,hfNode_t nodes[],int* pt);
hfNode_t* huffmanCodes( const char ch[],const int freq[],int size);
int encode(char fileName[],char dest[],hfNode_t nodes[],int size);
int decode(char fileName[],char dest[]);
int compress(char fileName[],char saveto[]);
void decompress(char decodeFileName[],char saveto[]);
