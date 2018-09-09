#include <stdio.h>
#include <string.h>
#define ALPHABET (('z'- 'a') + 1)
#define getIndex(A) ((A - 'a') % ALPHABET)
int splitAnagrama(const char * s){
    int left[ALPHABET]={0,};
    int right[ALPHABET]={0,};
    size_t  size = strlen(s);
    int middle = size/2;
    int sumA=0, sumB=0;

    // string A
    for(int i=0; i <  middle; i++ ){
        left[getIndex(s[i])]++ ;
    }

    // string B
    for(int i=middle; i <  size; i++ ){
        right[getIndex(s[i])]++ ;
    }

    for(int i=0; i < ALPHABET; i++){
        if (left[i] > right[i]){
            sumA += left[i] - right[i];
        } else if(right[i] > left[i]){
            sumB +=  right[i] - left[i];
        }
    }

    if (sumA == sumB){
        return sumA;
    }
    return sumA - sumB;
}
int main() {
    printf("aaabbb %d\n", splitAnagrama("aaabbb"));
    printf("ab %d\n", splitAnagrama("ab"));
    printf("abc %d\n", splitAnagrama("abc"));
    printf("mnop %d\n", splitAnagrama("mnop"));
    printf("xyyx %d\n", splitAnagrama("xyyx"));
    printf("xaxbbbxx %d\n", splitAnagrama("xaxbbbxx"));
    return 0;
}
