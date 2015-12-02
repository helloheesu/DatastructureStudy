package heap_sort;

import java.util.Arrays;

public class TestHeapify {

	public static void main(String[] args) {
		HeapTree heap = new HeapTree(new int[] {0,1,2,4,5,3,6});
		MaxHeapify mh = new MaxHeapify();
		
		System.out.println(isMaxHeap(heap.getElements()));
		mh.maxHeapify(heap, 1);
		System.out.println(isMaxHeap(heap.getElements()));
		
		System.out.println(Arrays.toString(heap.getElements()));
	}

	public static boolean isMaxHeap(int[] heapElements){
		if(heapElements==null){
			return false;
		}
		
		for(int i=2 ; i<heapElements.length ; i++){
			if(heapElements[i/2]<heapElements[i])		// 나와 내 부모를 비교!
				return false;
		}
		return true;
	}
}
