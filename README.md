# Heapsort
*Heapsort* is a sorting algorithm that uses the idea of a *binary tree*. A binary tree is a data structure in which each node has two children, which are referred to as the *left child* and the *right child*. In the representation of the tree, the first element has index 1 and the last has the index equal to the tree's size. Also, the children of a parent node have their index equal to their parent's index x 2 and x 2 + 1. 

To order the binary tree via Heapsort, we must follow a few steps: 
 
  1. Build the *max heap*
  2. Iterate and swap the largest value to the last position 

# Building the max heap

In a *max heap*, the children nodes cannot have a greater value than it's parent node. To build the *max heap*, along with a for loop in the source code, it is used a function called *ascend* that verifies if the child node is greater than the parent node. If it is, the child node *ascends* and occupies its former parent node.

The ascend function:

          void ascend(int* myArray, int child, int parent){
    
              while (parent >= 0) {
                if (myArray[child] > myArray[parent]) {
                    swap(myArray, child, parent);
                }
                child = parent;
                parent = (int)(floor((child+1)/2)-1);
              }
          }

Ascend inside the Heapsort function:
        
        for (int i = 1; i < arraySize; i++) {
        
            int child = i;
            int parent = (int)(floor((i+1)/2)-1);
        
            ascend(myArray, child, parent);
        }

# Descending order

After building the max heap, it is needed to order the array in descending order. To do so, we swap the last element in the array with the first and swap the first element with it's largest child until there are no more larger children. This process does not include the last element and every time that are no more larger children, the last element is reduced by one.

The descend function:

          void descend(int* myArray, int finalPos, int i) {
    
              int largest = i;
              int childLeft = 2 * largest + 1;
              int childRight = 2 * largest + 2;

              if (childLeft < finalPos && myArray[childLeft] > myArray[largest])
                  largest = childLeft;
              if (childRight < finalPos && myArray[childRight] > myArray[largest])
                  largest = childRight;

              if (largest != i) {
                swap(myArray, i, largest);
                descend(myArray, finalPos, largest);
              }
          }

Descend in the Heapsort function:

          for (int finalPos = arraySize-1; finalPos >= 0; finalPos--) {
              swap(myArray, finalPos, 0);
              descend(myArray, finalPos, 0);    
          }

