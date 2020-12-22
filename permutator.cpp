
#include<stdlib.h> // malloc
#include<string.h> // memcpy

template<typename T>
struct t_permutation {
  T *last_permutation;
  t_permutation(int array_length, T *array);
  ~t_permutation(void);
  int permutation_count(void);
  void permute(void);
  
  private: 
  int len;
  int *index;
  T *original_array;
  void increment_permutation_index(void);
};

template<typename T> t_permutation<T>::
t_permutation(int array_length, T *array) {
  len = array_length;
  original_array = (int *)malloc(array_length * sizeof(int));
  last_permutation = (int *)malloc(array_length * sizeof(int));
  index = (int *)malloc(array_length * sizeof(int));
  memcpy(original_array, array, array_length * sizeof(int));
  memcpy(last_permutation, array, array_length * sizeof(int));
  for(int digit = 0; digit < array_length; digit += 1) {
    index[digit] = digit;
  }
}

template<typename T> t_permutation<T>::
~t_permutation(void) {
  free(original_array);
  free(last_permutation);
  free(index);
}

template<typename T> void t_permutation<T>::
increment_permutation_index(void) {
  for(int i =  len-1; i >= 0; i -= 1) {
    if(index[i] !=  len-1) {
      index[i] += 1;
      break;
    }
    index[i] = 0;
  }
}

template<typename T> void t_permutation<T>::
permute(void) {
  while(true) {
    increment_permutation_index();
    bool repeating = false;
    for(int digit_index = 1; digit_index <  len; digit_index += 1) {
      for(int i = digit_index - 1; i >= 0; i -= 1) {
        if(index[digit_index] ==  index[i]) {
          repeating = true;
          break;
        }
      }
    }
    if(!repeating) {
      for(int i = 0; i <  len; i += 1) {
        last_permutation[i] =  original_array[ index[i]];
      }
      break;
    }
  }
}

template<typename T> int t_permutation<T>::
permutation_count(void) {
  int result = 1;
  for(int i = 2; i <=  len; i += 1) {
    result *= i;
  }
  return result;
}

#include<stdio.h>
int main(void) {
  int array[] = {'a', 'b', 'c'};
  int array_length = sizeof array / sizeof array[0];
  t_permutation<int> permutation(array_length, array);
  for(int permutation_index = 0; 
      permutation_index < permutation.permutation_count(); 
      permutation_index += 1) {
    for(int index = 0; index < array_length; index += 1) {
      printf("%c", permutation.last_permutation[index]);
    }
    permutation.permute();
    printf("\n");
  }
  return 0;
}
