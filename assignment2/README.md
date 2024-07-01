# Project2 Hashing:
## Purpose of the project is hashing. This project involves implementing and testing 3 hash table using different collision resolution methods: Quadratic Probing, Linear Probing, and Double Hashing.

### Part1 - Hashing Implementations and Testings
#### Table Size should be:

##### One edge case is that it could not be inserted, so probe is not available
Double the amount of data you expect to put into the table
A prime number. This is because if my hash table size is, say, 100, then any hash key that's a multiple of 100 will first try to go into index 100, causing a collision after the first insert. A good hash function will scatter the data evenly throughout the hash table.
Number of probes it took to find the next available location for the keys.

load factor λ: (total number of elements in the hash table)/(table size), ideally no morea than 0.5

Collisions:

1. Quadratic probing implementation is provided to us, we needed to implement helper functions to get the deliverables - total collisions, average collisions, number of probes it took to find the next available location for the keys.
start offset = 1, increment current position by offset, and increment offset by 2. 

2. Implement Linear Probing: increment current_position by 1. A probe is an effort made to find an available location. Downside is primary clustering, tend to form clusters.


3. Implement Double Hashing: hash2(x) = R − (x mod R) textbook p.207.


### Part2 - Spelling Checking
1. 



Command to run:
make clean && make && ./create_and_test_hash words.txt query_words.txt [quadratic, linear, double, rvalue]

References:
1. [Data Structures & Algorithm Analysis in C++ 4th Chapter 5, page. 205](https://www.uoitc.edu.iq/images/documents/informatics-institute/Competitive_exam/DataStructures.pdf)
2. [Linear and Quadratic Probing Readings](https://www.andrew.cmu.edu/course/15-310/applications/ln/hashing-review.html#:~:text=Quadratic%20Probing%20is%20just%20like,it%20looks%20ahead%201%20position)
3. [Linear Probing Youtube](https://www.youtube.com/watch?v=zeMa9sg-VJM)
4. [Double Hashing Youtube](https://www.youtube.com/watch?v=AYcsTOeFVas&t=718s)
