
template<typename T>
struct t_permutation {
  size_t array_length;
  T *permutation;
  size_t permutation_index;
  size_t permutation_count;
};

template<typename T> 
void init_permutation(t_permutation<T> *permutation, size_t array_length, T *array) {
  permutation->array_length = array_length;
  permutation->permutation = array;
  permutation->permutation_count = 1;
  permutation->permutation_index = 0;
  for(size_t index = 2; index <= array_length; index += 1) {
    permutation->permutation_count *= index;
  }
}

size_t weave(size_t k, size_t n) {
  if(n == 2) return 0;
  if(k % n != 0) {
    if(k % (2*n) > n) return (2*n - k - 1) % n;
    else return (k-1) % n;
  }
  else {
    if(k % (2*n) == n) return weave(k/n, n-1);
    else return weave(k/n, n-1)+1;
  }
}

template<typename T> 
void permute(t_permutation<T> *permutation) {
  permutation->permutation_index += 1;
  size_t swap_index = weave(permutation->permutation_index, permutation->array_length);
  T tmp = permutation->permutation[swap_index];
  permutation->permutation[swap_index] = permutation->permutation[swap_index+1];
  permutation->permutation[swap_index+1] = tmp;
  if(permutation->permutation_index == permutation->permutation_count) {
    permutation->permutation_index = 0;
  }
}
