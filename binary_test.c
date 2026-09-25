#include <stdio.h>
#include <stdint.h>
#include <time.h>

int safe(int n, int line, int bit, uint32_t array[n]){

    int i =0;
    int j =0;
    int temp = 1 << bit;
    for(i=0; i<n; i++){
        if(temp&array[i]){
            return 0;
        }
    }
    
    // perfect till here

    if(line==0){
        
    }
    else{
        i = line-1;
        temp = 1 << bit;
        temp = temp >> 1;

    while(i>=0 && temp>0){
        if(array[i] & temp){
            return 0;
        }
        i--;
        temp = temp >> 1;
    }
    }
    
    // good till here

    if(line==0){
        
    }
    else{
        i = line-1;
    
    temp = 1 << bit;
    temp = temp << 1;
    int temp0 = 1 << n;

    while(i>=0 && temp<temp0){
        if(array[i] & temp){
            return 0;
        }
        i--;
        temp = temp << 1;
    }
    }
    
    return 1;
}

int main(){

    clock_t start = clock();

    int n = 0;
    printf("Enter N: ");
    scanf("%d", &n);

    uint32_t array[n];

    int i = 0;
    for(i=0; i<n; i++){
        array[i] = 0b00000000;
        // printf("%b\n", array[i]);
    }

    int line = 0;
    int bit = 0;
    int temp = 0;

    while(line<n){
        while(bit<n){

            if(safe(n, line, bit, array)){
                array[line] = 1 << bit;
                line++;
                temp = bit;
                bit = 0;
                break;
            }
            bit++;
        }

        if(bit==n){
            if(line==0){
                printf("no solution\n");
                return 0;
            }

            line--;
            
            int i = 0;
            int count = 0;
            for(i=0; i<n; i++){
                if(array[line]==1){
                    break;
                }
                else{
                    array[line] = array[line] >> 1;
                    count++;
                }
            }
            count++;
            array[line] = 0;
            bit = count;
            temp = 0;
        }
    }

    int j = 0;
    int mask = 1;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d  ", mask&array[i] ? 1 : 0);
            mask = mask << 1;
        }
        mask = 1;
        printf("\n");
        // printf("%b\n", array[i]);
    }

    clock_t end = clock();

    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken: %.6f seconds\n", time_spent);

    return 0;
}