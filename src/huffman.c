/**************************************************************
 * FileName: huffman.c
 * Description: This is huffman  file which implement the method
   to create a HuffmanTree
 * @Author: Zhicheng Lin
 * Change Logs: 
    |Date           |Description                               |
    |2022-10-04     | Create the huffman.c                     |
    |2022-10-10     | upload the initial huffman comproess     |
    |2022-10-10     | upload the initial huffman decomporess   |
    |2022-10-10     | add debug mode for decoding and encoding |
    |2022-10-15     | Optimated the comproess and decomporess  |
 **************************************************************/

#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__
#include "huffman.h"
#endif

/******************************************************************************
 * This function will create a HuffmanNode base on a char and frequency. 
 * inputs:
 *     - ch: char -> the char of huffmanCodes 
       - freq: int -> the frequency of this ch appear in a file.
 * outputs:
 *     - Huffman Node pointer: return the node address.
 *****************************************************************************/

hfNode_t* newNode(char ch, unsigned freq){

  hfNode_t * temp = (hfNode_t *)malloc(sizeof(hfNode_t));
  temp->ch = ch;
  temp->left = NULL;
  temp->right = NULL;
  temp->freq = freq;
  return temp;
}


/******************************************************************************
 * create a min heap that size is "capity" parameter
 * inputs:
 *     - capity: the size of min heap
 * outputs:
 *     - minHeap_t*: the root of minHeap;
 *****************************************************************************/
minHeap_t* newMinHeap(unsigned capcity){
  minHeap_t * minHeap = (minHeap_t*) malloc(sizeof(minHeap_t));
  minHeap->size=0;
  minHeap->nodes = (hfNode_t **)malloc(capcity*sizeof(hfNode_t *));
  return minHeap;
}

/******************************************************************************
 * swap two huffman Nodes
 * inputs:
 *     - node1: hfNode_t  node1 
 *     - node2: hfNode_t
 * outputs:
 *     - none
 *****************************************************************************/
void swapTwoNode(hfNode_t **node1, hfNode_t **node2){
  hfNode_t *temp = *node1;
  *node1 = *node2;
  *node2 = temp;
}


/******************************************************************************
 * push a new node into heap
 * inputs:
 *     - heap: the heap that node will be added
 *     - newNode: the node will be added into heap
 * outputs:
 *     - none
 *****************************************************************************/

void push(minHeap_t* heap, hfNode_t* newNode){

  (heap->size) += 1;
  int idx = heap->size-1;

  /*Bubble up, maintain the min heap order*/
  while(idx && newNode->freq <= (*heap).nodes[(idx-1)/2]->freq){
    (*heap).nodes[idx] = (*heap).nodes[(idx-1)/2];
     idx = (idx-1)/2;
  }

  (*heap).nodes[idx] = newNode;

}

/******************************************************************************
 * Bubble Down, maintain the min heap oder.
 * inputs:
 *     - heap: the root of heap, which will be operated.
 *     - the idx of node 
 * outputs:
 *     - none
 *****************************************************************************/
void bubbleDown(minHeap_t *heap, int idx){
    int smallest = idx;
    int size = heap->size;
    int leftIdx = 2*idx+1;
    int rightIdx = 2*idx+2;
    if(leftIdx<size && heap->nodes[leftIdx]->freq <= heap->nodes[smallest]->freq){
      smallest = leftIdx;
    }
      
    if(rightIdx < size && heap->nodes[rightIdx]->freq <= heap->nodes[smallest]->freq){
      smallest = rightIdx;
    }

    if(smallest !=idx){
      swapTwoNode(&heap->nodes[smallest],&heap->nodes[idx]);
      bubbleDown(heap,smallest);
    }  
}



/******************************************************************************
 * Pop a min node from heap
 * inputs:
 *     - heap: the heap that node will be added
 * outputs:
 *     - HfNode_t: the samllest node from heap.
 *****************************************************************************/

hfNode_t * pop(minHeap_t *heap){
    hfNode_t * temp = heap->nodes[0];
    int lastIdx = heap->size-1;
    heap->nodes[0] = heap->nodes[lastIdx];
    heap->size -=1;
    bubbleDown(heap,0);
    return temp;
}



