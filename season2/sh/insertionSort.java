package Sort;

public class insertionSort {


	public static void main(String[] args) {
		int[] arr = { 5, 2, 3 };
		
		System.out.println(insertionSort(arr));
		
	}
	
	public static int[] insertionSort(int[] arr){
		int key,i,prekey;
		
		for(i=1;i<arr.length;i++){
			key = arr[i];
			prekey = i-1;
			
			while((prekey >= 0) && (arr[prekey] > key)){
				arr[prekey+1] = arr[prekey];
				prekey--;
			}
			arr[prekey+1] = key;
		}
		return arr;
	}
}
