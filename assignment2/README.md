# Project2 Hashing:
## Purpose of the project is hashing. This project involves implementing and testing 3 hash table using different collision resolution methods: Quadratic Probing, Linear Probing, and Double Hashing.

### Part1 - Hashing Implementations and Testings
1. Quadratic probing implementation is provided to us, we needed to implement helper functions to get the deliverables - total collisions, average collisions, number of probes it took to find the next available location for the keys.
start offset = 1, increment current position by offset, and increment offset by 2. 

2. Implement Linear Probing: offset = 1, increment current position by offset, and increment offset by 1. 

3. Implement Double Hashing: hash2(x) = R − (x mod R) textbook p.207.


### Part2 - Spelling Checking
1. 



Command to run:
make clean && make && ./create_and_test_hash words.txt query_words.txt [quadratic, linear, double, rvalue]

References:
1. [Data Structures & Algorithm Analysis in C++ 4th Chapter 5, page. 205](https://www.uoitc.edu.iq/images/documents/informatics-institute/Competitive_exam/DataStructures.pdf)
2. [Linear and Quadratic Probing Readings](https://www.andrew.cmu.edu/course/15-310/applications/ln/hashing-review.html#:~:text=Quadratic%20Probing%20is%20just%20like,it%20looks%20ahead%201%20position)
