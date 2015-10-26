public class MergeSort {
	public static int[] mergeSort(int[] arr){
		
		
	}
	public static int[] merge(int[] left,int[] right){
		int[] result = null;
		int l = 0; //index of left array
		int r = 0; //index of right array
		int i = 0; //index of result
		
		if(left)
		while(l<left.length && r <right.length){
			if(left[l] > right[r]){
				result[i] = left[l];
				l++;
			}
			else if(left[l] < right[r]){
				result[i] = right[r];
				r++;
			}
			else if()
			i++;
		}
		return result;
		
	}
	public static void main(String args[]) throws Exception{
		
	}
}