/******************************************************************************
 * count a file, make a statistics about ch and its frequency
 * this function will use freq[(int)ch]++ to count the frequency of character
 * Thus, the length of arr and freq is 255.
 * inputs:
 *     - filename: char[]: the filename of file that willed be counted
 *     - the ch containers to store all the character that appear in files.
 *     - the frequency of each ch.
 * outputs:
 *     - int: the count of each character in the file character
 *****************************************************************************/

int countFileContent(const char fileName[],char arr[],int freq[]){
    if(__debug){
        printfPrompt("Huffman.c ->countFileContent() start\n");
    } 
   /* read file*/
    FILE * fp = NULL;
    fp = fopen(fileName,"r");
    if(fp==NULL){
      printfError("Not such file!");
      return -1;
    }

    fseek(fp,0,SEEK_END);
    int len = ftell(fp)-1;
    fseek(fp,0,SEEK_SET);
    int chOfNum = 0,i;
    char c;
    for(i=0;i<len;i++){
      fread(&c,sizeof(char),1,fp);
      int idx = (int)c;
      if(freq[idx]==0){
        chOfNum++;
      }
      freq[idx] +=1;
      arr[idx]=c;
    }
    fclose(fp);

    
    fp=NULL;
    if(__debug){
        printfPrompt("Huffman.c ->countFileContent() end\n");
    } 
    return chOfNum;
}


/******************************************************************************
 * Likes the description of countFileContent, the length of arr and freq is 255
 * so this function is to remove some 
 * inputs:
 *     - arr: char[] -> the 255 length of char array
 *     - freq: int[] -> the 255 length of int array that contains all the frequency of each character.
 *     - ch_arr: char[]-> Reduced array， only contains the character that appeared in the file
 *     - ch_freq: char[] -> Reduced array， only contains the frequency of appeared character in the file.
 * outputs:
 *     - int: the count of each character in the file character
 *****************************************************************************/

void createStatisTable(char ch_arr[], const char arr[],int ch_freq[], const int freq[]){
    if(__debug){
        printfPrompt("Huffman.c ->createStatisTable() start\n");
    } 
    int i,j =0;
    for(i=0;i<256;i++){
      if(freq[i]>0){
        ch_freq[j] = freq[i];
        ch_arr[j] = arr[i];
        j++;
      }
    }
    if(__debug){
        printfPrompt("Huffman.c ->createStatisTable() end\n");
    } 
}

/******************************************************************************
 *this function draw the huffman heap according to the frequency table
 * using heap, pop and push, to build a huffman tree, and return a root node.
 * so this function is to remove some 
 * inputs:
 *     - ch: char[]: the frequency character
 *     - freq: int[]: the frequency of each character
 * outputs:
 *     - a root node of huffman tree.
 *****************************************************************************/
hfNode_t* createAndBuildMinHeap(const char ch[],const int freq[],int size){
  if(__debug){
     printfPrompt("Huffman.c ->createAndBuildMinHeap() start\n");
  } 
  minHeap_t *heap = newMinHeap(size);
  int i;
  for(i=0;i<size;i++){
    push(heap,newNode(ch[i],freq[i]));
  }

  while(heap->size >1){
    hfNode_t *left = pop(heap);
   
    hfNode_t *right = pop(heap);

    hfNode_t *node = newNode('$',left->freq+right->freq);
    node->left = left;
    node->right = right;
    push(heap,node);
  }
  return pop(heap);
}


/******************************************************************************
 *this function will generate huffman codes for every character based on huffman tree.
 * left child is 0, right child is 1
 * 
 * inputs:
 *     - root: hfNode_t *: the root node of huffman tree
 *     - arr: char[] -> huffmanCode-> all values are 0 or 1 based on the node position.
 *     - top: int -> the index of each node,
 *     - nodes:hfNode_t[]: huffman statistics table 
 *     - pt: int*: store the huffman leaf number. every leaf is character, and its code is huffman code for this letter.
 * outputs:
 *     - none
 *****************************************************************************/
