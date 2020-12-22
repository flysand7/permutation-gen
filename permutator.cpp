
#include<stdbool.h> //true, false
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
  this->len = array_length;
  this->original_array = (int *)malloc(array_length * sizeof(int));
  this->last_permutation = (int *)malloc(array_length * sizeof(int));
  this->index = (int *)malloc(array_length * sizeof(int));
  memcpy(this->original_array, array, array_length * sizeof(int));
  memcpy(this->last_permutation, array, array_length * sizeof(int));
  for(int digit = 0; digit < array_length; digit += 1) {
    this->index[digit] = digit;
  }
}

template<typename T> t_permutation<T>::
~t_permutation(void) {
  free(this->original_array);
  free(this->last_permutation);
  free(this->index);
}

template<typename T> void t_permutation<T>::
increment_permutation_index(void) {
  for(int i = this->len-1; i >= 0; i -= 1) {
    if(this->index[i] != this->len-1) {
      this->index[i] += 1;
      break;
    }
    this->index[i] = 0;
  }
}

template<typename T> void t_permutation<T>::
permute(void) {
  while(true) {
    this->increment_permutation_index();
    bool repeating = false;
    for(int digit_index = 1; digit_index < this->len; digit_index += 1) {
      for(int i = digit_index - 1; i >= 0; i -= 1) {
        if(this->index[digit_index] == this->index[i]) {
          repeating = true;
          break;
        }
      }
    }
    if(!repeating) {
      for(int i = 0; i < this->len; i += 1) {
        this->last_permutation[i] = this->original_array[this->index[i]];
      }
      break;
    }
  }
}

template<typename T> int t_permutation<T>::
permutation_count(void) {
  int result = 1;
  for(int i = 2; i <= this->len; i += 1) {
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
