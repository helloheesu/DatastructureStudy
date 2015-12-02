package Sort;

public class HeapSort {
	
	public static void heapsort(int[] arr){
		build_MaxHeap(arr);
		for(int i=arr.length; i >=2; i--){
			int temp = arr[1];
			arr[1]=arr[i];
			arr[i]=temp;
			int[] shorted = new int[arr.length-1];
			System.arraycopy(arr, arr[0], shorted, shorted[0], shorted.length);
		}
	}
	public static void build_MaxHeap(int[] arr){
		int heapsize = arr.length-1;
		for(int i =(heapsize/2); i >=1; i--){
			max_heapify(arr,i);
		}
	}

	private static void max_heapify(int[] arr, int i) {
		int heapsize = arr.length-1;
		int largest = i;
		int leftIdx = i * 2;
		int rightIdx = (i*2) + 1;
		
		if(leftIdx <= heapsize && arr[leftIdx] > arr[i]) {
			largest = leftIdx;
		}
		else 
			largest = i;
		
		if(rightIdx <= heapsize && arr[rightIdx] > arr[i]){
			largest = rightIdx;
		}
		if(largest != i){
			int oldlargest = arr[i];
			arr[i] = arr[largest];
			arr[largest] = oldlargest;
			max_heapify(arr,largest);
		}
	}

}
