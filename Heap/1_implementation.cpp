#include<bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
	int arr[100];
	int size;
	// int capacity;

	MinHeap()
	{
		// arr=new int[n];
		size=0;
		// capacity=n;
	}
	int left(int i) { return 2*i+1;}
	int right(int i) { return 2*i+2;}
	int parent(int i) { return ((i-1)/2);}
	//Approach
	//step 1: put the input value in array from the last (i.e. increase the size of array by one and put the input value)
	//step 2: Now we get a Complete binary tree: we have to make it min heap
	//        ami atia last r value tu check korim ki tar parent value tu dangor ne horu,
	//        jadi parent value tu horu=>means last value tu nijor jegat e ase
	//        jadi parent value tu dangor =>we have to swap
	//        aitu condition akw check korim thakim jetialoi k current value tu tar parent t k dangor nohoboo  
	void insert(int x)
	{
		// if(size==capacity) return;

		size=size+1;
		int ind=size-1;
		arr[ind]=x;

		int i=size-1;

		while(i!=0 and arr[parent(i)]>arr[i])
		{
			swap(arr[parent(i)], arr[i]);
			i=parent(i);
		}
	}


	//Approach: eyar kam ata heap t unbalance ata value k nijor actual jegat rakhi diya
	//ami atia i index t thoka value tu nijor actual jegat rakhibo lage
	//step 1: ami first find korim smallest value tu from (current value or i value), (current r left value) and (current r right value)
	//jdi smallest value among those is same as i value or current value =.we can stop here
	//jdi same nhoi tetia smallest value tu aru current(or i) value tu swap korim
	//value tuk right position rakhibole, akw condition tu solibo from smallest value index r karone 
	void heapify(int i)
	{
		int li=left(i), ri=right(i);
		int small=i;
		if(li<size and arr[li]<arr[small])
		{
			small=li;
		}
		if(ri<size and arr[ri]<arr[small])
		{
			small=ri;
		}
		if(small!=i)
		{
			swap(arr[small], arr[i]);
			heapify(small);
		}
	}

	//Approach-we have to delete the root value(first value) and return that value
	//step 1: first index t last r value tu put kori dim
	//step 2: heap r size tu 1 komai dim (delete hoise ata so size ek komibo, last r value tu first index t ase, problem u nai)
	//step 3: call the heapify for 0 index;
	//        heapify():-eyar kam ata heap t unbalance ata value k nijor actual jegat rakhi diya
	int extractMin()
	{
		if(size==0) return -1;
		if(size==1) 
		{
			size=0;
			return arr[0];
		}
		int temp=arr[0];
		arr[0]=arr[size-1];
		size=size-1;

		int i=0;
		heapify(i);
		return temp;
	}

	//Approach: decreaseKey r kam hoise ata index t ata input value put kora, put korile heap condition fail habo so heap kori tula
	//step-1: index t put kori de input value tu
	//step 2: if parent tu dangor tetia swap kori goi thak until parent value tu horu nhoi current value t k
	void decreaseKey(int i, int x)
	{
		arr[i]=x;
		while(i!=0 and arr[parent(i)]>arr[i])
		{
			swap(arr[parent(i)], arr[i]);
			i=parent(i);
		}
	}
	
	//Approach: ith index r value tu delete kori akw heap condition t anibo lage
	//step-1: ith index r value tu "INT_MIN" kori ith index r karone decreaseKey function tu logai de
	//        step 1 r result hisape first value tu INT_MIN hbo ge=>mane ami atia first value tu delete koribo lage
	//step-2: now first value delete kora function tu call kori de i.e. extractMin
	void deleteNodeAt(int i)
	{
		arr[i]=INT_MIN;
		while(i!=0 and arr[parent(i)]>arr[i])
		{
			swap(arr[parent(i)], arr[i]);
			i=parent(i);
		}
		// decreaseKey(i, INT_MIN);
		extractMin();
		// arr[i]=INT_MAX;
		// heapify(i);
		// size--;
	}

	//Approach : ek random array diya thakibo..value burak loi heap bonabo lage
	//ami janu last r n/2 value hodai leaf node hoi=>aru leaf node e hodai heap condition satisfy koribo
	// so ami leaf node r karone kam kora darkar nai, amni kam korim first (n-2)/2 r value karone
	//ami heap build koribo heapify fuction use korim=>it works on almost heapified heap t(means ata value unbalance thake)
	//so tar babe ami (n-2)/2 element r pora start korim, kionu hihotor children bur heap condition satisfy kori ase
	//so ami (n-2)/2 r pora 0 r loi k heapify function tu solam=>hoi gol..complete
	void buildHeap()
	{
		int i=(size-2)/2;
		while(i>=0)
		{
			heapify(i);
			i--;
		}
	}

	void print()
	{
		for(int i=0; i<size; i++) cout<<arr[i]<<" ";
		cout<<endl;
	}
};


int main()
{
	MinHeap hp;
	hp.insert(5);
	hp.insert(16);
	hp.insert(15);
	hp.insert(30);
	hp.insert(20);
	// hp.insert(60);
	hp.print();

	// cout<<hp.extractMin()<<endl;
	// hp.print();
	// hp.deleteNodeAt(0);
	// hp.print();
	// hp.decreaseKey(1, 25);
	hp.deleteNodeAt(0);
	hp.print();
}