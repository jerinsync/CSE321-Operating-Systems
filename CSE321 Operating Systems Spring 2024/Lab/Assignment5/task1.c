#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int checkP2(int x);
int *dTob(int n,int l);
int bTod(int a[],int l);

int main(){
    int pgs=4; //page size
    int ms=32; //memory size
    int nof=ms/pgs; //number of frames
    int offset_bit; //find out # of bits required for offset
    int m; //find out address spaces required in main memory
    int pg_num_bit; ////find out # of bits required for page number
    int la[]={8,4,3,2,15,18,25}; //logical addresses generated by the CPU
    int pmt[]={3,6,8,12,2}; //page table

    /*
    find out corresponding physical addresses of generated logical
    addresses
    using the formula: physical address = (frame # * page
    size)+offset
    */
    int flag=0;
    m = checkP2(ms);
    offset_bit = checkP2(pgs);
    if (m == -1 || offset_bit == -1){
        flag = 1;
    }
    pg_num_bit = m-offset_bit;
    int n = sizeof(la) / sizeof(la[0]);
    printf("Page size: %d\n", pgs);
    printf("Memory size: %d\n", ms);
    printf("Number of frames required: %d\n", nof);
    printf("Page number bits: %d\n", pg_num_bit);
    printf("Offset bits: %d\n", offset_bit);
    printf("Number of address spaces: %d\n", m);
    printf("Page Table ___\n");
    for (int i = 0; i < 5; i++){
        printf("%d -> %d\n", i, pmt[i]);
    }
    for (int j = 0; j< n; j++){
        if (flag == 1){
            printf("Invalid");
            break;
        }
        
        int* binTotal = dTob(la[j],m);
        int pgbinVal[pg_num_bit];
        int offsetbinVal[offset_bit];
        int c=0;
        for(int i = 0; i < pg_num_bit; i++){
            pgbinVal[i]=binTotal[i];
            c++;
        }
        
        for(int i = 0; i < offset_bit; i++){
            offsetbinVal[i]=binTotal[c];
            c++;
        }
        
        
        int pagedecimal = bTod(pgbinVal,pg_num_bit);
        int pagelen = sizeof(pmt)/sizeof(pmt[0]);
        int offsetdecimal = bTod(offsetbinVal, offset_bit);
        if (pagedecimal>pagelen){
            printf("%d is an invalid page number\n", pagedecimal);
        }
        else{
            int pa = (pmt[pagedecimal]*pgs) + offsetdecimal;
            if (pa <= ms-1){
                printf("Corresponding physical address of logical address %d: %d\n", la[j], pa);
            }
            else if(pa > ms-1){
                printf("%d is an invalid physical address\n", pa);
            }
        }
    }
    return 0;
}

int checkP2(int x){
    int power = 0;
    int value = 1;
    while (value < x){
        value *= 2;
        power++;
    }
    if (value == x){
        return power;
    } 
    else{
        return -1;
    }
    
}

int *dTob(int n,int l){
    int* binVal=(int*)malloc(l*sizeof(int));
    int i;
    for (i=0; i<l;i++){
        binVal[i] = 0;
    }
    i=l-1;
    while (n>0 && i>=0){
        binVal[i] =n%2;
        n /=2;
        i--;
    }
    return binVal;
}


int bTod(int a[],int l){
    int val=0;
    int base=1;
    for (int i=l-1;i>=0;i--){
        val= val+a[i]*base;
        base*=2;
    }
    return val;
}
