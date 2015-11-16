package heap_sort;

import java.util.Arrays;

public class TestHeapify {

	public static void main(String[] args) {
		HeapTree heap = new HeapTree(new int[] {0,1,2,0,0,0,0});
		MaxHeapify mh = new MaxHeapify();
		
		mh.maxHeapify(heap, 1);
		
		System.out.println(Arrays.toString(heap.getElements()));
	}

	public boolean isMaxHeap(int[] heapElements){
		if(heapElements==null){
			return false;
		}
		
		for(int i=2 ; i<heapElements.length ; i++){
			if(i%2==0){
				if(heapElements[i/2]<heapElements[i])
					return false;
			}
			else{
				if(heapElements[(i-1)/2]<heapElements[i])
					return false;
			}
		}
		return true;
	}
}
