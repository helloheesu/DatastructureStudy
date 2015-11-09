package maximum_subarray_n2;

import java.util.ArrayList;

public class MaxSubarrayFinder {

	ResultSet findMaxSubarray(int[] array, int lowIdx, int highIdx){
		if(array==null){
			return null;
		}
		
		// lowIdx, highIdx 예외처리 해줘야...
		
		ArrayList<ResultSet> pairs = new ArrayList<ResultSet>(); 
		
		for(int i=lowIdx ; i<=highIdx ; i++){
			int maxIdx=i;
			int sum=array[i], maxSum=array[i];
			for(int j=i+1 ; j<=highIdx ; j++){
				sum += array[j];
				if(sum > maxSum){
					maxSum = sum;
					maxIdx = j;
				}
			}
			pairs.add(new ResultSet(i, maxIdx, maxSum));
		}
		
		ResultSet maxPairs = pairs.get(0);
		for(int i=1 ; i<pairs.size() ; i++){
			if(pairs.get(i).getMaxSum() > maxPairs.getMaxSum()){
				maxPairs = pairs.get(i);
			}
		}
		return maxPairs;
	}
}
