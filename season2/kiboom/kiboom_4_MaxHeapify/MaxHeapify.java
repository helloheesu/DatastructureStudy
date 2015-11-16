package heap_sort;

public class MaxHeapify {

	public void maxHeapify (HeapTree heap, int pos){
		if(heap==null){
			return;
		}
		
		int leftSubPos = 2*pos;
		int rightSubPos = leftSubPos+1;
		int largestPos = pos;
		
		int heapSize = heap.getSize();
		int[] heapElements = heap.getElements();
		
		if(leftSubPos <= heapSize && heapElements[leftSubPos] > heapElements[pos]){
			largestPos = leftSubPos;
		}
		if(rightSubPos <= heapSize && heapElements[rightSubPos] > heapElements[largestPos]){
			largestPos = rightSubPos;
		}
		if(largestPos != pos){
			swap(heapElements, pos, largestPos);
			maxHeapify(heap, largestPos);
		}
	}

	private void swap(int[] heapElements, int a, int b) {
		int temp = heapElements[a];
		heapElements[a] = heapElements[b];
		heapElements[b] = temp;
	}
}
