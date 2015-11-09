package maximum_subarray_nlogn;

public class MaxSubarrayFinder {

	ResultSet findMaxSubarray(int[] array, int lowIdx, int highIdx){
		if(array==null){
			return null;
		}
		//lowIdx랑 highIdx가 array범위 안에 있는 인덱스인지 확인해줘야?!
		if(lowIdx==highIdx){	// 원소가 1개밖에 없을 때는 그 원소로 return
			return new ResultSet(lowIdx, highIdx, array[lowIdx]);
		}
		
		int midIdx = lowIdx + (highIdx-lowIdx)/2;
		
		ResultSet leftMaxSubarray = findMaxSubarray(array, lowIdx, midIdx);
		ResultSet rightMaxSubarray = findMaxSubarray(array, midIdx+1, highIdx);
		ResultSet crossingMaxSubarray = FindMaxCrossingSubarray(array, lowIdx, midIdx, highIdx);
		
		return compareSubarrays(leftMaxSubarray, rightMaxSubarray, crossingMaxSubarray);
	}
	
	
	private ResultSet compareSubarrays(ResultSet leftMaxSubarray, ResultSet rightMaxSubarray, ResultSet crossingMaxSubarray) {
		if(leftMaxSubarray.getMaxSum() >= rightMaxSubarray.getMaxSum() 
				&& leftMaxSubarray.getMaxSum() >= crossingMaxSubarray.getMaxSum() ){
			return leftMaxSubarray;
		}
		else if(rightMaxSubarray.getMaxSum() >= leftMaxSubarray.getMaxSum() 
				&& rightMaxSubarray.getMaxSum() >= crossingMaxSubarray.getMaxSum() ){
			return rightMaxSubarray;
		}
		else
			return crossingMaxSubarray;
	}


	ResultSet FindMaxCrossingSubarray(int[] array, int lowIdx, int midIdx, int highIdx){
		if(array==null){
			return null;
		}
		if(lowIdx==highIdx){
			return new ResultSet(lowIdx, highIdx, array[lowIdx]);
		}
		
		int maxLeft=midIdx, maxRight=midIdx+1;
		int leftSum=array[midIdx], leftMaxSum=array[midIdx];
		int rightSum=array[midIdx+1], rightMaxSum=array[midIdx+1];
		
		for(int i=midIdx-1 ; i>=lowIdx ; i--){
			leftSum += array[i];
			if(leftSum>leftMaxSum){
				leftMaxSum = leftSum;
				maxLeft = i;
			}
		}
		for(int i=midIdx+2 ; i<=highIdx ; i++){
			rightSum += array[i];
			if(rightSum>rightMaxSum){
				rightMaxSum = rightSum;
				maxRight = i;
			}
		}
		
		return new ResultSet(maxLeft, maxRight, leftMaxSum+rightMaxSum); 
	}
}
