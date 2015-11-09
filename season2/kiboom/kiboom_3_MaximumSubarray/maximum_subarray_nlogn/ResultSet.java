package maximum_subarray_nlogn;

public class ResultSet {
	private int lowIdx; 
	private int highIdx;
	private int maxSum;
	
	public ResultSet(int lowIdx, int highIdx, int maxSum) {
		this.lowIdx = lowIdx;
		this.highIdx = highIdx;
		this.maxSum = maxSum;
	}
	
	/*Getter and Setter*/
	public int getLowIndex() {
		return lowIdx;
	}
	public int getHighIndex() {
		return highIdx;
	}
	public int getMaxSum() {
		return maxSum;
	}

	@Override
	public String toString() {
		return "Maximum Subarray [index=" + lowIdx + "~" + highIdx + ", sum=" + maxSum + "]";
	}
		
}
