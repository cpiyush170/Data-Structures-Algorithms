AVL trees are height balanced binary search trees. The height of BST is balanced using balance factor.
Balance factor is = height of left subtree - height of right subtree.
We calcualte balance factor of every node of binary search tree (making it AVL tree).
The balance factor of every node is either -1, 0, 1. ie. | hl - hr | <= 1. Then it is balanced node
If balance factor is | hl - hr | > 1, then node is imbalanced.
If any node of binary search tree is imbalanced, then we perform rotations to make it balanced binary search tree i.e. AVL tree 
The height of an AVL tree is always O(log n) where n is the number of nodes in the tree.

#Insertion in AVL Tree:
For insertion in AVL tree, we first perform standard BST insertion of the node and then rebalance the BST by left or right rotation. After insertion if the tree is not balanced then following 4 cases might occur:
1. Left Left case
2. Left Right case
3. Right Right case
4. Right Left case

#Rotation for Insertion:
1. LL Rotation
2. RR Rotation
3. LR Rotation
4. RL Rotation


