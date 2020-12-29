# permutation generator

A simple permutation generator written in c++. 

Usage:
1. Declare and initialize t_permutation structure given an array and it's length. Note: the array is taken 'by reference', and it will be modified directly. If you want a copy to be permutated, pass a copy of your array.
```c
int array[] = {1,2,3,4,5};
int array_length = sizeof array / sizeof array[0];

t_permutation<int> permutation;
init_permutation(&permutation, array_length, array);
```

2. Use `permute` procedure to permute the passed array. You can also query some fields like `t_permutation.permutation_index` and `t_permutation.permutation_count` to control the permutation.

```
for(size_t i = 0; i < permutation.permutation_count; i += 1) {
  permute(&permutation);
  do_something_with_array(permutation.permutation);
}
``` 
