// 전에 있던 손코딩 결과
function getMaxSubarrayFromStart (array) {
	if (!array || !(length in array)) return;
	if (array.length < 1) return;

	var maxIdx = 0, currentSum, maxSum;
	maxSum = currentSum = array[0];

	for (var currentIdx = 1; currentIdx < array.length; currentIdx++) {
		currentSum += array[currentIdx];
		if (maxSum < currentSum) {
			maxSum = currentSum;
			maxIdx = currentIdx;
		}
	}
	return maxIdx;
}

function getMaxCrossingSubarray (array, startIdx, endIdx, midIdx) {
	if (typeof startIdx === "undefined") startIdx = 0;
	if (typeof endIdx === "undefined") endIdx = array.length -1;
	if (endIdx < startIdx) { endIdx^= startIdx; startIdx^= endIdx; endIdx^= startIdx; }
	if (typeof midIdx === "undefined") { midIdx = getMiddleIdx(startIdx, endIdx); }

	// fullarray[startIdx, endIdx], subarray[left, right]
	var iterator, subSum;

	var left = midIdx+1, leftSum = 0;
	for (iterator=midIdx, subSum=0; iterator >= startIdx; iterator--) {
		subSum += array[iterator];
		if (leftSum < subSum) {
			left = iterator;
			leftSum = subSum;
		}
	}
	var right = midIdx, rightSum = 0;
	for (iterator=midIdx+1, subSum=0; iterator <= endIdx; iterator++) {
		subSum += array[iterator];
		if (rightSum < subSum) {
			right = iterator;
			rightSum = subSum;
		}
	}
	return (left > right) ? [0, -1, -1] : [leftSum+rightSum, left, right];
}

function getMaxSubarray (array, startIdx, endIdx) {
	if (!array || !(length in array)) return;
	if (array.length < 1) return;

	if (typeof startIdx === "undefined") startIdx = 0;
	if (typeof endIdx === "undefined") endIdx = array.length -1;

	if (startIdx >= endIdx) return [array[startIdx], startIdx, startIdx];

	var midIdx = midIdx = getMiddleIdx(startIdx, endIdx);
	var max = [0, -1, -1]; // [sum, startIdx, endIdx], -1 means DO NOT BUY ANYTHING.
	var left = getMaxSubarray(array, startIdx, midIdx);
	if (max[0] < left[0]) max = left;
	var right = getMaxSubarray(array, midIdx+1, endIdx);
	if (max[0] < right[0]) max = right;
	var cross = getMaxCrossingSubarray(array, startIdx, midIdx, endIdx);
	if (max[0] < cross[0]) max = cross;

	return max;
}