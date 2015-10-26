package insertion_sort;

import java.util.Arrays;

public class InsertionSort {

	public static void main(String[] args) {
		int[] array0 = {};
		int[] array1 = {1};
		int[] array2 = {2,1};
		int[] array3 = {2,3,1};
		int[] array4 = {4,3,2,1};
		
		insertionSort(array0);
		insertionSort(array1);
		insertionSort(array2);
		insertionSort(array3);
		insertionSort(array4);
	}

	public static int[] insertionSort(int[] array){
		if(array.length <= 0){
			System.out.println("null");
			return null;
		}
		
		for(int i=1 ; i<array.length ; i++){
			int sortingKey = array[i];
			int prePos = i-1;
			while(prePos >= 0 && array[prePos]>sortingKey){
				array[prePos+1] = array[prePos];
				prePos--;
			}
			array[prePos+1] = sortingKey;
		}
		
		System.out.println(Arrays.toString(array));
		return array;
	}
}
