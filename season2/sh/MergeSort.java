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
	
	public static void main(String args[]) throws Exception{
		int[] testArr = {1,2,3,5,4};
		
		System.out.println("before : "+ Arrays.toString(testArr));
		mergeSort(testArr);
		System.out.println("after : " +Arrays.toString(testArr));
		
	}
}
