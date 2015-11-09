// 무조건 0번째에 샀다고 가정, 언제 팔면 가장 이득인지 인덱스를 반환하는 함수
function getMaxSumIdx(array) {
	if (array.length < 1) return;

	var maxIdx = 0, sum = [];
	sum[0] = array[0];

	for (var currentIdx = 1; currentIdx < array.length; currentIdx++) {
		sum[currentIdx] = sum[currentIdx-1] + array[currentIdx];
		if (sum[maxIdx] < sum[currentIdx]) {
			maxIdx = currentIdx;
		}
	}
	return maxIdx;
}

// 리팩토링
function getMaxSumIdx(array) {
	if (!array || !(length in array)) return;
	if (array.length < 1) return;

	var maxIdx = 0, currentSum, maxSum;
	maxSum = currentSum = array[0];

	for (var currentIdx = 1; currentIdx < array.length; currentIdx++) {
		currentSum += array[currentIdx];
		if (maxSum < currentSum) {
			maxSum = currentSum
			maxIdx = currentIdx;
		}
	}
	return maxIdx;
}

getMaxSumIdx([3,2,-7,6,-100,1000,-30,-20,60,0,-2]);

