Hashing is a technique or process of mapping keys, and values into the hash table by using a hash function. It is done for faster access to elements. The efficiency of mapping depends on the efficiency of the hash function used.

Types of Hashing:

Open Hashing: The "closed" in "closed hashing" refers to the fact that we never leave the hash table; every object is stored directly at an index in the hash table's internal array. Note that this is only possible by using some sort of open addressing strategy. This explains why "closed hashing" and "open addressing" are synonyms.

Closed Hashing: Contrast this with open hashing - in this strategy, none of the objects are actually stored in the hash table's array; instead once an object is hashed, it is stored in a list which is separate from the hash table's internal array. "open" refers to the freedom we get by leaving the hash table, and using a separate list. By the way, "separate list" hints at why open hashing is also known as "separate chaining".