void mappingCode(hfNode_t *root, char arr[], int top,hfNode_t nodes[],int* pt){
  if(root->left){
     arr[top] = '0';
     mappingCode(root->left,arr,top+1,nodes,pt);
  }
  if(root->right){
      arr[top] = '1';
       mappingCode(root->right,arr,top+1,nodes,pt);
  }
  /* leave*/
  if(!(root->left) && !(root->right)){
     arr[top] ='\0';
     nodes[*pt].ch = root->ch;
  
     nodes[*pt].freq = root->freq;
     strcpy(nodes[*pt].hCodes,arr);
     (*pt)++;
  }

  if(__debug){
     printfPrompt("Huffman.c ->createAndBuildMinHeap() end\n");
  } 

}

hfNode_t* huffmanCodes( const char ch[],const int freq[],int size){
  hfNode_t * root = createAndBuildMinHeap(ch,freq,size);
  char arr[50], top = 0; 
  hfNode_t* nodes= (hfNode_t *) malloc(sizeof(hfNode_t)*size);
  int pt =0;
  mappingCode(root,arr, top,nodes,&pt);
  return nodes;
}


/******************************************************************************
 * This method moves the string forward a few positions
 * 
 * inputs:
 *    - strs[]: char[] -> the string will be moved.
 *    - num: int -> the number of this function should move
 * outputs:
 *     - none
 *****************************************************************************/
void moveStr(char strs[],int num){
  int length = strlen(strs);
  int i;
  for(i=num;i<length;i++){
    strs[i-num] = strs[i];
  }
  strs[length-num]='\0';
}


/******************************************************************************
 * This method encode a file by huffman encoding.
 * 
 * inputs:
 *    - fileName -> the file path that will be encoded.
 *    - dest -> the encoded file will stroe in dest path.
 *    - nodes[] -> used to convert a char into huffmanCode 
 *    - size -> the number of distinc character of this file
 * outputs:
 *     - a integer, if encode success, return 1, otherwise return 0
 *****************************************************************************/
int encode(char fileName[],char dest[],hfNode_t nodes[],int size){
    if(__debug){
      printfPrompt("Huffman.c ->encode() start\n");
    }     
    int i,j,f;
    FILE * fp = NULL;
    FILE* dest_fp = NULL;

    /* access file*/
    fp = fopen(fileName,"r");
    dest_fp = fopen(dest,"w");
    if(fp==NULL){
      if(__debug){
        printfError("File open failed, huffman.c -> encode()\n");
      }
           
    
      printfError("Source file open fail! - Encode process");
      return 0;
    }
    if(dest_fp==NULL){
      if(__debug){
        printfError("File open failed, huffman.c -> encode()\n");
      }   
      printfError("Destination file open fail! - Encode process");
      return 0;
    }


    fseek(fp,0,SEEK_END);
    int filelength = ftell(fp);
    fseek(fp,0,SEEK_SET);
    fseek(dest_fp,9,SEEK_SET);

    unsigned char c;
    char temp[128];
    temp[0] = '\0';

    /* Convert every bytes to huffmanCode and stroe in file.*/
    for(i=0;i<filelength-1;i++){
      fread(&c,sizeof(char),1,fp);
   
      for(j=0;j<size;j++){
        if(nodes[j].ch==c){
          strcat(temp,nodes[j].hCodes);
          break;
        }
      }

     if(strlen(temp)>=8){
       c=0;
       for(j=0;j<8;j++){
         c = c<<1;
         if(temp[j]=='1'){
           c+=1;
         }
       }
       fwrite(&c,sizeof(char),1,dest_fp);
       moveStr(temp,8);
       
     }
    }
         
    if(strlen(temp)<8){
      c=0;
      for(i=0;i<8;i++){
          c = c<<1;
         if(temp[i]=='1'){
           c+=1;
         }
      }
      fwrite(&c,sizeof(char),1,dest_fp);
    }


    /*   Store the encoding parameter
    *    filelength
    *    Anchor -> the encoding content end, after anchor, we will stroe the huffman nodes data
    */
    int anchor = ftell(dest_fp);
    fseek(dest_fp,0,SEEK_SET);
    fwrite(&filelength,sizeof(int),1,dest_fp);
    fwrite(&anchor,sizeof(int),1,dest_fp);
    unsigned char fileMode = 1;
    fwrite(&fileMode,sizeof(char),1,dest_fp);
    fseek(dest_fp,0,SEEK_END);
    fwrite(&size,sizeof(int),1,dest_fp);
    
    /*Store huffman nodes data into file*/
    for(i=0;i<size;i++){
       fwrite(&nodes[i].ch,sizeof(char),1,dest_fp);
       j = strlen(nodes[i].hCodes);
       fwrite(&j,sizeof(char),1,dest_fp);
       if(j%8 != 0){
         for(f=j%8;f<8;f++){
           strcat(nodes[i].hCodes,"0");           
         }
       }
       c=0;
       for(f=0;f<strlen(nodes[i].hCodes);f++){ 
         c=c<<1; 
         if(nodes[i].hCodes[f]=='1'){
           c+=1;
         }
           if((f+1)%8==0){
             fwrite(&c,sizeof(char),1,dest_fp);
             c=0;
           }
       }
    }
    
    fclose(fp);
    fclose(dest_fp);
    if(__debug){
      printfPrompt("Huffman.c ->encode() end\n");
    }   
    return 1;
}



