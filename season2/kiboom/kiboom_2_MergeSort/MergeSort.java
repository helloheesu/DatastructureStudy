package merge_sort;

public class MergeSort {

	public static int[] mergeSort(int[] arr, int start, int end){
		
		if(arr==null || arr.length==0){
			return null;
		}
		
		if(start<0 || end<0){
			System.out.println("정렬 범위 오류! left, right 인자는 자연수만 가능합니다.");
			return null;
		}
		
		if(start<end){
			int mid = (start+end)/2;
			mergeSort(arr, start, mid);
			mergeSort(arr, mid+1, end);
			mergeTwoArrays(arr, start, mid, end);
		}
		
		return arr;
	}
	
	public static void mergeTwoArrays(int[] arr, int start, int mid, int end){
		int[] result = new int[arr.length];
		int resultIdx = start;
		
		int frontIdx = start;
		int rearIdx = mid + 1;
		
		while(frontIdx<=mid && rearIdx<=end){
			if(arr[frontIdx]<arr[rearIdx]){
				result[resultIdx++] = arr[frontIdx++];
			}else{
				result[resultIdx++] = arr[rearIdx++];
			}
		}
		
		if(frontIdx>mid){
			while(rearIdx<=end){
				result[resultIdx++] = arr[rearIdx++];
			}
		}
		if(rearIdx>end){
			while(frontIdx<=mid){
				result[resultIdx++] = arr[frontIdx++];
			}
		}
		
		for(int i=start ; i<=end ; i++){
			arr[i] = result[i];
		}
	}
}
