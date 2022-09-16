Heap is a complele binary tree satisfying any one of the conditions either as max-heap or min-heap. Heaps are represented mostly using array. As it is the complete binary
tree, the height of binary tree will be log n only. Therefore, the height of heap is also log n.

Types of heap:
Max-heap: It is a complete binary tree where every node has value greater than or equal to all its descendants.
Min-heap: It is a complete binary tree where every node has value smaller than or equal to all its descendants.


Heapify is faster method to create heap. Using this method we create heap from current node by moving downwards in the tree. Unlike the traditional method of creating heap where we move upwards by comparing the current element with parent to create heap. It's time complexity is O(n) whereas heap creation using conventional method takes O(nlogn) time.
We should use heapify method to create heap as it's performance is better.

Deletion From Heap:
Deletion is done always at the root of the tree in heap. We replace the root element with last element of tree (before taking root in temporary variable). After it, we just call heapify method to create heap(max or min) so that all elements are arranged properly according to max or min heap property.
