AVL trees are height balanced binary search trees. The height of BST is balanced using balance factor.
Balance factor is = height of left subtree - height of right subtree.
We calcualte balance factor of every node of binary search tree (making it AVL tree).
The balance factor of every node is either -1, 0, 1. ie. | hl - hr | <= 1. Then it is balanced node
If balance factor is | hl - hr | > 1, then node is imbalanced.
If any node of binary search tree is imbalanced, then we perform rotations to make it balanced binary search tree i.e. AVL tree 

Rotation for Insertion:
1. LL Rotation
2. RR Rotation
3. LR Rotation
4. RL Rotation


