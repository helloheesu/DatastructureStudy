package Sort;

import java.util.Arrays;

public class MergeSort {
	
	public static int[] mergeSort(int[] arr){
		if(arr.length <= 1){
			return null;
		}
		
		int[] left = new int[arr.length/2];
		int[] right = new int[arr.length - left.length];
		
		System.arraycopy(arr, 0, left, 0, left.length);
		System.arraycopy(arr, left.length , right, 0, right.length);
		
		mergeSort(left);
		mergeSort(right);
		merge(left,right,arr);
		return arr;
 		
	}
	
	public static void merge(int[] left,int[] right,int[] result){
		int l = 0; //index of left array
		int r = 0; //index of right array
		int i = 0; //index of result
		
		while(l<left.length && r <right.length){
			if(left[l] > right[r]){
				result[i] = right[r];
				r++;
			}
			else if(left[l] < right[r]){
				result[i] = left[l];
				l++;
			}
			i++;
		}
		//left array의 모든 원소가 result에 있는 경우
		if(l >= left.length){
			while(r < right.length){
				result[i] = right[r];
				r++;
				i++;
			}
		}
		else if( r >= right.length) {
			while(l < left.length){
				result[i] = left[l];
				l++;
				i++;
			}
		}
	}
	
	public static int isSorted(int[] arr) {
		int key, next;
		int i = 0;

		for (i = 0; i < arr.length - 1; i++) {
			key = arr[i];
			next = arr[i + 1];

			if (key > next) {
				return -1;
			}
		}
		return 0;
	}
	
	public static void main(String args[]) throws Exception{
		int[] arrNull = {};
		int[] arr1 = { 2 };
		int[] arr2 = { 2, 3 };
		int[] arrReverse = { 10, 5 };
		int[] arrRandom = { 46, 78, 85, 69, 543, 11, 77, 65, 32, 50, 13, 26 };
		int[] arrSame = { 7, 7, 7 };
		
		System.out.println("before : "+ Arrays.toString(arrReverse));
		mergeSort(arrNull);
		System.out.println("arrNull:"+isSorted(arrNull));
		mergeSort(arr1);
		System.out.println("arr1:"+isSorted(arr1));
		mergeSort(arr2);
		System.out.println("arr2:"+isSorted(arr2));
		mergeSort(arrReverse);
		System.out.println("arrReverse:"+isSorted(arrReverse));
		mergeSort(arrRandom);
		System.out.println("arrRandom:"+isSorted(arrRandom));
		mergeSort(arrSame);
		System.out.println("arrSame:"+isSorted(arrSame));

	}
}
