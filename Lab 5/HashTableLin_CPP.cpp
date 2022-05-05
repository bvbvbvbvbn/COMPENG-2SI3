#include HashTableLin.h
#include iostream
#include algorithm
#include vector
#include stdio.h
#include stdlib.h
#include cmath

using namespace std;

TC O(n)
SC O(1)
bool HashTableLinprimeNumber(int n) {

	If no, loop through every number up until n, and if its modulo is never 0, it is prime. therefore return true
	if (n == 1) { if n is 1
		return false; return false meaning n is not a prime number
	} else if (n == 0) { if n is 0
		return false; return false meaning n is not a prime number
	} else {
		for (int i = 2; i  n; i++) { if n is not 1 or 0, loop until n
			if (n % i == 0) { if modulo is 0 return false because it is not a prime number
				return false;
			}
		}
		return true; if module is not 0, return true meaning it is a prime number
	}
}

TC O(n^2)
SC O(1)
HashTableLinHashTableLin(int maxNum, double load) {
	size = ceil((maxNum  load)); size is max keys divided by load and then rounded up

	while (!primeNumber(size)) { while size is not a prime number
		size++; increment until it is a prime number
	}

	vectorint tempTable(size); create temporary table
	table = tempTable;
	keys = 0; set keys to 0
	maxkey = size  load; the max key times load factor
	maxload = load;
}

TC O(n^2)
SC O(1)
void HashTableLininsert(int n) {

	if (!isIn(n)) { if key is not in table
		keys++; increment keys until it is in table

		if (maxkey  keys) { if max keys is less than the current amount of keys
			rehash();
		}

		int indexHash = n % size; using hash function to get hash table index

		if (table[indexHash] == NULL) { if current index is NULL
			table[indexHash] = n; add n keys to index
		} else {
			while (table[indexHash] != NULL) { otherwise while it is not empty
				indexHash = (indexHash + 1) % size; find a index that is not empty
			}
			table[indexHash] = n; let n be index position after the empty index is found
		}
	}
}

TC O(n^2)
SC O(1)
void HashTableLinrehash() {
	size = size  2; double size of has table
	maxkey = maxload  size; redo calculation of max keys in relation to new size
	stdvectorint tempTable; creates temp table
	tempTable = table;

	while (!primeNumber(size)) { if size is not a prime number
		size++; increment until it is
	}

	keys = 0;  set keys to 0
	table.resize(0); reset table size to 0
	table.resize(size); restate table size as size

	for (int i = 0; i  tempTable.size(); i++) { from 0 to the end of table
		if (tempTable[i] != NULL) { if temp table index is not empty
			insert(tempTable[i]); copy keys from table table to current table
		}
	}
}

TC O(n)
SC O(1)
bool HashTableLinisIn(int n) {
	int indexHash = n % size; find index of hash table

	while (table[indexHash] != NULL) { while hash index is not empty
		if (table[indexHash] == n) { if current index key is same as n
			return true; return true
		}

		indexHash = (indexHash + 1) % size; move to the next index

		if (indexHash == n % size) { key is not in table
			return false; return false
		}
	}
	return false;
}

TC O(n)
SC O(1)
void HashTableLinprintKeys() {
	for (int i = 0; i  size; i++) { loops through hash table
		if (table[i] != NULL) {
			cout  table[i]  , ; print all keys until the end
		}
	}
}

TC O(n)
SC O(1)
void HashTableLinprintKeysAndIndexes() {

	for (int i = 0; i  size; i++) { loops through has table
		if (table[i] != NULL) {
			cout  i  ,   table[i]; prints all key indices until the end
		}
	}
}

TC O(n)
SC O(1)
int HashTableLingetNumKeys() {
	int numKeys = 0; set numkeys to 0

	for (int i = 0; i  size; i++) { loop through entire table
		if (table[i] != NULL) { add 1 to numKeys if there is a key present
			numKeys++;
		}
	}

	return numKeys; return number of keys in table
}

TC O(1)
SC O(1)
int HashTableLingetTableSize() {
	return size;
}

TC O(1)
SC O(1)
double HashTableLingetMaxLoadFactor() {
	return maxload;
}

TC O(n^2)
SC O(1)
int HashTableLinProbeCount(int n) {
	int attempts = 0; number of attempts when inserting a key is set to 0

	if (!isIn(n)) { if ket is not in the table
		keys++; increment until it is found

		if (maxkey  keys) { if the maximum amount of keys is less than the amount of keys currently
			rehash();
		}

		int indexHash = n % size; use this hash function to find index for hash table

		if (table[indexHash] == NULL) { if the index of the table is empty
			table[indexHash] = n; add n to that empty position
			attempts++; add 1 to the number of attempts each time
		} else {
			while (table[indexHash] != NULL) { if it is not empty
				indexHash = (indexHash + 1) % size; go through all the indices to find the empty one
				attempts++; add one to the number of attempts
			}
			table[indexHash] = n; add key to empty slot
			attempts++; add to number of attempts
		}
	}
	return attempts;
}

stdvectordouble HashTableLinsimProbeSuccess() {
	vectordouble vectorResult(9);
	int maxSize = 100000;
	int randListNums[100000];
	double resultt = 0;
	double tempSize = 100000;
	int k = 0;

	for (int i = 0; i  maxSize; i++) { for loop that proceeds while i is less than the max size
		int randNum; randon number
		bool isIn = true; if the random number is in the list, return True
		while (isIn) { while the number is in the list
			randNum = (rand()  rand()); make a random number using the rand operator
			isIn = false; if the number is not in the list

			for (int j = 0; j  i; j++) { for loop that goes through list and checks if the ranndom number is in the list
				if (randNum == randListNums[j]) { if the number is in the list, break out of the loop and make another number
					isIn = true;
					break;
				}
			}
		}
		randListNums[i] = randNum; add the unique number to the list
	}

	Simulation
	for (double loadFactor = 0.1; loadFactor  0.99; loadFactor += 0.1) { for loop that goes through as long as the load factor is between 0.1 and 0.9
		resultt = 0;
		for (int i = 0; i  100; i++) { when i is less than 100
			HashTableLin linHash = HashTableLin(maxSize, loadFactor); create a linear hash table with the defined max size and a load factor based off the iteration (0.1-0.9)
			for (int j = 0; j  maxSize; j++) { iterates from 0 to less than the maximum size
				resultt += ((linHash.ProbeCount(randListNums[j]))  (tempSize)); adds number of probes for the 10ok sims to resultt
			}
		}
		vectorResult[k] = resultt  100; divide the veector result by 100 to achieve the average probe value
		k++; next iteration
	}
	return vectorResult;
}

 for bonus
stdvectordouble HashTableLinsimProbeUnsuccess() {
	 TODO, change following code after completing this function
	vectordouble result(9);
	return result;
}
