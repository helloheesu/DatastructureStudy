package maximum_subarray_nlogn;

import java.util.Arrays;

public class Test {

	public static void main(String[] args) {

		MaxSubarrayFinder finder = new MaxSubarrayFinder();
		
		int[] arr = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
		ResultSet maxSubarray = finder.findMaxSubarray(arr, 0, arr.length-1);

		System.out.println(Arrays.toString(arr));
		System.out.println(maxSubarray);
	}

}