/******************************************************************************
 * This method will decode of a compressed file
 * inputs:
 *    - filename: the filepath of comporessed data.
 *    - dest: the destination of file.
 * outputs:
 *     - return 1 if decode sucessfully,otherwise return 0
 *****************************************************************************/
int decode(char fileName[],char dest[]){
    /* access file*/
    if(__debug){
      printfPrompt("Huffman.c ->decode() start\n");
    }   
     FILE * fp = NULL;
    fp = fopen(fileName,"r");

    if(fp==NULL){
      if(__debug){
        printfError("File open failed, huffman.c -> decode()\n");
      }
      printfError("Source file open fail!- Decode process");
      return 0;
    }
   
    int filelength,pt,n;
    char codelength,len;
    char ch;
    unsigned char c=0;
    char temp[128];
    temp[0]='\0';

    /*read compressed file parameter
     * filelenth: the length of original file
     * pt: the start index of huffman tree data.
     * fileMode: indicate the file is comporessed file or not, if filemodel = 1, 
     *             means this file can be decompressedn
     * n: the number of huffmanNode
     */
    fread(&filelength,sizeof(int),1,fp);
    filelength--;
    fread(&pt,sizeof(int),1,fp);
    char fileMode;
    fread(&fileMode,sizeof(char),1,fp);
    
    if(fileMode!=1){
      printfError("This file is not compressed file!");
      return 0;
    }

    fseek(fp,pt,SEEK_SET);
    fread(&n,sizeof(int),1,fp);


    /*read huffman tree from decomporessed file*/
    hfNode_t* nodes= (hfNode_t *) malloc(sizeof(hfNode_t)*n);
    int i =0,j,f;
   
    for(f=0;f<n;f++)
    {
      fread(&ch,sizeof(char),1,fp);
          
      fread(&codelength,sizeof(char),1,fp);
      len=codelength;
      for(i=0;i<(codelength-1)/8+1;i++){

          fread(&c,sizeof(char),1,fp);  
          for(j=0;j<8;j++){
            if(len<=0) break;
            len--;
            if(c>>7 ==0){
              strcat(temp,"0");
            }else{
              strcat(temp,"1");
            }
            c=c<<1;
          }          
      }
      
      nodes[f].ch = ch;
      nodes[f].hCodes[0]='\0';
      strcat(nodes[f].hCodes,temp);
      moveStr(temp,codelength);
       
    }
    /*Debug mode, draw the huffman code*/
    if(__detail){
       printfHuffmanCode(nodes,n);     
    }

    fseek(fp,4,SEEK_SET);
    fread(&pt,sizeof(int),1,fp);
    fread(&fileMode,sizeof(char),1,fp);

   
    FILE* outp = fopen(dest,"w");
    if(outp==NULL){
      if(__debug){
          printfError("File open failed, huffman.c -> decode()\n"); 
      }
      printfError("Destination file open fail!- DecodeProcess");
      return 0;
    }
    int count=0;
    /*read from decompressed file, decode each bytes based on huffman tree*/
    for(i=8;i<pt;i++){
      fread(&c,sizeof(char),1,fp);
      for(j=0;j<8;j++){
        if(c>>7==1){
          strcat(temp,"1");
        }else{
          strcat(temp,"0");
        }
        c=c<<1;
        count++;   
        for(f=0;f<n;f++){
          if(strcmp(temp,nodes[f].hCodes)==0 &&filelength>0){
             
              filelength--;
              
              fwrite(&nodes[f].ch,sizeof(char),1,outp);
              moveStr(temp,count);
              count=0;
              break;
          }
        }
      }

    }
   
   fclose(fp);
   fclose(outp);
    if(__debug){
      printfPrompt("Huffman.c ->decode() end\n");
    }   
   return 1;
}


