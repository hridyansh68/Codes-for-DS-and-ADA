#include <iostream>
#include <climits>
using namespace std;

class minHeap{
    int heap[1000];
    int size=0;
    
    public:
    void insertKey(int k);
    
    void deleteKey(int i);
    
    void minHeapify();
    
    void printHeap(){
        for(int i = 0;i<size;i++){
            cout<<heap[i]<<" ";
        }
    }
    
    int parent(int i){
        return (i-1)/2 ;
    }
    
    void decreaseKey(int i,int k);
    
    void extractMin();
    
    void heapify(int a);
};

void minHeap::decreaseKey(int i, int k){
    heap[i] = k;
    
    while(heap[i]<heap[parent(i)]&&i>=0){
         int temp = heap[i];
        heap[i]=heap[parent(i)];
        heap[parent(i)]=temp;
        i=parent(i);
    }
}

void minHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
}

void minHeap::extractMin(){
    heap[0] = heap[size-1];
    size--;
    heapify(0);
}

void minHeap::insertKey(int k){
    heap[size]=k;
    size++;
    int i = size-1;
    while(heap[i]<heap[parent(i)]&&i>=0){
        int temp = heap[i];
        heap[i]=heap[parent(i)];
        heap[parent(i)]=temp;
        
        i=parent(i);
    }
}

void minHeap::heapify(int a){
    int l = 2*a + 1;
    int r = 2*a + 2;
    int smallest = a;
    if(l<size&&heap[a]>heap[l]){
       smallest=l;
    }
    if (r<size&&heap[r]<heap[smallest]){
       smallest=r;
    }
    
    if(smallest!=a){
        int temp = heap[a];
        heap[a] = heap[smallest];
        heap[smallest] = temp;
        heapify(smallest);
    }
}

int main() {
	int n,a;
	minHeap h;
	cin>>n;
	for(int i =0;i<n;i++){
	    cin>>a;
	    h.insertKey(a);
	}
	h.printHeap();
	cout<<endl;
	h.deleteKey(1);
	h.printHeap();
	return 0;
}