package intro;

import java.util.Arrays;

public class LastElementSort {

	public static void main(String[] args) {
		int[] array = {1,2,3,4,6,7,8,5};
		lastElementSort(array);
	}

	public static int[] lastElementSort(int[] array){
		if(array.length <= 0){
			System.out.println("null");
			return array;
		}
		
		for(int i=array.length-1 ; i>=1 ; i--){
			if(array[i-1] <= array[i]){
				break;
			}
			int temp = array[i-1];
			array[i-1] = array[i];
			array[i] = temp;
		}
		
		System.out.println(Arrays.toString(array));
		return array;
	}
}
