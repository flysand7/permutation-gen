
This is a small algorithm for iterating over array permutations. It uses N-base number as a way of tracking the current permutation "index". Each N-base digit of that index can be an index to the original array. 

The idea of the algorithm is to increment this index, until no digits are repeating, then generating the permutation from the digits, by treating each of the digits of the index as the index of the original array.

The example of usage of the code is simple.

```c

int array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'}; // your array
int array_length = sizeof array / sizeof array[0];

// making a permutation object  
t_permutation permutation = create_permutation(array_length, array);

for(int permutation_index = 0; 
  permutation_index < permutation_count(array_length); // permutation_count is array_length factorial
  permutation_index += 1) {
    
  for(int index = 0; index < array_length; index += 1) { // print array
    printf("%c", permutation.last_permutation[index]);
  }

  permute(&permutation); // new permutation
    
  printf("\n");
}
```

To create a new permutation object, call
```c
t_permutation create_permutation(int array_length, int *array);
```

This function *copies* the array. After the return, the `last_permutation` is the copy of the input array.

To permute, call
```c
void permute(t_permutation *permutation)
```

This will cycle the `permutation` through all the permutations.