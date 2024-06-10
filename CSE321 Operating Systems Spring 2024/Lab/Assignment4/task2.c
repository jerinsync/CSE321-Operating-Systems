#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
/*
This program provides a possible solution using mutex and semaphore.
use 5 Farmers and 5 ShopOwners to demonstrate the solution.
*/
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize]={'R','W','P','S','M'}; //indicating room for different crops
char warehouse[warehouseSize]={'N','N','N','N','N'}; //initially all the room is empty
pthread_mutex_t mutex;
void *Farmer(void *far)
{
/*
1.Farmer harvest crops and put them in particular room. For example, room 0
for Rice(R).
2.use mutex and semaphore for critical section.
3.print which farmer is keeping which crops in which room inside the
critical section.
4.print the whole warehouse buffer outside of the critical section
*/
	for(int a = 0 ; a < MaxCrops ; a++){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		char product = crops[in];
		warehouse[in] = product;
		printf("Farmer %d: Inserts Crop %c at %d\n", *(int*)far, product ,in);
		in = (in + 1) % warehouseSize;
		sem_post(&full);
		pthread_mutex_unlock(&mutex);
		
	}
	
	pthread_mutex_lock(&mutex);
	printf("Farmer %d: ", *(int*)far);
		for(int a=0 ; a < warehouseSize ; a++){
		printf("%c" , warehouse[a]);
	}
	printf("\n");
	pthread_mutex_unlock(&mutex);

}
void *ShopOwner(void *sho)
{
/*
1.Shop owner takes crops and makes that particular room empty.
2.use mutex and semaphore for critical section.
3.print which shop owner is taking which crops from which room inside the
critical section.
4.print the whole warehouse buffer outside of the critical section
*/
	for(int b = 0 ; b < MaxCrops; b++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		char consumed = warehouse[out];
		warehouse[out] = 'N';
		printf("Shop owner %d: Removes crops %c from %d\n", *(int*)sho,consumed,out);
		out = (out + 1) % warehouseSize;
		sem_post(&empty);
		pthread_mutex_unlock(&mutex);
		
		}
		
	pthread_mutex_lock(&mutex);
	printf("Shopowner %d: ", *(int*)sho);
		for(int b= 0 ; b < warehouseSize; b++){
		printf("%c" , warehouse[b]);
	}
	printf("\n");
	pthread_mutex_unlock(&mutex);
	 
}
int main()
{
    
    /*initializing thread,mutex,semaphore
    */
    pthread_t Far[5],Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,warehouseSize);//when the warehouse is full thread will wait
    sem_init(&full,0,0);//when the warehouse is empty thread will wait
    int a[5] = {1,2,3,4,5}; //Just used for numbering the Farmer and ShopOwner
    /*create 5 thread for Farmer 5 thread for ShopOwner
    -------------------------------------------------
    -------------------------------------------------
    */
    for (int i=0; i<5; i++){
    	pthread_create(&Far[i],NULL,(void *)Farmer,&a[i]);
    }
    
    for (int j=0; j<5; j++){
    	pthread_create(&Sho[j],NULL,(void *)ShopOwner,&a[j]);
    }
    
    for (int k=0; k<5; k++){
    	pthread_join(Far[k],NULL);
    }
    
    for (int v=0; v<5; v++){
    	pthread_join(Sho[v],NULL);
    }
    
    // Closing or destroying mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}
