# Project2 Hashing

## Purpose of the project is hashing. This project involves implementing and testing 3 hash table using different collision resolution methods: Quadratic Probing, Linear Probing, and Double Hashing

### Part1 - Hashing Implementations and Testings

1. When a hash table is created, the `array_` vector size is default to 101. And initializes each HashEntry object's `element_` to empty (e.g. if `element_` is a string, it will be an empty string) and `info_` to enum EMPTY. Note: when we call `hash_table.MakeEmpty()`, it does not change the size of `array_` vector. It only resets the `info_` field of each HashEntry to `EMPTY` and sets `current_size_` to `0`, it does not change the vector's capacity.

2. Each `HashEntry` struct object has two attributes:
   - `element_`: `element_` is of type `ItemType` (in this project, it's a `std::string`) and holds the object that is being hashed. The `hash_value % table_size` gives the index position where the `HashEntry` will be stored.
   - `info_`: `info_` is of type enum and acts as a flag for `HashEntry`.

3. Using `std::hash<HashedObj>`  hf() to get the hash value of the object, in this project HashObj will be a string - e.g. hf(x). Then use `hf(x) % table_size` to get the index position. This operation: `h0(x)` is the first attempt, so probe count is 1. If there's no collision, then we insert the key (e.g. `HashEntry`). If there's a collision, we then try `0 <= i < table_size` and since `h1(x) = (h0(x) + 0^2) % table_size`. `h0(x) = hx(1)` the probe count is just 1. We continue to increment `i` and probe count.

4. load factor `λ`: $\frac{\text{total number of elements in the hash table}}{\text{table size}}$, ideally no more than 0.5. If the table is even one more than half full, the insertion could fail (although this is extremely unlikely). Therefore, it is important to keep this in mind. It is also crucial that the table size be prime. If the table size is not prime, the number of alternative locations can be severely reduced.

Collisions Resolution:

1. Quadratic probing involves incrementing the current_pos by an increasing quadratic offset to find the next available slot. Initially, offset is 1. With each iteration, offset is incremented by 2 (offset += 2), resulting in quadratic increments (1, 3, 5, 7, etc.).
This quadratic increment ensures that the sequence of probed positions (current_pos) forms a quadratic pattern rather than a linear one, which can reduce clustering of hashed keys.
First, instead of doing  $i^2$ and getting the sequence 0,1,4,9,16, etc
The code is instead starting from the number 1, and adding consecutive odd numbers to get the squares instead of running multiplication. Notice that: (0+1=1), (1+3=4), (4+5=9), (9+7=16), etc

2. Implement Linear Probing: increment current_position by 1. A probe is an effort made to find an available location. Downside is primary clustering, tend to form clusters.

3. Implement Double Hashing:

   - `m = array.tableSize()`
   - Hash value: `x = hf(x)`
   - Initial hash function: `h(x) = x % m`
   - Secondary hash function: `hash2(x) = R - (x % R)` (from textbook p.207)

   Double Hashing Process:
   - Hash Value: `x = hf(x)`
   - 1st Attempt (Probe 1): `h(x) % m`
   - 2nd Attempt (Probe 1): `(h(x) + 0 * hash2(x)) % m`
   - 3rd Attempt (Probe 2): `(h(x) + 1 * hash2(x)) % m`
   - 4th Attempt (Probe 3): `(h(x) + 2 * hash2(x)) % m`
   - subsequent (Probe i+1 )`(h(x) + i * hash2(x)) % m`

   For each attempt `i` from `0 to m-1`, the hash function adjusts the probe sequence to handle collisions effectively. This method combines a primary hash function `h(x) = x % m` with a secondary hash function `hash2(x) = R - (x % R)`

### Part2 - Spell Check Using Double Hashing Technique (most efficient)

1. Read in from `wordsEn.txt` to make a dictionary, size of `109,582`.
2. Read in an article `document1.txt`, pre-process each word: such as converting to lowercase, removing punctuation, split by `-`, removing trailings.
3. After words are cleaned up, pass them into the dictionary; if found, print e.g. `early is CORRECT`.
4. If not found, fix the misspelled word by one of the three methods:
   - Adding one character in any possible position
   - Removing one character from the word
   - Swapping adjacent characters from the word  
Finally, print out the misspelled word along with its corrected form and method used.
5. I initialized a `bool found` flag initially set to false `bool found = false`.  
It's then passed-by-reference to the 3 function calls. If any function sets it to true, it will be true, else it will remain false. It means the 3 functions have tried to fix the word, but it's still incorrect or the dictionary does not have the word.

### Notes

1. hash functions are the calculation to get the index for initial insertion. There are 3 different types we went over, division based, bit-shifting and multiplicative (here M is NOT necessary to be a power of 2.) - and they are all for integers as the input.
2. String encoding is a hash function only for string as the input.
3. The goal of the above 2 hash functions is to get the index, and if there're collisions, then we're using separate chaining(linkedlist) and open address(linear, quadratic, double hashing) to resolve to a new index for insertion.
4. Double the amount of data you expect to put into the table
A prime number. This is because if my hash table size is, say, 100, then any hash key that's a multiple of 100 will first try to go into index 100, causing a collision after the first insert. A good hash function will scatter the data evenly throughout the hash table.
Number of probes it took to find the next available location for the keys.

## Command to run

### Populate a hash table

```bash
make clean && make all && ./create_and_test_hash words.txt query_words.txt [quadratic, linear, double, rvalue]
```

### Spell Checker

```bash
make clean && make all && ./spell_check document1_short.txt wordsEn.txt
```

References:

1. [Data Structures & Algorithm Analysis in C++ 4th Chapter 5, page. 205](https://www.uoitc.edu.iq/images/documents/informatics-institute/Competitive_exam/DataStructures.pdf)
2. [Linear and Quadratic Probing Readings](https://www.andrew.cmu.edu/course/15-310/applications/ln/hashing-review.html#:~:text=Quadratic%20Probing%20is%20just%20like,it%20looks%20ahead%201%20position)
3. [Linear Probing Youtube](https://www.youtube.com/watch?v=zeMa9sg-VJM)
4. [Double Hashing Youtube](https://www.youtube.com/watch?v=AYcsTOeFVas&t=718s)
5. [Punctuation marks](https://www.dictionary.com/browse/punctuation-mark)
