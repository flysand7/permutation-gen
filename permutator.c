// the code

struct {
  int len;
  int *index;
  int *original_array;
  int *last_permutation;
} typedef t_permutation;

#include<stdbool.h> //true, false
#include<stdlib.h> //malloc
#include<string.h> //memcpy

t_permutation create_permutation(int array_length, int *array) {
  t_permutation permutation;
  permutation.len = array_length;
  
  // saving original array by copy, and setting 
  // last permutation to the value of the array
  permutation.original_array = (int *)malloc(array_length * sizeof(int));
  permutation.last_permutation = (int *)malloc(array_length * sizeof(int));
  permutation.index = (int *)malloc(array_length * sizeof(int));
  memcpy(permutation.original_array, array, array_length * sizeof(int));
  memcpy(permutation.last_permutation, array, array_length * sizeof(int));
  
  // making number of the form 0123...(n-1)_n
  for(int digit = 0; digit < array_length; digit += 1) {
    permutation.index[digit] = digit;
  }
  
  return permutation;
}

void increment_permutation_index(t_permutation *permutation) {
  
  for(int i = permutation->len-1; i >= 0; i -= 1) {
    if(permutation->index[i] != permutation->len-1) {
      permutation->index[i] += 1;
      break;
    }
    permutation->index[i] = 0;
  }
}

void permute(t_permutation *permutation) {
  
  // add 1 to the 'index' until we 
  // find one without repeating digits
  while(true) {
    
    increment_permutation_index(permutation);
    
    // checking if the digits aren't repeating...
    bool repeating = false;
    for(int digit_index = 1; digit_index < permutation->len; digit_index += 1) {
      for(int i = digit_index - 1; i >= 0; i -= 1) {
        if(permutation->index[digit_index] == permutation->index[i]) {
          repeating = true;
          break;
        }
      }
    }
    
    // ...if they aren't, pick a permutation with 
    // each digit being array's corresponding element
    if(!repeating) {
      for(int i = 0; i < permutation->len; i += 1) {
        permutation->last_permutation[i] = permutation->original_array[permutation->index[i]];
      }
      break;
    }
  }
  
}

// testing
int permutation_count(int array_length) {
  int result = 1;
  for(int i = 2; i <= array_length; i += 1) {
    result *= i;
  }
  return result;
}

#include<stdio.h>
int main(void) {
  int array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
  int array_length = sizeof array / sizeof array[0];
  
  t_permutation permutation = create_permutation(array_length, array);
  for(int permutation_index = 0; 
      permutation_index < permutation_count(array_length); 
      permutation_index += 1) {
    
    for(int index = 0; index < array_length; index += 1) {
      printf("%c", permutation.last_permutation[index]);
    }
    permute(&permutation);
    
    printf("\n");
  }
  
  return 0;
}
