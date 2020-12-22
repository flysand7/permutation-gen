
# Introduction

This is a small algorithm for iterating over array permutations. It uses N-base number as a way of tracking the current permutation "index". Each N-base digit of that index can be an index to the original array. 

The idea of the algorithm is to increment this index, until no digits are repeating, then generating the permutation from the digits, by treating each of the digits of the index as the index of the original array.

This algotithm was implemented by a C programmer who knows nearly nothing about C++. But the information about the code usage for convenience is presented for both languages.

# C version

The example of usage of the code is simple.

```c

// your array
int array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
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

# C++ version

C++ version defines an object `t_permutation<T>`, that has one public value `T *last_permutation`. The public interface for this object:

```cpp
template<typename T>
struct t_permutation {
  T *last_permutation;

  t_permutation(int array_length, T *array);
  ~t_permutation(void);

  int permutation_count(void);
  void permute(void);
}
```

Use `t_permutation<T>::permutation_count` to retrieve the amount of possible permutations.

Use `t_permutation<T>::permute` to generate the next permutation. The next permutation will be available in the public field `T *t_permutation<T>::last_permutation`.