/******************************************************************************
 * This method will print the huffman code of characters
 * inputs:
 *    - nodes[]: the array of huffmanNode
 *    - size: the size of array
 * outputs:
 *     - none
 *****************************************************************************/
void printfHuffmanCode(const hfNode_t nodes[], int size){
  if(size==0){
    return;
  }
  drawMenuTableHeader("Huffman Codes Mapping Table");
  int i;
  for(i=0;i<size;i++){
    char temp[512];
    temp[0]='\n';
    char ch = nodes[i].ch;
    if(ch=='\n'){
      sprintf(temp, "ch=\\n %*s|        CODES=%s",15," ",nodes[i].hCodes);
    }else{
      sprintf(temp, "ch=%c  %*s|        CODES=%s", ch,15," ",nodes[i].hCodes);
     }
        
    drawBody(temp);
        
    }
    drawBottomLine();
    
  
}

/******************************************************************************
 * This method will printf the file statistics
 * inputs:
 *    - ch_arr -> characters appear in a file
 *    - ch_freq -> the frequency of a character in a file
 *    - size -> the size of characters
 * outputs:
 *     - none
 *****************************************************************************/
void printfStatistic(const char ch_arr[], const int ch_freq[],int size){
  if(size==0){
    return;
  }
    drawMenuTableHeader("File Statistics");
    int i;

    for(i=0;i<size;i++){
        char temp[200];
        temp[0]='\n';
        char ch = ch_arr[i];
        if(ch=='\n'){
          sprintf(temp, "ch=\\n %*s|        freq=%d",15," ",ch_freq[i]);
        }else{
          sprintf(temp, "ch=%c  %*s|        freq=%d", ch,15," ",ch_freq[i]);
        }
        
        drawBody(temp);
        
    }
    drawBottomLine();
    
}

/******************************************************************************
 * This method do the compress bussiness process.
 * inputs:
 *    - fileName -> the filepath that will be compress
 *    - saveto -> the compressed file will be stroe in this path
 * outputs:
 *     - none
 *****************************************************************************/
int compress(char fileName[],char saveto[]){
    printf("System is try to compressed %s...\n",fileName);
    int freq[256] = {0};
    char arr[256];
    int size = countFileContent(fileName,arr,freq);
    if(size==-1){
      return 0;
    }
    char ch_arr[size];
    int ch_freq[size];
    createStatisTable(ch_arr,arr,ch_freq,freq);

    hfNode_t*  nodes= huffmanCodes(ch_arr,ch_freq,size);
    
    
    if(__detail){
      printfStatistic(ch_arr,ch_freq,size);
      printfHuffmanCode(nodes,size);
    }
   
    if(encode(fileName,saveto,nodes,size)){
      printfSuccess("Comporess file successfully!");
      return 1;  
    }
    return 0;
}


/******************************************************************************
 * This method do the decompress bussiness process.
 * 
 * inputs:
 *    - decodeFileName -> the filepath that will be decomporessed
 *    - saveto -> the compressed file will be stroe in this path
 * outputs:
 *     - none
 *****************************************************************************/
void decompress(char decodeFileName[],char saveto[]){ 
      printf("System is try to decompressed %s...\n",decodeFileName);
      if(decode(decodeFileName,saveto)){
          printfSuccess("Decompressed file successfully");
          printf("%s is decompressed as %s\n",decodeFileName,saveto);
      }  
}





