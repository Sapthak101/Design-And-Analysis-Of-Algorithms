#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//Define a structure of Huffman Tree
struct Node{
    char data;
    unsigned freq;  //unsigned used because freq variable accepts only non-negative value
    struct Node* left;
    struct Node* right;
};

//new node creation of Huffman tree
struct Node* newnode(char data,unsigned freq){
       struct Node* node=(struct Node*)malloc(sizeof(struct Node));
       node->data=data;
       node->freq=freq;
       node->left=node->right=NULL;
       return node;
}

//structure for min-heap which stores the nodes of Huffman tree during construction
struct Minheap{
    unsigned size;      //Current number of elements present in min-heap
    unsigned capacity;  //Max no of element the minheap can hold 
    struct Node** array;
};

//create the Minheap
struct Minheap* createMinheap(unsigned capacity){
    struct Minheap* minheap=(struct Minheap*)malloc(sizeof(struct Minheap));
    minheap->size=0;
    minheap->capacity=capacity;
    minheap->array=(struct Node*)malloc(capacity*sizeof(struct Node));
    return minheap;
}

void swapnodes(struct Node** a,struct Node** b){
    struct Node* temp=*a;
    *a=*b;
    *b=temp;
}

//Min Heapify
void minheapify(struct Minheap* minheap,int i){
    int smallest =i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<minheap->size && minheap->array[left]->freq < minheap->array[smallest]->freq){
        smallest=left;
    }

    if(right<minheap->size && minheap->array[right]->freq < minheap->array[smallest]->freq){
        smallest=right;
    }

    if(smallest!=i){
        swapnodes(&minheap->array[i],&minheap->array[smallest]);
        minheapify(minheap,smallest);
    }
}

//cheack if the Minheap has only one node.(if it is, then it means that tree is completed as there is only one node is the root node of Huffman tree)
int issizeone(struct Minheap* minheap){
    return(minheap->size==1);
}

//extact the node with min frequency from the heap
struct Node* extractmin(struct Minheap* minheap){
    struct Node* temp=minheap->array[0];
    minheap->array[0]=minheap->array[minheap->size-1];
    --minheap->size;
    minheapify(minheap,0);
    return temp;
}

//insert a new node into minheap which is created by adding two char freq
void insertMinheap(struct Minheap* minheap,struct Node* node){
    ++minheap->size;
    int i = minheap->size - 1;
    while(i && node->freq < minheap->array[(i-1)/2]->freq){
        minheap->array[i]=minheap->array[(i-1)/2];
        i=(i-1)/2;
    }
    minheap->array[i]=node;
}

//Build the Huffman tree and return root node
struct Node* buildHuffmanTree(char data[], int frequency[], int size) {
    struct Node *left, *right, *top;
    struct Minheap* minHeap = createMinheap(size);

    for (int i = 0; i < size; ++i)
        insertMinheap(minHeap, newnode(data[i], frequency[i]));

    while (!issizeone(minHeap)) {
        left = extractmin(minHeap);
        right = extractmin(minHeap);
        top = newnode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinheap(minHeap, top);
    }
    return extractmin(minHeap);  //return root node
}

//print the tree
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Huffman coding function
void huffmanCodes(char data[], int frequency[], int size) {
    struct Node* root = buildHuffmanTree(data, frequency, size);
    int arr[size], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
}

// Driver program
int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    char data[n];
    int frequency[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &data[i]);
        printf("Enter frequency for %c: ", data[i]);
        scanf("%d", &frequency[i]);
    }
    clock_t start = clock();
    huffmanCodes(data, frequency, n);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %lf s.\n", time_taken);
    return 0;
}