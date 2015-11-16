package heap_sort;

public class HeapTree {
	int size;
	int[] elements;
	
	public HeapTree(int[] heapElements) {
		this.size = heapElements.length-1;
		this.elements = heapElements;
	}
	
	public int getSize() {
		return size;
	}
	public int[] getElements() {
		return elements;
	}
	
	
}
