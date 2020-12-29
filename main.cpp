#include"permutator.cpp"
#include<stdio.h>
int main(void) {
  int array[] = {'a', 'b', 'c'};
  int array_length( sizeof array / sizeof array[0]);
  t_permutation<int> permutation;
  init_permutation(&permutation, array_length, array);
  
  for(int permutation_index = 0; 
      permutation_index < permutation.permutation_count;
      permutation_index += 1) {
    for(int index = 0; index < array_length; index += 1) {
      printf("%c", permutation.permutation[index]);
    }
    permute(&permutation);
    printf("\n");
  }
  return 0;
}
