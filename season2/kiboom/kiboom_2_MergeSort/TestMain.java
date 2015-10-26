package merge_sort;

import java.util.Arrays;

public class TestMain {

	public static void main(String[] args) {
		
		int[] arr0 = {};
		int[] arr1 = {1};
		int[] arr2 = {1,3};
		int[] arr3 = {3,1};
		int[] arr4 = {3,3};
		int[] arr5 = {1,2,3};
		int[] arr6 = {3,2,1};
		int[] arr7 = {3,1,2};
		int[] arr8 = {1,1,1};
		int[] arr9 = {1,2,3,4};
		int[] arr10 = {4,3,2,1};
		int[] arr11 = {1,3,4,2};
		int[] arr12 = {3,3,3,3};
		
		int[][] testDatas = new int[][] {arr0, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10, arr11, arr12};
		
		for(int[] testArr : testDatas){
			MergeSort.mergeSort(testArr, 0, testArr.length-1);
			System.out.println(Arrays.toString(testArr));
		}
		
	}

}
